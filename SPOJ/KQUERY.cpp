#include <iostream>
#include <algorithm>
#define AC ios::sync_with_stdio(0),cin.tie(0);
using namespace std;

int n, q;
int BIT[30002], ans[230002];
class Node{
public:
    bool isQ;
    int id, l, r, k;
    Node(): isQ(0) {}
} A[230002];

void add(int x, int v){
    for(; x <= n; x += x&-x) BIT[x] += v;
}

int query(int x){
    int ans = 0;
    for(; x > 0; x -= x&-x) ans += BIT[x];
    return ans;
}


int main(){
    AC
    cin >> n;
    for(int i = 0; i < n; ++i) {
        A[i].l = i+1;
        cin >> A[i].k;
    }
    cin >> q;
    for(int i = n; i < n+q; ++i) {
        A[i].id = i-n;
        A[i].isQ = 1;
        cin >> A[i].l >> A[i].r >> A[i].k;
    }

    sort(begin(A), begin(A)+n+q, [](Node& n1, Node& n2) {return n1.k > n2.k || (n1.k == n2.k && n1.isQ); });

    for(int i = 0; i < n+q; ++i){
        if(A[i].isQ) ans[A[i].id] = query(A[i].r) - query(A[i].l-1);
        else add(A[i].l, 1);
    }

    for(int i = 0; i < q; ++i) cout << ans[i] << endl;
    return 0;
}