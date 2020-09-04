#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(),x.end()

//Saving a gift of love - Binary Search
//https://www.codechef.com/problems/ASHIGIFT
bool f(ll x, map<int, pair<ll, ll>> &m) {
	
	map<int, pair<ll, ll>> :: iterator it;
	for (it = m.begin(); it != m.end(); it++) {
		if ((it->second.first != 0) && (it->second.first <= x)) {
			x = x + it->second.second;
		}
		else if (it->second.first == 0) {
			x -= it->second.second;
		}
	}
	return (x > 0);
}

void solve() {
	int x, b, c, i, p;
	cin >> x;
	map<int, pair<ll, ll>> m;
	
	ll sum = 0;
	cin >> b;
	for (i = 0; i < b; i++) {
		cin >> p;
		cin >> m[p].second;
		m[p].first = 0;
		sum += m[p].second;
	}

	cin >> c;
	for (i = 0; i < c; i++) {
		cin >> p;
		cin >> m[p].first;
		cin >> m[p].second;
	}

	// map<int, pair<int, int>> :: iterator it;
	// for (it = m.begin(); it != m.end(); it++) {
	// 	cout << it->first << " " << it->second.first << " " << it->second.second;
	// 	cout << "\n";
	// }
	// cout << "\n";

	ll l = 1, r = sum+1, mid;

	while (l <= r) {
		mid = l + (r - l)/2;
		//cout << l << " " << r << " " << mid << " " << f(mid, m) << "\n";
		if (mid == r)
			break;

		if (f(mid, m)) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}

	cout << mid << "\n";
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