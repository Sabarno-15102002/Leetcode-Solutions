class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<char> s;
        for(auto& e:sentence)
        {
            s.insert(e);
        }
        
        return s.size() == 26;
    }
};