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

//https://www.spoj.com/problems/GNY07H/
//Sol - http://journeywithdp.blogspot.com/2018/07/way-to-solve-tiling-problems.html
//GNY07H - Tiling a Grid With Dominoes | DP
void solve() {
	int T, i, N = 1000, n;
	cin >> T;
	
	vll dp(N+1, 0), g(N+1, 0), h(N+1, 0);
	//base conditions:
	dp[0] = 1;
	dp[1] = 1;
	g[0] = 1;
	g[1] = 2;
	h[0] = 1;
	h[1] = 1;

	loop(i, 2, N+1) {
		dp[i] = dp[i-1] + dp[i-2] + 2*g[i-2] + h[i-2];
		g[i] = dp[i] + g[i-1];
		h[i] = dp[i] + h[i-2];
	}

	i = 1;
	while (T--) {
		cin >> n;
		cout << i << " " << dp[n] << "\n";
		i++;
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

	// int t = 1;
	// cin >> t;
	// for (int i = 1; i <= t; i++) {
	// 	// cout << "Case #" << i << ": ";
	// 	cout << i << " ";
	// 	solve();
	// }
	solve();

	cerr << "time: "<<(double)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}
