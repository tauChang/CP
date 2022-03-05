/*
 tag: Treap, difficult
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#define AC ios::sync_with_stdio(0),cin.tie(0);
using namespace std;

class Node{
public:
    bool tag;
    int id, sz, pri;
    Node *lc, *rc;
    Node(int _id): id(_id){
        pri = rand();
        lc = rc = NULL;
        tag = 0;
        sz = 1;
    }
};

void update(Node* a){
    a->sz = (a->lc ? a->lc->sz : 0) + (a->rc ? a->rc->sz : 0) + 1;
}

void push(Node* a){
    if(a->tag) swap(a->lc, a->rc);
    if(a->lc) a->lc->tag ^= a->tag;
    if(a->rc) a->rc->tag ^= a->tag;
    a->tag ^= a->tag;
    update(a);
}

void split(Node *t, Node *&a, Node*& b, int k){
    if(!t) {
        a = b = NULL;
        return;
    }

    push(t);
    int v = (t->lc ? t->lc->sz : 0) + 1;

    if(v <= k){
        a = t; 
        split(t->rc, a->rc, b, k-v);
        update(a);
    } else{
        b = t;
        split(t->lc, a, b->lc, k);
        update(b);
    }
}

Node* merge(Node* a, Node* b){
    if(!a) return b;
    if(!b) return a;
    if(a->pri > b->pri){
        push(a);
        a->rc = merge(a->rc, b);
        update(a);
        return a;
    } else{
        push(b);
        b->lc = merge(a, b->lc);
        update(b);
        return b;
    }
}

Node* init(int n){
    Node* t = NULL;
    for(int i = 1; i <= n; ++i){
        t = merge(t, new Node(i));
    }
    return t;
}

void clean(Node* t){
    if(!t) return;
    clean(t->lc);
    clean(t->rc);
    delete t;
}

void inOrder(Node* t){
    if(!t) return;
    push(t);
    inOrder(t->lc);
    cout << t->id << " ";
    inOrder(t->rc);
}

int main(){
    AC
    int n, m, p, q;
    Node *root, *a, *b, *c;
    while(cin >> n >> m){
        root = init(n);
        while(m--){
            cin >> p >> q;
            split(root, b, c, q);
            split(b, a, b, p-1);
            b->tag = 1;
            merge(merge(a, b), c);
        }
        inOrder(root);
        cout << endl;
        clean(root);
    }
}