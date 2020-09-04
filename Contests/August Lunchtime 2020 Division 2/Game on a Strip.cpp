#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(),x.end()

//Game on a Strip
//August Lunchtime 2020 Division 2
void solve() {
	int n, i;
	cin >> n;
	int cnt = 0;
	bool inp;
	vector<int> subcnt;
	for (i = 0; i < n; i++) {
		cin >> inp;
		if (inp && cnt) {
			subcnt.push_back(cnt);
			cnt = 0;
		}
		else if (inp == 0)
			cnt++;
	}

	if (cnt != 0)
		subcnt.push_back(cnt);

	if (subcnt.size() == 0) {
		cout << "No\n";
		return;
	}

	sort(all(subcnt), greater<int>());
	int l1, l2;

	l1 = subcnt[0];
	if (subcnt.size() >= 1)
		l2 = subcnt[1];
	
	if (l1 % 2 != 1) {
		cout << "No\n";
		return;
	}

	if ((subcnt.size() > 1) && (l2 >= (l1 + 1)/2)) {
		cout << "No\n";
		return;	
	}

	cout << "Yes\n";

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

	int t = 1;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}

	cerr << "time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}