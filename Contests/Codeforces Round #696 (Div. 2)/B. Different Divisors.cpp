#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()

//B. Different Divisors
//Codeforces Round #696 (Div. 2)

vector<bool> prime(MAX, 1);
void SieveOfEratosthenes() {
	for (ll p = 2; p*p < MAX; p++) {
		// If prime[p] is not changed, then it is a prime 
		if (prime[p] == true)  {
			for (ll i = p*p; i <= MAX; i += p)
				prime[i] = false; 
		} 
	} 
}

ll smallestPrime(int n) {
	int ans = n;
	while (1) {
		if (prime[ans])
			return ans;
		ans++;
	}
}

void solve() {
	ll n, a, b, d;
	cin >> d;
	a = smallestPrime(1 + d);
	b = smallestPrime(d + a);
	n = a*b;
	// cout << a << " " << b << " ";
	cout << n << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
	//freopen is used to associate a file with stdin or stdout stream in C++
	#endif

	int t = 1;
	cin >> t;
	SieveOfEratosthenes();
	for (int i = 1; i <= t; i++) {
		solve();
	}

	cerr << "time: "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}