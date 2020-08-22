#include<bits/stdc++.h> 
using namespace std; 
typedef unsigned long long ll;
typedef short int st; 

//Ada King ADAKING July Challenge 2020 Division 2
vector<vector<char>> out;

void display() {
	for (st i = 0; i < 8; i++) {
		for (st j = 0; j < 8; j++) {
			cout << out[i][j];
		}
		cout << "\n";
	}
}

void solve() {
	st k, i, j;
	cin >> k;

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			out[i][j] = 'X';
		}
	}
	
	st count = 0;
	for (i = 0; i < 8 && count < k; i++) {
		for (j = 0; j < 8 && count < k; j++) {
			out[i][j] = '.';
			count++;
		}
	}
	out[0][0] = 'O';
	
	display();
	cout << "\n";
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

	for (st i = 0; i < 8; i++) {
		out.push_back(vector<char> ());
		for (st j = 0; j < 8; j++) {
			out[i].push_back('X');
		}
	}

	st t = 1;
	cin >> t;
	for (st i = 0; i < t; i++)
		solve(); 

	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0; 
} 
