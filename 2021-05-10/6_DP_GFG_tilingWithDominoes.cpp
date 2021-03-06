/*
Given a 3 x n board, find the number of ways to fill it with 2 x 1 dominoes.

https://www.geeksforgeeks.org/tiling-with-dominoes/

*/


#include <iostream>
using namespace std;
  
int countWays(int n)
{
    int A[n + 1], B[n + 1];
    A[0] = 1, A[1] = 0, B[0] = 0, B[1] = 1;
    for (int i = 2; i <= n; i++) {
        A[i] = A[i - 2] + 2 * B[i - 1];
        B[i] = A[i - 1] + B[i - 2];
    }
  
    return A[n];
}
  
int main()
{
    int n = 8;
    cout << countWays(n);
    return 0;
}