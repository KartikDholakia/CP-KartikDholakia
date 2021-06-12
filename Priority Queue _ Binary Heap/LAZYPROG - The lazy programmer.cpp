#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(),x.end()

//LAZYPROG - The lazy programmer
//https://www.spoj.com/problems/LAZYPROG/
struct lazy {
	int a, b, d;
};

bool cmp(lazy x, lazy y) {
	if (x.d == y.d)
		return (double)(x.b/x.a) >= (double)(y.b/y.a);
	return x.d <= y.d;
}

void solve() {
	int n, a, b, d;
	cin >> n;
	vector<lazy> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].a >> v[i].b >> v[i].d;
	}
	sort(all(v), cmp);

	int t = 0;
	double ans = 0;

	for (int i = 0; i < n; i++) {
		//cout << v[i].a << " " << v[i].b << " " << v[i].d << " => ";
		if (v[i].b > v[i].d - t) {
			ans += (double)(v[i].b - v[i].d + t)/(double)(v[i].a);
		} 
		t = v[i].d;
		//cout << ans << "; " << t << "\n";
	}

	cout << setprecision(2) << fixed << ans << "\n";
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

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
	}

	cerr << "time: "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}