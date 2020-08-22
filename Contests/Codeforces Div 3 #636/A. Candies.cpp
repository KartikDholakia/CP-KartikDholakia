#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;
#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807

//Codeforces Div 3 #636
//A. Candies
void solve() {
	int n, k, y;
	cin >> n;
	for (k = 2; (pow(2, k) - 1) <= n; k++) {
		y = pow(2, k) - 1;
		if (n % y == 0) {
			cout << n/y << "\n";
			break;
		}
	}
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
