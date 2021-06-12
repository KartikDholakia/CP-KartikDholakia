#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(),x.end()

//A. Kick_Start
//KickStart 2020 Round G
void solve() {
	int i, cnta = 0, cntb = 0;
	string s;
	cin >> s;
	
	if (s.size() < 9) {
		cout << "0\n";
		return;
	}
	
	ll ans = 0;
	for (i = 0; i <= s.size() - 5; i++) {
		if (s.substr(i, 4) == "KICK")
			cnta++;
		if (s.substr(i, 5) == "START") {
			cntb++;
			ans += cnta;
		}
	}
	//cout << cnta << " " << cntb << " ";
	cout << ans << "\n";
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

	ll t = 1;
	cin >> t;
	for (ll i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}

	cerr << "time: "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}