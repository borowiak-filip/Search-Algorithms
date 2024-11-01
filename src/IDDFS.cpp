#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
#include <queue>


struct Node {
    std::string name;
    int data;
    const Node* parent_ptr = nullptr;
    std::vector<const Node*> children;

    Node(std::string name_, int data_): name(name_), data(data_) {}

    void addParent(const Node* parent_ptr_) {parent_ptr = parent_ptr_;}
    void addChild(const Node* child_ptr_) {children.push_back(child_ptr_);}
    void printName() const {std::cout  << "Node: " << name << " (Node value: " << data << ")" << std::endl;}

    void printTree(int level= 0) const {

        std::cout << std::string(level*2, ' ') << name << " -> ";
        
        if (children.empty()) {
            std::cout << "None";
        } else {

            std::cout << "\n";
            for (const auto* child : children) {
            child -> printTree(level + 1);
            }
        }
        std::cout << std::endl;   

    }  

    void IDDFS(int depth_limit) {

        // apply depth threshold
        for (int i = 0; i < depth_limit; i++) {
            DLS(this, i);

        } 

    }

    void DLS(const Node* node, int depth) {

        // visited node
        node -> printName();
        if (depth <= 0) {return;}
        else if (depth > 0) {
            for (const auto* child : node -> children) {
                // invoke DFS for child node 
                    DLS(child, depth-1);

            }
        }

    }

};



int main() {

    // Create nodes
    Node r = Node("root", 0);
    Node a = Node("A", 1);
    Node b = Node("B", 2);
    Node c = Node("C", 3);
    Node d = Node("D", 4);
    Node e = Node("E", 5);
    Node f = Node("F", 6);
    Node g = Node("G", 7);
    Node h = Node("H", 8);
    Node i = Node("I", 9);

    // Create relations between nodes
    r.addChild(&a);
    a.addParent(&r);
    r.addChild(&b);
    b.addParent(&r);

    a.addChild(&c);
    c.addParent(&a);
    a.addChild(&d);
    d.addParent(&a);

    b.addChild(&e);
    e.addParent(&b);

    e.addChild(&f);
    f.addParent(&e);
    e.addChild(&g);
    g.addParent(&e);
    d.addChild(&h);
    h.addParent(&d);
    g.addChild(&i);
    i.addParent(&g);

    r.printTree();

    // Iterative Deepening Search
    r.IDDFS(5);
    

    return 0;
}

