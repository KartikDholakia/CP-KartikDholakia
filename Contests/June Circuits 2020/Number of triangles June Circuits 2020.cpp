#include<bits/stdc++.h> 
using namespace std; 
typedef unsigned long long ll;
typedef short int st; 

//Number of triangles June Circuits 2020
//partially solved
void solve() {
	int n, b1, b2;
	cin >> n;
	cin >> b1 >> b2;
	int count = 0;

	for (int i = 1; i < n; i++) {
		if ((i == b1)||(i == b2)||(i+1 == b1)||(i+1 == b2))
			continue;
		count += n-4;
		if ((i != 1) && (i - 1 != b1) && (i - 1 != b2))
			count--;
		cout << i << " " << count << "\n";
	}

	if ((n != b1 && n != b2)&&(b1 != 1 && b2 != 1)) {
		count += n-4;
		if (b1 != 2 && b2 != 2)
			count--;
		if ((n-1 != b1)&&(n-1 != b2))
			count--;
	}

	cout << n << " " << count << "\n";

	cout << count << "\n\n";
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

	st t;
	cin >> t;
	for (int i = 0; i < t; i++)
		solve(); 

	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0; 
} 
