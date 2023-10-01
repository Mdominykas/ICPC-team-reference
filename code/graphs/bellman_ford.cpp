template<typename T>
vector<T> bellmanFord(int n,
  vector<pair<pair<int, int>, T> > &edgeList)
{
  vector<T> dist(n, INF);
  dist[0] = 0;
  for(int i = 0; i < n; i++)
  {
    for(auto e : edgeList)
    {
      int u = e.first.first, v = e.first.second;
      if((dist[u] < INF) && (dist[v] > dist[u] + e.second))
        dist[v] = dist[u] + e.second;
    }
  }
  return dist;
}