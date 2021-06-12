#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//Sieve:
bool prime[10000001];
vector<ll> cntPrimes(10000001, 0);

void SieveOfEratosthenes(ll n) {
	memset(prime, true, sizeof(prime));

	for (ll p = 2; p * p < n; p++) {
		if (prime[p] == true) {
			for (ll i = p * p; i < n; i += p)
				prime[i] = false;
		}
	}

	for (ll i = 2; i < n; i++) {
		cntPrimes[i] = cntPrimes[i-1];
		if (prime[i])
			cntPrimes[i]++;
	}
}

//(x^y) % k:
ll power(ll x, ll y, ll k) {
	ll res = 1;
	x = x % k;

	if (x == 0) return 0;

	while (y > 0) {
		if (y & 1)
			res = (res*x) % k;
		y = y >> 1;
		x = (x*x) % k;
	}
	return res;
}
