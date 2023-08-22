class Solution {
public:
    string convertToTitle(int num) {
        string s="";
        while(num>0){
            num=num-1;
            char c='A'+num%26;
            s=s+c;
            num=num/26;
        }reverse(s.begin(),s.end());
        return s;
    }
};