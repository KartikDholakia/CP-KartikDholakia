#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()

//https://www.spoj.com/problems/PT07Z/
//Longest Path in Undirected Tree Using BFS
vector<int> adj[10001];

int bfs(int &root, int n) {
	queue<int> q;
	q.push(root);
	vector<bool> visited(n+1, 0);
	visited[root] = 1;
	int curr;
	vector<int> lvl(n+1, 0);

	while(!q.empty()) {
		curr = q.front();
		q.pop();
		visited[curr] = 1;
		for (int i = 0; i < adj[curr].size(); i++) {
			if (!visited[adj[curr][i]]) {
				q.push(adj[curr][i]);
				lvl[adj[curr][i]] = lvl[curr] + 1;
			}
		}
	}
	root = curr;
	return lvl[curr];
}

void solve() {
	int n, u, v, i;
	cin >> n;

	for (i = 0; i < n-1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// for (i = 1; i <= 10; i++) {
	// 	cout << i << " -> ";
	// 	for (int j = 0; j < adj[i].size(); j++)
	// 		cout << adj[i][j] << " ";
	// 	cout << "\n";
	// }

	int root = 1, lvl;
	lvl = bfs(root, n);
	// cout << root << " " << lvl << "\n";
	lvl = bfs(root, n);
	cout << lvl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	#ifndef ONLINE_JUDGE
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