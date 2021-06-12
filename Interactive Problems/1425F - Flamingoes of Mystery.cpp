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

//Interactive Problem
//https://codeforces.com/problemset/problem/1425/F
void ask(ll l, ll r) {
	cout << "? " << l << " " << r << "\n";
    cout.flush();
}

void solve() {
	ll n, i, sum = 0, query, S;
	cin >> n;
	vector<ll> v(n+1, 0);

	ask(1, n);
	cin >> sum;
	S = sum;

	loop(i, 2, n) {
		ask(i, n);
		cin >> query;
		v[i-1] = sum - query;
		sum = query;
	}

	ask(n-2, n-1);
	cin >> query;
	v[n-1] = query - v[n-2];

	sum = 0;
	loop(i, 1, n)
		sum += v[i];

	v[n] = S - sum;

    cout << "! ";
	loop(i, 1, n+1)
		cout << v[i] << " ";
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
	// cin >> t;
	for (int i = 1; i <= t; i++) {
		// cout << "Case #" << i << ": ";
		solve();
	}

//	cerr << "time: "<<(double)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}
