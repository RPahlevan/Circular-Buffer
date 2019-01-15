#include <stdio.h>
#include <stdlib.h>

//circular buffer implementation
#define max_len 512

int Circ_Buff[max_len];
int rear=-1;// enqueue from head
int front=-1;// dequeue from tail


//function prototype
int push(int );
int is_empty(void);
int pop();
void Print();

int main(int argc, char* argv[])
{
	push(2);  Print();  
	push(4); Print();  
	push(6);  Print();
	pop();   Print();
	push(8);  Print();
	
	return 0;
}

int pop()
{
	if (is_empty()==0)
	{
		return -1;//no element inside the buffer 
	}else if (front==rear)
	{
		rear=front=-1;//only one element is inside the buffer
	}else
	{
		front=(front+1)%max_len;
	}
}
int push(int data)
{
	//when buffer is full
	if(((rear+1)%max_len)==front)
	{
		return -1;// it means buffer is full
	}else if(is_empty()==0)
	{
		front=rear=0;// add the frist element to the array
	}else
	{
		rear=(rear+1)%max_len;// increment the rear index
	}
	Circ_Buff[rear]=data;
}


int is_empty()
{
	if (front==rear && front==-1)
	{
		return 0;// if empty, it will return 0
	}
	return 1;// if not emty, it will return 1
}

void Print()
{
	// Finding number of elements in queue
	int count = (rear+max_len-front)%max_len + 1;
	printf("\nQueue       : ");
	int i;
	for(i = 0; i <count; i++)
	{
		int index = (front+i) % max_len; // Index of element while travesing circularly from front
		printf(" %d",Circ_Buff[index]);
	}
	printf("\n\n");
}
