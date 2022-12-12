#include <iostream>
using namespace std;
 
int kth(int X[], int b, int n, int Y[], int c, int m, int k )
{
    // In case we have reached end of array 1
    if (b == n)
        return Y[c + k - 1];
 
    // In case we have reached end of array 2
    if (c == m)
        return X[b + k - 1];
 
    // k should never reach 0 or exceed sizes
    // of arrays
    if (k == 0 || k > (n - b) + (m - c))
        return -1;
 
    // Compare first elements of arrays and return
    if (k == 1)
        return (X[b] < Y[c]) ?
            X[b] : Y[c];
    int atual = k / 2;
 
    // Size of array 1 is less than k / 2
    if (atual - 1 >= n - b)
    {
        // Last element of array 1 is not kth
        // We can directly return the (k - n)th
        // element in array 2
        if (X[n - 1] < Y[c + atual - 1])
            return Y[c + (k - (n - b) - 1)];
        else
            return kth(X, b, n, Y, c + atual, m, k - atual);
    }
 
    // Size of array 2 is less than k / 2
    if (atual-1 >= m-c)
    {
        if (Y[m - 1] < X[b + atual - 1])
            return X[b + (k - (m - c) - 1)];
        else
            return kth(X, b + atual, n, Y, c, m, k - atual
                 );
    }
    else
    {
        // Normal comparison, move starting index
        // of one array k / 2 to the right
        if (X[atual + b - 1] < Y[atual + c - 1])
            return kth(X,  b + atual, n, Y, c, m, k - atual);
        else
            return kth(X,b,n, Y,c + atual,  m, k - atual);
    }
}
 
// Driver code
int main()
{
    int X[5] = {2, 3, 6, 7, 9};
    int Y[4] = {1, 4, 8, 10};
 
    int k = 4;
    cout << kth(X, 0, 5, Y, 0, 4,  k) << "\n";
    return 0;
}
