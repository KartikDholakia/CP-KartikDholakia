#include<bits/stdc++.h> 
using namespace std; 
typedef unsigned long long ll;
typedef unsigned short int st; 

//C. Move Brackets Div 3 #653
void solve() {
	st n, count = 0;
	short top = 0;
	cin >> n;
	string br;
	cin >> br;
	//cout << br << " ";
	for (st i = 0; i < n; i++) {
		if (br[i] == '(')
			top++;
		else {
			top--;
			if (top < 0) {
				count++;
				top = 0;
			}
		}
		//cout << br[i] << " top: " << top << "\tcount: " << count << "\n"; 
	}
	cout << count << "\n";
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
