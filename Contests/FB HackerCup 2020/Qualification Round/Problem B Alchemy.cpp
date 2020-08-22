#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef short int st;
#define mod 1000000007
#define MAX 1000001

//Problem B: Alchemy
void solve() {
	int cntA = 0, cntB = 0, n;
	char x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == 'A')
			cntA++;
		else
			cntB++;
	}
	if (abs(cntA-cntB) == 1)
		cout << ": Y\n";
	else
		cout << ": N\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

/*	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
	//freopen is used to associate a file with stdin or stdout stream in C++
	#endif
*/
	st t = 1;
	cin >> t;
	for (st i = 0; i < t; i++) {
		cout << "Case #" << i+1;
		solve();
	}

//	cerr << "time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}
