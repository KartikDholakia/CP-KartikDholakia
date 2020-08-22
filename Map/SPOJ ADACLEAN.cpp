#include<bits/stdc++.h> 
using namespace std; 

void solve() {
	//https://www.spoj.com/problems/ADACLEAN/
	int t, n, k;
	string str, sub;
	unordered_set<string> s;
	//set<string> :: iterator itr;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> k;
		cin >> str;
		for (int j = 0; j <= n-k; j++) {
			sub = str.substr(j, k);
			s.insert(sub);
		}
		cout << s.size() << "\n";
		s.clear();
	}
}

int main() 
{ 
	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("error.txt", "w", stderr); 
	freopen("output.txt", "w", stdout); 
	//freopen is used to associate a file with stdin or stdout stream in C++
	#endif 

	solve(); 

	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0; 
} 
