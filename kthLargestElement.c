void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void threeWayPartition(int *nums, int low, int high,
                       int *lt, int *gt) {
    int pivot = nums[high];

    int i = low;
    *lt = low;
    *gt = high;

    while (i <= *gt) {

        if (nums[i] < pivot) {
            swap(&nums[i], &nums[*lt]);
            (*lt)++;
            i++;
        }

        else if (nums[i] > pivot) {
            swap(&nums[i], &nums[*gt]);
            (*gt)--;
        }

        else {
            i++;
        }
    }
}
int quickSelect3(int *nums, int low, int high, int k) {

    if (low == high)
        return nums[low];

    int lt, gt;

    threeWayPartition(nums, low, high, &lt, &gt);

    if (k < lt)
        return quickSelect3(nums, low, lt - 1, k);

    if (k > gt)
        return quickSelect3(nums, gt + 1, high, k);

    return nums[k];
}
int findKthLargest(int* nums, int numsSize, int k) {
    int target = numsSize - k;

    return quickSelect3(nums, 0, numsSize - 1, target);
}
