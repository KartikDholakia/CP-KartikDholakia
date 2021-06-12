#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()

//1. Prime Tuples
//January Cook-Off 2021
vector<bool> prime(MAX, 1);
vector<int> primes;
vector<int> dp(MAX, 0);

void SieveOfEratosthenes() {
	for (int p = 2; p*p < MAX; p++) {
		// If prime[p] is not changed, then it is a prime 
		if (prime[p] == true)  {
			for (int i = p*p; i < MAX; i += p)
				prime[i] = false; 
		} 
	} 

	for (int i = 2; i < MAX; i++) {
		if (prime[i])
			primes.push_back(i);
	}
}

void precompute() {
	int i, ans = 0;
	for (i = 1; i < primes.size(); i++) {
		if (primes[i] - primes[i-1] == 2) {
			ans++;
			dp[primes[i]] = ans;
		}
	}
	ans = 0;
	for (i = 0; i < MAX; i++) {
		if (dp[i])
			ans = dp[i];
		else
			dp[i] = ans;
	}
}

// void solve() {

// }

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

	int t = 1, n;
	cin >> t;
	SieveOfEratosthenes();
	precompute();
	for (int i = 1; i <= t; i++) {
		cin >> n;
		cout << dp[n] << "\n";
		// solve();
	}

	cerr << "time: "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}