int findBridges(int v, int par)
{
  visited[v] = true;
  int highest = depth[v];
  for(int u : adj[v])
  {
    if(!visited[u])
    {
      depth[u] = depth[v] + 1;
      int high = findBridges(u, v);
      if(high > depth[v])
        bridges.push_back(mp(u, v));
      highest = min(highest, high);
    }
    else if (u != par)
      highest = min(highest, depth[u]);
  }
  return highest;
}
