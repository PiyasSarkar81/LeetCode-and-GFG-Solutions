class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n,0);
        int left = 0,leftCnt=0, right =0, rightCnt=0;
        for(int i=0;i<n;i++){
            if(boxes[i]=='1') {
                right += i;
                rightCnt++;
            }
        }
        if(boxes[0] =='1') rightCnt--;
        
        for(int i=0;i<n;i++){
            if(i !=0){
                if(boxes[i-1] == '1') leftCnt++;
                if(boxes[i] == '1'){
                    rightCnt--;
                    right--;
                }
                left += leftCnt;
                right -= rightCnt;
            }
            // cout<<right<<" "<<rightCnt<<" "<<left<<" "<<leftCnt<<endl;
            ans[i] = left + right;
        }
        return ans;

    }
};