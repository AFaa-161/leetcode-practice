int* searchRange(int* nums, int numsSize, int key, int* returnSize) {
    int low=0;
    int high=numsSize-1;
    int first=-1;

    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==key){
            first=mid;
            high=mid-1;
        }else if(nums[mid]<key){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }

      low=0;
     high=numsSize-1;
    int last=-1;

    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==key){
            last=mid;
            low=mid+1;
        }else if(nums[mid]<key){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }

    int* ans=malloc(2*sizeof(int));
    *returnSize=2;

    ans[0]=first;
    ans[1]=last;

    return ans;
}