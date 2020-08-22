#include<bits/stdc++.h> 
using namespace std; 
typedef unsigned long long ll;
typedef short int st; 

//Tree query https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/tree-query-3-5d98588f/?layout=old
struct tree {
	int v;
	ll count;
	tree *left, *right;
};

class st {
	tree *root;
public:
	st() {
		root = NULL;
	}
	tree *search(int x);
	void insert(int a, int b);
	void update();
	void fun();
}

tree* st::search(int x, tree *troot = root) {
	if (troot == NULL)	return NULL;
	tree *temp;
	if (troot->data == x)
		return troot;
	temp = search(x, troot->left);
	if (temp != NULL)
		return temp;
	else
		return search(x, troot->right);
} 

void st::insert(int a, int b) {
	tree *temp = new tree;
	temp->v = b;
	tree *p = search(a);
	
	if (p == NULL) {
		p = search(b);
		temp->v = a;
	}
		
	if (p->left == NULL)
		p->left = temp;
	else
		p->right = temp;
}

void solve() {
	int n, q, a, b, i;
	cin >> n >> q;
	for (i = 0; i < n-1; i++) {
		cin >> a >> b;
		s.insert(a, b);
	}
	for (i = 0; i < q; i++) {
		cin >> a >> b;
		if (a == 1) {

		}
		else {

		}
	}
		}
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

