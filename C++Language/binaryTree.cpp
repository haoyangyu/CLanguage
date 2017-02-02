#include <iostream>

template <typename T>
struct TreeNode {
	T nodeData;
	TreeNode *left;
	TreeNode *right;
};

template <typename T>
void preOrderPrint(TreeNode<T> *node) {
	if (node != NULL) {
		std::cout<<node->nodeData<<std::endl;
		preOrderPrint(node->left);
		preOrderPrint(node->right);
	}
}

template <typename T>
void preOrderPrint(std::unique_ptr<TreeNode<T>> node) {
	if (node != NULL) {
		std::cout<<node->nodeData<<std::endl;
		preOrderPrint(node->left);
		preOrderPrint(node->right);
	}
}

template <typename T>
void inOrderPrint(TreeNode<T> *node) {
	if (node != NULL) {
		inOrderPrint(node->left);
		std::cout<<node->nodeData<<std::endl;
		inOrderPrint(node->right);
	}
}

template <typename T>
void postOrderPrint(TreeNode<T> *node) {
	if (node != NULL) {
		postOrderPrint(node->left);
		postOrderPrint(node->right);
		std::cout<<node->nodeData<<std::endl;
	}
}

int main(int argc, char const *argv[])
{
	//version 1 by using new and delete to allocate memory space
	TreeNode<int> *node1 = new TreeNode<int>;
	TreeNode<int> *node2 = new TreeNode<int>;
	TreeNode<int> *node3 = new TreeNode<int>;

	node1->nodeData = 1;
	node2->nodeData = 2;
	node3->nodeData = 3;

	node1->left = node2;
	node1->right = node3;
	node2->left = NULL;
	node2->right = NULL;
	node3->left = NULL;
	node3->right = NULL;

	std::cout<<"preOrderPrint"<<std::endl;
	preOrderPrint(node1);
	std::cout<<"inOrderPrint"<<std::endl;
	inOrderPrint(node1);
	std::cout<<"postOrderPrint"<<std::endl;
	postOrderPrint(node1);

	delete node1;
	delete node2;
	delete node3;

	return 0;
}