
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        map<int,int> m;
        int sum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            sum+=A[i];
            if(sum==0) ans=max(ans,i+1);
            if(m.find(sum)!=m.end()){
                ans=max(ans,i-m[sum]);
            }
            else if(m.find(sum)==m.end()){
                m[sum]=i;
            }
        }
        if(sum==0) return n;
        // for(auto j:m) cout<<j.first<<" "<<j.second<<endl;
        return ans;
    }
};
