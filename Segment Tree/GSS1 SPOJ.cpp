#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()

//GSS1 SPOJ
//https://www.spoj.com/problems/GSS1/
//Segment Tree
struct node {
	ll lsum,	//prefix sum
	rsum,		//suffix sum
	total,		//total sum
	ans;		//max sum of subarray

	node() {
		lsum = -1e14;
		rsum = -1e14;
		total = -1e14;
		ans = -1e14;
	}
};

void merge(node &p, node l, node r) {
	p.lsum = max(l.lsum, l.total + r.lsum);
	p.rsum = max(r.rsum, r.total + l.rsum);
	p.total = l.total + r.total;
	p.ans = max(max(l.ans, r.ans), l.rsum + r.lsum);
	p.ans = max(p.ans, max(p.lsum, p.rsum));
}

void buildtree(vector<ll> &v, vector<node> &tree, ll s, ll e, ll i) {
	if (s == e) {
		tree[i].lsum = v[s];
		tree[i].rsum = v[s];
		tree[i].total = v[s];
		tree[i].ans = v[s];
		return;
	}

	ll mid = s + (e - s)/2;
	buildtree(v, tree, s, mid, 2*i);
	buildtree(v, tree, mid+1, e, 2*i + 1);

	merge(tree[i], tree[2*i], tree[2*i + 1]);
}

void print(vector<node> &tree) {
	cout << "i\tlsum\trsum\ttotal\tans\n";
	for (ll i = 1; i < tree.size(); i++) {
		cout << i << "\t";
		cout << tree[i].lsum << "\t" << tree[i].rsum << "\t";
		cout << tree[i].total << "\t" << tree[i].ans << "\n";
	}
	cout << "\n";
}

node query(vector<node> &tree, ll qs, ll qe, ll s, ll e, ll i) {
	//qe, qs - query range
	//s, e - range of particular node
	//no overlap:
	if (qe < s || e < qs) {
		node nullNode;
		return nullNode;
	}
	//complete overlap:
	if(qs <= s && e <= qe)
		return tree[i];

	//partial overlap:
	ll mid = s + (e - s)/2;
	node left = query(tree, qs, qe, s, mid, 2*i);
	node right = query(tree, qs, qe, mid+1, e, 2*i + 1);

	node temp; 
	merge(temp, left, right);
	return temp;
}

void solve() {
	ll n, l, r, q, i;
	cin >> n;
	vector<ll> v(n+1);
	for (i = 1; i <= n; i++)
		cin >> v[i];

	vector<node> tree(4*n + 1);
	buildtree(v, tree, 1, n, 1);

	// print(tree);
	cin >> q;
	node temp;
	for (i = 0; i < q; i++) {
		cin >> l >> r;
		temp = query(tree, l, r, 1, n, 1);
		cout << temp.ans << "\n";
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

	int t = 1;
//	cin >> t;
	for (int i = 1; i <= t; i++) {
		// cout << "Case #" << i << ": ";
		solve();
	}

	cerr << "time: "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}