//The result is still inconclusive, got to recheck 
//least common subsequence
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define M 6 // x.length
#define N 7 //y.length

int *b[N+1];

int *c[N+1];

char x[M]={'B','D','C','A','B','A'};
char y[N]={'A','B','C','B','D','A','B'};

void lcs_length();
void print_lcs(int **b , char *x , int m , int n); 

int main(int argc , char*argv[])
{
	printf("LCS\n");
	
	for(int i = 0 ; i < N+1; i++)
	{
	
			b[i] = (int*)malloc(sizeof(int)*(M+1));
		
	}
	
	for(int i = 0 ; i < N+1; i++)
	{
	
			c[i] =  (int*)malloc(sizeof(int)*(M+1));

	}
	
	lcs_length();
	
	print_lcs(b , x , M, N);
	for(int i = 0 ; i < N+1 ; i++)
	{
		for(int j = 0 ; j < M+1 ; j++)
		{
			printf("c[%d][%d]%d\n",i,j,c[i][j]);
	
		}
	
	}
	return 0;
}


void lcs_length()
{
	printf("This is a test\n");
	//printf("c[0][0]:%d ",c[0][0]);
	
	for(int i = 0 ; i < N+1 ; i++)
	{
		for(int j = 0 ; j< M+1 ; j++)
		{
			c[i][j] = 0;
			b[i][j] =0 ;
		}
	
	}
	
	
	
	for(int i = 1 ; i < N+1 ;i++)
	{

		for(int j = 1 ; j< M+1 ; j++)
		{
				//printf(".........%c %c\n",x[i-1],y[j-1]);
			if(x[j-1] == y[i-1])
			{
				//printf(".........Equal..%c %c\n",x[i-1],y[j-1]);
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = 1;//"left arrow"				
				
			}
			else if(c[i-1][j] >= c[i][j-1])
			{
				//printf("c[%d][%d] %d >= c[%d][%d] %d\n",i-1,j,c[i-1][j],i,j-1,c[i][j-1]);
				//printf("b[%d][%d] %d\n",i,j,b[i][j]);
				
				c[i][j] = c[i-1][j];
				//printf("....c[%d][%d] %d \n",i,j,c[i][j]);
				
				b[i][j] = 2;//"up arrow"
				
			}
		
			else
			{
				
				c[i][j] = c[i][j-1];
				//printf("c[%d][%d] %d \n",i,j,c[i][j]);
				
			
				b[i][j] = 3;//"side arrow "
			
			}
		
		}
	
	}
	
	
}

void print_lcs(int **b , char * x , int i , int j)

{
	if (( i == 0)||( j == 0))
	{
		return ;
		
	}
	//printf("b[%d][%d]%d\n",i,j,b[i][j]);
	
	if ((b[i][j]) == 1)
	{
		print_lcs(b , x , i-1 , j-1);
		printf("%c", x[i]);
		printf ("\n");
	}
	else if(b[i][j] == 2)
	{
		print_lcs(b , x , i-1 ,j);
	
	}
	else
	{
		print_lcs(b,x,i,j-1);
	
	}
	
}