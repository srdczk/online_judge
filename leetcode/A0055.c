
#define MAX(x, y) (x) > (y) ? (x) : (y)

bool canJump(int* nums, int numsSize) {
    int reach = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (reach >= numsSize - 1) return 1;
        if (reach < i) return 0;
        reach = MAX(reach, i + nums[i]);
    }
    return reach >= numsSize - 1;
}