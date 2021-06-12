#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()

//A. Replacing Elements
//Edu Round 102 Div. 2
void solve() {
	int n, d, i, j;
	cin >> n >> d;
	vector<int> v(n);

	bool flag = 1;
	for (i = 0; i < n; i++) {
		cin >> v[i];
		if (v[i] > d)
			flag = 0;
	}

	if (flag) {
		cout << "YES\n";
		return;
	}
	sort(all(v));

	flag = 0;
	for (i = 0; i < n; i++) {
		if (v[i] >= d) 
			break;
		for (j = i+1; j < n; j++) {
			if (v[i] + v[j] <= d) {
				flag = 1;
				break;
			}
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
		// cout << "Case #" << i << ": ";
		// cout << "Test " << i << ":\n";
		solve();
	}

	cerr << "time: "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}