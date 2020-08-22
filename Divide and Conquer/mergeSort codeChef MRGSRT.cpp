#include<bits/stdc++.h> 
using namespace std; 
typedef unsigned long long ll; 

//merge srt codechef
void solve() {
	int s, t, i;
	cin >> s >> t >> i;
	if ((i < s)||(i > t)) {
		cout << -1;
		return;
	}
	int mid, count = 0;
	while (s < t) {
		cout << s << " " << t << "\n";
		mid = (s+t)/2;
		if (i > mid)
			s = mid + 1;
		else
			t = mid;
		count++;
		if (s == t) {
			cout << s << " " << t << "\n";
			count++;
			break;
		}

	}
	cout << count  << "\n";
}

int main() 
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("error.txt", "w", stderr); 
	freopen("output.txt", "w", stdout); 
	//freopen is used to associate a file with stdin or stdout stream in C++
	#endif 

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
		solve(); 

	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0; 
} 
