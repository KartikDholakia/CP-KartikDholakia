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

//E. Restoring the Permutation_Upsolved
//Codeforces Round #710 (Div. 3)
void solve() {
	int n, i, mx = INT_MIN;
	cin >> n;
	vector<int> v(n+1);
	vector<bool> pre(n+1, 0);
	pre[0] = v[0] = -1;

	for (i = 1; i <= n; i++) {
		cin >> v[i];
		pre[v[i]] = 1;
		mx = max(mx, v[i]);
	}

	//for minimal
	cout << v[1] << " ";
	int j = 1;
	for (i = 2; i <= n; i++) {
		if (v[i] != v[i-1])
			cout << v[i] << " ";
		else {
			while (j <= n && pre[j])
				j++;
			cout << j << " ";
			j++;
		}
	}
	cout << "\n";

	//for maximal:
	cout << v[1] << " ";
	j = n;
	for (i = 2; i <= n; i++) {
		if (v[i] != v[i-1])
			cout << v[i] << " ";
		else {
			j = v[i];
			while (j >= 1 && pre[j])
				j--;
			cout << j << " ";
			pre[j] = 1;
			j--;
		}
	}
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
		// cout << "Case #" << i << ": ";
		solve();
	}

	cerr << "time: "<<(double)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}