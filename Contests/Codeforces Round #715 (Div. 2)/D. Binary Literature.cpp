#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

#define MOD 1000000007
#define MAX 1000001					//1e6 + 1
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define mp make_pair

//D. Binary Literature
//Codeforces Round #715 (Div. 2)
void solve() {
	ll n, i;
	cin >> n;
	vector<string> v;
	string s;

	cin >> s;
	v.pb(s);
	cin >> s;
	v.pb(s);
	cin >> s;
	v.pb(s);
	
	sort(all(v));

	// for (i = 0; i < 3; i++)
	// 	cout << v[i] << "\n";

	ll x1 = 0, x2 = 0, y1 = 0, y2 = 0, x3 = 0, y3 = 0;
	for (i = 0; i < 2*n; i++) {
		//b/w v0 and v1:
		if (v[0][i] == v[1][i])
			x1++;
		else
			y1++;
		//b/w v1 and v2:
		if (v[1][i] == v[2][i])
			x2++;
		else
			y2++;
		if (v[2][i] == v[0][i])
			x3++;
		else
			y3++;
	}
	// cout << x1 << " " << y1 << "\n";
	// cout << x2 << " " << y2 << "\n";

	string ans;
	if (x1 + 2*y1 <= 3*n) {
		for (i = 0; i < 2*n; i++) {
			ans.pb(v[0][i]);
			if (v[0][i] != v[1][i])
				ans.pb(v[1][i]);
			// cout << i << ": " << ans << "\n";
		}
		while (ans.size() < 3*n)
			ans.pb('0');
	}

	else if (x2 + 2*y2 <= 3*n) {
		for (i = 0; i < 2*n; i++) {
			ans.pb(v[1][i]);
			if (v[1][i] != v[2][i])
				ans.pb(v[2][i]);
		}
		while (ans.size() < 3*n)
			ans.pb('0');
	}

	else {
		for (i = 0; i < 2*n; i++) {
			ans.pb(v[2][i]);
			if (v[2][i] != v[0][i])
				ans.pb(v[0][i]);
		}
		while (ans.size() < 3*n)
			ans.pb('0');
	}

	cout << ans << "\n";
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
		// cout << "Case #" << i << ": ";
		solve();
	}

	cerr << "time: "<<(double)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}