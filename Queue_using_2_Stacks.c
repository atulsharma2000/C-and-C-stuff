#include<stdio.h>
#include<stdlib.h>
struct Stack{
    int size;
    int top;
    int *S;
}S1,S2;

void create(struct Stack *st){
    st->size=10;
    st->top=-1;
    st->S=(int *)malloc(st->size*sizeof(int));

}

void push(struct Stack *st, int x){
    if(st->top==st->size-1)
        printf("\nStack overflow\n");
    else
    {
        st->top++;

        st->S[st->top]=x;
    }    
}

int pop(struct Stack *st){
    int x=-1;
    if(st->top==-1)
        printf("\nStack Underflow\n");
    else
    {
        x=st->S[st->top--];  // post decrement of top
    }
    return x;
}

int isEmpty(struct Stack *st){
    if(st->top==-1)
        return 1;
    return 0;
}

void enqueue(int x){
    push(&S1,x);
}

int dequeue(){
    int x=-1;
    if(isEmpty(&S2)){
        if(isEmpty(&S1)){
            printf("Empty Queue!");
            return x;
        }
        else
        {
            while(!isEmpty(&S1))
                push(&S2,pop(&S1));
        }       
    }
    return pop(&S2);
}
void display(struct Stack *st){
    
    for(int i=st->top;i>=0;i--)
        printf("%d ",st->S[i]);
    printf("\n");
    
}

int main(){

    create(&S1);
    create(&S2);

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    int deleted_element=dequeue();
    printf("Dequeued Element is = %d\n",deleted_element);
    display(&S2);



    return 0;
}
