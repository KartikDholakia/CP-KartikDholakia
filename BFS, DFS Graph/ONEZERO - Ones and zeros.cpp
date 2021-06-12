#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()

//ONEZERO - Ones and zeros
//https://www.spoj.com/problems/ONEZERO/
//BFS | Modulo of large numbers represented in strings
vector<string> binary;

int modulo(string num, int m) {
	int res = 0;
	for (int i = 0; i < num.length(); i++)
		res = (res*10 + (num[i] - '0')) % m;

	return res;
}

void solve() {
	int n, i = 0;
	cin >> n;
	string temp;

	while(1) {
		temp = binary[i];
		if (modulo(temp, n) == 0) {
			cout << temp << "\n";
			return;
		}
		i++;
		if (2*i + 1 > binary.size() - 1) {
			binary.push_back(temp + "0");
			binary.push_back(temp + "1");
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
	//freopen is used to associate a file with stdin or stdout stream in C++
	#endif

	int t = 1;
	cin >> t;
	binary.push_back("1");
	for (int i = 1; i <= t; i++) {
		solve();
	}

	cerr << "time: "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}