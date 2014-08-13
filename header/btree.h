/*
 * btree.h
 *
 *  Created on: 2014-8-13
 *      Author: Administrator
 */

#ifndef BTREE_H_
#define BTREE_H_

#include <iostream>
#include <stack>

/**
 * 二叉树
 */
class BTree {
public:
	BTree() :
			value(0), left(0), right(0) {

	}

	BTree(int value, BTree *left, BTree *right) :
			value(value), left(left), right(right) {

	}
	/**
	 * 前序遍历（递归）
	 */
	void preOrderTraverseTreeRecursive() {
		this->visit();
		if (this->left) {
			this->left->preOrderTraverseTreeRecursive();
		}
		if (this->right) {
			this->right->preOrderTraverseTreeRecursive();
		}
	}
	/**
	 * 中序遍历（递归）
	 */
	void inOrderTraverseTreeRecursive() {
		if (this->left) {
			this->left->inOrderTraverseTreeRecursive();
		}
		this->visit();
		if (this->right) {
			this->right->inOrderTraverseTreeRecursive();
		}
	}
	/**
	 * 后序遍历（递归）
	 */
	void postOrderTraveseTreeRecursive() {
		if (this->left) {
			this->left->postOrderTraveseTreeRecursive();
		}
		if (this->right) {
			this->right->postOrderTraveseTreeRecursive();
		}
		this->visit();
	}

	/**
	 * 前序遍历（非递归）
	 */
	void preOrderTraverseTree() {
		BTree *root = this;
		if (!root||!stackk->empty()) {
			return;
		}
		BTree *p = root;
		stackk->push(root);
		p->visit();
		while (p || !stackk->empty()) {
			BTree *q = NULL;
			if (p) {
				q = p->left;
			} else {
				q = stackk->top()->right;;
				stackk->pop();
			}
			if (q) {
				stackk->push(q);
				q->visit();
			}
			p = q;
		}

	}
	/**
	 * 中序遍历（非递归）
	 */
	void inOrderTraverseTree() {
		BTree *root = this;
		if (!root||!stackk->empty()) {
			return;
		}
		BTree *p = root;
		while(p||!stackk->empty()){
			while(p){
				stackk->push(p);
				p = p->left;
			}
			BTree *q = stackk->top();
			stackk->pop();
			q->visit();
			p = q->right;
		}
	}
	/**
	 * 后序遍历（非递归）
	 */
	void postOrderTraveseTree() {
		BTree *root = this;
		if (!root||!stackk->empty()) {
			return;
		}
		BTree *p = root;
		while(p||!stackk->empty()){
			while(p){//左节点为空就右节点进桟
				stackk->push(p);
				p = p->left;
				if(!p){
					p = p->right;
				}
			}
			while(!stackk->empty()){//一直出桟，直到当前节点的左节点非空或者桟已经空，令p=p->right;
				p = stackk->top();
				stackk->pop();
				p->visit();
				if(p->left||stackk->empty()){
					p = p->right;
					break;
				}
			}
		}
	}

	void visit() {
		std::cout << value << '\t';
	}

	static std::stack<BTree*> *stackk;
	/**
	 *先序遍历创建二叉树
	 */
	static BTree* createBTreePreOrder() {
		char value = 0;
		std::cin >> value;
		//std::cout << value << endl;
		if (value != '#') {
			BTree *node = new BTree(value, 0, 0);
			node->left = createBTreePreOrder();
			node->right = createBTreePreOrder();
			return node;
		}
		return NULL;
	}

private:
	char value;
	BTree *left;
	BTree *right;
};

#endif /* BTREE_H_ */
