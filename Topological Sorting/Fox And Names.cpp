#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long llu;

#define MOD 1000000007				//1e9 + 7
#define MAX 200001					//2e5 + 1
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define mp make_pair
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pair<ll, ll>>
#define mem(x, y) memset(x, y, sizeof(x))
#define loop_diff(var, start, end, diff) for (ll var = start; var < end; var += diff)
#define loop(var, start, end) for (auto var = start; var < end; var++)
#define loop_rev(var, start, end) for(auto var = start; var > end; var--)
#define ordered_set tree<pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update>

//https://codeforces.com/contest/510/problem/C
//Topological Sorting
vll adj[26];
ll inDegree[26] = {0};

void addEdge(char a, char b) {
	adj[a - 'a'].pb(b - 'a');
}

void topSort() {
	ll i;
	queue<ll> q;
	loop(i, 0, 26) {
		if (inDegree[i] == 0)
			q.push(i);
	}

	string ans;
	ll curr;
	while (!q.empty()) {
		curr = q.front();
		ans.pb((char)(curr + 'a'));
		q.pop();
		loop(i, 0, adj[curr].size()) {
			inDegree[adj[curr][i]]--;
			if (inDegree[adj[curr][i]] == 0) {
				// cout << "Push: " << (char)(adj[curr][i] + 'a') << "\n";
				q.push(adj[curr][i]);
			}
		}
	}

	cout << ans << "\n";
}

//returns 1 if cycle is present:
bool dfs() {
	ll i, curr, j;
	stack<ll> s;

	//dfs on each node:
	loop(i, 0, 26) {
		s.push(i);
		vector<bool> visited(26, 0);
		
		//running dfs:
		while (!s.empty()) {
			curr = s.top();
			s.pop();
			visited[curr] = 1;
			loop(j, 0, adj[curr].size()) {
				if (visited[adj[curr][j]])
					return 1;
				s.push(adj[curr][j]);
			}
		}
	}

	return 0;
}

void solve() {
	string curr, prev;
	char firstLetter;
	ll n, i;
	cin >> n;
	cin >> prev;
	firstLetter = prev[0];
	bool mark[26] = {0};
	mark[prev[0] - 'a'] = 1;

	bool flag = 1;
	ll j;
	loop(j, 1, n) {
		cin >> curr;
		i = 0;
		while ((i < min(prev.size(), curr.size())) && (curr[i] == prev[i]))
			i++;
		if (i == curr.size()) {
			flag = 0;
		}
		else if (i != prev.size()) {
			addEdge(prev[i], curr[i]);
			inDegree[curr[i] - 'a']++;
			// cout << "Add Edge: " << prev[i] << " - " << curr[i] << "\n";
		}
		prev = curr;
	}

	// cout << "Flag = " << flag << "\n";
	if (!flag || dfs()) {
		cout << "Impossible\n";
		return;
	}

	// loop(i, 0, 26) {
	// 	if (adj[i].size() == 0)
	// 		continue;
	// 	cout << (char)(i + 'a') << ": ";

	// 	loop(j, 0, adj[i].size())
	// 		cout << (char)(adj[i][j] + 'a') << " ";
		
	// 	cout << "\n";
	// }

	// loop(i, 0, 26) {
	// 	if (inDegree[i])
	// 		cout << (char)(i + 'a') << " : " << inDegree[i] << "\n";
	// }

	topSort();
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
		// cout << "Case #" << i << ": ";
		solve();
	}

	cerr << "time: "<<(double)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}