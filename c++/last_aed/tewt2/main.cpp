 #include <iostream>
 using std::cout;
 using std::endl;
 using std::ostream;

class Tree{
public:
Tree(): root(0), list(0){
}
~Tree(){
    delete_postorder( root); root = 0;
    delete list;             list = 0;
}
void add(int d){
    if (root==0)
        root = new Node(d);
    else
        add_inorder(root, d);
}
friend ostream& operator <<( ostream& o, Tree& t){
    o << "Inorder traversal:   ";
    t.print_inorder(o, t.root);
    o << endl;
    return o;
}
void convert_to_list( ostream& o ){
    o << "Converting to a list ... ";
    delete list; list = 0;
    list = list_inorder( root );
    /*
     * Print list
     */
    for (LNode* p = list; p != 0; p=p->next)
        o << p->data << " ";
    o << " done!" << endl;
}
   private:
class Node{
public:
    Node(int d): data(d), left(0), right(0) {
    }
    ~Node() {
        delete left;  left = 0;
        delete right; right = 0;
    }
    int data;
    Node* left;
    Node* right;
};
Node* root;

void add_inorder(Node* t, int d){
    if (d <= t->data)
        if (t->left == 0)
            t->left = new Node(d);
        else add_inorder(t->left, d);
    else
        if (t->right == 0)
            t->right = new Node(d);
        else add_inorder(t->right, d);
}

void print_inorder( ostream& o, Node*t ){
    if (t==0)
        return;
    print_inorder(o, t->left);
    o << t->data << " ";
    print_inorder(o, t->right);
}
void delete_postorder(Node* t){
    if (t== 0)
        return;
    delete_postorder( t->left );
    t->left = 0;
    delete_postorder( t->right );
    t->right = 0;
    delete t; t=0;
}
class LNode{
public:
    int data;
    LNode* next;
    LNode(int d): data(d), next(0){
    }
    ~LNode(){
        delete next; next = 0;
    }
    void append(int d){
        LNode* p = this;
        for (; p->next != 0; p=p->next)
            ;
        p->next = new LNode( d );
    }
};

LNode* list;
LNode* list_inorder(Node* t){
    if (t==0)
        return 0;
    LNode* left = list_inorder( t-> left );
    LNode* right = list_inorder( t->right );
    if (left == 0)
        return right;
    if (right == 0)
        return left;
    /*
     * Find last node in "left" and append right to it.
     */
    LNode* p = left;
    for (; p->next != 0; p=p->next) ;
    p->next = right;
    return left;
}
void list_inorder(Node* t){
    if (t==nullptr)
        return;
    list_inorder( t-> left );
    if (list==nullptr)
        list = new LNode( t->data );
    else
        list->append(t->data);
    list_inorder( t->right );
}

    };



   int main(){
Tree t;
int data[] = { -2, 3, 10, -21, 35, 3, 85, -2, 100};

for (int i=0; i<9; i++)
    t.add( data[i] );

cout << t << endl;

t.convert_to_list( cout );

cout << "Done!";
     }
