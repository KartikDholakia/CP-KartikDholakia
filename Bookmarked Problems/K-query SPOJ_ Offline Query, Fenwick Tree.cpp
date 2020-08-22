#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;
#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807

//KQUERY - K-query SPOJ
//https://www.spoj.com/problems/KQUERY/
//Offline Query, Fenwick Tree

struct que{
	int pos, l, r, val;
};

bool cmp(que a, que b) {
	if (a.val > b.val)
		return 1;
	else if (a.val == b.val)
		return a.l > b.l;
	else
		return 0;
}

void update(int k, vector<int> &bit) {
	while (k < bit.size()) {
		bit[k]++;
		k += k & -k;
	}
}

int query(int k, vector<int> &bit) {
	int sum = 0;
	while (k >= 1) {
		sum += bit[k];
		k -= k & -k;
	}
	return sum;
}

void print(vector<que> &arr) {
	cout << "i\tpos\tl\tr\tval\n";
	for (int i = 1; i < arr.size(); i++) {
		cout << i << "\t";
		cout << arr[i].pos << "\t" << arr[i].l << "\t";
		cout << arr[i].r << "\t" << arr[i].val << "\n";
	}
}

void solve() {
	int n, l, r, k, i, q;
	cin >> n;
	vector<que> arr;
	arr.push_back(que());

	for (i = 1; i <= n; i++) {
		arr.push_back(que());
		cin >> arr[i].val;
		arr[i].r = i;
		arr[i].l = 0;
		arr[i].pos = 0;
	}
	
	cin >> q;
	for (; i <= n+q; i++) {
		arr.push_back(que());
		cin >> arr[i].l;
		cin >> arr[i].r;
		cin >> arr[i].val;
		arr[i].pos =  i-n;
	}

	sort(arr.begin()+1, arr.end(), cmp);
//	print(arr);
//	cout << "\n";

	vector<int> bit(n+1, 0);
	vector<int> ans(q);

	for (i = 1; i <= n+q; i++) {
		if (arr[i].pos == 0) 
			update(arr[i].r, bit);
		else {
			ans[arr[i].pos-1] = query(arr[i].r, bit) - query(arr[i].l - 1, bit);
		}
	}

//	for (i = 1; i < n+1; i++)
//		cout << bit[i] << " ";
//	cout << "\n";

	for (i = 0; i < q; i++)
		cout << ans[i] << "\n";

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
