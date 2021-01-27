#include <iostream>

using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

node* create(){																			
	node* drzewo = new node{
		4,
		NULL,
		new node{
			6,
			new node{4, NULL, NULL},
			new node{4, NULL, NULL}
		},
	};
	return drzewo;
}

node* createBST(){
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

void print_tree(node * tree, int depth = 0, char prefix = '.') {		
    if (tree != NULL) {
        for (int i = 0; i < depth; i++) {
            cout << prefix;
        }
        cout << tree -> data << endl;
        print_tree(tree -> left, depth + 1, prefix);
        print_tree(tree -> right, depth + 1, prefix);
    }
}

int node_count(node * tree) {										
    int licznik = 0;
    if (tree != NULL) {
        licznik++;
        licznik += node_count(tree -> left) + node_count(tree -> right);
    }
    return licznik;
}

int tree_height(node * tree) {
    if (tree == NULL) return 0;
    else if (tree != NULL && tree -> left == NULL && tree -> right == NULL)
        return 0;
    int heightL = tree_height(tree -> left);
    int heightR = tree_height(tree -> right);
    if (heightL > heightR)
        return heightL + 1;
    else return heightR + 1;
}
int writeTree(node * tree, int * tab) {
    if (tree == NULL) return 0;
    int x = writeTree(tree -> left, tab);
    tab[x] = tree -> data;
    x++;
    x += writeTree(tree -> right, tab + x);
    return x;
}

node* create_perfect_tree(int * a, const int k) {	
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


node* reconstruct(node* tree){											//zadanie2
	int x = node_count(tree);
	int* tab = new int[x];
	writeTree(tree, tab);
	int y = tree_height(tree);
	return create_perfect_tree(tab, x);
}

bool szukaj(node * tree, int x) {										//zadanie3
    if (tree == NULL) return false;
    else if (tree -> data == x) return true;
    else if (tree -> left && tree -> data > x) szukaj(tree -> left, x);
    else szukaj(tree -> right, x);
}


int main(){
	cout << "Zadanie 2" << endl;
	node* drzewo = create();
	print_tree(drzewo);
	cout << endl;
	print_tree(reconstruct(drzewo));
	cout << endl;
	cout << "Zadanie 3" << endl;
	cout << "Drzewo przeszukiwane:" << endl;
	node* drzewoBST = createBST();
	print_tree(drzewoBST);
	cout << endl;
	cout << "Czy w drzewie jest 13?" << endl;
	cout << szukaj(drzewoBST, 13) << endl;
	cout << "Czy w drzewie jest 3?" << endl;
	cout << szukaj(drzewoBST, 3) << endl;
}
