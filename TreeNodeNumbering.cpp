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
{	// ����Ʈ���� nNo���� Numbering �Ѵ�.
	if (pTree) {
		// pTree�� nData�� nNo�� �����Ѵ�
		// pTree�� lChild�� 2 * nNo���� Numbering �Ѵ�
		// pTree�� rChild�� 2 * nNo + 1���� Numbering �Ѵ�
	}
}

int PreorderTrvs(TreePtr pTree, char *sOrder)
{	// preorder�� ��ȸ�Ͽ� �� ����� sOrder�� ����ϰ� ��� ������ ��ȯ�Ѵ�.
	// nCtr�� �ʱ�ȭ �Ѵ�
	if (pTree) {
		// sOrder�� "%-3d" �������� pTree->nData�� ����ϰ� nCtr�� 1 �����Ѵ�
		// pTree�� lChild�� ��ȸ�Ͽ� sOrder ���� �߰� �ϰ� nCtr�� ��ȯ�� ����ŭ �����Ѵ�
		// pTree�� rChild�� ��ȸ�Ͽ� sOrder ���� �߰� �ϰ� nCtr�� ��ȯ�� ����ŭ �����Ѵ�
	}
	return 0; // nCtr�� ��ȯ�Ѵ�
}

int InorderTrvs(TreePtr pTree, char *sOrder)
{	// inorder�� ��ȸ�Ͽ� �� ����� sOrder�� ����ϰ� ��� ������ ��ȯ�Ѵ�.
	// nCtr�� �ʱ�ȭ �Ѵ�
	if (pTree) {
		// pTree�� lChild�� ��ȸ�Ͽ� sOrder ���� �߰� �ϰ� nCtr�� ��ȯ�� ����ŭ �����Ѵ�
		// sOrder�� "%-3d" �������� pTree->nData�� ����ϰ� nCtr�� 1 �����Ѵ�
		// pTree�� rChild�� ��ȸ�Ͽ� sOrder ���� �߰� �ϰ� nCtr�� ��ȯ�� ����ŭ �����Ѵ�
	}
	return 0; // nCtr�� ��ȯ�Ѵ�
}

int PostorderTrvs(TreePtr pTree, char *sOrder)
{	// postorder�� ��ȸ�Ͽ� �� ����� sOrder�� ����ϰ� ��� ������ ��ȯ�Ѵ�.
	// nCtr�� �ʱ�ȭ �Ѵ�
	if (pTree) {
		// pTree�� lChild�� ��ȸ�Ͽ� sOrder ���� �߰� �ϰ� nCtr�� ��ȯ�� ����ŭ �����Ѵ�
		// pTree�� rChild�� ��ȸ�Ͽ� sOrder ���� �߰� �ϰ� nCtr�� ��ȯ�� ����ŭ �����Ѵ�
		// sOrder�� "%-3d" �������� pTree->nData�� ����ϰ� nCtr�� 1 �����Ѵ�
	}
	return 0; // nCtr�� ��ȯ�Ѵ�
}

// ť�� ������ ��带 ����Ű�� ��ȯ ���� ����Ʈ�� ǥ���ȴ�.
void AddQ(QueuePtr& pQueue, TreePtr pTree)
{	// ������ ���� ����
}

TreePtr DeleteQ(QueuePtr& pQueue)
{	// ù ��带 ����
	return NULL;
}

void LevelOrderTrvs(TreePtr pTree, char *sOrder)
{	// level order�� ��ȸ�Ͽ� �� ����� sOrder�� ����Ѵ�.
	// pQueue�� �ʱ�ȭ �Ѵ�
	if (pTree) {
		// pQueue�� pTree�� �����Ѵ�
		while (1) {
			// pTree�� pQueue�� �����Ͽ� NULL�� �ƴϸ�
				break;
			// sOrder�� "%-3d" �������� pTree->nData�� �����ϰ� sOrder�� 3 �����Ѵ�
			// pTree�� lChild�� �����ϸ�
				// pQueue�� pTree->lChild�� �����Ѵ�
			// pTree�� rChild�� �����ϸ�
				// pQueue�� pTree->rChild�� �����Ѵ�
		}
	}
}

void FreeTree(TreePtr pTree)
{	// ����Ʈ���� ��� ��带 �ǵ����ش�.
	if (pTree) {
		// pTree->lChild�� ��� ��带 ��ȯ�Ѵ�
		// pTree->rChild�� ��� ��带 ��ȯ�Ѵ�
		// pTree�� ��Ʈ ��带 ��ȯ�Ѵ�
	}
}