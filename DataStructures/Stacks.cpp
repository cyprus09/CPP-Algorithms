#include <stdio.h>
#define max 5

int t;
int data[max];

void stack_init(){
    t = -1;
}

int stack_empty(){
    if(t == -1){
        //printf("empty");
        return 1;
    }
    else{
        //printf("NOT empty");
        return 0;
    }
}

void stack_push(int add){
    t ++;
    if (t+1 > max){
        printf("cannot add more\n");
        return;
    }
    else{
        data[t] = add;
    }
}

void stack_pop(){
     if(stack_empty() == 1){
        printf("Error - Stack is empty\n");
     }
     else{
        t --;
     }
}

int stack_top(){
    if(stack_empty() == 1){
        printf("Error - Stack is empty\n");
     }
     else{
        return data[t];
     }
}

int stack_length(){
    int len;
    len = t + 1;
    return len;
}

void main(){
    int input;
    stack_init();

    while (1){
        printf("key-in: ");
        scanf("%d",&input);

    if (input > 0){
        stack_push(input);
        }
    else if (input == 0){
        stack_pop();
        }
    else {
        printf("%d\n",stack_top());
        printf("data in stack: %d\n",stack_length());
        }
    }
    }