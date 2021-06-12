#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)

//3. Team Name
//February Challenge 2021 Division 2
void solve() {
	int n, i, j;
	cin >> n;
	string inp;
	unordered_set<string> s;
	vector<string> v;
	// map<char, int> first_char;
	vector<int> first_char(26, 0);

	for (i = 0; i < n; i++) {
		cin >> inp;
		s.insert(inp);
		v.pb(inp);
		first_char[inp[0] - 'a']++;
	}
	sort(all(v));

	string x, y;
	ll ans = 0;
	for (i = 0; i < n-1; i++) {
		for (j = i + first_char[v[i][0] - 'a']; j < n; j++) {
			x = v[i];
			y = v[j];
			if (x.substr(1, x.size()-1) == y.substr(1, y.size()-1))
				continue;
			x[0] = v[j][0];
			y[0] = v[i][0];
			if ((s.find(x) == s.end()) && (s.find(y) == s.end()))
				ans += 2;
		}
		first_char[v[i][0] - 'a']--;
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
		solve();
	}

	cerr << "time: "<<(double)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}