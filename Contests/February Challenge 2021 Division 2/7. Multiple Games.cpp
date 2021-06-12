#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
// #define mod 998244353
#define MAX 1000001					//1e6 + 1
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define mp make_pair

//7. Multiple Games
//February Challenge 2021 Division 2
void solve() {
	int n, q, m, i;
	cin >> n >> q >> m;
	vector<int> v(n+1);
	vector<int> cnt(n+2, 0);	//stores the count of occurence of v[i] in queries

	for (i = 1; i <= n; i++)
		cin >> v[i];

	int l, r;
	//applying prefix trick
	for (i = 0; i < q; i++) {
		cin >> l >> r;
		cnt[l]++;
		cnt[r+1]--;
	}

	int mx = INT_MIN, idx;
	//doing prefix sum:
	for (i = 1; i < n+1; i++) {
		cnt[i] += cnt[i-1];
		if (cnt[i] > mx) {
			mx = cnt[i];
			idx = i;
		}
	}

	// for (i = 1; i <= n; i++)
	// 	cout << v[i] << " ";
	// cout << "\n";
	// for(i = 1; i <= n; i++)
	// 	cout << cnt[i] << " ";
	// cout << "\n";

	cout << mx << "\n";
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