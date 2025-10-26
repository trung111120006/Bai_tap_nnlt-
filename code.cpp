#include <iostream>
using namespace std;

struct node {
    int data;
    node *left, *right;
};

// Tạo node mới
node* createNode(int data) {
    node* newNode = new node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Chèn node vào cây BST
node* insert(node* root, int data) {
    if (root == nullptr) return createNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

// In-order traversal để kiểm tra cây
void inorder(node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Hàm xóa node
node* delete_node(node *root, int data) {
    if (root == nullptr) return root;

    if (data < root->data)
        root->left = delete_node(root->left, data);
    else if (data > root->data)
        root->right = delete_node(root->right, data);
    else {
        // Node cần xóa được tìm thấy

        // Case 1: Không có con
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        }
        // Case 2: Có một con bên phải
        else if (root->left == nullptr) {
            node* temp = root;
            root = root->right;
            delete temp;
        }
        // Case 2: Có một con bên trái
        else if (root->right == nullptr) {
            node* temp = root;
            root = root->left;
            delete temp;
        }
        // Case 3: Có hai con
        else {
            // Tìm node nhỏ nhất bên phải (inorder successor)
            node* temp = root->right;
            while (temp->left != nullptr)
                temp = temp->left;

            // Thay giá trị
            root->data = temp->data;

            // Xóa node nhỏ nhất bên phải
            root->right = delete_node(root->right, temp->data);
        }
    }
    return root;
}

int main() {
    node* root = nullptr;

    // Chèn dữ liệu
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Cay truoc khi xoa: ";
    inorder(root);
    cout << "\n";

    // Xoa node
    root = delete_node(root, 50);  // Xóa nút gốc có 2 con

    cout << "Cay sau khi xoa 50: ";
    inorder(root);
    cout << "\n";

    return 0;
}
