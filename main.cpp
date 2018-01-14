/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Abdul
 * program #5 Binary search tree
 * Created on October 25, 2017, 5:52 PM
 * description: this program is to make a search tree based off of orders and how many times they are ordered.
 *              then delete meals that had less than 2 orders.
 */

#include "BinaryTree1.h"
#include <iostream>
#include <stdlib.h>
#include<string>
using namespace std;

/*
 * 
 */


int main() {

    string str = "99887766554433221";

        cout<<"Enter string of numbers"<<endl;
        cin>>str;

    binaryTree r;
    for (int i = 0; i < str.length(); i++) { // makes tree
        r.Insert(str[i] - 48); //char to int only works for last digit in char

    }
  cout<<endl;
    r.Display();
    cout<<endl;
    cout<< "new menu:"<<endl;
    r.Delete();

}

