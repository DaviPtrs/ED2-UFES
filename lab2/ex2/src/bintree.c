#include <stdio.h>
#include <stdlib.h>
#include "../include/bintree.h"


binTree *newBinTree(){
    binTree *x = (binTree *) malloc(sizeof(binTree));
    x->head = NULL;
    return x;
}

int isEmpty_BinTree(binTree *x){
    if(x == NULL){
        printf("NULL binTree\n");
        exit(1);
    }else if(x->head == NULL){
        return 1;
    }else{
        return 0;
    }
}

node *newNode(int key){
    node *x = (node *) malloc(sizeof(node));
    x->key = key;
    x->left = NULL;
    x->right = NULL;
    return x;
}

int insert_BinTree(binTree *tree, int key){
    if(tree == NULL){
        printf("NULL binTree\n");
        return 0;
    }
    if(isEmpty_BinTree(tree)){
        tree->head = newNode(key);
        return 1;
    }else{
        node *currentNode = tree->head;
        while (key != currentNode->key){
            if(key > currentNode->key){
                node *temp = currentNode->right;
                if(temp == NULL){
                    currentNode->right = newNode(key);
                    return 1;
                }else{
                    currentNode = temp;
                }
            }else if(key < currentNode->key){
                node *temp = currentNode->left;
                if(temp == NULL){
                    currentNode->left = newNode(key);
                    return 1;
                }else{
                    currentNode = temp;
                }
            }
        }
        return 0;
    }
}


int search_BinTree(binTree * tree, int key){
    if(isEmpty_BinTree(tree)){
        return 0;
    }else{
        node *currentNode = tree->head;
        while(currentNode != NULL){
            if(key > currentNode->key){
                currentNode = currentNode->right;
            }else if(key < currentNode->key){
                currentNode = currentNode->left;
            }else{
                return 1;
            }
        }
        return 0;
    }
}


int height_BinTree(binTree *x){
    if(x == NULL){
        printf("NULL binTree\n");
        exit(1);
    }else{
        return recursiveHeight(x->head);
    }
}

int recursiveHeight(node *);

int recursiveHeight(node *x){
    if(x != NULL){
        int hl, hr;

        hl = recursiveHeight(x->left);
        hr = recursiveHeight(x->right);

        if(hl > hr){
            return (hl + 1);
        }else{
            return (hr + 1);
        }
    }
    return 0;
}



void freeBinTree(binTree *x){
    if(x != NULL){
        node *currentNode = x->head;
        node *upNode = NULL;

        while(currentNode != NULL){
            if (currentNode->left != NULL) {
                node *left = currentNode->left;
                currentNode->left = upNode;
                upNode = currentNode;
                currentNode = left;
            } else if (currentNode->right != NULL) {
                node *right = currentNode->right;
                currentNode->left = upNode;
                currentNode->right = NULL;
                upNode = currentNode;
                currentNode = right;
            } else {
                if (upNode == NULL) {
                    free(currentNode);
                    currentNode = NULL;
                }
                while (upNode != NULL) {
                    free(currentNode);
                    if (upNode->right != NULL) {
                        currentNode = upNode->right;
                        upNode->right = NULL;
                        break;
                    } else {
                        currentNode = upNode;
                        upNode = upNode->left;
                    }
                }
            }
        }
    }
    free(x);
}