#include <iostream>
#include <memory>

using namespace std;

template <typename T>
class binarySearchTree {
public:
	T data;
	shared_ptr<binarySearchTree<T>> left, right;
	binarySearchTree(T data): data(data), left(nullptr), right(nullptr) {};
	binarySearchTree(T data, shared_ptr<binarySearchTree<T>> left, shared_ptr<binarySearchTree<T>> right):
							data(data),left(left), right(right) {};
};

//pre-situation: current has left side
template <typename T>
shared_ptr<binarySearchTree<T>> findPredecessor(shared_ptr<binarySearchTree<T>> current) {
	current = current->left;
	while (current->right != nullptr) {
		current = current->right;
	}
	return current;
}

template <typename T>
bool isBinarySearchTreeByInOrder(shared_ptr<binarySearchTree<T>> ptr) {
	shared_ptr<binarySearchTree<T>> current = ptr;
	bool isBinarySearchTreeByInOrderResult = true;
	T previousData;

	while (current != nullptr) {
		if (current->left == nullptr) {
			cout<< current->data <<endl;
			current = current->right;
		} else {
			shared_ptr<binarySearchTree<T>> predecessor = findPredecessor(current);
			//create the predecessor link to current one	
			if (predecessor->right == nullptr) {
				predecessor->right = current;
				current = current->left;
			} else {
				predecessor->right = nullptr;
				std::cout<< current->data <<std::endl;
				current = current->right;
			}
		}
	}
	return isBinarySearchTreeByInOrderResult;
}

template <typename T>
void inOrderPrint(shared_ptr<binarySearchTree<T>> node) {
	if (node != nullptr) {
		inOrderPrint(node->left);
		std::cout<<node->data<<std::endl;
		inOrderPrint(node->right);
	}
}


int main() {
	// the tree looks like:
	/*
					10
				   *  *
				  5    30
				 * *     *
				-2  6     40
				  *	 *
				   2  8
				  *				
				 -1
	*/
	shared_ptr<binarySearchTree<int>> root(new binarySearchTree<int>(10));
	shared_ptr<binarySearchTree<int>> ptr1(new binarySearchTree<int>(5));
	shared_ptr<binarySearchTree<int>> ptr2(new binarySearchTree<int>(-2));
	shared_ptr<binarySearchTree<int>> ptr3(new binarySearchTree<int>(2));
	shared_ptr<binarySearchTree<int>> ptr4(new binarySearchTree<int>(-1));
	shared_ptr<binarySearchTree<int>> ptr5(new binarySearchTree<int>(6));
	shared_ptr<binarySearchTree<int>> ptr6(new binarySearchTree<int>(8));
	shared_ptr<binarySearchTree<int>> ptr7(new binarySearchTree<int>(30));
	shared_ptr<binarySearchTree<int>> ptr8(new binarySearchTree<int>(40));

	root->left = ptr1;
	root->right = ptr7;
	ptr1->left = ptr2;
	ptr1->right = ptr5;
	ptr2->right = ptr3;
	ptr3->left = ptr4;
	ptr5->right = ptr6;
	ptr7->right = ptr8;
	//the inorder traverse should look like
	//-1, 2, -2, 5, 6, 8, 10, 30, 40
	isBinarySearchTreeByInOrder<int>(root);
	//inOrderPrint(root);
}