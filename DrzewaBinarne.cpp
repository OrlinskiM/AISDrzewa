#include <iostream>
#include <math.h>

using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

struct node_calc {
    char op; 
    int numer; 
    node_calc* left;
    node_calc* right;
};

void create(node * tree, int num){
	if(num > 0){
		node* newLeft = new node{num-1, NULL, NULL};
		node* newRight = new node{num+2, NULL, NULL};
		tree -> left = newLeft;
		tree -> right = newRight;
		create(tree -> left, num-2);
		create(tree -> right, num-2);
	}
}

void createBST(node * tree, int num){
	if(num > 0){
		node* newLeft = new node{(tree -> data)-1, NULL, NULL};
		node* newRight = new node{(tree -> data)+1, NULL, NULL};
		tree -> left = newLeft;
		tree -> right = newRight;
		createBST(tree -> left, num-2);
		createBST(tree -> right, num-2);
	}
}

bool search(node * tree, int x) { 											//zadanie 1
    if (tree == NULL)
        return false;
    else {
        if (tree -> data == x) return true;
        else if (search(tree -> left, x) == true) return true;
        else if (search(tree -> right, x) == true) return true;
    }
    return false;
}

int node_count(node * tree) {												//zadanie 2.1
    int licznik = 0;
    if (tree != NULL) {
        licznik++;
        licznik += node_count(tree -> left) + node_count(tree -> right);
    }
    return licznik;
}

int leaves_count(node * tree) {												//zadanie 2.2
    if (tree == NULL) return 0;
    if (tree -> left == NULL && tree -> right == NULL) return 1;
    return leaves_count(tree -> left) + leaves_count(tree -> right);
}

int right_children_count(node * tree) {										//zadanie 2.3
    int licznik = 0;
    if (tree == NULL) return licznik;
    if (tree -> right != NULL) licznik++;
    licznik += right_children_count(tree -> left) + right_children_count(tree -> right);
    return licznik;
}

int tree_height(node * tree) {												//zadanie 2.4
    if (tree == NULL) return 0;
    else if (tree != NULL && tree -> left == NULL && tree -> right == NULL)
        return 0;
    int heightL = tree_height(tree -> left);
    int heightR = tree_height(tree -> right);
    if (heightL > heightR)
        return heightL + 1;
    else return heightR + 1;
}

bool is_balanced(node * tree) {												//zadanie 3
    if (tree == NULL)
        return true;
    int left = 0;
    int right = 0;
    left = tree_height(tree -> left);
    right = tree_height(tree -> right);
    int r = right - left;
    if ((r == 0 || r == 1 || r == -1) && is_balanced(tree -> right) && is_balanced(tree -> left)) 
		return true;
    else
        return false;
}

bool is_bst(node * tree) {													//zadanie 4
    if (tree == NULL) 
		return true;
    if (tree -> left != NULL && (tree -> left -> data > tree -> data))
      	return false;
    if (tree -> right != NULL && (tree -> right -> data < tree -> data))
      	return false;
    if (is_bst(tree -> left) && is_bst(tree -> right))
		return true;
    else return false;
}

bool is_leaf(node * tree) {
    if (tree != NULL && tree -> left == NULL && tree -> right == NULL)
        return true;
    else return false;
}

void delete_leaves(node * tree) {											//zadanie 5
    if (tree != NULL) {
        if (is_leaf(tree -> left)) {
            delete tree -> left;
            tree -> left = NULL;
        } else delete_leaves(tree -> left);
        if (is_leaf(tree -> right)) {
            delete tree -> right;
            tree -> right = NULL;
        } else delete_leaves(tree -> right);
    }
}

node* create6(){
	node* drzewo = new node{
		10,
		new node{
			5,
			new node{
				4,
				new node{0, NULL, NULL},
				NULL
			},
			new node{
				6,
				NULL,
				new node{
					7,
					NULL,
					new node{9,NULL,NULL}
				}
			}
		},
		new node{
			20,
			new node{
				15,
				new node{13,NULL,NULL},
				NULL
			},
			new node{30, NULL, NULL}
		}
	};
	return drzewo;
}

void preorder(node * p){													//zadanie 6
	if(p != NULL){
		cout << p -> data << ",";
		preorder(p->left);
		preorder(p->right);
	}
}

void inorder(node * p){
	if(p != NULL){
		inorder(p->left);
		cout << p -> data << ",";
		inorder(p->right);
	}
}

