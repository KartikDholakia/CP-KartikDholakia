#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001					//1e6 + 1
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define mp make_pair

//6. Another Tree with Number Theory
//February Challenge 2021 Division 2
vector<int> adj[100001];

int bfs(int v, int w) {
	queue<pair<int, int>> q;
	q.push(mp(v, w));
	int curr_v, ans = 0, sz, i;

	while (!q.empty()) {
		curr_v = q.front().first;
		w = q.front().second;
		q.pop();
		sz = adj[curr_v].size();
		
		//leaf node
		if (sz == 0)
			continue;
		
		if (w % sz != 0) {
			ans += w;
			// cout << curr_v << " " << w << " " << ans << "\n";
			continue;
		}

		w = w/sz;
		for (i = 0; i < adj[curr_v].size(); i++) {
			q.push(mp(adj[curr_v][i], w));
		}
	}

	return ans;
}

void solve() {
	int n, i, q;
	cin >> n;
	vector<int> p(n);
	p[0] = -1;
	for (i = 1; i < n; i++) {
		cin >> p[i];
		adj[p[i]].pb(i+1);
	}

	cin >> q;
	int v, w;
	for (i = 0; i < q; i++) {
		cin >> v >> w;
		cout << bfs(v, w) << "\n";
	}
}

/*
11
1 1 2 2 3 3 3 6 9 9
3
1 30
3 21
1 40
*/

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

	cerr << "time: "<<(double)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}