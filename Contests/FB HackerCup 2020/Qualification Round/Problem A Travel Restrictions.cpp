#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef short int st;
#define mod 1000000007
#define MAX 1000001

//Problem A: Travel Restrictions
void solve() {
	st n, i, j;
	cin >> n;

	vector<char> I(n);
	vector<char> O(n);
	vector<vector<char>> ans;

	for (i = 0; i < n; i++) {
		cin >> I[i];
	}
	for (i = 0; i < n; i++) {
		cin >> O[i];
	}

	for (i = 0; i < n; i++) {
		ans.push_back(vector<char> ());
		for(j = 0; j < n; j++) {
			ans[i].push_back('x');
		}
	}

	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			if (i == j)
				ans[i][j] = 'Y';
			else if (ans[i][j-1] == 'N')
				ans[i][j] = 'N';
			else {
				if (O[j-1] == 'Y' && I[j] == 'Y')
					ans[i][j] = 'Y';
				else
					ans[i][j] = 'N';
			}
		}
		if (i > 0) {
			for (j = i-1; j >= 0; j--) {
				if (ans[i][j+1] == 'N')
					ans[i][j] = 'N';
				else {
					if (O[j+1] == 'Y' && I[j] == 'Y')
						ans[i][j] = 'Y';
					else
						ans[i][j] = 'N';
				}
			}
		}		
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cout << ans[i][j];
		}
		cout << "\n";
	}
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

	st t = 1;
	cin >> t;
	for (st i = 0; i < t; i++) {
		cout << "Case #" << i+1 << ":\n";
		solve();
	}

//	cerr << "time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}
