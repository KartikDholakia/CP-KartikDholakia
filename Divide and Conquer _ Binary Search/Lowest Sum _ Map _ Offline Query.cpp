#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(),x.end()

//Lowest Sum
//Binary Search
//https://www.codechef.com/problems/LOWSUM
void solve() {
	int k, q, i, j;
	cin >> k >> q;

	vector<ll> a(k);
	vector<ll> b(k);
	
	for (i = 0; i < k; i++)
		cin >> a[i];

	for (i = 0; i < k; i++)
		cin >> b[i];

	map<ll, int> m;
	for (i = 0; i < k; i++) {
		for (j = 0; j < k; j++) {
			m[a[i] + b[j]]++;
		}
	}

	//offline query:
	map<int, int> query;
	vector<ll> ans(q);
	int inp;

	for (i = 0; i < q; i++) {
		cin >> inp;
		query[inp] = i;
	}

	auto it1 = m.begin();
	int pos, cnt = 0;
	
	for (auto it2 = query.begin(); it2 != query.end(); it2++) {
		pos = it2->first;
		while (it1 != m.end()) {
			if (cnt + it1->second >= pos) {
				ans[it2->second] = it1->first;
				break;
			}
			cnt += it1->second;
			it1++;
		}
	}

	for (i = 0; i < q; i++)
		cout << ans[i] << "\n";
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

	st t;
	cin >> t;
	for (st i = 1; i <= t; i++) {
		solve();
	}

	cerr << "time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}