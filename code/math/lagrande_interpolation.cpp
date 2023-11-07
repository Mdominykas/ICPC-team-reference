ll lagrande(vector<ll> x, vector<ll> y, ll p)
{
  ll ans = 0;
  int n = x.size();
  for(int i = 0; i < n; i++)
  {
    ll part = y[i];
    for(int j = 0; j < n; j++)
    {
      if(j == i)
        continue;
      
      part *= (p - x[j]);
      part %= mod;

      part *= inverse(x[i] - x[j]);
      part %= mod;
      if(part < 0)
        part += mod;
      assert(part >= 0);
    }
    ans += part;
    ans %= mod;
  }
  return ans;
}
