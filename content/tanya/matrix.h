/**
 * Author: Tanya
 * Description: Nothing to says
 */
struct Matrix {
    vector<vector<long long>> a;
    int rows, cols;
 
    Matrix(int r, int c, int val) : rows(r), cols(c), a(r, vector<long long>(c, val)) {}
 
    Matrix operator *(const Matrix& other) {
        Matrix product(rows, other.cols, 0);
 
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    product.a[i][j] += a[i][k] * other.a[k][j] % INF;
                    product.a[i][j] %= INF;
                }
            }
        }
        return product;
    }
};
 
Matrix expo_power(Matrix a, long long n, int size){//note n=1 is equal do nothing,n=2is do once 
    Matrix product(size,size,0);
    for(int i=0;i<size;++i)product.a[i][i]=1;
    while(n>0){
        if(n&1){
            product = product * a;
        }
        a = a * a;
        n>>=1;
    }
    return product;
}
