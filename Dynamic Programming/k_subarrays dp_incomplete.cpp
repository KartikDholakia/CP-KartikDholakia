#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

#define MOD 1000000007				//1e9 + 7
#define MAX 200001					//2e5 + 1
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define mp make_pair
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pair<ll, ll>>
#define loop_diff(var, start, end, diff) for (ll var = start; var < end; var += diff)
#define loop(var, start, end) for (auto var = start; var < end; var++)
#define loop_rev(var, start, end) for(auto var = start; var > end; var--)

//2d DP, Prefix
//https://www.codechef.com/LTIME96B/problems/CHESUB
void solve() {
	ll n, k, i, j;
	cin >> n >> k;

	vll v(n+1, 0);
	loop(i, 1, n+1)
		cin >> v[i];

	ll dp[k+1][n+1], prefix[k+1][n+1];
	loop(i, 0, k+1) {
		loop(j, 0, n+1) {
			dp[i][j] = LLONG_MIN;
			prefix[i][j] = LLONG_MIN;
		}
	}
	loop(i, 0, n+1) {
		dp[0][i] = 0;
		prefix[0][i] = 0;
	}

	loop(i, 0, k+1) {
		loop(j, 0, n+1)
			cout << dp[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";

	//dp[i][j] -> denotes ans taking elements v[1]...v[j] and ith subset ends at v[j]
	//prefix[i][j] -> max of dp[i][j-1], dp[i][j-2]..., dp[i][1]
	loop(i, 1, k+1) {
		loop(j, 1, n+1) {
			dp[i][j] = max(dp[i][j-1], prefix[i-1][j-1]) + i*v[j];
			// if (j == 1)
			// 	prefix[i][j] = dp[i][j];
			// else
			prefix[i][j] = max(dp[i][j], prefix[i][j-1]);
		}
	}

	loop(i, 0, k+1) {
		loop(j, 0, n+1)
			cout << prefix[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";

	loop(i, 1, k+1) {
		loop(j, 1, n+1) 
			cout << dp[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";

	ll ans = -INF;
	loop(i, 1, n+1)
		ans = max(ans, dp[k][i]);
	
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
	cin >> t;
	for (int i = 1; i <= t; i++) {
		// cout << "Case #" << i << ": ";
		solve();
	}

	cerr << "time: "<<(double)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}
