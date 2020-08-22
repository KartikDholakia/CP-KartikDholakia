#include<bits/stdc++.h> 
using namespace std; 
//https://www.spoj.com/problems/BUSYMAN/
//ACCEPTED :)
bool cmp(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second < p2.second)
		return true;
	else if (p1.second == p2.second) {
		if  (p1.first < p2.first)
			return true;
		else 
			return false;
	}
	else
		return false;
}

void solve() {
	short int t;
	int n, start, end, count = 1;
	vector<pair<int, int>> v;
	pair<int, int> prev;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> start >> end;
			v.push_back(make_pair (start, end));
		}
		sort(v.begin(), v.end(), cmp);
		count = 1;
		prev = v[0];
		for (int j = 1; j < v.size(); j++) {
			if (v[j].first >= prev.second) {
				count++;
				prev = v[j];	
			} 
				
		}
		cout << count << "\n";
		v.clear();
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
