#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()

//C. Array Destruction
//Codeforces Round #696 (Div. 2)
vector<pair<int, int>> fun(vector<int> &v, int k) {
	vector<pair<int, int>> ans;
	multiset<int> s;
	for (auto x : v)
		s.insert(x);
	
	s.erase(s.find(v[v.size()-1]));
	s.erase(s.find(v[k]));
	ans.push_back(make_pair(v[k], v[v.size()-1]));

	auto it  = s.end();
	int x = v[v.size()-1];
	int mx;

	// cout << v[k] << "\n";
	while(!s.empty()) {
		it = s.end();
		it--;
		mx = *it;
		s.erase(s.find(mx));
		// cout << mx << " ";
		if (s.find(x - mx) == s.end()) {
			// cout << "\n";
			return {};
		}
		ans.push_back(make_pair(x - mx, mx));
		s.erase(s.find(x - mx));
		x = mx;
	}
	// cout << "\n";
	return ans;
}

void solve() {
	int n, i;
	cin >> n;
	vector<int> v(2*n);

	for (i = 0; i < 2*n; i++)
		cin >> v[i];
	
	sort(all(v));
	for (i = 0; i < 2*n - 1; i++) {
		vector<pair<int, int>> ans = fun(v, i);
		if (ans.size() > 0) {
			cout << "YES\n";
			cout << v[i] + v[2*n-1] << "\n";
			for (int j = 0; j < ans.size(); j++) {
				cout << ans[j].first << " " << ans[j].second << "\n";
			}
			return;
		}
	}
	cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	#ifndef ONLINE_JUDGE
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

	cerr << "time: "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}