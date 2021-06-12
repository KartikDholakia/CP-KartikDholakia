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

//https://codeforces.com/problemset/problem/1498/B
//Best-fit algo for Bin Packing using Min-Heap
void solve() {
	ll n, w, i, j;
	cin >> n >> w;

	vector<ll> v(n);
	for (i = 0; i < n; i++)
		cin >> v[i];
	sort(all(v), greater<ll>());

	priority_queue<ll, vector<ll>, greater<ll>> pq;	//min heap
	ll temp, h = 0;
	for (i = 0; i < n; i++) {
		if (!pq.empty() && (pq.top() + v[i] <= w)) {
			temp = pq.top() + v[i];
			pq.pop();
			if (temp == w)
				h++;
			else
				pq.push(temp);
		}
		else
			pq.push(v[i]);
	}

	cout << h + pq.size() << "\n";

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
		// cout << "Case #" << i << ": ";
		solve();
	}

	cerr << "time: "<<(double)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}