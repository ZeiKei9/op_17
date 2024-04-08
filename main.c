#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "libs/data_structures/vector/vector.h"
#include "libs/string/tasks/string_.h"

size_t test_strlen_() {
    char *s = "abcdefg";

    size_t res = strlen_(s);
    assert(res == 7);
}

char* test_find() {
    char *s = "Hello";

    char *res = find(&s[0], &s[3], 'e');
    assert(*res == 'e');
}

char* test_findNonSpace() {
    char *s = "   d  ";

    char *res = findNonSpace(s);
    assert(*res == 'd');
}

char* test_findSpace() {
    char *s = "rew hj";

    char *res = findSpace(s);
    assert(*res == ' ');
}

char* test_findNonSpaceReverse() {
    char *s = "test test ";

    char *res = findNonSpaceReverse(s + sizeof(char) * 9, s);
    assert(*res == 't');
}

char* test_findSpaceReverse() {
    char *s = "ab de";

    char *res = findSpaceReverse(s + sizeof(char) * 5, s);
    assert(*res == ' ');
}

int test_strcmp_() {
    char *lhs1 = "ABCD";
    char *rhs1 = "EFGH";
    int res1 = strcmp_(lhs1, rhs1);
    assert(res1 < 0);

    char *lhs2 = "ABCD";
    char *rhs2 = "ABCD";
    int res2 = strcmp_(lhs2, rhs2);
    assert(res2 == 0);

    char *lhs3 = "ZXCV";
    char *rhs3 = "BHFR";
    int res3 = strcmp_(lhs3, rhs3);
    assert(res3 > 0);
}

char* test_copy() {
    char *s = "12345333333333333333";
    char sd[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1};

    char *res = copy(s, s + sizeof(char) * 4, sd);
    assert(*res == 1);
}

char* test_copyIf() {
    char *s = "123456";
    char sd[20] = {1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,};

    char *res = copyIf(s, s + sizeof(char) * 5, sd, &checkIfNotNum);
    assert(res[0] == 0 && res[1] == 1);
}

char* test_copyIfReverse() {
    char *s = "123456";
    char sd[20] = {1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,};

    char *res = copyIfReverse(s + sizeof(char) * 5, s, sd, &checkIfNotNum);
    assert(res[0] == 0 && res[1] == 1);
}


//4 номер
//тест без пробелов
void test_without_spaces(){
    char input[] = "HelloWorld";
    char *result = findNonSpaceReverse( input + strlen(input) - 1, input);
    if (result != input){
        printf("Passed\n");
    }else{
        printf("Failed\n");
    }

}

//тестирование на пустой строке
void test_empty_line(){
    char input[] = "";
    char *result = findNonSpaceReverse(input + strlen(input) - 1, input);
    if (result == input){
        printf("passed\n");
    }else{
        printf("failed\n");
    }
}








//номер 5

void tests_without_spaces(){
    char input[] = "HelloWorld";
    char *result = findSpaceReverse(input + strlen(input) - 1, input);
    if (result == input){
        printf("Passed\n");
    }else{
        printf("failed\n");
    }

}

// Тестирование на пустой строке
void tests_empty_line(){
    char input[] = "";
    char *result = findSpaceReverse(input + strlen(input) - 1, input);
    if (result != input){
        printf("Passed\n");

    }else{
        printf("Failed\n");
    }

}






//номер 6
//тест на разные строки
void test_not_eqial_string(){
    const char *str1 = "fhusgfus";
    const char *str2 = "tfvcydnkj";

    int result = strcmp(str1, str2);

    if (result != 0){
        printf("Failed");
    }else{
        printf("passed");
    }

}

void test_are_eqial_string(){
    const char *str1 = "hello";
    const char *str2 = "hello";

    int result = strcmp(str1, str2);

    if (result == 0) {
        printf("passed\n");
    } else {
        printf("failed\n");
    }
}









//номер 7
//Тест с пустыми исходными строками
void test_empty_string(){
    char source[] = "";
    char destination[10] = "12345";
    char* newDestination = copy(source, source, destination);
    printf("Result: %s\n", destination);

}
//Тест с непустыми исходными строками
void test_with_no_empty__string(){
    char source[] = "Hello, World!";
    char* endSource = source +6;
    char destination[20] = "";
    char* newDestination = copy(source, endSource, destination);
    printf("Result: %s\n", destination);
}



//Номер 8
//  Копирование только букв
void test_only_the_letters(){
    char source[] = "Hello,??world!";
    char destination[40];

    char *result = copyIf(source, source + 15, destination, isLetter);
    *result = '\0'; // Добавляем ноль-символ для корректного вывода строки
    printf("%s\n", destination);
}


void test_only_the_digits(){
    char source[] = "Hello,123world!123";
    char destination[40];

    char *result = copyIf(source, source + 19, destination, isDigit);
    *result = '\0'; // Добавляем ноль-символ для корректного вывода строки
    printf("%s\n", destination);
}



//номер 9
void test_only_is_vowel_letters(){
    char destination[10];
    char source1[] = "hello";
    char *endDestination1 = copyIfReverse(&source1[4], &source1[0], destination, isVowel);
    *endDestination1 = '\0';
    if (strcmp(destination, "oe") == 0) {
        printf(" Passed\n");
    } else {
        printf(" Failed\n");
    }
}
void test_only_is_odd_numbers(){
    char destination[10];
    char source2[] = "1234567";
    char *endDestination2 = copyIfReverse(&source2[6], &source2[0], destination, isOddDigits);
    *endDestination2 = '\0'; // Add null terminator
    if (strcmp(destination, "7531") == 0) {
        printf("Passed\n");
    } else {
        printf("Failed\n");
    }
}




void test() {
    test_strlen_();
    test_find();
    test_findNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
    test_strcmp_();
    test_copy();
    test_copyIf();
    test_copyIfReverse();
    test_without_spaces();
    test_empty_line();
    tests_without_spaces();
    tests_empty_line();
    test_empty_string();
    test_with_no_empty__string();
    test_only_the_letters();
    test_only_the_digits();
    test_only_is_vowel_letters();
    test_only_is_odd_numbers();


}

int main() {
    test();

    return 0;
}