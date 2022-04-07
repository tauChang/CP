/*
 tag: bit, linked list, priority queue, medium
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <cmath>
#define AC ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
#define MAXV 105
#define MAXN 250005
#define EPS 1e-7
typedef long long ll;
typedef double db;
int n, pre[MAXN], nxt[MAXN];
db x[MAXN], v[MAXN];

int bit[MAXV];

void add(int x){
    for(; x < MAXV; x+=x&-x) bit[x]++;
}

ll query(int x){
    ll res = 0;
    for(; x; x-=x&-x) res+=bit[x];
    return res;
}

class Event{
public:
    int a, b;
    db t, pos;
    Event(int _a, int _b): a(_a), b(_b){
        t = (x[b]-x[a])/(v[a]-v[b]);
        pos = x[b]+v[b]*t;
    }
    bool operator< (const Event& e) const{
        return fabs(t-e.t) > EPS ? t < e.t : pos < e.pos;
    }
};

int main(){
    ll count = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%lf %lf", &x[i], &v[i]);
        count += i-1 - query((int)v[i]);
        add((int)v[i]);
    }
    printf("%d\n", count%1000000);

    set<Event> S;

    for(int i = 0; i <=n; ++i){
        if(i > 0 && i < n && v[i] > v[i+1]) S.insert(Event(i, i+1));
        nxt[i] = i+1;
        pre[i+1] = i;
    }

    for(int i = 0; i < 10000 && !S.empty(); ++i){
        auto e = *S.begin();
        int a = e.a, b = e.b;
        printf("%d %d\n", a, b);
        S.erase(S.begin());
        S.erase(Event(pre[a], a));
        S.erase(Event(b, nxt[b]));
        nxt[pre[a]] = b;
        pre[b] = pre[a];
        nxt[a] = nxt[b];
        pre[nxt[b]] = a;
        nxt[b] = a;
        pre[a] = b;
        if(pre[b] && v[pre[b]] > v[b]) S.insert(Event(pre[b], b));
        if(nxt[a] <= n && v[a] > v[nxt[a]]) S.insert(Event(a, nxt[a]));
    }

    return 0;
}