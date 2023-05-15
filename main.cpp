#include <iostream>
using namespace std;

/**
 * Метод прогонки
 * n - число уравнений (строк матрицы)
 * C - диагональ, лежащая над главной (нумеруется: [0;n-2])
 * B - главная диагональ матрицы A (нумеруется: [0;n-1])
 * A - диагональ, лежащая под главной (нумеруется: [1;n-1])
 * F - правая часть (столбец)
 * res - решение, массив x будет содержать ответ
 */
void solveMatrix(int n, double * A, double * B, double * C, double * F, double * res)
{
    double temp;
    for (int i = 1; i < n; i++)
    {
        temp = A[i] / B[i - 1];
        
        B[i] = B[i] - temp * C[i - 1];
        
        F[i] = F[i] - temp * F[i - 1];
        
    }

    res[n - 1] = F[n - 1] / B[n - 1];
    
 
    
    for (int i = n - 2; i >= 0; i--)
    {
        res[i] = (F[i] - C[i] * res[i + 1]) / B[i];
    }
    
}


int main() {

    // Пример
    int n = 3;
    double *b = new double[n];
    double *c = new double[n];
    double *a = new double[n];
    double *x = new double[n];
    double *f = new double[n];
    
    
    c[0] = 4;
    c[1] = 0;
    c[2] = 0;
    
    b[0] = 5;
    b[1] = 7;
    b[2] = 8;
    
    a[0] = 0;
    a[1] = 3;
    a[2] = 0;
    
    
    f[0] = 8;
    f[1] = 5;
    f[2] = 4;
    
    

    solveMatrix(n, a, b, c, f, x);
    
    for (int i = 0; i < n; i++) {
            cout << x[i] << endl;
        }

    system("pause");
    return 0;
}
