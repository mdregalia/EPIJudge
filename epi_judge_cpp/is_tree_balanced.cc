#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
#include <algorithm>

using namespace std;

bool heightBalanced(const unique_ptr<BinaryTreeNode<int>>& tree, int* maxheight)
{
	int rightHeight = 0;
	int leftHeight = 0;
	bool balancedRight = true;
	bool balancedLeft = true;
	
	if (tree->right)
	{
		balancedRight = heightBalanced(tree->right, &rightHeight);
	}
	if (tree->left)
	{
		balancedLeft = heightBalanced(tree->left, &leftHeight);
	}

	int heightDiff = rightHeight - leftHeight;
	*maxheight = max(rightHeight, leftHeight) + 1;

	if (heightDiff <= 1 && heightDiff >= -1 && balancedLeft && balancedRight)
	{
		return true;
	}

	return false;
}

bool IsBalanced(const unique_ptr<BinaryTreeNode<int>>& tree) {
  // TODO - you fill in here.
	if (!tree)
	{
		return true;
	}

	int height = 0;
 	return heightBalanced(tree, &height);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_balanced.cc", "is_tree_balanced.tsv",
                         &IsBalanced, DefaultComparator{}, param_names);
}
