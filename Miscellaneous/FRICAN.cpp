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

//https://www.codechef.com/problems/FRICAN
void buildTree(vector<int> &tree, vector<int> &v, int i, int l, int r) {
	if (l == r) {
		tree[i] = v[l];
		return;
	}

	int mid = l + (r - l)/2;
	buildTree(tree, v, 2*i, l, mid);
	buildTree(tree, v, 2*i + 1, mid+1, r);

	tree[i] = max(tree[2*i], tree[2*i + 1]);
}

pair<int, int> findMax(vector<int> &tree, ll qs, ll qe, ll s, ll e, ll i) {
	//qe, qs - query range
	//s, e - range of particular node
	//no overlap:
	if (qe < s || e < qs) {
		return mp(INT_MIN, -1);
	}
	//complete overlap:
	if(qs <= s && e <= qe)
		return mp(tree[i], i);

	//partial overlap:
	int mid = s + (e - s)/2;
	pair<int, int> left = findMax(tree, qs, qe, s, mid, 2*i);
	pair<int, int> right = findMax(tree, qs, qe, mid+1, e, 2*i + 1);

	if (left.first >= right.first)
		return left;
	else
		return right;
}

bool query(vector<int> &tree, int l, int r, int n) {
	pair<int, int> left = findMax(tree, 1, l, 1, n, 1);
	pair<int, int> left = findMax(tree, n-r+1, n, 1, n, 1);
	
}

bool cmp(pair<int, int> a, pair<int, int> b) {
	return ((a.first + a.second) <= (b.first + b.second));
}

void solve() {
	int n, m, i;
	cin >> n >> m;
	vector<int> v(n+1);
	v[0] = -1;

	ll sum = 0;
	for (i = 1; i <= n; i++) {
		cin >> v[i];
		sum += v[i];
	}

	vector<pair<int, int>> q;
	int l, r;
	for (i = 0; i < m; i++) {
		cin >> l >> r;
		q.pb(mp(l, r));
	}
	sort(all(q), cmp);

	vector<int> segTree(4*n, INT_MIN);
	buildTree(segTree, v, 1, 1, n);


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	//remove this piece of code when this has to be submitted in kickstart
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
	//freopen is used to associate a file with stdin or stdout stream in C++
	#endif

	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
	}

	cerr << "time: "<<(double)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}