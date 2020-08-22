#include<bits/stdc++.h> 
using namespace std; 
typedef long long ll;
typedef short int st; 
#define mod 1000000007
 
//C. Make It Good Codeforces Round #656 (Div. 3)
//upsolved :(
void solve() {
	int n, i;
	cin >> n;
	vector<int> a(n);
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	for (i = n-1; i > 0 && a[i-1] >= a[i]; i--) {}
	
	for (; i > 0 && a[i-1] <= a[i]; i--) {}

	cout << i << "\n";
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
