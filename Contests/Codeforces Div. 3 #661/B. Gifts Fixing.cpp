#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;
#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807

//B. Gifts Fixing
int max(int x, int y) {
	return x > y? x:y;
}

void solve() {
	st n, i;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	
	for (i = 0; i < n; i++)
		cin >> a[i];
	
	for (i = 0; i < n; i++)
		cin >> b[i];
	
	ll sum = 0;
	int min_a = *min_element(a.begin(), a.end());
	int min_b = *min_element(b.begin(), b.end());

	for (i = 0; i < n; i++) {
		if (a[i] > min_a && b[i] == min_b) {
			sum += (a[i] - min_a);
			//cout << i << " " << sum << "\n";
		}

		else if (b[i] > min_b && a[i] == min_a) {
			sum += (b[i] - min_b);
			//cout << i << " " << sum << "\n";
		}

		else {
			sum += max((b[i] - min_b), (a[i] - min_a));
			//cout << i << " " << sum << "\n";
		}
	}

	cout << sum << "\n";
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
		solve();
	}

	cerr << "time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}
