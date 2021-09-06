#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short int st;

#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(), x.end()

//https://www.spoj.com/problems/PPATH/
//BFS Graph | Sieve Of Eratosthenes

vector<bool> prime(10001, 1);
vector<int> primes;
vector<int> graph[10001];

void SieveOfEratosthenes() {
	for (int p = 2; p*p < 10000; p++) {
		// If prime[p] is not changed, then it is a prime 
		if (prime[p] == true)  {
			for (int i = p*p; i <= 10000; i += p)
				prime[i] = false; 
		} 
	} 

	for (int i = 1000; i < 10000; i++) {
		if (prime[i])
			primes.push_back(i);
	}

	// // Print all prime numbers 
	// for (int i = 0; i <= primes.size(); i++)
	// 	cout << primes[i] << "\n";
}

bool is(int x, int y) {
	string s1 = to_string(x);
	string s2 = to_string(y);
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		if (s1[i] == s2[i])
			cnt++;
	}
	if (cnt == 3)
		return 1;
	else
		return 0;
}

void buildGraph() {
	for (int i = 1000; i < 10000; i++)
		graph[i].clear();
	
	for (int i = 0; i < primes.size(); i++) {
		for (int j = i+1; j < primes.size(); j++) {
			if (is(primes[i], primes[j])) {
				graph[primes[i]].push_back(primes[j]);
				graph[primes[j]].push_back(primes[i]);
			}
		}
	}
	// cout << "Created!!\n";
}

int bfs(int x, int y) {
	vector<bool> visited(10000, false);
	queue<int> q;
	q.push(x);
	visited[x] = 1;
	int i, curr;
	vector<int> level(10000, 0);

	while (!q.empty()) {
		curr = q.front();
		q.pop();
		for (i = 0; i < graph[curr].size(); i++) {
			if (!visited[graph[curr][i]]) {
				visited[graph[curr][i]] = 1;
				q.push(graph[curr][i]);
				level[graph[curr][i]] = level[curr] + 1;
				if (graph[curr][i] == y)
					return level[graph[curr][i]];
			}
		}		
	}

	return 0;
}

void solve() {
	int x, y;
	cin >> x >> y;
	if (x == y) {
		cout << "0\n";
		return;
	}
	int ans = bfs(x, y);
	if (ans)
		cout << ans;
	else
		cout << "Impossible";
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
	//freopen is used to associate a file with stdin or stdout stream in C++
	#endif

	int t = 1;
	cin >> t;
	SieveOfEratosthenes();
	buildGraph();
	// for (int i = 0; i < graph[1033].size(); i++)
	// 	cout << graph[1033][i] << " ";
	// cout << "\n";
	
	// for (int i = 0; i < graph[1733].size(); i++)
	// 	cout << graph[1733][i] << " ";
	// cout << "\n";

	// for (int i = 0; i < graph[3733].size(); i++)
	// 	cout << graph[3733][i] << " ";
	// cout << "\n";

	for (int i = 1; i <= t; i++) {
		solve();
	}

	cerr << "time: "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}