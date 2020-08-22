#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;
#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807

//Codeforces Div 3 #636
//B. Balanced Array
void solve() {
	int n, cnt = 0, i, j;
	cin >> n;
	if (n % 4 != 0) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for (i = 1; 2*i <= n; i++) {
		cout << 2*i << " ";
	}
	for (i = 1, j = 1; i < n/2; i++, j += 2) {
		cout << j << " ";
	}
	cout << j+i << "\n";
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
