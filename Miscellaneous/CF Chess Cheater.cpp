#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

#define MOD 1000000007
#define MAX 1000001					//1e6 + 1
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define mp make_pair

//https://codeforces.com/problemset/problem/1427/B
void solve() {
	ll n, k, i;
	cin >> n >> k;
	string s;
	cin >> s;

	vector<ll> gap;
	ll cnt = 0, cntw = 0;
	for (i = 0; i < n; i++) {
		if (s[i] == 'W') {
			cnt = 0;
			cntw++;
			while ((i < n-1) && (s[i+1] == 'L')) {
				cnt++;
				i++;
			}
			if (i < n-1 && s[i+1] == 'W' && cnt != 0)
				gap.pb(cnt);
		}
	}
	sort(all(gap));

	if (cntw + k >= n) {
		cout << 2*n - 1 << "\n";
		return;
	}

	if (cntw == 0) {
		if (k)
			cout << 2*k-1;
		else
			cout << "0";
		cout << "\n";
		return;
	}

	// for (i = 0; i < gap.size(); i++)
	// 	cout << gap[i] << " ";
	// cout << "\n";

	ll K = k;
	ll cntgaps = 0, temp;
	for (i = 0; i < gap.size() && k != 0; i++) {
		if (gap[i] <= k) {
			temp = gap[i];
			gap[i] = 0;
			k -= temp;
			cntgaps++;
		}
		else {
			temp = gap[i];
			gap[i] -= k;
			k = 0;
		}
	}
	// cout << "cntgap = " << cntgaps << "\n";
	// cout << "cntw = " << cntw << "\n";

	ll ans = 2*(cntw + K) - (gap.size()+1 - cntgaps);
	cout << ans << "\n";
}

/*
9
5 2
WLWLL
6 5
LLLWWL
7 1
LWLWLWL
15 5
WWWLLLWWWLLLWWW
40 7
LLWLWLWWWLWLLWLWWWLWLLWLLWLLLLWLLWWWLWWL
1 0
L
1 1
L
6 1
WLLWLW
2 1
LL
*/

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