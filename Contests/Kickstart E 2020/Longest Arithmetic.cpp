#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;
#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807

//Longest Arithmetic
//Kickstart E 2020
void solve() {
	int n, ans = 2, i, cnt = 2;
	cin >> n;
	ll diff = 0, prev;
	vector<ll> v(n, 0);
	for (i = 0; i < n; i++)	cin >> v[i];

	//cout << "\n";
	for (i = 1; i < n; i++) {
		diff = v[i] - v[i-1];
		if (i != 1) {
			if (diff == prev)
				cnt++;
			else {
				if (ans < cnt)
					ans = cnt;
				cnt = 2;
			}
		}
		prev = diff;
	//	cout << i << setw(3) << diff << setw(3) << prev << setw(3) << cnt << setw(3) << ans << "\n";
	}

	if (cnt > ans)
		ans = cnt;

	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
	//freopen is used to associate a file with stdin or stdout stream in C++
	#endif

	st t = 1;
	cin >> t;
	for (st i = 0; i < t; i++) {
		cout << "Case #" << i+1 << ": ";
		solve();
	}

	cerr << "time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}