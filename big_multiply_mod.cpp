//This function computes (a*b)%m when a and b are of the order 10^18 witthout causing overflow


long long big_multiply(long long a, long long b, long long m){
  a %= m;
  b %= m;

  long long res = 0;
  while(b > 0){
    if(b & 1) res = (res + a) % m;
    a = (a + a) % m;
    b >>= 1;
  }
  return res;
}
