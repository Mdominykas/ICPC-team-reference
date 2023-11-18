ll modPow(ll a, ll n, ll mod)
{
  if(n == 0)
    return 1;
  else if (n % 2 == 0)
    return modPow((a * a) % mod, n / 2, mod);
  else
    return (a * modPow(a, n - 1, mod)) % mod;
}