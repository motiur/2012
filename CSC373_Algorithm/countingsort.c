#include <stdio.h>
#include <stdlib.h>


int max(int *arr, int len);

int main()
{


	int number = 10000000;//10 million
	printf("Number is %d", number);
	int *a = (int*)malloc(sizeof(int)*number); 
	for(int i = 1 ; i<= number; i++)
	{
		a[i] = ((float)number*rand())/(RAND_MAX)+1.0;
	}

	//initialization  of  input array

	/*int *a = (int*)malloc(sizeof(int)*10);
	
	for(int i = 1 ; i <= 10 ; i++)
	{
		a[i] = 10 - (i-1);

	}

	for(int i = 1 ; i <= 10 ; i++)
	{
		printf("a[%d]: %d\n",i,a[i]);

	}*/

	for(int i = 1 ; i <= number ; i++)
	{
		//printf("a[%d]: %d\n",i,a[i]);

	}	
	
	int maximum = max(a,number);//Prints maximum of the arrays
	
	//printf("m is %d\n",maximum);
	//First loop , for i = 0 to k ;  k  = 10

	int *c = (int*)malloc(sizeof(int)*maximum);

	for(int i = 1 ; i <= maximum ; i++)
	{
		c[i] = 0;
	}
	//Second loop , counting numbers of occurance  of
	//each element

	for(int j = 1 ; j <= number; j++)

	{
		c[a[j]]  = c[a[j]] + 1;
	}

	//Third loop , relative position, for 1 to k , k = 10

	for(int i = 2 ; i <=maximum; i++)
	{
		c[i] = c[i] + c[i-1];
	}

	//Fourth loop , for j = A.length downto 1

	int *b =(int*)malloc(sizeof(int)*number);

	for(int j = 1 ; j <=number ; j++)
	{
		b[j] = 0 ;
	}

	for(int j = number ; j > 0 ; j--)
  	{
		b[c[a[j]]] = a[j];
		c[a[j]] = c[a[j]] -1;
  	}

	for(int i = 1 ; i <= number ;i++)
	{
		//printf("%d\n",b[i]);

	}
	free(a);
	free(b);
	free(c);
	return 0;
}



int max(int *arr, int len)

{

	int max = 0 ;
	for(int i = 1 ; i<=len ;i++)
	{
		if (max <= arr[i])
			{
				max = arr[i];

			}

	}
	//printf("max is %d ",max); //Prints maximum of the array
	return max ;


}
