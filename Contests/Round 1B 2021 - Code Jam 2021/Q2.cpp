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

//Q2
//Round 1B 2021 - Code Jam 2021
bool check(vector<ll> &v, vector<ll> &temp) {
	for (ll i = 1; i < v.size(); i++) {
		if (v[i] > temp[i])
			return 0;
	}
	return 1;
}

void recurSolve(ll x, ll a, ll b, vector<ll> &v, vector<ll> &temp) {
	if ((x < v.size()) && (v[x] > temp[x])) {
		temp[x]++;
		return;
	}

	if (x > b)
		recurSolve(x-b, a, b, v, temp);
	if (x > a)
		recurSolve(x-a, a, b, v, temp);
}

void solve() {
	ll n, a, b, i;
	cin >> n >> a >> b;

	vector<ll> v(n+1, 0);
	for (i = 1; i <= n; i++)
		cin >> v[i];

	vector<ll> temp(n+1, 0);
	recurSolve(n+a, a, b, v, temp);

	// for (i = 1; i <= n; i++)
	// 	cout << temp[i] << " ";
	// cout << "\n";

	if (check(v, temp)) {
		cout << n+a << "\n";
		return;
	}

	for (i = 0; i <= n; i++)
		temp[i] = 0;
	
	recurSolve(n+b, a, b, v, temp);

	// for (i = 1; i <= n; i++)
	// 	cout << temp[i] << " ";
	// cout << "\n";

	if (check(v, temp))
		cout << n+b << "\n";
	else
		cout << "IMPOSSIBLE\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}