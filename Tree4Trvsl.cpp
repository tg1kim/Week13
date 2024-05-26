#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TESTING			// define for testing
#ifdef TESTING
#define NoNODE	11
#else
#define NoNODE	26
#endif

#pragma warning (disable: 4326 4996 6031)

typedef struct node {
	char	nData;
	struct node *plChild;
	struct node *prChild;
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
	return 0;
}

int InorderTrvs(TreePtr pTree, char *sOrder)
{	// 중위 순회를 하여 sOrder에 저장하고 노드 개수를 반환한다
	return 0;
}

int PostorderTrvs(TreePtr pTree, char *sOrder)
{	// 후위 순회를 하여 sOrder에 저장하고 노드 개수를 반환한다
	return 0;
}

TreePtr Tree4InPreorder(char *sInorder, char *sPreorder, int nCtr)
{
	return NULL;
}

TreePtr Tree4InPostorder(char *sInorder, char *sPostorder, int nCtr)
{
	return NULL;
}

bool EqualTree(TreePtr pTree1, TreePtr pTree2)
{
	return true;
}

void FreeTree(TreePtr pTree)
{
	if (pTree) {
		FreeTree(pTree->plChild);
		FreeTree(pTree->prChild);
		free(pTree);
	}
}

void PrintRootLeftRght(TreePtr pTree)
{	// 트리의 모든 노드에 대하여 [D, L, R] 형식으로 출력한다(NULL은 ^)
}