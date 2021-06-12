#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

#define MOD 1000000007				//1e9 + 7
#define MAX 200001					//2e5 + 1
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define mp make_pair
#define vll vector<ll>
#define loop_diff(var, start, end, diff) for (ll var = start; var < end; var += diff)
#define loop(var, start, end) for (ll var = start; var < end; var++)

//https://codeforces.com/contest/1519/problem/D
void solve() {
	ll n, i, sum = 0, j;
	cin >> n;
	
	vll a(n), b(n);
	loop(i, 0, n)
		cin >> a[i];
	loop(i, 0, n)
		cin >> b[i];
	
	ll l = -1, r = -1, len = -INF;
	ll sum1 = 0, sum2 = 0, k;
	loop (i, 0, n-1) {
		j = i+1;
		while (j < n && a[j] <= a[j-1] && b[j] >= b[j-1])
			j++;
		if (j != i+1) {
			if (len < j-i) {
				r = j;
				l = i;
				len = j-i;
			}
			else if (len == j-i) {
				cout << "Here: ";
				loop(k, 0, j-i)
					sum1 += a[k+i] * b[j-k-1];

				loop(k, 0, r-l)
					sum2 += a[k+l] * b[r-k-1];
				
				cout << sum1 << " " << sum2 << "\n";
				if (sum1 > sum2) {
					len = j-1;
					l = i;
					r = j;
				}
			}
		}
		// cout << i << " " << l << " " << r << "\n";
	}

	reverse(a.begin()+l, a.begin()+r);
	// loop(i, 0, n)
	// 	cout << a[i] << " ";
	// cout << "\n";

	loop(i, 0, n) {
		sum += a[i] * b[i];
	}
	cout << sum << "\n";
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
