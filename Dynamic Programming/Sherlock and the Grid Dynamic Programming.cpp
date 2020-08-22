#include<bits/stdc++.h> 
using namespace std; 
typedef unsigned long long ll;
typedef short int st; 
#define mod 1000000007
#define MAX 1000001
 
//Sherlock and the Grid
//Dynamic Programming
//https://www.codechef.com/problems/GRID
void solve() {
	int n, i, j;
	cin >> n;
	vector<vector<char>> inp_mat;
	vector<vector<bool>> rx, ry;
	char inp;
	
	for (i = 0; i < n; i++) {
		inp_mat.push_back(vector<char> ());
		rx.push_back(vector<bool> ());
		ry.push_back(vector<bool> ());
		for (j = 0; j < n; j++) {
			cin >> inp;
			inp_mat[i].push_back(inp);
			rx[i].push_back(0);
			ry[i].push_back(0);
		}
	}

	for (i = 0; i < n; i++) {
		for (j = n-1; j >= 0; j--) {

			if (inp_mat[i][j] == '.') {
				if (j == n-1)
					rx[i][j] = 1;
				else
					rx[i][j] = rx[i][j+1];
			}
			else 
				rx[i][j] = 0;

			if (inp_mat[j][i] == '.') {
				if (j == n-1) 
					ry[j][i] = 1;
				else
					ry[j][i] = ry[j+1][i];
			}
			else
				ry[j][i] = 0; 
		}
	}

	int count = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if ((rx[i][j] == ry[i][j]) && (rx[i][j] ==  1))
				count++;
		}
	}

	cout << count << "\n";
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
	for (st i = 0; i < t; i++) {
		solve(); 
	}
 
	cerr << "time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0; 
} 
