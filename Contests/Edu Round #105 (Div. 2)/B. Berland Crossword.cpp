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

//B. Berland Crossword
//Educational Codeforces Round 105 (Rated for Div. 2)
int find_max_idx(int arr[]) {
	int mx = -1, mx_idx;
	for (int i = 0; i < 4; i++) {
		if (arr[i] > mx) {
			mx = arr[i];
			mx_idx = i;
		}
	}
	return mx_idx;
}

bool any(int arr[]) {
	for (int i = 0; i < 4; i++) {
		if (arr[i] < 0)
			return 1;
	}
	return 0;
}

void solve() {
	int n, i, mx_idx;
	int next, prev;
	int inp[4];
	cin >> n;
	for (i = 0; i < 4; i++)
		cin >> inp[i];

	for (i = 0; i < 4; i++) {
		mx_idx = find_max_idx(inp);

		// for (int j = 0; j < 4; j++)
		// 	cout << inp[j] << " ";
		// cout << "\n";
		// cout << mx_idx << "\n";

		next = (mx_idx + 1) % 4;
		prev = mx_idx - 1;

		if (prev == -1)
			prev = 3;

		if (inp[mx_idx] == n-1) {
			if (inp[next] >= inp[prev])
				inp[next]--;
			else
				inp[prev]--;
		}
		else if (inp[mx_idx] == n) {
			inp[next]--;
			inp[prev]--;
		}
		else {
			cout << "YES\n";
			return;
		}
		if (any(inp)) {
			cout << "NO\n";
			return;
		}
		inp[mx_idx] = 0;
	}

	cout << "YES\n";
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