#include <iostream>
#include <string>
#include <vector>
using namespace std;

// vertex 오브젝트
struct vertex {
	int vertexId; // 정점의 고유 번호
	int matrixId; // edge matrix 에서 정점의 인덱스 번호

	vertex* prev; // vertex 시퀀스에서 자신의 이전과 다음 vertex 오브젝트가 누구인지를 저장
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

// 정점을 저장하는 시퀀스 
// ( 이론 수업 배운 것과 달리, 엣지 오브젝트들을 가리키는 시퀀스와, vertex 오브젝트들을 가키리는 시퀀스가 따로 존재하지 않는다.)
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

// 정점 오브젝트 시퀀스에 새로운 정점을 삽입
void vertexList::insertVertex(vertex* newVertex) {
	newVertex->prev = trailer->prev;
	newVertex->next = trailer;
	newVertex->matrixId = trailer->prev->matrixId + 1; // 기존 정점 오브젝트 시퀀스의 마지막 정점 오브젝트의 matrixId 값이 3이라면, 새로 삽입시킬 정점은 4로 설정
	trailer->prev->next = newVertex;
	trailer->prev = newVertex;
}

// 정점 오브젝트 시퀀스에서 해당 정점을 삭제
// => 그래프에서 정점 삭제시 1
// 1) 정점 오브젝트 삭제 2) 정점 오브젝트의 시퀀스 원소를 삭제(몰론 실습 코드는 이 시퀀스가 따로없음)
// 3) 정점과 인접한(adjacent) 엣지들 삭제
// 4) 삭제할 정점보다 인덱스 번호 데이터 (matrixId) 가 큰 정점들의 matrixId 를 1씩 감소
// 여기서는 1번인 "정점 오브젝트 삭제" 과정을 이 함수로 진행하면 된다.
void vertexList::eraseVertex(vertex* delVertex) {
	for (vertex* cur = delVertex; cur != trailer; cur = cur->next) {    // 삭제할 정점보다 matrixId가 큰 정점들의 matrixId를 1씩 감소
		cur->matrixId--;
	}

	delVertex->prev->next = delVertex->next;
	delVertex->next->prev = delVertex->prev;
	delete delVertex; // delVertex 를 정점 오브젝트 시퀀스에서 삭제
}

// 정점 오브젝트 시퀀스에서 정점 vertexId 를 찾고 리턴 
vertex* vertexList::findVertex(int vertexId) {
	for (vertex* cur = header->next; cur != trailer; cur = cur->next) {
		if (cur->vertexId == vertexId) {
			return cur;
		}
	}

	return NULL;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// edge 오브젝트
struct edge {
	vertex* src;  // 이 edge 가 양끝에 어떤 두 개의 정점 (source, destination) 을 연결하고 있는지를 변수로 저장
	vertex* dst; 

	edge* prev; // 엣지 시퀀스에서 자신의 다음과 이전 엣지가 누구인지를 저장
	edge* next;
	
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

// 엣지 오브젝트들을 저장하는 시퀀스
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

// 새로운 엣지 오브젝트를 엣지 오브젝트 시퀀스에 삽입
void edgeList::insertEdge(edge* newEdge) {
	newEdge->prev = trailer->prev;
	newEdge->next = trailer;
	trailer->prev->next = newEdge;
	trailer->prev = newEdge;
}

// 엣지 오브젝트를 엣지 오브젝트 시퀀스에서 삭제
// 이 함수는 엣지 오브젝트를 딱 삭제하고 끝날때 활용될 수도 있瑁嗤, vertex 오브젝트를 삭제하는 연산에서 활용된다!
// ( vertex 를 삭제할때 vertex 는 몰론, vertex 와 연결된 edge 들도 함께 삭제해야 하기때문)
void edgeList::eraseEdge(edge* delEdge) {
	delEdge->prev->next = delEdge->next;
	delEdge->next->prev = delEdge->prev;
	delete delEdge;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

class graph {
private:
	vector<vector<edge*>> edgeMatrix; // 인접 행렬 => 각 셀에 edge 의 주소를 저장해서, edge의 주소가 저장된 셀은 해당 edge 오브젝트를 가리킴
	vertexList vList;  // 정점을 저장하는 리스트
	edgeList eList;    // edge를 저장하는 리스트
public:
	void insertVertex(int vertexId);
	void eraseVertex(int vertexId);
	void insertEdge(int srcVertexId, int dstVertexId);
	void eraseEdge(int srcVertexId, int dstVertexId);
};

// vertex 시퀀스에 vertex 오브젝트를 삽입. 이때 행렬의 행과 열의 크기를 1씩 늘려준다.
// (이론시간에 배운것은 원래 크기를 키운 새로운 행렬을 만들고 기존 행렬의 모든 원소를 카피한후, 새로운 vertex 오브젝트를 삽입하는 것이였으나,
// 여기서는 기존 행렬에서 그냥 크기를 키운다. )
void graph::insertVertex(int vertexId) {
	if (vList.findVertex(vertexId) != NULL) {  // 정점 vertexId 가 이미 그래프가 존재하는 경우
		return;
	}

	vertex* newVertex = new vertex(vertexId);

	// 인접행렬에 새로운 정점과 연결될 edge 의 정보를 저장할 공간을 생성

	for (int i = 0; i < edgeMatrix.size(); i++) {     // 인접행렬의 각 행에다 NULL 값을 추가해줌으로써, 행렬의 열을 1증가시킴. 
		edgeMatrix[i].push_back(NULL);                // ex. 3x3 행렬인 경우, 3x4 가 된다.  예를들어 2행에 {NULL, NULL, NULL} 이 저장되있는 경우, 
		                                              // NULL 을 하나 추가함으로써 해당 행은 {NULL, NULL. NULL, NULL} 이 된다.
	}

	edgeMatrix.push_back(vector<edge*>(edgeMatrix.size() + 1, NULL)); // 인접행렬의 행을 1 늘림. 
	// 앞서서 1열을 늘렸으므로, 이 작업을 통해서 행도 1을 늘린다. ex) 3x3 행렬이 앞서 실행한 작업으로 3x4 가 되었다면, 이번 작업을 통해 4x4 가 된다.

	vList.insertVertex(newVertex);   // 정점 오브젝트 시퀀스에 새로운 정점 오브젝트를 삽입 
}



// 정점 오브젝트 시퀀스에서 해당 정점을 삭제
// => 그래프에서 정점 삭제시 
// 1) 정점 오브젝트 삭제 2) 정점 오브젝트의 시퀀스 원소를 삭제(몰론 실습 코드는 이 시퀀스가 따로없음)
// 3) 정점과 인접한(adjacent) 엣지들 삭제
// 4) 삭제할 정점보다 인덱스 번호 데이터 (matrixId) 가 큰 정점들의 matrixId 를 1씩 감소

// 정점 vertexId 를 삭제. 이때 인접한 edge 들도 함께 삭제해준다.
void graph::eraseVertex(int vertexId) {
	vertex* delVertex = vList.findVertex(vertexId);  // 정점 시퀀스에서 정점 vertexId 를 찾아냄

	if (delVertex == NULL) { // 삭제할 정점이 존재하지 않는 경우
		return;
	}

	int matrixId = delVertex->matrixId; // 삭제할 노드의 인덱스 번호
	
	// matrixId 값이 2인 vertex, 즉 데이터 필드에 인덱스 번호를 2를 가지고 있는 vertex 오브젝트와 
	// 인접한 edge 오브젝트들의 주소값은 인접행렬에서 2행의 셀들과, 2열의 셀들이 모두 저장하고 있다.
	// 따라서 인접행렬에서 2행의 셀들과, 2열의 셀들을 모두 제거해주면, 해당 vertex와 인접한 edge들을 모두 제거하면서 
	// 동시에 행렬의 행과 열의 크기를 1 줄일 수 있다! (ex. 4x4 행렬 => 3x3 행렬)

	// 인접 행렬에서 삭제할 정점과 연결된 edge 와, edge 의 정보를 저장하는 공간을 삭제
	// i행 matrixId 열에 담겨있는 주소값을 제거한다!
	for (int i = 0; i < edgeMatrix.size(); i++) {  // * 참고 : 2차원 벡터의 size() 함수 결과값은 행의 크기가 나온다!!
		if (i != matrixId) {  
			if (edgeMatrix[i][matrixId] != NULL) {  // i행 matrixId 에 담겨있는 주소값이 NULL 이 아니라면. 즉, i행 matrixLd 열 셀이 어떤 엣지 오브젝트를 가리키고 있는 상태이라면
				eList.eraseEdge(edgeMatrix[i][matrixId]);  // 인접한 edge 오브젝트들도 함께 삭제
			}
			edgeMatrix[i].erase(edgeMatrix[i].begin() + matrixId); // i열에 있는 셀들을 모두 (이때, i행 i열은 제외) 제거. 
			                                                       // => 이때 행렬 셀 자체를 삭제해 버리는 것이다!
		}
	}

	edgeMatrix.erase(edgeMatrix.begin() + matrixId);  // 인접행렬의 matrixId 행의 모든 셀들을 삭제
	vList.eraseVertex(delVertex); // vertex 시퀀스에서 vertex 오브젝트 삭제
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
		return;
	}

	edge* newEdge = new edge(src, dst);
	eList.insertEdge(newEdge); // 엣지 시퀀스에 새로운 엣지 오브젝트를 삽입
	edgeMatrix[srcMatrixId][dstMatrixId] = edgeMatrix[dstMatrixId][srcMatrixId] = newEdge; // 행렬에 새로운 edge 오브젝트의 주소를 저장
}

// 인자로 주어진 두 정점 사이를 연결해주고 있는 edge 를 삭제
void graph::eraseEdge(int srcVertexId, int dstVertexId) {
	vertex* src = vList.findVertex(srcVertexId);
	vertex* dst = vList.findVertex(dstVertexId);

	if (src == NULL || dst == NULL) // 정점이 그래프가 존재하지 않는 경우
		return;

	int srcMatrixId = src->matrixId;
	int dstMatrixId = dst->matrixId;

	// 두 정점을 잇는 간선이 존재하지 않는 경우
	if (edgeMatrix[srcMatrixId][dstMatrixId] == NULL || edgeMatrix[dstMatrixId][srcMatrixId] == NULL)
		return;

	eList.eraseEdge(edgeMatrix[srcMatrixId][dstMatrixId]); // edge 오브젝트 시퀀스에서 삭제하려던 edge 를 삭제
	edgeMatrix[srcMatrixId][dstMatrixId] = NULL;  // 인접행렬의 해당 셀을 NULL 처리
	edgeMatrix[dstMatrixId][srcMatrixId] = NULL;
}
