#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

/*双指针的题目先思考暴力法，然后发现元素中的单调性，这道题遍历所有i，然后先让j向左走，那么i必然就要向右走，这就是单调性*/
int main(){
    int n, m, x;
    cin>>n>>m>>x;
    vector<int> nums1(n, 0);
    vector<int> nums2(m, 0);
    for(int i = 0; i < n; i++) scanf("%d", &nums1[i]);
    for(int i = 0; i < m; i++) scanf("%d", &nums2[i]);
    int i = 0, j = m - 1;
    for(int i = 0; i < n; i++){
        while(j >= 0 && nums1[i] + nums2[j] > x) j--;
        if(j >= 0 && nums1[i] + nums2[j] == x) cout<<i<<" "<<j<<endl;
    }
    return 0;
}