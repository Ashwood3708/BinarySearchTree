/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   binaryTree.cpp
 * Author: Abdul
 * 
 * Created on October 25, 2017, 5:54 PM
 */

#include "BinaryTree1.h"
#include <iostream>
using namespace std;

binaryTree::binaryTree() {
    root = NULL;
    max = 50;


}

bool binaryTree::empty() {
    if (root == NULL) {
        return true;
    }
    return false;
}

string binaryTree::meal(int dishNum) { //returns meal to corresponding num
    string meal = "";
    if (dishNum == 1) {
        meal = "Fried Chicken";
    } else if (dishNum == 2) {
        meal = "Pork Chops";
    } else if (dishNum == 3) {
        meal = "Baked Chicken";
    } else if (dishNum == 4) {
        meal = "Grilled Salmon";
    } else if (dishNum == 5) {
        meal = "Roast Beef";
    } else if (dishNum == 6) {
        meal = "Grilled Steak";
    } else if (dishNum == 7) {
        meal = "Meat Loaf";
    } else {
        meal = "meal does not exist";
    }
    return meal;
}

bool binaryTree::Insert(int dishNum) {
    if (dishNum > 0 && dishNum < 8) {
        if (empty() == true) { //if empty, set root to new node
            node*T = new node;
            if (dishNum == 0 || dishNum > 7) { //for meals that don't exist
                T->dishNumber = 9;
            } else {
                T->dishNumber = dishNum;
            }
            T->meal = meal(dishNum);
            T->counter++;
            root = T;
            return true;
        } else if (IsThere(dishNum, root) == true) { // if node already exist return true
            return true;

        } else if (IsThere(dishNum, root) == false) {//if node does not exist make new node
            node*T = new node;
            T->counter++;
            T->dishNumber = dishNum;

            T->meal = meal(dishNum);
            if (findNull(dishNum, root)->dishNumber > T->dishNumber) { // if node num is less than found node num
                findNull(dishNum, root)->leftchild = T; //place to the left
            } else {
                findNull(dishNum, root)->rightchild = T; //otherwise place to the right
            }
            return false;
        }
    }

}

node* binaryTree::findNull(int num, node* t) { //use recursion to find location for new node
    node* r;
    if (num < t->dishNumber) { //if num is less than dishNumber
        if (t->leftchild == NULL) {
            return t;
        }
        findNull(num, t->leftchild);
    } else if (num > t->dishNumber) {//if num is more than dishNumber
        if (t->rightchild == NULL) {
            return t;
        }
        findNull(num, t->rightchild);
    }
}

bool binaryTree::IsThere(int dishNum, node*t) { //finds node if it exist and increment counter 

    if (t->dishNumber == dishNum) { //if node exist increment counter
        t->counter++;
        return true;
    } else if (t != NULL && dishNum < t->dishNumber) { //num is less than
        if (t->leftchild == NULL) { //if node doesn't exist return false
            return false;
        }
        IsThere(dishNum, t->leftchild); //if not found check left child of node
    } else if (t != NULL && dishNum > t->dishNumber) { // num is more than
        if (t->rightchild == NULL) { //if node doesn't exist return false
            return false;
        }
        IsThere(dishNum, t->rightchild); //if not found check left child of node
    }
}

void binaryTree::deleteNode(node*p, node*parent) {

    if (p == root) {

    } else if (p->leftchild == NULL && p->rightchild == NULL) { //if p is leaf node
        if (parent->leftchild == p) {
            parent->leftchild = NULL;
        } else {
            parent->rightchild = NULL;
        }
    } else if (p->leftchild == NULL && p->rightchild != NULL) { //if left is null
        if (parent->leftchild == p) {
            parent->leftchild = p->rightchild;
        } else {
            parent->rightchild = p->rightchild;
        }
    } else if (p->leftchild != NULL && p->rightchild == NULL) { //if right is null
        if (parent->leftchild == p) {
            parent->leftchild = p->leftchild;
        } else {
            parent->rightchild = p->leftchild;
        }
    } else if (p->leftchild != NULL && p->rightchild != NULL) { //if neither are null
        if (parent->leftchild == p) {
            if (p->leftchild->dishNumber > p->rightchild->dishNumber) { //if p->left is greater than p->right
                parent->leftchild = p->leftchild;
                p->leftchild->leftchild = p->rightchild;
            } else { // else if p->right is greater than p->left
                parent->leftchild = p->rightchild;
                p->rightchild->leftchild = p->leftchild;
            }

        } else {
            if (p->leftchild->dishNumber > p->rightchild->dishNumber) { //if p->left is greater than p->right
                parent->rightchild = p->leftchild;
                p->leftchild->leftchild = p->rightchild;
            } else { // else if p->right is greater than p->left
                parent->rightchild = p->rightchild;
                p->rightchild->leftchild = p->leftchild;
            }
        }
    }
    delete p;
}

void binaryTree::remove(node* p, node* parent) {
    //iterate through the tree checking each node
    if (p != NULL) {
        p->display = false;
        if (p->counter < 2) { //if counter is less than 2 delete node
            deleteNode(p, parent);
        }
        remove(p->leftchild, p);
        remove(p->rightchild, p);

    }

}

void binaryTree::Delete() {
    remove(root, root);
    DisplayAfter(root);
}
//not in use
void binaryTree::display(node * p, value max) {
    //recursion display of nodes with one or more orders in order from greatest to least

    if (p != NULL) {
        node*k;
        display(p->leftchild, max);
        if (p->counter > max && p->meal != "meal does not exist") {
            if (p->display == false && p->dishNumber <= 7) {
                cout << p->meal << " " << p->counter << endl;
                p->display = true;
            }

        }
        display(p->rightchild, max);
    }
}

void binaryTree::Display(node* p) {
    if (p != NULL) {
        Display(p->leftchild);
        cout << p->meal << " " << p->counter << endl;
        Display(p->rightchild);
    }

}

void binaryTree::DisplayAfter(node* p) {
    if (p != NULL) {
        DisplayAfter(p->leftchild);
        if (p->counter > 1) {
            cout << p->meal << " " << p->counter << endl;
        }
        DisplayAfter(p->rightchild);
    }
}

void binaryTree::Display() {
    Display(root);
    //    while (max >= 0) {
    //        display(root, max);
    //        max--;
    //    }
    //    max = 50;



}