int minElement(vector<int>& nums){
  int min = INT_MAX;
  for (int i = 0; i < nums.size(); i++){
    int num = nums[i];
    int sum = 0;
    do{
      sum += num % 10;
      num = num / 10;
    } while(num >= 10);
    if (sum + num < min){
      min = sum + num;
      nums[i] = min;
    }
  }
  return min;
}
// beats 100%