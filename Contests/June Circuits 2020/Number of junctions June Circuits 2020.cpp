#include<bits/stdc++.h> 
using namespace std; 
typedef unsigned long long ll;
typedef unsigned short int st; 

//Number of junctions June Circuits 2020
struct btree{
	int n, oil;
	btree *up, *left, *right;
} *root;

btree *search(int x, btree *troot = root) {
	if (troot == NULL)	return NULL;
	if (troot->n == x)
		return troot;
	btree *temp = search(x, troot->left);
	if (temp != NULL)
		return temp;
	else
		return search(x, troot->right);

}

void insert(int u, int v) {
	btree *temp, *ptr;
	ptr = new btree;
	ptr->oil = 0;
	ptr->left = NULL;
	ptr->right = NULL;
	if ((temp = search(u)) != NULL) 
		ptr->n = v;
	
	else {
		temp = search(v);
		ptr->n = u;
	}
	if (temp->left == NULL)
		temp->left = ptr;
	else
		temp->right = ptr;
	ptr->up = temp;
}

bool getpath(btree *troot, vector<int> &arr, int x) {
	if (!troot) 
        return false;
    arr.push_back(troot->n); 
  
    if (troot->n == x) 
        return true; 
  
    if (getpath(troot->left, arr, x) || getpath(troot->right, arr, x)) 
        return true; 
  
    arr.pop_back(); 
    return false; 
}

void spill(int s, int d, int l) {
	vector<int> path1, path2;
	getpath(root, path1, s);
	getpath(root, path2, d);
	int inter;
	for (inter = 0; inter < path1.size() && inter < path2.size(); inter++) {
		if (inter == path1.size()-1 || inter == path2.size()-1)
			break;
		if (path1[inter+1] != path2[inter+1])
			break;
	}
	btree *ptr = search(s);
	int oil = 1;
	for (int i = path1.size() - 1; i > inter; i--) {
		ptr->oil += oil;
		l -= oil;
		if (oil+1 <= l) 
			oil++;
		else if (l < oil)
			oil = l;

		if (ptr->up != NULL && ptr->up->n == path1[i-1])
			ptr = ptr->up;
		else if (ptr->left != NULL && ptr->left->n == path1[i-1])
			ptr = ptr->left;
		else if (ptr->right != NULL && ptr->right->n == path1[i-1])
			ptr = ptr->right;
	}
	if (ptr->up != NULL && ptr->up->n == path2[inter+1])
		ptr = ptr->up;
	else if (ptr->left != NULL && ptr->left->n == path2[inter+1])
		ptr = ptr->left;
	else if (ptr->right != NULL && ptr->right->n == path2[inter+1])
		ptr = ptr->right;
	
	for (int  i = inter+1; i < path2.size(); i++) {
		ptr->oil += oil;
		l -= oil;
		if (oil+1 <= l) 
			oil++;
		if (l < oil)
			oil = l;
		if ((ptr->up != NULL) && (i+1 < path2.size()) && (ptr->up->n == path2[i+1]))
			ptr = ptr->up;
		else if ((ptr->left != NULL) && (i+1 < path2.size()) && (ptr->left->n == path2[i+1]))
			ptr = ptr->left;
		else if ((ptr->right != NULL) && (i+1 < path2.size()) && (ptr->right->n == path2[i+1]))
			ptr = ptr->right;	
	}

}

void getmax(int &max, int sum = 0, btree *troot = root) {
	if (troot == NULL) {
		if (sum > max) 
			max = sum;
		return;
	}
	sum += troot->oil;
	getmax(max, sum, troot->left);
	getmax(max, sum, troot->right);
}

void solve() {
	root = new btree;
	root->n = 1;
	root->oil = 0;
	root->up = NULL;
	root->left = NULL;
	root->right = NULL;

	int N, u, v;
	cin >> N;
	for (int i = 0; i < N-1; i++) {
		cin >> u >> v;
		insert(u, v);
	}
	int M, s, d, l;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> s >> d >> l;
		spill(s,d,l);
	}
	int max = 0;
	getmax(max);
	cout << max << "\n";
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

//	int t;
//	cin >> t;
//	for (int i = 0; i < t; i++)
		solve(); 

	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0; 
} 
