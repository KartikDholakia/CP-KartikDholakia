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

//E. Accidental Victory
//Codeforces Round #702 (Div. 3)
bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first < b.first)
		return 1;
	else if (a.first == b.first)
		return a.second < b.second;
	else
		return 0;
}

void solve() {
	int n, i, inp;
	cin >> n;
	vector<pair<int, int>> v;	//first->value, 2nd->index

	for (i = 0; i < n; i++) {
		cin >> inp;
		v.pb(make_pair(inp, i+1));
	}

	sort(all(v), cmp);
	// for (i = 0; i < n; i++) {
	// 	cout << v[i].first << " " << v[i].second << "\n";
	// }

	vector<int> prefix(n);
	prefix[0] = v[0].first;

	for (i = 1; i < n; i++) {
		prefix[i] = prefix[i-1] + v[i].first; 
	}

	vector<int> ans;
	for (i = n-1; i >= 0; i--) {
		if (i == n-1) {
			ans.pb(v[i].second);
			continue;
		}
		if (prefix[i] >= v[i+1].first)
			ans.pb(v[i].second);
		else
			break;
	}

	cout << ans.size() << "\n";
	for (i = ans.size()-1; i >= 0; i--)
		cout << ans[i] << " ";
	cout << "\n";
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