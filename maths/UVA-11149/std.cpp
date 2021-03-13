#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
 
using namespace std;
 
class matrix
{
	private:
		int data[41][41];
	public:
		matrix(){}
		matrix(int n) {
			for (int i = 0; i < n; ++ i)
			for (int j = 0; j < n; ++ j) {
				scanf("%d",&data[i][j]);
				data[i][j] %= 10;
			}
		}
		void show(int n) {
			for (int i = 0; i < n; ++ i)
			for (int j = 0; j < n; ++ j) {
				printf("%d",data[i][j]);
				if (j == n-1) printf("\n");
				else printf(" ");
			}printf("\n");
		}
		friend matrix E(matrix mat, int n);
		friend matrix add(matrix A, matrix B, int n);
		friend matrix mul(matrix A, matrix B, int n);
		friend matrix qpow(matrix mat, int k);
		friend matrix spow(matrix mat, int k);
};
//单位矩阵 
matrix E(matrix mat, int n) 
{
	for (int i = 0; i < n; ++ i)
	for (int j = 0; j < n; ++ j)
		mat.data[i][j] = (i==j);
	return mat;
}
//矩阵加法 
matrix add(matrix A, matrix B, int n)
{
	matrix C;
	for (int i = 0 ; i < n; ++ i)
		for (int j = 0 ; j < n; ++ j)
			C.data[i][j] = (A.data[i][j]+B.data[i][j])%10;
	return C;
}
//矩阵乘法 
matrix mul(matrix A, matrix B, int n)
{
	matrix C;
	for (int i = 0 ; i < n ; ++ i)
		for (int j = 0 ; j < n ; ++ j) {
			C.data[i][j] = 0;
			for (int k = 0 ; k < n ; ++ k)
				C.data[i][j] = (C.data[i][j]+A.data[i][k]*B.data[k][j])%10;
	}
	return C;
}
//矩阵快速幂 
matrix qpow(matrix mat, int k, int n)
{
	if (k == 1) return mat;
	matrix now = qpow(mat, k/2, n);
	if (k%2 == 0) return mul(now, now, n);
	return mul(mul(now, now, n), mat, n);
}
//矩阵快速幂和 
matrix spow(matrix mat, int k, int n)
{
	if (k == 1) return mat;
	matrix A = spow(mat, k/2, n);
	matrix B = add(qpow(mat, k/2, n), E(mat, n), n);
	if (k%2 == 0) return mul(A, B, n);
	else return add(mul(A, B, n), qpow(mat, k, n), n);
}
 
int main()
{
    #ifdef D
    freopen("UVA-11149.in", "r", stdin);
    freopen("out", "w", stdout);
    clock_t TIMEA = clock();
#endif
	int n,k;
	while (cin >> n >> k && n)
		spow(matrix(n), k, n).show(n);

#ifdef D
    clock_t TIMEB=clock();
    printf("\n# Time consumed: %.3fs.\n", (float)(TIMEB-TIMEA)/CLOCKS_PER_SEC);
#endif
    return 0;
}