vector<int> prefixFunction(string s)
{
  int n = s.size();
  vector<int> p;
  p.push_back(0);
  for(int i = 1; i < n; i++)
  {
    int j = p[i - 1];
    while((j > 0) && (s[j] != s[i]))
      j = p[j - 1];
    if(s[i] == s[j])
      j++;
    p.push_back(j);
  }
  return p;
}
