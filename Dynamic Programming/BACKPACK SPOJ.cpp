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

//https://www.spoj.com/problems/BACKPACK/
//Knapsack version | DP
struct item {
	ll v, c, u;
	item (ll x, ll y, ll z): v(x), c(y), u(z) {}
};

struct item1 {
	ll v, c, sz;
	item1(ll x, ll y, ll z): v(x), c(y), sz(z) {}
	item1(): v(0), c(0), sz(0) {}
};

ll dp[61][32001];
ll knapsack(vector<item1> &list, ll n, ll v) {
	if (n < 0)
		return 0;

	if (dp[n][v] != -1)
		return dp[n][v];

	if (list[n].v <= v) {
		return dp[n][v] = max((knapsack(list, n-1, v - list[n].v) + list[n].v * list[n].c)
							,knapsack(list, n-1-list[n].sz, v));
	}
	else {
		return dp[n][v] = knapsack(list, n-1-list[n].sz, v);
	}
}

void solve() {
	memset(dp, -1, sizeof(dp));
	ll V, n, i, j, k;
	cin >> V >> n;

	vector<item> data;
	data.pb(item(-1, -1, -1));
	ll x, y, z, main_items = 0;

	loop(i, 1, n+1) {
		cin >> x >> y >> z;
		data.pb(item(x, y, z));
		if (z == 0)
			main_items++;
	}

	unordered_map<ll, vll> list;
	//inserting main items:
	loop(i, 1, n+1) {
		if (data[i].u == 0)
			list[i].resize(0);
	}

	//inserting attachments:
	loop(i, 1, n+1) {
		if (data[i].u)
			list[data[i].u].pb(i);
	}

	// debug: list
	// for (auto it: list) {
	// 	cout << it.first << ": " << "(" << it.second.size() << ") ";
	// 	for (j = 0; j < it.second.size(); j++) {
	// 		cout << it.second[j] << " ";
	// 	}
	// 	cout << "\n";
	// }

	vector<item1> final_list;
	ll idx;
	for (auto it: list) {
		idx = it.first;
		final_list.pb(item1(data[idx].v, data[idx].c, it.second.size()));
		for (j = 0; j < it.second.size(); j++) {
			idx = it.second[j];
			final_list.pb(item1(data[idx].v, data[idx].c, 0));
		}
	}

	//debug: final list
	// for (i = 0; i < final_list.size(); i++)
	// 	cout << final_list[i].v << " " << final_list[i].c << " " << final_list[i].sz << "\n";

	reverse(all(final_list));
	cout << knapsack(final_list, n, V) << "\n";
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
