#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;
#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807

//https://www.codechef.com/problems/TACHSTCK
//Greedy
void solve() {
	int n, d, i;
	cin >> n >> d;
	vector<int> v(n, 0);
	int ans = 0;
	for (i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());
	for (i = 1; i < n; i++) {
		if (v[i] - v[i-1] <= d) {
			ans++;
			i++;
		}
	}
	cout << ans << "\n";
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

	st t = 1;
//	cin >> t;
	for (st i = 0; i < t; i++) {
		solve();
	}

	cerr << "time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}