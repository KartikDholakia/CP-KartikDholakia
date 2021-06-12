#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(),x.end()

//Mahesh and his lost array
//https://www.codechef.com/problems/ANUMLA
//https://qr.ae/pNoiwm
void solve() {
	int n, i, inp, x;
	cin >> n;
	
	multiset <int> s;
	vector<int> ans, t;

	for (i = 0; i < pow(2, n); i++) {
		cin >> inp;
		if (inp)
			s.insert(inp);
	}
	
	auto it1 = s.begin();
	auto it2 = t.begin();
	int tsize;

	while (!s.empty()) {
		x = *s.begin();
		ans.push_back(x);
        tsize = t.size();
		for (i = 0; i < tsize; i++) {
			t.push_back(x + t[i]);
			s.erase(s.find((x + t[i])));
		}
		t.push_back(x);
		s.erase(s.find(x));
	}

	for (i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
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

	cerr << "time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}