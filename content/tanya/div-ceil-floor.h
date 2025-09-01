/**
 * Author: Tanya
 * Description: to stop c++ fucked up negative case of ceil, floor
 */

long long div_floor(__int128 a, long long b){
    __int128 q = a / b;
    __int128 r = a % b;
    if (r != 0 && ((a < 0) != (b < 0))) --q;
    return (long long)q;
}
long long div_ceil(__int128 a, long long b){
    return -div_floor(-a, b);
}
