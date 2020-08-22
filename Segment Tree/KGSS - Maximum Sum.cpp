#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;
#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807

//KGSS - Maximum Sum SPOJ
//https://www.spoj.com/problems/KGSS/
//Segment Tree
ll max (ll x, ll y) {
	return (x > y)? x:y;
}

struct node{
	ll ans,
	m;			//stores max element in the range
	node() {
		ans = 0, m = 0;
	}
};

void merge (node &temp, node l, node r) {
	temp.ans = max(max(l.ans, r.ans), (l.m + r.m));
	temp.m = max(l.m, r.m);
}

node query(vector<node> &tree, ll ql, ll qr, ll l, ll r, ll i = 1) {
	//ql, qr - query range
	//l, r - range of particular node
	//no overlap:
	if (qr < l || r < ql) {
		node nullNode;
		return nullNode;
	}
	//complete overlap:
	if(l >= ql && r <= qr)
		return tree[i];

	//partial overlap:
	ll mid = l + (r - l)/2;
	node left = query(tree, ql, qr, l, mid, 2*i);
	node right = query(tree, ql, qr, mid+1, r, 2*i + 1);

	node temp; 
	merge(temp, left, right);
	return temp;
}

void update(ll pos, ll x, vector<node> &tree, ll l, ll r, ll i = 1) {
	if ((l == r) && (l == pos)) {
		tree[i].ans = x;
		tree[i].m = x;
		return;
	}

	ll mid = l + (r-l)/2;
	if (pos <= mid)
		update(pos, x, tree, l, mid, 2*i);
	else
		update(pos, x, tree, mid + 1, r, 2*i + 1);

	//merge:
	merge(tree[i], tree[2*i], tree[2*i + 1]);
}

void print(vector<node> &tree) {
	for (ll i = 1; i < tree.size(); i++) {
		cout << i << " " << tree[i].m << " " << tree[i].ans << "\n";
	}
}

void solve() {
	ll n, i, q;
	cin >> n;
	vector<ll> v(n+1);
	vector<node> tree(4*n);

	for (i = 1; i <= n; i++) {
		cin >> v[i];
		update(i, v[i], tree, 1, n, 1);
	}

	cin >> q;
	char Q;
	ll x, y;
	node temp;
	for (i = 0; i < q; i++) {
		cin >> Q >> x >> y;
		if (Q == 'Q') {
			temp = query(tree, x, y, 1, n);
			cout << temp.ans << "\n";
		}
		else
			update(x, y, tree, 1, n);
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
	//cin >> t;
	for (st i = 0; i < t; i++) {
		solve();
	}

	cerr << "time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}
