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
		printf("��� ���� ? ");
		scanf("%d", &nMax);
		if (nMax <= 0)
			break;
		NodePtr pTree = NULL;
		pTree->nCtr = 0;
		printf("    [Heap ���� ����]\n");
		int nData;
		for (int i = 1; i <= nMax; i++) {
			nData = rand() % 1000;		// �������� ���ڸ� �����Ѵ�.
			printf("    [%02d] %d\n", i, nData);
			InsertHeap(pTree, nData);		// Heap�� �����Ѵ�.
		}
		printf("\n    [Heap ����]\n");
		for (int i = 1; i <= nMax; i++) {
			DeleteHeap(pTree, nData);		// �ϳ��� �����Ѵ�.
			printf("    [%02d] %d\n", i, nData);
		}
		putchar('\n');
	}
	printf("Bye, ...\n\n");
}

int InsertHeap(NodePtr& pTree, int nData)
{	// Heap�� ����Ÿ�� �����ϰ� �����̸� true, �����̸� false�� ��ȯ�Ѵ�.
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
{	// Heap�� �����͸� �����ϰ� �����̸� true, �����ϸ� false�� ��ȯ�Ѵ�.
	if (pTree == NULL)
		return false;
	// Data �ް�
	nData = pTree->nData;
	// Link ����
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
{	// �θ� ã�� nNo�� ¦(Ȧ)���� ��(����)�� �ڽ��̴�
	if (nNo <= 1)
		return (nNo == 1) ? pRoot : NULL;
	TreePtr pParent = FindTreeByNo(pRoot, nNo / 2);
	return (nNo % 2) ? pParent->rChild : pParent->lChild;
}