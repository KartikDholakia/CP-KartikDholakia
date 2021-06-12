#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()

//B. New Year's Number
//Codeforces Round #697 (Div. 3)
void solve() {
	int n, y, x;
	cin >> n;

	if (n < 2020) {
		cout << "NO\n";
		return;
	}
	if ((n % 2020 == 0) || (n % 2021 == 0)) {
		cout << "YES\n";
		return;
	}

	y = n % 10;
	int k = n/2021;
	for (; y <= k; y += 10) {
		if ((n - 2021*y) % 2020 == 0) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
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