#include <iostream>
using namespace std;



int find(int x) {
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}