#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)

//B. New Colony
//Codeforces Round #699 (Div. 2)
void solve() {
	int n, k, i;
	cin >> n >> k;
	vector<int> v(n);
	for (i = 0; i < n; i++)
		cin >> v[i];

	bool flag = 1;
	while (k--) {
		for (i = 0; i < n; i++) {
			if (i == n-1) {
				flag = 0;
				break;
			}
			else if (v[i] < v[i+1]) {
				v[i]++;
				break;
			}
		}
		if (flag == 0)
			break;
	}
	if (flag)
		cout << i+1 << "\n";
	else
		cout << "-1\n";
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