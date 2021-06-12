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

//2. 
//April Lunchtime
//(x^y) % MOD:
ll power(ll x, ll y) {
    ll res = 1;
    x = x % MOD;
  
    if (x == 0) return 0;
 
    while (y > 0) {
        if (y & 1)
            res = (res*x) % MOD;
        y = y >> 1;
        x = (x*x) % MOD;
    }
    return res;
}

// ll mod(ll a, ll b) {
// 	ll c = a % b
// 	return (c < 0) ? c + b : c;
// }

void solve() {
	ll n, i, sum = 0, inp;
	cin >> n;

	loop(i, 0, n) {
		cin >> inp;
		sum = (sum + inp) % MOD;
	}
	
	ll q, x;
	cin >> q;

	loop(i, 0, q) {
		cin >> x;
		sum = (sum * (ll)2) % MOD;
		if (sum < 0)
			sum = sum + MOD;
		cout << sum << "\n";
	}
	
	// sum = (sum * power(2, q)) % MOD;
	// cout << sum;
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

	cerr << "time: "<<(double)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}
