class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0) return 0;
        vector<int> lastoccur(256,-1);
        int ans=INT_MIN;
        int start=0,end=0;
        while(end<n){
            start=max(start,lastoccur[s[end]]+1);
            
            ans=max(ans,end-start+1);
            lastoccur[s[end]]=end;
            end++;
        }
        return ans;
    }
};