void postorder(node * p){
	if(p != NULL){
		postorder(p->left);
		postorder(p->right);
		cout << p -> data << ",";
	}
}

void preorder1(node * p){													//zadanie 6a
	if(p != NULL){
		if (p -> left != 0 && p -> data - p -> left -> data < 2)
			p -> left -> data += 2;
		cout << p -> data << ",";
		preorder1(p->left);
		preorder1(p->right);
	}
}

void inorder1(node * p){
	if(p != NULL){
		if (p -> left != 0 && p -> data - p -> left -> data < 2)
			p -> left -> data += 2;
		inorder1(p->left);
		cout << p -> data << ",";
		inorder1(p->right);
	}
}

void postorder1(node * p){
	if(p != NULL){
		if (p -> left != 0 && p -> data - p -> left -> data < 2)
			p -> left -> data += 2;
		postorder1(p->left);
		postorder1(p->right);
		cout << p -> data << ",";
	}
}

void preorder2(node * p){													//zadanie 6b
	if(p != NULL){
		if (p->left == 0)
			p->right = 0;
		cout << p -> data << ",";
		preorder2(p->left);
		preorder2(p->right);
	}
}

void inorder2(node * p){
	if(p != NULL){
		if (p->left == 0)
			p->right = 0;
		inorder2(p->left);
		cout << p -> data << ",";
		inorder2(p->right);
	}
}

void postorder2(node * p){
	if(p != NULL){
		if (p->left == 0)
			p->right = 0;
		postorder2(p->left);
		postorder2(p->right);
		cout << p -> data << ",";
	}
}


node* create7(){															//zadanie 7
	node* drzewo = new node{
		4,
		new node{
			6,
			new node{4, NULL, NULL},
			new node{4, NULL, NULL}
		},
		new node{
			7,
			new node{7, NULL, NULL},
			new node{2, NULL, NULL}
		}
	};
	return drzewo;
}

void mirror_tree(node * tree) {												//zadanie 8
    if (tree != NULL) {
        mirror_tree(tree -> left);
        mirror_tree(tree -> right);
        if (tree -> left != NULL && tree -> right != NULL) {
            node * wsk = tree -> left;
            tree -> left = tree -> right;
            tree -> right = wsk;
        }
    }
}

void print_tree(node * tree, int depth = 0, char prefix = '.') {			//zadanie 9
    if (tree != NULL) {
        for (int i = 0; i < depth; i++) {
            cout << prefix;
        }
        cout << tree -> data << endl;
        print_tree(tree -> left, depth + 1, prefix);
        print_tree(tree -> right, depth + 1, prefix);
    }
}

int eval(node_calc * tree) {												//zadanie 10
    if (tree != NULL) {
        if (tree -> left == NULL && tree -> right == NULL)
            return tree -> numer;
        else {
            int a = eval(tree -> left);
            int b = eval(tree -> right);
            if (tree -> op == '+') return a + b;
            if (tree -> op == '-') return a - b;
            if (tree -> op == '*') return a * b;
            if (tree -> op == '/' && b!=0) return a/b;
                else cout << "Proba dzielenia przez zero!";
        }
	}
}

node_calc* createCalc(){
	node_calc* calc = new node_calc{
		'*',
		NULL,
		new node_calc{
			'+',
			NULL,
			new node_calc{NULL, 7, NULL, NULL},
			new node_calc{NULL, 8, NULL, NULL}
		},
		new node_calc{
			'-',
			NULL,
			new node_calc{NULL, 3, NULL, NULL},
			new node_calc{NULL, 2, NULL, NULL}
		}
	};
	return calc;
}

node* create_perfect_tree(int * a, const int k) {							//zadanie 11
    if (k == 1) {
        node* nowy = new node;
        nowy -> data = a[0];
        nowy -> left = NULL;
        nowy -> right = NULL;
        return nowy;
    } else {
        node* nowy = new node;
        nowy -> data = a[k / 2];
        nowy -> left = create_perfect_tree(a, k / 2);
        nowy -> right = create_perfect_tree(a + k / 2 + 1, k / 2);
        return nowy;
    }
}


