template<typename T>
vector<T> dijkstra(int root,
  vector<vector<pair<int, T> > > &adj)
{
  int n = adj.size();
  vector<T> dist(n, INF);
  vector<bool> visited(n, false);
  dist[root] = 0;
  priority_queue<pair<T, int>, vector<pair<T, int> >,
    greater<pair<T, int> > > pq;
  pq.push(mp(dist[root], root));
  while(!pq.empty())
  {
    int g = pq.top().second;
    pq.pop();
    if(visited[g])
      continue;
    visited[g] = true;
    for(auto it : adj[g])
    {
      int v = it.first;
      if(dist[v] > dist[g] + it.second)
      {
        dist[v] = dist[g] + it.second;
        pq.push(mp(dist[v], v));
      }
    }
  }
  return dist;
}
