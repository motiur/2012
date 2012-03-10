#include <iostream>
#include <string>

using namespace std;

class vertex

{

	public:

	vertex();//contructor

	string element ;//name of the element

	int start_time ; //time at which the node has been marked gray

	int end_time;//time at which the node has been marked black

	int color ;//1 for white(not visited) ,2 for still processing(gray),3 for has visted(black)

	vertex* parent;

};

class graph
{
	public :

	graph();

	void addVertex(vertex *v);

	void addEdge(vertex *v , vertex *w , int d);

	int indexOf(vertex *v);

	vertex ** arrayofadjacentVertex(vertex *v);

	vertex *verticies[50];

	vertex *getVertex(string g);

	int getsizeofadjVerticies(vertex *v);

	int numVerticies;

	int maxVerticies;

	int edges[50][50];


};

int getInteger(string g);
