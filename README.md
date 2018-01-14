

A restaurant would like to keep count the frequencies of dishes that are ordered. The restaurant offers 7 different main course dishes as follows:

Dish 1 – Fried Chicken

Dish 2 – Pork Chops

Dish 3 – Baked Chicken

Dish 4 – Grilled Salmon

Dish 5 – Roast Beef

Dish 6 – Grilled Steak 

Dish 7 – Meat Loaf

Write a program to keep up with the number of times a particular dish is ordered. The first time a dish is ordered, the dish comes into existence and a counter for the dish is set to 1.  If the dish already exists and an order is made, the counter for the dish is incremented. Using the Display method for the binary search tree, display the dishes which have been ordered (in numerical order).  With each dish, display the frequency that the dish has been ordered.  The restaurant owner would like to remove from the menu the dishes which have not been ordered more than once. Using the Display method for the binary search tree, display the updated list of dishes (in numerical) with corresponding frequencies after dishes with one order have been removed.

## Programming Guidelines:  
-	Use a binary search tree to store the information on the dishes. 
-	Use the appropriate binary tree traversal that will give you the correct output.
-	You can add additional methods to the BinarySearchTree class if you desire. 

### The following definition for the binary search tree modifies the node class to hold the two values:

```
class node
{
   friend class BinarySearchTree;
   private:
int dishNumber;
int counter;
   	node * leftchild;
   	node * rightchild;
};

class BinarySearchTree
{
 public: 
   BinarySearchTree();
   bool empty(); // return true if the tree is empty, otherwise return false
   bool Insert(int dishNum);//insert a value dishNum 
   bool IsThere (int dishNum); 
//return true if dishNum is in the tree, otherwise return false
   void Delete(int dishNum); //if value dishNum is in the tree, remove dishNum
   void Display();
//Display the data stored from smallest to largest based on dish number
  
 private:
	node * root;//pointer to the root node
};
```
### The following definition for the binary search tree using a struct to hold the two values:
```
struct dish{
	int dishNumber;
	int counter;
};

typedef dish ElementType;
class node
{
   friend class BinarySearchTree;
   private:
ElementType data;
   	node * leftchild;
   	node * rightchild;
};

class BinarySearchTree
{
 public: 
   BinarySearchTree();
   bool empty(); // return true if the tree is empty, otherwise return false
   bool Insert(ElementType x);//insert a value x 
   bool IsThere (ElementType  x); 
//return true if x is in the tree, otherwise return false
   void Delete(ElementType x); //if value x is in the tree, remove x
   void Display();
//Display the data stored from smallest to largest based on dish number
  
 private:
	node * root;//pointer to the root node
};
```

**Sample input:**  4 3 2 3 7 2 2 5 2 1 3 3 5 5

**Sample output:**

*List of all dishes ordered:*

1 – Fried Chicken	1 order

2 – Pork Chops		4 orders

3 – Baked Chicken	4 orders

4 – Grill Salmon		1 order

5 – Roast Beef		3 orders

7 – Meat Loaf		1 order

*List of dishes with more than one order:*

2 – Pork Chops		4 orders

3 – Baked Chicken	4 orders

5 – Roast Beef		3 orders
