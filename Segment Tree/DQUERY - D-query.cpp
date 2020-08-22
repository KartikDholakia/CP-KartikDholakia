#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;
#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807

//DQUERY - D-query
//https://www.spoj.com/problems/DQUERY/
int n;

struct query {
	int l, r, pos;
};

bool cmp(query a, query b) {
	if ((double)(a.l/sqrt(n)) == (double)(b.l/sqrt(n)))
		return (a.r <= b.r);
	else
		return ((double)(a.l/sqrt(n)) < (double)(b.l/sqrt(n)));
}

void solve() {
	int i, j, k;
	cin >> n;
	vector<int> v(n);
	for (i = 0; i < n; i++)
		cin >> v[i];
	
	int q, l, r;
	cin >> q;
	vector<query> que(q);
	vector<int> ans(q);
	for (i = 0; i < q; i++) {
		cin >> que[i].l >> que[i].r;
		que[i].pos = i;
	}
	sort(que.begin(), que.end(), cmp);

	map<int, int> cnt;
	int ansi = 0;
	for (i = que[0].l; i <= que[0].r; i++) {
		cnt[v[i-1]]++;
		if (cnt[v[i-1]] == 1)
			ansi++;
	}
	ans[que[0].pos] = ansi;
	i = que[0].l, j = que[0].r;
	
	for (k = 1; k < q; k++) {
		while (i < que[k].l) {
			cnt[v[i-1]]--;
			if (cnt[v[i-1]] == 0)
				ansi--;
			i++;
		}
		if (j > que[k].r){
			while (j > que[k].r) {
				cnt[v[j-1]]--;
				if (cnt[v[j-1]] == 0)
					ansi--;
				j--;	
			}
		}
		else {
			while (j < que[k].r) {
				cnt[v[j]]++;
				if (cnt[v[j]] == 1)
					ansi++;
				j++;
			}
		}
		ans[que[k].pos] = ansi;
	}

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
	//cin >> t;
	for (st i = 0; i < t; i++) {
		solve();
	}

	cerr << "time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}
