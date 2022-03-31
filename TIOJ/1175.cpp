/*
 tag: LIS, DP, medium
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define AC ios::sync_with_stdio(0),cin.tie(0);
using namespace std;

int main(){
    int n;
    vector<int> arr, lis;
    scanf("%d\n", &n);
    arr.resize(n);
    for(int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    lis.push_back(arr[0]);
    for(int i = 1; i < n; ++i) {
        if(arr[i] > lis.back()) lis.push_back(arr[i]);
        else *(lower_bound(begin(lis), end(lis), arr[i])) = arr[i];
    }
    printf("%d", lis.size());
}