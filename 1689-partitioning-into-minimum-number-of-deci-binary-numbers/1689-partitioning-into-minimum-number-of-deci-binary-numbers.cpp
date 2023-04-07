class Solution {
public:
    int minPartitions(string n) {
        char mini = '1';
        for(int i=0;i<n.size();i++){
            if(n[i]>mini) mini = n[i];
        }
        return mini-'0';
    }
};