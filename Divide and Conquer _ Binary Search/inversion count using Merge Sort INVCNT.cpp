#include<bits/stdc++.h> 
using namespace std; 
typedef unsigned long long ll; 

//inversion count using Merge Sort
ll merge(vector<int> &v, int lo, int hi) {
	int i, j;
	int mid = (lo+hi)/2;
	ll count = 0;
	vector<int> temp;
	
/*	cout << "\n(" << lo << ", " << hi << ") : ";
	for (int k = 0; k < v.size(); k++)
		cout << v[k] << " ";
	cout << "=> ";
*/
	for (i = lo, j = mid; (i < mid) && (j < hi); ) {
		if (v[i] < v[j]) {
			temp.push_back(v[i]);
			i++;
		}
		if (v[i] > v[j]) {
			count += mid - i;
			temp.push_back(v[j]);
			j++;
		}
	}
	while (i < mid) {
		temp.push_back(v[i]);
		i++;
	}
	while (j < hi) {
		temp.push_back(v[j]);
		j++;
	}

	for (int k =  lo, m = 0; k < hi; k++, m++) {
		v[k] = temp[m];
	}
/*	//cout << "\nMerge count: " << count;
	for (int k = 0; k < v.size(); k++)
		cout << v[k] << " ";
	cout << "; Temp: ";
	for (int m = 0; m < temp.size(); m++)
		cout << temp[m] << " ";
	cout << "; Count : " << count;
*/	
	temp.clear();
	return count;
}

ll countInv(vector<int> &v, int lo, int hi) {
	if (hi-lo == 1)
		return 0;
	int mid = (lo+hi)/2;
	ll lc = countInv(v, lo, mid);
	ll rc = countInv(v, mid, hi);
	return merge(v, lo, hi) + lc  + rc;
}


void solve() {
	int n, inp;
	cin >> n;
	vector<int> a;
	for (int i = 0; i < n; i++) {
		cin >> inp;
		a.push_back(inp);
	}
	cout << countInv(a, 0, n) << "\n";
}

int main() 
{ 
	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("error.txt", "w", stderr); 
	freopen("output.txt", "w", stdout); 
	//freopen is used to associate a file with stdin or stdout stream in C++
	#endif 

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
		solve(); 

	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0; 
} 
