int findArticulationPoints(int v, int par)
{
  visited[v] = true;
  int highest = depth[v];
  int childs = 0;
  bool isolatedChild = false;
  for(int u : adj[v])
  {
    if(!visited[u])
    {
      depth[u] = depth[v] + 1;
      int high = findArticulationPoints(u, v);
      if(high >= depth[v])
        isolatedChild = true;
      highest = min(highest, high);      
      childs++;
    }
    else if (u != par)
    {
      highest = min(highest, depth[u]);
    }
  }

  if((childs > 1) && (isolatedChild))
    articulationPoints.push_back(v);
  else if ((childs == 1) && (isolatedChild) && (par != -1))
    articulationPoints.push_back(v);
  return highest;
}