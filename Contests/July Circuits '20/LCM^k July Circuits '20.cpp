#include<bits/stdc++.h> 
using namespace std; 
typedef unsigned long long ll;
typedef short int st; 
#define mod 1000000007
#define MAX 1000001
 
//LCM^K July Circuits '20
map<int, ll> max_map;
map<int, ll> :: iterator mit;
int prime[MAX];
 
ll power(int a, ll n, ll m) 
{ 
    if (n == 0) 
        return 1; 
    ll p = power(a, n/2, m) % m; 
    p = (p * p) % m; 
    if (n & 1) 
        p = (p * a) % m; 
    return p; 
} 
 
//stores the smallest prime factor of a number
void sieve() { 
    prime[0] = prime[1] = 1; 
    for (int i = 2; i < MAX; i++) { 
        if (prime[i] == 0) { 
            for (int j = 2 * i; j < MAX; j += i) { 
                if (prime[j] == 0) { 
                    prime[j] = i; 
                } 
            } 
            prime[i] = i; 
        } 
    } 
} 
 
ll lcm(int n, int m, int k, vector<int> &a) {
	int num, fact;
	for (int i = 0;  i < n; i++) {
		num = a[i];
		map<int, ll> temp;
		map<int, ll> :: iterator it;
		while(num > 1) {
			fact = prime[num];
			temp[fact]++;
			num = num/fact;
		}
		for (it = temp.begin(); it != temp.end(); it++)	{
			if (max_map[it->first] < it->second)
				max_map[it->first] = it->second;
			
		}
	}
 
	ll ans = 1;
	for (mit = max_map.begin(); mit != max_map.end(); mit++) {
		ans = (ans*power(mit->first, mit->second, m)) % m;
	}
	return power(ans, k, m);
}
 
void solve() {
	int n, k, m;
	cin >> n >> m >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << lcm(n, m, k, a) << "\n";
}
 
int main() { 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	sieve();
	st t = 1;
	cin >> t;
	for (st i = 0; i < t; i++) {
		solve(); 
		max_map.clear();
	}
 
	return 0; 
} 
