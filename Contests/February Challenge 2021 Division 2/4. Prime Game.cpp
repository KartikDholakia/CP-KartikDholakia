#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)

//4. Prime Game
//February Challenge 2021 Division 2
vector<int> prefix(MAX, 0);

void SieveofEratosthenes() {
    bool prime[MAX];
    memset(prime, true, sizeof(prime));   
    for (int p = 2; p * p < MAX; p++) { 
        if (prime[p] == true) {   
            for (int i = p * 2; i <= MAX; i += p) 
                prime[i] = false; 
        } 
    } 
    // Build prefix array 
    prefix[0] = prefix[1] = 0; 
    for (int p = 2; p < MAX; p++) { 
        prefix[p] = prefix[p - 1]; 
        if (prime[p]) 
            prefix[p]++; 
    } 
}

void solve() {
	int x, y;
	cin >> x >> y;
	if (y < prefix[x])
		cout << "Divyam\n";
	else
		cout << "Chef\n";
}

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	//remove this piece of code when this has to be submitted in kickstart
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
	//freopen is used to associate a file with stdin or stdout stream in C++
	#endif


	int t = 1;
	cin >> t;
	SieveofEratosthenes();
	for (int i = 1; i <= t; i++) {
		solve();
	}

	cerr << "time: "<<(double)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}