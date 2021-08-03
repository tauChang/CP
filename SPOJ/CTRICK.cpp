#include <iostream>
#include <cstring>
#define AC ios::sync_with_stdio(0),cin.tie(0);
using namespace std;

int n;
int BIT[20009], ans[20009];

void init(){
    memset(BIT, 0, sizeof (BIT));
    for(int i = 1; i <= n; ++i) {
        BIT[i] += 1;
        if(i+(i&-i) <= n) BIT[i+(i&-i)] += BIT[i];
    }
}

int query(int x){
    int ans = 0;
    for(; x > 0; x -= (x&-x)) ans += BIT[x];
    return ans;
}

void add(int x, int v){
    for(; x <= n; x += (x&-x)) BIT[x] += v;
}

int main(){
    AC
    int t;
    cin >> t;
    while(t--){
        cin >> n;

        memset(BIT, 0, sizeof (BIT));
        for(int i = 1; i <= n; ++i) {
            add(i, 1);
        }   

        for(int i=1, j=1; i <= n; ++i){ // i should be placed at the j-th empty slot (1-based)
            j = (j-1+i+1) % (n-i+1);
            if(!j) j = n-i+1;

            int l = 1, r = n;
            while(l != r){
                int m = (l+r)/2;
                if(query(m) < j) l = m+1;
                else r = m;
            }
            ans[l] = i;
            add(l, -1);
        }
        
        for(int i = 1; i <= n; ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}