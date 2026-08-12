int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    for(int i=0;i<intervalsSize-1;i++){
        for(int j=i+1;j<intervalsSize;j++){
            if(intervals[i][0]>intervals[j][0]){
                int temp=intervals[i][0];
                intervals[i][0]=intervals[j][0];
                intervals[j][0]=temp;

                temp = intervals[i][1];
                intervals[i][1] = intervals[j][1];
                intervals[j][1] = temp;
            }
        }
    }

    int** ans=malloc(intervalsSize*sizeof(int*));
    for(int i=0;i<intervalsSize;i++){
        ans[i]=malloc(2*sizeof(int));
    }
    int count=0;

    for(int i=0;i<intervalsSize;i++){
        
        if(count==0 || (intervals[i][0]>ans[count-1][1])){
            ans[count][0]=intervals[i][0];
             ans[count][1]=intervals[i][1];
             count++;
        }
        else{
            if(intervals[i][1]>ans[count-1][1]){
                ans[count-1][1]=intervals[i][1];
            }
        }
    }

    *returnSize=count;
    *returnColumnSizes=malloc(count*sizeof(int));

    for(int i=0;i<count;i++){
        (*returnColumnSizes)[i]=2;
    }
    return ans;
}