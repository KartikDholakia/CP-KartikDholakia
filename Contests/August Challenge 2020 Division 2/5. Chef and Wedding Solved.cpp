#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;
#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807

//Chef and Wedding Arrangements
//Dynamic Programming
//https://www.codechef.com/AUG20B/problems/CHEFWED
void solve() {
	int n, k, i, j;
	cin >> n >> k;
	vector<int> v(n+1);
	map<int, int> pre;
	map<int, int> :: iterator it;
	int arr[n+1][n+1] = {0};

	for (i = 1; i <= n; i++)
		cin >> v[i];

	for (i = 1; i <= n; i++) {
		pre.clear();
		arr[i][i] = k;
		pre[v[i]]++;
		for (j = i+1; j <= n; j++) {
			if (pre[v[j]] == 0)
				arr[i][j] = arr[i][j-1];
			
			else if (pre[v[j]] == 1)
				arr[i][j] = arr[i][j-1] + 2;
			
			else
				arr[i][j] = arr[i][j-1] + 1;
			
			pre[v[j]]++;
		}
	}

	vector<int> dp(n+1, 0);

	for (i = 1; i <= n; i++) {
		dp[i] = INT_MAX;
		for (j = 1; j <= i; j++) {
			dp[i] = min(dp[i], dp[j-1] + arr[j][i]);
		}
	}

	cout << dp[n] << "\n";
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