#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 20

typedef struct node_s {
    char value;
    struct node_s *left;
    struct node_s *right;
} Node;

Node *preorder(Node *root, char *pre, char *in, int *pre_index, int in_start, int in_end) {
    int pivot;
    char target[2] = "\0";

    if (in_start > in_end)
        return NULL;

    root = malloc(sizeof(Node));
    root->value = pre[(*pre_index)++];
    root->left = NULL;
    root->right = NULL;

    if (in_start == in_end)
        return root;

    target[0] = root->value;
    pivot = strcspn(in, target);

    root->left = preorder(root, pre, in, pre_index, in_start, pivot - 1);
    root->right = preorder(root, pre, in, pre_index, pivot + 1, in_end);

    return root;
}

Node *postorder(Node *root, char *post, char *in, int *post_index, int in_start, int in_end) {
    int pivot;
    char target[2] = "\0";

    if (in_start > in_end)
        return NULL;

    root = malloc(sizeof(Node));
    root->value = post[(*post_index)--];
    root->left = NULL;
    root->right = NULL;

    if (in_start == in_end)
        return root;

    target[0] = root->value;
    pivot = strcspn(in, target);

    root->right = postorder(root, post, in, post_index, pivot + 1, in_end);
    root->left = postorder(root, post, in, post_index, in_start, pivot - 1);

    return root;
}

#define QUEUE_SIZE 20

void print_bfs(Node *root) {
    int head = 0, tail = 1;
    Node *queue[QUEUE_SIZE];

    queue[0] = root;

    while (head != tail) {
        printf("%c", queue[head]->value);

        if (queue[head]->left) {
            queue[tail] = queue[head]->left;
            tail = (tail + 1) % QUEUE_SIZE;
        }

        if (queue[head]->right) {
            queue[tail] = queue[head]->right;
            tail = (tail + 1) % QUEUE_SIZE;
        }

        head = (head + 1) % QUEUE_SIZE;
    }
}

void print_preorder(Node *root) {
    if (root) {
        printf("%c", root->value);
        print_preorder(root->left);
        print_preorder(root->right);
    }
}

void print_inorder(Node *root) {
    if (root) {
        print_inorder(root->left);
        printf("%c", root->value);
        print_inorder(root->right);
    }
}

void delete_tree(Node *root) {
    if (root) {
        delete_tree(root->left);
        root->left = NULL;
        delete_tree(root->right);
        root->right = NULL;
        free(root);
    }
}

int main() {
    Node *root = NULL;
    int index;
    char m1, m2;
    char l1[MAX_STRING_LEN], l2[MAX_STRING_LEN];

    m1 = getchar();
    getchar();
    fgets(l1, MAX_STRING_LEN, stdin);
    l1[strcspn(l1, "\n")] = '\0';

    m2 = getchar();
    getchar();
    fgets(l2, MAX_STRING_LEN, stdin);
    l2[strcspn(l2, "\n")] = '\0';

    index = 0;
    if (m1 == 'P' && m2 == 'I')
        root = preorder(root, l1, l2, &index, 0, strlen(l1) - 1);
    if (m2 == 'P' && m1 == 'I')
        root = preorder(root, l2, l1, &index, 0, strlen(l1) - 1);

    index = strlen(l1) - 1;
    if (m1 == 'O' && m2 == 'I')
        root = postorder(root, l1, l2, &index, 0, strlen(l1) - 1);
    if (m2 == 'O' && m1 == 'I')
        root = postorder(root, l2, l1, &index, 0, strlen(l1) - 1);

    print_bfs(root);
    printf("\n");

    delete_tree(root);

    return 0;
}
