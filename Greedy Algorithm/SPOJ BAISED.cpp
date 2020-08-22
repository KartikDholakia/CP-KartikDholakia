#include<bits/stdc++.h> 
using namespace std; 
typedef long long ll; 

void solve() {
	//https://www.spoj.com/problems/BAISED/
	int t;
	ll n, sum = 0, temp;
	cin >> t;
	vector<ll> v;
	string tstr;
	for (int i = 0; i < t; i++) {
		cin >> n;
		sum = 0;
		for (ll j = 0; j < n; j++) {
			cin >> tstr >> temp;
			v.push_back(temp);
		}
		sort(v.begin(), v.end());
		for (ll j = 0; j < n; j++) {
			sum += abs(v[j] - j - 1);
		}
		cout << sum << "\n";
		v.clear();
	}
}

int main() 
{ 
	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("error.txt", "w", stderr); 
	freopen("output.txt", "w", stdout); 
	//freopen is used to associate a file with stdin or stdout stream in C++
	#endif 

	solve(); 

	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0; 
} 
