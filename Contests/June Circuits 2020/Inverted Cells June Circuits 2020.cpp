#include<bits/stdc++.h> 
using namespace std; 
typedef unsigned long long ll;
typedef unsigned short int st; 

//Inverted Cells June Circuits 2020
st n, m;
vector<vector<char>> given;
vector<vector<short>> out;

bool ifblock(st i = 0, st j = 0) {
	if ((i == n-1) && (j == m-1))
		return 1;
	if ((i >= n) || (j >= m))
		return 0;
	if (given[i][j] == '#')
		return 0;
	bool flag = ifblock(i+1, j);
	if (!flag)
		flag = ifblock(i, j+1);
	//cout << "return from " << i << ", " << j << ": " << flag << "\n";
	return flag;
}

void show() {
	for (st i = 0; i < n; i++) {
		for (st j = 0; j < m; j++) {
			cout << out[i][j] << " ";
		}
		cout << "\n";
	}
}

void solve() {
	st i, j;
	char inp;
	cin >> n >> m;
	
	
	for (i = 0; i < n; i++) {
		given.push_back(vector<char> ());
		out.push_back(vector<short> ());
		for (j = 0; j < m; j++) {
			cin >> inp;
			given[i].push_back(inp);
			out[i].push_back(-1);
		}
	}

	if ((given[0][0] == '#')||(given[n-1][m-1] == '#')) {
		
		if ((given[0][0] == '#')&&(given[n-1][m-1] == '#')) {
			for (i = 0; i < n; i++)
				for (j = 0; j < m; j++)
					out[i][j] = 0;
		}
		
		else if (given[0][0] == '#') {
			for (i = 0; i < n; i++)
				for (j = 0; j < m; j++)
					out[i][j] = 0;	
			out[0][0] = 1;
		}

		else if (given[n-1][m-1] == '#'){
			for (i = 0; i < n; i++)
				for (j = 0; j < m; j++)
					out[i][j] = 0;	
			out[n-1][m-1] = 1;
		}

		show();
		return;
	}

	out[0][0] = 0;
	out[n-1][m-1] = 0;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (out[i][j] == -1) {
				if (given[i][j] == '.') {
					given[i][j] = '#';
					out[i][j] = ifblock();			
					given[i][j] = '.';
				}
				else {
					given[i][j] = '.';
					out[i][j] = ifblock();			
					given[i][j] = '#';
				}
			}
		}
	}
	show();
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

	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0; 
} 
