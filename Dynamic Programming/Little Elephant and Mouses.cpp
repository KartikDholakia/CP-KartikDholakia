#include<bits/stdc++.h> 
using namespace std; 
typedef long long ll;
typedef short int st; 
#define mod 1000000007
#define MAX 1000001
 
//Little Elephant and Mouses
//Dynamic Programming
//unsolved :(
int a[100][100];
st n, m;

int min(int x, int y) {
	if (x > y)
		return y;
	else
		return x;
}

int minreq(vector<vector<char>> &inp, set <pair<st, st>> crd, st i = 0, st j = 0) {
	if (i >= n || j >= m) 
		return 0;

	if (a[i][j] != -1)
		return a[i][j];

	int cnt = 0;

	if ((inp[i][j] == '1') && (crd.find(pair<st, st> (i, j)) == crd.end())) {
		cnt++;
		crd.insert(pair<st, st> (i, j));	
	}
	
	if ((i > 0) && (inp[i-1][j] == '1') && (crd.find(pair<st, st> (i-1, j))) == crd.end()) {
		cnt++;
		crd.insert(pair<st, st> (i-1, j));	
	}
	
	if ((i < n-1) && (inp[i+1][j] == '1') && (crd.find(pair<st, st> (i+1, j))) == crd.end()) {
		cnt++;
		crd.insert(pair<st, st> (i+1, j));
	}
	
	if ((j > 0) && (inp[i][j-1] == '1') && (crd.find(pair<st, st> (i, j-1))) == crd.end()) {
		cnt++;
		crd.insert(pair<st, st> (i, j-1));
	}
	
	if ((j < m-1) && (inp[i][j+1] == '1') && (crd.find(pair<st, st> (i, j+1))) == crd.end()) {
		cnt++;
		crd.insert(pair<st, st> (i, j+1));
	}
	
/*	cout << cnt << "\t" << "(" << i << ", " << j << ")\t";

	set <pair<st, st>> :: iterator it;
	for (it = crd.begin(); it != crd.end(); it++) 
		cout << "(" << it->first << ", " << it->second << ")";

	cout << "\n"; 
*/
	return a[i][j] = min(minreq(inp, crd, i+1, j), minreq(inp, crd, i, j+1)) + cnt;

}

void solve() {
	st i, j;
	cin >> n >> m;

	vector<vector<char>> inp;
	char x;

	for (i = 0; i < n; i++) {
		inp.push_back(vector<char> ());
		for (j = 0; j < m; j++) {
			cin >> x;
			inp[i].push_back(x);
			a[i][j] = -1;
		}
	}

//	cout << "cnt\tcur_pos\tpath:\n";
	set <pair<st, st>> crd;
	cout << minreq(inp, crd) << "\n"; 

/*	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cout << a[i][j];
		}
		cout << "\n";
	}
*/
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