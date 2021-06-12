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
void add_x(ll &N, ll &E, ll &A, ll &x, ll &cost) {
	ll cnt = min(N, E/2);
	N = N-cnt;
	E = E - cnt*2;
	x += cnt;
	cost += A*cnt;
	if (E < 2)
		A = INF;
}

void add_y(ll &N, ll &H, ll &B, ll &y, ll &cost) {
	ll cnt = min(N, H/3);
	N -= cnt;
	H -= cnt*3;
	y += cnt;
	cost += cnt*B;
	if (H < 3)
		B = INF;
}

void add_z(ll &N, ll &E, ll &H, ll &C, ll &z, ll &cost) {
	ll cnt = min(N, min(E, H));
	N -= cnt;
	E -= cnt;
	H -= cnt;
	z += cnt;
	cost += cnt*C;
	if (min(E, H) < 1)
		C = INF;
}

ll cost(ll N, ll E, ll H, ll A, ll B, ll C) {
	ll x = 0, y = 0, z = 0;
	ll min_val, ans = 0;
	
	if (E < 2)
		A = INF;
	if (H < 3)
		B = INF;
	if (min(E, H) < 1)
		C = INF;

	while (N) {
		min_val = min(A, min(B, C));
		if (A == min_val && A == B && A == C) {
			add_z(N, E, H, C, z, ans);
		}
		else if (A == min_val && A == B) {
			add_x(N, E, A, x, ans);
		}
		else if (B == min_val && B == C) {
			add_z(N, E, H, C, z, ans);
		}
		else if (C == min_val && A == C) {
			add_z(N, E, H, C, z, ans);
		}
		else if (A == min_val) {
			add_x(N, E, A, x, ans);
		}
		else if (B == min_val) {
			add_y(N, H, B, y, ans);
		}
		else {
			add_z(N, E, H, C, z, ans);
		}
	}
	cout << x << " " << y << " " << z << "\n";
	return ans;
}

void solve() {
	ll N, E, H, A, B, C;
	cin >> N >> E >> H >> A >> B >> C;

	if (2*N > E + H)
		cout << "-1\n";
	else
		cout << cost(N, E, H, A, B, C) << "\n";
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