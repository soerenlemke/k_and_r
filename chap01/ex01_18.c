//
// Created by soerenlemke on 08.01.26.
//

#include <stdio.h>
#include <stdbool.h>
#include <string.h>


#define MAXLINE 1000
#define LINESBUFFER 100

bool got_newline = false;

int getline(char line[], int max);

void copy(char to[], const char from[]);

void remove_trailing_blanks_and_tabs(char line[]);

int main(void) {
    int len;
    int current_len = 0;

    char line[MAXLINE];
    char current_text[MAXLINE];
    int current_text_len = 0;

    while ((len = getline(line, MAXLINE)) > 0) {
        current_len += len;

        for (int i = 0; i < len && current_len < MAXLINE - 1; i++) {
            current_text[current_text_len++] = line[i];
        }
        current_text[current_text_len] = '\0';

        remove_trailing_blanks_and_tabs(current_text);
        printf("%s", current_text);

        // TODO: delete entirely empty lines

        if (got_newline) {
            current_len = 0;
            current_text_len = 0;
            current_text[0] = '\0';
        }
    }

    return 0;
}

int getline(char line[], const int max) {
    int c = 0;
    int i = 0;
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

// TODO: check function logic
void remove_trailing_blanks_and_tabs(char line[]) {
    size_t len = strlen(line);

    while (len > 0 && (line[len - 1] == ' ' || line[len - 1] == '\t')) {
        len--;
    }

    line[len] = '\0';
}
