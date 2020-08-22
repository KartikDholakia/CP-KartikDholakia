#include<bits/stdc++.h> 
using namespace std; 
typedef unsigned long long ll;
typedef short int st; 

//https://www.spoj.com/problems/AGGRCOW/
bool f(vector<ll> v, ll x, int c) {
	int cows = 1;
	ll last = v[0];
	for (int i = 1; i < v.size(); i++) {
		if (v[i] - last >= x) {
			last = v[i];
			cows++;
			if (cows >= c)
				return 1;
		}
	}
	return 0;
}

void solve() {
	int n, c;
	cin >> n >> c;
	vector<ll> v;
	ll inp;
	for (int i = 0; i < n; i++) {
		cin >> inp;
		v.push_back(inp);
	}
	sort(v.begin(), v.end());
	ll start = 0, end = v[0] - v[n-1] + 1;
	ll mid;
	while (end - start > 1) {
		mid  = start + (end-start)/2;
		(f(v, mid, c) ? start : end) = mid;
	}
	cout << start << "\n";
}

int main()  { 
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
	for (int i = 0; i < t; i++)
		solve(); 

	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0; 
} 
