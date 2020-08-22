#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;
#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807

//Dessert Wizard
//Dynamic Programming
//https://www.codechef.com/problems/DELISH
void solve() {
	int n, i;
	cin >> n;
	vector<ll> v(n+1, 0);
	for (i = 1; i <= n; i++)
		cin >> v[i];

	vector<ll> dplmax(n+1, 0);
	vector<ll> dplmin(n+1, 0);
	
	for (i = 1; i <= n; i++) {
		dplmax[i] = max(dplmax[i-1] + v[i], v[i]);
		dplmin[i] = min(dplmin[i-1] + v[i], v[i]);
	}

	for (i = 2; i <= n; i++) {
		dplmax[i] = max(dplmax[i-1], dplmax[i]);
		dplmin[i] = min(dplmin[i-1], dplmin[i]);
	}

	vector<ll> dprmax(n+1, 0);
	vector<ll> dprmin(n+1, 0);
	
	dprmax[n] = v[n];
	dprmin[n] = v[n];

	for (i = n-1; i >= 1; i--) {
		dprmax[i] = max(dprmax[i+1] + v[i], v[i]);
		dprmin[i] = min(dprmin[i+1] + v[i], v[i]);
	}

	for (i = n-1; i >= 1; i--) {
		dprmax[i] = max(dprmax[i+1], dprmax[i]);
		dprmin[i] = min(dprmin[i+1], dprmin[i]);
	}

	ll diff = 0, ans = 0;
	for (i = 1; i <= n-1; i++) {
		diff = abs(dplmax[i] - dprmin[i+1]);
		ans = max(ans, diff);
		diff = abs(dplmin[i] - dprmax[i+1]);
		ans = max(ans, diff);
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

	st t = 1;
	cin >> t;
	for (st i = 0; i < t; i++) {
		solve();
	}

	cerr << "time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}