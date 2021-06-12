#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()

//D. Program
//Edu Round 102 Div. 2
//Segment Tree
struct node {
	ll mn, mx, ans, sum;
	node() {
		sum = 0;
		mn = INT_MAX;
		mx = INT_MIN;
		ans = 0;
		sum = 0;
	}
};

void merge(node &p, node l, node r) {
	p.mn = min(l.mn, l.sum + r.mn);
	p.mx = max(l.mx, l.sum + r.mx);
	p.ans = p.mx - p.mn + 1;
	p.sum = l.sum + r.sum;

	if (p.mn <= 0 && 0 <= p.mx)
		return;
	p.ans++;
}

void buildtree(vector<char> &v, vector<node> &tree, ll s, ll e, ll i = 1) {
	if (s == e) {
		if (v[s] == '+') {
			tree[i].mn = 1;
			tree[i].mx = 1;
			tree[i].sum = 1;
		}
		else {
			tree[i].mn = -1;
			tree[i].mx = -1;
			tree[i].sum = -1;
		}
		tree[i].ans = 1;
		return;
	}

	ll mid = s + (e - s)/2;
	buildtree(v, tree, s, mid, 2*i);
	buildtree(v, tree, mid+1, e, 2*i + 1);

	merge(tree[i], tree[2*i], tree[2*i + 1]);
}

node query(vector<node> &tree, ll qs, ll qe, ll s, ll e, ll i = 1) {
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
	ll n, m, i;
	cin >> n >> m;
	vector<char> v(n+1);
	v[0] = ' ';

	for (i = 1; i <= n; i++)
		cin >> v[i];

	vector<node> tree(4*n);
	buildtree(v, tree, 1, n, 1);
	ll l, r;

	// //debug:
	// cout << tree[1].ans << "\n";
	// cout << tree[1].mn << "\n";
	// cout << tree[1].mx << "\n";
	// return;

	for (i = 0; i < m; i++) {
		node p_node, l_node, r_node;
		cin >> l >> r;
		if (l == 1 && r == n) {
			cout << "1\n";
			continue;
		}
		if (l != 1)
			l_node = query(tree, 1, l-1, 1, n);
		if (r != n)
			r_node = query(tree, r+1, n, 1, n);
		merge(p_node, l_node, r_node);

		// cout << p_node.mn << " " << p_node.mx << " ";
		cout << p_node.ans << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

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