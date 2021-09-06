#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long llu;

#define MOD 1000000007				//1e9 + 7
#define MAX 200001					//2e5 + 1
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define mp make_pair
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pair<ll, ll>>
#define mem(x, y) memset(x, y, sizeof(x))
#define loop_diff(var, start, end, diff) for (ll var = start; var < end; var += diff)
#define loop(var, start, end) for (auto var = start; var < end; var++)
#define loop_rev(var, start, end) for(auto var = start; var > end; var--)
#define ordered_set tree<pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update>

//INCOMPLETE
//DP | Knapsack 
//https://www.spoj.com/problems/MINUS/
bool getSeq(vector<char> &seq, vll &v, ll idx, ll m) {
	if (idx <= 1)
		return ((v[0] - v[1]) == m);
	
	seq[idx] = '-';
	bool temp = getSeq(seq, v, idx-1, v[idx] + m);
	if (temp)
		return temp;
	else {
		seq[idx] = '+';
		temp = getSeq(seq, v, idx-1, m - v[idx]);
		return temp;
	}
}

void solve() {
	ll n, m, i;
	cin >> n >> m;

	vll v(n);
	loop(i, 0, n)
		cin >> v[i];
	
	vector<char> seq(n, 'x');
	seq[0] = '+';
	seq[1] = '-';

	bool temp = getSeq(seq, v, n-1, m);
	loop(i, 0, n)
		cout << seq[i] << " ";
	
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
		// cout << "Case " << i << ": ";
		solve();
	}

	cerr << "time: "<<(double)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}
