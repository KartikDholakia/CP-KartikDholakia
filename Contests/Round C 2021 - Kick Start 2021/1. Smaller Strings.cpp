#include<bits/stdc++.h>
using namespace std;
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
#define loop_diff(var, start, end, diff) for (ll var = start; var < end; var += diff)
#define loop(var, start, end) for (auto var = start; var < end; var++)
#define loop_rev(var, start, end) for(auto var = start; var > end; var--)

//1. Smaller Strings
//Round C 2021 - Kick Start 2021
ll power(ll x, ll y, ll k = MOD) {
	ll res = 1;
	x = x % k;

	if (x == 0) return 0;

	while (y > 0) {
		if (y & 1)
			res = (res*x) % k;
		y = y >> 1;
		x = (x*x) % k;
	}
	return res;
}

void solve() {
	ll n, k, i;
	cin >> n >> k;
	
	string s;
	cin >> s;

	ll mid = (n+1)/2;
	ll j = mid-1, ans = 0, c;

	loop(i, 0, mid) {
		c = min(s[i], s[n-i-1]);
		// if ((i == n/2) && (n % 2))
		// 	c = s[i];
		ans = (((s[i] - 'a') * power(k, j)) + ans) % MOD;
		j--;
	}

	string temp;
	loop(i, 0, mid)
		temp.pb(s[i]);

	if (n % 2) {
		for (i = mid-2; i >= 0; i--)
			temp.pb(s[i]);
	}
	else {
		for (i = mid-1; i >= 0; i--)
			temp.pb(s[i]);
	}

	// cout << temp << "\n";

	if (temp < s)
		cout << (ans+1) % MOD << "\n";
	else
		cout << ans << "\n";
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
