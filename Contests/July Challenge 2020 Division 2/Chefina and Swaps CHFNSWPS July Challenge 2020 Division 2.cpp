#include<bits/stdc++.h> 
using namespace std; 
typedef unsigned long long ll;
typedef short int st; 

//Chefina and Swaps CHFNSWPS July Challenge 2020 Division 2
int min(int a, int b) {
	return (a<b) ? a:b;
}

void solve() {
	int n, inp, i, j;
	cin >> n;
	map<int, int> a, b;
	for (i = 0; i < n; i++) {
		cin >> inp;
		a[inp]++;
		b[inp] = 0;
	}
	for (i = 0; i < n; i++) {
		cin >> inp;
		b[inp]++;
		if (a.find(inp) == a.end())
			a[inp] = 0;
	}

	map<int, int> :: iterator i1 = a.begin();
	map<int, int> :: iterator i2 = b.begin();

	bool flag = 1;
	ll sum = 0;
	int diff;
	vector<int> at, bt;
	while(i1 != a.end() && i2 != b.end()) {
		if ((i1->second - i2->second)%2 != 0) { 
			cout << -1 << "\n";
			flag = 0;
			break;
		}
		if (i1->second > i2->second) {
			diff = (i1->second - i2->second)/2;
			for (i = 0; i < diff; i++)
				bt.push_back(i1->first);
		}
		else if (i1->second < i2->second) {
			diff = (i2->second - i1->second)/2;
			for (i = 0; i < diff; i++)
				at.push_back(i1->first);	
		}
		i1++;
		i2++;
	}

	if (!flag)
		return;

	for (i = 0, j = bt.size()-1; i < at.size() && j >= 0; i++, j--) {
		sum += min(2*((a.begin())->first), min(at[i], bt[j]));
	}

	cout << sum << "\n";

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
	for (st i = 0; i < t; i++)
		solve(); 

	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0; 
} 
