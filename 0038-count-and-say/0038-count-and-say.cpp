class Solution {
public:
    string countAndSay(int n) {
        int i=1,count=0,j,k;
        string s="1",a;
        if(n==1)
            return "1";
        else{
            while(i!=n){
                i++;
                count=0;
                k=0;
                for(j=0;j<s.size();j++){
                    if(s[j]==s[k])
                        count++;
                    else if(s[j]!=s[k]){
                        a+=to_string(count)+s[k];
                        count=1;
                        k=j;
                    } 
                }
                a+=to_string(count)+s[k];
                s=a;
                a.clear();
            }
        }
        return s;
    }
};