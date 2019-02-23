#ifndef ADT_EILE_H
#define ADT_EILE_H
#include "ADT_Tipas.h"


struct QueueNode //Creating a node that every queue element will use to store the links and the value of your choise
                 // This node will not need a name as it is not used to call any functions
{
  struct QueueNode *Next;
  struct QueueNode *Previous;
  QueueElement Data;
};

struct Queue //Creating a structure type that you will use for all the functioms, you can create as many queues as you want
             // example for creating queues "struct Queue q1 = CreateMyQueue(), q2 = CreateMyQueue;"
{
  struct QueueNode *Head;
  struct QueueNode *Tail;
  int Size;
};

struct Queue CreateMyQueue (void); //A function that creates an empty line that points to nowhere and has a queue size value of 0
                                   // function has no parameters, example to call "CreateMyQueue ();"

struct QueueNode* CreateMyQueueNode (QueueElement MyData); //A function that returns and adress of a node that every queue element has
                                                           // example to call "CreateMyQueueNode (x);" (you shouldn't need this function as it's already being used in PushToQueue)

void PushToQueue (struct Queue* MyQueue, QueueElement MyData); //A function that puts a value into the queue's tail and increases the queue size by 1
                                                               // example to call "PushToQueue (q1, x)"

void DestroyQueue (struct Queue* MyQueue); //A function that destroys the entire queue and frees all the elements stored
                                           // example to call "DestroyQueue (q1)"

QueueElement PopFromQueue (struct Queue* MyQueue); //A function that returns that value that was stored in the queue and destroys the head reducing queue's size by 1
                                                   // example to call "PopFromQueue (q1)"

QueueElement GetHeadValue (struct Queue* MyQueue); //A function that does nothing with the queue, just returnes the value of the queue's head
                                                   // example to call "GetHeadValue (q2)"

bool IsQueueEmpty (struct Queue* MyQueue); //A function that returnes a bool value is the queue empty, true if queue is empty, false if not
                                           // example to call "IsQueueEmpty (q1)"

int QueueSize (struct Queue* MyQueue); //A function that returnes an int value of how many elements are in the queue
                                       // example to call "QueueSize (q1)"
#endif
