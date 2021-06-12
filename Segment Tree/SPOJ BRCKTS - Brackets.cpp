#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()

//SPOJ BRCKTS - Brackets
//https://www.spoj.com/problems/BRCKTS/#
//Segment Tree
class Node {
	public:
	ll open, close;				//unmatched open and closed paranthesis count
	void merge(Node l, Node r);
	// friend void buildtree(vector<ll> &v, vector<Node> &tree, ll s, ll e, ll i = 1);
	// friend void update(vector<Node> &tree, ll k, ll s, ll e, ll i = 1);
	bool check();
};

void Node::merge(Node l, Node r) {
	ll match = min(l.open, r.close);
	open = l.open + r.open - match;
	close = l.close + r.close - match;
}

bool Node::check() {
	return (open == 0 && close == 0);
}

void buildtree(vector<char> &v, vector<Node> &tree, ll s, ll e, ll i = 1) {
	if (s == e) {
		if (v[s] == '(')
			tree[i].open = 1;
		else
			tree[i].close = 1;
		return;
	}

	ll mid = s + (e - s)/2;
	buildtree(v, tree, s, mid, 2*i);
	buildtree(v, tree, mid+1, e, 2*i + 1);

	tree[i].merge(tree[2*i], tree[2*i + 1]);
}

void update(vector<Node> &tree, ll k, ll s, ll e, ll i = 1) {
	if (s == e && e == k) {
		swap(tree[i].open, tree[i].close);
		return;
	}

	ll mid = s + (e - s)/2;
	if (k <= mid)
		update(tree, k, s, mid, 2*i);
	else
		update(tree, k, mid + 1, e, 2*i + 1);

	tree[i].merge(tree[2*i], tree[2*i + 1]);
}

void print(vector<Node> &tree) {
	cout << "i\topen\tclose\n";
	for (ll i = 1; i < tree.size(); i++) {
		cout << i << "\t" << tree[i].open << "\t" << tree[i].close;
		cout << "\n";
	}
	cout << "\n";
}

void solve() {
	ll n, m, k, i;
	cin >> n;
	vector<char> v(n+1);
	for (i = 1; i <= n; i++)
		cin >> v[i];

	vector<Node> tree(4*n);
	buildtree(v, tree, 1, n);

	// print(tree);
	cin >> m;
	while (m--) {
		cin >> k;
		if (k)
			update(tree, k, 1, n);
		else {
			if (tree[1].check())
				cout << "YES\n";
			else
				cout << "NO\n";
		}
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

	int t = 10;
//	cin >> t;
	for (int i = 1; i <= t; i++) {
		// cout << "Case #" << i << ": ";
		cout << "Test " << i << ":\n";
		solve();
	}

	cerr << "time: "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}