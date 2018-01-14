/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   binaryTree.h
 * Author: Abdul
 *
 * Created on October 25, 2017, 5:54 PM
 */

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include<string>
using namespace std;


typedef int value;

struct node {
    friend class binaryTree;
private:
    string meal;
    value dishNumber;
    value counter = 0;
    bool display = false;
    node * leftchild = NULL;
    node * rightchild = NULL;
};


class binaryTree {
public:
    binaryTree();
    bool empty(); // return true if the tree is empty, otherwise return false
    bool Insert(value dishNum); //insert a dish into tree, if already exist increment counter
    bool IsThere(value dishNum, node*t); //return true if dish is in the tree, otherwise return false *for insert method*
    void remove(node* p, node* parent); //use recursion to go through tree *for delete method*
    void Delete(); //delete nodes with counters < 2
    void deleteNode(node*t, node*parent);  //delete node and fix list
    void Display(); //Display the data stored from largest to smallest based on dish counter
    void Display(node*p); //Display the data stored based on dish counter *uses recursion*
    void DisplayAfter(node*p); //Display data if counter > 1 *uses recursion* *used in delete method*
    void display(node*p, value max); //uses recursion to display nodes with two or more orders in order from greatest to least
    node* findNull(value dishNum, node*t); // finds location for new dish in tree
    string meal(value dishNum); // correlates meal with dishNumber


private:
    node * root; //pointer to the root node
    int max;
    

};



#endif /* BINARYTREE_H */

