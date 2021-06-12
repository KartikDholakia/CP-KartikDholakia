#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define MOD 1000000007
#define MAX 1000001					//1e6 + 1
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define mp make_pair

//1. Append Sort
//Code Jam 2021 - Round 1A
void solve() {
	ll n, i, ans = 0;
	cin >> n;
	vector<ll> v(n);

	for (i = 0; i < n; i++)
		cin >> v[i];

	ll prev = v[0], d1, d2, diff;
	for (i = 1; i < n; i++) {
		if (v[i] > prev) {
			prev = v[i];
			continue;
		}
		d1 = floor(log10(prev) + 1);
		d2 = floor(log10(v[i]) + 1);
		ans += d1-d2;
		v[i] *= pow(10, d1-d2);

		if (v[i] > prev) {
			prev = v[i];
			continue;
		}

		diff = prev + 1 - v[i];
		if (floor(log10(diff) + 1) > d1-d2) {
			ans++;
			v[i] *= 10;
			prev = v[i];
		}
		else {
			v[i] += diff;
			prev = v[i];
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