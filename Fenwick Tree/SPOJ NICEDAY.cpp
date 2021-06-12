#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()

//NICEDAY - The day of the competitors
//https://www.spoj.com/problems/NICEDAY/
//BIT/Fenwick Tree
struct scores {
	ll a, b, c;
};

bool cmp(scores x, scores y) {
	return x.a < y.a;
}

//function to find the best rank in 3rd competion in range [1,bi-1)
ll query(vector<ll> &BIT, ll idx) {
	ll ans = INF;
	while (idx >= 1) {
		ans = min(ans, BIT[idx]);
		idx -= (idx & -idx);
	}
	return ans;
}

void update(vector<ll> &BIT, ll idx, ll x) {
	while (idx < BIT.size()) {
		BIT[idx] = min(x, BIT[idx]);
		idx += (idx & -idx);
	}
}

void solve() {
	ll n, i;
	cin >> n;
	vector<scores> v;
	for (i = 0; i < n; i++) {
		v.push_back(scores());
		cin >> v[i].a >> v[i].b >> v[i].c; 
	}
	sort(all(v), cmp);
	
	ll cnt = 0, temp;
	vector<ll> BIT(n+1, INF);

	for (i = 0; i < n; i++) {
		temp = query(BIT, v[i].b - 1);
		update(BIT, v[i].b, v[i].c);
		
		if (temp > v[i].c)
			cnt++;
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