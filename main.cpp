#include <iostream>

struct node {
    int data;
    struct node *right, *left;
};

struct node* newNode(int tempData) {
    struct node* templateStruct = new struct node;

    templateStruct->data = tempData;
    templateStruct->left = NULL;
    templateStruct->right = NULL;

    std::cout << "New branch was created.Data is: " << tempData << std::endl;

    return templateStruct;
}

struct node* insert(struct node* node, int data) {
    if (node == NULL)
        return newNode(data);

    if (node->data > data)
        node->left = insert(node->left, data);
    else if (node->data > data)
        node->right = insert(node->right, data);

    return node;
};

struct node* search(struct node* root, int data) {
    if (root == NULL || root->data == data)
        return root;

    if (root->data < data) {
        return search(root->right, data);
    }

    return search(root->left,data);
}

int main() {
    //map
    //id
    int id = 000;
    int data;
    int mainBranchData;
    std::string action = "";
    struct node* root = NULL;

    std::cout << "Write main branch data:";
    std::cin >> mainBranch;
    root = insert(root,mainBranch);

    std::cout << "Pick action - SEARCH/CREATE :";
    std::cin >> action;

    if (action == "SEARCH") {
        std::cout << "You pick to SEARCH\n";
        std::cout << "Write data for search:";
        std::cin >> data;
        if (search(root, data) == NULL)
            std::cout << data << " not on database" << std::endl;
        else
            std::cout << data << " in the database. Id branch: "<< id << std::endl;
    } else if (action == "CREATE") {
        std::cout << "You pick to CREATE\n";
        std::cout << "Write data to create:";
        std::cin >> data;
        insert(root,data);
    }

    return 0;
};