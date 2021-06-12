#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define MOD 1000000007
#define MAX 1000001					//1e6 + 1
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define mp make_pair

//E1. Square-free division (easy version)
//Codeforces Round #708 (Div. 2)
void solve() {
	ll n, k, i, j;
	cin >> n >> k;
	vector<ll> v(n);
	set<ll> s;

	cin >> v[0];
	ll mx = v[0], cnt = 1;
	s.insert(v[0]);
	for (i = 1; i < n; i++) {
		cin >> v[i];
		for (j = 1; v[i]*j*j <= mx; j++) {
			if (s.find(v[i]*j*j) != s.end()) {
				cnt++;
				mx = v[i];
				s.clear();
				break;
			}
		}
		s.insert(v[i]);
		if (v[i] > mx)
			mx = v[i];
	}

	cout << cnt << "\n";	
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

	cerr << "time: "<<(double)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}