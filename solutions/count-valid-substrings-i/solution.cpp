class Solution {
public:
    long long countValidSubstrings(string s) {
        int n=s.size();
        int left=0;
        long long ans=0;
        for(int right=0;right<n;right++){
            if(right>=2 && s[right-2]=='a' && s[right-1]=='b' && s[right]=='c'){
                left=right-1;
            }
            ans += right-left+1;
        }
        return ans;
    }
};