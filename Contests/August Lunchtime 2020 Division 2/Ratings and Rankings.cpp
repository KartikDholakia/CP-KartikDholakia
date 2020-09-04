#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(),x.end()

//Ratings and Rankings
//August Lunchtime 2020 Division 2
struct node {
	int data, rightsize;
	node *left, *right;
};

node *insert(node *troot, int x) {
	if (troot == NULL) {
		troot = (node*)malloc(sizeof(node));
		troot->data = x;
		troot->rightsize = 0;
		troot->left = NULL;
		troot->right = NULL;
	}
	else if (x <= troot->data)
		troot->left = insert(troot->left, x);
	else {
		troot->rightsize++;
		troot->right = insert(troot->right, x);
	}
	return troot;
}

int getrank(node *troot, int x) {
	if (troot == NULL)
		return -1;

	if (x == troot->data)
		return troot->rightsize + 1;

	if (x < troot->data)
		return troot->rightsize + 1 + getrank(troot->left, x);
	else
		return getrank(troot->right, x);
}

void solve() {
	int n, m, i, j;
	cin >> n >> m;
	int c;
	int rat[n][m];
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			rat[i][j] = 0;

	for (i = 0; i < n; i++) {
		cin >> rat[i][0];
	}

	//insertion:
	node *root[m];
	for (j = 0; j < m; j++)
		root[j] = NULL;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> c;
			if (j == 0)
				rat[i][j] += c;
			else
				rat[i][j] = rat[i][j-1] + c;

			root[j] = insert(root[j], rat[i][j]);
		}
	}

	//debug:
	// for (j = 0; j < m; j++) {
	// 	if (root[j] == NULL)
	// 		cout << "NULL\n";
	// 	else
	// 		cout << root[j]->data << " " << root[j]->rightsize << "\n";
	// }
	// return;

	//creatinon of rank matrix:
	int rank[n][m];
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			rank[i][j] = getrank(root[j], rat[i][j]);
		}
	}

	//debug:
	// for (i = 0; i < n; i++) {
	// 	for (j = 0; j < m; j++) {
	// 		cout << rat[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	// cout << "\n";

	// for (i = 0; i < n; i++) {
	// 	for (j = 0; j < m; j++) {
	// 		cout << rank[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }

	int ans = 0, max_rat = 0, min_rank = 500;
	int m1, m2;
	for (i = 0; i < n; i++) {
		max_rat = rat[i][0];
		m1 = 1;
		for (j = 0; j < m; j++) {
			if (rat[i][j] > max_rat) {
				max_rat = rat[i][j];
				m1 = j+1;
			}
		}
		min_rank = 500;
		for (j = 0; j < m; j++) {
			if (rank[i][j] < min_rank) {
				min_rank = rank[i][j];
				m2 = j+1;
			}
		}

		if (m1 != m2)
			ans++;
	}

	cout  << ans << "\n";
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
	for (int i = 0; i < t; i++) {
		solve();
	}

	cerr << "time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}