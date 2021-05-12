/*
Tiling Problem

https://www.geeksforgeeks.org/tiling-problem/

Difficulty Level : Easy
Last Updated : 19 Dec, 2020
Given a “2 x n” board and tiles of size “2 x 1”, 
count the number of ways to tile the given board using the 2 x 1 tiles.
A tile can either be placed horizontally 
i.e., as a 1 x 2 tile or vertically i.e., as 2 x 1 tile. 

Examples: 

Input: n = 4

Output: 3

Explanation:



For a 2 x 4 board, there are 3 ways

All 4 vertical
All 4 horizontal
2 vertical and 2 horizontal
Input: n = 3

Output: 2

Explanation:

We need 2 tiles to tile the board of size  2 x 3.

We can tile the board using following ways

Place all 3 tiles vertically.
Place 1 tile vertically and remaining 2 tiles horizontally.

*/

#include <iostream>
using namespace std;

int tiling(int n)
{
    int t[n+1];
    t[0] = 0;
    t[1] = 1;
    t[2] = 2;
    
    for(int i=3;i<=n;i++)
    {
        t[i] = t[i-1] + t[i-2];
    }
    return t[n];
}

int main()
{
    cout<<tiling(2)<<endl;
    cout<<tiling(3)<<endl;
    cout<<tiling(4)<<endl;
    
    return 0;
}