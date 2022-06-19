#include "BSTreeInt.h"

void main()
{
	BSTreeInt tree;
	tree.insert(20);
	tree.insert(10);
	tree.insert(5);
	tree.insert(15);
	tree.insert(30);
	tree.insert(35);
	tree.insert(25);
	tree.insert(40);
	tree.insert(6);
	tree.insert(7);
	tree.insert(8);
	tree.insert(9);
	tree.breadthFirstSearch();
	//tree.findNodeWithLargestRightSubtree();
	//cout << endl << tree.deleteAllLeftLeafes(tree.getRoot()) << endl;
	//tree.breadthFirstSearch();
	BSTNodeInt* node = tree.differenceInNumber();
	cout << endl << node->getKey();
}
