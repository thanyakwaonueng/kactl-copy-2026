/**
 * Author: Tanya
 * Description: for large n and small modulo, the complexity is O(p * log-p(n)), p must be prime
 */
// Standard nCr modulo p for small n and r
long long nCr_small(long long n, long long r, int p) {
    if (r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n / 2) r = n - r;

    long long num = 1, den = 1;
    for (int i = 0; i < r; ++i) {
        num = (num * (n - i)) % p;
        den = (den * (i + 1)) % p;
    }

    // Modular inverse using Fermat's Little Theorem (den^(p-2) % p)
    auto power = [&](long long base, long long exp) {
        long long res = 1;
        base %= p;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % p;
            base = (base * base) % p;
            exp /= 2;
        }
        return res;
    };

    return (num * power(den, p - 2)) % p;
}

// Lucas Theorem Implementation
long long lucas(long long n, long long k, int p) {
    // Base cases
    if (k == 0) return 1;
    if (n < k) return 0;

    // Recursive step: nCr % p = ( (n/p)C(k/p) * (n%p)C(k%p) ) % p
    return (lucas(n / p, k / p, p) * nCr_small(n % p, k % p, p)) % p;
}
