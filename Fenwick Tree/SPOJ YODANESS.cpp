#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()

//YODANESS - Yodaness Level
//https://www.spoj.com/problems/YODANESS/
//Inversion Count using BIT/Fenwick Tree
//can be done using merge sort and seg tree too
int query(vector<int> &BIT, int idx) {
	int ans = 0;
	while (idx >= 1) {
		ans += BIT[idx];
		idx -= (idx & -idx);
	}
	return ans;
}

void update(vector<int> &BIT, int idx, int x = 1) {
	while (idx < BIT.size()) {
		BIT[idx] += x;
		idx += (idx & -idx);
	}
}

void solve() {
	int n, i;
	cin >> n;
	
	vector<string> v(n);
	map<string, int> m;
	string temp;

	for (i = 0; i < n; i++)
		cin >> v[i];

	for (i = 0; i < n; i++) {
		cin >> temp;
		m[temp] = i+1;
	}

	vector<int> arr(n, 0);
	for (i = 0; i < n; i++) {
		arr[i] = m[v[i]];
		// //debug:
		// cout << arr[i] << " ";
	}
	// cout << "\n";

	vector<int> BIT(n+1, 0);
	ll cnt = 0;
	for (i = n-1; i >= 0; i--) {
		cnt += query(BIT, arr[i]-1);
		update(BIT, arr[i]);
	}

	cout << cnt << "\n";
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
	for (int i = 1; i <= t; i++) {
		// cout << "Case #" << i << ": ";
		// cout << "Test " << i << ":\n";
		solve();
	}

	cerr << "time: "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}