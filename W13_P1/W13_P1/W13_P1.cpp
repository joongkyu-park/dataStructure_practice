﻿#include<iostream>
#include<string>
#include<vector>

using namespace std;

class vertex {
public:
	int index;
	int number;

	vertex(int number, int index) {
		this->number = number;
		this->index = index;
	}
};
class edge {
public:
	vertex* v;
	vertex* u;

	edge(vertex* v, vertex* u) {
		this->v = v;
		this->u = u;
	}

	vertex* oppostie(vertex* v) {
		if (v == this->v)
			return u;
		else
			return v;
	}
};

class graph {
public:
	vector<vertex*> vertices_list;
	vector<edge*> edges_list;

	vector<vector<int>> adjacency_matrix;

	graph(int N) {
		vector<vector<int>> *tmp = new vector<vector<int>>(N, vector<int>(N,0));
		adjacency_matrix = *tmp;
	}

	void insert_vertex(int number,int index) {
		vertex* v = new vertex(number, index);

		this->vertices_list.push_back(v);
	}

	void insert_edge(int num1, int num2) {
		vertex* v = NULL;
		vertex* u = NULL;
		for (int i = 0; i < this->vertices_list.size();i++) {
			if (this->vertices_list[i]->number == num1) {
				v = this->vertices_list[i];
			}
			if (this->vertices_list[i]->number == num2) {
				u = this-> vertices_list[i];
			}
		}
		
		if (v == NULL || u == NULL) {
			cout << -1 << endl;
			return;
		}

		if (this->adjacency_matrix[v->index][u->index] == 1) {
			cout << -1 << endl;
			return;
		}
		else {
			edge* e = new edge(v,u);
			this->adjacency_matrix[v->index][u->index] = 1;
			this->adjacency_matrix[u->index][v->index] = 1;

			this->edges_list.push_back(e);
			return;
		}

	}
};



int main() {
	int N;
	cin >> N;

	int M;
	cin >> M;

	graph g(N);

	int index = 0;
	while (N--) {
		int I;
		cin >> I;

		
		g.insert_vertex(I,index);
		index++;
	}

	while (M--) {
		int S, D;
		cin >> S >> D;

		g.insert_edge(S, D);
	}

	cout << g.vertices_list.size() << " " << g.edges_list.size() << endl;
}



































