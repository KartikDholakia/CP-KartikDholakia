#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()

//https://www.codechef.com/problems/FIRESC
//Union-Find
ll find(ll x, vector<ll> &p) {
	if (p[x] == x)
		return x;
	return p[x] = find(p[x], p);
}

void merge(ll x, ll y, vector<ll> &p, vector<ll> &sz) {
	ll p1 = find(x, p);
	ll p2 = find(y, p);
	if (p1 == p2)
		return;
	
	if (sz[p1] > sz[p2])
		swap(p1, p2);
	
	p[p1] = p2;
	sz[p2] += sz[p1];
}

void solve() {
	ll n, m, i;
	cin >> n >> m;
	vector<ll> p(n+1, 0);
	vector<ll> sz(n+1, 1);
	sz[0] = -1;

	for (i = 1; i <= n; i++)
		p[i] = i;

	ll u, v;
	for (i = 0; i < m; i++) {
		cin >> u >> v;
		merge(u, v, p, sz);
	}
	
/*	for (i = 1; i <= n; i++)
		cout << i << " ";
	cout << "\n";

	for (i = 1; i <= n; i++)
		cout << p[i] << " ";
	cout << "\n";

	for (i = 1; i <= n; i++)
		cout << sz[i] << " ";
*/
	set<ll> s;
	for (i = 1; i <= n; i++)
		s.insert(find(i, p));

	ll captains = 1;
	for (ll x: s)
		captains = (captains*sz[x]) % mod;

	cout << s.size() << " " << captains << "\n";

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	//remove this piece of code when this has to be submitted in kickstart
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
	//freopen is used to associate a file with stdin or stdout stream in C++
	#endif

	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
	}

	cerr << "time: "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}