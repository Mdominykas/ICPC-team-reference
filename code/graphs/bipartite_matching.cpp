#include <bits/stdc++.h>

#define mp make_pair
using namespace std;

const int maxN = 1e6;
// HopCroft Karp algorithm
// abi puses numeruojamos nuo 0.
// Kaires dydis - |U|, desines - |V|
vii bipartiteMatching(vii edgeList, int U, int V)
{
  vector<int> pairFromU(U, -1), pairFromV(V, -1);
  int d[U];
  vector<int> adjU[U];
  for(auto e : edgeList)
    adjU[e.first].push_back(e.second);

  while(true)
  {
    const int INF = 1e9;
    int minDist = INF;
    for(int i = 0; i < U; i++)
      d[i] = minDist;
    queue<int> q;
    for(int i = 0; i < U; i++)
    {
      if(pairFromU[i] == -1)
      {
        d[i] = 0;
        q.push(i);
      }
    }

    while(!q.empty())
    {
      int g = q.front();
      q.pop();
      for(int v : adjU[g])
      {
        if(pairFromV[v] == -1)
          minDist = min(minDist, d[g]);
        else if(d[pairFromV[v]] > d[g] + 1)
        {
          d[pairFromV[v]] = d[g] + 1;
          q.push(pairFromV[v]);
        }
      }
    }
    if(minDist == INF)
      break;

    bool visited[U] = {};

    function<bool(int)> dfs = [&](int u)
    {
      if(visited[u])
        return false;
      visited[u] = true;
      for(int v : adjU[u])
      {
        if(pairFromV[v] == -1)
        {
          pairFromV[v] = u;
          pairFromU[u] = v;
          return true;
        }
        else if ((d[pairFromV[v]] == d[u] + 1)
         && (dfs(pairFromV[v])))
        {
          pairFromU[u] = v;
          pairFromV[v] = u;
          return true;
        }
      }
      return false;
    };


    for(int i = 0; i < U; i++)
    {
      if(pairFromU[i] == -1)
        dfs(i);
    }
  }

  vii ans;
  for(int i = 0; i < V; i++)
  {
    if(pairFromV[i] != -1)
      ans.push_back(mp(pairFromV[i], i));
  }
  return ans;
}
