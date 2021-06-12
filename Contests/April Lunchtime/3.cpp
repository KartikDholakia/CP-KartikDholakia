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
#define loop_diff(var, start, end, diff) for (ll var = start; var < end; var += diff)
#define loop(var, start, end) for (ll var = start; var < end; var++)

//3. 
//April Lunchtime
void solve() {
	ll n, w_min, w_rod, inp, i;
	cin >> n >> w_min >> w_rod;

	map<ll, ll> m;
	loop(i, 0, n) {
		cin >> inp;
		m[inp]++;
	}

	if (w_rod >= w_min) {
		cout << "YES\n";
		return;
	}

	ll sum = 0;
	bool flag = 0;
	for (auto it = m.begin(); it != m.end(); it++) {
		sum += it->first * (it->second - (it->second % 2));
		if (sum >= w_min - w_rod) {
			flag = 1;
			break;
		}
	}

	if (flag)
		cout << "YES\n";
	else
		cout << "NO\n";
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
