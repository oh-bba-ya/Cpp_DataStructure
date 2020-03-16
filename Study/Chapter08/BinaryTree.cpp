#include "BinaryTree.h"

void main() {
	BinaryTree tree;
	BinaryNode* d = new BinaryNode('D',NULL,NULL);			//자료형 잘볼것.
	BinaryNode* e = new BinaryNode('E', NULL, NULL);
	BinaryNode* b = new BinaryNode('B', NULL, NULL);
	BinaryNode* f = new BinaryNode('F', NULL, NULL);
	BinaryNode* c = new BinaryNode('C', NULL, NULL);
	BinaryNode* a = new BinaryNode('A', NULL, NULL);
	tree.setRoot(a);
	tree.inorder();
	tree.preorder();
	tree.postorder();
	printf("\n");
	tree.levelorder();
	printf(" 노드의 개수 = %d\n", tree.getCount());
	printf(" 단말의 개수 = %d\n", tree.getLeafCount());
	printf(" 트리의 높이 = %d\n", tree.getHeight());
}
