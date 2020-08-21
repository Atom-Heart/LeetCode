/*每一步都计算一下当前位置最远能够跳到哪里，然后和一个全局最优的最远位置furthest比较，通过每一步的最优解，更新全局
最优解*/
bool CanJump(vector<int>& nums){
	int furthest = 0;//最远能到达的位置
	for(int i = 0; i < nums.size() - 1; i++){
		furthest = max(furthest, nums[i] + i);//每次遍历都更新最远能到达的位置
		if(furthest <= i) return false;//如果最远能到达的位置小于等于当前位置，那么肯定就是到头了
	}
	return furthest >= nums.size() - 1;//如果最远能到达的位置大于等于最后一个下标的位置，那么就返回真
}
