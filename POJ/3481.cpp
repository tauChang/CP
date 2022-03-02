/*
 tag: Treap, medium
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
    Node *lc, *rc;
    int pri, v, id;
    Node(int _id, int _v): id(_id), v(_v) {
        pri = rand();
        lc = rc = NULL;
    }
};

Node* root = NULL;

void split(Node* t, Node*& a, Node*& b, int x){
    if(!t) {
        a = b = NULL;
        return;
    }
    if(t->v <= x) {
        a = t;
        split(t->rc, a->rc, b, x);
    } else{
        b = t;
        split(t->lc, a, b->lc, x);
    }
}

Node* merge(Node* a, Node* b){
    if(!a) return b;
    if(!b) return a;

    if(a->pri >= b->pri) {
        a->rc = merge(a->rc, b);
        return a;
    } else{
        b->lc = merge(a, b->lc);
        return b;
    }
}

void add(int id, int v) {
    Node *a, *b;
    split(root, a, b, v);
    root = merge(merge(a, new Node(id, v)), b);
}

void del(int v) {
    Node *a, *b, *c;
    split(root, a, b, v-1);
    split(b, b, c, v);
    root = merge(a, c);
    delete b;
}

Node* get(bool max){
    if(!root) return NULL;

    Node* t = root;
    if(max){
        while(t->rc) t = t->rc;
    } else{
        while(t->lc) t = t->lc;
    }
    return t;
}

int main(){
    AC
    int t, k, p;
    Node* x;
    while(1){
        cin >> t;
        if(!t) break;
        if(t == 1){
            cin >> k >> p;
            add(k, p);
        } else{
            x = get(t == 2);
            if(x){
                cout << x->id << endl;
                del(x->v);
            } else{
                cout << 0 << endl;
            }
        }
    }
}