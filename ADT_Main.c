#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ADT_Eile.h"
#include "ADT_Tipas.h"

// This example when ran: asks to enter two seperate symbol queues (example: aaaaaacd, bbbbbbef)
// and it makes a new queue putting one character from each queue and repeating (example outcome: ababababababcedf)

int main ()
{
  struct Queue Queue1 = CreateMyQueue(), Queue2 = CreateMyQueue(); //Making two queues
  QueueElement QueueSimbol; //Listing an element which will read the simbols we need to put in the queues

  printf("Enter the first simbol queue: ");

  QueueSimbol = getchar();

  while (getchar() != '\n') //Reading the first queue
  {
    PushToQueue (&Queue1, QueueSimbol);
    QueueSimbol = getchar();
  }

  printf("Enter the second simbol queue: ");

  QueueSimbol = getchar();

  while (getchar() != '\n') //Reading the second queue
  {
    PushToQueue (&Queue2, QueueSimbol);
    QueueSimbol = getchar();
  }

  return 0;
}
