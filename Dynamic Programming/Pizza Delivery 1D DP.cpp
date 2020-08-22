#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;
#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807

//Pizza Delivery 1D DP
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

	ll dp[2*l + 1];
	ll ans = 0;

	for (i = 1; i <= 2*l; i++)
		dp[i] = INF;

	dp[0] = 0;

	for (i = 1; i <= n; i++) {
		for (j = K[i]; j <= 2*l; j++) {
			dp[j] = min(dp[j], dp[j-K[i]] + 1);
		}
	}

	for (i = 1; i <= n; i++)
		ans += dp[2*H[i]];

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