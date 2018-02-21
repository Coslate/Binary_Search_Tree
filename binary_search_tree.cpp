#include <iostream>
#include <cstdio>
#include <queue>
#include <binary_search_tree.h>

BST::~BST(){
    CleanAll();
}

void BST::CleanAll(){
    if(root == NULL){
        return;
    }

    std::queue<BSTNode*> printed_queue;
    printed_queue.push(root);

    while(!printed_queue.empty()){
        BSTNode* current_node = printed_queue.front();
        printed_queue.pop();
        
        if(current_node->left_child != NULL){
            printed_queue.push(current_node->left_child);
        }
        if(current_node->right_child != NULL){
            printed_queue.push(current_node->right_child);
        }
        current_node->left_child = NULL;
        current_node->right_child = NULL;
        delete current_node;        
    }
}

int BST::GetTreeSize(){
    return size_of_tree;
}

void BST::Search(const int key, BSTNode* &return_node, BSTNode* &return_parent_node){
    BSTNode* current_node = root;
    BSTNode* current_parrent_node = root->parent;

    while(current_node != NULL){
        if(key == current_node->key){
            break;
        }else if(key > current_node->key){
            current_parrent_node = current_node;
            current_node = current_node->right_child;
        }else{
            current_parrent_node = current_node;
            current_node = current_node->left_child;
        }
    }
    return_node = current_node;
    return_parent_node = current_parrent_node;
}

void BST::InsertArbitrary(const int key){
    BSTNode* new_added_node = new BSTNode(key);

    if(size_of_tree == 0){
        root = new_added_node;
        ++size_of_tree;
    }else{
        BSTNode* found_node = NULL;
        BSTNode* found_parent_node = NULL;

        Search(key, found_node, found_parent_node);
        if(found_node == NULL){
            if(key < found_parent_node->key){
               found_parent_node->left_child = new_added_node;
            }else{
               found_parent_node->right_child = new_added_node;
            }
            new_added_node->parent = found_parent_node;
        }else{
            found_node->left_child = new_added_node;
            new_added_node->parent = found_node;
        }
        ++size_of_tree;
    }
}

void BST::InOrderTraverseEngine(BSTNode* current_node){
    if(current_node != NULL){
        InOrderTraverseEngine(current_node->left_child);
        std::cout<<current_node->key<<" ";
        InOrderTraverseEngine(current_node->right_child);
    }
}

void BST::InOrderTraverseSetEngine(BSTNode* current_node, int &set_index, const int* const L){
    if(current_node != NULL){
        InOrderTraverseSetEngine(current_node->left_child, set_index, L);
        current_node->key = L[set_index];
        ++set_index;
        InOrderTraverseSetEngine(current_node->right_child, set_index, L);
    }
}

void BST::InOrderTraversePrint(){
    InOrderTraverseEngine(root);
    std::cout<<std::endl;
}

void BST::PreOrderTraverseEngine(BSTNode* current_node){
    if(current_node != NULL){
        std::cout<<current_node->key<<" ";
        PreOrderTraverseEngine(current_node->left_child);
        PreOrderTraverseEngine(current_node->right_child);
    }
}

void BST::PreOrderTraversePrint(){
    PreOrderTraverseEngine(root);
    std::cout<<std::endl;
}

void BST::PostOrderTraverseEngine(BSTNode* current_node){
    if(current_node != NULL){
        PostOrderTraverseEngine(current_node->left_child);
        PostOrderTraverseEngine(current_node->right_child);
        std::cout<<current_node->key<<" ";
    }
}

void BST::PostOrderTraversePrint(){
    PostOrderTraverseEngine(root);
    std::cout<<std::endl;
}

void BST::LevelOrderTraversePrint(){
    std::queue<BSTNode*> printed_queue;
    printed_queue.push(root);

    while(!printed_queue.empty()){
        BSTNode* current_node = printed_queue.front();
        printed_queue.pop();
        std::cout<<current_node->key<<" ";
        
        if(current_node->left_child != NULL){
            printed_queue.push(current_node->left_child);
        }
        if(current_node->right_child != NULL){
            printed_queue.push(current_node->right_child);
        }   
    }
    std::cout<<std::endl;
}

BSTNode* BST::SearchLeftMostEngine(BSTNode* current_node){
    while((current_node != NULL) && (current_node->left_child != NULL)){
        current_node = current_node->left_child;
    }
    return current_node;
}

BSTNode* BST::SearchRightMostEngine(BSTNode* current_node){
    while((current_node != NULL) && (current_node->right_child != NULL)){
        current_node = current_node->right_child;
    }
    return current_node;
}

void BST::SearchLeftMostPrint(){
    BSTNode* leftest_node = SearchLeftMostEngine(root);
    if(leftest_node == NULL){
        std::cout<<"smallest node not found."<<std::endl;
    }else{
        std::cout<<"smallest = "<<leftest_node->key<<std::endl;
    }
}

void BST::SearchRightMostPrint(){
    BSTNode* rightest_node = SearchRightMostEngine(root);
    if(rightest_node == NULL){
        std::cout<<"biggest node not found."<<std::endl;
    }else{
        std::cout<<"biggest = "<<rightest_node->key<<std::endl;
    }
}

BSTNode* BST::FindInOrderSuccessor(BSTNode* current_node){
    BSTNode* inorder_successor_node = NULL;

    if(current_node->parent == NULL){
        inorder_successor_node = SearchLeftMostEngine(current_node->right_child);
    }else{
        if(current_node == current_node->parent->left_child){
            if(current_node->right_child != NULL){
                inorder_successor_node = SearchLeftMostEngine(current_node->right_child);
            }else{
                inorder_successor_node = current_node->parent;
            }   
        }else if(current_node == current_node->parent->right_child){
            inorder_successor_node = current_node->right_child;
        }
    }
    return inorder_successor_node;
}

