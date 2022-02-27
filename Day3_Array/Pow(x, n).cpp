/*Pow(x, n)
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
Example 1:
Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:
Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:
Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
1.Brute force soln-O(n) Time
2.Using Binary Exponentiation -O(logn) time where n is power 
(Shown Below)
*/
//Code:(only Function)
double myPow(double x, int n) {
        //Using Binary Exponentiation
        //O(logn)
        if(x==1.0)return x;
        double result=1.0;
        long long int nn=n;
        if(nn<0)
            nn*=-1;
        while(nn!=0)
        {
            if(nn%2)//nn is odd power
            {
                result*=x;
                nn--;
            }
            else
            {
                x=x*x;
                nn=nn/2;
            }
        }
        if(n<0)return 1.0/result;
        return result;
    }
};
