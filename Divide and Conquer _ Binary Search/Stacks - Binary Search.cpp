#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(),x.end()

//Problem Name - Stacks
//Binary Search
//https://www.codechef.com/problems/STACKS
void solve() {
	int n, i;
	cin >> n;
	vector<int> v(n);
	for (i = 0; i < n; i++)
		cin >> v[i];

	vector<int> ans;
	int l, r, mid;
	ans.push_back(v[0]);
	
	for (i = 1; i < n; i++) {
		l = 0, r = ans.size() - 1;
		while (l <= r) {
			mid = l + (r - l)/2;
			if (mid == r)
				break;
			if (ans[mid] <= v[i])
				l = mid + 1;
			else
				r = mid;
		}
		if (ans[mid] <= v[i])
			ans.push_back(v[i]);
		else
			ans[mid] = v[i];
	}

	cout << ans.size() << " ";
	for (i = 0; i < ans.size(); i++) 
		cout << ans[i] << " ";

	cout << "\n";
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

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
	}

	cerr << "time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}