#include<bits/stdc++.h> 
using namespace std; 
typedef long long ll;
typedef short int st; 
#define mod 1000000007
 
//Chef and Linear Chess
bool isprime(int n) { 
    if (n <= 1) 
        return false; 
  
    for (int i = 2; i < n; i++) 
        if (n % i == 0) 
            return false; 
  
    return true; 
} 

void solve() {
	st n;
	int k, p, ans = INT_MAX, temp, pos;
	cin >> n >> k;

	// if (isprime(k)) {
	// 	cout << -1 << "\n";
	// 	return;
	// }

	bool flag = 0;
	for (int i = 0; i < n; i++) {
		cin >> p;
		if (k%p == 0) {
			temp = k/p - 1;
			flag = 1;
			if (temp < ans) {
				ans = temp;
				pos = p;
			}
		}
	}
	if (flag)
		cout << pos << "\n";
	else
		cout << -1 << "\n";
}
 
int main() { 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("error.txt", "w", stderr); 
	freopen("output.txt", "w", stdout); 
	//freopen is used to associate a file with stdin or stdout stream in C++
	#endif 
 
	st t = 1;
	cin >> t;
	for (st i = 0; i < t; i++)
		solve(); 
 
	cerr << "time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0; 
} 
