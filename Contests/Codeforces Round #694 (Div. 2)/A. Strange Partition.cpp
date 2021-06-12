#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()

//A. Strange Partition
//Codeforces Round #694 (Div. 2)
void solve() {
	int mx = 0, mn = 0, i, n, x;
	cin >> n >> x;

	vector<int> v(n);
	for (i = 0; i < n; i++)
		cin >> v[i];

	for (i = 0; i < n; i++) {
		if (i < n-1 && (v[i] + v[i+1]) % x == 0) {
			mn += (v[i] + v[i+1]) / x;
			i++;
		}
		else
			mn += ceil((double)v[i]/(double)x);
	}

	for (i = 0; i < n; i++) {
		mx += ceil((double)v[i]/(double)x);
	}

	cout << mn << " " << mx << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
	//freopen is used to associate a file with stdin or stdout stream in C++
	#endif

	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		// cout << "Case #" << i << ": ";
		// cout << "Test " << i << ":\n";
		solve();
	}

	cerr << "time: "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}