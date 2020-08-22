#include<bits/stdc++.h> 
using namespace std; 
typedef unsigned long long ll; 

//https://www.spoj.com/problems/ABCDEF/
void solve() {
	map<ll, ll> m1, m2;
	short int n;
	cin >> n;
	vector<ll> v;
	ll inp;
	for (short int i = 0; i < n; i++) {
		cin >> inp;
		v.push_back(inp);
	}
	short int a, b, c;
	ll lhs, rhs;
	for (a = 0; a < v.size(); a++) {
		for (b = 0; b < v.size(); b++) {
			for (c = 0; c < v.size(); c++) {
				lhs = v[a]*v[b]+v[c];
				rhs = v[a]*(v[b]+v[c]);
				m1[lhs]++;
				if (v[a] != 0)
					m2[rhs]++;
			}
		}
	}
	ll count = 0;
	map<ll, ll> :: iterator i, j;
	for (i = m1.begin(); i != m1.end(); i++) {
		j = m2.find(i->first);
		if (j != m2.end())
			count += i->second * j->second;
	}
	cout << count << "\n";
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

/*	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
*/		solve(); 

	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0; 
} 
