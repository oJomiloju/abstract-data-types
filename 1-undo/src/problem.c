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
    int i_data;

    // Initiatilize your ADT
    Stack s;
    s.top = 0;
    int track = 1; // helps track location we are in the stack
    
    // Translate transcript to your ADT functions
    for(int i = 0; i < n; i++){
        if(strcmp(transcript[i]->action, "Type") == 0){
            // Do something with your ADT
            push(&s,transcript[i]->data);
            //print_stack(&s);
            //printf("Type %s\n", transcript[i]->data); // Comment out when running make test
            }
        if(strcmp(transcript[i]->action, "Undo") == 0){
            // Do something with your ADT

            i_data = atoi(transcript[i]->data);
            for (track = 1; track <= (i_data); track++)
            {
                pop(&s);
            }
            //printf("Undo %d\n", i_data); // Comment out when running make test
        }
        if(strcmp(transcript[i]->action, "Redo") == 0){
            // Do something with your ADT
            i_data = atoi(transcript[i]->data);
            push(&s,transcript[i-track]->data);
            track--;

            
            //printf("Redo %d\n", i_data); // Comment out when running make test
        }

    }

    // Print out the final text (after redo/undo)
    print(&s);
    printf("\n");
    

    // Memory cleanup
    destroyTranscript(transcript, n);

    return EXIT_SUCCESS;
}
