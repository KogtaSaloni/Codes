//Why is no elements to delete not getting printed?
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int value;
	struct node* next;
} *head, *save, *prev;

void enqueque(int value)
{
	save = (struct node*)malloc(sizeof(struct node));
	save-> value=value;
	save->next=head;
	head = save;
}

void dequeue()
{
	if(head==NULL)
		printf("No Elements to dequeue.\n");
	else
	{
		prev = (struct node*)malloc(sizeof(struct node));
		save=head;
	while(save->next != NULL)
	{
		prev = save;
		save = save->next;
	}

	prev->next=NULL;
	free(save);
	}
}

void print()
{
	save=head;
	while(save != NULL)
	{
	printf("%d->\n",save->value );
	save = save->next;
	}
}

int main()
{
	int value=5,choice=1;
	head = (struct node*)malloc(sizeof(struct node));
	save = (struct node*)malloc(sizeof(struct node));

	head->value = value;
	head->next = NULL;
	//save=head;
	printf("Menu:\n0)Exit\n1)Insert\n2)Delete\n3)Print Queue\n");
	scanf("%d",&choice);

	while(choice != 0)
	{
		if (choice==1)
		{
			printf("Element to be inserted: "); 
				scanf("%d", &value);
			enqueque(value);
		}

		else if(choice == 2)
		{
			dequeue();
		}
		else if(choice == 3)
		{
			print();
		}
		printf("Menu:\n0)Exit\n1)Insert\n2)Delete\n3)Print Stack\n");
		scanf("%d",&choice);

	}
	
return 0;
}