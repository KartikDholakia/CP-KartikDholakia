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

//B: Xs and Os 
//FB Hackercup 2021
void solve() {
	ll n, i, j, ways = 0, ans = INT_MAX;
	cin >> n;
	// ways = 2*n;

	char inp[n][n];
	loop(i, 0, n)
		loop(j, 0, n)
			cin >> inp[i][j];
	
	vll cols(n, 0), rows(n, 0);

	//for cols:
	loop(j, 0, n) {
		loop(i, 0, n) {
			if (inp[i][j] == '.')
				cols[j]++;
			else if (inp[i][j] == 'O') {
				cols[j] = INT_MAX;
				// ways--;
				break;
			}
		}
		ans = min(ans, cols[j]);
	}

	//for rows:
	loop(i, 0, n) {
		loop(j, 0, n) {
			if (inp[i][j] == '.')
				rows[i]++;
			else if (inp[i][j] == 'O') {
				rows[i] = INT_MAX;
				// ways--;
				break;
			}
		}
		ans = min(ans, rows[i]);
	}

	if (ans == INT_MAX) {
		cout << "Impossible\n";
		return;
	}

	loop(j, 0, n) {
		if (cols[j] == ans)
			ways++;
	}

	bool flag = 1;
	loop(i, 0, n) {
		flag = 1;
		if ((ans == 1) && (rows[i] == 1)) {
			loop(j, 0, n) {
				if (inp[i][j] == '.' && cols[j] == 1) {
					flag = 0;
					break;
				}
			}
			if (flag)
				ways++;
		}
		else if ((rows[i] == ans) && (ans != 1))
			ways++;
	}

	cout << ans << " " << ways << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// #ifndef ONLINE_JUDGE
	// //remove this piece of code when this has to be submitted in kickstart
	// freopen("input.txt", "r", stdin);
	// freopen("error.txt", "w", stderr);
	// freopen("output.txt", "w", stdout);
	// //freopen is used to associate a file with stdin or stdout stream in C++
	// #endif

	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}

	cerr << "time: "<<(double)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}