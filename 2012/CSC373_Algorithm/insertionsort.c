#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

int * sort(int *arr , int len);
int main(int argc , char * argv[])
{
	int number = 50000 ;
/*
	printf("Enter a number: \n");

	scanf("%d",&number);

	printf("The number is %d",number);
*/
	int *a = (int*)malloc((int)number* sizeof(int));

	if ( a == NULL){printf("Sorry mate");return 0;}

	for(int i = 0 ; i< number; i++)
	{
		a[i] = ((float)number*rand())/(RAND_MAX)+1.0;
	}
	/*
	printf("Before Sorting\n");

	for(int i = 0 ; i<number; i++)
	{
		printf("%d\t",a[i]);
	}
*/
	//free(a);

	int * sortedarray = (int*)malloc(number* sizeof(int));

	sortedarray = sort(a,number);


	printf("\n");
/*
	printf("After sorting\n");

	for (int i = 0 ; i <number ;i++)
	{
		printf("%d\t",sortedarray[i]);

	}
*/
	printf("\n");

	return 0;

}

int * sort(int *arr , int len)
{

	printf("Length of array %d",len);
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
	/*
	printf("Inside the function:");
	for(int i = 0 ; i <len; i++)
	{
	printf("%d\t",arr[i]);
	}*/
	return arr;

}

