/*
https://leetcode.com/problems/find-the-town-judge/

997_FindtheTownJudge

In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi.

Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.
*/



class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
		if(trust.empty() && n==1)
            return 1;
        
		vector<int> out(n+1,0);
        
		vector<int> in(n+1,0);
        
		for(auto edge : trust){
            out[edge[0]]++;
            in[edge[1]]++;
        }
        
		for(int i=0;i<=n;i++){
            if(out[i]==0 && in[i]==n-1)
                return i;
        }

        return -1;
    }
};