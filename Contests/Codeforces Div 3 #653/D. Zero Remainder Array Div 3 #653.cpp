#include<bits/stdc++.h> 
using namespace std; 
typedef unsigned long long ll;
typedef unsigned short int st; 

//D. Zero Remainder Array Div 3 #653
void solve() {
	int n, k, inp, key;
	map<int, int> rem;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> inp;
		key = (k - inp%k) % k;
		rem[key]++;
	}
	int max = 0;
	map<int, int> :: iterator itr;
	
	for (itr = rem.begin(); itr != rem.end(); itr++) {
		if (itr->first == 0)
			continue;
		if ((itr->second > max)||(itr->first > key && itr->second == max)) {
			max = itr->second;
			key = itr->first;
		}
	}
	//cout << "max: " << max << " key: " << key << "\n";
	if (key == 0)
		cout << 0 << "\n";
	else
		cout << (ll)(k)*(max - 1) + key + 1 << "\n";
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
