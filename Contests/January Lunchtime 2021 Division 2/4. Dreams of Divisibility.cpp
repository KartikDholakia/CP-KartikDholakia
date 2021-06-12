#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)

//4. Dreams of Divisibility
//January Lunchtime 2021 Division 2
void solve() {
	int n, k, i;
	cin >> n >> k;
	vector<int> v(n);

	// cout << k << " ";
	// cout << (k & (k-1)) << " ";
	for (i = 0; i < n; i++)
		cin >> v[i];

	if ((k & (k-1)) == 0) {
		cout << "YES\n";
		return;
	}

	for (i = 0; i < n; i++) {
		if (v[i] % k) {
			cout << "NO\n";
			return;
		}
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

	cerr << "time: "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}