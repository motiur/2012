#include <stdio.h>
#include <stdlib.h>

int global_array[1000];
int slowfib(int n);
int fastfib(int n);
int slownumbers = 0 ;
int fastnumbers = 0 ;

int main()
{


	int n1 = 14;
	int n2 = 14;

	for(int i = 0 ; i < 1000; i++)
	{

		global_array[i] = -1;


	}
	//0 th element is 0 ; 1st element is 1

	global_array[0] = 0;

	global_array[1] = 1;

	int slowresult = slowfib(n1);

	printf("Slow result is %d\n", slowresult);
	printf("Total call for slow fibonacci is %d\n",slownumbers);

	int fastresult = fastfib(n2);

	printf("Fast result is %d\n", fastresult);
	printf("Total call for fast fibonacci is %d\n",fastnumbers);
	return 0;

}
int slowfib(int n)
{
	slownumbers += 1;

	if ( n <= 1)
	{
	return n;
	}

	else
	{
	return slowfib(n-1) + slowfib(n-2);
	}

}


int fastfib(int n)
{
	fastnumbers += 1;

  if (global_array[n] == -1)
  {
  	global_array[n] = fastfib(n-1) + fastfib(n-2);
  }

  else
  {
  return  global_array[n];
  }

}

