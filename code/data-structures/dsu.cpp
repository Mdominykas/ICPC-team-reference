struct DSU
{
  int *parent;
  DSU(int n)
  {
    parent = new int [n+1];
    for(int i=0; i<=n; i++)
      parent[i] = i;
  }

  int findSet(int id)
  {
    if(parent[id]==id)
      return id;
    else
      return parent[id] = findSet(parent[id]);
  }

  void unionSets(int i, int j)
  {
    if(findSet(i)==findSet(j))
      return;
    else
      parent[findSet(i)] = findSet(j);
  }
};


int main()
{
  int n;
  cin >> n;
  DSU naujas(n);
  return 0;
}