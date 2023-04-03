class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int j = people.size()-1;
        int cnt =0;
        int i =0;
        sort(people.begin(),people.end());
        while(i<=j){
            if(people[i]+people[j] <= limit){
                i++;
                j--;
            }
            else{
                j--;
            }
            cnt++;
        }
        
        return cnt;
        
    }
};