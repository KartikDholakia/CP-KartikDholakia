#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;
#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807

//SPOJ D-QUERY
//fenwick tree || offline query
void update(vector<int> &tree, int idx, int val) {
	while (idx < tree.size()) {
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

int sum(vector<int> tree, int idx) {
	int ans = 0;
	while (idx > 0) {
		ans += tree[idx];
		idx -= (idx & - idx);
	}
	return ans;
}

void solve() {
	int n, i, q, j = 0;
	scanf("%d", &n);

	vector<int> a(n+1, 0);
	
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	
	scanf("%d", &q);
//	cout << q << "\n";

	vector<int> ans(q, 0);
	pair<int, pair<int, int>> pr[q];
	vector<int> tree(n+1, 0);
	int l = *max_element(a.begin(), a.end()) + 1;
	vector<int> p(l, -1);

	for (i = 0; i < q; i++) {
		scanf("%d %d", &pr[i].second.first, &pr[i].first);
		pr[i].second.second = i;
	}

	sort(pr, pr + q);

	for (i = 1; i <= n; i++) {
		if (p[a[i]] != -1) {
			update(tree, p[a[i]], -1);
		}
		p[a[i]] = i;
		update(tree, i, 1);
		while ((j < q) && (pr[j].first == i)) {
			ans[pr[j].second.second] = sum(tree, pr[j].first) - sum(tree, pr[j].second.first - 1);
			j++;
		}
	}

	for (i = 0; i < q; i++) {
		printf("%d\n", ans[i]);
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
//	cin >> t;
	for (st i = 0; i < t; i++) {
		solve();
	}

	cerr << "time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}