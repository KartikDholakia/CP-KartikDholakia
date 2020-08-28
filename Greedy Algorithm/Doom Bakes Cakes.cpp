#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(),x.end()

//https://www.codechef.com/problems/CAKEDOOM
//Doom Bakes Cakes
//Greedy
void solve() {
	int k;
	string s;
	cin >> k;
	cin >> s;
	int n = s.size(), i;
	int j;

	if (n == 1) {
		if (s[0] == '?')
			cout << "0\n";
		else
			cout << s << "\n";
		return;
	}

	for (i = 0; i < n-1; i++) {
		if ((s[i] == s[i+1]) && (s[i] != '?')) {
			cout << "NO\n";
			return;
		}
	}
	if ((s[0] == s[n-1]) && (s[0] != '?')) {
		cout << "NO\n";
		return;
	}

	bool flag = 1;
	for (i = 0; i < n; i++) {
		if (s[i] == '?') {
			for (j = '0'; j < k + '0'; j++) {
				if (i == 0) {
					if ((j != s[(i+1)%n]) && (j != s[n-1])) {
						s[i] = (char)j;
						break;
					}
				}
				else {
					if ((j != s[(i+1)%n]) && (j != s[i-1])) {
						s[i] = (char)j;
						break;
					}
				}
			}
			if (s[i] == '?') {
				flag = 0;
				break;
			}
		}
	}
//	cout << k << "\t";
	if (flag)
		cout << s << "\n";
	else
		cout << "NO\n";
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
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}

	cerr << "time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}