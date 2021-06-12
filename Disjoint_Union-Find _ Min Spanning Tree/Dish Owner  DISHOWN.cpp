#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(),x.end()

//Dish Owner | DISHOWN
//https://www.codechef.com/problems/DISHOWN
//Disjoint | Min Spanning Tree | Union-Find
int find(int x, vector<int> &p) {
	if (p[x] == x)
		return x;
	return p[x] = find(p[x], p);
}

void unite(int a, int b, vector<int> &p, vector<int> &s) {
	int x = find(a, p), y = find(b, p);
	if (x == y) {
		cout << "Invalid query!\n";
		return;
	}
	
	if (s[x] == s[y])
		return;

	if (s[x] < s[y])
		swap(x, y);
	
	p[y] = x;
}

void solve() {
	int n, q, i;
	cin >> n;
	
	vector<int> p(n+1, 0);
	vector<int> s(n+1, 0);

	for (i = 1; i <= n; i++) {
		cin >> s[i];
		p[i] = i;
	}
	
	cin >> q;
	int x, y;
	bool c;

	for (i = 0; i < q; i++) {
		cin >> c >> x;
		if (c == 0) {
			cin >> y;
			unite(x, y, p, s);
		}
		else {
			cout << find(x, p) << "\n";
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

	ll t = 1;
	cin >> t;
	for (ll i = 1; i <= t; i++) {
		solve();
	}

	cerr << "time: "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}