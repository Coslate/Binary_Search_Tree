#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_
#include <cstdlib>
class BST;

class BSTNode{
        int key;
        BSTNode* parent;
        BSTNode* left_child;
        BSTNode* right_child;
    public : 
        BSTNode() : key(0), parent(NULL), left_child(NULL), right_child(NULL){};
        BSTNode(const int value) : key(value), parent(NULL), left_child(NULL), right_child(NULL){};

        friend class BST;
};

class BST{
        BSTNode* root;
        int size_of_tree;
    protected:
        BSTNode* FindInOrderSuccessor(BSTNode* current_node);
        BSTNode* FindInOrderPreDecessor(BSTNode* current_node);
        BSTNode* SearchLeftMostEngine(BSTNode* current_node);
        BSTNode* SearchRightMostEngine(BSTNode* current_node);
        void InOrderTraverseEngine(BSTNode* current_node);
        void InOrderTraverseSetEngine(BSTNode* current_node, int &set_index, const int* const L);
        void PreOrderTraverseEngine(BSTNode* current_node);
        void PostOrderTraverseEngine(BSTNode* current_node);

    public : 
        BST() : root(NULL), size_of_tree(0){};
        ~BST();

        void Search(const int key, BSTNode* &return_node, BSTNode* &return_parent_node);

        void CleanAll();
        void InsertArbitrary(const int key);
        void DeleteArbitrary(const int key);
        void InOrderTraversePrint();
        void PreOrderTraversePrint();
        void PostOrderTraversePrint();
        void LevelOrderTraversePrint();
        void SearchLeftMostPrint();
        void SearchRightMostPrint();
        void SearchInorderSuccessorOfSmallestPrint();
        void SearchInorderPreDecessorOfBiggestPrint();
        void ConstructBSTUsingSorting(const int* const L, const int size);
        int GetTreeSize();

};

#endif
