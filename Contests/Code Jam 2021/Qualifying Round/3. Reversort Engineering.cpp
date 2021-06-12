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

//3. Reversort Engineering
//Code Jam 2021
void solve() {
	int n, c, i;
	cin >> n >> c;

	if (c < n-1 || c >= n*(n+1)/2) {
		cout << "IMPOSSIBLE\n";
		return;
	}

	vector<int> ans(n+1, 0), cost(n+1, 0);
	cost[n] = 0;

	for (i = 1; i < n; i++) {
		if (c - n + i + 1 >= n - i + 1) {
			cost[i] = n-i+1;
		}
		else {
			cost[i] = c - n + i + 1;
		}
		c -= cost[i];
	}

	for (i = 0; i <= n; i++)
		ans[i] = i;

	for (i = n-1; i >= 1; i--) {
		if (cost[i] == 1)
			continue;
		reverse(ans.begin()+i, ans.begin()+i+cost[i]);
	}

	for (i = 1; i <= n; i++)
		cout << ans[i] << " ";

	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}