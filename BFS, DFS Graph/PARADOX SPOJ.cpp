#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)

//https://www.spoj.com/problems/PARADOX/
//DFS

void solve(int n) {
	int i, inp;
	string temp;
	vector<pair<int, int>> grph;
	grph.pb(make_pair(-1, 0));
	
	for (i = 1; i <= n; i++) {
		cin >> inp >> temp;
		grph.pb(make_pair(inp, ((temp == "true") ? 1 : -1)));
	}
	// for (i = 0; i <= n; i++) {
	// 	cout << grph[i].first << " " << grph[i].second << "\n";
	// }


	vector<int> visited(n+1, 0);
	//visited[i] == 1 -> ith statement is marked true
	//visited[i] == -1 -> ith statement is marked false
	//visited[i] == 0 -> ith statement is not yet explored

	int prev, curr;
	bool flag = 1;
	for (i = 1; i <= n; i++) {
		if (visited[i])
			continue;
		visited[i] = 1;
		prev = i;
		while (1) {
			curr = grph[prev].first;
			if (visited[curr] != 0) {
				if (visited[curr] != grph[prev].second*visited[prev])
					flag = 0;
				break;
			}
			else {
				visited[curr] = grph[prev].second*visited[prev];
				prev = curr;
			}
		}
		if (flag == 0)
			break;
	}

	if (flag)
		cout << "NOT PARADOX\n";
	else
		cout << "PARADOX\n";
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

	// int t = 1;
	// cin >> t;
	// for (int i = 1; i <= t; i++) {
	// 	solve();
	// }
	int n;
	while (cin >> n) {
		if (n)	solve(n);
	}

	cerr << "time: "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}