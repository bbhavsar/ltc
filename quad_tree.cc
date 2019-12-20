#include "common.hh"

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

Node *cloneQuadTree(Node *quadTree) {
    if (quadTree == NULL) {
        return NULL;
    }
    return new Node(quadTree->val, quadTree->isLeaf,
                    cloneQuadTree(quadTree->topLeft), cloneQuadTree(quadTree->topRight),
                    cloneQuadTree(quadTree->bottomLeft),
                    cloneQuadTree(quadTree->bottomRight));
}

Node* intersect(Node* quadTree1, Node* quadTree2) {
    if (quadTree1->isLeaf && quadTree2->isLeaf) {
        return new Node(quadTree1->val || quadTree2->val, true,
                        NULL, NULL, NULL, NULL);
    }
    if (quadTree1->isLeaf || quadTree2->isLeaf) {
        Node *leaf = quadTree1->isLeaf ? quadTree1 : quadTree2;
        Node *non_leaf = quadTree1->isLeaf ? quadTree2 : quadTree1;

        if (leaf->val) {
            return cloneQuadTree(leaf);
        } else {
            return cloneQuadTree(non_leaf);
        }
    }

    return new Node(false, false, intersect(quadTree1->topLeft, quadTree2->topLeft),
                    intersect(quadTree1->topRight, quadTree2->topRight),
                    intersect(quadTree1->bottomLeft, quadTree2->bottomLeft),
                    intersect(quadTree1->bottomRight, quadTree2->bottomRight));
}


int main() {


    return 0;
}

