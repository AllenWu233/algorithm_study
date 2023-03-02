#include <iostream>
using namespace std;

int cmp(const int i, const int j) { return w[i] < w[j]; }
int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
 