#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(),x.end()

//Lowest Sum
//Priority Queue
//https://www.codechef.com/problems/LOWSUM
void solve() {
	int k, q, i, j;
	cin >> k >> q;

	vector<ll> a(k);
	vector<ll> b(k);

	for (i = 0; i < k; i++)
		cin >> a[i];

	for (i = 0; i < k; i++)
		cin >> b[i];

	
	priority_queue<ll> pq;				//maxheap
	for (i = 0; i < k; i++) {
		for (j = 0; j < k; j++) {
			if (pq.size() < 10000)
				pq.push(a[i] + b[j]);

			else {
				if (a[i] + b[j] < pq.top()) {
					pq.pop();
					pq.push(a[i] + b[j]);
				}
			}
		}
	}

	vector<ll> ans;
	while (!pq.empty()) {
		ans.push_back(pq.top());
		pq.pop();
	}

	int n = ans.size(), inp;
	for (i = 0; i < q; i++) {
		cin >> inp;
		cout << ans[n - inp] << "\n";
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

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
	}

	cerr << "time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}