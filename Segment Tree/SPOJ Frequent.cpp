#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()

//FREQUENT - Frequent values
//https://www.spoj.com/problems/FREQUENT/
struct node {
	ll lval, lcnt,
	rval, rcnt,
	ans;
	
	node() {

	}
};

void buildtree(vector<ll> &v, vector<node> &tree, ll l, ll r) {

}

ll query(vector<node> &tree, ll l, ll r) {

}

void solve(ll n) {
	ll q, i, l, r;
	cin >> q;
	vector<ll> v(n+1, 0);
	vector<node> tree(4*n);

	for (i = 1; i <= n; i++)
		cin >> v[i];
	
	buildtree(v, tree, 1, n);

	while(q--) {
		cin >> l >> r;
		cout << query(tree, l, r) << "\n";
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

	// int t = 1;
	// // cin >> t;
	// for (int i = 1; i <= t; i++) {
	// 	// cout << "Case #" << i << ": ";
	// 	// cout << "Test " << i << ":\n";
	// 	solve();
	// }

	ll n;
	while (cin >> n)
		solve(n);

	cerr << "time: "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}