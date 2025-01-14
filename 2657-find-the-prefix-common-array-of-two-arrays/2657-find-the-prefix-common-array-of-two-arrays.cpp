class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(), cnt = 0;
        vector<int> C(n,0);
        unordered_map<int,int> mpa, mpb;
        for(int i=0;i<n;i++){
            if(A[i] == B[i]) cnt++;
            else {
                if(mpa.find(B[i]) != mpa.end()){
                    if(mpb.count(B[i]) && mpb[B[i]] < mpa[B[i]]) cnt++;
                    else if(mpb.find(B[i]) == mpb.end()) cnt++;
                }
                if(mpb.find(A[i]) != mpb.end()){
                    if(mpa.count(A[i]) && mpa[A[i]] < mpb[A[i]]) cnt++;
                    else if(mpa.find(A[i]) == mpa.end()) cnt++;
                }
            }
            C[i] = cnt;
            mpa[A[i]]++;
            mpb[B[i]]++;

        }
        return C;
    }
};