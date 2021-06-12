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

//B. M-arrays
//Codeforces Round #708 (Div. 2)
void solve() {
	int n, m, i, inp;
	vector<int> rem(100001, 0);
	cin >> n >> m;

	for (i = 0; i < n; i++) {
		cin >> inp;
		rem[inp % m]++;
	}

	int cnt = 0, mn;
	for (i = 0; i < m; i++) {
		if (rem[i] == 0)
			continue;
		if ((i == 0) || (2*i == m)) {
			// cout << "Case-1: ";
			cnt++;
			rem[i] = 0;
		}
		else if (rem[m - i] == 0) {
			// cout << "Case-2: ";
			cnt += rem[i];
			rem[i] = 0;
		}
		else {
			if (abs(rem[i] - rem[m - i]) <= 1) {
				// cout << "Case-3.1: ";
				cnt++;
				rem[i] = 0;
				rem[m - i] = 0;
			}
			else {
				// cout << "Case-3.2: ";
				mn = min(rem[i], rem[m-i]);
				rem[i] -= mn;
				rem[m-i] -= mn;
				cnt += max(rem[i], rem[m-i]);
				rem[i] = rem[m-i] = 0;
			}
		}
		// cout << i << " " << rem[i] << " " << cnt << "\n";
	}

	cout << cnt << "\n";
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