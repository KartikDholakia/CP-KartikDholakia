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

//D
//Codeforces Round #719 (Div. 3)
void solve() {
	ll n, i;
	cin >> n;
	
	vll v(n+1);
	map<ll, ll> dif;
	loop(i, 1, n+1) {
		cin >> v[i];
		dif[v[i] - i]++;
	}

	ll ans = 0;
	ll x;
	for (auto it = dif.begin(); it != dif.end(); it++) {
		x = it->second;
		ans += x*(x-1)/2;
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