#include<bits/stdc++.h> 
using namespace std; 
typedef long long ll;
typedef short int st; 
#define mod 1000000007

//C. Make It Good Codeforces Round #656 (Div. 3)
int cache[20000][20000];

int min(int x, int y) {
	if (x < y)
		return x;
	else
		return y;
}

bool ispos(int i, int j, vector<int> &a, int curr_max = 0) {
	if (i > j)
		return 1;

	if (min(a[i], a[j]) < curr_max)
		return 0;
	
	if (cache[i][j] != -1)
		return cache[i][j];
	
	if (a[i] <= a[j]) 
		return cache[i][j] = ispos(i+1, j, a, a[i]);
	else
		return cache[i][j] = ispos(i, j-1, a, a[j]);	 
}

void solve() {
	int n, i, j;
	cin >> n;
	vector<int> a(n);

	for (i = 0; i < n; i++) 
		for (j = 0; j < n; j++)
			cache[i][j] = -1;

	bool flag;

	for (i = 0; i < n; i++) {
		cin >> a[i]; 
	}

	for (i = 0; i < n; i++) {
		flag = ispos(i, n-1, a);
		if (flag) {
			cout << i << "\n";
			break;
		}
	}
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

	int t = 1;
	cin >> t;
	for (int i = 0; i < t; i++)
		solve(); 

	cerr << "time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0; 
} 

