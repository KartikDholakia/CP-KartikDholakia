#include<bits/stdc++.h> 
using namespace std; 
typedef unsigned long long ll;
typedef short int st; 

//Doctor Chef DRCHEF July Challenge 2020 Division 2
int findclosest(int x, vector<int> &a) {
	//return the index of the closest element from x
	if (x <= a[0])
		return 0;
	if (x >= a[a.size() - 1])
		return a.size()-1;

	int l = 0, h = a.size() - 1, mid;
	while (l < h) {
		mid = l + (h - l)/2;

		if (a[mid] == x)
			return mid;

		if (x < a[mid]) {
			if ((mid > 0) && (x > a[mid-1])) {
				if ((x - a[mid-1]) < (a[mid] - x))
					return mid-1;
				else
					return mid;
			}
			h = mid;
		}

		else {
			if ((mid < a.size() - 1) && (x < a[mid+1])) {
				if ((a[mid+1] - x) > (x - a[mid]))
					return mid;
				else 
					return mid+1;
			}
			l = mid+1;
		}
	}

	return mid;
}

void setdouble(vector<int> &a, vector<int> &temp) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] < temp[i]) 
			if (a[i]*2 <= temp[i])
				a[i] *= 2;
			else
				a[i] = temp[i];
	}
}

void solve() {
	int n, inp, i, count = 0;
	ll x;
	vector<int> a, temp;
	cin >> n >> x;

	for (i = 0; i < n; i++) {
		cin >> inp;
		a.push_back(inp);
		temp.push_back(inp);
	}

	sort(a.begin(), a.end());
	sort(temp.begin(), temp.end());
	ll cure = 0, days = 0;

	while (count < n) {
		days++;
		setdouble(a, temp);				//doubles the no of infected people in each country
		i = findclosest(x, a);			//returns the index of the closest element in array to x

		if (i > 0 && ((a[i-1] > x/2) || (2*a[i-1] >= a[i]))) // && (a[i-1] <= x))// && )
			i--;
		
		else if ((a[i] < x/2) || ((a[i]/2 < x) && (x < a[i])))
			if (i+1 < a.size())
				i++;

		cout << x << " -> " << a[i];

		cure = (a[i] > x)? x:a[i]; 
		a[i] = (a[i] > x)? (a[i] - x): 0;
		x = cure*2;

		cout << " -> " << a[i] << "\n";

		if (a[i] == 0) {
			count++;
			a.erase(a.begin() + i);
			temp.erase(temp.begin() + i);
		}
	}
	
	cout << days << "\n";
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

/*
7
6 1
2 6 17 36 125 400
6 20
2 6 17 36 125 400
5 5
1 2 3 4 5
5 1
40 30 20 10 50
3 10
20 1 110
3 8
10 20 30
3 16
10 21 44
*/

/*
12
9
5
9
6
4
5
*/