//#define MappingSize 501
//
//class vertex {
//public:
//	vertex* prev;
//	vertex* next;
//	int degree;
//	int data;
//	vertex(int data) {
//		this->degree = 0;
//		this->data = data;
//	}
//	void increase_degree() {
//		this->degree++;
//	}
//	void decrease_degree() {
//		this->degree--;
//	}
//};
//
//class edge {
//public:
//	edge* prev;
//	edge* next;
//	vertex* source;
//	vertex* destination;
//	string data;
//	edge(vertex* a, vertex* b, string data) {
//		this->source = a;
//		this->destination = b;
//		this->data = data;
//	}
//};
//
//class DoublyVertexLinkedList {	//vertex로 이루어진 이중연결리스트
//public:
//	vertex* head;
//	vertex* tail;
//	DoublyVertexLinkedList() {
//		this->head = NULL;
//		this->tail = NULL;
//	}
//	void insert(vertex* insertVertex) {
//		if (this->head == NULL) {
//			head = insertVertex;
//			tail = insertVertex;
//		}
//		else {
//			tail->next = insertVertex;
//			insertVertex->prev = tail;
//			tail = insertVertex;
//		}
//	}
//	void remove(vertex* delVertex) {
//		if (delVertex == head || delVertex == tail) {
//			if (delVertex == head && delVertex != tail) {
//				vertex* temp = head;
//				head = head->next;
//				head->prev = NULL;
//				delete temp;
//			}
//			else if (delVertex == tail && delVertex != head) {
//				vertex* temp = tail;
//				tail = tail->prev;
//				tail->next = NULL;
//				delete temp;
//			}
//			else { head = tail = NULL; }
//		}
//		else {
//			delVertex->prev->next = delVertex->next;
//			delVertex->next->prev = delVertex->prev;
//			delete delVertex;
//		}
//	}
//};
//
//class DoublyEdgeLinkedList {		//edge로 이루어진 이중연결리스트
//public:
//	edge* head;
//	edge* tail;
//	DoublyEdgeLinkedList() {
//		this->head = NULL;
//		this->tail = NULL;
//	}
//	void insert(edge* insertEdge) {
//		if (this->head == NULL) {
//			head = insertEdge;
//			tail = insertEdge;
//		}
//		else {
//			tail->next = insertEdge;
//			insertEdge->prev = tail;
//			tail = insertEdge;
//		}
//	}
//	void remove(edge* delEdge) {
//		if (delEdge == head || delEdge == tail) {
//			if (delEdge == head && delEdge != tail) {
//				edge* temp = head;
//				head = head->next;
//				head->prev = NULL;
//				delete temp;
//			}
//			else if (delEdge == tail && delEdge != head) {
//				edge* temp = tail;
//				tail = tail->prev;
//				tail->next = NULL;
//				delete temp;
//			}
//			else { head = tail = NULL; }
//		}
//		else {
//			delEdge->prev->next = delEdge->next;
//			delEdge->next->prev = delEdge->prev;
//			delete delEdge;
//		}
//	}
//};
//
//class graph {
//public:
//	edge*** edgeMatrix;						//edge정보를 관리하는 matrix
//	DoublyVertexLinkedList* VertexList;		//전체 vertex정보를 관리하는 이중연결리스트
//	DoublyEdgeLinkedList* EdgeList;			//전체 edge정보를 관리하는 이중연결리스트
//	int vertexSize;							//그래프에 존재하는 vertex의 개수
//	int edgeSize;
//	int mappingTable[MappingSize];			// vertex의 고유한 번호와 
//											// 해당 veretx의 matrix에서 index로 매핑
//	graph() {
//		this->VertexList = new DoublyVertexLinkedList();
//		this->EdgeList = new DoublyEdgeLinkedList();
//		this->vertexSize = 0;
//		this->edgeSize = 0;
//		for (int i = 0; i < MappingSize; i++)mappingTable[i] = -1;
//		this->edgeMatrix = new edge * *[1];
//		this->edgeMatrix[0] = new edge * [1];
//		this->edgeMatrix[0][0] = NULL;
//	}
//	bool isfindVertex(int n) {		// VertexList에서 고유한 번호가 n인 vertex의 존재 유무 검사
//		bool flag = false;
//		vertex* temp = VertexList->head;
//		while (temp != NULL) {
//			if (temp->data == n) {
//				flag = true;
//				break;
//			}
//			temp = temp->next;
//		}
//		return flag;
//	}
//	vertex* findVertex(int n) {				// VertexList에서 고유한 번호가 n인 
//		vertex* temp = VertexList->head;    //vertex의 주소 반환
//		while (temp != NULL) {
//			if (temp->data == n) {
//				break;
//			}
//			temp = temp->next;
//		}
//		return temp;
//	}
//
//	void insert_vertex(int n) {			// 그래프에 고유한 번호가 n인 vertex 삽입
//		if (isfindVertex(n) == true) {
//			return;
//		}
//
//		else {
//			edge*** tempMatrix = new edge * *[vertexSize + 1];  //정점이 1개 추가될 때마다 
//			for (int i = 0; i < vertexSize + 1; i++) {        //기존 matrix보다 가로, 세로 길이가 1만큼 
//				tempMatrix[i] = new edge * [vertexSize + 1];	  //더 큰 tempmatrix 생성
//				for (int j = 0; j < vertexSize + 1; j++) {
//					tempMatrix[i][j] = NULL;
//				}
//			}
//
//			for (int i = 0; i < vertexSize; i++) {
//				for (int j = 0; j < vertexSize; j++) {
//					tempMatrix[i][j] = this->edgeMatrix[i][j];	 //element들  copy
//				}
//			}
//
//			//for (int i = 0; i < vertexSize; i++) {
//			//	
//			//		delete this->edgeMatrix[i];	 //element들  copy
//			//	
//			//}
//			//delete this->edgeMatrix;
//
//			this->edgeMatrix = tempMatrix;
//
//			vertex* newVertex = new vertex(n);
//			VertexList->insert(newVertex);						//VertexList에 고유번호가 n인 vertex 추가
//			this->vertexSize++;
//			mappingTable[vertexSize - 1] = n;					// mappingtable에 vertex 자신이 
//		}														//matrix의 어느 index인지 저장
//	}
//
//
//	void erase_vertex(int n) {                          // 그래프에 고유한 번호가 n인 vertex 제거
//		if (isfindVertex(n) == false || vertexSize == 0) {
//			return;
//		}
//		else {
//			edge*** tempMatrix = new edge * *[vertexSize - 1]; //정점이 1개 삭제될 때마다
//			for (int i = 0; i < vertexSize - 1; i++) {       //기존 matrix보다 가로, 세로 길이가 1만큼
//				tempMatrix[i] = new edge * [vertexSize - 1];   //더 작은 tempmatrix 생성
//				for (int j = 0; j < vertexSize - 1; j++) {
//					tempMatrix[i][j] = NULL;
//				}
//			}
//
//			int middleIdx = 0;
//			for (int i = 0; i < vertexSize; i++) {
//				if (mappingTable[i] == n)middleIdx = i;		//middleidx: 삭제할 vertex의 matrix에서의 인덱스
//			}
//			for (int i = middleIdx; i < vertexSize; i++) {	// mappingtable update
//				mappingTable[i] = mappingTable[i + 1];
//			}
//
//
//			for (int i = 0; i < vertexSize; i++) {			//EdgeList에서 고유번호가 n인 vertex와 연결된 모든 edge들 제거
//				if (this->edgeMatrix[middleIdx][i] != NULL) {
//					EdgeList->remove(this->edgeMatrix[middleIdx][i]);
//				}
//			}
//
//			for (int i = 0; i < vertexSize; i++) {			//middleidx를 기점으로 element들을 적절히 copy
//				for (int j = 0; j < vertexSize; j++) {
//					if (i < middleIdx && j < middleIdx) {
//						tempMatrix[i][j] = this->edgeMatrix[i][j];
//					}
//					else if (i > middleIdx && j > middleIdx) {
//						tempMatrix[i - 1][j - 1] = this->edgeMatrix[i][j];
//					}
//					else if (j > middleIdx) {
//						tempMatrix[i][j - 1] = this->edgeMatrix[i][j];
//					}
//					else if (i > middleIdx) {
//						tempMatrix[i - 1][j] = this->edgeMatrix[i][j];
//					}
//				}
//			}
//			this->edgeMatrix = tempMatrix;
//			VertexList->remove(findVertex(n));			//VertexList에 고유번호가 n인 vertex 제거
//			this->vertexSize--;
//
//		}
//	}
//
//	void insert_edge(int indirectSource, int IndirectDestination, string data) {
//		if (isfindVertex(indirectSource) == false || isfindVertex(IndirectDestination) == false) {
//			cout << -1 << endl;
//			return;
//		}
//
//		int destination = -1;
//		int source = -1;
//		for (int i = 0; i <= vertexSize; i++) {
//			if (mappingTable[i] == IndirectDestination)destination = i;
//			if (mappingTable[i] == indirectSource)source = i;
//			if (source != -1 && destination != -1)break;
//		}
//
//		if (edgeMatrix[source][destination] != NULL || edgeMatrix[destination][source] != NULL) {
//			cout << -1 << endl;
//			return;
//		}
//
//		edge* newEdge = new edge(findVertex(indirectSource), findVertex(IndirectDestination), data);
//		edgeMatrix[source][destination] = newEdge;
//		edgeMatrix[destination][source] = newEdge;
//
//		findVertex(indirectSource)->increase_degree();
//		findVertex(IndirectDestination)->increase_degree();
//
//		this->edgeSize++;
//
//		EdgeList->insert(newEdge);
//	}
//
//	void erase_edge(int indirectSource, int IndirectDestination) {
//		int destination = -1;
//		int source = -1;
//		for (int i = 0; i <= vertexSize; i++) {
//			if (mappingTable[i] == IndirectDestination)destination = i;
//			if (mappingTable[i] == indirectSource)source = i;
//			if (source != -1 && destination != -1)break;
//		}
//
//		if (edgeMatrix[source][destination] == NULL || edgeMatrix[destination][source] == NULL)return;
//		findVertex(indirectSource)->decrease_degree();
//		findVertex(IndirectDestination)->decrease_degree();
//
//		edge* delEdge = edgeMatrix[source][destination];
//		EdgeList->remove(delEdge);
//
//		this->edgeSize--;
//
//		edgeMatrix[source][destination] = NULL;
//		edgeMatrix[destination][source] = NULL;
//	}
//
//
//
//};
//
//
//
//int main()
//{
//	int N, M;
//	cin >> N >> M;
//
//	graph g;
//
//	int tmp = N;
//	while (tmp--) {
//		int vertex;
//		cin >> vertex;
//		g.insert_vertex(vertex);
//	}
//	while (M--) {
//		int s, d;
//		cin >> s >> d;
//		g.insert_edge(s, d,"");
//	}
//
//	cout << g.vertexSize << " " << g.edgeSize << endl;
//}
