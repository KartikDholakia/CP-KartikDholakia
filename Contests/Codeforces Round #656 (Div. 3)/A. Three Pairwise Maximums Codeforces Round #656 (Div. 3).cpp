#include<bits/stdc++.h> 
using namespace std; 
typedef long long ll;
typedef short int st; 
#define mod 1000000007

//A. Three Pairwise Maximums Codeforces Round #656 (Div. 3)
int max(int x, int y, int z) {
	if (x > y && x > z)
		return x;
	else {
		if (y > z)
			return y;
		else
			return z;
	}
}

void solve() {
	int x, y, z;
	cin >> x >> y >> z;
	int max_inp = max(x, y, z);
	int count_max = 0;

	if (x == max_inp)
		count_max++;
	if (y == max_inp)
		count_max++;
	if (z == max_inp)
		count_max++;
	
	if (count_max < 2) {
		cout << "NO" << "\n";
		return;
	}
	else {
		cout << "YES" << "\n";
		cout << max_inp << " " ;
		if (x < max_inp)
			cout << x << " " << x << "\n";
		else if (y < max_inp)
			cout << y << " " << y << "\n";
		else
			cout << z << " " << z << "\n"; 
	}
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

