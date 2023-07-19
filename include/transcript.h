
#ifndef TRANSCRIPT_H
#define TRANSCRIPT_H

// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

// Definitions
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1


typedef struct {
    char action[100];
    char data[500];
}Line;


int readTranscript(char *file, Line* transcript[]);
void destroyTranscript(Line* transcript[], int n);
#endif /* TRANSCRIPT_H */