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

//D. Permutation Transformation
//Codeforces Round #702 (Div. 3)
void buildtree(vector<int> &v, vector<int> &ans, int l, int r, int d = 0) {
	if (l > r)
		return;

	int m, i, mx = INT_MIN;
	for (i = l; i <= r; i++) {
		if (v[i] > mx) {
			mx = v[i];
			m = i;
		}
	}
	ans[m] = d;

	buildtree(v, ans, l, m-1, d+1);
	buildtree(v, ans, m+1, r, d+1);
}

void solve() {
	int n, i;
	cin >> n;
	vector<int> v(n), ans(n);

	for (i = 0; i < n; i++)
		cin >> v[i];

	buildtree(v, ans, 0, n-1);

	for (i = 0; i < n; i++)
		cout << ans[i] << " ";

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

	cerr << "time: "<<(double)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}