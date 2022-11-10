class Solution {
public:
    string removeDuplicates(string s) {
        string str;
        for(const char c: s){
            if(str.empty()){
                str.push_back(c);
            }
            else if(str.back() == c){
                str.pop_back();
            }
            else{
                str.push_back(c);
            }
        }
        return str;
    }
};