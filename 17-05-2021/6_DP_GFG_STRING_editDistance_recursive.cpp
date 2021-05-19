/*

https://www.geeksforgeeks.org/edit-distance-dp-5/

Given two strings str1 and str2 and below operations that can performed on str1.
Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.  


Insert
Remove
Replace
All of the above operations are of equal cost. 

*/

#include <bits/stdc++.h>
using namespace std;

int min(int x, int y, int z)
{
    return min(min(x,y),z);
}

int editDistance(string str1, string str2, int m, int n)
{
    if(m==0)
    {
        return n;
    }
    if(n==0)
    {
        return m;
    }
    
    if(str1[m-1] == str2[n-1])
    {
        return editDistance(str1, str2, m-1, n-1);
    }
    return 1 + min(editDistance(str1, str2, m, n-1),
                   editDistance(str1, str2,m-1,n),
                   editDistance(str1, str2, m-1, n-1));
}

int main()
{
    string str1 = "sunday";
    string str2 = "saturday";
 
    cout << editDistance(str1, str2, str1.length(),
                     str2.length());
 
    return 0;
}