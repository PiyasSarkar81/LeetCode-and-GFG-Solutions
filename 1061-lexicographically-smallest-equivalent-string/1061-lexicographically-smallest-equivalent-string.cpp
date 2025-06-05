class Solution {
    int parent[26];
public:
    int findPar(int x){
        if(parent[x] == -1) return x;
        return parent[x] = findPar(parent[x]);
    }

    void Union(int x, int y){
        x = findPar(x);
        y = findPar(y);

        if(x != y) parent[max(x,y)] = min(x,y);
    }


    string smallestEquivalentString(string s1, string s2, string baseStr) {
        memset(parent, -1, sizeof(parent));
        
        for(int i=0;i<s1.size();i++){
            Union(s1[i]-'a', s2[i]-'a');
        }
        for(int i=0;i<baseStr.size();i++){
            baseStr[i] = findPar(baseStr[i]-'a') + 'a';
        }
        return baseStr;
    }
};