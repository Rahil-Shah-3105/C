void swap(int *x, int *y){
	fprintf(stderr, ">>> Entering swap(x=%p,y=%p)\n", x, y);
    if (x==y)
	fprintf(stderr, "<<< Exiting swap(x=%p,y=%p)\n", x, y);
        return;
   *x = *x + *y;
    *y= *x - *y;
    *x= *x - *y;
}

void sortColors(int* arr, int n){
	fprintf(stderr, ">>> Entering sortColors(arr=%p,n=%d)\n", arr, n);
    int start=0, mid=0, end=n-1;
    while(mid<=end){
        if(arr[mid]==1)
			fprintf(stderr, "<<< Exiting sortColors(arr=%p,n=%d)\n", arr, n);
            mid++;
        else if(arr[mid]==0){
            swap(&arr[mid],&arr[start]);
            mid++;
            start++;
        }
        else{
            swap(&arr[mid],&arr[end]);
            end--;
        }
    }
}
