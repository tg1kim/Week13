#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#pragma warning (disable: 4326 4996 6031)

typedef struct node{
	static int nCtr;
	int nData;
//	struct node *parent;
	struct node *lChild;
	struct node *rChild;
}	Node, *NodePtr, *TreePtr;

int Node::nCtr = 0;

TreePtr FindTreeByNo(TreePtr pTree, int nNo);
int InsertHeap(NodePtr& pTree, int nData);
int DeleteHeap(NodePtr& pTree, int& nData);

void main()
{
	//srand((unsigned)time(NULL));
	srand((unsigned)17);
	while (1) {
		int nMax;
		printf("노드 개수 ? ");
		scanf("%d", &nMax);
		if (nMax <= 0)
			break;
		NodePtr pTree = NULL;
		pTree->nCtr = 0;
		printf("    [Heap 랜덤 삽입]\n");
		int nData;
		for (int i = 1; i <= nMax; i++) {
			nData = rand() % 1000;		// 무작위로 숫자를 생성한다.
			printf("    [%02d] %d\n", i, nData);
			InsertHeap(pTree, nData);		// Heap에 삽입한다.
		}
		printf("\n    [Heap 삭제]\n");
		for (int i = 1; i <= nMax; i++) {
			DeleteHeap(pTree, nData);		// 하나씩 삭제한다.
			printf("    [%02d] %d\n", i, nData);
		}
		putchar('\n');
	}
	printf("Bye, ...\n\n");
}

int InsertHeap(NodePtr& pTree, int nData)
{	// Heap에 데이타를 삽입하고 성공이면 true, 실패이면 false를 반환한다.
	pNew에 메모리를 할당받고
	if (할당되면) {
		자식들을 NULL로 초기화 한다
		pTree->nCtr를 1 증가하고 nNo에 노드 번호를 저장한다
		if (pTree가 없으면) {
			pNew에 데이터를 저장하고
			pNew가 새로운 트리가 된다
		}
		else {
			pParent에 부모 노드(번호: nParentNo = nNo / 2)를 찾는다
			pParent의 왼쪽 혹은 오른쪽 자식으로 pNew를 연결한다
			pChild에 pNew를 저장한다
			while (pParent가 있고 nData가 부모의 데이터보다 크다) {
				pChild에 pParent의 데이터를 내린다
				pChild에 pParent를 저장한다
				pParent에 부모 노드(번호: nParentNo /= 2)를 찾는다
			}
			pChild에 데이터를 저장한다
		}
	}
	성공 여부를 반환한다
}

int DeleteHeap(NodePtr& pTree, int& nData)
{	// Heap에 데이터를 삭제하고 성공이면 true, 실패하면 false를 반환한다.
	if (pTree가 없다)
		false를 반환한다
	nData에 루트 노드의 데이터를 받아낸다
	pDel에 삭제될 노드(번호: pTree->nCtr)를 찾는다
	pParent에 pDel의 부모 노드(번호: pTree->nCtr / 2)를 찾는다
	pParent의 오른 혹은 왼쪽 자식을 끊어 pDel을 분리한다
	// Max Tree
	nLastData에 삭제할 데이터를 저장한다
	pParent에 루트 노드를 저장한다
	pChild에 루트의 왼쪽 자식을 저장한다
	while (pChild이 존재한다) {
		prChild을 pParent의 오른쪽 자식을 저장한다
		if (오른쪽 자식이 있고 오른쪽 자식이 데이터가 크다)
			pChild에 오른쪽 자식을 저장한다
		if (nLastData가 큰 자식보다 크다)
			break;
		pParent에 자식의 데이터를 저장한다
		pParent에 pChild를 저장한다
		pChild에 왼쪽 자식을 저장한다
	}
	pParent의 데이터에 nLastData를 저장한다
	트리의 노드 수를 1 감소한다
	pDel의 메모리를 반환한다
	true를 반환한다
}

TreePtr FindTreeByNo(TreePtr pRoot, int nNo)
{	// 부모를 찾고 nNo가 짝(홀)수면 왼(오른)쪽 자식이다
	번호는 1번부터 시작되므로
	nNo가 0이면 노드가 없고
	nNo가 1이면 pRoot이고
	아니면 일단 부모 노드(번호: nNo / 2)를 찾고
	nNo가 홀수이면 부모 노드의 왼쪽 자식이고
	nNo가 짝수이면 부모 노드의 오른쪽 자식이다
}