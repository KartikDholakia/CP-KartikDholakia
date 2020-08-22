#include<bits/stdc++.h> 
using namespace std; 
typedef long long ll;
typedef short int st; 
#define mod 1000000007

//COINS - Bytelandian gold coins
map<ll, ll> ans;

ll max(ll a, ll b) {
	if (a > b)
		return a;
	else
		return b;
}

ll solve(ll n) {
	if (ans.find(n) != ans.end())
		return ans[n];
	
	ll temp = solve(n/2) + solve(n/3) + solve(n/4);
	ans[n] = max(n, temp);

	return ans[n];
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

/*	st t = 1;
	//cin >> t;
	for (st i = 0; i < t; i++)
		solve(); 
*/
	ll n;
	ans[0] = 0;

	while (cin >> n) 
		cout << solve(n) << "\n";

	cerr << "time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0; 
} 

