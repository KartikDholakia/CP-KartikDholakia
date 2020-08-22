#include<bits/stdc++.h> 
using namespace std; 
typedef long long ll;
typedef short int st; 
#define mod 1000000007

//B. Restore the Permutation by Merger Codeforces Round #656 (Div. 3)
void solve() {
	st n, x;
	cin >> n;
	set<st> s; 
	for (st i = 0; i < 2*n; i++) {
		cin >> x;
		if (s.find(x) == s.end()) {
			cout << x << " ";
			s.insert(x);
		}
	}
	cout << "\n";
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

