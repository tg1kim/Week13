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
	pNew�� �޸𸮸� �Ҵ�ް�
	if (�Ҵ�Ǹ�) {
		�ڽĵ��� NULL�� �ʱ�ȭ �Ѵ�
		pTree->nCtr�� 1 �����ϰ� nNo�� ��� ��ȣ�� �����Ѵ�
		if (pTree�� ������) {
			pNew�� �����͸� �����ϰ�
			pNew�� ���ο� Ʈ���� �ȴ�
		}
		else {
			pParent�� �θ� ���(��ȣ: nParentNo = nNo / 2)�� ã�´�
			pParent�� ���� Ȥ�� ������ �ڽ����� pNew�� �����Ѵ�
			pChild�� pNew�� �����Ѵ�
			while (pParent�� �ְ� nData�� �θ��� �����ͺ��� ũ��) {
				pChild�� pParent�� �����͸� ������
				pChild�� pParent�� �����Ѵ�
				pParent�� �θ� ���(��ȣ: nParentNo /= 2)�� ã�´�
			}
			pChild�� �����͸� �����Ѵ�
		}
	}
	���� ���θ� ��ȯ�Ѵ�
}

int DeleteHeap(NodePtr& pTree, int& nData)
{	// Heap�� �����͸� �����ϰ� �����̸� true, �����ϸ� false�� ��ȯ�Ѵ�.
	if (pTree�� ����)
		false�� ��ȯ�Ѵ�
	nData�� ��Ʈ ����� �����͸� �޾Ƴ���
	pDel�� ������ ���(��ȣ: pTree->nCtr)�� ã�´�
	pParent�� pDel�� �θ� ���(��ȣ: pTree->nCtr / 2)�� ã�´�
	pParent�� ���� Ȥ�� ���� �ڽ��� ���� pDel�� �и��Ѵ�
	// Max Tree
	nLastData�� ������ �����͸� �����Ѵ�
	pParent�� ��Ʈ ��带 �����Ѵ�
	pChild�� ��Ʈ�� ���� �ڽ��� �����Ѵ�
	while (pChild�� �����Ѵ�) {
		prChild�� pParent�� ������ �ڽ��� �����Ѵ�
		if (������ �ڽ��� �ְ� ������ �ڽ��� �����Ͱ� ũ��)
			pChild�� ������ �ڽ��� �����Ѵ�
		if (nLastData�� ū �ڽĺ��� ũ��)
			break;
		pParent�� �ڽ��� �����͸� �����Ѵ�
		pParent�� pChild�� �����Ѵ�
		pChild�� ���� �ڽ��� �����Ѵ�
	}
	pParent�� �����Ϳ� nLastData�� �����Ѵ�
	Ʈ���� ��� ���� 1 �����Ѵ�
	pDel�� �޸𸮸� ��ȯ�Ѵ�
	true�� ��ȯ�Ѵ�
}

TreePtr FindTreeByNo(TreePtr pRoot, int nNo)
{	// �θ� ã�� nNo�� ¦(Ȧ)���� ��(����)�� �ڽ��̴�
	��ȣ�� 1������ ���۵ǹǷ�
	nNo�� 0�̸� ��尡 ����
	nNo�� 1�̸� pRoot�̰�
	�ƴϸ� �ϴ� �θ� ���(��ȣ: nNo / 2)�� ã��
	nNo�� Ȧ���̸� �θ� ����� ���� �ڽ��̰�
	nNo�� ¦���̸� �θ� ����� ������ �ڽ��̴�
}