#include<bits/stdc++.h> 
using namespace std; 
typedef long long ll;
typedef short int st;

//Chef and Dragon Dens DRGNDEN July Challenge 2020 Division 2
ll max_taste(int start, int end, vector<int> &h, vector<int> &a) {
	ll sum = a[start - 1];
	int cur_pos = start - 1;
	
	if (start <= end) {
		for (int i = start - 1; i < end; i++) {
			if (h[i] > h[cur_pos]) {
				sum += a[i];
				cur_pos = i;
			}
		}
	}
	else {
		for (int i = start - 1; i >= end-1; i--) {
			if (h[i] > h[cur_pos]) {
				sum += a[i];
				cur_pos = i;
			}
		}	
	}

	if (cur_pos == end-1) 		//means chef has reached the starting point 
		return sum;
	else
		return -1;
}

void solve() {
	int n, q;
	vector<int> h, a;
	st choice;
	int b, k, c, i, inp;
	
	cin >> n >> q;
	for (i = 0; i < n; i++) {
		cin >> inp;
		h.push_back(inp);
	}
	for (i = 0; i < n; i++) {
		cin >> inp;
		a.push_back(inp);
	}

	for (i = 0; i < q; i++) {
		cin >> choice;
		if (choice == 1) {
			cin >> b >> k;
			a[b-1] = k;
		}
		else {
			cin >> b >> c;
			cout << max_taste(c, b, h, a) << "\n";
		}
	}
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
	//cin >> t;
	for (st i = 0; i < t; i++)
		solve(); 

	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0; 
}