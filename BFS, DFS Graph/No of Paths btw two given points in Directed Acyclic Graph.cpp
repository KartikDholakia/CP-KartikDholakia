#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)

//https://www.spoj.com/problems/KFSTB/
//No of Paths b/w two given points in Directed
//Acyclic Graph | DFS + DP

ll dfs(vector<int> adj[], vector<ll> &dp, int x) {
	if (dp[x] != 0)
		return dp[x];
	
	for (int i = 0; i < adj[x].size(); i++) {
		dp[x] = (dp[x] + dfs(adj, dp, adj[x][i])) % mod;
	}
	return dp[x];
}

void solve() {
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	
	vector<ll> dp(n+1, 0);
	dp[t] = 1;
	// dp[i] -> deontes the no paths b/w i & given 't'

	int i, j, u, v;
	vector<int> adj[n+1];
	for (i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].pb(v);
	}

	cout << (ll)dfs(adj, dp, s) << "\n";
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