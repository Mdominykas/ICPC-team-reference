vector<vector<pii> > roundRobin(int n)
{
  if(n % 2 == 0)
  {
    vector<vector<pii> > partial = roundRobin(n-1);
    for(int i = 0; i < n - 1; ++i)
      partial[i].push_back(make_pair(i, n - 1));
    return partial;
  }
  vector<vector<pii> > answer(n, vector<pair<int, int>>());
  for(int i = 0; i < n; i++)
  {
    for(int j = 1; 2 * j < n; j++)
    {
      int a = (i - j), b = i + j;
      if(a < 0)
        a += n;
      if(b >= n)
        b -= n;
      answer[i].push_back(make_pair(a, b));
    }
  }
  return answer;
}
