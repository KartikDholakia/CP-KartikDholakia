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

//A. ABC String
//Educational Codeforces Round 105 (Rated for Div. 2)
void solve() {
	string str;
	cin >> str;
	int n = str.size(), i;
	if (str[0] == str[n-1]) {
		cout << "NO\n";
		return;
	}

	int cnt[3] = {0};
	char sign[3] = {'x', 'x', 'x'};
	sign[str[0] - 'A'] = '(';

	for (i = 0; i < n; i++)
		cnt[str[i] - 'A']++;

	bool flag = 0;
	if (cnt[0] == cnt[1] + cnt[2])
		flag = 1;
	else if (cnt[1] == cnt[2] + cnt[0])
		flag = 1;
	else if (cnt[2] == cnt[0] + cnt[1])
		flag = 1;
	else {
		cout << "NO\n";
		return;
	}

	stack<char> st;
	st.push('(');
	for (i = 1; i < n; i++) {
		if (sign[str[i] - 'A'] == 'x') {
			if (st.empty()) {
				sign[str[i] - 'A'] = '(';
				st.push('(');
			}
			else {
				sign[str[i] - 'A'] = ')';
				st.pop();
			}
		}
		else {
			if (sign[str[i] - 'A'] == '(')
				st.push('(');
			else {
				if (st.empty()) {
					cout << "NO\n";
					return;
				}
				else
					st.pop();
			}
		}
	}

	if (st.empty()) 
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

	cerr << "time: "<<(double)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}