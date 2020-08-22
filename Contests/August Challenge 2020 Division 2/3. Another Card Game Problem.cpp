#include<bits/stdc++.h> 
using namespace std; 
typedef long long ll;
typedef short int st; 
#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
 
//Another Card Game Problem
void solve() {
	int x, y, nx, ny;
	cin >> x >> y;

	if (x%9 == 0)
		nx = x/9;
	else
		nx = x/9 + 1;
	
	if (y%9 == 0)
		ny = y/9;
	else
		ny = y/9 + 1;
	
	if (nx >= ny)
		cout << 1 << " " << ny << "\n";
	else
		cout << 0 << " " << nx << "\n";
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
