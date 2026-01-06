//
// Created by soerenlemke on 05.01.26.
//

#include <stdio.h>
#include <stdlib.h>
#include <../include/grund.h>

#define MAXLINE 1000

int getline(char line[]);

int main() {
    char buf[MAXLINE];
    const int len = getline(buf);
    printf("len=%d\n", len);
    return 0;
}

int getline(char line[]) {
    int c, i = 0;

    while (i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n') {
        GRUND_LOG("logging something");
        line[i++] = (char) (unsigned char) c;
    }

    GRUND_TODO("attach new line and null terminator'\0'");
}
