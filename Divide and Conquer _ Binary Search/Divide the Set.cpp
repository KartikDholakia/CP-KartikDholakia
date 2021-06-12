#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(),x.end()

//Divide the Set
//Binary Search
//https://www.codechef.com/problems/DIVSET
bool check(int x, vector<ll> &v, int k, int c) {
	if (x == 0)
		return 1;

	vector<int> sets[x];
	int curr = 0;
	int n = v.size();

	for (int i = 0; i < n; i++) {
		if ((sets[curr].empty()) || (v[i] >= c*sets[curr][sets[curr].size()-1])) {
			sets[curr].push_back(v[i]);
			curr = (curr + 1) % x;
		}
	}

	bool flag = 1;
	for (int i = 0; i < x; i++) {
		if (sets[i].size() != k) {
			flag = 0;
			break;
		}
	}

	return flag;
}

void solve() {
	int n, i, k, c;
	cin >> n >> k >> c;
	ll inp;
	
	vector<ll> v(n);
	for (i = 0; i < n; i++) 
		cin >> v[i];
	
	sort(all(v));
	int l = 0, r = n/k, mid;
	bool f;

	while (l < r) {
		mid = (l + r + 1)/2;
		f = check(mid, v, k, c);

		// cout << l << " " << r << " " << mid << " " << f << "\n";

		if (f)
			l = mid;
		else
			r = mid - 1;
	}

	cout << l << "\n";
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

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
	}

	cerr << "time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}