#include<bits/stdc++.h> 
using namespace std; 
typedef long long ll;
typedef short int st; 
#define mod 1000000007

//EDIST - Edit distance SPOJ
//https://www.spoj.com/problems/EDIST/
string a, b;
int d[2001][2001];

int min(int x, int y, int z) {
	if (x < y && x < z)
		return x;
	else {
		if (y < z)
			return y;
		else
			return z;
	}
}

int ed(int i, int j) {
	if (d[i][j] != -1)
		return d[i][j];

	bool cost = 1;
	if (a[i-1] == b[j-1])
		cost = 0;

	return d[i][j] = min(ed(i-1, j-1)+cost,
						ed(i-1, j)+1,
						ed(i, j-1)+1);
}

int solve() {
	//cin.ignore();
	getline(cin, a);
	getline(cin, b);

	int n = a.size(), m = b.size();
	
	for (int i = 1; i <= n; i++)
		for (int j = 1;  j <= m; j++)
			d[i][j] = -1;

	ed(n, m);
	cout << d[n][m] << "\n";
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

	for (int i = 0; i < 2001; i++) {
		d[0][i] = i;
		d[i][0] = i;
	}

	st t = 1;
	cin >> t;
	getline(cin, a);
	for (st i = 0; i < t; i++)
		solve(); 

	cerr << "time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0; 
} 

