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

//2. Space Arrays
//February Challenge 2021 Division 2
void solve() {
	int n, i, d = 0;
	cin >> n;
	vector<int> v(n);

	for (i = 0; i < n; i++)
		cin >> v[i];
	
	sort(all(v));
	for (i = 1; i <= n; i++) {
		if (i < v[i-1]) {
			cout << "Second\n";
			return;
		}
		d += i - v[i-1];
	}
	if (d % 2)
		cout << "First\n";
	else
		cout << "Second\n";
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