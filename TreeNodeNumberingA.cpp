#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define DebugON			// define for testing
#ifdef DebugON
#define NoNODE	4
#else
#define NoNODE	15
#endif

#pragma warning (disable: 4326 4996)

typedef struct node1 {
	int	nData;
	struct node1 *lChild;
	struct node1 *rChild;
}	Node1, *Node1Ptr, *TreePtr;

typedef struct node2 {
	TreePtr pData;
	struct node2 *link;
}	Node2, *Node2Ptr, Queue, *QueuePtr;

int  MakeTree(TreePtr& pTree);
void Numbering(TreePtr pTree, int nNo);
int  PreorderTrvs(TreePtr pTree, char *sOrder);
int  InorderTrvs(TreePtr pTree, char *sOrder);
int  PostorderTrvs(TreePtr pTree, char *sOrder);
void LevelOrderTrvs(TreePtr pTree, char *sOrder);
void FreeTree(TreePtr pTree);

void main()
{
#ifdef DebugON
	srand((unsigned)1);
#else
	srand((unsigned)time(NULL));
#endif
	char sTrvslOrder[5 * NoNODE];
	while (1) {
		TreePtr pTree = NULL;
		for (int i = 0; i < NoNODE; i++) {
			if (MakeTree(pTree) == false)
				return;
		}
		// Node numbering
		Numbering(pTree, 1);
		// level order
		LevelOrderTrvs(pTree, sTrvslOrder);
		printf("Level order: %s\n", sTrvslOrder);
		// Preorder
		PreorderTrvs(pTree, sTrvslOrder);
		printf("   Preorder: %s\n", sTrvslOrder);
		// inorder
		InorderTrvs(pTree, sTrvslOrder);
		printf("    Inorder: %s\n", sTrvslOrder);
		// postorder
		PostorderTrvs(pTree, sTrvslOrder);
		printf("  Postorder: %s\n", sTrvslOrder);
		// deallocate tree
		FreeTree(pTree);

		printf("\nContinue[y/*] ? ");
		char sAns[10];
		gets_s(sAns);
		if (*sAns != 'y')
			break;
	}
}

int MakeTree(TreePtr& pTree)
{
	if (pTree == NULL) {
		pTree = (Node1Ptr)malloc(sizeof(Node1));
		if (pTree == NULL)
			return false;
		pTree->lChild = pTree->rChild = NULL;
		return true;
	}
	return MakeTree((rand() % 2) ? pTree->lChild : pTree->rChild);
}

void Numbering(TreePtr pTree, int nNo)
{	// 이진트리를 nNo부터 Numbering 한다.
	if (pTree) {
		pTree->nData = nNo;
		nNo *= 2;
		Numbering(pTree->lChild, nNo);
		Numbering(pTree->rChild, nNo + 1);
	}
}

int PreorderTrvs(TreePtr pTree, char *sOrder)
{	// preorder로 순회하여 그 결과를 sOrder에 출력하고 노드 개수를 반환한다.
	int nCtr = 0;
	if (pTree) {
		sprintf(sOrder + 3 * nCtr++, "%-3d", pTree->nData);
		nCtr += PreorderTrvs(pTree->lChild, sOrder + 3 * nCtr);
		nCtr += PreorderTrvs(pTree->rChild, sOrder + 3 * nCtr);
	}
	return nCtr;
}

int InorderTrvs(TreePtr pTree, char *sOrder)
{	// inorder로 순회하여 그 결과를 sOrder에 출력하고 노드 개수를 반환한다.
	int nCtr = 0;
	if (pTree) {
		nCtr += InorderTrvs(pTree->lChild, sOrder + 3 * nCtr);
		sprintf(sOrder + 3 * nCtr++, "%-3d", pTree->nData);
		nCtr += InorderTrvs(pTree->rChild, sOrder + 3 * nCtr);
	}
	return nCtr;
}

int PostorderTrvs(TreePtr pTree, char *sOrder)
{	// postorder로 순회하여 그 결과를 sOrder에 출력하고 노드 개수를 반환한다.
	int nCtr = 0;
	if (pTree) {
		nCtr += PostorderTrvs(pTree->lChild, sOrder + 3 * nCtr);
		nCtr += PostorderTrvs(pTree->rChild, sOrder + 3 * nCtr);
		sprintf(sOrder + 3 * nCtr++, "%-3d", pTree->nData);
	}
	return nCtr;
}

// 큐는 마지막 노드를 가리키는 순환 연결 리스트로 표현된다.
void AddQ(QueuePtr& pQueue, TreePtr pTree)
{	// 마지막 노드로 삽입
	QueuePtr pNew = (Node2Ptr)malloc(sizeof(Node2));
	if (pNew) {
		pNew->pData = pTree;
		if (pQueue) {
			pNew->link = pQueue->link;
			pQueue->link = pNew;
		}
		else
			pNew->link = pNew;
		pQueue = pNew;
	}
}

TreePtr DeleteQ(QueuePtr& pQueue)
{	// 첫 노드를 삭제
	if (pQueue == NULL)
		return NULL;
	QueuePtr pDel = pQueue->link;
	TreePtr pTree = pDel->pData;
	if (pQueue == pDel)
		pQueue = NULL;
	else
		pQueue->link = pDel->link;
	free(pDel);
	return pTree;
}

void LevelOrderTrvs(TreePtr pTree, char *sOrder)
{	// level order로 순회하여 그 결과를 sOrder에 출력한다.
	QueuePtr pQueue = NULL;
	if (pTree) {
		AddQ(pQueue, pTree);
		while (1) {
			if ((pTree = DeleteQ(pQueue)) == NULL)
				break;
			sOrder += sprintf(sOrder, "%-3d", pTree->nData);
			if (pTree->lChild)
				AddQ(pQueue, pTree->lChild);
			if (pTree->rChild)
				AddQ(pQueue, pTree->rChild);
		}
	}
}

void FreeTree(TreePtr pTree)
{	// 이진트리의 모든 노드를 되돌려준다.
	if (pTree) {
		FreeTree(pTree->lChild);
		FreeTree(pTree->rChild);
		free(pTree);
	}
}