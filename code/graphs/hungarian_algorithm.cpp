int findMinAssignment(vector<vector<int> > C)
{
  int n = C.size(), m = C[0].size();
  // cout << "n, m = " << n << ", " << m << endl;
  assert(n <= m);
  int a[n + 1][m + 1];
  for(int i = 1; i <= n; i++)
  {
    for(int j = 1; j <= m; j++)
    {
      a[i][j] = C[i - 1][j - 1];
    }
  }
  const int INF = 1e9;

  vector<int> u(n + 1, 0), v(m + 1, 0), p(m + 1), way(m + 1);
  // p[i] - corresponding row for column i in matching
  for(int i = 1; i <= n; i++)
  {
    p[0] = i;
    int j0 = 0; // free column
    vector<int> minv(m + 1, INF);
    vector<bool> used(m + 1, false); // jau panaudotas paieskoje
    do
    {
      used[j0] = true;
      int i0 = p[j0], delta = INF, j1;
      for(int j = 1; j <= m; j++)
      {
        if(!used[j])
        {
          int cur = a[i0][j] - u[i0] - v[j];
          if(cur < minv[j])
          {
            minv[j] = cur;
            way[j] = j0;
          }
          if(minv[j] < delta)
          {
            delta = minv[j];
            j1 = j;
          }
        }
      }

      for(int j = 0; j <= m; j++)
      {
        if(used[j])
        {
          u[p[j]] += delta;
          v[j] -= delta;
        }
        else
          minv[j] -= delta;
      }

      j0 = j1;
    }
    while(p[j0] != 0);

    do
    {
      int j1 = way[j0];
      p[j0] = p[j1];
      j0 = j1;
    }
    while(j0);
  }
  
  int cost = -v[0];
  return cost;

}