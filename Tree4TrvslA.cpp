#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//#define TESTING			// define for testing
#ifdef TESTING
#define NoNODE	11
#else
#define NoNODE	26
#endif

#pragma warning (disable: 4326 4996 6031)

typedef struct node {
	char	nData;
	struct node *lChild;
	struct node *rChild;
}	Node, *NodePtr, *TreePtr;

int MakeTree(TreePtr& pTree, int nData);
int PreorderTrvs(TreePtr pTree, char *sOrder);
int InorderTrvs(TreePtr pTree, char *sOrder);
int PostorderTrvs(TreePtr pTree, char *sOrder);
TreePtr Tree4InPreorder(char *sInorder, char *sPreorder, int nCtr);
TreePtr Tree4InPostorder(char *sInorder, char *sPostorder, int nCtr);
bool EqualTree(TreePtr pTree1, TreePtr pTree2);
void FreeTree(TreePtr pTree);
void PrintRootLeftRght(TreePtr pTree);

void main()
{
#ifdef TESTING
	srand((unsigned)1);
#else
	srand((unsigned)time(NULL));
#endif
	while (1) {
		char sPreorder[NoNODE+1];
		char sInorder[NoNODE+1];
		char sPostorder[NoNODE+1];
		TreePtr pTree = NULL;
		for (int i = 0; i < NoNODE; i++)
			if (MakeTree(pTree, 'A' + i) == false)
				return;
		printf("[D, L, R]\n---------\n");
		PrintRootLeftRght(pTree);
		putchar('\n');
		PreorderTrvs(pTree, sPreorder);
		printf(" Preorder: %s\n", sPreorder);
		InorderTrvs(pTree, sInorder);
		printf("  Inorder: %s\n", sInorder);
		PostorderTrvs(pTree, sPostorder);
		printf("Postorder: %s\n", sPostorder);

		TreePtr pTree1 = Tree4InPreorder(sInorder, sPreorder, NoNODE);
		TreePtr pTree2 = Tree4InPostorder(sInorder, sPostorder, NoNODE);

		printf("Equal Test1: %d\n", EqualTree(pTree, pTree1));
		printf("Equal Test2: %d\n", EqualTree(pTree, pTree2));

		FreeTree(pTree);
		FreeTree(pTree1);
		FreeTree(pTree2);

		printf("\nContinue(y/*) ? ");
		char cAns;
		scanf(" %c", &cAns);
		if (cAns != 'y')
			break;
	}
}

int MakeTree(TreePtr& pTree, int nData)
{
	if (pTree == NULL) {
		pTree = new Node;
		if (pTree) {
			pTree->nData = nData;
			pTree->lChild = pTree->rChild = NULL;
		}
		return (int)pTree;
	}
	int nChild;
	if (pTree->lChild == NULL && pTree->rChild)
		nChild = 0;
	else if (pTree->lChild && pTree->rChild == NULL)
		nChild = 1;
	else
		nChild = rand() % 2;
	return MakeTree((nChild) ? pTree->rChild : pTree->lChild, nData);
}

int PreorderTrvs(TreePtr pTree, char *sOrder)
{	// 전위 순회를 하여 sOrder에 저장하고 노드 개수를 반환한다
	int nCtr = 0;
	if (pTree) {
		sOrder[nCtr++] = pTree->nData;
		nCtr += PreorderTrvs(pTree->lChild, sOrder + nCtr);
		nCtr += PreorderTrvs(pTree->rChild, sOrder + nCtr);
	}
	sOrder[nCtr] = NULL;
	return nCtr;
}

int InorderTrvs(TreePtr pTree, char *sOrder)
{	// 중위 순회를 하여 sOrder에 저장하고 노드 개수를 반환한다
	int nCtr = 0;
	if (pTree) {
		nCtr += InorderTrvs(pTree->lChild, sOrder + nCtr);
		sOrder[nCtr++] = pTree->nData;
		nCtr += InorderTrvs(pTree->rChild, sOrder + nCtr);
	}
	sOrder[nCtr] = NULL;
	return nCtr;
}

int PostorderTrvs(TreePtr pTree, char *sOrder)
{	// 후위 순회를 하여 sOrder에 저장하고 노드 개수를 반환한다
	int nCtr = 0;
	if (pTree) {
		nCtr += PostorderTrvs(pTree->lChild, sOrder + nCtr);
		nCtr += PostorderTrvs(pTree->rChild, sOrder + nCtr);
		sOrder[nCtr++] = pTree->nData;
	}
	sOrder[nCtr] = NULL;
	return nCtr;
}

TreePtr Tree4InPreorder(char *sInorder, char *sPreorder, int nCtr)
{
	TreePtr pNew = NULL;
	if (nCtr) {
#ifdef  TESTING
		char cIn = sInorder[nCtr], cPre = sPreorder[nCtr];
		sInorder[nCtr] = sPreorder[nCtr] = NULL;
		printf("\nPreOrder: %s\n", sPreorder);
		printf(" InOrder: %s\n", sInorder);
		sInorder[nCtr] = cIn;
		sPreorder[nCtr] = cPre;
#endif
		pNew = new Node;
		if (pNew) {
			pNew->nData = *sPreorder;
			char *pData = strchr(sInorder, pNew->nData);
			char *sLftIn = sInorder, *sRgtIn = pData + 1;
			int nlCtr = pData - sLftIn, nrCtr = nCtr - nlCtr - 1;
			char *sLftPr = sPreorder + 1, *sRgtPr = sLftPr + nlCtr;
			pNew->lChild = Tree4InPreorder(sLftIn, sLftPr, nlCtr);
			pNew->rChild = Tree4InPreorder(sRgtIn, sRgtPr, nrCtr);
		}
	}
	return pNew;
}

TreePtr Tree4InPostorder(char *sInorder, char *sPostorder, int nCtr)
{
	TreePtr pNew = NULL;
	if (nCtr) {
		pNew = new Node;
		if (pNew) {
			pNew->nData = sPostorder[nCtr - 1];
			char *pData = strchr(sInorder, pNew->nData);
			char *sLftIn = sInorder, *sRgtIn = pData + 1;
			int nlCtr = pData - sLftIn, nrCtr = nCtr - nlCtr - 1;
			char *sLftPo = sPostorder, *sRgtPo = sLftPo + nlCtr;
			pNew->lChild = Tree4InPostorder(sLftIn, sLftPo, nlCtr);
			pNew->rChild = Tree4InPostorder(sRgtIn, sRgtPo, nrCtr);
		}
	}
	return pNew;
}

bool EqualTree(TreePtr pTree1, TreePtr pTree2)
{
	if (pTree1 == NULL && pTree2 == NULL)
		return true;
	if (pTree1 == NULL || pTree2 == NULL)
		return false;
	return pTree1 && pTree2 &&
		   pTree1->nData == pTree2->nData &&
		   EqualTree(pTree1->lChild, pTree2->lChild) &&
		   EqualTree(pTree1->rChild, pTree2->rChild);
}

void FreeTree(TreePtr pTree)
{
	if (pTree) {
		FreeTree(pTree->lChild);
		FreeTree(pTree->rChild);
		free(pTree);
	}
}

void PrintRootLeftRght(TreePtr pTree)
{
	if (pTree) {
		printf("[%c, %c, %c]\n", 
			pTree->nData, 
			(pTree->lChild) ? pTree->lChild->nData : '^', 
			(pTree->rChild) ? pTree->rChild->nData : '^');
		PrintRootLeftRght(pTree->lChild);
		PrintRootLeftRght(pTree->rChild);
	}
}