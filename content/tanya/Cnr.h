/**
 * Author: Tanya
 * Description: this is ok
 */
long long Cnr(int n, int k) {
    if(k<0 || n<k)return 0;
    if(k==0 or n==k)return 1;
    /*
    double res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (long long)(res + 0.01);
    */
    return fac[n] * faci[k] % MOD * faci[n-k] % MOD;
}
