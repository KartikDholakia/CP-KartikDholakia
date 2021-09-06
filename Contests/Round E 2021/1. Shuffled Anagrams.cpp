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

//1. Shuffled Anagrams
//Round E 2021 Kickstart
//https://codingcompetitions.withgoogle.com/kickstart/round/000000000043585c/000000000085a152#problem
bool cmp(pair<ll, char> a, pair<ll, char> b) {
	if (a.first == b.first)
		return (a.second < b.second);
	return (a.first > b.first);
}

void solve() {
	string str, ans;
	cin >> str;
	ans = str;
	
	ll cnt[26] = {0}, n = str.size();
	loop(i, 0, n) {
		cnt[str[i] - 'a']++;
		if (cnt[str[i] - 'a'] > n/2) {
			cout << "IMPOSSIBLE\n";
			return;
		}
	}

	vector<pair<ll, char>> order;
	loop(i, 0, 26) {
		if (cnt[i] != 0)
			order.pb(mp(cnt[i], (char)i+'a'));
	}

	sort(all(order), cmp);

	// loop(i, 0, order.size())
	// 	cout << order[i].second << " : " << order[i].first << "\n";
	// cout << "\n";

	ll j, k;
	char c;
	loop(i, 0, order.size()) {
		c = order[i].second;
		// cout << c << ": ";
		loop(j, 0, n) {
			if (str[j] == c) {
				for (k = order.size()-1; k >= 0; k--) {
					if (order[k].first != 0 && order[k].second != c) {
						order[k].first--;
						// cout << ans[j] << " -> ";
						ans[j] = order[k].second;
						// cout << ans[j] << " " << ans << "\n";
						break;
					}
				}
			}
		}
	}

	// loop(i, 0, order.size())
	// 	cout << order[i].second << " : " << order[i].first << "\n";

	cout << ans << "\n";
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