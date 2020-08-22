#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;
#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807

//Pizza Delivery
//Dynamic Programming
//https://www.codechef.com/problems/DBOY
void solve() {
	int n, i, j;
	cin >> n;
	vector<int> H(n+1, 0);
	vector<int> K(n+1, 0);

	for (i = 1; i <= n; i++) 
		cin >> H[i];

	for (i = 1; i <= n; i++) 
		cin >> K[i];

	sort(K.begin(), K.end());
	int l = *max_element(H.begin(), H.end());

	ll dp[n+1][2*l + 1];
	ll ans = 0;

	for (j = 1; j <= 2*l; j++)
		dp[0][j] = INF;

	for (i = 0; i <= n; i++)
		dp[i][0] = 0;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= 2*l; j++) {
			if (j >= K[i])
				dp[i][j] = min(dp[i-1][j], dp[i][j - K[i]] + 1);
			else
				dp[i][j] = dp[i-1][j];
		}
	}

	// for (i = 1; i <= n; i++) {
	// 	for (j = 1; j <= 2*l; j++) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }

	for (i = 1; i <= n; i++)
		ans += dp[n][2*H[i]];

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
	cin >> t;
	for (st i = 0; i < t; i++) {
		solve();
	}

	cerr << "time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}