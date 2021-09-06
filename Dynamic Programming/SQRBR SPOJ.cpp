#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

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
#define ordered_set tree<pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update>

//2D DP
//https://www.spoj.com/problems/SQRBR/
void solve() {
	ll n, k, i, inp;
	cin >> n >> k;
	string s(2*n+1, 'x');

	s[1] = '[';
	s[2*n] = ']';
	loop(i, 0, k) {
		cin >> inp;
		s[inp] = '[';
	}

	ll dp[2*n+1][2*n+1];

	loop(i, 0, 2*n+1)
		loop(j, 0, 2*n+1)
			dp[i][j] = 0;

	dp[1][0] = 0;
	dp[1][1] = 1;
	loop(i, 2, 2*n + 1) {
		loop(j, 0, i+1) {
			if (s[i] == 'x') {
				dp[i][j] = dp[i-1][j+1];
				if (j)
					dp[i][j] += dp[i-1][j-1];
			}
			else {
				if (s[i] == '[') {
					if (j)
						dp[i][j] = dp[i-1][j-1];
				}
				else
					dp[i][j] = dp[i-1][j+1];
			}
		}
	}

	// loop(i, 1, 2*n+1) {
	// 	loop(j, 0, i+1) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }

	cout << dp[2*n][0] << "\n";
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
