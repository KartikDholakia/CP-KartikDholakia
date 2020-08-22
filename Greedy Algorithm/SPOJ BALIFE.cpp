#include<bits/stdc++.h> 
using namespace std; 
typedef long long ll; 

void solve() {
	//https://www.spoj.com/problems/BALIFE/
	int t;
	ll n, max = 0, sum, temp, x, j, y;
	vector<ll> v;
	while (1) {
		cin >> n;
		if (n == -1)
			break;
		sum = 0;
		for (j = 0; j < n; j++) {
			cin >> temp;
			v.push_back(temp);
			sum += temp;
		}
		if (sum%n != 0) {
			cout << -1 << "\n";
		}
		else {
			x = sum/n;
			y = 0;
			max = 0;
			for (j = 0; j < n; j++) {
				y = v[j] - x + y;
				if (y > max)
					max = y;
			}
			cout << max << "\n";
		}
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
