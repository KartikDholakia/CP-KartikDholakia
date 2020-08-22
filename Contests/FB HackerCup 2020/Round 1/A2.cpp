#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;
#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807

//Problem A1: Perimetric - Chapter 1
void solve() {
	int n, k, i;
	st w;
	int a, b, c, d;
	cin >> n >> k;
	vector<int> L(n, 0);
	vector<int> H(n, 0);
	vector<int> W(n, 0);

	for (i = 0; i < k; i++)
		cin >> L[i];
	cin >> a >> b >> c >> d;

	while (i < n) {
		L[i] = ((a*L[i-2])%d + (b*L[i-1])%d + c%d) % d + 1;
		i++;
	}

	for (i = 0; i < k; i++)
		cin >> W[i];
	cin >> a >> b >> c >> d;

	while (i < n) {
		W[i] = ((a*W[i-2])%d + (b*W[i-1])%d + c%d) % d + 1;
		i++;
	}

	for (i = 0; i < k; i++)
		cin >> H[i];
	cin >> a >> b >> c >> d;
	
	while (i < n) {
		H[i] = ((a*H[i-2])%d + (b*H[i-1])%d + c%d) % d + 1;
		i++;
	}

	ll ans = 1, p = 0, temp;
	int l;

	p = 2*(W[0] + H[0]);
	ans = p % mod;
	l = L[0] + W[0];

	map<int, int> xy;
//	map<int, int> :: iterator it;
	
	cout << "\n";
	cout << p << ": " << l << "\n";

	for (i = 1; i < n; i++) {

		if (L[i] > l)
			temp = 2*(W[i] + H[i]);

		else if (L[i] == l)
			temp = 2*W[i];

		else {
			if (L[i] + W[i] <= l)
				temp = 0;
			else
				temp = 2*(L[i] + W[i] - l);
		}

		p = (p + temp % mod) % mod;

		if (l < L[i] + W[i])
			l = L[i] + W[i];

		cout << p << ": " << l << "\n";
		ans = (ans * p) % mod;
	}

 	cout << "\n";
	cout << ans << "\n";
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
	for (st i = 0; i < t; i++) {
		cout << "Case #" << i+1 << ": ";
		solve();
	}

	cerr << "time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}