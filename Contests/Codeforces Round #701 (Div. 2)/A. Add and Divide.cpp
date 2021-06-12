#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
// #define mod 998244353
#define MAX 1000001					//1e6 + 1
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define mp make_pair

//A. Add and Divide
//Codeforces Round #701 (Div. 2)
void solve() {
	int a, b, i;
	cin >> a >> b;
	int ans = INT_MAX, cnt = 0;

	if (b < 2)
		cnt++, b++;
	
	int n = log2(1000000000);		//worst case
	int temp;
	for (i = 0; i < n; i++) {
		temp = (double)log(a)/(double)log(b) + 1;
		ans = min(ans, temp + cnt);
		if (a < b)
			break;
		b++;
		cnt++;
	}

	cout << ans << "\n";
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