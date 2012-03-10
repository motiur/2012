#include <iostream>
#include <string>

using namespace std;

class vertex

{

	public:

	vertex();//contructor

	string element ;//name of the element

	int distance ; //distance of the vertex from the adjacent node

	int color ;//1 for not visited
							//2 for still processing
							//3 for has visted
	vertex* parent;

};

class graph
{
	public :

	graph();

	void addVertex(vertex *v);

	void addEdge(vertex *v , vertex *w , int d);

	int indexOf(vertex *v);
	
	//returns array of adjacent vertex of a certain vertex
	
	vertex ** arrayofadjacentVertex(vertex *v);

	//array of vertex
	
	vertex *verticies[50];

	vertex *getVertex(string g);

	int getsizeofadjVerticies(vertex *v);

	int numVerticies;

	int maxVerticies;

	int edges[50][50];

	bool marks[50];


};

int getInteger(string g);
