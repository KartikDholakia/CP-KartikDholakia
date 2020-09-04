#include<bits/stdc++.h> 
using namespace std; 
typedef unsigned long long ll;
typedef short int st; 

//https://www.spoj.com/problems/SUBS/
bool subSeq(int mid, string x, string y) {
	if (!mid)
		return 1;
	int req = 0;
	int i = 0, j = 0;
	while (i < x.size() && j < y.size()) {
		if (x[i] == y[j]) {
			req++;
			if (req == mid) {
				i++;
				req = 0;
			}
		}
		j++;
	}
	if (i == x.size())
		return 1;
	else 
		return 0;
}

void solve() {
	string x, y;
	cin >> x >> y;
	int m = 0;
	int lo = 0, hi = y.size()/x.size(), mid;
	while (hi > lo) {
		mid = lo + (hi-lo+1)/2;
		if(subSeq(mid, x, y))
			lo = mid;
		else
			hi = mid - 1;
	}
	cout << hi << "\n";
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
