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

//Round A 2021 - Kick Start 2021
void solve() {
	int n, i, k, cnt = 0;
	string s;
	cin >> n >> k;
	cin >> s;

	for (i = 0; i < n/2; i++) {
		if (s[i] != s[n - i - 1])
			cnt++;
	}

	cout << abs(k-cnt) << "\n";
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