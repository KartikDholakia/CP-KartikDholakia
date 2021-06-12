#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(),x.end()

//Sebi and the corrupt goverment
//https://www.codechef.com/problems/SETELE
//Min-Spanning Tree _ Kruskal _ Union-Find
struct edge {
	int a, b, c;
};

bool cmp(edge x, edge y) {
	return x.c <= y.c;
}

int find(int x, vector<int> &par) {
	if (x == par[x])
		return x;
	return par[x] = find(par[x], par);
}

void solve() {
	int n, i, u, v, ci;
	cin >> n;

	vector<edge> arr;
	for (i = 0; i < n-1; i++) {
		cin >> u >> v >> ci;
		arr.push_back(edge());
		arr[i].a = u;
		arr[i].b = v;
		arr[i].c = ci;
	}

	sort(all(arr), cmp);
	
	double cost = 0, s  = 0;
	double t = ((double)n*((double)n-1))/2;
	vector<ll> sz(n+1, 1);
	sz[0] = 0;

	vector<int> par(n+1);
	for (i = 1; i <= n; i++)
		par[i] = i;

	for (i = 0; i < n-1; i++) {
		// cout << arr[i].a << " " << arr[i].b << " " << arr[i].c << "\n";
		
		u = find(arr[i].a, par);
		v = find(arr[i].b, par);
		
		cost += arr[i].c;
		s += sz[u] * sz[v] * (ll)arr[i].c;

		//unite:
		if (sz[u] < sz[v]) {
			par[u] = v;
			sz[v] += sz[u];
		}
		else {
			par[v] = u;
			sz[u] += sz[v];
		}
	}

	double ans = cost - s/t;
	printf("%.11f\n", ans);
	// cout << fixed << setprecision(6) << ans;
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