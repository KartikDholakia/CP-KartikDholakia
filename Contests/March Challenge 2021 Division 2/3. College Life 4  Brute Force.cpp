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

//3. College Life 4 | Brute Force
//March Challenge 2021 Division 2
void solve() {
	ll N, E, H, A, B, C;
	cin >> N >> E >> H >> A >> B >> C;
	ll x, y, z;

	bool flag = 0;
	ll ans = INF;

	ll X, Y, Z;
	for (x = 0; x <= min(E/2, N); x++) {
		for (y = 0; y <= min(N-x, H/3); y++) {
			z = N-x-y;
			if ((2*x + z <= E) && (3*y + z <= H)) {
				flag = 1;
				if (A*x + B*y + C*z < ans) {
					ans = A*x + B*y + C*z;
					X = x;
					Y = y;
					Z = z;
				}
			}
			else if (3*y + z > H){
				break;
			}
		}
	}
	if (flag)
		cout << ans;
	else
		cout << -1;
	cout << "\n";
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
		solve();
	}

	cerr << "time: "<<(double)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}