#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()

//2. Maximise Islands
//January Cook-Off 2021
void solve() {
	int n, m, i, j;
	cin >> n >> m;
	string temp;

	vector<string> inp;
	for (i = 0; i < n; i++) {
		cin >> temp;
		inp.push_back(temp);
	}

	char matr[n][m], curr = '*';
	for (i = 0; i < n; i++) {
		if (i > 0) {
			if (matr[i-1][0] == '*')
				curr = '.';
			else
				curr = '*';
		}
		for (j = 0; j < m; j++) {
			matr[i][j] = curr;
			curr = ((curr == '*') ? '.' : '*');
		}
	}

	int ans1 = 0, ans2 = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (matr[i][j] != inp[i][j])
				ans1++;
			matr[i][j] = ((matr[i][j] == '*') ? '.' : '*');
			if (matr[i][j] != inp[i][j])
				ans2++;
		}
	}
	
	cout << min(ans1, ans2) << "\n";
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