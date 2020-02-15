#include "binary_search_tree.h"
#include <stdlib.h>

static int fill_array(node_t* tree, int* array, int pos);

node_t *build_tree(int *tree_data, size_t tree_data_len)
{
    node_t* tree = (node_t*) calloc(1,sizeof(node_t));
    node_t* current_node = tree;
    _Bool found_free_node = 0;
    tree->data = *tree_data;
    tree->left = NULL;
    tree->right = NULL;
    for (unsigned int i=1; i < tree_data_len; i++)
    {
        while (!found_free_node)
        {
            if (current_node->data >= tree_data[i])
            {
                if (current_node->left == NULL)
                {
                    current_node->left = (node_t*) calloc(1,sizeof(node_t));
                    found_free_node = 1;
                }
                current_node = current_node->left;
            }
            else
            {
                if (current_node->right == NULL)
                {
                    current_node->right = (node_t*) calloc(1,sizeof(node_t));
                    found_free_node = 1;
                }
                current_node = current_node->right;
            }
        }
        current_node->data = tree_data[i];
        found_free_node = 0;
        current_node = tree;
    }
    return tree;
}

void free_tree(node_t * tree)
{
    if (tree->left != NULL) free_tree(tree->left);
    if (tree->right != NULL) free_tree(tree->right);
    free(tree);
}

int *sorted_data(node_t * tree)
{
    int* data = (int*) calloc (BUFFER_SIZE, sizeof(int));
    fill_array(tree, data, 0);
    return data;
}

static int fill_array(node_t* tree, int* data, int pos)
{
    if(tree->left != NULL) pos = fill_array(tree->left, data, pos);
    data[pos++] = tree->data;
    if(tree->right != NULL) pos = fill_array(tree->right, data, pos);
    return pos;
}
