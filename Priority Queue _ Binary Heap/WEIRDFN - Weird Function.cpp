#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(),x.end()

//WEIRDFN - Weird Function
//https://www.spoj.com/problems/WEIRDFN/
void solve() {
	ll n, a, b, c;
	cin >> a >> b >> c >> n;

	priority_queue<ll> maxheap;
	priority_queue<ll, vector<ll>, greater<ll>> minheap;
	maxheap.push(1);

	ll med = 1, sz = 1, sum = 1, next;

	for (ll i = 2; i <= n; i++) {
		med = maxheap.top() % mod;
		next = ((a * med)%mod + (b * i)%mod + c) % mod;
		minheap.push(next);
		sum += next;
		
		if (sz % 2 == 0) {
			maxheap.push(minheap.top());
			minheap.pop();
		}
		else {
			if (maxheap.top() > minheap.top()) {
				maxheap.push(minheap.top());
				minheap.pop();
				minheap.push(maxheap.top());
				maxheap.pop();
			}
		}
		sz++;
		//cout << next << "\n";
	}

	//cout << "\n";
	cout << sum << "\n";
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