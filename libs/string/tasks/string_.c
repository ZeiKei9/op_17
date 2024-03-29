#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

size_t strlen_(const char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;
    return end - begin;
}

char* find(char *begin, char *end, int ch) {
    for (char *ptr = begin; ptr < end; ptr = ptr + sizeof(char)) {
        if (*ptr == ch) {
            return ptr;
        }
    }
    return end;
}

char* findNonSpace(char *begin) {
    char *ptr = begin;

    while (*ptr != '\0') {
        int res = 0;
        res = isspace(*ptr);
        if (!res) {
            return ptr;
        }

        ptr += sizeof(char);
    }
    return ptr;
}

char* findSpace(char *begin) {
    char *ptr = begin;

    while (*ptr != '\0') {
        int res = 0;
        res = isspace(*ptr);
        if (res) {
            return ptr;
        }

        ptr += sizeof(char);
    }
    return ptr;
}

char* findNonSpaceReverse(char *rbegin, const char *rend) {
    char *ptr = rbegin;
    bool found = false;

    while (ptr != rend) {
        int res = isspace(*ptr);

        if (!res) {
            found = true;
        } else {
            if (found) {
                return ptr + sizeof(char);
            }
        }

        ptr -= sizeof(char);
    }
    return rend;
}


//
char* findSpaceReverse(char *rbegin, const char *rend) {
    char *ptr = rbegin;
    bool found = false;

    while (ptr != rend) {
        int res = isspace(*ptr);

        if (!res) {
            found = true;
        } else {
            if (found) {
                return ptr;
            }
        }

        ptr -= sizeof(char);
    }
    return rend;
}

int strcmp_(const char *lhs, const char *rhs) {
    while (*lhs == *rhs++)
        if (*lhs++ == 0) return (0);
    return (*(unsigned char *) lhs - *(unsigned char *) --rhs);
}

char* copy(const char *beginSource, const char *endSource, char *beginDestination) {
    for (char *i = beginSource; i <= endSource; i += sizeof(char)) {
        *beginDestination = *i;
        beginDestination += sizeof(char);
    }

    *beginDestination = '\0';
    return beginDestination;
}