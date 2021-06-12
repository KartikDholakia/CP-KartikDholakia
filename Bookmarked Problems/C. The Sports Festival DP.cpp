#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

#define MOD 1000000007
#define MAX 1000001					//1e6 + 1
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define mp make_pair

//https://codeforces.com/contest/1509/problem/C
//DP
ll dp[2001][2001];

ll solveDP(ll l, ll r, vector<ll> &v) {
	if (l == r)
		return dp[l][r] = 0;

	if (dp[l][r] != -1)
		return dp[l][r];

	return dp[l][r] = (v[r] - v[l] + min(solveDP(l, r-1, v), solveDP(l+1, r, v)));
}

void solve() {
	ll n, i, j;
	cin >> n;
	
	vector<ll> v(n);
	for (i = 0; i < n; i++)
		cin >> v[i];
	sort(all(v));

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			dp[i][j] = -1;
	
	cout << solveDP(0, n-1, v) << "\n";
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
		// cout << "Case #" << i << ": ";
		solve();
	}

	cerr << "time: "<<(double)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}