/*Majority Element
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
Example 1:
Input: nums = [3,2,3]
Output: 3
Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2
Solution 1 (Brute Force):Check the count of occcurence of every element
Time-O(n^2)
Solution 2:(Use Hashing)
Time Complexity: O(N)-> Frequency array or O(N log N) -> HashMap 
Space Complexity: O(N)
Solution3:Moore’s Voting Algorithm
Majority element count = N/2 + x;
Minority/Other elements = N/2 – x;
Where x is the number of times it occurs after reaching the minimum value N/2.
Now, we can say that count of minority elements and majority element are equal upto certain point of time in the array. 
So when we traverse through the array we try to keep track of the count of elements and which element we are tracking.
Since the majority element appears more than N/2 times, we can say that at some point in array traversal we find the majority element.
Time Complexity: O(N)
Space Complexity: O(1)
*/
//Code:(Moore Voting Algorithm)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Moore Voting Algotithm
        int n=nums.size();
        int count=0,candidate;
        for(int i=0;i<n;i++)
        {
            if(count==0)candidate=nums[i];
            if(candidate==nums[i])//we have to count every element
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        //As it is given majority element is present,we do not need to check again
        return candidate;
        
    }
};
