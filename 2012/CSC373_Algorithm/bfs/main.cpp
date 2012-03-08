#include <iostream>
#include <string>
#include "graph.h"
#include <stdlib.h>
#include <stdio.h>
#include <queue>

using namespace std;

void bfs(graph *gr , vertex *v);


int main(int argc , char * argv[])
{

	graph *gr = new graph();

	vertex *v1 = new vertex();
	vertex *v2 = new vertex();
	vertex *v3 = new vertex();
	vertex *v4 = new vertex();
	vertex *v5 = new vertex();
	vertex *v6 = new vertex();
	vertex *v7 = new vertex();
	vertex *v8 = new vertex();

	v1->element = "R";
	v2->element = "S";
	v3->element = "T";
	v4->element = "U";
	v5->element = "Y";
	v6->element = "X";	
	v7->element = "W";						
	v8->element = "V";						
	

	
	gr->addVertex(v1);
	gr->addVertex(v2);
	gr->addVertex(v3);
	gr->addVertex(v4);
	gr->addVertex(v5);
	gr->addVertex(v6);
	gr->addVertex(v7);
	gr->addVertex(v8);

	gr->addEdge(v1,v2,1);
	gr->addEdge(v1,v8,1);
	gr->addEdge(v2,v7,1);
	gr->addEdge(v7,v3,1);
	gr->addEdge(v7,v6,1);
	gr->addEdge(v3,v4,1);
	gr->addEdge(v3,v6,1);
	gr->addEdge(v6,v4,1);
	gr->addEdge(v6,v5,1);
	gr->addEdge(v4,v5,1);
	
	

	
	for(int i = 0 ; i < gr->numVerticies ; i++)
	{
		//cout<<gr->verticies[i]->element<<endl;
	
	}


	bfs(gr,v2);
	

	return 0;
}


void bfs(graph *gr , vertex *s)
{

	queue <string> newqueue;
	
	
	
	//Initializing all of the verticies of the graph gr
	
	//for each vertex u E G,V - {s}
	
	for(int i = 0 ; i < gr->numVerticies ; i++)
	
	{
		if (i == gr->indexOf(s))
	
		{
		
			//cout<<i<<endl;
			
			continue;
		}
		
		else
		
		{
			//u.color = white
			
			gr->verticies[i]->color = 1;
			
			//u.color = 10,000
			gr->verticies[i]->distance = 1000000;
			
			//u.parent = NIL
			gr->verticies[i]->parent = "";
			
		
		}
	
	
	}//end of initialization


	//not needed for checking only
	
	for(int i = 0 ; i < gr->numVerticies ; i++)
	{
		//cout << gr->verticies[i]->color<<endl;
	
	}
	
	

	
	//Getting the size of adjacent verticies
	
	int size = gr->getsizeofadjVerticies(s);
	
	//cout <<"size is :"<<size<<endl;//not needed
	
	
	//Initializing the array of vertex
	
	//vertex ** arrofadjvert = (vertex**)malloc(sizeof(vertex)*size);
	
	//arrofadjvert = gr->arrayofadjacentVertex(s);
	
	
	//Seeing whats inside the array of verticies
	
	for(int i = 0 ; i< size ; i++)
	{
		//cout<<(arrofadjvert[i])->element<<endl;
		
	}
	
	
	//Now back to the algorithm 
	
	//s.color = GRAY
	
	gr->verticies[gr->indexOf(s)]->color = 2;

	//s.d = 0 
	gr->verticies[gr->indexOf(s)]->distance = 0;

	//s.π = 0 
	gr->verticies[gr->indexOf(s)]->parent = "";

	
	
	//Enqueue(Q,s)
	
	newqueue.push(s->element);
	
	//cout<<"s->element : "<<s->element<<endl;
	//while Q=! 0
	while (!newqueue.empty())
	{
		
		//u = Dequeue(Q)
		vertex *u = new vertex();
		
		string element = newqueue.front();
		//cout<<"Element is : "<<element<<endl;
		
		u = gr->getVertex(element);
	
		newqueue.pop();
		
		//cout<<"ggggggggggg"<<newqueue.front()<<endl;
		//Finishing u = Dequeue(Q)
		
		//foreach v E G.Adj[u]
		
		vertex ** arrofadjvert = (vertex**)malloc(sizeof(vertex)*gr->getsizeofadjVerticies(u));
	
	  arrofadjvert = gr->arrayofadjacentVertex(u);
	
		
		
		
		for(int i = 0 ; i< gr->getsizeofadjVerticies(u) ; i++)
	
		{
		
			//cout<<(arrofadjvert[i])->element<<endl;
		
		
			vertex *v = new vertex();
		
		
			v = arrofadjvert[i];
			//cout<<"v->color"<<v->color<<endl;
			
			//cout<<"v->element: "<<v->element<<endl;
			
			//if v.color == white
			
			if(v->color == 1)
			
			{
			
				//cout<<"v->color : "<<v->color<<endl;
				//cout<<"v->element"<<v->element<<endl;
			
				//v.color = GRAY
				gr->verticies[gr->indexOf(v)]->color = 2;

				
				
				//v.d = v.d + 1
				
				gr->verticies[gr->indexOf(v)]->distance = gr->verticies[gr->indexOf(u)]->distance + 1;

  
			
				//v.parent = u 
				gr->verticies[gr->indexOf(v)]->parent = gr->verticies[gr->indexOf(u)]->element;



				
				//Enqueue(Q,v)
				//cout<<"Now element is : "<<v->element<<endl;
				newqueue.push(v->element);
				
			}
	}
	
	gr->verticies[gr->indexOf(u)]->color = 3;

	if(gr->verticies[gr->indexOf(u)]->color == 3)
	{

	cout<<gr->verticies[gr->indexOf(u)]->element<<endl;
	cout<<gr->verticies[gr->indexOf(u)]->distance<<endl;
	
	}
	cout<<"-->>"<<endl;
		
		
	}
	
	
	cout<<"............."<<endl;
	for(int i = 0 ; i < gr->numVerticies ; i++)
	{
		cout<<gr->verticies[i]->distance<<endl;
	
	}
	
	
	
}