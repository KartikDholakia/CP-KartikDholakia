#include<bits/stdc++.h> 
using namespace std; 
typedef long long ll;
typedef short int st; 
#define mod 1000000007
 
//D. a-Good String Codeforces Round #656 (Div. 3)
//upsolved :(
string a;

int  count(int l, int r, char c) {
	int cnt = 0;
	for (int i = l; i <= r; i++) {
		if (a[i] == c)
			cnt++;
	}
	return cnt;
}

int min(int x, int y) {
	if (x < y)
		return x;
	else 
		return y;
}

int goodc(int l, int r, char c) {
	if (l == r) {
		if (a[l] == c)
			return 0;
		else 
			return 1; 
	}

	int mid = (r+l)/2, x = (r-l+1)/2;
	int cnt1 = x - count(l, mid, c) + goodc(mid+1, r, c+1);
	int cnt2 = x - count(mid+1, r, c) + goodc(l, mid, c+1);

	int ans = min(cnt1, cnt2);
//	cout << "(" << l << ", " << r << ") [" << c << "]: " << ans << "\n";
	return ans;
}

void solve() {
	int n;
	cin >> n;
	cin >> a;
	cout << /*a << " " <<*/ goodc(0, n-1, 'a') << "\n";
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
