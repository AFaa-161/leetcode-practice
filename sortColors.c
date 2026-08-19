void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;

}



void partition(int* nums,int low,int high,int *lt,int *gt){
    int pivot=1;
    *lt=low;
    *gt=high;
    int i=low;

    while(i<=*gt){
        if(nums[i]<pivot){
            swap(&nums[i],&nums[*lt]);
            i++;
            (*lt)++;
        }else if(nums[i]>pivot){
            swap(&nums[i],&nums[*gt]);
            (*gt)--;
        }
        else{
            i++;
        }
    }

}


void sortColors(int* nums, int numsSize) {
    int lt,gt;
    partition(nums,0,numsSize-1,&lt,&gt);
 
    
}
