#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()

//C. Ball in Berland
//Codeforces Round #697 (Div. 3)
void solve() {
	int a, b, k, i, j;
	cin >> a >> b >> k;
	vector<int> A(k), B(k);
	vector<int> afreq(a+1, 0), bfreq(b+1, 0);

	for (i = 0; i < k; i++) {
		cin >> A[i];
		afreq[A[i]]++;
	}
	for (i = 0; i < k; i++) {
		cin >> B[i];
		bfreq[B[i]]++;
	}

	ll ans = 0;
	for (i = 0; i < k; i++) {
		ans += (k-i-1) - (afreq[A[i]] - 1 + bfreq[B[i]] - 1);
		afreq[A[i]]--;
		bfreq[B[i]]--;
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

	cerr << "time: "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}