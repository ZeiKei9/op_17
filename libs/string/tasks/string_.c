#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <memory.h>

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
    size_t size = endSource - beginSource + 1;
    memcpy(beginDestination, beginSource, size);

    return beginDestination + size;
}

int checkIfNotNum(int i) {
    return i != '2' && i != '5';
}

char* copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)) {
    for (char *i = beginSource; i < endSource; i += sizeof(char)) {

        if (f(*i)) {
            *beginDestination = *i;
            beginDestination += sizeof(char);
        }
    }

    *beginDestination = '\0';
    return beginDestination;
}

char* copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)) {
    for (char *i = rbeginSource; i > rendSource; i -= sizeof(char)) {

        if (f(*i)) {
            *beginDestination = *i;
            beginDestination += sizeof(char);
        }
    }

    *beginDestination = '\0';
    return beginDestination;
}
//– возвращает указатель на первый пробельный символ справа, расположенный на ленте памяти,
// начиная с rbegin и заканчивая rend. Если символ не найден,
// возвращается адрес rend

char* findSpaceReverse(char *rbegin, const char *rend){

}

int strcmp(const char *lhs, const char *rhs) {

}



char* copy(const char* beginSource, const char* endSource, char* beginDestination) {

}


char* copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)){

}

// Функция, которая определяет, является ли символ буквой
int isLetter(int f){
    return (f >= 'a' && f <= 'z') || (f >= 'A' && f <= 'Z');
}

int isDigit(int f){
    return (f >= '0' && f <= '9');
}

char* copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)){

}

int isVowel(int f){
    return f == 'a' || f == 'e' || f == 'i' || f == 'o' || f == 'u' || f == 'y';
}

int isOddDigits(int f) {
    return f == '1' || f == '3' || f == '5' || f == '7' || f == '9';
}