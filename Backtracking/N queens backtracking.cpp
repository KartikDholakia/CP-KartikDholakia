#include<bits/stdc++.h> 
using namespace std; 
typedef unsigned long long ll;
typedef short int st; 

//N queens
st N;
void mark(st i, st j, vector<vector<st>> &arr) {
	st x, y;
	//horizontally:
	for (y = 0; y < N; y++)
		arr[i][y] = 0;
	//vertically:
	for (x = 0; x < N; x++)
		arr[x][j] = 0;
	//left diagonal:
	st back = -1, forw = 1;
	while((back + i >= 0)&&(back + j >= 0)) {		//upper side
		arr[back + i][back + j] = 0;
		back--;
	}
	while((forw + i < N)&&(forw + j < N)) {			//lower side
		arr[forw + i][forw + j] = 0;
		forw++;
	}
	//right diagonal:
	back = -1;
	forw = 1;
	while ((i + forw < N)&&(back + j >= 0)) {		//upper side
		arr[forw + i][back + j] = 0;
		forw++;
		back--;
	}
	back = -1;
	forw = 1;
	while ((i + back >= 0)&&(j + forw < N)) {		//lower side
		arr[i + back][j + forw] = 0;
		forw++;
		back--;
	}
	arr[i][j] = 1;
}

void display(vector<vector<st>> arr) {
	for (st i = 0; i < N; i++) {
		for (st j = 0; j < N; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

bool Nq(st n, vector<vector<st>> arr) {
	if (n == N) {
		display(arr);
		return 1;
	}
	vector<vector<st>> temp = arr;
	bool flag = 0;
	for (st j = 0; j < N; j++) {
		if (arr[n][j] == -1) {
			arr[n][j] = 1;
			flag = 1;
			mark(n, j, arr);
			if (Nq(n+1, arr) == 0) {
				flag = 0;
				arr = temp;
			}
			else {
				flag = 1;
				break;
			}
		}
	}
	return flag;
}

void solve() {
	cin >> N;
	vector<vector<st>> arr;
	for (st i = 0; i < N; i++) {
		arr.push_back(vector<st> ());
		for(st j = 0; j < N; j++)
			arr[i].push_back(-1);
	}

	if (Nq(0, arr) == 0) 
		cout << "Not possible";
}

int main()  { 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("error.txt", "w", stderr); 
	freopen("output.txt", "w", stdout); 
	//freopen is used to associate a file with stdin or stdout stream in C++
	#endif 

	solve(); 

	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0; 
} 
