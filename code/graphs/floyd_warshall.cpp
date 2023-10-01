// d - adjacency matrix with d[i][i] = 0
vector<vector<ll> > floydWarshall(vector<vector<ll> > d)
{
  int n = d.size();
  auto ans = d;
  for(int k = 0; k < n; k++)
  {
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < n; j++)
      {
        ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);
      }
    }
  }
  return ans;
