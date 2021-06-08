//
// Created by Gabriel on 06/05/2021.
//

#include "test_utilities.h"
#include "../AVLRankTree.h"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

#define NUMBER_TESTS 9

ostream& printInt(int num, ostream& os){
    return os << num << endl;
}
//template<class T>
//class PrintFile{
//public:
//    PrintFile(const string& file_name){
//        clearFile(file_name);
//        file = ofstream (file_name);
//    }
//    ~PrintFile(){
//        file.close();
//    }
//    ofstream file;
//    void operator()(T& data){
//        file << data << " ";
//    }
//};

template<class T>
class PrintTree{
    int counter;
public:
    PrintTree(): counter(1){};
    bool operator()(T *data){
        std::cout << "iteration no:"<< counter << " data:" << *data << endl;
        counter++;
        return true;
    }
};

bool testAVLTreeCreateDestroy(){
    bool result = true;
    AVLTree<int> tree = AVLTree<int>();
    ASSERT_TEST(tree.getHeight() == 0, returnLabel);
    returnLabel:
    return result;
}

bool testAVLIntInsert1(){
    bool result = true;
    AVLTree<int> tree= AVLTree<int>();
    int num = 5;
    tree.insert(num);
    string expected = "../tests/outputs/avl_int_print1.txt";
    string tested = "../tests/outputs/output.txt";
//    clearFile(tested);
//    ofstream output_file(tested);

    return result;
}

bool testAVLReverseInorder(){
    bool result = true;
    AVLTree<int> tree= AVLTree<int>();
    tree.insert(9);
    tree.insert(4);
    tree.insert(22);
    tree.insert(2);
    tree.insert(6);
    tree.insert(14);
    tree.insert(50);
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);
    tree.insert(8);
    tree.insert(12);
    tree.insert(16);
    tree.insert(44);
    tree.insert(53);
    tree.insert(11);
    tree.insert(13);
    tree.insert(25);
    tree.insert(56);
    PrintTree<int> print = PrintTree<int>();
//    tree.reverseInorder(print);
//
//    tree.reverseInorder(print, 3);

returnLabel:
    return result;
}

bool testAVLSortedArrayInit() {
    bool result = true;
    int arr1[10] = {0};
    for(int i = 0; i < 10; i++){
        arr1[i] = i;
    }
    AVLTree<int> tree1 = AVLTree<int>();
    tree1.sortedArrayInit(arr1, 10);
    for(AVLTree<int>::AvlIterator it = tree1.begin(); it!= tree1.end(); ++it){
        int* curr =*it;
        std::cout<< *curr <<std::endl;
    }
    tree1.remove(1);
    tree1.printTree();
    tree1.remove(9);
    tree1.printTree();
    tree1.remove(6);
    tree1.printTree();
    tree1.remove(8);
    tree1.printTree();

    returnLabel:
    return result;
}

bool testInorder(){
    bool result = true;
    AVLTree<int> tree= AVLTree<int>();
    tree.insert(9);
    tree.insert(4);
    tree.insert(22);
    tree.insert(2);
    tree.insert(6);
    tree.insert(14);
    tree.insert(50);
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);
    tree.insert(8);
    tree.insert(12);
    tree.insert(16);
    tree.insert(44);
    tree.insert(53);
    tree.insert(11);
    tree.insert(13);
    tree.insert(25);
    tree.insert(56);
    PrintTree<int> print = PrintTree<int>();
//    tree.inorder(print);
//
//    tree.inorder(print, 13);

    returnLabel:
    return result;
}

bool testCopyAndAssignment(){
    bool result = true;

    //Correct output
    //1 BF: 0 Height: 0
    //5 BF: -1 Height: 2
    //6 BF: -1 Height: 1
    //7 BF: 0 Height: 0
    //8 BF: 0 Height: 3
    //12 BF: -1 Height: 1
    //16 BF: 0 Height: 0
    //22 BF: 1 Height: 2
    //33 BF: 0 Height: 0

    PrintTree<int> print = PrintTree<int>();
    AVLTree<int> tree1 = AVLTree<int>();
    tree1.insert(5);
    tree1.insert(8);
    tree1.insert(6);
    tree1.insert(22);
    tree1.insert(33);
    tree1.insert(12);
    tree1.insert(1);
    tree1.insert(16);
    tree1.insert(7);

    AVLTree<int> tree2 = AVLTree<int>(tree1);
    tree2.printTree();
    AVLTree<int> tree3 = AVLTree<int>();
    tree3.insert(3);
    tree3.insert(6);
    tree3.insert(9);

    tree3 = tree2;
    tree3.printTree();
    returnLabel:
    return result;
}

