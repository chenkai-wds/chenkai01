#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct listNode{
    char name[10];
    int num;
    int score;
    struct listNode *next;
}*head;

typedef struct listNode node;

void creathead()
{
    node* newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("Enter the name,num and score:\n");
    scanf("%s %d %d",newnode->name,&newnode->num,&newnode->score);
    newnode->next=NULL;
    head=newnode;
}

node* creatNode()
{
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("Enter the name,num and score:\n");
    scanf("%s %d %d",newnode->name,&newnode->num,&newnode->score);
    newnode->next=NULL;
    return newnode;
}

void printlist()
{
    node *pMove;
    pMove=head;
    printf("\n");
    printf("NAME\tNUMBER\tSCORE\n");
    while(pMove){
        printf("%s\t%d\t%d\n",pMove->name,pMove->num,pMove->score);
        pMove=pMove->next;
    }
}

void searchNode(int num)
{
    node *pMove;
    pMove=head;
    while(pMove->num!=num){
        pMove=pMove->next;
        if(!pMove){
            printf("There's no data you're looking for\n");
            return;
        }
    }
    printf("%s\t%d\t%d\n",pMove->name,pMove->num,pMove->score);    
}

void deleteNode(int num)
{
    node *pMove,*p;
    pMove=head;
    if(head->num==num){
        node *a;
        a=head;
        head=head->next;
        free(a);
        return;
    }
    while(pMove->num!=num){
        p=pMove;
        pMove=pMove->next;
        if(!pMove){
            printf("There's no data you want to delete\n");
            return;
        }
    }
    p->next=pMove->next;
    free(pMove);
    printf("finished!\n");
}

void modifyNode()
{
    int a,b,c;
    char name1[10],name2[10];
    printf("Please enter the name or number:\n");
    printf("Select name search and enter 1, then enter the name of the object to be modified.\n");
    printf("Select number search and enter 2, then enter the number of the object to be modified.\n");
    scanf("%d",&a);
    if(a==1){
        scanf("%s",name1);
        node *pMove;
        pMove=head;
        while(strcmp(pMove->name,name1)){
            pMove=pMove->next;
            if(!pMove){
                printf("There's no data you're looking for\n");
                return;
            }
        }
        printf("%s\t%d\t%d\n",pMove->name,pMove->num,pMove->score);
        printf("Enter 1 to change the name, 2 to change the number, 3 to change the score,and 4 to exit.\n");
        scanf("%d",&b);
        switch(b){
            case 1:
                printf("Input replacement name:\n");
                scanf("%s",name2);
                strcpy(pMove->name,name2);
                printf("finished!\n");
                break;
            case 2:
                printf("Input replacement number:\n");
                scanf("%d",&pMove->num);
                printf("finished!\n");
                break;
            case 3:
                printf("Input replacement score:\n");
                scanf("%d",&pMove->score);
                printf("finished!\n");
                break;
            case 4:
                exit(0);
                break;
        }
    }
    else if(a==2){
        scanf("%d",&c);
        node *pMove;
        pMove=head;
        while(pMove->num!=c){
            pMove=pMove->next;
            if(!pMove){
                printf("There's no data you're looking for\n");
                return;
            }
        }
        printf("%s\t%d\t%d\n",pMove->name,pMove->num,pMove->score);
        printf("Enter 1 to change the name, 2 to change the number, 3 to change the score,and 4 to exit.\n");
        scanf("%d",&b);
        switch(b){
            case 1:
                printf("Input replacement name:\n");
                scanf("%s",name2);
                strcpy(pMove->name,name2);
                printf("finished!\n");
                break;
            case 2:
                printf("Input replacement number:\n");
                scanf("%d",&pMove->num);
                printf("finished!\n");
                break;
            case 3:
                printf("Input replacement score:\n");
                scanf("%d",&pMove->score);
                printf("finished!\n");
                break;
            case 4:
                exit(0);
                break;
        }
    }
}
int main()
{
    int choice,x,number;
    printf("Each individual contains name, number and score.\n");
    printf("\nstart to creat linklist?(1/0)\n");
    scanf("%d",&choice);
    if(choice==1){
        printf("\nEnter the data please,like:joker 1 100\n");
        creathead();
    }else{
        exit(0);
    }
    do{
        printf("\n0.exit\n");
        printf("1.creat a new data node\n");
        printf("2.search a node\n");
        printf("3.delete a node\n");
        printf("4.print the linklist\n");
        printf("5.modify a node\n");
        scanf("%d",&x);
        node *pMove,*p;
        switch(x)
        {
            case 1:
                pMove=creatNode();
                if(!head->next){
                    head->next=pMove;
                    p=pMove;
                    head->next=p;
                    p->next=NULL;
                }
                p->next=pMove;
                p=p->next;
                p->next=NULL;
                break;
            case 2:
                printf("Please enter this node number:\n");
                scanf("%d",&number);
                searchNode(number);
                break;
            case 3:
                printf("Please enter this node number:\n");
                scanf("%d",&number);
                deleteNode(number);
                break;
            case 4:
                printlist();
                break;
            case 5:
                modifyNode();
                break;
            default:
                exit(0);
                break;
        }
        printf("continue?(1|0)\n");
        scanf("%d",&choice);
    }while(choice);
    return 0;
}