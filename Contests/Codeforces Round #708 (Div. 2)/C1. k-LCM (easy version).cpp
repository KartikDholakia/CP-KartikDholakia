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

//C1. k-LCM (easy version)
//Codeforces Round #708 (Div. 2)
void solve() {
	int n, k;
	cin >> n >> k;

	if (n % 2) {
		cout << n/2 << " " << n/2 << " 1\n";
	}
	else {
		if (n % 4 == 0) {
			cout << n/2 << " " << n/4 << " " << n/4 << "\n";
		}
		else
			cout << n/2 - 1 << " " << n/2 - 1 << " 2\n";
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
	cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
	}

	cerr << "time: "<<(double)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}