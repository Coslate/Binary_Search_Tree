#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <binary_search_tree.h>

void PrintArray(const int size, const int* arr, const std::string arr_name){
    std::cout<<arr_name<<" = [";
    for(int i=0;i<size;++i){
        if(i == 0){
            std::cout<<arr[i];
        }else if(i == size - 1){
            std::cout<<", "<<arr[i]<<"]"<<std::endl; 
        }else{
            std::cout<<", "<<arr[i];
        }
    }
}

void MoveArray(const int* from_arr, int* to_arr, const int to_size, const int to_begin_index, const int from_begin_index){
    int index = to_begin_index;
    for(int i=from_begin_index; i<from_begin_index+to_size; ++i){
        to_arr[index] = from_arr[i];
        ++index;
    }
}

void Merge2(const int low, const int mid, const int high, int* S){
    int i = low;
    int j = mid + 1;
    int k = 0;
    int *u = new int[(high - low + 1)]();

    while((i<=mid) && (j<=high)){
        if(S[i]<S[j]){
            u[k] = S[i];
            ++i;
        }else{
            u[k] = S[j];
            ++j;
        }
        ++k;
    }
    if(i > mid){
        MoveArray(S, u, (high - j + 1), k, j);
    }else{
        MoveArray(S, u, (mid - i + 1), k, i);
    }
    MoveArray(u, S, (high - low + 1), low, 0);

    delete [] u;
}

void MergeSort2(const int low, const int high, int* S){
    int mid;

    if(low < high){
        mid = floor((low+high)/2);
        MergeSort2(low, mid, S);
        MergeSort2(mid+1, high, S);
        Merge2(low, mid, high, S);
    }
}



int main(){
    BST tree_main;
    tree_main.InsertArbitrary(20);
    tree_main.InsertArbitrary(5);
    tree_main.InsertArbitrary(55);
    tree_main.InsertArbitrary(80);
    tree_main.InsertArbitrary(1);
    tree_main.InsertArbitrary(6);
    tree_main.InsertArbitrary(40);

    std::cout<<"InsertArbitrary 20 5 55 80 1 6 40 done"<<std::endl;
    std::cout<<"tree_size = "<<tree_main.GetTreeSize()<<std::endl;

    //In-order Traverse
    std::cout<<"---------------In-order Traversal----------------"<<std::endl;
    tree_main.InOrderTraversePrint();

    //Pre-order Traverse
    std::cout<<"---------------Pre-order Traversal----------------"<<std::endl;
    tree_main.PreOrderTraversePrint();

    //Post-order Traverse
    std::cout<<"---------------Post-order Traversal----------------"<<std::endl;
    tree_main.PostOrderTraversePrint();

    //Level-order Traverse
    std::cout<<"---------------Level-order Traversal----------------"<<std::endl;
    tree_main.LevelOrderTraversePrint();

    std::cout<<"---------------Find Smallest----------------"<<std::endl;
    tree_main.SearchLeftMostPrint();

    std::cout<<"---------------Find Biggest----------------"<<std::endl;
    tree_main.SearchRightMostPrint();

    std::cout<<"---------------Find Successor Smallest----------------"<<std::endl;
    tree_main.SearchInorderSuccessorOfSmallestPrint();

    std::cout<<"---------------Find PreDecessor Biggest----------------"<<std::endl;
    tree_main.SearchInorderPreDecessorOfBiggestPrint();

    std::cout<<"---------------Delete 20----------------"<<std::endl;
    tree_main.DeleteArbitrary(20);
    std::cout<<"In-order Traversal : "<<std::endl;
    tree_main.InOrderTraversePrint();
    std::cout<<"Level-order Traversal : "<<std::endl;
    tree_main.LevelOrderTraversePrint();
    std::cout<<"tree_size = "<<tree_main.GetTreeSize()<<std::endl;

    std::cout<<"---------------Delete 100----------------"<<std::endl;
    tree_main.DeleteArbitrary(100);
    std::cout<<"In-order Traversal : "<<std::endl;
    tree_main.InOrderTraversePrint();
    std::cout<<"Level-order Traversal : "<<std::endl;
    tree_main.LevelOrderTraversePrint();
    std::cout<<"tree_size = "<<tree_main.GetTreeSize()<<std::endl;

    std::cout<<"---------------Delete 5----------------"<<std::endl;
    tree_main.DeleteArbitrary(5);
    std::cout<<"In-order Traversal : "<<std::endl;
    tree_main.InOrderTraversePrint();
    std::cout<<"Level-order Traversal : "<<std::endl;
    tree_main.LevelOrderTraversePrint();
    std::cout<<"tree_size = "<<tree_main.GetTreeSize()<<std::endl;

    std::cout<<"---------------Delete 80----------------"<<std::endl;
    tree_main.DeleteArbitrary(80);
    std::cout<<"In-order Traversal : "<<std::endl;
    tree_main.InOrderTraversePrint();
    std::cout<<"Level-order Traversal : "<<std::endl;
    tree_main.LevelOrderTraversePrint();
    std::cout<<"tree_size = "<<tree_main.GetTreeSize()<<std::endl;

    std::cout<<"---------------Insert 100 & 41 & 33----------------"<<std::endl;
    tree_main.InsertArbitrary(100);
    tree_main.InsertArbitrary(41);
    tree_main.InsertArbitrary(33);
    std::cout<<"In-order Traversal : "<<std::endl;
    tree_main.InOrderTraversePrint();
    std::cout<<"Level-order Traversal : "<<std::endl;
    tree_main.LevelOrderTraversePrint();
    std::cout<<"tree_size = "<<tree_main.GetTreeSize()<<std::endl;


    std::cout<<"---------------Constructing Balence BST using sorting----------------"<<std::endl;

    const int n = 10;
    int *a = new int[n];

    //initialize random seed
    srand(time(NULL));

    std::cout<<"---before MergeSort2---"<<std::endl;
    for(int i=0;i<n;++i){
        a[i] = rand()%1000+1;
    }
    PrintArray(n, a, "S");

    MergeSort2(0, n-1, a);
    std::cout<<"---after MergeSort2---"<<std::endl;
    PrintArray(n, a, "S");    

    BST tree_test;
    tree_test.ConstructBSTUsingSorting(a, n);
    //In-order Traverse
    std::cout<<"---------------In-order Traversal----------------"<<std::endl;
    tree_test.InOrderTraversePrint();

    //Pre-order Traverse
    std::cout<<"---------------Pre-order Traversal----------------"<<std::endl;
    tree_test.PreOrderTraversePrint();

    //Post-order Traverse
    std::cout<<"---------------Post-order Traversal----------------"<<std::endl;
    tree_test.PostOrderTraversePrint();

    //Level-order Traverse
    std::cout<<"---------------Level-order Traversal----------------"<<std::endl;
    tree_test.LevelOrderTraversePrint();
    return EXIT_SUCCESS;
}
