/* CS1 assignment 2 by Mehrob Farhangmehr*/

#include<stdio.h>
#include<stdlib.h>
 typedef struct node{
	int data;
	struct node *next;
}node;
node *root;

void addN(struct node* list,int n);//adds N to each value of the link list
struct node* deleteFirst(struct node* list);//deletes the first item in the link list
struct node* copyList(struct node* list);
struct node* isSorted(struct node* list);
void insertToPlace(struct node* list,int val,int place);

int main(void)
{
	root=NULL;
	node *t,del;
	int ch,ele,v,increase,insert,pos;
	while(1)
	{
		printf("\nMenu: 1. insert at front, 2. insert at end, 3. Delete 4. \nIncrease 5. Delete Front 6.Copy the list 7.Check Sorting 8. Insert 9.exit:");
	    scanf("%d",&ch);
		if(ch==9)
		{
			printf("\nGOOD BYE>>>>\n");
			break;
		}
		if(ch==1){
			printf("\nEnter information(an integer): ");
			scanf("%d",&ele);
			insert_front(ele);
			printf("\nPrinting ur link list.......");
			t=root;
			while(t!=NULL)
			{
				printf("%d ",t->data);
				t=t->next;
			}
		}
		if(ch==2)
		{
			printf("\nEnter information(an integer): ");
			scanf("%d",&ele);
			insert_end(ele);
			printf("\nPrinting ur link list.......");
			t=root;
			while(t!=NULL)
			{
				printf("%d ",t->data);
				t=t->next;
			}
		}
	   if(ch==3){
		 printf("\nEnter info which u want to DELETE: ");
		 scanf("%d",&del.data);
		 v=DelList(del.data);
		 if(v==1)
		 {
			printf("\nDELETing....");
			t=root;
			while(t!=NULL)
			{
				printf("%d ",t->data);
				t=t->next;
			}
		 }
		  else if(v==0)
			printf("\nUr info does not exist in the list");
	   }
	   if (ch==4){
	   	printf("\nEnter the number you want to Increase by:");
	   	scanf("%d",&increase);
	   	addN(t,increase);	   	
	   }
	   if (ch==5){
	   	printf("\nWe are deleting the front of the head...");
	   	deleteFirst(t);
	   }
	   if (ch==6){
	   printf("\nWe are copying the list...\n");
	   copyList(t);
	   }
	   if (ch==7){
	   	printf("\nChecking if in order...\n");
	   	if (isSorted(t) == 1){
	   		printf("Hey, it's in order");
		   }
		else {
			printf("Sorry, it's not in order or empty....");
		}
		printf("\nPrinting the list...");
		t=root;
		while(t!=NULL)
		{
				printf("%d ",t->data);
				t=t->next;
			}	   	
	   }
	   if (ch=8){
	   	printf("\nWhat number do you want to insert:\n");
	   	scanf("%d",&insert);
	   	printf("\nWhat position?");
	   	scanf("%d",&pos);
	   	insertToPlace(t,insert,pos);
		printf("\nPrinting the list...");
		t=root;
		while(t!=NULL)
		{
				printf("%d ",t->data);
				t=t->next;
			}	   	
	   } 
	}
}

void insert_front(int item)
{
	node *temp;
	temp= (node *) malloc(sizeof(node));
	temp->data=item;
	temp->next=NULL;
	if(root==NULL)
        root=temp;
    else
    {
        temp->next = root;
        root = temp;
    }

}


void insert_end(int item)
{
	node *t;
	node *temp;
	temp= (node *) malloc(sizeof(node));
	temp->data=item;
	temp->next=NULL;
	if(root==NULL)
		root=temp;
	else
	{
		t=root;
        while(t->next!=NULL)
            t=t->next;
        t->next=temp;
	}
}

int DelList(int item)
{
	node *t;
	node *temp;
	if(root==NULL)
		return 0;
	if(root->data==item)
	{
		temp=root;
		root=root->next;
		free(temp);
		return 1;
	}

	t=root;

	while(t->next!=NULL && t->next->data != item)
		t=t->next;
	if(t->next==NULL)
		return 0;
	temp=t->next;
	t->next=t->next->next;
	free(temp);
	return 1;
}

void addN(node* list,int n){
	list = root;
	while (list != NULL){
		list->data=list->data+n;
		list=list->next;
	}
	list=root;
	printf("Printing the list... ");
	while(list!=NULL){
	printf("%d ",list->data);
	list=list->next;
	}	   	
}

node* deleteFirst(node* list){
	node *temp=root;

	if (root == NULL){
		return NULL;
	}
	
	root = root->next;
	list=root;
	printf("Printing the list... ");
	while(list!=NULL){
	printf("%d ",list->data);
	list=list->next;
	}	   	
	return root;

}

node* copyList(node *list){
	node* list2;
	list2 = (node *) malloc(sizeof(node));
	
	while (list != NULL){
		list2->data=list->data;
		list2=list2->next;
		list=list->next;
	}
	list2=root;
	printf("Printing the list... ");
	while(list2!=NULL){
	printf("%d ",list2->data);
	list2=list2->next;
	}	   		
	free(list2);
}

node* isSorted(struct node *list) {
	int sorted=1;
	int compare,a;
	if (root==NULL){
		return 0;
	}
	list = root;
	
	while (list->next != NULL){
	compare=list->data;
	a = list->next->data;
		if (a < compare){
			sorted = 0;
		}
	list=list->next;	
	}
	
	return sorted;
} 

void insertToPlace(struct node* list,int val,int place){
	int i;
	node *temp;
	temp= (node *) malloc(sizeof(node));
	temp->data=val;
	temp->next=NULL;
	if(root==NULL)
        root=temp;
    else
    {
		for (i=0;i<place && list->next != NULL;i++){
			printf("yert");
			list=list->next;
			}
		}
		list->data=val;
        temp->next = root;
        root = temp;
}
