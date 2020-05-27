
#define MAX(x, y) (x) > (y) ? (x) : (y)

int jump(int* nums, int numsSize){
	int cnt = 0;
	int cur = 0, next = nums[0];
	for (int i = 1; i < numsSize; ++i) {
		if (next >= numsSize - 1) return cnt + 1;
		if (i > cur) {
			cnt++;
			cur = next;
		}
		next = MAX(nums[i] + i, next);
	}
	return cnt;
}