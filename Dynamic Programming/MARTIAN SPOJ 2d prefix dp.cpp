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

//DP | Prefix
//https://www.spoj.com/problems/MARTIAN/
void solve(ll n, ll m) {
	ll yey[n][m], blog[n][m], pre_yey[n][m], pre_blog[n][m];
	ll i, j, sum = 0;

	loop(i, 0, n) {
		loop(j, 0, m) {
			pre_yey[i][j] = 0;
			pre_blog[i][j] = 0;
		}
	}

	loop(i, 0, n) {
		loop(j, 0, m) {
			cin >> yey[i][j];
			pre_yey[i][j] = yey[i][j];
			if (j)
				pre_yey[i][j] += pre_yey[i][j-1];
		}
	}

	loop(i, 0, n) {
		loop(j, 0, m) {
			cin >> blog[i][j];
			pre_blog[i][j] = blog[i][j];
			if (i)
				pre_blog[i][j] += pre_blog[i-1][j];
		}
	}

	// loop(i, 0, n) {
	// 	loop(j, 0, m) {
	// 		cout << pre_yey[i][j] << "|" << pre_blog[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	// cout << "\n";

	ll dp[n][m];
	loop(i, 0, n)
		loop(j, 0, m)
			dp[i][j] = 0;

	loop(i, 0, n) {
		loop(j, 0, m) {
			if (i >= 1 && j >= 1)
				dp[i][j] = max(pre_yey[i][j] + dp[i-1][j], 
								pre_blog[i][j] + dp[i][j-1]);
			else if (i >= 1)
				dp[i][j] = max(pre_yey[i][j] + dp[i-1][j], pre_blog[i][j]);
			else if (j >= 1)
				dp[i][j] = max(pre_yey[i][j], pre_blog[i][j] + dp[i][j-1]);
			else
				dp[i][j] = max(pre_yey[i][j], pre_blog[i][j]);
			
			// cout << dp[i][j] << " ";
		}
		// cout << "\n";
	}

	cout << dp[n-1][m-1] << "\n";
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
	// cin >> t;
	// for (int i = 1; i <= t; i++) {
	// 	// cout << "Case #" << i << ": ";
	// 	solve();
	// }
	ll n, m;
	cin >> n >> m;
	while (n) {
		solve(n, m);
		cin >> n >> m;
	}

	cerr << "time: "<<(double)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}
