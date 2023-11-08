class Solution {
public:
    string addBinary(string a, string b) {
        int carry=0;
        int i=0;
        string ans="";
        int alen=a.size();
        int blen=b.size();
        
        while(i<alen || i<blen || carry!=0){
            int x=0;
            if(i<alen && a[alen-i-1]=='1')
                x=1;
            int y=0;
            if(i<blen && b[blen-i-1]=='1')
                y=1;
            
            int sum=x+y+carry;
            int val=sum%2;
            carry=sum/2;
            i++;
            ans=to_string(val)+ans;
        }
    return ans;
    
    }
};