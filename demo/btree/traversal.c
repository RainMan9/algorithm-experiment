#include <stdio.h>

//顺序存储二叉树
/*
#define LENGTH 100  
typedef char datatype;  
typedef struct node{  
    datatype data;  
    int lchild,rchild;  
    int parent;  
}Node;  
Node tree[LENGTH];  
int length;  
int root;  
*/

//链式存储二叉树
typedef char datatype;  
  
typedef struct BinNode{  
    datatype data;  
    struct BinNode* lchild;  
    struct BinNode* rchild;  
}BinNode;  
  
typedef BinNode* bintree;          //bintree本身是个指向结点的指针 

//前序遍历,递归遍历
/*
void preorder(bintree t){  
    if(t){  
        printf("%c ",t->data);  
        preorder(t->lchild);  
        preorder(t->rchild);  
    }  
}  
*/

//因为当遍历过根节点之后还要回来，所以必须将其存起来。考虑到后进先出的特点，选用栈存储。数量确定，以顺序栈存储。
#define SIZE 100  
typedef struct seqstack{  
    bintree data[SIZE];  
    int tag[SIZE];   //为后续遍历准备的  
    int top;     //top为数组的下标  
}seqstack;  
  
void push(seqstack *s,bintree t){  
  
    if(s->top == SIZE){  
        printf("the stack is full\n");  
    }else{  
        s->top++;  
        s->data[s->top]=t;  
    }  
}  
  
bintree pop(seqstack *s){  
    if(s->top == -1){  
        return NULL;  
    }else{  
        s->top--;  
        return s->data[s->top+1];  
    }  
}  

//前序遍历,非递归遍历

void preorder_dev(bintree t){  
    seqstack s;  
    s.top = -1;     //因为top在这里表示了数组中的位置，所以空为-1  
    if(!t){  
        printf("the tree is empty\n");  
    }else{  
        while(t || s.stop != -1){  
            while(t){    //只要结点不为空就应该入栈保存，与其左右结点无关      
                  printf("%c ",t->data);  
                push(&s,t);  
                t= t->lchild;  
            }  
            t=pop(&s);  
            t=t->rchild;  
        }  
    }  
} 