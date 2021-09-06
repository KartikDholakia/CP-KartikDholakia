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

//C1: Gold Mine - Chapter 1
//FB Hackercup 2021
vll adj[51];
bool visited[51];
ll w[51];

ll dfs(ll x) {
	visited[x] = 1;
	ll temp = INT_MIN, i;
	bool flag = 0;

	loop(i, 0, adj[x].size()) {
		if (!visited[adj[x][i]]) {
			temp = max(temp, dfs(adj[x][i]));
			flag = 1;
		}
	}

	if (flag)
		return (temp + w[x]);
	return w[x];
}

void solve() {
	ll n, i, j;
	cin >> n;

	mem(w, 0);
	// vll w(n);
	loop(i, 1, n+1)
		cin >> w[i];

	if (n == 1) {
		cout << w[1] << "\n";
		return;
	}

	mem(visited, 0);
	loop(i, 0, n+1)
		adj[i].clear();
	
	ll a, b;
	loop(i, 0, n-1) {
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	vll gold1;
	visited[1] = 1;
	loop(i, 0, adj[1].size()) {
		ll temp = dfs(adj[1][i]);
		gold1.pb(temp);
	}

	sort(all(gold1), greater<ll>());
	
	if (gold1.size() == 1)
		cout << (ll)(gold1[0] + w[1]) << "\n";
	else
		cout << (ll)(gold1[0] + gold1[1] + w[1]) << "\n";
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