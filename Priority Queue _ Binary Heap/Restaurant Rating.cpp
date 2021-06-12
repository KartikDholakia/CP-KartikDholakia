#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(),x.end()

//Restaurant Rating
//https://www.codechef.com/problems/RRATING
void solve() {
	int n, sz = 0;
	cin >> n;

	priority_queue<int> maxheap;				//descending order
	priority_queue<int, vector<int>, greater<int>> minheap;	//ascending order
	int a, x, temp, temp2;

	while (n--) {
		cin >> a;
		if (a == 1) {
			cin >> x;
			maxheap.push(x);
			sz++;
			if (sz % 3 == 0) {
				temp = maxheap.top();
				maxheap.pop();
				minheap.push(temp);
			}
			else if (!minheap.empty() && minheap.top() < maxheap.top()) {
				temp = maxheap.top();
				maxheap.pop();
				temp2 = minheap.top();
				minheap.pop();
				minheap.push(temp);
				maxheap.push(temp2);
			}
		}
		else {
			if (!minheap.empty())
				cout << minheap.top() << "\n";
			else
				cout << "No reviews yet\n";
		}
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

	int t = 1;
	//cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
	}

	cerr << "time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}