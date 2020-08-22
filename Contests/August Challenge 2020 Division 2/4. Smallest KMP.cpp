#include<bits/stdc++.h> 
using namespace std; 
typedef long long ll;
typedef short int st; 
#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
 
//Smallest KMP
void solve() {
	string s, p;
	cin >> s >> p;
	sort(s.begin(), s.end());
	int i;

	vector<int> alpha(26, 0);

	for (i = 0; i < s.size(); i++)
		alpha[s[i] - 'a']++;

	for (i = 0; i < p.size(); i++)
		alpha[p[i] - 'a']--;


	int k = 0;
//	char min_char = *min_element(p.begin(), p.end());

	for (i = 0; i <= p[0] - 'a'; i++) {
		k = 0;
		while ((i == p[k] - 'a') && alpha[i]) {
			k++;
		}
		if (i < p[k] - 'a') {
			while (alpha[i]) {
				cout << (char)(i + 'a');
				alpha[i]--;
			}
		}
	}
	cout << p;
	for (i = 0; i < 26; i++) {
		while (alpha[i]) {
			cout << (char)(i + 'a');
			alpha[i]--;
		}
	}

	cout << "\n";
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
 
	st t = 1;
	cin >> t;
	for (st i = 0; i < t; i++)
		solve(); 
 
	cerr << "time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0; 
} 
