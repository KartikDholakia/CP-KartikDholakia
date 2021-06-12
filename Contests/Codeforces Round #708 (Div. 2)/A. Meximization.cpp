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

//A. Meximization
//Codeforces Round #708 (Div. 2)
void solve() {
	int n, i, inp;
	int arr[101] = {0};
	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> inp;
		arr[inp]++;
	}

	for (i = 0; i <= 100; i++) {
		if (arr[i]) {
			cout << i << " ";
			arr[i]--;
		}
	}

	for (i = 0; i <= 100; i++) {
		while (arr[i]) {
			cout << i << " ";
			arr[i]--;
		}
	}
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