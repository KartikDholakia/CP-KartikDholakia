#include<bits/stdc++.h> 
using namespace std; 
typedef unsigned long long ll;
typedef short int st; 

//Chef and Strings CHEFSTR1 July Challenge 2020 Division 2
void solve() {
	int n, prev, curr = 0;
	cin >> n;
	ll sum = 0;
	cin >> prev;
	for (int i = 1; i < n; i++) {
		cin >> curr;
		sum += abs(curr - prev) - 1;
		prev = curr;		
	}
	cout << sum << "\n";
} 

int main()  { 
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
	for (int i = 0; i < t; i++)
		solve(); 

	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0; 
} 
