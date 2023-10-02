#include<bits/stdc++.h>
using namespace std;
const int max_N = 1000003;
const int logn = 22;
int lookup[max_N][logn];
int loga[max_N];
void buildsparsetable(int N, int a[])
{
  for(int i = 0; i < N; i++)
    lookup[i][0] = a[i];
  for(int j = 1; j < logn; j++)
  {
    for(int i = 0; i + (1<<j) <= N; i++)
      lookup[i][j] = min(lookup[i][j - 1], 
        lookup[i + (1<<(j - 1))][j - 1]);
  }
  loga[1] = 0;
  for(int i = 2; i <= N; i++)
    loga[i] = loga[i / 2] + 1;
}

int query(int L, int R)
{
  int sk = loga[R - L + 1];
  return min(lookup[L][sk], lookup[R - (1<<sk) + 1][sk]);
}