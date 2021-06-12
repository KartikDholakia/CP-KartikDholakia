#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define MOD 1000000007
#define MAX 1000001					//1e6 + 1
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define mp make_pair

//B. Partial Replacement
//Codeforces Round #710 (Div. 3)
void solve() {
	int n, k, i, j, ans = 0;
	cin >> n >> k;
	string s;
	cin >> s;

	i = 0;
	while (i < n && s[i] != '*')
		i++;
	if (i < n) {
		s[i] = 'x';
		ans++;
		j = i;
	}
	if (ans == 0) {
		cout << "0\n";
		return;
	}

	i = n-1;
	while (i >= 0 && s[i] != '*')
		i--;
	if (i >= 0) {
		s[i] = 'x';
		ans++;
	}

	i = 0;
	while (j < n && i < n) {
		// cout << s << " " << i << " " << j << " " << ans << "\n";
		i = j + k;
		if (i >= n)
			break;
		while (i > j && s[i] != '*')
			i--;
		if (j == i)
			break;
		// if (s[i] == '*') {
		s[i] = 'x';
		ans++;
		// }
		j = i;
	}

	// cout << s << ": ";
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