class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0) return;
        if(m == 0){
            while(!nums1.empty()){
                nums1.pop_back();
            }
            for(auto num : nums2){
                nums1.push_back(num);
            }
            return;
        }
        auto it1 = nums1.begin();
        auto it2 = nums2.begin();

        int count = 0;
        for(auto it = nums1.begin(); it!=nums1.end(); it++){
            if(count == m){
                nums1.erase(it, nums1.end());
                break;
            }
            count++;
        }


        while(it1 != nums1.end() && it2 != nums2.end()){
            if(*it2 < *it1){
                it1 = nums1.insert(it1, *it2);//这里一定要更新it1，因为插入之后会使迭代器失效
                it2++;
            }
            it1++;
        }
        while(it2 != nums2.end()){
            nums1.push_back(*it2);
            it2++;
        }
        
    }
};