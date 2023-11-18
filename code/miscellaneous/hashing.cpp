struct HashArray
{
  ll p, mod;
  vector<ll> prefixArray;
  HashArray(vector<int> s, ll p=15648, ll mod = 1e9 + 7) :
    p(p), mod(mod)
  {
    prefixArray.push_back(0);
    ll mul = 1;
    for(int i = 0; i < s.size(); i++)
    {
      prefixArray.push_back((prefixArray.back()
        + mul * ((long long) s[i])) % mod);
      mul *= p;
      mul %= mod;
    }
  }

  // 0-indexed hash of [l, r]
  ll getHash(int l, int r)
  {
    ll val = (prefixArray[r + 1] - prefixArray[l]
      + mod) % mod;
    ll shift = modPow(modPow(p, mod - 2, mod), l, mod);
    return (val * shift) % mod;
  }
};
