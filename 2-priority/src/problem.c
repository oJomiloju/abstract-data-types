#include <stdio.h>
#include <stdlib.h>
#include "transcript.h"
#include "adt.h"

/* Usage: ./mysolution [filename]*/
Line* transcript[1000];
int main(int argc, char *argv[])
{
    char* filename = argv[1];
    int n = readTranscript(filename, transcript);


    // Initiatilize your ADT
    PriorityQueue *ADT = createPriorityQueue();
    
    // Translate transcript to your ADT functions
    for(int i = 0; i < n; i++){
        int priority = atoi(transcript[i]->action);
        enqueue(ADT,transcript[i]->data,priority);
        // printf("Priority %d - %s\n", priority, transcript[i]->data); // Comment out when running make test

    }
    
    // Print the priority list from your ADT
    printPriorityQueue(ADT);
    
    // Memory cleanup
    destroyTranscript(transcript, n);

    return EXIT_SUCCESS;
}
