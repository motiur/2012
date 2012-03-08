#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "graph.h"
using namespace std;

vertex::vertex()
{
	element = "";

	distance = 10000;

	//numberofadjacentVertex= -1;

	color = 0;

	parent = "";


}


//Initializing graph () constructor
graph::graph()

{
	numVerticies = 0;

	maxVerticies = 50;

	for (int i = 0 ; i <= maxVerticies ; i++)
	{
		marks[i] = false;//not visited ith vertex yet

		verticies[i] = NULL;

	}

	for(int i = 0 ; i < maxVerticies; i++)
	{
		for(int j = 0 ; j <maxVerticies; j++)
		{
			edges[i][j] = 10000; //distance from i to j

		}

	}

}

void graph::addVertex(vertex *v)
{
	
	verticies[numVerticies++]= v;

}

void graph::addEdge(vertex *v , vertex *w , int d)
{
	int index_vertical = indexOf(v);
	
	int index_horizontal = indexOf(w);
	
	edges[index_vertical][index_horizontal] = d;

	


}

int graph::indexOf(vertex *v)
{

	for(int i = 0 ; i <numVerticies; i++)
	{
		if (verticies[i] == v)
			return i;

	}
	return -1;

}

int graph::weightIs(vertex *v , vertex *w)
{
	int index_vertical = indexOf(v);

	int index_horizontal = indexOf(w);

	return edges[index_vertical][index_horizontal];

}

vertex **graph::arrayofadjacentVertex(vertex *v)
{
	int size = 0 ;
	
	int ind = indexOf(v);

	for(int i = 0 ; i<numVerticies ; i++)
	{
		if ((edges[ind][i]!= 10000)||(edges[i][ind]!= 10000))
		{
	
			size++;

		}
	
	}

	int *arr = new int[size];



	//arr is an array that contains
	//valid index values 
	for(int i = 0 , j = 0 ; i<numVerticies ; i++)
	{
		
		//for say: [5]->[6]->[7] :ind= [5]
		if(edges[ind][i]!= 10000)//ten thousand
		{

			arr[j] = i;//i is a valid index 

			j++;

		}
		
		//This thing has been added due to undirected nature of the graph
		
		//for say:[4]->[5]: ind = [5] ; i has incremented
		
		if(edges[i][ind]!= 10000)//ten thousand
		{

			arr[j] = i;//i is a valid index 

			j++;

		}

	
	}


	vertex **ver = new vertex *[size];

	for(int i = 0 ; i<size ; i++)
	{
		int ind = arr[i];
		
		ver[i] = verticies[ind];

	}

	

	return ver;


}

int graph::getsizeofadjVerticies(vertex *v)
{

	int size = 0 ;
	
	int ind = indexOf(v);

	for(int i = 0 ; i<numVerticies ; i++)
	{
		if ((edges[ind][i]!= 10000)||(edges[i][ind]!= 10000))
		{
			//cout<<"egde["<<ind<<"]i["<<i<<"]"<<edges[ind][i]<<endl;
			size++;

		}

	}

	return size;


}
void graph::markVertex(vertex *v)
{

	int index = indexOf(v);

	marks[index] = true;

}

bool graph::isMarked(vertex *v)
{
	int index = indexOf(v);

	return marks[index];

}

void graph::clearMarks()
{
	for(int i = 0;i <maxVerticies ; i++)
	{

		marks[i] = false;

	}

}

vertex * graph::getVertex(string g)
{

	for(int i = 0 ; i<numVerticies; i++)
	{
		vertex *v = verticies[i];

		if ( v->element.compare(g) == 0)
			{
				return v;

			}


	}

}
int getInteger(string g)
{
	int siz=g.length();
	int x =0;
	for(int i=0; i<siz; i++)
	{
		int val=g[i]-'0';
		x*=10;
		x+=val;
	}
	return x;
}
