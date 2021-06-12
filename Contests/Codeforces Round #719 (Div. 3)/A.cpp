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

//A
//Codeforces Round #719 (Div. 3)
void solve() {
	ll n, i, j;
	string s;
	cin >> n;
	cin >> s;
	// vector<bool> ch(27, 0);
	bool ch[27] = {0};

	bool flag = 1;
	char temp;
	for (i = 0; i < n;) {
		if (ch[s[i] - 'A']) {
			flag = 0;
			// cout << i << "\n";
			break;
		}
		ch[s[i]-'A'] = 1;
		temp = s[i];
		while (i < n && s[i] == temp)
			i++;
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
