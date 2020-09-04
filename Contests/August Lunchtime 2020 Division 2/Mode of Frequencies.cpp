#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(),x.end()

//Mode of Frequencies
//August Lunchtime 2020 Division 2
void solve() {
	int n, i;
	cin >> n;
	int inp;
	vector<int> arr(11, 0);
	for (i = 0; i < n; i++) {
		cin >> inp;
		arr[inp]++;
	}
	
	// for (i = 0; i < 11; i++)
	// 	cout << arr[i] << " ";
	// cout << "\n";

	map<int, int> m;
	map<int, int> :: iterator it;
	int ans = 0, max_freq = 0;
	for (i = 1; i <= 10; i++) {
		if (arr[i] == 0)
			continue;
		m[arr[i]]++;
		if ((m[arr[i]] > max_freq) || ((m[arr[i]] == max_freq) && (arr[i] < ans))) {
			ans = arr[i];
			max_freq = m[arr[i]];
		}
	}

	// for (it = m.begin(); it != m.end(); it++) {
	// 	cout << it->first << ": " << it->second << "\n";
	// }

	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
	//freopen is used to associate a file with stdin or stdout stream in C++
	#endif

	int t = 1;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}

	cerr << "time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}