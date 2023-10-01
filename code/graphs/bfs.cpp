void bfs(int root, vector<vi> &adj)
{
  int n = adj.size();
  bool visited[n] = {};
  queue<int> q;
  q.push(root);
  visited[root] = true;
  while(!q.empty())
  {
    int g = q.front();
    q.pop();
    for(int v : adj[g])
    {
      if(!visited[v])
      {
        visited[v] = true;
        q.push(v);
      }
    }
  }
}