#include<bits/stdc++.h> 
using namespace std; 
typedef unsigned long long ll;
typedef unsigned short int st; 

//A. Required Remainder Codeforces Round #653 (Div. 3)
void solve() {
	int x, y, n;
	cin >> x >> y >> n;
	if (n%x == y)
		cout << n << "\n";
	else if (n < x) {
		cout << y << "\n";
	}
	else {
		if (n%x > y)
			cout << n - n%x + y << "\n";
		else
			cout << n - n%x - x + y << "\n";
	}
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

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
		solve(); 

	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0; 
} 
