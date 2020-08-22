#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;
#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807

//C. Boats Competition
int max(int x, int y) {
	return x > y? x:y;
}

st min(st x, st y) {
	return x < y? x:y;	
}

void solve() {
	st n, i;
	cin >> n;
	
	map<st, st> w;
	map<st, st> :: iterator it; 
	vector<st> a(n);

	for (i = 0; i < n; i++) {
		cin >> a[i];
		w[a[i]]++;
	}

	if (n < 2) {
		cout << 0 << "\n";
		return;
	}

	sort(a.begin(), a.end());
	st l = a[0] + a[1];
	st r = a[n-1] + a[n-2], s = 0, cnt = 0, max_cnt = 0;

	for (s = l; s <= r; s++) {
		cnt = 0;
		for (it = w.begin(); it != w.end() && it->first <= s/2; it++) {
			if (2*(it->first) == s)
				cnt +=	(it->second)/2;
			else if (w[s - it->first] != 0)
				cnt += min(it->second, w[s - it->first]);
		}
		if (cnt > max_cnt)
			max_cnt = cnt;
	}

	cout << max_cnt << "\n";
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
