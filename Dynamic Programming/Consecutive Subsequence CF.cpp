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
#define loop(var, start, end) for (auto var = start; var < end; var++)
#define loop_rev(var, start, end) for(auto var = start; var > end; var--)

//https://codeforces.com/problemset/problem/977/F
//DP
void solve() {
	ll n, i;
	cin >> n;
	
	vll v(n+1, 0);
	map<ll, ll> dp;			//dp[x] stores length of subseq ending at x

	loop(i, 1, n+1) {
		cin >> v[i];
		dp[v[i]] = max(dp[v[i]], dp[v[i] - 1] + 1);
	}
	
	ll ans = 0, end;
	for (auto it = dp.begin(); it != dp.end(); it++) {
		if (ans < it->second) {
			ans = it->second;
			end = it->first;
		}
	}

	// cout << end << " ";
	cout << ans << "\n";
	stack<ll> idx;
	loop_rev(i, n, 0) {
		if (v[i] == end) {
			idx.push(i);
			end--;
		}
		if (end == 0)
			break;
	}

	while(!idx.empty()) {
		cout << idx.top() << " ";
		idx.pop();
	}
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
	// cin >> t;
	for (int i = 1; i <= t; i++) {
		// cout << "Case #" << i << ": ";
		solve();
	}

	cerr << "time: "<<(double)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}
