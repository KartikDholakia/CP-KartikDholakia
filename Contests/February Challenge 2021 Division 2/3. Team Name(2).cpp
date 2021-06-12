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
	string inp, temp;
	vector<string> v;
	unordered_map<char, unordered_set<string>> m;

	for (i = 0; i < n; i++) {
		cin >> inp;
		temp = inp.substr(1, inp.size()-1);
		v.pb(inp);
		m[inp[0]].insert(temp);
	}

	char c1, c2;
	int common = 0;
	ll ans = 0;
	unordered_map<char, unordered_set<string>> :: iterator it1, it2;
	unordered_set<string> :: iterator k;
	for (it1 = m.begin(); it1 != m.end(); it1++) {
	    for (it2 = it1; it2 != m.end(); it2++) {
	        if (it2 == it1)
	            continue;
			if (it1->second.size() < it2->second.size())
				c1 = it1->first, c2 = it2->first;
			else
				c1 = it2->first, c2 = it1->first;
			common = 0;
			for (k = m[c1].begin(); k != m[c1].end(); k++) {
				if (m[c2].find(*k) != m[c2].end())
					common++;
			}
			ans += 2 * (m[c1].size() - common) * (m[c2].size() - common);
	    }
	}

	cout << ans << "\n";
}

/*
4
2
suf mas
3
good game guys
4
hell bell best test
7
xa xb yb yc yd zd zf
*/

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