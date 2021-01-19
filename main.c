#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "homework4.h"

int main(int argc, const char * argv[])
{ 
    int i=0;
    char *caser = (char *) malloc(30*sizeof(char));
    for(int k=1;k<argc;k++){
        *caser = *argv[k];

        

    }

    switch (caser[i])
    {   
        default:;
            char t[100];
            node *root=(node*)malloc(sizeof(node));
            for(int i=0;i<NUM_LETTERS;i++)
            {
                root->children[i]=NULL;
            }
            root->letter='*';
            root->count=0;
            while(fgets(t, 100 , stdin) != NULL)
            {
                insert(root, t);
            }
            frequancy(root, temp);
            caser = (char *) realloc(caser, i);
            free(root);
            free(caser);
            break;




        case 'r':;
            char t2[100];
            node *root2=(node*)malloc(sizeof(node));

            for(int i=0;i<NUM_LETTERS;i++)

            {

                root2->children[i]=NULL;
            }

            root2->letter='*';

            root2->count=0;

            while(fgets(t2, 100 , stdin) != NULL)
            {

                insert(root2, t2);
            }
            frequancy2(root2, temp);
            caser = (char *) realloc(caser, i);
            free(root2);
            free(caser);


            break;

    }
    return 0;

    
        
    
}