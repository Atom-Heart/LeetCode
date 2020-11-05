class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        multiset<long long> helper;
        helper.insert(0);
        int ans=0;
        long long sum=0;
        for (int &i:nums)
        {
            sum+=i;
            cout<<"sum = "<<sum<<" ";
            int num1 = sum-upper, num2 = sum-lower;
            ans+=distance(helper.lower_bound(sum-upper),helper.upper_bound(sum-lower));
            cout<<"ans = " << ans<<endl;
            helper.insert(sum);
        }
        return ans;
    }
};

