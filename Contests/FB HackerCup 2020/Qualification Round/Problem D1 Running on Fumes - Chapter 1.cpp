#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;
#define mod 1000000007
#define MAX 1000001

//Problem D1: Running on Fumes - Chapter 1
ll dp[MAX];
bool ready[MAX];
ll n, m;

ll min(ll x, ll y) {
	if (x < y)
		return x;
	else 
		return y;
}

ll minfuel(vector<ll> &c, ll i = n-1) {
	if (i <= m)
		return 0;

	if (ready[i])
		return dp[i];

	bool flag = 0;
	ll sum = 9223372036854775807, x;		//max value for long long
	for (ll j = 1; j <= m; j++) {
		if (c[i-j] != 0 && dp[i-j] != -1) {
			flag = 1;
			x = minfuel(c, i-j);
			if (x == -1) {
				flag = 0;
				break;
			}
			sum = min(sum, c[i-j] + x);	
		}
	}
	ready[i] = 1;
	if (flag == 0)
		return dp[i] = -1;
	else {
		dp[i] = sum;
		return sum;
	}
} 

void print(vector<ll> &c) {
	ll i;
	cout << "i:  ";
	for (i = 0; i < n; i++)
		cout << i << " ";
	
	cout << "\ndp: ";
	for (i = 0; i < n; i++)
		cout << dp[i] << " ";

	cout << "\nc:  ";
	for (i = 0; i < n; i++)
		cout << c[i] << " ";

}

void solve() {
	cin >> n >> m;
	vector<ll> c(n);
	for (ll i = 0; i < n; i++) {
		cin >> c[i];
		ready[i] = 0;
		dp[i] = 0;
	}

	cout << minfuel(c) << "\n";
//	print(c);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

/*	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
	//freopen is used to associate a file with stdin or stdout stream in C++
	#endif
*/
	st t = 1;
	cin >> t;
	for (st i = 0; i < t; i++) {
		cout << "Case #" << i+1 << ": ";
		solve();
	}

//	cerr << "time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}
