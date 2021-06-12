#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)

//https://www.spoj.com/problems/NITTROAD/
//Disjoint Sets | Offline Query
int find(int x, vector<int> &p) {
	if (p[x] == x)
		return x;
	return find(p[x], p);
}

void unite(int u, int v, vector<int> &p, vector<int> &s) {
	int x = find(u, p), y = find(v, p);
	
	if (s[y] > s[x])
		swap(y, x);
	
	p[y] = x;
	s[x] += s[y];
}

void solve() {
	int n, i, q, u, v;
	cin >> n;
	
	vector<pair<int, int>> edges;
	edges.pb(make_pair(-1, -1));
	for (i = 1; i < n; i++) {
		cin >> u >> v;
		edges.pb(make_pair(u, v));
	}

	cin >> q;
	char c;
	int idx;
	stack<int> queries;				// > 0 for 'R' and -1 for 'Q'
	vector<bool> e(n, 1);			//e[i] = 1 if ith edge is not removed
	e[0] = 0;

	//loop to store queries
	for (i = 0; i < q; i++) {
		cin >> c;
		if (c == 'R') {
			cin >> idx;
			e[idx] = 0;
			queries.push(idx);
		}
		else
			queries.push(-1);
	}

	ll ans = (ll)n*((ll)n-1)/2;
	vector<int> parent(n+1), sz(n+1, 1);
	for (i = 1; i <= n; i++)
		parent[i] = i;

	//loop to construct graph
	for (i = 1; i < n; i++) {
		if (e[i]) {
			ans -= (ll)sz[find(edges[i].first, parent)] * (ll)sz[find(edges[i].second, parent)];
			//above rhs is just product of size of two disjoint sets
			// cout << edges[i].first << " " << edges[i].second << " " << ans << "\n";
			unite(edges[i].first, edges[i].second, parent, sz);
		}
	}

	//to process queries:
	int qu;
	stack<ll> q_ans;
	while (!queries.empty()) {
		qu = queries.top();
		queries.pop();
		if (qu == -1)
			q_ans.push(ans);
		else {
			ans -= (ll)sz[find(edges[qu].first, parent)] * (ll)sz[find(edges[qu].second, parent)];
			unite(edges[qu].first, edges[qu].second, parent, sz);
		}
	}

	//printing ans in reverse order
	while (!q_ans.empty()) {
		cout << q_ans.top() << "\n";
		q_ans.pop();
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	//remove this piece of code when this has to be submitted in kickstart
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
	//freopen is used to associate a file with stdin or stdout stream in C++
	#endif

	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
	}

	cerr << "time: "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}