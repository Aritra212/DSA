// Link list follow LIFO manner
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
typedef struct Node * Nodeptr;

Nodeptr CreateNode();
Nodeptr InsertBeg(Nodeptr);
Nodeptr InsertEnd(Nodeptr);
void InsertAffter(Nodeptr);
Nodeptr DeleteBeg(Nodeptr);
Nodeptr DeleteEnd(Nodeptr);
void DeleteAffter(Nodeptr);
void Display(Nodeptr);

int main(){
    int n;
    Nodeptr start= NULL;

    while(1){
        printf("\n--------------------------------------------\n");
        printf("\nEnter '1' to insert node into beginning");
        printf("\nEnter '2' to insert node into end");
        printf("\nEnter '3' to insert node into specific position");
        printf("\nEnter '4' to delete node from beginning");
        printf("\nEnter '5' to delete node from specific position");
        printf("\nEnter '6' to delete node from End");
        printf("\nEnter '7' to display Link list");
        printf("\nEnter '8' to exit");

        printf("\nEntr your choice:: ");
        scanf("%d",&n);

        switch(n){
            case 1: start= InsertBeg(start);
            break;
            case 2: start= InsertEnd(start);
            break;
            case 3: InsertAffter(start);
            break;
            case 4: start= DeleteBeg(start);
            break;
            case 5: start= DeleteEnd(start);
            break;
            case 6: DeleteAffter(start);
            break;
            case 7: Display(start);
            break;
            case 8: exit(0);
            break;
            default: printf("Invalid Choice");
        }
    }
}

Nodeptr CreateNode(){
    Nodeptr address;
    address = (Nodeptr) malloc(sizeof(Nodeptr));
    address->next=NULL;
    return address;
}

Nodeptr InsertBeg(Nodeptr start){
    Nodeptr temp;
    int item;
    printf("\nEnter node item/data: ");
    scanf("%d",&item);
    temp = CreateNode();
    temp->data= item;
    if(start!= NULL){
        temp->next= start;
    }
    start= temp;
    printf("\nNode Inserted sucessfully enter '7' to display");
    return start;
}

Nodeptr InsertEnd(Nodeptr start){
    Nodeptr temp, ptr = start;
    int item;

    temp= CreateNode(start);
    printf("\nEnter Data:: ");
    scanf("%d",&item);
    temp->data= item;

    if(start== NULL){
        start= temp;
    }
    else{
        while(ptr->next!=NULL){
            ptr= ptr->next;
        }
        ptr->next= temp;
    }
    printf("\n%d Inserted",temp->data);
    return start;
}

void InsertAffter(Nodeptr start){
    int n,i;
    Nodeptr ptr=start, temp;

    if(ptr==NULL){
        printf("\nEmpty List insert some node first.");
    }
    else{
        printf("\nEnter Position: ");
        scanf("%d",&n);
        for(i=1;i<n;i++){
            if(ptr==NULL){
                break;
            }
            ptr=ptr->next;
        }
        if(ptr!=NULL){
            temp= CreateNode(start);
            printf("\nEnter Data:: ");
            scanf("%d",&n);
            temp->data= n;

            temp->next= ptr->next;
            ptr->next= temp;
            printf("\n%d Inserted",temp->data);
        }
        else{
            printf("\nInvalid Position");
        }
    }
}
Nodeptr DeleteBeg(Nodeptr start){
    Nodeptr temp;
    temp= start;
    if(start==NULL){
        printf("\nThe List is empty insert some data before delete.");
    }
    else{
        start= start->next;
        printf("\n%d is deleted.",temp->data);
        free(temp);
    }
    return start;
}
Nodeptr DeleteEnd(Nodeptr start){
    Nodeptr temp, ptr= start;
    if(start== NULL){
        printf("\nLinked List is empty");
    }
    else{
        if(start->next==NULL){
            temp= start;
            start=NULL;
        }
        else{
            while(ptr->next->next!=NULL){
                ptr= ptr->next;
            }
            temp= ptr->next;
            ptr->next= NULL;
        }
        printf("\n%d deleted",temp->data);
        free(temp);
    }
    return start;
}
void DeleteAffter(Nodeptr start){
    int n,i;
    Nodeptr ptr=start, temp;

    if(ptr==NULL){
        printf("\nEmpty List insert some node first.");
    }
    else{
        printf("\nEnter Position: ");
        scanf("%d",&n);
        if(n==1){
            printf("\nYou cann't delete first node by this function try Delete from end/beginning function to do this work.");
        }
        else{
            for(i=2;i<n;i++){
                ptr=ptr->next;
                if(ptr==NULL){
                    printf("\nInvalid Position");
                    break;
                }
            }
            if( ptr!=NULL && ptr->next!=NULL){
                printf("%d ",ptr->data);
                temp= ptr->next;
                ptr->next= ptr->next->next;
                printf("\n%d Deleted",temp->data);
                free(temp);
            }
        }
    }
}
void Display(Nodeptr start){
    Nodeptr ptr= start;
    if(start== NULL){
        printf("\nNo node to show please insert some nodes before display");
    }
    else{
        printf("\nThe list element(s) is(are) : ");
        while(ptr!=NULL){
            printf("%d ",ptr->data);
            ptr= ptr->next;
        }
    }
}