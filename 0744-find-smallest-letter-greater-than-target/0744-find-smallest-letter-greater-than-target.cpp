class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int l = 0, r=n-1;
        char ans = letters[0];
        while(l<=r){
            int mid = (l+r)>>1;
            if(letters[mid]>target && mid == 0){
                ans = letters[0];
                break;
            }
            if(letters[mid]>target){
                ans = letters[mid];
                r = mid - 1;
            } else l = mid + 1;

        }
        return ans;
    }
};