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
#define loop(var, start, end) for (ll var = start; var < end; var++)

//https://codeforces.com/contest/1515/problem/D
void solve() {
	ll n, l, r, i, inp, j;
	cin >> n >> l >> r;

	vector<pll> cnt;	//first -> cnt_l, second -> cnt_r
	loop(i, 0, n+1)
		cnt.pb(mp(0, 0));

	loop(i, 0, n) {
		cin >> inp;
		if (i < l)
			cnt[inp].first++;
		else
			cnt[inp].second++;
	}

	vll left, right;
	ll a, b, diff, ans = 0;
	for (i = 1; i <= n; i++) {
		a = cnt[i].first;
		b = cnt[i].second;
		diff = abs(a-b);
		if (diff && (l != r) /*&& ((a + b) % 2 == 0)*/) {
			if (l < r) {
				// if (cnt[i].second >)
				l += diff/2;
				r -= diff/2;
				cnt[i].first += diff/2;
				cnt[i].second -= diff/2;
				ans += diff/2;
			}
			else {
				l -= diff/2;
				r += diff/2;
				cnt[i].first -= diff/2;
				cnt[i].second += diff/2;
				ans += diff/2;
			}
		}
		a = cnt[i].first;
		b = cnt[i].second;
		loop(j, 0, a)
			left.pb(i);

		loop(j, 0, b)
			right.pb(i);
	}

	// loop(i, 1, n+1) {

	// }

	loop(i, 0, n/2) {
		if (left[i] != right[i])
			ans++;
	}

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
