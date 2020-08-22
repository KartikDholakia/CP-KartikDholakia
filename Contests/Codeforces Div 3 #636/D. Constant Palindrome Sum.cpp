#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;
#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807

//Codeforces Div 3 #636
//D. Constant Palindrome Sum
int max(int x, int y) {
	return x > y? x:y;
}

int min(int x, int y) {
	return x > y? y:x;
}

void solve() {
	int n, k, i;
	cin >> n >> k;
	vector<int> v(n);
	for (i = 0; i < n; i++)
		cin >> v[i];
	
	int mp, l = INT_MIN, r = INT_MAX, lp;
	map<ll, int> sop;
	ll sum = 0;
	for (i = 0; i < n/2; i++) {
		mp = max(v[i], v[n-i-1]);
		lp = min(v[i], v[n-i-1]);
		if (l < lp + 1)
			l = mp+1;
		if (r > mp + k)
			r = mp + k;

		sum = v[i] + v[n-i-1];
		sop[sum]++;
	}

	int cnt = 0, max_sum;
	for (i = l; i <= r; i++) {
		if (sop[i] > cnt) {
			cnt = sop[i];
			max_sum = i;
		} 
	}

	cout << n/2 - cnt << "\n"; 
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
