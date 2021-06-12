#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()

//B. Hills And Valleys
//Codeforces Round #695 (Div. 2)
void solve() {
	int n, i;
	cin >> n;

	if (n < 3) {
		cout << "0\n";
		return;
	}
	
	vector<int> v(n);
	for (i = 0; i < n; i++)
		cin >> v[i];

	int nh = 0, nv = 0;
	vector<char> temp(n, 'p');
	for (i = 1; i < n-1; i++) {
		if (v[i] > v[i+1] && v[i] > v[i-1]) {
			temp[i] = 'h';
			nh++;
		}
		else if (v[i] < v[i+1] && v[i] < v[i-1]) {
			temp[i] = 'v';
			nv++;
		}
	}

	int mx = 0;
	for (i = 1; i < n-1; i++) {
		if (temp[i] == 'h') {
			if (temp[i-1] == 'v' && temp[i+1] == 'v' && mx < 3) {
				mx = 3;
				break;
			}
			else if ((temp[i-1] == 'v' || temp[i+1] == 'v') && mx < 2)
				mx = 2;
			else
				mx = 1;
		}
		else if (temp[i] == 'v') {
			if (temp[i-1] == 'h' && temp[i+1] == 'h' && mx < 3) {
				mx = 3;
				break;
			}
			else if ((temp[i-1] == 'h' || temp[i+1] == 'h') && mx < 2)
				mx = 2;
			else
				mx = 1;
		}
	}

	cout << (nh + nv - mx) << "\n";

	// if (nh + nv <= 3)
	// 	cout << 0;
	// else
	// 	cout << (nh + nv - 3);
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
	for (int i = 1; i <= t; i++) {
		// cout << "Case #" << i << ": ";
		// cout << "Test " << i << ":\n";
		solve();
	}

	cerr << "time: "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}