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

//A2: Consistency - Chapter 2
//https://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round/problems/A2
//Floyd Warshall
void solve() {
	string s;
	cin >> s;
	ll n, i, j, k;
	cin >> k;
	n = s.size();

	ll dp[26][26];
	// mem(dp, INT_MAX);
	char u, v;

	loop(i, 0, 26) {
		loop(j, 0, 26) {
			if (i == j)
				dp[i][j] = 0;
			else
				dp[i][j] = INT_MAX;
		}
	}

	loop(i, 0, k) {
		cin >> u >> v;
		dp[u - 'A'][v - 'A'] = 1;
	}

	// cout << "\n";
	// loop(i, 0, 3) {
	// 	loop(j, 0, 3)
	// 		cout << dp[i][j] << " ";
	// 	cout << "\n";
	// }

	bool flag = 1;
	loop(i, 1, n) {
		if (s[i] != s[0]) {
			flag = 0;
			break;
		}
	}

	if (flag) {
		cout << "0\n";
		return;
	}

	loop(k, 0, 26) {
		loop(i, 0, 26) {
			loop(j, 0, 26) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}

	sort(all(s));

	ll ans = INT_MAX;
	ll sum[26] = {0};

	loop(i, 0, n) {
		loop(j, 0, 26) {
			if (sum[j] == INT_MAX || dp[s[i] - 'A'][j] == INT_MAX)
				sum[j] = INT_MAX;
			else
				sum[j] += dp[s[i] - 'A'][j];
		}
	}

	loop(i, 0, 26)
		ans = min(ans, sum[i]);

	if (ans == INT_MAX)
		cout << "-1\n";
	else
		cout << ans << "\n";

	// loop(i, 0, 3) {
	// 	loop(j, 0, 3)
	// 		cout << dp[i][j] << " ";
	// 	cout << "\n";
	// }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}