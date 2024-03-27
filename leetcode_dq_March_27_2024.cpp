class Solution {
public:
    
    //Variable sliding window
    //Time Complexity: O(n)
    //Space Complexity: O(1)
    
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        //left and right ends
        int left = 0,right = 0;
        
        //product variable
        long long prod = nums[0];
        
        //Our answer
        int ans = 0;
        
        
        while(right<nums.size() ){
            if(prod<k){     //If product is strictly less than k then the whole window size is to be added
                
                //This is done because if we are including a new element(e.g. An) at the element like here
                //Then from the window containing (A1,A2,...,An) we need to add the contiguous subarrays containing An
                //i.e. [An], [An-1,An], ...., complete window  this sums to size of window
                // That is why we are adding it's size!
                ans += right-left+1;
                
                
                //Incrementing window
                right++;
                //Incrementing product
                if(right<nums.size()) prod *= nums[right];
            }
            else if(left<right){
                //Decrementing since prod>=k
                left++;
                prod /= nums[left-1];
            }
            else{
                //This shows that the single element itself is >=k
                //Therefore we are considering next single element
                left++;
                right++;
                if(right<nums.size()) prod = nums[right];
            }
        }
        return ans;
    }

int speed_up = []{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
};

