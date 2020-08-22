#include<bits/stdc++.h> 
using namespace std; 
typedef unsigned long long ll;
typedef short int st; 

//Missing a Point PTMSSNG July Challenge 2020 Division 2
void solve() {
	map <int, int> x, y;
	map <int, int> :: iterator itr;
	int n, a, b;
	cin >> n;
	for (int i = 0; i < 4*n-1; i++) {
		cin >> a >> b;
		x[a]++;
		y[b]++;
	}
	for (itr = x.begin(); itr != x.end(); itr++) {
		if ((itr->second)%2 != 0) {
			cout << itr->first << " ";
			break;
		}
	}
	for (itr = y.begin(); itr != y.end(); itr++) {
		if ((itr->second)%2 != 0) {
			cout << itr->first << "\n";
			break;
		}
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

	st t = 1;
	cin >> t;
	for (st i = 0; i < t; i++)
		solve(); 

	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0; 
} 
