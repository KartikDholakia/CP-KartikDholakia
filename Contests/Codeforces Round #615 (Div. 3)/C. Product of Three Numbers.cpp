#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define MOD 1000000007
#define MAX 1000001					//1e6 + 1
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define mp make_pair

//C. Product of Three Numbers
//Codeforces Round #615 (Div. 3)
bool isPrime(ll n) {
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
  
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
}

void solve() {
	ll n, i;
	cin >> n;

	if (isPrime(n)) {
		cout << "NO\n";
		return;
	}

	ll temp = n;
	map<ll, ll> primeFactors;
    while (n % 2 == 0) {
		primeFactors[2]++;
        n = n/2;
    }  
  
    for (ll i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
			primeFactors[i]++;
            n = n/i;  
        }  
    }  
  
    if (n > 2)  
		primeFactors[n]++;
	
	ll a, b, c;
	if (primeFactors.size() >= 3) {
		auto it = primeFactors.begin();
		a = it->first;
		it++;
		b = it->first;
		c = temp/(a*b);
		cout << "YES\n";
		cout << a << " " << b << " " << c << "\n";
	}

	else if (primeFactors.size() == 2) {
		bool flag = 1;
		auto it = primeFactors.begin();
		a = it->first;
		if (it->second < 2) 
			flag = 0;
		it++;
		b = it->first;
		if (it->second < 2) 
			flag = 0;
		
		if (flag) {
			c = temp/(a*b);
			cout << "YES\n";
			cout << a << " " << b << " " << c << "\n";
		}
		else {
			cout << "NO\n";
			return;
		}
	}

	else {
		auto it = primeFactors.begin();
		if (it->second <= 5) {
			cout << "NO\n";
			return;
		}

		a = it->first;
		cout << "YES\n";
		cout << a << " " << a*a << " " << temp/(a*a*a) << "\n";
	}
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