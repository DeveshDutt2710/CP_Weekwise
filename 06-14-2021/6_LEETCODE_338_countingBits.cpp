
/*


338. Counting Bits

Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

 

Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
 

Constraints:

0 <= n <= 105
*/

class Solution {
public:
    int countTotal(int n)
    {
        int count = 0;
        while(n)
        {
            if(n%2 != 0)
            {
                count++;
                n /= 2;
            }
            else
            {
                n /= 2;
            }
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> listFinal;
        
        for(int i = 0;i<=n;i++)
        {
            listFinal.push_back(countTotal(i));
        }
        
        return listFinal;
        
    }
};





class Solution {
public:
    vector<int> countBits(int num) 
    {
        if(num == 0)
            return {0};
        vector<int> res(num + 1, 0);

        res[0] = 0;
        res[1] = 1;

        for(int i = 2; i <= num; i++)
            res[i] = res[i / 2] + i % 2;

        return res;
    }
};