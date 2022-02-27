/*Majority Element II
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
Example 1:
Input: nums = [3,2,3]
Output: [3]
Example 2:
Input: nums = [1]
Output: [1]
Example 3:
Input: nums = [1,2]
Output: [1,2]
Approach1:Brute force-O(n^2)
Approach2:Use Hashing
Time Complexity: O(n)
Space Complexity: O(n)
Approach3:Extended Boyer Moore’s Voting Algorithm
Approach + Intuition: 
In our code, we start with declaring a few variables:
num1 and num2 will store our currently most frequent and second most frequent element.
c1 and c2 will store their frequency relatively to other numbers.
We are sure that there will be a max of 2 elements which occurs > N/3 times because there cannot be if you do a simple math addition.
Let, ele be the element present in the array at any index. 
if ele == num1, so we increment c1.
if ele == num2, so we increment c2.
if c1 is 0, so we assign num1 = ele.
if c2 is 0, so we assign num2 = ele.
In all the other cases we decrease both c1 and c2.
In the last step, we will run a loop to check if num1 or nums2 are the majority elements or not by running a for loop check.
*/
//Code(Boyer Moore Voting Algo):
#include<bits/stdc++.h>
using namespace std;
vector<int> majorityElement(vector<int>& nums) {
        //for linear time and o(1) Space
        //Bayers moore voting ALgorithm
        int num1=-1;//first majority element
        int num2=-1;//second majority element 
        //There can be max 2 majority element
        int c1=0,c2=0;//count of first and second majority element
        int n=nums.size();
        for(int ele:nums)
        {
             if(ele==num1)
                c1++;
            else if(ele==num2)
                c2++;
            else if(c1==0)
            {
             num1=ele;
             c1=1;
            }
            else if(c2==0)
            {
                num2=ele;
                c2=1;
            }
                
            
            else
            {
                c1--;
                c2--;
            }
        }
        c1=0,c2=0;
        for(auto ele:nums)
        {
            if(ele==num1){
                c1++;
            }
            else if(ele==num2)
                c2++;
        }
        vector<int>ans;
        if(c1>n/3)
            ans.push_back(num1);
        if(c2>n/3)
            ans.push_back(num2);
        return ans;
        
    }
