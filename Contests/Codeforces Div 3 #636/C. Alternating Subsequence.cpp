#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;
#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807

//Codeforces Div 3 #636
//C. Alternating Subsequence
int max(int x, int y) {
	return x > y? x:y;
}

void solve() {
	int n, i;
	cin >> n;
	vector<int> v(n);
	for (i = 0; i < n; i++) {
		cin >> v[i];
	}
	int sign = v[0] > 0? 1:-1;
	int prev_max = v[0];
	ll sum = 0;
	for (i = 1; i < n; i++) {
		if (((ll)sign * (ll)v[i]) < 0) {
			sum += prev_max;
			sign *= -1;
			prev_max = v[i];
		}
		else {
			if (prev_max < v[i])
				prev_max = v[i];
		}
	}
	cout << sum + (ll)prev_max << "\n";
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
