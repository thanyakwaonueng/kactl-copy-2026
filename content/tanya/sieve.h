/**
 * Author: Tanya
 * Description: construct is O(sqrt(n)), can use to find all prime factor of a number in O(log n)
 */
vector<bool> is_prime(M+1, true);
void sieve(){
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= M; i++) {
        if (is_prime[i]) {
            for (ll j = (ll)i * i; j <= M; j += i)
                is_prime[j] = false;
        }
    }
}
