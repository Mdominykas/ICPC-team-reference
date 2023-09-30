// in conjunctions: 2a means a is false, 2a + 1 means a is true
bool solve2Sat(int n, vector<pii> &conjuctions,
  vector<bool> &ans)
{
  vector<pair<int, int> > impl;
  for(auto it : conjuctions)
  {
    impl.push_back(mp(it.first ^ 1, it.second));
    impl.push_back(mp(it.second ^ 1, it.first));
  }

  auto components = scc(2 * n, impl);
  int number[2 * n];
  for(int i = 0; i < components.size(); i++)
  {
    for(int v : components[i])
      number[v] = i;
  }

  ans.clear();
  for(int i = 0; i < 2 * n; i += 2)
  {
    if(number[i] == number[i + 1])
    {
      ans.clear();
      return false;
    }
    else if (number[i] < number[i + 1])
      ans.push_back(true);
    else
      ans.push_back(false);
  }
  return true;
}
