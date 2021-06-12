#include <iostream>
#include <cmath>
using namespace std;

struct node {
    int x, y, pm, sm, pv, sv;
    node(){}
    node(int x, int y, int pm, int sm, int pv, int sv) {
        this->x = x;
        this->y = y;
        this->pm = pm;
        this->sm = sm;
        this->pv = pv;
        this->sv = sv;
    }
};

int n;
node arr[101];

/*
Find out if it is possible to have given number of
servings for each ingredient with given money
*/
bool isServingPossible(int totalServings, int money) {
    
    int required = 0;
    
    /* check if we can have totalServings of each ingredient */
    for(int i = 0; i < n; i++) {
        required = totalServings * arr[i].x;
        required -= arr[i].y;
        int minMoneySpent = 99999999;
        
        int limit = ceil(required / (double)arr[i].sm);
        
        for(int numSmallItem = 0; numSmallItem <= limit; numSmallItem++) {

            int totalSmallItem = numSmallItem * arr[i].sm;
            
            int numLargeItem = (required > totalSmallItem)? ceil((required - totalSmallItem) / (double)arr[i].sv) : 0;
            
            minMoneySpent = min(minMoneySpent, numSmallItem * arr[i].pm + numLargeItem * arr[i].pv);
        }
        
        money -= minMoneySpent;
        
        /* if no money left return false */
        if(money < 0)
            return false;
        
    }
    
    return true;
}

/*
find out if mid number of servings possible with given money
if yes search in mid to e
otherwise search in e to mid - 1
*/

void solve(int s, int e, int money) {
    while(s < e) {
        int mid = s + (e - s + 1) / 2;
        
        if(isServingPossible(mid, money))
            s = mid;
        
        else
            e = mid - 1;
    
    }
    
    cout << s << endl;
}

int main() {
    int m, x, y, pm, sm, pv, sv;
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        cin >> x >> y >> sm >> pm >> sv >> pv;
        arr[i] = node(x, y, pm, sm, pv, sv);
    }
    
    solve(0, m, m);
    
    return 0;
}
