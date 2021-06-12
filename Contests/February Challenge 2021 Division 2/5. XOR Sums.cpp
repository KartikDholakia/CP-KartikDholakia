#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

// #define mod 1000000007
#define mod 998244353
#define MAX 1000001					//1e6 + 1
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define mp make_pair

//5. XOR Sums
//February Challenge 2021 Division 2
vector<int> no_of_1s(31, 0);
vector<ll> m_dp(100001, -1);
vector<int> v;
int n;
int len;	//length of no_of_1s

ll ncr(int n, int r) {
	//https://www.geeksforgeeks.org/program-to-calculate-the-value-of-ncr-efficiently/
    ll p = 1, k = 1;
    if (n - r < r)
        r = n - r;
 
    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
            ll m = __gcd(p, k);
            p /= m;
            k /= m;
            n--;
            r--;
        }
    } 
    else
        p = 1;
 
	return p;
}

ll query(int k) {						//k -> length of subsequence
	if (k == 0)
		return 0;

	if (m_dp[k] != -1)
		return m_dp[k];

	ll sum = 0, number = 0;
	int m;								//no of 1s in ith bits
	for (int i = 0; i <= len; i++) {
		m = no_of_1s[i];
		sum = 0;
		for (int j = 1; j <= min(m, k); j += 2) {
			if (n - m >= k - j) {
				sum = (sum + (ncr(m, j) * ncr(n-m, k-j)) % mod) % mod;
			}
		}
		number = (number + (sum * (ll)pow(2, i)) % mod) % mod;
		// cout << "i = " << i << "; sum = " << sum << "; num = " << number << "\n";
	}

	return (m_dp[k] = (number + query(k-1)) % mod);
}

void solve() {
	cin >> n;
	m_dp[1] = 0;
	len = 0;

	int i, inp, q, x, j;
	for (i = 0; i < n; i++) {
		cin >> inp;
		v.pb(inp);
		//storing no of 1s in each bit
		x = log2(inp);
		for (j = 0; j <= x; j++) {
			no_of_1s[j] += ((inp & (1 << j)) >> j);
		}
		
		if (x > len)
			len = x;

		//sum of all elements:
		m_dp[1] = (m_dp[1] + inp) % mod;
	}

	// cout << len << "\n";
	// for (j = 0; j <= len; j++)
	// 	cout << no_of_1s[j] << " ";
	// cout << "\n";

	cin >> q;
	while (q--) {
		cin >> inp;
		cout << query(inp) << "\n";
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
	// cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
	}

	cerr << "time: "<<(double)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}