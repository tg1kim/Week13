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
	NodePtr pNew = new Node;
	if (pNew) {
		pNew->lChild = pNew->rChild = NULL;
		int nNo = ++pTree->nCtr, nParentNo;
		if (pTree == NULL) {
			pNew->nData = nData;
			pTree = pNew;
		}
		else {
			TreePtr pParent = FindTreeByNo(pTree, nParentNo = nNo / 2);
			nNo % 2 ? pParent->rChild = pNew : pParent->lChild = pNew;
			TreePtr pChild = pNew;
			while (pParent && nData > pParent->nData) {
				pChild->nData = pParent->nData;
				pChild = pParent;
				pParent = FindTreeByNo(pTree, nParentNo /= 2);
			}
			pChild->nData = nData;
		}
	}
	return pNew !=NULL;
}

int DeleteHeap(NodePtr& pTree, int& nData)
{	// Heap에 데이터를 삭제하고 성공이면 true, 실패하면 false를 반환한다.
	if (pTree == NULL)
		return false;
	// Data 받고
	nData = pTree->nData;
	// Link 조작
	NodePtr pDel = FindTreeByNo(pTree, pTree->nCtr);		// Last Node
	NodePtr pParent = FindTreeByNo(pTree, pTree->nCtr / 2);
	if (pParent)
		(pTree->nCtr % 2) ? pParent->rChild = NULL : pParent->lChild = NULL;
	// Max Tree
	int nLastData = pDel->nData;
	pParent = pTree;
	NodePtr pChild = pTree->lChild;
	while (pChild) {
		NodePtr prChild = pParent->rChild;
		if (prChild && pChild->nData < prChild->nData)
			pChild = prChild;
		if (nLastData >= pChild->nData)
			break;
		pParent->nData = pChild->nData;
		pParent = pChild;
		pChild = pParent->lChild;
	}
	pParent->nData = nLastData;
	pTree->nCtr--;
	delete pDel;
	return true;
}

TreePtr FindTreeByNo(TreePtr pRoot, int nNo)
{	// 부모를 찾고 nNo가 짝(홀)수면 왼(오른)쪽 자식이다
	if (nNo <= 1)
		return (nNo == 1) ? pRoot : NULL;
	TreePtr pParent = FindTreeByNo(pRoot, nNo / 2);
	return (nNo % 2) ? pParent->rChild : pParent->lChild;
}