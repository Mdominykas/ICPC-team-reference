#include<bits/stdc++.h>
void find(int a, int b)
{
  const int max_log_a = 50;
  int r[max_log_a], s[max_log_a], t[max_log_a];
  r[0] = a;
  r[1] = b;
  s[0] = 1;
  s[1] = 0;
  t[0] = 0;
  t[1] = 1;
  int k = 1;
  for(int i=2; i<max_log_a; i++)
  {
    if(r[i-1]==0)
      break;
    k = i-1;
    int q = r[i-2]/r[i-1];
    s[i] = s[i-2] - q*s[i-1];
    t[i] = t[i-2] - q*t[i-1];
    r[i] = r[i-2] - q*r[i-1];
  }
  assert(s[k] * a + t[k] * b == r[k]);
  assert(r[k] == __gcd(a, b));
}