#include <iostream>
#include <queue>

using namespace std;

class Bst {
    class Node {
    public:
        int value;
        Node* left;
        Node* right;
        Node* parent;

        Node(int val) {
            value = val;
            left = nullptr;
            right = nullptr;
            parent = nullptr;
        }

        void print_node() {

            cout << endl;
            cout << "Node: " << value << endl;
            if (parent != nullptr) {
                cout << "Parent: " << parent->value << endl;
            } else { cout << "Parent: nullptr" << endl; }
            if (left != nullptr) {
                cout << "Left: " << left->value << endl;
            } else { cout << "Left: nullptr" << endl; }
            if (right != nullptr) {
                cout << "Right: " << right->value << endl;
            } else { cout << "Right: nullptr" << endl; }

        }

    };
    int size_;
    Node* root_;

    Node* insert_(Node* node, int val);
    Node* find_(Node* node, int val);
    Node* min_(Node* node);
    Node* max_(Node* node);
    Node* succ_(Node* node);
    Node* succ2_(Node* node);
    Node* erase_(Node* node, int val);

public:
    Bst() {
        size_ = 0;
        root_ = nullptr;
    }

    void insert(int val);
    bool find(int val);
    int min();
    int max();
    int succ(int val);
    int pred(int val);
    void del(int val);
    void erase(int val);

    void print();
    bool empty();
};

Bst::Node* Bst::insert_(Node* node, int val) {
    if(node == nullptr){
        return new Node(val);
    }
    if(val > node->value){
        node->right = insert_(node->right, val);
        node->right->parent = node;
    }
    else{
        node->left = insert_(node->left, val);
        node->left->parent = node;
    }
    return node;
}

void Bst::insert(int val) {
    root_ = insert_(root_, val);
}

Bst::Node* Bst::find_(Node* node, int val) {
    if(node == nullptr)
        return nullptr;
    if(val > node->value)
        return find_(node->right, val);
    else if(val < node->value)
        return find_(node->left, val);
    return node;
}

bool Bst::find(int val) {
    return find_(root_, val) != nullptr; // placeholder; you can change the return type if you see fit
}

Bst::Node* Bst::min_(Node* node) {
    if(node->left != nullptr)
        return min_(node->left);
    return node;
}

int Bst::min() {
    Node* node = min_(root_);
    if(node == nullptr)
        throw invalid_argument("No tree no min");
    return node->value;
}

Bst::Node* Bst::max_(Node* node) {
    if(node->right != nullptr)
        return max_(node->right);
    return node;
}

int Bst::max() {
    Node* node = max_(root_);
    if(node == nullptr)
        throw invalid_argument("No tree no max");
    return node->value;
}

Bst::Node* Bst::succ_(Node* node) {
    if(node->right)
        return min_(node->right);
    else {
        while(node->parent->value < node->value)
            node = node->parent;
        return node->parent;
    }
}

Bst::Node* Bst::succ2_(Node* node) {
    return nullptr; // placeholder; second way of finding successor
}

int Bst::succ(int val) {
    Node* node = find_(root_, val);
    return succ_(node)->value; // placeholder
}

int Bst::pred(int val) {
    return 0; // placeholder
}

Bst::Node* Bst::erase_(Node* node, int value) {
    return nullptr; // placeholder; private function for recursive version
}

void Bst::erase(int value) {
    // recursive version
}

void Bst::del(int val) {
    // iterative version
}

void Bst::print() {
    queue<Node*> to_visit;
    if (empty()) {
        throw invalid_argument("Nothing to print, tree empty.");
    } else {
        to_visit.push(root_);
        Node* current = root_;
        cout << "----------print--";
        while ( !to_visit.empty()) {
            current->print_node();
            if (current->left != nullptr) {
                to_visit.push(current->left);
            }
            if (current->right != nullptr) {
                to_visit.push(current->right);
            }
            to_visit.pop();
            current = to_visit.front();
        }
    }
}

bool Bst::empty() {
    if (root_ == nullptr) {
        return true;
    } else {
        return false;
    }
}

int main() {

    Bst tree;

    tree.insert(15);
    tree.insert(6);
    tree.insert(18);
    tree.insert(21);
    tree.insert(17);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(13);
    tree.insert(9);

//    tree.print();

//    cout << tree.find(15);

//    cout << endl << "Min: " << tree.min() << endl;
//    cout << "Max: " << tree.max() << endl << endl;

    //cout << "Successor of 13 is " << tree.succ(13) << endl;
    //cout << "Successor of 15 is " << tree.succ(15) << endl;
    //cout << "Successor of 9 is " << tree.succ(9) << endl;
    //cout << "Successor of 4 is " << tree.succ(4) << endl;
    //cout << "Successor of 17 is " << tree.succ(17) << endl;
    ////cout << "Successor of 20 is " << tree.succ(20) << endl;
    //cout << endl;
    //cout << "Predecessor of 15 is " << tree.pred(15) << endl;
    //cout << "Predecessor of 6 is " << tree.pred(6) << endl;
    //cout << "Predecessor of 17 is " << tree.pred(17) << endl;
    ////cout << "Predecessor of 2 is " << tree.pred(2) << endl;

    tree.insert(16);
    tree.insert(19);
    tree.insert(20);
    tree.insert(25);

    //tree.erase(21);
    // or
    //tree.del(21)
    //tree.print();

    return 0;
}