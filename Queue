#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct ArrayQueue
{
    int front,rear;
    int capacity;
    int *array;
};

struct ArrayQueue* Create(int cap)
{
  struct ArrayQueue *Q;

  Q=(struct ArrayQueue*)malloc(sizeof(struct ArrayQueue));
  if(!Q) return NULL;
  Q->capacity=cap;
  Q->front=Q->rear=-1;

  Q->array=(struct ArrayQueue*)malloc(sizeof(int)*cap);
  if(!Q->array) return NULL;
  return Q;
}

int isEmptyQueue(struct ArrayQueue* Q)
{
    return (Q->front==-1);
}

int isFullQueue(struct ArrayQueue* Q)
{
    if((Q->rear+1)%Q->capacity==Q->front)
        return 1;
    return 0;
}

int QueueSize(struct ArrayQueue* Q)
{
    printf("%d",(Q->capacity-Q->front+Q->rear+1)%Q->capacity);
    getch();
}

void Insert(struct ArrayQueue* Q)
{
        if(isFullQueue(Q))
       {
            printf("Queue is Full.");
            getch();
       }
       else{
             Q->rear=(Q->rear+1)%Q->capacity;
             printf("\nEnter Data:");
             scanf("%d",&Q->array[Q->rear]);

             if(Q->front==-1)
                Q->front=Q->rear;
       }
}

void Delete(struct ArrayQueue* Q)
{


    if(isEmptyQueue(Q))
    {
         printf("Queue is Empty.");
         getch();
    }
    else{
           printf("%d is Deleted from Queue.",Q->array[Q->front]);
           Q->array[Q->front]=NULL;
          if(Q->front==Q->rear)
             Q->front=Q->rear=-1;
          else
             Q->front=(Q->front+1)%Q->capacity;
    }
    getch();
}

void Display(struct ArrayQueue* Q)
{
  int i;
  i=Q->front;

  if(isEmptyQueue(Q))
  {
      printf("Queue is Empty.");
  }
  else{
        while(i!=Q->rear+1)
          {
            printf("%d ",Q->array[i]);
            i=i+1%Q->capacity;
          }
  }
  getch();
}

int main()
{
    struct ArrayQueue* Q;
    int cap;

    printf("Enter Capacity:");
    scanf("%d",&cap);

    Q=Create(cap);

    while(1)
    {int ch;
        system("cls");

        printf("1] Insert\n");
        printf("2] Size of queue\n");
        printf("3] Delete\n");
        printf("4] Display\n");
        printf("5] Exit");

        printf("\nEnter the choice:");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                     Insert(Q);
                     break;
            case 2:
                     QueueSize(Q);
                     break;
            case 3:
                     Delete(Q);
                     break;
            case 4:
                     Display(Q);
                     break;
            case 5:
                     exit(0);
        }
    }

    return 0;
}


