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

//https://codeforces.com/contest/1560/problem/D
//Min Edit Distance | DP
//Codeforces Round #739 (Div. 3)
vector<ll> powerof2;

void generate() {
	ll k = 1;
	for (ll i = 0; i <= 63; i++) {
		powerof2.pb(k);
		k = k*2;
	}
}

ll minEdit(string a, string b) {
	ll m = a.size(), n = b.size();
	ll dp[m + 1][n + 1];

	for (ll i = 0; i <= m; i++) {
		for (ll j = 0; j <= n; j++) {
			if (i == 0)
				dp[i][j] = j;

			else if (j == 0)
				dp[i][j] = i;

			else if (a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1];

			// else
			// 	dp[i][j]
			// 		= 1
			// 			+ min(dp[i][j - 1], min(
			// 				dp[i - 1][j],
			// 				dp[i - 1][j - 1]));
			else
				dp[i][j] = dp[i-1][j] + 1;
		}
	}

	return dp[m][n];
}

void solve() {
	ll n;
	cin >> n;

	string num = to_string(n), ts;
	ll mn = INT_MAX, temp;
	reverse(all(num));

	for (ll i = 0; i < powerof2.size(); i++) {
		string a = to_string(powerof2[i]);
		reverse(all(a));
		temp = minEdit(num, a);
		// mn = min(mn, temp);
		if (temp < mn) {
			mn = temp;
			ts = a;
		}
	}

	// cout << mn << " " << ts << "\n";
	cout << mn << "\n";
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

	generate();

	// for (ll i = 0; i < powerof2.size(); i++)
	// 	cout << powerof2[i] << " ";
	// cout << "\n";

	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		// cout << "Case " << i << ": ";
		solve();
	}

	cerr << "time: "<<(double)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}