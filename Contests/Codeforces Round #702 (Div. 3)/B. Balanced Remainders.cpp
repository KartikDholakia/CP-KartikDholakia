#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define MOD 1000000007
#define MAX 1000001					//1e6 + 1
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define mp make_pair

//B. Balanced Remainders
//Codeforces Round #702 (Div. 3)
void solve() {
	int n, i, ans = 0, j;
	cin >> n;
	vector<int> v(n);
	int c[3] = {0};

	for (i = 0; i < n; i++) {
		cin >> v[i];
		c[v[i] % 3]++;
	}

	int cost[3][3] = {
		{0, 1, 2},
		{2, 0, 1},
		{1, 2, 0}
	};				//cost[i][j] -> denotes cost of transfering from ci to cj

	for (i = 0; i < 3; i++) {
		if (c[i] >= n/3)
			continue;
		for (j = 0; j < 3; j++) {
			if (i == j)
				continue;
			while (c[j] > n/3 && c[i] < n/3) {
				ans += cost[j][i];
				c[j]--;
				c[i]++;
			}
		}
	}

	cout << ans << "\n";
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

	cerr << "time: "<<(double)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}