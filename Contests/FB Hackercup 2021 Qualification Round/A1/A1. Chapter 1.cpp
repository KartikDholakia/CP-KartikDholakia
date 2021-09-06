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

//1. 
//FB Hackercup 2021
bool isVowel(char c) {
	return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

void solve() {
	string s;
	ll x = 0, y = 0, i, n;
	vll cnt(26, 0);

	cin >> s;
	n = s.size();
	loop(i, 0, n) {
		if (isVowel(s[i]))
			y++;
		else
			x++;
		cnt[s[i] - 'A']++;
	}

	if (x == 0 || y == 0) {
		if (n == 1)
			cout << "0\n";
		else
			cout << n << "\n";
		return;
	}

	ll ans = INT_MAX, temp;
	loop(i, 0, n) {
		if (isVowel(s[i]))
			temp = 2*(y - cnt[s[i] - 'A']) + x;
		else
			temp = 2*(x - cnt[s[i] - 'A']) + y;
		ans = min(ans, temp);
	}

	cout << ans << "\n";
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