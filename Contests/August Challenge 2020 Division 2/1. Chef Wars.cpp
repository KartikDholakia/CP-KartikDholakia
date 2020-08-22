#include<bits/stdc++.h> 
using namespace std; 
typedef long long ll;
typedef short int st; 
#define mod 1000000007
 
//Chef Wars - Return of the Jedi
void solve() {
	int p, h;
	cin >> h >> p;
	while (h && p) {
		h -= p;
		p /= 2;
		if (h < 0)
			h = 0;
	}
	if (h == 0)
		cout << "1\n";
	else
		cout << "0\n";
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
 
	int t = 1;
	cin >> t;
	for (int i = 0; i < t; i++)
		solve(); 
 
	cerr << "time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0; 
} 
