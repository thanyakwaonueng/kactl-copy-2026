/**
 * Author: Tanya
 * Description: before k-th phase d[i][j] = stp len from i to j using only vertices from set {1,2,...k-1} as internal path, the beginning and end of path are not restricted by this property.
 */
//don't forget to initialize the base case of weight 
//this work for negative weight without negative cycle
for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (d[i][k] < INF && d[k][j] < INF)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
        }
    }
}
