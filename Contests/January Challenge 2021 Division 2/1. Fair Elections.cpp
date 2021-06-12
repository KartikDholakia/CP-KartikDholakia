#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()

//Fair Elections
//January Challenge 2021 Division 2
void solve() {
	int n, m, i, j, suma = 0, sumb = 0;
	cin >> n >> m;
	vector<int> A(n), B(m);

	for (i = 0; i < n; i++) {
		cin >> A[i];
		suma += A[i];
	}

	for (i = 0; i < m; i++) {
		cin >> B[i];
		sumb += B[i];
	}

	sort(all(A));
	sort(all(B), greater<int> ());

	if (suma > sumb) {
		cout << "0\n";
		return;
	}

	int ans = 0;
	for (i = 0, j = 0; i < n && j < m; i++, j++) {
		suma += B[j] - A[i];
		sumb += A[i] - B[j];
		ans++;
		if (suma > sumb)
			break;
	}

	if (suma > sumb) 
		cout << ans << "\n";
	else
		cout << "-1\n";
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
	for (int i = 1; i <= t; i++) {
		// cout << "Case #" << i << ": ";
		// cout << "Test " << i << ":\n";
		solve();
	}

	cerr << "time: "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}