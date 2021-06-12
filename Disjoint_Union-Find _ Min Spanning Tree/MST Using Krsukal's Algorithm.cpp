#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)

//https://www.spoj.com/problems/MST/
//MST Using Krsukal's Algorithm
int find(int x, vector<int> &p) {
	if (p[x] == x)
		return x;
	return p[x] = find(p[x], p);
}

void unite(int u, int v, vector<int> &p, vector<int> &s) {
	int x = find(u, p), y = find(v, p);
	
	if (s[y] > s[x])
		swap(y, x);
	
	p[y] = x;
	s[x] += s[y];
}

void solve() {
	int n, m, i;
	int u, v, w;
	cin >> n >> m;
	
	vector<int> parent(n+1, -1), sz(n+1, 1);
	for (i = 1; i <= n; i++)
		parent[i] = i;

	map<int, pair<int, int>> edge;
	//should be stored in vector and then sort by weight
	
	for (i = 0; i < m; i++) {
		cin >> u >> v >> w;
		edge[w] = make_pair(u, v);
	}

	ll ans = 0;
	for (auto it = edge.begin(); it != edge.end(); it++) {
		// cout << it->first << " " << it->second.first << " " << it->second.second << "\n";
		if (find(it->second.first, parent) == find(it->second.second, parent))
			continue;

		ans += it->first;
		unite(it->second.first, it->second.second, parent, sz);

		// cout << "parent:\n";
		// for (i = 1; i <= n; i++)
		// 	cout << parent[i] << " ";
		// cout << "\nsize:\n";
		// for (i = 1; i <= n; i++)
		// 	cout << sz[i] << " ";
		// cout << "\n\n";
	}

	cout << ans << "\n";
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
	// cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
	}

	cerr << "time: "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}