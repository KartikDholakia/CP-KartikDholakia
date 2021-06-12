#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(),x.end()

//IPC Trainers
//Priority Queue
//https://www.codechef.com/JULY17/problems/IPCTRAIN
struct ipc {
	int d, l, s;
	ipc(): d(0), l(0), s(0) {}
};

bool cmp(ipc a, ipc b) {
	return (a.d <= b.d);
}

void solve() {
	int N, D, i;
	cin >> N >> D;

	vector<ipc> arr(N);
	for (i = 0; i < N; i++) {
		cin >> arr[i].d >> arr[i].l >> arr[i].s;
	}
	sort(all(arr), cmp);

	int j = 0, temp1, temp2;
	priority_queue< pair <int, int> > pq;

	for (i = 1; i <= D; i++) {
		while (arr[j].d == i) {
			pq.push(make_pair(arr[j].s, arr[j].l));
			j++;
		}
		if (!pq.empty()) {
			temp1 = pq.top().first;
			temp2 = pq.top().second - 1;
			pq.pop();
			if (temp2 != 0)
				pq.push(make_pair(temp1, temp2));
		}
	}

	ll ans = 0;
	while (!pq.empty()) {
		ans += (ll)(pq.top().first) * (ll)(pq.top().second);
		pq.pop();
	}

	cout << ans << "\n";
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