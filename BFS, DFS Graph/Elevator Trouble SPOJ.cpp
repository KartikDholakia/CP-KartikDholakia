#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)

//https://www.spoj.com/problems/ELEVTRBL/
//BFS
void solve() {
	ll f, s, g, u, d, i;
	cin >> f >> s >> g >> u >> d;

	if (s == g) {
		cout << "0";
		return;
	}
	if ((g > s && u == 0) || (g < s && d == 0)) {
		cout << "use the stairs";
		return;
	}

	vector<ll> lvl(f+1, 0);
	queue<ll> q;
	q.push(s);
	vector<bool> visited(f+1, 0);
	visited[s] = 1;
	ll curr;

	while (!q.empty()) {
		curr = q.front();
		q.pop();
		if (curr == g) {
			cout << lvl[curr];
			return;
		}
		if ((curr + u <= f) && (visited[curr + u] == 0)) {
			q.push(curr + u);
			lvl[curr + u] = lvl[curr] + 1;
			visited[curr + u] = 1;
		}
		if ((curr - d >= 1) && (visited[curr - d] == 0)) {
			q.push(curr - d);
			lvl[curr - d] = lvl[curr] + 1;
			visited[curr - d] = 1;
		}
	}
	cout << "use the stairs";
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
	// cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
	}

	cerr << "time: "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}