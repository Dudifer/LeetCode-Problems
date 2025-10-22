vector<int> getConcatenation(vector<int>& nums) {
  int len = nums.size();
  for(int i = 0; i < nums.size(); i++){
    nums.push_back(nums[i]);
  }
  return nums;
}
// beats 100%