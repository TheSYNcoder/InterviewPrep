class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int len = (len1 + len2);
        if(len1 == 0 || len2 == 0){
            vector<int> temp;
          if(len1 != 0){
             temp = nums1; 
          } 
            else{
                temp = nums2;
            }
            int sz = temp.size();
            if(sz%2 == 1){
                return temp[sz/2];
            }
            else{
                return (temp[sz/2] + temp[sz/2 - 1] + 0.0)/2;
            }
        }
        int totallen ;
        int maxi = len/2 + 1;
        int mini = 0;
        totallen = maxi;
        while(mini <= maxi){
            int midi = (mini + maxi)/2;
            int midj = totallen - midi;
             if(midi > len1){
               midi = len1;
               midj = totallen - midi;
            }
            else if(midj > len2){
                midj = len2;
                midi = totallen - midj;
            }

            int ele1, ele2;
            if(midi != 0)
                 ele1 = nums1[midi - 1];
            if(midj != 0)
                 ele2 = nums2[midj - 1];
            if(midi < len1 && midj != 0){
                if(ele2 > nums1[midi]){
                    mini = midi + 1;
                    continue;
                }
            }
            if(midj < len2 && midi != 0){
                if(ele1 > nums2[midj]){
                    maxi = midi - 1;
                    continue;
                }
            }
            
                if(len%2 == 1){
                    if(midi == 0){
                        return ele2;
                    }
                    else if(midj == 0){
                       return ele1; 
                    }
                    return max(ele1, ele2);
                }
                else{
                    if(midi == 0){
                        return (ele2 + 0.0 + nums2[midj - 2])/2;
                    }
                    else if(midj == 0){
                        return (ele1 + 0.0 + nums1[midi - 2])/2;
                    }
                   int max1 = max(ele1, ele2);
                    int max2 = min(ele1, ele2);
                    if((midi - 2) >= 0 && nums1[midi - 2] > max2){
                        max2 = nums1[midi - 2];
                    }
                    if((midj - 2) >= 0 && nums2[midj - 2] > max2){
                       max2 = nums2[midj - 2]; 
                    }
                    return (max1+max2 + 0.0)/2;
                }
            
        }
        return 0;
    } 
};