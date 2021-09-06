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
#define mem(x, y) memset(x, y, sizeof(x))
#define loop_diff(var, start, end, diff) for (ll var = start; var < end; var += diff)
#define loop(var, start, end) for (auto var = start; var < end; var++)
#define loop_rev(var, start, end) for(auto var = start; var > end; var--)
#define ordered_set tree<pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update>

//https://www.spoj.com/problems/LISA/
//LISA SPOJ | MCM DP
void solve() {
	ll n, i, j, k, l;
	string s;
	cin >> s;
	// cout << s << "\n";

	vll num;
	num.pb(0);
	vector<char> op;
	op.pb('x');

	loop(i, 0, s.size()) {
		if (s[i] == '+' || s[i] == '*')
			op.pb(s[i]);
		else
			num.pb(s[i] - '0');
	}
	op.pb('-');

	n = num.size();
	// loop(i, 1, n)
	// 	cout << num[i];
	// cout << "\n";

	// loop(i, 1, n)
	// 	cout << op[i];
	// cout << "\n";

	int mx_dp[n][n], mn_dp[n][n];
	mem(mx_dp, 0);
	mem(mn_dp, 0);

	loop(i, 1, n) {
		mx_dp[i][i] = num[i];
		mn_dp[i][i] = num[i];
	}

	loop(l, 1, n-1) {
		for (i = 1; (i <= n) && (i+l <= n); i++) {
			j = i+l;
			mn_dp[i][j] = INT_MAX;
			loop(k, i, j) {
				if (op[k] == '+') {
					mx_dp[i][j] = max(mx_dp[i][j], mx_dp[i][k] + mx_dp[k+1][j]);
					mn_dp[i][j] = min(mn_dp[i][j], mn_dp[i][k] + mn_dp[k+1][j]);
				}
				else {
					mx_dp[i][j] = max(mx_dp[i][j], mx_dp[i][k] * mx_dp[k+1][j]);
					mn_dp[i][j] = min(mn_dp[i][j], mn_dp[i][k] * mn_dp[k+1][j]);
				}
			}
		}
	}

	// loop(i, 1, n) {
	// 	loop(j, 1, n) {
	// 		cout << mx_dp[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }

	cout << mx_dp[1][n-1] << " " << mn_dp[1][n-1] << "\n";
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
	// solve();

	cerr << "time: "<<(double)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}
