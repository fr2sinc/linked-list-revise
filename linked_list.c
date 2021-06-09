/* This file contains a simple library to review linked list in c. */
#define MAXC 40
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char value[MAXC];
    struct node* next;
} node;

node* createNode(){
    node* new;
    new = malloc(sizeof(node));
    if(new == NULL){
        exit(1);
    }
    new->next = NULL;
    return new;
}

int addNode(node* new, node** init){
    node* current;
    if(*init == NULL){
        *init = new;
        return -1;
    }
    //slide all nodes
    for(current = *init; current->next != NULL; current = current->next){
        //slide
    }
    current->next = new;
    current->next->next = NULL;
    return 1;
}

int insertNode(node* q, node* p){
    //insert p after q
    if(p == NULL || q == NULL || p == q || q->next == p){
        return -1;
    }
    p->next = q->next;
    q->next = p;
    return 1;
}

int deleteNode(node** target, node** init){
    node *current;
    
    if(*target == *init){
        if((*init)->next != NULL){
            *init = (*target)->next;
        }
        else{
            *init = NULL;
        }
    }
    else{
        for(current = *init; current->next != *target; current = current->next){
            //slide
        }
        if(current == NULL){
            //not found
            return -1;
        }
        current->next = current->next->next;
    }
    free(*target);
    *target = NULL;
    return 1;
}

int printList(node* init){
    node* current;
    int count;
    
    if(init == NULL){
        //empty list
        return -1;
    }
    else{
        current = init;
               
        for(current = init; current != NULL; current = current->next){
            printf("%s\n", current->value);
            ++count;
        }
        return count;
    }
}

node* findValue(char* value, node* init){
    node* current;
    
    for(current = init; current != NULL; current = current->next){
        if(strcmp(value, current->value) == 0){
            return current;
        }
    }
    return NULL;
}

int main(){
    
    char ans, buffer[80];
    node* init = NULL;
    node* p = NULL;
    int not_found = 0;
    
    while(1){
        printf("Do you want to insert new element?(y/n): ");
        fgets(buffer, 80, stdin);
        sscanf(buffer,"%c", &ans);
	    if(ans == 'n'){ 
	        break;
	    }
        p = createNode();
        printf("Type something: ");
        fgets(buffer, 80, stdin);
        sscanf(buffer, "%80s", p->value);
        addNode(p, &init);
    }
    
    do {
        printList(init);
	    printf("Which one do you want to delete?: ");
	    scanf("%s", buffer);
	
        if((p=findValue(buffer,init)) != NULL){
    	    printf("Found ! : %s \n",p->value);
    	    not_found = 0;
    	    deleteNode(&p,&init);
    	    
            printf("List updated!\n");
            printList(init);
        }  
         else{
    	     printf("Not Found\n");
    	     not_found = 1;
	     }
	} while(not_found);
}



