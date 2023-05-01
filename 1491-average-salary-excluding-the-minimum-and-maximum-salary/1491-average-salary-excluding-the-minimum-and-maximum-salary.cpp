class Solution {
public:
    double average(vector<int>& salary) {
        int maxi = *max_element(salary.begin(),salary.end());
        int mini = *min_element(salary.begin(),salary.end());
        long sum=0;
        int cnt =0;
        for(auto s: salary){
            if(s != maxi && s != mini){
                sum += s;
            }
            else{
                cnt++;
            }
        }
        double avg = (double)sum/(salary.size()-cnt);
        return avg;
    }
};