bool testAVLFind(){
    bool result = true;
    bool passed = true;

    AVLTree<int> tree1 = AVLTree<int>();
    tree1.insert(5);
    tree1.insert(8);
    tree1.insert(6);
    tree1.insert(22);
    tree1.insert(33);
    tree1.insert(12);
    tree1.insert(1);
    tree1.insert(16);
    tree1.insert(7);

    tree1.remove(16);
    tree1.remove(33);

    try{
        passed = false;
        tree1.find(70);
    } catch(NodeDoesntExist& e){
        passed = true;
    }
    ASSERT_TEST(passed, returnLabel);

    try{
        passed = false;
        tree1.find(16);
    } catch(NodeDoesntExist& e){
        passed = true;
    }
    ASSERT_TEST(passed, returnLabel);

    try{
        passed = false;
        tree1.find(33);
    } catch(NodeDoesntExist& e){
        passed = true;
    }
    ASSERT_TEST(passed, returnLabel);
    returnLabel:
    return result;
}

bool testTreeSelect(){
    bool result = true;
    bool passed = true;
    AVLTree<int> tree1 = AVLTree<int>();
    tree1.insert(106);
    tree1.insert(50);
    tree1.insert(36);
    tree1.insert(48);
    tree1.insert(120);
    tree1.insert(12);
    tree1.insert(17);
    tree1.insert(23);
    tree1.remove(120);
    tree1.insert(18);
    tree1.insert(55);
    tree1.insert(57);
    tree1.remove(12);
    tree1.insert(118);
    tree1.insert(200);
    tree1.remove(48);
    tree1.insert(56);
    tree1.insert(210);
    tree1.printTree();

//      Final tree state:
//        17 BF: 0 Height: 0 Size: 1
//        18 BF: 0 Height: 1 Size: 3
//        23 BF: 0 Height: 0 Size: 1
//        36 BF: 0 Height: 2 Size: 7
//        50 BF: 0 Height: 0 Size: 1
//        55 BF: 0 Height: 1 Size: 3
//        56 BF: 0 Height: 0 Size: 1
//        57 BF: 0 Height: 3 Size: 12
//        106 BF: 0 Height: 0 Size: 1
//        118 BF: -1 Height: 2 Size: 4
//        200 BF: -1 Height: 1 Size: 2
//        210 BF: 0 Height: 0 Size: 1

    ASSERT_TEST(*(tree1.select(3)) == 23, returnLabel);
    ASSERT_TEST(*(tree1.select(8)) == 57, returnLabel);
    ASSERT_TEST(*(tree1.select(12)) == 210, returnLabel);

    try{
        passed = false;
        tree1.select(13);
    } catch(InvalidIndex& e){
        passed = true;
    }
    ASSERT_TEST(passed, returnLabel);

    try{
        passed = false;
        tree1.select(-3);
    } catch(InvalidIndex& e){
        passed = true;
    }
    ASSERT_TEST(passed, returnLabel);
    returnLabel:
    return result;
}

bool testTreeMerge(){
    bool result = true;
    AVLTree<int> tree1= AVLTree<int>();
    AVLTree<int> tree2= AVLTree<int>();

    tree1.insert(3);
    tree1.insert(8);
    tree1.insert(11);
    tree1.insert(14);

    tree2.insert(4);
    tree2.insert(6);
    tree2.insert(15);

    AVLTree<int> tree3 = AVLTree<int>(tree1, tree2);
    tree3.printTree();

    return result;
}

/* bool test(){
    bool result = true;

returnLabel:
    return result;
} */

bool (*tests[]) (void) = {
        testAVLTreeCreateDestroy,
        testAVLIntInsert1,
        testAVLReverseInorder,
        testInorder,
        testCopyAndAssignment,
        testAVLFind,
        testAVLSortedArrayInit,
        testTreeSelect,
        testTreeMerge
};

const char* testNames[] = {
        "testAVLTreeCreateDestroy",
        "testAVLIntInsert1",
        "testAVLReverseInorder",
        "testInorder",
        "testCopyAndAssignment",
        "testAVLFind",
        "testAVLSortedArrayInit",
        "testTreeSelect",
        "testTreeMerge"
};

int main(int argc, char *argv[]) {
    if (argc == 1) {
        for (int test_idx = 0; test_idx < NUMBER_TESTS; test_idx++) {
            RUN_TEST(tests[test_idx], testNames[test_idx]);
        }
        return 0;
    }
    if (argc != 2) {
        fprintf(stdout, "Usage: priority_queue_tests <test index>\n");
        return 0;
    }

    int test_idx = strtol(argv[1], NULL, 10);
    if (test_idx < 1 || test_idx > NUMBER_TESTS) {
        fprintf(stderr, "Invalid test index %d\n", test_idx);
        return 0;
    }

    RUN_TEST(tests[test_idx - 1], testNames[test_idx - 1]);
    return 0;
}