#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;
#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807

//Chef and Wedding Arrangements
void solve() {
	int n, k, inp;
	cin >> n >> k;
	map<int, int> pre;
	map<int, int> one;
	map<int, int> :: iterator it;
	ll cost = k, opt = 0, aio = 0;

	for (int i = 0; i < n; i++) {
		cin >> inp;
		one[inp]++;
		if (pre[inp] == 0)
			opt = 0;
		else if (pre[inp] == 1)
			opt = 2;
		else
			opt = 1;
		
		if (opt < k)
			cost += opt;

		else {
			// for (it = pre.begin(); it != pre.end(); it++) {
			// 	cout << inp << " " << it->first << " " << it->second << "\n";
			// }
			pre.clear();
			cost += k;
		}
		pre[inp]++;
	}

	for (it = one.begin(); it != one.end(); it++) {
		if (it->second > 1)
			aio += it->second;
	}

	if (cost < aio + (ll)k)
		cout << cost << "\n";
	else
		cout << aio + (ll)k << "\n";
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

	st t = 1;
	cin >> t;
	for (st i = 0; i < t; i++)
		solve();

	cerr << "time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}