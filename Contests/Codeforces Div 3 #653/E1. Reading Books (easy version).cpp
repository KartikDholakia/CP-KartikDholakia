#include<bits/stdc++.h> 
using namespace std; 
typedef unsigned long long ll;
typedef unsigned short int st; 

//E1. Reading Books (easy version)
void solve() {
	ll t_sum = 0;
	vector<st> al, bo, both;
	st t;
	int n, k;
	bool a, b;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> t >> a >> b;
		if (a && b)
			both.push_back(t);
		else {
			if (a)
				al.push_back(t);
			if (b)
				bo.push_back(t);
		}
	}
	if ((both.size() + al.size() < k) || (both.size() + bo.size() < k)) {
		cout << -1 << "\n";
		return;
	}
	
	sort(both.begin(), both.end());
	sort(al.begin(), al.end());
	sort(bo.begin(), bo.end());
	
	int ai = 0, bi = 0;
	for (int i = 0; i < both.size() && ai < k && bi < k; i++) {
		t_sum += both[i];
		ai++;
		bi++;
	}
	for (int i = 0; i < al.size() && ai < k; i++, ai++) {
		t_sum += al[i];
	}
	for (int i = 0; i < bo.size() && bi < k; i++, bi++) {
		t_sum += bo[i];
	}
	
	cout << t_sum << "\n";

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

//	int t;
//	cin >> t;
//	for (int i = 0; i < t; i++)
		solve(); 

	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0; 
} 
