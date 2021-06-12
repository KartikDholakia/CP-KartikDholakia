#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)

//https://www.spoj.com/problems/QUEEN/
//BFS
char chess[1001][1001];
int lvl[1001][1001];
	//lvl[i][j] = -1 => unvisted
	//lvl[i][j] = INF => can't reach
int n, m;

int qadd(queue<pair<int, int>> &q, int y, int x, pair<int, int> f) {
	pair<int, int> s = q.front();

	int i = s.first, j = s.second;
	while ((i < n) && (i >= 0) && (j < m) && (j >= 0)) {
		// cout << lvl[i][j];
		if (lvl[i][j] == INT_MAX)
			break;
		if (lvl[i][j] != -1) {
			i += y;
			j += x;
			continue;
		}

		lvl[i][j] = lvl[s.first][s.second] + 1;
		if ((i == f.first) && (j == f.second))
			return lvl[i][j];

		q.push(make_pair(i, j));
		i += y;
		j += x;
	}

	i = s.first, j = s.second;
	while ((i < n) && (i >= 0) && (j < m) && (j >= 0)) {
		if (lvl[i][j] == INT_MAX)
			break;
		if (lvl[i][j] != -1) {
			i -= y;
			j -= x;
			continue;
		}

		lvl[i][j] = lvl[s.first][s.second] + 1;
		if ((i == f.first) && (j == f.second))
			return lvl[i][j];

		q.push(make_pair(i, j));
		i -= y;
		j -= x;
	}

	return -1;
}

void solve() {
	int i, j;
	cin >> n >> m;

	pair<int, int> s, f;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> chess[i][j];
			lvl[i][j] = -1;
			if (chess[i][j] == 'S') {
				s = make_pair(i, j);
				lvl[i][j] = 0;
			}
			if (chess[i][j] == 'F')
				f = make_pair(i, j);
			if (chess[i][j] == 'X')
				lvl[i][j] = INT_MAX;
		}
	}

	queue<pair<int, int>> q;
	q.push(s);
	int ans = -1;

	while (!q.empty()) {
		// cout << "-- " << q.front().first << " " << q.front().second << " --\n";
		// cout << "lvl = " << lvl[q.front().first][q.front().second] << "\n";
		ans = qadd(q, 1, 0, f);		// '|'
		// cout << "| " << ans << "\n";
		if (ans != -1)
			break;
		ans = qadd(q, 0, 1, f);		// '-'
		// cout << "- " << ans << "\n";
		if (ans != -1)
			break;
		ans = qadd(q, 1, -1, f);	// '/'
		// cout << "/ " << ans << "\n";
		if (ans != -1)
			break;
		ans = qadd(q, 1, 1, f);		// '\'
		// cout << "\\ " << ans << "\n";
		if (ans != -1)
			break;
		// cout << "\n";
		q.pop();
	}

	cout << ans;
	cout << "\n";
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