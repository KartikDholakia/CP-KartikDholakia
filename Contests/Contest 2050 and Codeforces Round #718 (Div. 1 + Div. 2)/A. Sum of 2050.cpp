#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

#define MOD 1000000007				//1e9 + 7
#define MAX 200001					//2e5 + 1
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define mp make_pair

//
//Contest 2050 and Codeforces Round #718 (Div. 1 + Div. 2)
llu power(llu x, llu y) {
    llu temp;
    if( y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return temp * temp;
    else
        return x * temp * temp;
}
 

void solve() {
	llu n, k1, k2, num = 0, cnt = 0, temp;
	cin >> n;

	if (n < 2050) {
		cout << "-1\n";
		return;
	}

	while (num < n) {
		// temp = num;
		k1 = (n - num)/2050;
		if (k1 != 0)
			k1 = (ll)log10((double)((n - num)/2050));
		temp = 2050 * power(10, k1);
		k2 = (n-num)/temp;
		num += temp*k2;
		cnt += k2;
		if (k1 + k2 == 0)
			break;
		// cout << num << " " << cnt << "\n";
		// cout << "+" << num-temp << " " << num << " " << cnt << "\n";
	}

	if (num == n)
		cout << cnt << "\n";
	else
		cout << "-1\n";
}

//DON'T GET STUCK AT ONE APPROACH

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
		// cout << "Case #" << i << ": ";
		solve();
	}

	cerr << "time: "<<(double)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}