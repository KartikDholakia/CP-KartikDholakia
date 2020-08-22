#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;
#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807

//Matrix
//Dynamic Programming
//https://www.codechef.com/problems/MATRIX2
void solve() {
	int n, m, i, j;
	char inp;
	cin >> n >> m;
	bool mat[n+1][m+1];

	for (i = 0; i < n; i++) {
		for (j = 1; j <= m; j++) {
			cin >> inp;
			mat[i][j] = inp - '0';
		}
	}

	int dp[n+1][m+1];
	
	for (i = 0; i <= n; i++)
		for (j = 0; j <= m; j++)
			dp[i][j] = 0;
	
	ll ans = 0;
	for (i = n-1; i >= 0; i--) {
		for (j = 1; j <= m; j++) {
			if (mat[i][j]) {
				dp[i][j] = min(dp[i][j-1], dp[i+1][j]) + 1;
				ans += dp[i][j];
			}
		}
	}

	// for (i = 0; i < n+1; i++) {
	// 	for (j = 0; j < m+1; j++) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }

	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
	//freopen is used to associate a file with stdin or stdout stream in C++
	#endif

	st t = 1;
//	cin >> t;
	for (st i = 0; i < t; i++) {
		solve();
	}

	cerr << "time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}