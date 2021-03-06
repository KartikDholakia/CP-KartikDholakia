#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;
#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807

//A. Remove Smallest
void solve() {
	st n, i;
	cin >> n;
	vector<st> a(n);
	for (i = 0; i < n; i++)
		cin >> a[i];

	sort(a.begin(), a.end());

	bool flag = 1;
	for (i = 0; i < n-1; i++) {
		if (a[i+1] - a[i] > 1) {
			flag = 0;
			break;
		}
	}
	if (flag)
		cout << "YES\n";
	else
		cout << "NO\n";
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
	cin >> t;
	for (st i = 0; i < t; i++) {
		solve();
	}

	cerr << "time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}
