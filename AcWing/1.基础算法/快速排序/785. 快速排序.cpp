void quick_sort(vector<int>& nums, int l, int r) {
    if (l >= r) return;
    int x = nums[l], i = l - 1, j = r + 1;

    while (i < j) {
        do { i++; } while (nums[i] < x);
        do { j--; } while (nums[j] > x);
        if (i < j) {
            swap(nums[i], nums[j]);
        }
    }
    quick_sort(nums, l, j);
    quick_sort(nums, j + 1, r);
}

int main()
{
    //Solution s;

    vector<int> nums = { 4, 7, 3, 5, 2, 1 };
    quick_sort(nums, 0, 5);

    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

作者：CeciliaLiu
链接：https://www.acwing.com/activity/content/code/content/557153/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。