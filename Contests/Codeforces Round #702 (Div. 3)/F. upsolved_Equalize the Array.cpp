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

//F. Equalize the Array
//Codeforces Round #702 (Div. 3)
void solve() {
	int n, i, inp;
	cin >> n;
	map<int, int> m;
	
	for (i = 0; i < n; i++) {
		cin >> inp;
		m[inp]++;
	}

	vector<int> v;
	for (auto it = m.begin(); it != m.end(); it++)
		v.pb(it->second);

	int n1 = v.size();
	sort(all(v));

	// for (i = 0; i < n1; i++)
	// 	cout << v[i] << " ";
	// cout << "\n";

	vector<int> pre(n1, 0);
	pre[0] = v[0];

	for (i = 1; i < n1; i++) {
		pre[i] += pre[i-1] + v[i];
	}

	// for (i = 0; i < n1; i++)
	// 	cout << pre[i] << " ";
	// cout << "\n";

	int ans = INT_MAX, temp;
	for (i = 0; i < n1; i++) {
		if (i > 0 && v[i] == v[i-1])
			continue;
		if (i)
			temp = pre[i-1] + pre[n1 - 1] - (n1 - i - 1) * v[i] - pre[i];
		else
			temp = pre[n1 - 1] - (n1 - i - 1) * v[i] - pre[i];
		// cout << "i = " << i << " temp = " << temp << "\n";
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
		solve();
	}

	cerr << "time: "<<(double)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}