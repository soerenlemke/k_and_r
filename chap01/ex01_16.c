//
// Created by soerenlemke on 05.01.26.
//

#include <stdio.h>
#include <stdbool.h>

#define MAXLINE 1000

bool got_newline = false;

int getline(char line[], int max);

void copy(char to[], const char from[]);

int main(void) {
    int len;
    int current_len = 0;
    int max_len = 0;

    char line[MAXLINE];

    char current_text[MAXLINE];
    int current_text_len = 0;

    char longest[MAXLINE];
    longest[0] = '\0';

    while ((len = getline(line, MAXLINE)) > 0) {
        current_len += len;

        for (int i = 0; i < len && current_len < MAXLINE - 1; i++) {
            current_text[current_text_len++] = line[i];
        }
        current_text[current_text_len] = '\0';

        if (got_newline) {
            if (current_len > max_len) {
                max_len = current_len;
                copy(longest, current_text);
            }
            current_len = 0;
            current_text_len = 0;
            current_text[0] = '\0';
        }
    }

    if (current_len > 0 && current_len > max_len) {
        max_len = current_len;
        copy(longest, current_text);
    }

    if (max_len > 0) {
        printf("Longest line: %d chars\n", max_len);
        printf("As many chars as possible: %s\n", longest);
        if (max_len > 0 && longest[max_len - 1] != '\n') {
            printf("\n");
        }
    }

    return 0;
}

int getline(char line[], const int max) {
    int c, i = 0;
    got_newline = false;

    while (i < max - 1 && (c = getchar()) != EOF && c != '\n') {
        line[i++] = (char) (unsigned char) c;
    }

    if (c == '\n') {
        got_newline = true;
        if (i < max - 1)
            line[i++] = '\n';
    } else if (c == EOF) {
        got_newline = true;
    }

    line[i] = '\0';
    return i;
}

void copy(char to[], const char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') {
        i++;
    }
}
