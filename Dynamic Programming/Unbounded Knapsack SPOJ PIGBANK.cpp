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

//DP | Unbounded Knapsack 
//https://www.spoj.com/problems/PIGBANK/
void solve() {
	ll emptyW, fullW, n, i, w;
	cin >> emptyW >> fullW;
	cin >> n;

	vll val(n, 0), wt(n, 0);
	loop(i, 0, n)
		cin >> val[i] >> wt[i];

	vll dp(fullW+1, INT_MAX);

	loop(w, 0, emptyW+1)
		dp[w] = 0;

	loop(w, emptyW, fullW + 1) {
		loop(i, 0, n) {
			if (wt[i] <= w - emptyW) {
				dp[w] = min(dp[w], 
					(dp[w - wt[i]] + val[i])
				);
			}
			// else
			// 	dp[w] = 0;
		}
	}

	if (dp[fullW] == INT_MAX) {
		cout << "This is impossible.\n";
	}
	else {
		cout << "The minimum amount of money in the piggy-bank is " << dp[fullW] << ".\n";
	}
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
		// cout << "Case " << i << ": ";
		solve();
	}

	cerr << "time: "<<(double)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}
