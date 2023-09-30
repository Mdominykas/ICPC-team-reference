vector<vi> scc(int n, vector<pair<int, int> > edgeList)
{
  vector<int> adj[n], rAdj[n];
  for(auto it : edgeList)
  {
    adj[it.first].push_back(it.second);
    rAdj[it.second].push_back(it.first);
  }

  bool visited[n] = {};
  vi order, current;
  function<void(int)> dfs1 = [&](int v) {
    visited[v] = true;
    for(int u : adj[v])
    {
      if(!visited[u])
        dfs1(u);
    }
    order.push_back(v);
  };

  function<void(int)> dfs2 = [&](int v){
    visited[v] = true;
    for(int u : rAdj[v])
    {
      if(!visited[u])
        dfs2(u);
    }
    current.push_back(v);
  };
  for(int i = 0; i < n; i++)
  {
    if(!visited[i])
      dfs1(i);
  }
  reverse(order.begin(), order.end());
  for(int i = 0; i < n; i++)
    visited[i] = false;
  vector<vi> ans;
  for(int v : order)
  {
    if(!visited[v])
    {
      current.clear();
      dfs2(v);
      ans.push_back(current);
    }
  }

  return ans;
}
