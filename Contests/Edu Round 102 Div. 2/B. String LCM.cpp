#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()

//B. String LCM
//Edu Round 102 Div. 2
string reduce(string s) {
	string temp;
	bool flag = 0;
	for (int i = 0; i < s.size()/2; i++) {
		temp += s[i];
		if (s.substr(i+1, s.size()-1) + temp == s) {
			flag = 1;
			break;
		}
	}
	if (flag)
		return temp;
	else
		return s;
}

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
 
// Function to return LCM of two numbers 
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

void solve() {
	string s1, s2;
	cin >> s1 >> s2;

	string reduced1 = reduce(s1);
	string reduced2 = reduce(s2);
	int x1 = s1.size()/reduced1.size(), x2 = s2.size()/reduced2.size();

	// cout << reduced1 << "\n";
	// cout << reduced2 << "\n";

	if (reduced1 != reduced2) {
		cout << "-1\n";
		return;
	}
	
	int n = lcm(x1, x2);
	for (int i = 0; i < n; i++)
		cout << reduced1;
	
	cout << "\n";
	
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
	for (int i = 1; i <= t; i++) {
		// cout << "Case #" << i << ": ";
		// cout << "Test " << i << ":\n";
		solve();
	}

	cerr << "time: "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}