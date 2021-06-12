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

//2. Moons and Umbrellas
//Code Jam 2021
void solve() {
	int x, y, i;
	string str, temp;
	cin >> x >> y;
	cin >> str;

	for (i = 0; i < str.size(); i++) {
		if (str[i] != '?')
			temp.pb(str[i]);
	}

	if (temp.size() < 2) {
		cout << "0\n";
		return;
	}

	int cost = 0;
	for (i = 0; i < temp.size()-1; i++) {
		if (temp.substr(i, 2) == "CJ")
			cost += x;
		else if (temp.substr(i, 2) == "JC")
			cost += y;
	}

	cout << cost << "\n";
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