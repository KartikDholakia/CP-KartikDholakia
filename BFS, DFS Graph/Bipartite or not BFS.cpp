#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()

//https://www.spoj.com/problems/BUGLIFE/
//To check if graph is bipartite or not
bool bfs(vector<int> graph[], vector<char> &color, int n, int i) {
	color[i] = 'r';
	queue<int> q;
	q.push(i);
	int curr;

	while (!q.empty()) {
		curr = q.front();
		q.pop();
		for (int i = 0; i < graph[curr].size(); i++) {
			if (color[graph[curr][i]] == color[curr])
				return 0;
			if (color[graph[curr][i]] != 'g')
				continue;
			if (color[curr] == 'r')
				color[graph[curr][i]] = 'b';
			else
				color[graph[curr][i]] = 'r';
			q.push(graph[curr][i]);
		}
	}
	return 1;
}

void solve() {
	int n, k, i, u, v;
	cin >> n >> k;
	vector<int> graph[n+1];

	for (i = 0; i < k; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	vector<char> color(n+1, 'g');
	//g - gray -> not explored
	//r -> red(m), b -> (f)

	bool flag = 1;
	for (i = 1; i <= n; i++) {
		if (color[i] == 'g') {
			flag = bfs(graph, color, n, i);
		}
		if (flag == 0) {
			cout << "Suspicious bugs found!\n";
			return;
		}
	}
	cout << "No suspicious bugs found!\n";
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
		cout << "Scenario #" << i << ":\n";
		solve();
	}

	cerr << "time: "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}