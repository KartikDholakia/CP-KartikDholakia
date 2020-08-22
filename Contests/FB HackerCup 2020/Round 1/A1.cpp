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
	cin >> n >> k >> w;
	vector<int> L(n, 0);
	vector<int> H(n, 0);

	for (i = 0; i < k; i++)
		cin >> L[i];
	cin >> a >> b >> c >> d;

	while (i < n) {
		L[i] = (a*L[i-2]%d + b*L[i-1]%d + c%d) % d + 1;
		i++;
	}

	for (i = 0; i < k; i++)
		cin >> H[i];
	cin >> a >> b >> c >> d;
	
	while (i < n) {
		H[i] = (a*H[i-2]%d + b*H[i-1]%d + c%d) % d + 1;
		i++;
	}

	ll ans = 1, p = 0, temp;
	int l, h, diff, x;

	p = 2*(w + H[0]);
	ans = ((ans % mod) * (p % mod)) % mod;
	l = L[0] + w;
	h = H[0];

	map<int, int> xy;
	map<int, int> :: iterator it;
	for (x = L[0]; x <= l; x++)
		xy[x] = H[0];

	for (i = 1; i < n; i++) {

		diff = (H[i] >= xy[L[i]]) ? (H[i] - xy[L[i]]) : 0;

		for (x = L[i]; x <= L[i] + w; x++)
			xy[x] = max(H[i], xy[x]);
		
		if (L[i] > l) 
			temp = 2*(w + H[i]);

		else if (L[i] == l)
			temp = 2*(w + diff);

		else
			temp = 2*(L[i] - L[i-1] + diff);

		p += temp;
		l = L[i] + w;

		ans = ((ans % mod) * (p % mod)) % mod;
	}

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