#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()

//A. Puzzle From the Future
//Codeforces Round #696 (Div. 2)
void solve() {
	int n, i;
	cin >> n;
	vector<char> b(n), a(n);
	a[0] = '1';
	
	for (i = 0; i < n; i++)
		cin >> b[i];
	
	int prev = (b[0] - '0') + 1;
	for (i = 1; i < n; i++) {
		switch(prev) {
			case 2:	a[i] = (b[i] == '0') ? '1' : '0';
					break;
			case 1: a[i] = (b[i] == '0') ? '0' : '1';
					break;
			case 0: a[i] = '1';
					break;
		}
		prev = (a[i] - '0') + (b[i] - '0');
	}

	for (i = 0; i < n; i++)
		cout << a[i];

	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	#ifndef ONLINE_JUDGE
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