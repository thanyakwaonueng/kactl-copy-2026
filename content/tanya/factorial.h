/**
 * Author: Tanya
 * Description: use 2*N when do stars and bars
 */
long long fac[N], faci[N];

long long bigmod(long long a, long long n){
    long long res = 1;
    while(n>0){
        if(n&1){
            res = res * a % MOD;
        }
        a = a * a % MOD;
        n>>=1;
    }
    return res;
}

void cal_fac(){
    fac[0] = 1;
    for(int i=1;i<N;++i) fac[i] = fac[i-1] * i % MOD;
    faci[N-1] = bigmod(fac[N-1], MOD-2);
    for(int i=N-2;i>=0;--i) faci[i] = faci[i+1] * (i+1) % MOD;
}
