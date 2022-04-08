/*
 tag: segment tree, greedy, medium
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <cstring>
using namespace std;
#define MAXN 100005
#define MAXTIME 100005
typedef vector<int> vi;
int n, st[MAXTIME<<2], tag[MAXTIME<<2];

void push(int id, int tl, int tr){
    tag[id*2+1] += tag[id];
    tag[id*2+2] += tag[id];
    st[id] += tag[id]*(tr-tl+1);
    tag[id] = 0;
}

int rv(int id, int tl, int tr) { return st[id]+tag[id]*(tr-tl+1); }

void add(int id, int tl, int tr, int l, int r){
    if(tl == l && tr == r) {
        tag[id]++; return;
    }
    int tm = (tl+tr)/2;
    if(r <= tm) add(id*2+1, tl, tm, l, r);
    else if(l > tm) add(id*2+2, tm+1, tr, l, r);
    else {
        add(id*2+1, tl, tm, l, tm);
        add(id*2+2, tm+1, tr, tm+1, r);
    }
    st[id] = rv(id*2+1, tl, tm) + rv(id*2+2, tm+1, tr);
    return;
}

int query(int id, int tl, int tr, int l, int r){
    if(tl == l && tr == r) return rv(id, tl, tr);
    push(id, tl, tr);
    int tm = (tl+tr)/2;
    if(r <= tm) return query(id*2+1, tl, tm, l, r);
    if(l > tm) return query(id*2+2, tm+1, tr, l, r);
    return query(id*2+1, tl, tm, l, tm)+query(id*2+2, tm+1, tr, tm+1 ,r);
}


int main(){
    while(1){
        vector<vi> stack, arr;
        memset(st, 0, sizeof(st));
        memset(tag, 0, sizeof(tag));
        
        scanf("%d", &n);
        if(!n) break;
        for(int i = 0, a, b, c; i < n; ++i){
            scanf("%d %d %d", &a, &b, &c);
            arr.push_back({a, b-1, c});
        }
        sort(begin(arr), end(arr), [](vi& v1, vi& v2) { return v1[1] < v2[1]; });
        int cur = -1;
        for(auto& v:arr){
            if(cur != v[1]){
                stack.push_back({cur+1, v[1]});
                cur = v[1];
            }

            v[2] -= query(0, 0, MAXTIME-1, v[0], v[1]);

            while(v[2] > 0){
                vi u = stack.back(); stack.pop_back();
                int l, r;
                if(u[1]-u[0]+1 > v[2]) {
                    r = u[1]; l = r-v[2]+1;
                    stack.push_back({u[0], l-1});
                } else{
                    r = u[1]; l = u[0];
                }
                v[2] -= (r-l+1);
                add(0, 0, MAXTIME-1, l, r);
            }
        }
        printf("%d\n", query(0, 0, MAXTIME-1, 0, MAXTIME-1));
    }
    return 0;
}