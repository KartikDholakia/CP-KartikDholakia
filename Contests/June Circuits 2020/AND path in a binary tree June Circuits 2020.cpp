#include<bits/stdc++.h> 
using namespace std; 
typedef unsigned long long ll;
typedef unsigned short int st; 

//AND path in a binary tree June Circuits 2020
int fact(int n) {
	return (n == 1 || n == 0) ? 1: n * fact(n - 1);   
}

int f(double n) {
	int integral = n;
	if (n - integral == 0.00) 
		return integral;
	
	else
		return integral+1;
}

void solve() {
	int n, j, x;
	cin >> n;
	long int count = 0;
	
	for (int i = 1; i <= n; i = i+2) {
		x = (int)(log2((n+1)/(i+1)));
		count += x; 
	}
	
	cout << n << "\t" << count;
	int a = (n+1)/4;
	count = a*(int)(log2(2*a)) - f((log2(fact(a))));
	cout << "\t" << count << "\n";
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
	cout << "n\tcount(O(n))\tcount(O(1))\n";
	for (int i = 0; i < t; i++)
		solve(); 

	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0; 
} 
