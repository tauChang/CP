/*
 tag: graph, medium
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <cstring>
using namespace std;
#define MAX 1e9+3

class Node{
public:
    Node *lc=NULL, *rc=NULL;
    int val=0, tag=0;
};

void push(Node* x){
    if(!x->lc) x->lc = new Node();
    if(!x->rc) x->rc = new Node();
    x->lc->tag = x->tag;
    x->rc->tag = x->tag;
    x->val += x->tag;
    x->tag = 0;
}

void add(Node* x, int tl, int tr, int l, int r, int v){
    if(tl == l && tr == r) {
        x->tag += v;
        return;
    }
    int tm = (tl+tr)/2;
    if(!x->lc) x->lc = new Node();
    if(!x->rc) x->rc = new Node();
    if(r <= tm) add(x->lc, tl, tm, l, r, v);
    else if(l > tm) add(x->rc, tm+1, tr, l, r, v);
    else{
        add(x->lc, tl, tm, l, tm, v);
        add(x->rc, tm+1, tr, tm+1, r, v);
    }
    x->val = max(x->lc->val+x->lc->tag, x->rc->val+x->rc->tag);
}

int query(Node* x, int tl, int tr, int l, int r){
    if(!x) return 0;
    if(tl == l && tr == r) return x ? x->val+x->tag : 0;
    push(x);
    int tm = (tl+tr)/2;
    if(r <= tm) return query(x->lc, tl, tm, l, r);
    if(l > tm) return query(x->rc, tm+1, tr, l, r);
    return max(query(x->lc, tl, tm, l, tm), query(x->rc, tm+1, tr, tm+1, r));
}

int main(){
    int n;
    scanf("%d", &n);

    Node* root = new Node();
    for(int i = 0, l, r, w; i < n; ++i){
        scanf("%d %d %d", &l, &r, &w);
        add(root, 0, MAX, l, r, w);
    }
    printf("%d", query(root, 0, MAX, 0, MAX));
}