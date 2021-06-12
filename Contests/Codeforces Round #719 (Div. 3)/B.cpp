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

//B
//Codeforces Round #719 (Div. 3)
void solve() {
	ll n;
	cin >> n;

	if (n <= 9) {
		cout << n << "\n";
		return;
	}

	string s = to_string(n);
	char temp = s[0];

	int flag = 1;
	for (ll i = 0; i < s.size(); i++) {
		if (temp != s[i]) {
			flag = 0;
			break;
		}
	}

	string ideal(s.size(), temp);
	ll mx = stoll(ideal);

	ll ans;
	if (flag) {
		ans = (s.size()-1)*9 + (ll)(temp - '0');
	}
	else {
		ans = (s.size()-1)*9 + (ll)(temp - '0' - 1);
		if (mx < n)
			ans++;
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
