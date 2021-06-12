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

//2. Alien
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
	ll g, i, temp, ans = 0;
	cin >> g;

	for (i = 1; i <= g && i*(i-1) < 2*g; i++) {
		temp = 2*g - i*(i-1);
		if ((temp % (2*i)) == 0) {
			ans++;
			// cout << i << " ";
		}
	}

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
