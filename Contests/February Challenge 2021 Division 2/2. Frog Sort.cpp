#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)

//2. Frog Sort
//February Challenge 2021 Division 2
struct frog {
	int w, p_initial, l;
};

bool cmp(frog x, frog y) {
	return x.w < y.w;
}

void solve() {
	int n, i, inp;
	cin >> n;
	
	frog arr[4];
	for (i = 0; i < n; i++) {
		cin >> arr[i].w;
		arr[i].p_initial = i+1;
	}
	for (i = 0; i < n; i++) {
		cin >> arr[i].l;
	}

	sort(arr, arr + n, cmp);

	// for (i = 0; i < n; i++) {
	// 	cout << i << " " << arr[i].w << " " << arr[i].p_initial << " " << arr[i].l << " \n";
	// }
	// cout << "\n";

	ll ans = 0, x = 0;
	int pf = arr[0].p_initial;
	
	// cout << arr[0].w << " " << pf << " " << x << "\n";

	for (i = 1; i < n; i++) {
		if (arr[i].p_initial > pf)
			x = 0;
		else
			x = ((pf - arr[i].p_initial)/arr[i].l) + 1;

		pf = arr[i].p_initial + x*arr[i].l;
		ans += x;
		// cout << arr[i].w << " " << pf << " " << x << "\n";
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