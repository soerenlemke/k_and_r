//
// Created by soerenlemke on 05.01.26.
//

#include <stdio.h>
#include <stdlib.h>
#include <slk/debug.h>

#define MAXLINE 1000

int getline(char line[]);

int main() {
    char buf[MAXLINE];
    int len = getline(buf);
    printf("len=%d\n", len);
    return 0;
}

int getline(char line[]) {
    int c, i = 0;

    while (i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n') {
        line[i++] = (char) (unsigned char) c;
    }

    SLK_TODO("attach new line and null terminator'\0'");
}


