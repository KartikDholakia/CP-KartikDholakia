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

//DP | 3D
//https://www.spoj.com/problems/TOURIST/
void solve() {
	int h, w, i, j;
	cin >> w >> h;
	char city[h+1][w+1];

	loop(i, 1, h+1)
		loop(j, 1, w+1)
			cin >> city[i][j];

	int dp[h+1][w+1][w+1];
	mem(dp, 0);

	int temp1, temp2, x1, y1, x2, y2;
	//x1, y1 -> coord of 1st person while going from (1, 1) to (h, w)
	//x2, y2 -> coord of 2nd person while going from (1, 1) to (h, w)

	loop(y1, 1, h+1) {
		loop(x1, 1, w+1) {
			loop(x2, 1, w+1) {
				//x1 + y1 = x2 + y2
				y2 = x1 + y1 - x2;
				if (y2 < 1 || y2 > h)
					continue;

				if (city[y1][x1] == '#') {
					dp[y1][x1][x2] = -1;
					continue;
				}

				if (city[y2][x2] == '#') {
					dp[y1][x1][x2] = -1;
					continue;
				}

				temp1 = (city[y1][x1] == '*');
				temp2 = (city[y2][x2] == '*');
				dp[y1][x1][x2] = max(
					max(dp[y1-1][x1][x2], dp[y1][x1-1][x2]),
					max(dp[y1-1][x1][x2-1], dp[y1][x1-1][x2-1])
				) + temp1 + temp2;

				if (x1 == x2 && y1 == y2 && city[y1][x1] == '*')
					dp[y1][x1][x2]--;
			}
		}
	}

	cout << dp[h][w][w] << "\n";
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