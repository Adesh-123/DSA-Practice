class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int sum ;
        sort(nums.begin(),nums.end());
        if(nums.size()<4)  return {};
        for(int i=0;i<nums.size()-3;i++){
            if(i==0 || nums[i]!=nums[i-1]){
            for(int j=i+1;j<nums.size()-2;j++){
                int k=j+1;
                int z=nums.size()-1;
                if(j==i+1  || nums[j]!=nums[j-1]){
                    while(k<z){
                      sum=nums[i]+nums[j]+nums[k]+nums[z];
                      if(sum==target){
                          result.push_back({nums[i],nums[j],nums[k],nums[z]});
                          while(k<z && nums[k]==nums[k+1]) k++;
                          while(k<z && nums[z]==nums[z-1]) z--;
                          k++,z--;
                        }
                      else if(sum>target) z--;
                      else k++;
                      
                    }
                }
            }
            }
        }
        return result;
    }
};