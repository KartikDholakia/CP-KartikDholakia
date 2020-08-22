#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;
#define mod 1000000007
#define MAX 1000001

//Weird Sum July Circuits '20
//Dynamic Programming
ll max_sum = 0;
int n, k, m;

void reqmax(vector<int> &a, ll temp = INT_MIN, int i = -1, int cnt = 0) {
	
}

void solve() {
	cin >> n >> k >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> temp(k);
	reqmax(a);
	cout << max_sum << "\n";
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
	//cin >> t;
	for (st i = 0; i < t; i++) {
		solve(); 
	}

	cerr << "time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0; 
}