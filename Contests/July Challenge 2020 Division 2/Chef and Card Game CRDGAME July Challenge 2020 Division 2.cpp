#include<bits/stdc++.h> 
using namespace std; 
typedef unsigned long long ll;
typedef short int st; 

//Chef and Card Game CRDGAME July Challenge 2020 Division 2
ll sod(int x) {
	ll sum = 0;
	while (x > 0) {
		sum += x%10;
		x = x/10;
	}
	return sum;
}

void solve() {
	st n, chef = 0, morty = 0;
	unsigned int a, b;
	ll suma = 0, sumb = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		suma = sod(a);
		sumb = sod(b);
		if (suma > sumb)
			chef++;
		else if (suma < sumb)
			morty++;
		else {
			chef++;
			morty++;
		}
	}
	if (chef > morty) 
		cout << 0 << " " << chef << "\n";
	else if (chef < morty)
		cout << 1 << " " << morty << "\n";
	else
		cout << 2 << " " << chef << "\n";
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

	st t = 1;
	cin >> t;
	for (int i = 0; i < t; i++)
		solve(); 

	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0; 
} 
