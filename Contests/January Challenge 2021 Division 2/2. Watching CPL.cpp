#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()

//Watching CPL
//January Challenge 2021 Division 2
void solve() {
	int n, k, i, ans, sum = 0, j;
	cin >> n >> k;

	vector<int> v(n), suffix(n+1, 0);
	for (i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
	}
	sort(all(v));

	if (sum < 2*k) {
		cout << "-1\n";
		return;
	}

	for (i = n-1; i >= 0; i--)
		suffix[i] = suffix[i+1] + v[i];

	ll dp[n+1][k+1];
	//dp[i][s] -> represents minimum height that can be obtained using
	//elements from v[i] to v[n-1]
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= k; j++) {
			dp[i][j] = INF;
		}
	}
	dp[n][0] = 0;

	for (i = n-1; i >= 0; i--) {
		for (j = k; j >= 0; j--) {
			if (j <= v[i]) {
				dp[i][j] = v[i];
				continue;
			}
			if (dp[i+1][j - v[i]] == INF)
				dp[i][j] = INF;
			else
				dp[i][j] = min(dp[i+1][j], dp[i+1][j - v[i]] + v[i]);
				//dp[i+1][j] -> case when v[i] is not included
				//dp[i+1][j - v[i]] + v[i] -> case when v[i] is included
		}
	}
	for (i = n-1; i >= 0; i--) {
		if (suffix[i] - dp[i][k] >= k) {
			cout << n-i << "\n";
			return;
		}
	}
	cout << "-1\n";
}

/*
4
8 38
7 8 19 7 8 7 10 20
=> 7
9 70
25 24 23 23 20 18 16 6 5
=> 7
4 5
2 10 4 9
=> 2
8 8
5 5 1 1 1 1 1 1
=> 8
9 60
29 27 21 21 19 10 9 5 2
=> 6
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
	//freopen is used to associate a file with stdin or stdout stream in C++
	#endif

	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		// cout << "Case #" << i << ": ";
		// cout << "Test " << i << ":\n";
		solve();
	}

	cerr << "time: "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}