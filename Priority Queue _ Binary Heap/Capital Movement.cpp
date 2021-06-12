#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(),x.end()

//Capital Movement
//https://www.codechef.com/problems/CAPIMOVE
void solve() {
	int n, u, v, i;
	cin >> n;
	map<int, int, greater<int>> m;
	vector<int> inp(n+1);

	for (i = 1; i <= n; i++) {
		cin >> inp[i];
		m.insert(make_pair(inp[i], i));
	}

	auto itr = m.begin();
	// while (itr != m.end()) {
	// 	cout << "(" << itr->first << "," << itr->second << ")\n";
	// 	itr++;
	// }

	vector<int> p[n+1];
	for (i = 1; i <= n; i++)
		p[i].push_back(inp[i]);

	for (i = 1; i < n; i++) {
		cin >> u >> v;
		p[u].push_back(inp[v]);
		p[v].push_back(inp[u]);
	}

	for (i = 1; i <= n; i++)
		sort(all(p[i]), greater<int>());
	
	int j = 0;

	// for (i = 1; i <= n; i++) {
	// 	cout << i << ": {";
	// 	for (j = 0; j < p[i].size(); j++)
	// 		cout << p[i][j] << " ";
	// 	cout << "}\n";
	// }
	// cout << "\n";
	
	for (i = 1; i <= n; i++) {
		itr = m.begin();
		j = 0;
		while (itr->first == p[i][j]) {
			itr++;
			j++;
		}
		cout << itr->second << " ";
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

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
	}

	cerr << "time: "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}