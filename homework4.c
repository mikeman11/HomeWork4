#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_LETTERS ((int)26)
typedef enum {FALSE=0, TRUE=1} boolean;
typedef struct node {
    char letter;
    long unsigned int count;
    struct node* children[NUM_LETTERS];
} node;

node * inserter(node *root,char x)
{
    node *ptr=NULL;
    if(x<='Z'&&x>='A')
    {
        x+=32;
    }
    if(x-'z'<NUM_LETTERS&&x-'a'>=0)
    {
        if(root->children[x-'a']!=NULL)
        {
            return root->children[x-'a'];
        }
        ptr=(node *)malloc(sizeof(node));
        root->children[x-'a']=ptr;
        for(int i=0;i<NUM_LETTERS;i++)
        {
            ptr->children[i]=NULL;
        }
        ptr->letter=x;
        ptr->count=0;
        root=ptr;
    }
    return root;
}
void insert(node * root,char x[100])
{
    for(int i=0;i<strlen(x);i++)
    {
        root=inserter(root, x[i]);
    }
    root->count++;
}
char temp[100]={0};
void frequancy(node *root,char x[100])
{
    
    for(int i=0;i<NUM_LETTERS;i++)
    {
        if(root->children[i]!=NULL)
        {
            strcat(x, &root->children[i]->letter);
            if(root->children[i]->count!=0)
            {
                printf("%s %lu\n",x,root->children[i]->count);
            }
            frequancy(root->children[i], x);
        }
    }
    x[strlen(x)-1]=0;
}
void frequancy2(node *root,char x[100])
{
    
    for(int i=NUM_LETTERS-1;i>=0;i--)
    {
        if(root->children[i]!=NULL)
        {
            strcat(x, &root->children[i]->letter);
            if(root->children[i]->count!=0)
            {
                printf("%s %lu\n",x,root->children[i]->count);
            }
            frequancy2(root->children[i], x);
        }
    }
    x[strlen(x)-1]=0;
    
}
