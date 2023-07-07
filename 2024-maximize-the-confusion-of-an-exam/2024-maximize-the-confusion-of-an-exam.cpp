class Solution {
public:

    int count(string s, int k, char ch){
        int n = s.size();
        int i=0,j=0, bad =0, maxlen=0;
        while(j<n){
            if(s[j]!=ch) bad++;
            while(i<=j && bad>k){
                char curr = s[i];
                if(curr!=ch) bad--;
                i++;
            }
            maxlen = max(maxlen,j-i+1);
            j++;
        }
        return maxlen;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(count(answerKey,k, 'T'),count( answerKey, k, 'F'));
    }
};