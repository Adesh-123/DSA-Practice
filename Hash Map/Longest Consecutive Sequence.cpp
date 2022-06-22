class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        map<int,int> m;
        int minele=INT_MAX,maxele=INT_MIN;
        for(int i=0;i<n;i++){
            minele=min(minele,nums[i]);
            maxele=max(maxele,nums[i]);
            m[nums[i]]++;
        }
        bool first=true;
        int k,prev;
        int ans=INT_MIN;
        for(auto j:m){
            if(first){
                first=false;
                k=j.first;
            }
            else if((j.first-prev)!=1){
                ans=max(ans,prev-k+1);
                k=j.first;
            }
            prev=j.first;
        }
        ans=max(ans,prev-k+1);
        return ans;
    }
};