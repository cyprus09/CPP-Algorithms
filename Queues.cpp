#include <stdio.h>
#define SIZE 5

int front,tail,length;
int data[SIZE];

void queue_init(){
    front = tail = -1;
}

int queue_empty(){
    if(front == -1 || tail == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(int add){
    if(queue_empty() == 1){
        front = 0;
        tail = 0;
    }
    else if (length >= SIZE){
        printf("cannot add more\n");
        return;
    }
    else{
        tail = (tail + 1)% SIZE;
        // for case that tail is in front of front
        }
    data[tail] = add;
    length ++;
}

void dequeue(){
     if(queue_empty() == 1){
        printf("Error - Queue is empty\n");
     }
     else if(front == tail){
        data[front] = 0;
        front = -1;
        tail = -1;
    }
    else{
        data[front] = 0;
        front = (front + 1)% SIZE;
        // normal operation
    }
    length --;
}

int show(){
    if(queue_empty() == 1){
        printf("Error - Queue is empty\n");
     }
     else{
        return data[front];
     }
}


void main(){
    int input;
    queue_init();

    while (1){
        printf("key-in: ");
        scanf("%d",&input);

    if (input > 0){
        enqueue(input);
        }
    else if (input == 0){
        dequeue();
        }
    else {
        printf("%d\n",show());
        printf("data in queue: %d\n",length);
        }
    }
    }