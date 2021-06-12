#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(),x.end()

//RMID2 - Running Median Again
//https://www.spoj.com/problems/RMID2/
//Priority Queue
void solve() {
	ll n, sz = 0;
	priority_queue<ll> maxheap;
	priority_queue<ll, vector<ll>, greater<ll>> minheap;
	while (1) {
		cin >> n;
		if (n > 0) {
			minheap.push(n);
			sz++;
			if (sz % 2) {
				maxheap.push(minheap.top());
				minheap.pop();
			}
			else if (maxheap.top() > minheap.top()) {
				maxheap.push(minheap.top());
				minheap.pop();
				minheap.push(maxheap.top());
				maxheap.pop();
			}
		}
		else if (n == -1) {
			cout << maxheap.top() << "\n";
			maxheap.pop();
			sz--;
			if (sz % 2) {
				maxheap.push(minheap.top());
				minheap.pop();
			}
		}
		else if (n == 0)
			break;
	}
	cout << "\n";
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

	ll t;
	cin >> t;
	for (ll i = 1; i <= t; i++) {
		solve();
	}

	cerr << "time: "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}