BSTNode* BST::FindInOrderPreDecessor(BSTNode* current_node){
    BSTNode* inorder_predecessor_node = NULL;

    if(current_node->parent == NULL){
        inorder_predecessor_node = SearchRightMostEngine(current_node->left_child); 
    }else{
        if(current_node == current_node->parent->right_child){
            if(current_node->left_child != NULL){
                inorder_predecessor_node = SearchRightMostEngine(current_node->left_child);
            }else{
                inorder_predecessor_node = current_node->parent;
            }
        }else if(current_node == current_node->parent->left_child){
            inorder_predecessor_node = current_node->left_child;
        }
    }
    return inorder_predecessor_node;
}

void BST::SearchInorderSuccessorOfSmallestPrint(){
    BSTNode* smallest_node = SearchLeftMostEngine(root);
    if(smallest_node == NULL){
        std::cout<<"not found smallest node in BST::SearchInorderSuccessorOfSmallestPrint"<<std::endl;
        return;
    }
    
    BSTNode* successor_of_smallest_node = FindInOrderSuccessor(smallest_node);
    if(successor_of_smallest_node == NULL){
        std::cout<<"not found successor of smallest node in BST::SearchInorderSuccessorOfSmallestPrint"<<std::endl;
        return;
    }

    std::cout<<"successor of smallest = "<<successor_of_smallest_node->key<<std::endl;
}

void BST::SearchInorderPreDecessorOfBiggestPrint(){
    BSTNode* biggest_node = SearchRightMostEngine(root);
    if(biggest_node == NULL){
        std::cout<<"not found biggest node in BST::SearchInorderPreDecessorOfBiggestPrint"<<std::endl;
        return;
    }

    BSTNode* predecessor_of_biggest_node = FindInOrderPreDecessor(biggest_node);
    if(predecessor_of_biggest_node == NULL){
        std::cout<<"not found predecessor of biggest node in BST::SearchInorderPreDecessorOfBiggestPrint"<<std::endl;
        return;
    }

    std::cout<<"predecessor of biggest = "<<predecessor_of_biggest_node->key<<std::endl;
}

void BST::DeleteArbitrary(const int key){
        BSTNode* found_node = NULL;
        BSTNode* found_parent_node = NULL;

        Search(key, found_node, found_parent_node);
        if(found_node == NULL){
            std::cout<<"cannot find the node with key = "<<key<<std::endl;
            return;
        }
        while(found_node!=NULL){
            if(found_parent_node == NULL){//root
                BSTNode* successor_node = FindInOrderSuccessor(found_node);
                if(successor_node == successor_node->parent->left_child){
                    successor_node->parent->left_child = NULL;
                }else if(successor_node == successor_node->parent->right_child){
                    successor_node->parent->right_child = NULL;
                }

                found_node->key = successor_node->key;
                delete successor_node;
            }else{
                if((found_node->left_child == NULL) && (found_node->right_child == NULL)){
                    if(found_node == found_parent_node->right_child){
                        found_parent_node->right_child = NULL;
                    }else if(found_node == found_parent_node->left_child){
                        found_parent_node->left_child = NULL;
                    }
                    delete found_node;
                }else if((found_node->left_child != NULL) && (found_node->right_child != NULL)){
                    BSTNode* successor_node = FindInOrderSuccessor(found_node);
                    if(successor_node == successor_node->parent->left_child){
                        successor_node->parent->left_child = NULL;
                    }else if(successor_node == successor_node->parent->right_child){
                        successor_node->parent->right_child = NULL;
                    }

                    found_node->key = successor_node->key;
                    delete successor_node;
                }else if((found_node->left_child == NULL) && (found_node->right_child != NULL)){
                    if(found_node == found_parent_node->right_child){
                        found_parent_node->right_child = found_node->right_child;
                    }else if(found_node == found_parent_node->left_child){
                        found_parent_node->left_child = found_node->right_child;
                    }
                    delete found_node;
                }else{
                    if(found_node == found_parent_node->right_child){
                        found_parent_node->right_child = found_node->left_child;
                    }else if(found_node == found_parent_node->left_child){
                        found_parent_node->left_child = found_node->left_child;
                    }
                    delete found_node;
                }
            }
            --size_of_tree;
            Search(key, found_node, found_parent_node);
        }
}

void BST::ConstructBSTUsingSorting(const int* const L, const int size){
    int set_index = 0;
    BSTNode* root_node = new BSTNode;
    std::queue<BSTNode*> construct_queue;
    construct_queue.push(root_node);
    ++size_of_tree;
    root = root_node;

    while(!construct_queue.empty()){
        int remain_num = size - size_of_tree;
        BSTNode* current_node = construct_queue.front();
        construct_queue.pop();

       if(remain_num >= 2){
           BSTNode* left_node = new BSTNode;
           BSTNode* right_node = new BSTNode;
           current_node->left_child = left_node;
           current_node->left_child->parent = current_node;
           current_node->right_child = right_node;
           current_node->right_child->parent = current_node;

           size_of_tree += 2;
           construct_queue.push(left_node);
           construct_queue.push(right_node);
       }else if(remain_num == 1){
           BSTNode* left_node = new BSTNode;
           current_node->left_child = left_node;
           current_node->left_child->parent = current_node;

           ++size_of_tree;
           construct_queue.push(left_node);
       }else{
           break;
       }
    }

    //Inorder Traversal to put value into BST
    InOrderTraverseSetEngine(root, set_index, L);
}
