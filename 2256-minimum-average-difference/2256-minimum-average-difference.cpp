class Solution {
public:
    long long Sum(vector<int> &nums,int l,int h)
    {
        long long s=0,n=h-1;
        for(int i=l;i<h;i++)
        {
            s += nums[i];
        }
        return s;
    }
    int abs(int x)
    {
        return (x > 0) ? x : -x;
    }
    int minimumAverageDifference(vector<int>& nums) {
        long long mn = INT_MAX,ind = -1,low = 0,high = Sum(nums,0,nums.size());
        for(int i=0;i<nums.size();i++)
        {
            low += nums[i];
            high -= nums[i];
            long long x;
            if(nums.size()-i-1 == 0)
            {
                x = abs(low/(i+1));
            }
            else x = abs(low/(i+1) - high/(nums.size()-i-1));
            if(x < mn)
            {
                mn = x;
                ind = i;
            }
        }
        return ind;
    }
};