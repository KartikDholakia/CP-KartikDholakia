#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)

//C. Fence Painting
//Codeforces Round #699 (Div. 2)
void solve() {
	int n, m, i;
	cin >> n >> m;
	vector<int> a(n);

	for (i = 0; i < n; i++)
		cin >> a[i];

	int inp;
	map<int, queue<int>> req, done;
	for (i = 0; i < n; i++) {
		cin >> inp;
		if (inp == a[i])
			done[inp].push(i+1);
		else
			req[inp].push(i+1);
	}

	stack<int> prev_rem;
	vector<int> ans(m);
	for (i = 0; i < m; i++) {
		cin >> inp;
		if (req[inp].empty()) {
			if (done[inp].empty())
				prev_rem.push(i);
			else {
				while (!prev_rem.empty()) {
					ans[prev_rem.top()] = done[inp].front();
					prev_rem.pop();
				}
				ans[i] = done[inp].front();
			}
		}
		else {
			while (!prev_rem.empty()) {
				ans[prev_rem.top()] = req[inp].front();
				prev_rem.pop();
			}
			ans[i] = req[inp].front();
			req[inp].pop();
			done[inp].push(ans[i]);
		}
	}

	if (!prev_rem.empty()) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for (i = 0; i < m; i++)
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

	cerr << "time: "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}