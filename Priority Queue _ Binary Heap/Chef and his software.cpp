#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(),x.end()

//Chef and his software
//Priority Queue
//https://www.codechef.com/problems/TSECJ05
void solve() {
	int n, k, inp;
	cin >> k >> n;

	priority_queue <int, vector<int>, greater<int>> minheap;

	while (n--) {
		cin >> inp;
		if (minheap.size() < k) {
			minheap.push(inp);
		}

		else if (inp > minheap.top()) {
			minheap.push(inp);
			minheap.pop();
		}

		if (minheap.size() < k)
			cout << "-1 ";
		else
			cout << minheap.top() << " ";
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

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
	}

	cerr << "time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}