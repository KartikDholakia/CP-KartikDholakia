#include<bits/stdc++.h> 
using namespace std; 
typedef long long ll;
typedef short int st; 
#define mod 1000000007
 
//Supernatural July Circuits '20
vector<int> a(101, -1);

bool isprime(st n) { 
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

int cs(st x) {
	if (a[x] != -1)
		return a[x];

	if (x == 1)
		return a[x] = 0;

	if (x <= 3)
		return a[x] = 1;

	if (isprime(x)) {
		if (x > 10)
			return a[x] = 0;
		else
			return a[x] = 1;
	}

	st l = x/4, r = x/2;
	int ans = 0;

	for (st i = 2; i <= r; i++) {
		if (x % i == 0 && x/i < 10)
			ans += cs(i);
	}

	return a[x] = ans + (x < 10 ? 1:0);
}

void solve() {
	st n;
	cin >> n;
	cout << cs(n) << "\n";
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
 
	int t = 1;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve(); 
	}
 
	cerr << "time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0; 
} 
