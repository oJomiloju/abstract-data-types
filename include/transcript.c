#include "transcript.h"

// DO NOT ALTER 

void destroyTranscript(Line* transcript[], int n){
    for(int i = 0; i < n; i++){
        free(transcript[i]);
    }
}
int readTranscript(char *file, Line* transcript[]){
    char action[10], data[200];
    int matches;
    FILE *fp;

    fp = fopen(file,"r");
    if(fp == NULL)
    {
        printf("Error!");  
        exit(1);             
    }
    int i = 0;
    while((matches = fscanf(fp, "%s %99[^\n]%*1[\n]", action, data) == 2)){
        Line* line = malloc(sizeof(Line));
        if(line == NULL){
            fprintf(stderr, "Error allocating memory!");
            exit(EXIT_FAILURE);
        }
        strcpy(line->action, action);
        strcpy(line->data, data);
        transcript[i] = line;
        i++;
    }
    fclose(fp);
    return i;
}
