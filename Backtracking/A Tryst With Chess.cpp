#include<bits/stdc++.h> 
using namespace std; 
typedef unsigned long long ll;
typedef short int st; 

//A Tryst With Chess
bool chess[10][10];

int tryst(st i, st j, st m) {
	if ((i < 1) || (j < 1) || (i > 10) || (j > 10))
		return -1;
	
	if (m == 0 && chess[i-1][j-1] != 1) {
		chess[i-1][j-1] = 1;
		return 0;
	}
	int count = 0;
	count += 1 + tryst(i-2, j+1, m-1);
	count += 1 + tryst(i-1, j+2, m-1);
	count += 1 + tryst(i+1, j+2, m-1);
	count += 1 + tryst(i+2, j+1, m-1);
	count += 1 + tryst(i+2, j-1, m-1);
	count += 1 + tryst(i+1, j-2, m-1);
	count += 1 + tryst(i-1, j-2, m-1);
	count += 1 + tryst(i-2, j-1, m-1);
	return count;
}

void solve() {
	st i, j, n;
	cin >> i >> j >> n;
	for (st x = 0; x < 10; x++)
		for (st y = 0; y < 10; y++)
			chess[x][y] = 0;
	cout << tryst(i, j, n) << "\n";
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

//	st t;
//	cin >> t;
//	for (int i = 0; i < t; i++)
		solve(); 

//	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0; 
} 
