class Solution {
public:
    string removeDuplicates(string s) {
        string c="";
        for(auto a:s){
            if(c !="" && c.back() == a){
                c.pop_back();
                continue;
            }
            c.push_back(a);
            
        }
        return c;        
    }
};