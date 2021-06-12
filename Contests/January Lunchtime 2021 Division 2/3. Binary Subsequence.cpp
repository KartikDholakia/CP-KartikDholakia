#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)

//3. Binary Subsequence
//January Lunchtime 2021 Division 2
void solve() {
	int n, i;
	string s;
	cin >> n;
	cin >> s;

	vector<int> zeros(n, 0), ones(n, 0);
	for (i = 0; i < n; i++) {
		if (s[i] == '0') {
			if (i == 0)
				zeros[i] = 1;
			else
				zeros[i] = zeros[i-1] + 1;
		}
		else {
			if (i == 0)
				zeros[i] = 0;
			else
				zeros[i] = zeros[i-1];
		}
	}

	for (i = n-1; i >= 0; i--) {
		if (s[i] == '1') {
			if (i == n-1)
				ones[i] = 1;
			else
				ones[i] = ones[i+1] + 1;
		}
		else {
			if (i == n-1)
				ones[i] = 0;
			else
				ones[i] = ones[i+1];
		}
	}

	// for (i = 0; i < n; i++)
	// 	cout << zeros[i] << " ";
	// cout << "\n";
	// for (i = 0; i < n; i++)
	// 	cout << ones[i] << " ";
	// cout << "\n";

	int ans = INT_MIN;
	for (i = 0; i < n; i++) {
		ans = max(ans, ones[i] + zeros[i]);
	}
	cout << n-ans << "\n";
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