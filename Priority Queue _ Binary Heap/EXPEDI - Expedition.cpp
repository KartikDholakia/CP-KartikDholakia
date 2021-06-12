#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(),x.end()

//EXPEDI - Expedition
//https://www.spoj.com/problems/EXPEDI/
//Priority Queue | Greedy (Have to tell the min no of stops)
void solve() {
	int n, i, p, l;
	cin >> n;
	int a, b;
	map<int, int, greater<int>> m;
	
	for (i = 0; i < n; i++) {
		cin >> a >> b;
		m[a] = b;
	}
	
	cin >> l >> p;
	if (l == p) {
		cout << "0\n";
		return;
	}

	priority_queue<pair<int, int>> pq;
	auto itr = m.begin();
	int s = 0, fuel = p, last = l, ans = 0;

	for (i = 0; i < n; i++) {
		fuel -= (last - itr->first);
		if (fuel >= 0)
			pq.push(make_pair(itr->second, itr->first));

		else {
			if (pq.empty()) {
				cout << "-1\n";
				return;
			}
			else {
				while ((fuel < 0) && (!pq.empty())) {
					fuel += pq.top().first;
					pq.pop();
					ans++;
				}
				if ((fuel < 0) && (pq.empty())) {
					cout << "-1\n";
					return;
				}
				pq.push(make_pair(itr->second, itr->first));
			}
		}
		if (fuel == itr->first)
			break;
		last = itr->first;
		itr++;
	}
	cout << ans << "\n";
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

	ll t;
	cin >> t;
	for (ll i = 1; i <= t; i++) {
		solve();
	}

	cerr << "time: "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}