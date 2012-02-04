#include <stdio.h> 
#include <stdlib.h>
#include <time.h>


void mergesort(int *array,int *temporary, int low, int high);
void merge(int *arr,int *temp, int low,int middle,int high);
int * insertionsort(int *arr , int len);

int main(int argc , char * argv[])
{
	int number = 9000000;//9 million numbers

	/*
  printf("Enter a number: \n");

  scanf("%d",&number);

  //printf("The number is %d",number);
	*/
  int *arr = (int*)malloc((int)number* sizeof(int));

	int *temp = (int*)malloc((int)number*sizeof(int));


	for(int i = 0 ; i< number; i++)
	{
	  arr[i] =((float)number*rand())/(RAND_MAX)+1.0;
		//arr[i] = (float)(number/2) - i;
	}
	for(int i = 0 ; i< number; i++)
  	{
    	temp[i] =0;
  	}
/*
	printf("Before Sorting...\n");

	for(int i = 0 ; i< number; i++)
	{
		printf("%d\t",arr[i]);
	}
*/
	mergesort(arr,temp,0, number-1);

	printf("\n");
/*
	printf("After Sorting...\n");

  	for(int i = 0 ; i< number; i++)
  	{
    		printf("%d\t",arr[i]);

  	}*/
	printf("\n");
	/*
	for(int i = 0 ; i< number; i++)
 	 {
    		printf("%d\t",arr[i]);

  	}
	*/
	

	printf("\n");

	free(arr);
	free(temp);
	
	return 0;

}

void mergesort( int *array,int *temporary ,int low,  int high)
{

	if (high -low <= 44)
	{
		array = insertionsort(array , high-low +1 );
		temporary = array;
	}	
	if (low < high) 

	{
		int middle = (low + high)/2;
		mergesort(array,temporary, low , middle);
		mergesort(array,temporary,middle+1, high);
		merge(array,temporary,low,middle+1,high);

	}


}

void merge(int numbers[], int tempo[], int left, int mid, int right)
{

	int low_end = left;
	int high_end = mid;
	int k = left ;
	int num_elm = right - left + 1;
	while( (low_end < mid) &&(high_end <=right))
	{
		if(numbers[low_end]<=numbers[high_end])
		{
			tempo[k] = numbers[low_end];
			k++;
			low_end++;
		}
		else
		{
			tempo[k] = numbers[high_end];
			k++;
			high_end++;

		}

	}
	while(low_end < mid)
	{
		tempo[k]= numbers[low_end];
		k++;
		low_end++;

	}
	
	while(high_end <= right)
	{

		tempo[k]= numbers[high_end];
		k++;
		high_end++;

	}
	for(int i = 0 ; i <num_elm; i++)
	{
		numbers[right] = tempo[right];
		right--;

	}
}

int * insertionsort(int *arr , int len)
{

	for(int j = 1 ; j < len ; j ++)
	{
		int key = arr[j];
		int i = j -1;
		while(( i >= 0)&& ( arr[i] > key))
		{
			arr[i + 1] = arr[i];
			i = i -1;
		}
		arr[i + 1] = key ;
	}
	return arr;

}

