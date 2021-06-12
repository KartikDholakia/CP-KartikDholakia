#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()

//C. Strange Birthday Party
//Codeforces Round #694 (Div. 2)
void solve() {
	ll n, m, i, j;
	ll ans = 0;
	cin >> n >> m;

	vector<ll> v(n), c(m);
	for (i = 0; i < n; i++)
		cin >> v[i];

	sort(all(v), greater<ll>());
	
	for (i = 0; i < m; i++)
		cin >> c[i];

	j = 0;
	for (i = 0; i < n; i++) {
		if (c[j] < c[v[i] - 1] && j < m) {
			ans += c[j];
			j++;
		}
		else
			ans += c[v[i] - 1];
	}

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

	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		// cout << "Case #" << i << ": ";
		// cout << "Test " << i << ":\n";
		solve();
	}

	cerr << "time: "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}