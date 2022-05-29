#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct vertex {
	int vertexId;
	int matrixId;
	vertex* prev;
	vertex* next;

	vertex() {
		vertexId = matrixId = -1;
		prev = next = NULL;
	}

	vertex(int vertexId) {
		this->vertexId = vertexId;
		matrixId = -1;
		prev = next = NULL;
	}
};

struct edge {
	vertex* src;
	vertex* dst;
	edge* next;
	edge* prev;

	edge() {
		src = dst = NULL;
		prev = next = NULL;
	}

	edge(vertex* src, vertex* dst) {
		this->src = src;
		this->dst = dst;
		prev = next = NULL;
	}
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class vertexList {
private:
	vertex* header;
	vertex* trailer;
public:
	vertexList();
	void insertVertex(vertex* newVertex);
	void eraseVertex(vertex* delVertex);
	vertex* findVertex(int vertexId);
};

vertexList::vertexList() {
	header = new vertex();
	trailer = new vertex();

	header->next = trailer;
	header->matrixId = -1;

	trailer->prev = header;
}

void vertexList::insertVertex(vertex* newVertex) {
	newVertex->prev = trailer->prev;
	newVertex->next = trailer;
	newVertex->matrixId = trailer->prev->matrixId + 1; //  새로운 vertex 의 matrixId 값 설정
	trailer->prev->next = newVertex;
	trailer->prev = newVertex;
}

void vertexList::eraseVertex(vertex* delVertex) {
	// 삭제를 시키기전에, 정점 리스트에서 삭제할 정점보다 뒤에 있는 정점들의 인덱스 데이터 값을 1씩 감소시켜줌
	for (vertex* cur = delVertex; cur != trailer; cur = cur->next) {
		cur->matrixId--;
	}

	delVertex->prev->next = delVertex->next;
	delVertex->next->prev = delVertex->prev;
	delete delVertex;
}

vertex* vertexList::findVertex(int vertexId) {
	for (vertex* cur = header->next; cur != trailer; cur = cur->next) {
		if (cur->vertexId == vertexId) {
			return cur;
		}
	}
	return NULL;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class edgeList {
private:
	edge* header;
	edge* trailer;
public:
	edgeList();
	void insertEdge(edge* newEdge);
	void eraseEdge(edge* delEdge);
};

edgeList::edgeList() {
	header = new edge();
	trailer = new edge();
	header->next = trailer;
	trailer->prev = header;
}

void edgeList::insertEdge(edge* newEdge) {
	newEdge->prev = trailer->prev;
	newEdge->next = trailer;
	trailer->prev->next = newEdge;
	trailer->prev = newEdge;
}

void edgeList::eraseEdge(edge* delEdge) {
	delEdge->prev->next = delEdge->next;
	delEdge->next->prev = delEdge->prev;
	delete delEdge;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class graph {
private:
	vector<vector<edge*>> edgeMatrix;  // edge 오브젝트의 주소값들을 저장하고 있는 2차원 배열 
	vertexList vList;
	edgeList eList;
public:
	void insertVertex(int vertexId);
	void eraseVertex(int vertexId);
	void insertEdge(int srcVertexId, int dstVertexId);
	void eraseEdge(int srcVertexId, int dstVertexId);

	void MaxAdjacentNode(int vertexId);
};

void graph::insertVertex(int vertexId) {
	if (vList.findVertex(vertexId) != NULL)
		return;

	vertex* newVertex = new vertex(vertexId);

	for (int i = 0; i < edgeMatrix.size(); i++) {
		edgeMatrix[i].push_back(NULL);   // 각 행의 열의 크기를 1씩 늘려줌
	}
	edgeMatrix.push_back(vector<edge*>(edgeMatrix.size() + 1, NULL));  // 행의 크기도 1 늘려줌

	vList.insertVertex(newVertex);  // vertex 시퀀스에 새로운 정점 추가
}

void graph::eraseVertex(int vertexId) {
	vertex* delVertex = vList.findVertex(vertexId);

	if (delVertex == NULL)
		return;

	int matrixId = delVertex->matrixId;

	// ex) 인덱스 데이터가 2이고, 행렬의 크기가 4x4 인 경우
	for (int i = 0; i < edgeMatrix.size(); i++)
	{
		if (i != matrixId)
		{
			if (edgeMatrix[i][matrixId] != NULL) {  // (0,2), (1,2), (3,2) 에 담긴 주소값이 가리키는 엣지 오브젝트를 엣지 시퀀스에서 삭제
				eList.eraseEdge(edgeMatrix[i][matrixId]);  // 즉, 행렬의 해당 셀에서 가리키던 엣지 오브젝트를, 엣지 시퀀스(엣지 리스트)에서 삭제
			}
			edgeMatrix[i].erase(edgeMatrix[i].begin() + matrixId); // (0,2), (1,2), (3,2) 셀 자체를 행렬에서 완전히 삭제시켜버림
		}
		edgeMatrix.erase(edgeMatrix.begin() + matrixId); // (2,0), (2,1), (2,2), (2,3) 셀 자체를 행렬에서 완전히 삭제시켜버림

		vList.eraseVertex(delVertex);  //  정점을 vertex 시퀀스에서 삭제
	}
}

void graph::insertEdge(int srcVertexId, int dstVertexId) {
	vertex* src = vList.findVertex(srcVertexId);  // 삽입할 엣지의 양끝점 vertex 오브젝트를 vertex 시퀀스에서 찾아냄
	vertex* dst = vList.findVertex(dstVertexId);
	if (src == NULL || dst == NULL)
		return;

	int srcMatrixId = src->matrixId;
	int dstMatrixId = dst->matrixId;

	// 두 정점을 잇는 간선이 이미 존재하는 경우
	if (edgeMatrix[srcMatrixId][dstMatrixId] != NULL || edgeMatrix[dstMatrixId][srcMatrixId] != NULL) {
		cout << "Exist" << endl;
		return;
	}

	edge* newEdge = new edge(src, dst);
	eList.insertEdge(newEdge); // 엣지 시퀀스에 새로운 엣지 오브젝트를 삽입
	edgeMatrix[srcMatrixId][dstMatrixId] = edgeMatrix[dstMatrixId][srcMatrixId] = newEdge; // 행렬에 새로운 edge 오브젝트의 주소를 저장
}

void graph::eraseEdge(int srcVertexId, int dstVertexId) {
	vertex* src = vList.findVertex(srcVertexId);
	vertex* dst = vList.findVertex(dstVertexId);

	if (src == NULL || dst == NULL)
		return;

	int srcMatrixId = src->matrixId;
	int dstMattrixId = dst->matrixId;

	// 두 정점을 잇는 간선이 존재하지 않는 경우.
	if (edgeMatrix[srcMatrixId][dstMattrixId] == NULL || edgeMatrix[dstMattrixId][srcMatrixId] == NULL) {
		cout << "None" << endl;
		return;
	}

	eList.eraseEdge(edgeMatrix[srcMatrixId][dstMattrixId]); // 엣지 오브젝트 삭제
	edgeMatrix[srcMatrixId][dstMattrixId] = NULL;  // 인접행렬에 NULL 을 저장해서 할당해제
	edgeMatrix[dstMattrixId][srcMatrixId] = NULL;
}


void graph::MaxAdjacentNode(int vertexId)
{
	vertex* vertex = vList.findVertex(vertexId);

	int matrixId = vertex->matrixId;
	int max = 0;

	// 행렬의 모든 셀에 대해 탐색
	for (int i = 0; i < edgeMatrix.size(); i++)
	{
		for (int j = 0; j < edgeMatrix.size(); j++)
		{
			if (edgeMatrix[i][j] != NULL && edgeMatrix[j][i] != NULL) // 해당 셀이 어떤 엣지 오브젝트를 가리키고 있는 경우 
			{
				// if (edgeMatrix[i][j] == edgeMatrix[j][i])

				if (edgeMatrix[i][j]->src == vertex || edgeMatrix[i][j]->dst == vertex) // 해당 셀의 엣지 오브젝트가 가리키는 두 개의 vertex 오브젝트중 하나가 정점 vertex 인 경우. 즉, 정점 vertex 와 인접한 정점을 찾은 경우
				{
					// 이제 엣지 오브젝트가 가리키는 두 정점 오브젝트 src, dst 중에서 vertex 가 아닌 정점에 대해서 최댓값 비교 연산을 진행하면 된다.
					// => vertex가 아닌 정점이 바로 정점 vertex와 인접한 정점이다.
					if (edgeMatrix[i][j]->src != vertex) // src 가 인접한 정점이고, dst 가 정점 vertex 인 경우
					{
						if (edgeMatrix[i][j]->src->vertexId > max)
							max = edgeMatrix[i][j]->src->vertexId;
					}
					else if (edgeMatrix[i][j]->dst != vertex) // dst 가 인접한 정점이고, src 가 정점 vertex 인 경우
					{
						if (edgeMatrix[i][j]->dst->vertexId > max)
							max = edgeMatrix[i][j]->dst->vertexId;
					}
				}
			}
		}
	}

	if (max == 0) // 정점 vertexId 와 연결된 정점이 존재하지 않는 경우
	{  //  => 연결된 정점이 존재하지 않았다면, 비교 연산을 단 한번도 진행하지 않아서 max 값이 초기에 설정해준 값인 0 일 것이다.
		cout << "None " << endl;
		return;
	}

	cout << max << endl;
}




int main(void)
{
	graph g;
	int t, n;
	cin >> t >> n;

	while (n--)
	{
		int data;
		cin >> data;
		g.insertVertex(data);
	}

	while (t--)
	{
		string a;
		cin >> a;
		if (a == "insertEdge")
		{
			int data1, data2;
			cin >> data1 >> data2;
			g.insertEdge(data1, data2);
		}
		else if (a == "eraseEdge")
		{
			int data1, data2;
			cin >> data1 >> data2;
			g.eraseEdge(data1, data2);
		}
		else if (a == "MaxAdjacentNode")
		{
			int data;
			cin >> data;
			g.MaxAdjacentNode(data);
		}
	}
}
