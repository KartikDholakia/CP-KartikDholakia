#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)

//A. Space Navigation
//Codeforces Round #699 (Div. 2)
void solve() {
	int i, y_min = 0, y_max = 0, x_min = 0, x_max = 0, u, v;
	cin >> u >> v;
	string s;
	cin >> s;

	for (i = 0; i < s.size(); i++) {
		switch(s[i]) {
			case 'L':	x_min--;
						break;
			case 'R':	x_max++;
						break;
			case 'D':	y_min--;
						break;
			case 'U':	y_max++;
						break;			
		}
	}

	if ((x_min <= u && u <= x_max) && (y_min <= v && v <= y_max))
		cout << "YES\n";
	else
		cout << "NO\n";

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

	cerr << "time: "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}