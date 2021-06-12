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

//2. L-Shaped Plots
bool inp[1001][1001];

int check(int r, int c, int x, int y) {
	int cnt = 0, i, j;
	//*
	//*
	//*
	//**
	i = x - 3;
	j = y + 1;
	while (i >= 0 && j < c && inp[i][j]) {
		i -= 2;
		j++;
		cnt++;
	}

	//****
	//*
	i = x + 1;
	j = y + 3;
	while (i < r && j < c && inp[i][j]) {
		i++;
		j += 2;
		cnt++;
	}

	//**
	// *
	// *
	// *
	i = x - 1;
	j = y + 3;
	while (i >= 0 && j < c && inp[i][j]) {
		i--;
		j += 2;
	}

	// *
	// *
	// *
	//**
	i = x - 3;
	j = y - 1;
	while (i >= 0 && j >= 0 && inp[i][j]) {
		i -= 2;
		j--;
		cnt++;
	}

	//*
	//****
	i = x - 1;
	j = y + 3;
	while (i >= 0 && j < c && inp[i][j]) {
		i--;
		j += 2;
		cnt++;
	}

	//**
	//*
	//*
	//*
	i = x + 3;
	j = y + 1;
	while (i < r && j < c && inp[i][j]) {
		i += 2;
		j++;
		cnt++;
	}

	//****
	//   *
	i = x + 1;
	j = y - 3;
	while (i < r && j >= 0 && inp[i][j]) {
		i++;
		j -= 2;
		cnt++;
	}

	return cnt;
}

void solve() {
	int r, c, i, j;
	cin >> r >> c;

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			cin >> inp[i][j];

	ll cnt = 0;
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			if (inp[i][j])
				cnt += check(r, c, i, j);
		}
	}

	cout << cnt << "\n";
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
		cout << "Case #" << i << ": ";
		solve();
	}

	cerr << "time: "<<(double)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}