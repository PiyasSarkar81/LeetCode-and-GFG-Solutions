class Solution {
public:
    void addSpace(int i, int spaceCnt, int maxWidth, bool is_last, string *s){
        if(i<spaceCnt){
            int space = is_last ? 1 : maxWidth / spaceCnt + (i<maxWidth%spaceCnt);
            s->append(space,' ');
        }
    }
    string connect(vector<string>& words, int maxWidth,int begin, int end, int len, bool islast){
        string s;
        int n = end - begin;
        for(int i=0;i<n;i++){
            s += words[begin+i];
            addSpace(i,n-1,maxWidth-len,islast,&s);
        }
        if(s.size()<maxWidth){
            s.append(maxWidth-s.size(),' ');
        }
        return s;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        int begin =0,len =0;
        for(int i=0;i<n;i++){
            if(len+words[i].size()+(i-begin) > maxWidth){
                ans.push_back(connect(words,maxWidth,begin,i,len,false));
                begin =i;
                len =0;
            }
            len += words[i].size();
        }
        ans.push_back(connect(words,maxWidth,begin,n,len,true));
        return ans;
    }
};