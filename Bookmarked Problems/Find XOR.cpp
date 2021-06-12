#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef short int st;
#define mod 1000000007
#define MAX 1000001
#define INF 9223372036854775807
#define all(x) x.begin(),x.end()

//FIND XOR
//BIT Manipulation, XOR, Linear Equations
//https://www.codechef.com/SEPT20B/problems/FINXOR
//https://www.youtube.com/watch?v=lX41qdW9u3M
class grader {
    vector<int> v;
    int xr;
public:
    grader(vector<int> x) {
        xr = 0;
        for (int i = 0; i < x.size(); i++) {
            v.push_back(x[i]);
            xr = (xr ^ x[i]);
        }
    }
    ll query(int k) {
        ll sum = 0;
        for (int i = 0; i < v.size(); i++) {
            sum += (v[i] ^ k);
        }
        return sum;
    }
    bool check(int x) {
        return (xr == x);
    }
};

void solve() {
    int n, i, k;
    cin >> n;

/*    vector<int> v(n);
    for (i = 0; i < n; i++)
        cin >> v[i];

    class grader g(v);
    x = g.query((int)pow(2, 20));
*/
    ll x, S;
    cout << "1 " << (int)pow(2, 20) << "\n";
    cout.flush();
    //cout << "1 20: ";

    cin >> x;

    //cout << x << "\n";

    S = x - n*((int)pow(2, 20));

//    cout << "S = " << S << "\n";

    vector<int> bin1(20, -1);
    ll temp = 0;
    ll ans = 0;

    for (i = 0; i < 19; i++) {
        cout << 1 << " " << (int)pow(2, i) << "\n";
        //cout << "1 " << i << " : ";
        cout.flush();
        cin >> x;
        //x = g.query((int)pow(2, i));
        //cout  << x << "\n";
        if (x == -1) {
            cout << "\nInvalid Query!!";
            return;
        }
        bin1[i] = ((S - x)/(int)pow(2, i) + n)/2;
        temp += (bin1[i] * (int)pow(2, i));
        ans += (bin1[i] % 2) * (int)pow(2, i);
    }
    bin1[19] = (S - temp)/(int)pow(2, 19);
    ans += (bin1[19] % 2) * (int)pow(2, 19);

    //cout << "ans = ";
    cout << "2 " << ans << "\n";
    cout.flush();
    cin >> x;
    if (x == -1) {
        exit(0);
    }

    /*cout << "Binary array is: ";
    for (i = 0; i < 20; i++)
        cout << bin1[i] << " ";
    cout << "\n";

    if (g.check(ans))
        cout << "Correct\n";
    else
        cout << "Wrong\n";
    */
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}

	cerr << "time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}
