/**
 * Author: Tanya
 * Description: both work in O(3**n)
 */
for (int s = 0; s < (1<<n); s++) {
    for (int t = s; t < (1<<n); t = (t+1)|s) {
        // t is a superset of s
    }
}

for (int s = 0; s < (1<<n); s++) {
    for (int t = s; ; t = (t-1)&s) {
        // t is a subset of s
        if (t == 0) break;
    }
}
