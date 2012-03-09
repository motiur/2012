#include <iostream>
#include <string>

using namespace std;

class vertex

{

	public:

	vertex();//contructor

	string element ;//name of the element

	int distance ; //distance of the vertex from the adjacent node

	//int numberofadjacentVertex;//number of the adjacent verticies

	int color ;//1 for not visited
							//2 for still processing
							//3 for has visted
	vertex* parent;

};

class graph
{
	public :

	graph();

	~graph();

	void makeEmpty();

	void isEmpty();

	bool isFull();

	void addVertex(vertex *v);

	void addEdge(vertex *v , vertex *w , int d);

	int weightIs(vertex *v , vertex *w);

	void adjacentVertex(vertex *v);

	void clearMarks();

	void markVertex(vertex *v);

	bool isMarked(vertex * v);

	int indexOf(vertex *v);

	
	vertex ** arrayofadjacentVertex(vertex *v);

	vertex *verticies[50];

	vertex *getVertex(string g);

	int getsizeofadjVerticies(vertex *v);


	void adjacentVertex(int arr[], int size , vertex *w);

	int numVerticies;

	int maxVerticies;

	int edges[50][50];

	bool marks[50];


};

int getInteger(string g);
