/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int l =0,r=mountainArr.length()-1,mid;
        
        // find peak
        while(l<r){
            mid = l+(r-l)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)) l= mid+1;
            else r = mid;
        }
        int peak = l;

        // BS on left half
        l=0,r=peak;
        while(l<=r){
            mid = l+(r-l)/2;
            if(mountainArr.get(mid)==target){
                return mid;
            }
            else if(mountainArr.get(mid) < target) l = mid+1;
            else r = mid - 1;
        }

        // BS on right half
        l = peak+1, r = mountainArr.length()-1;
        while(l<=r){
            mid = l+(r-l)/2;
            if(mountainArr.get(mid)==target) return mid;
            else if(mountainArr.get(mid) > target) l = mid+1;
            else r = mid -1;
        }
        return -1;
    }
};