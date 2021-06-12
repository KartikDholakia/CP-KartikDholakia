#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define MOD 1000000007
#define MAX 1000001					//1e6 + 1
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define mp make_pair

//1. Reversort
//Code Jam 2021
void solve() {
	int n, i, cost = 0;
	cin >> n;
	vector<int> v(n);

	for (i = 0; i < n; i++)
		cin >> v[i];
	
	int mn = INT_MAX, j, k;
	for (i = 0; i < n-1; i++) {
		// for (k = 0; k < n; k++)
		// 	cout << v[k];
		// cout << "\t" << cost;
		mn = INT_MAX;
		for (k = i; k < n; k++) {
			if (v[k] < mn) {
				mn = v[k];
				j = k;
			}
		}
		// cout << "\t" << j << "\n";
		cost += j-i+1;
		reverse(v.begin()+i, v.begin()+j+1);
	}

	cout << cost << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}