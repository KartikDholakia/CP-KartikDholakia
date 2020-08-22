#include<bits/stdc++.h> 
using namespace std; 
typedef unsigned long long ll;
typedef unsigned short int st; 
 
//The maximum number June Circuits 2020
unsigned int to_dec(string str) {
    //convert binary string to decimal
	unsigned int dec = 0;
	for (st i = 0; i < str.size(); i++) {
		dec += (str[str.size() - i - 1] - '0') * pow(2, i);
	}
	return dec;
}
 
st countbitsets(unsigned int x) {
	st count = 0;
	while (x) {
		count += x & 1;
		x >>= 1;
	}
	return count;
}
 
void solve() {
	unsigned int n, inp, max = 0, num;
	ll sum = 0, max_sum = 0, count = 1;
	st l;
	cin >> n >> l;
	vector<unsigned int> a;
	for (unsigned int i = 0; i < n; i++) {
		cin >> inp;
		a.push_back(inp);
		max = max|inp;
	}
//	cout << "max is: " << max << "\n";
	string binary;
	st bl = log10(max)/log10(2);
	st req = countbitsets(max);
	if (l > req) {
		cout << -1 << "\n";
		return;
	}
 
	for(st i = 0; i <= bl; i++)
		binary.push_back('0');
	
	for (st i = 0; i < l; i++)
		binary[bl-i] = '1';
 
	bool infinte = 0;
//    cout << "binary\tnum\tsum\tcount\n";
    
    do {
		num = to_dec(binary);
		sum = 0;
		for (unsigned int i = 0; i < n; i++) {
			sum += a[i] & num;
		}
		if (sum == max_sum) {
			count++;
            if (count >= 1e18) {
                infinte = 1;
                break;
            }
        }
		if (sum > max_sum) {
			max_sum = sum;
			count = 1; 
		}
//        cout << binary << "\t" << num << "\t" << sum << "\t" << count << "\n";
	} while(next_permutation(binary.begin(), binary.end()));
	
    if (infinte == 0)
	    cout << count;
    else
        cout << -1;
    cout << "\n";
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
 
	st t;
	cin >> t;
	for (int i = 0; i < t; i++)
		solve(); 
 
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0; 
} 