#ifndef LAB_STRING__H
#define LAB_STRING__H

# include <stdint.h>
# include <string.h>

size_t strlen_(char *s);

char* find(char *begin, char *end, int ch);

char* findNonSpace(char *begin);

char* findSpace(char *begin);

char* findNonSpaceReverse(char *rbegin, const char *rend);

char* findSpaceReverse(char *rbegin, const char *rend);

#endif //LAB_STRING__H
