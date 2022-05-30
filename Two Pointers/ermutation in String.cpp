class Solution {
public:
    bool checkfrequencies(vector<int> &freq1,vector<int> &freq2){
        for(int i=0;i<26;i++){
            if(freq1[i]!=freq2[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        for(int i=0;i<s1.size();i++){
            freq1[s1[i]-'a']++;
        }
        
        int i=0,j=0;
        while(j<s2.size()){
            freq2[s2[j]-'a']++;
            
            if(j-i+1<s1.size()){
                j++;
            }
            else if(j-i+1==s1.size()){
                if(checkfrequencies(freq1,freq2)) return true;
                freq2[s2[i]-'a']--;
                i++,j++;
            }
        }
        return false;
    }
};