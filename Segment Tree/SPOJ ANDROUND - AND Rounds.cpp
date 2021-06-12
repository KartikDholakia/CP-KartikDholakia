#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()

//SPOJ ANDROUND - AND Rounds
//https://www.spoj.com/problems/ANDROUND/
//Segment Tree
void build(vector<int> &tree, vector<int> &v, int s, int e, int i = 1) {
	if (s == e) {
		tree[i] = v[s];
		return;
	}
	int mid = s + (e - s)/2;
	build(tree, v, s, mid, 2*i);
	build(tree, v, mid + 1, e, 2*i + 1);

	tree[i] = (tree[2*i] & tree[2*i + 1]);
}

int query(vector<int> &tree, int l, int r, int s, int e, int i = 1) {
	//no overlap:
	if (r < s || e < l)
		return 1073741823;			//decimal form of 30 times 1 in binary
		//smallest number greater the 1e9 with all set bits

	//complete overlap
	if (l <= s && e <= r)
		return tree[i];

	int mid = s + (e - s)/2;
	int left = query(tree, l, r, s, mid, 2*i);
	int right = query(tree, l, r, mid + 1, e, 2*i + 1);

	return (left & right);
}

void solve() {
	int n, k, i;
	cin >> n >> k;
	vector<int> v(n+1, 1);
	for (i = 1; i <= n; i++)
		cin >> v[i];

	vector<int> tree(4*n + 1, 1);
	build(tree, v, 1, n);

	int l, r;
	for (i = 1; i <= n; i++) {
		//AND of all elements:
		if (k >= n/2)
			cout << tree[1];

		else {
			if (i > k && i + k <= n)
				cout  << query(tree, i-k, i+k, 1, n);

			else if (i <= k && i + k <= n) {
				l = query(tree, 1, i + k, 1, n);
				r = query(tree, n - k + i, n, 1, n);
				cout << (l & r);
			}
			else {
				l = query(tree, 1, (i+k)%n, 1, n);
				r = query(tree, i-k, n, 1, n);
				cout << (l & r);
			}
		}
		cout << " ";
	}
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

	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		// cout << "Case #" << i << ": ";
		// cout << "Test " << i << ":\n";
		solve();
	}

	cerr << "time: "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}