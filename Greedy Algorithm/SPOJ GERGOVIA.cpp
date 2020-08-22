#include<bits/stdc++.h> 
using namespace std; 
typedef long long ll; 

void solve() {
	//https://www.spoj.com/problems/GERGOVIA/
	struct wine {
		int amt, index;
		wine() {
			amt = 0;
			index = -1;
		}
	};
	vector<wine> buy, sell;
	int n, a, l1 = 0, l2 = 0;
	ll work = 0;
	while(1) {
		cin >> n;
		if (n == 0)
			break;
		for (int i = 0; i < n; i++) {
			cin >> a;
			if (a > 0) {
				buy.push_back(wine());
				buy[l1].amt = a;
				buy[l1].index = i;
				l1++;
			}
			if (a < 0) {
				sell.push_back(wine());
				sell[l2].amt = -a;
				sell[l2].index = i;
				l2++;	
			}
		}
		for (int i = 0, j = 0; i < l1 && j < l2;) {
			if (buy[i].amt >= sell[j].amt) {
				work += sell[j].amt * abs(sell[j].index - buy[i].index);
				buy[i].amt -= sell[j].amt;
				sell[j].amt = 0;
				j++;
			}
			else {
				work += buy[i].amt * abs(sell[j].index - buy[i].index);
				sell[j].amt -= buy[i].amt;
				buy[i].amt = 0;
				i++;
			}
		}
		cout << work << "\n";
		work = 0;
	}
	

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

	solve(); 

	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0; 
} 
