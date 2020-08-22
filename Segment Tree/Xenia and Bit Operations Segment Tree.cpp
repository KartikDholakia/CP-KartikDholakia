#include<bits/stdc++.h> 
using namespace std; 
typedef unsigned long long ll;
typedef short int st; 

//Xenia and Bit Operations https://codeforces.com/contest/339/problem/D
int update(int i, int b, bool rem, vector<int> &tree) {
	tree[i] = b;
	for (i = i/2; i > 0; i = i/2) {
		if (rem == ((int)log2(i))%2)
			tree[i] = tree[2*i] | tree[2*i + 1];
		else
			tree[i] = tree[2*i] ^ tree[2*i + 1];
	}
	return tree[1]; 
}

void solve() {
	st n;
	int m, i;
	cin >> n >> m;
	int N = pow(2, n);
	
	vector<int> tree(2*N, 0);
	for (i = 0; i < N; i++) {
		cin >> tree[i + N];
	}
	
	bool rem = (n-1)%2;

	//build tree:
	for (i = N-1; i > 0; i--) {
		if (rem == ((int)log2(i))%2)
			tree[i] = tree[2*i] | tree[2*i + 1];
		else
			tree[i] = tree[2*i] ^ tree[2*i + 1];
	}

/*	cout << "Tree is: ";
	for (i = 1; i < 2*N; i++)
		cout << tree[i] << " ";
*/
	int p, b;
	for (i = 0; i < m; i++) {
		cin >> p >> b;
		cout << update(p+N-1, b, rem, tree) << "\n";
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

	st t = 1;
	//cin >> t;
	for (st i = 0; i < t; i++)
		solve(); 

	cerr << "time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0; 
} 

