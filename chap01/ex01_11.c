//
// Created by soerenlemke on 04.01.26.
//

#include <stdio.h>

#define IN  1
#define OUT 0

int main() {
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;

    while ((c = getchar()) != EOF) {
        ++nc;

        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }

    printf("%d %d %d\n", nl, nw, nc);
}

/*
- Empty input (EOF immediately): all counters stay 0.
- Single word (e.g. hello): nw should be 1, nl 0, nc equals the number of characters.
- Only whitespace (spaces/tabs/newlines): nw 0; nl counts only \n; nc counts everything.
- Leading/trailing whitespace (e.g. hello ): still nw 1 (checks correct OUT->IN transitions).
- Multiple delimiters in a row (e.g. a b\t\tc\n\n\nd): many state changes; should count nw as 4.
- One word per line: nw should match nl if every line ends with \n and contains exactly one word.
- No final newline (e.g. a b without ending \n): nl stays 0, nw should be 2.
- Only newlines (e.g. \n\n\n): nl 3, nw 0.
- Punctuation / special characters (e.g. hello,world, foo-bar): counted as part of a word since only whitespace splits words.
- Non-ASCII / UTF-8 input (e.g. äöü): nc counts bytes, which can surprise you with multibyte characters.
- Windows line endings (\r\n): \n increments nl, but \r is treated as a normal character and can end up inside “words”.
- Very long input / very long “words”: good for robustness/performance and to catch edge cases.
- Interactive backspace: terminals often handle backspace locally, so \b may never reach the program; can look like “wrong” behavior if you expect it in the input stream.
*/