int main(){
	cout << "Zadanie 1" << endl;
	cout << "Wypelniam drzewo przykladowymi wartosciami" << endl;
	node* drzewo = new node{5, NULL, NULL};
	create(drzewo, 4);
	print_tree(drzewo);
	cout << "Sprawdzam, czy 3 znajduje sie w drzewie:" << endl;
	cout << search(drzewo, 3) << endl << endl;
	
	cout << "Zadanie 2" << endl;
	cout << "Sprawdzam liczbe wierzcholkow:" << endl;
	cout << node_count(drzewo) << endl;
	cout << "Sprawdzam liczbe lisci:" << endl;
	cout << leaves_count(drzewo) << endl;
	cout << "Sprawdzam liczbe prawych potomkow:" << endl;
	cout << right_children_count(drzewo) << endl;
	cout << "Sprawdzam wysokosc drzewa:" << endl;
	cout << tree_height(drzewo) << endl << endl;
	
	cout << "Zadanie 3" << endl;
	cout << "Sprawdzam czy drzewo jest zbalansowane:" << endl;
	cout << is_balanced(drzewo) << endl << endl;
	
	cout << "Zadanie 4" << endl;
	cout << "Sprawdzam czy drzewo jest drzewem BST:" << endl;
	cout << is_bst(drzewo) << endl;
	cout << "Tworze nowe drzewo, ktore jest BST:" << endl;
	node* drzewoBST = new node{5, NULL, NULL};
	createBST(drzewoBST, 4);
	print_tree(drzewoBST);
	cout << "Sprawdzam, czy ono jest BST:" << endl;
	cout << is_bst(drzewoBST) << endl << endl;
	
	cout << "Zadanie 6" << endl;
	node* drzewo6 = create6();
	cout << "Drzewo wypisane preorder:" << endl;
	preorder(drzewo6);
	cout << endl;
	cout << "Drzewo wypisane inorder:" << endl;
	inorder(drzewo6);
	cout << endl;
	cout << "Drzewo wypisane postorder:" << endl;
	postorder(drzewo6);
	cout << endl << endl << "a) Po zastosowaniu dzialania, procedury wydrukuja:" << endl;
	cout << "Drzewo wypisane preorder:" << endl;
	preorder1(drzewo6);
	cout << endl;
	drzewo6 = create6();
	cout << "Drzewo wypisane inorder:" << endl;
	inorder1(drzewo6);
	cout << endl;
	drzewo6 = create6();
	cout << "Drzewo wypisane postorder:" << endl;
	postorder1(drzewo6);
	cout << endl;
	drzewo6 = create6();
	cout << endl << endl << "b) Po zastosowaniu dzialania, procedury wydrukuja:" << endl;
	cout << "Drzewo wypisane preorder:" << endl;
	preorder2(drzewo6);
	cout << endl;
	drzewo6 = create6();
	cout << "Drzewo wypisane inorder:" << endl;
	inorder2(drzewo6);
	cout << endl;
	drzewo6 = create6();
	cout << "Drzewo wypisane postorder:" << endl;
	postorder2(drzewo6);
	cout << endl << endl;
	
	
	cout << "Zadanie 7" << endl;
	node* drzewo7 = create7();
	cout << "Drzewo wypisane preorder:" << endl;
	preorder(drzewo7);
	cout << endl;
	cout << "Drzewo wypisane inorder:" << endl;
	inorder(drzewo7);
	cout << endl << endl;
	
	cout << "Zadanie 8" << endl;
	cout << "Drzewo przed odbiciem:" << endl;
	print_tree(drzewo7);
	cout << endl;
	mirror_tree(drzewo7);
	cout << "Drzewo po odbiciu:" << endl;
	print_tree(drzewo7);
	cout << endl;
	
	cout << "Zadanie 9" << endl;
	drzewo6 = create6();
	print_tree(drzewo6);
	cout << endl;
	
	cout << "Zadanie 10" << endl;
	node_calc* calc = createCalc();
	cout << eval(calc) << endl;
	cout << endl;
	
	cout << "Zadanie 11" << endl;
	cout << "Stworzenie drzewa z tablicy: 4,2,1,3,6,5,7" << endl;
	int* tablica = new int[7] {4,2,1,3,6,5,7};
	node* drzewoTab = create_perfect_tree(tablica, 7);
	print_tree(drzewoTab);
	
	//cout << "Preorder: 10,5,4,0,6,7,9,20,15,13,30" << endl;
	//cout << "Inorder: 0,4,5,6,7,9,10,13,15,20,30" << endl;
	//cout << "Postorder: 0,4,9,7,6,5,13,15,30,20,10" << endl << endl;
}
