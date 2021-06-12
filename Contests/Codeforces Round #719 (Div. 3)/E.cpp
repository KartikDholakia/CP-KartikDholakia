#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

#define MOD 1000000007				//1e9 + 7
#define MAX 200001					//2e5 + 1
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define mp make_pair
#define vll vector<ll>
#define pll pair<ll, ll>
#define loop_diff(var, start, end, diff) for (ll var = start; var < end; var += diff)
#define loop(var, start, end) for (ll var = start; var < end; var++)

//E
//Codeforces Round #719 (Div. 3)
void solve() {
	ll n, i;
	cin >> n;
	vector<char> s(n+1, 'x');
	loop(i, 1, n+1)
		cin >> s[i];

	vll lcnt(n+1, 0), rcnt(n+1, 0), lsum(n+1, 0), rsum(n+1, 0);

	loop(i, 1, n+1) {
		lcnt[i] = lcnt[i-1] + (s[i] == '*' ? 1 : 0);
		lsum[i] = lsum[i-1] + (s[i] == '*' ? i : 0);
	}

	rcnt[n] = (s[i] == '*' ? 1 : 0);
	rsum[n] = (s[i] == '*' ? n : 0);
	for (i = n-1; i > 0; i--) {
		rcnt[i] = rcnt[i+1] + (s[i] == '*' ? 1 : 0);
		rsum[i] = rsum[i+1] + (s[i] == '*' ? i : 0);
	}

	ll temp, temp1, temp2;
	ll ans = INF;
	loop(i, 1, n+1) {
		temp1 = lcnt[i]*(lcnt[i] + 1)/2; 
		temp2 = rcnt[i]*(rcnt[i] + 1)/2;
		temp = i*(lcnt[i] - rcnt[i]) + (rsum[i] - lsum[i]) - temp1 - temp2;
		if (temp > 0)
			ans = min(ans, temp);
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
