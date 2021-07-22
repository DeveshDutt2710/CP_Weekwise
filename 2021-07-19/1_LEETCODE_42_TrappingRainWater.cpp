
https://leetcode.com/problems/trapping-rain-water/
42_TrappingRainWater


class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0; 
        int res = 0;
        
        stack<int> path;   
        for(int i=0; i<height.size(); i++) {
            while(!path.empty() && height[i] > height[path.top()]) {
                int concaveIdx = path.top();
                path.pop();
                
                if(path.empty()) break; 
                int leftIdx = path.top();
                int concaveWidth = i - leftIdx - 1;
                int rainDepth = min(height[i], height[leftIdx]) - height[concaveIdx];
                res += rainDepth*concaveWidth;
            }
            path.push(i);
        }
        return res;
    }
};


class Solution {
public:
    int trap(vector<int>& arr) {
     
    int n=arr.size();
        
    if(n==0) return 0;
        
    int lmax[n],rmax[n];
    
    lmax[0]=arr[0];
    rmax[n-1]=arr[n-1];
    
    int res=0;
    
    for(int i=1;i<n;i++)
        lmax[i]=max(lmax[i-1],arr[i]);
    
    for(int i=n-2;i>=0;i--)
        rmax[i]=max(arr[i],rmax[i+1]);
    
    for(int i=1;i<n-1;i++)
        res+=min(lmax[i],rmax[i])-arr[i];
        
    return res;
    }
};
