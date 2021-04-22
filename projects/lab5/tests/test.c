#include <stdlib.h>
#include "../Replacement.h"
#include "../ConfigChecker.h"

int sizeFindWord;
int sizeChangeWord;

int testCorrect1() {
    char *findWord = (char *)malloc(0);
    char *changeWord = (char *)malloc(0);
    char *config_correct_1 = "..\\texts\\correct\\config_correct_1.txt";
    int checkConfig = getFindWordAndChangeWord(config_correct_1, findWord, changeWord, &sizeFindWord, &sizeChangeWord);
    char *input_correct_1 = "..\\texts\\correct\\input_correct_1.txt";
    char *output_correct_1 = "..\\texts\\correct\\results\\output_correct_1.txt";
    int returnCode = replaceWords(input_correct_1, output_correct_1, findWord, changeWord, sizeFindWord, sizeChangeWord);
    return 0;
}
int testCorrect2() {
    char *findWord = (char *)malloc(0);
    char *changeWord = (char *)malloc(0);
    char *config_correct_2 = "..\\texts\\correct\\config_correct_2.txt";
    int checkConfig = getFindWordAndChangeWord(config_correct_2, findWord, changeWord, &sizeFindWord, &sizeChangeWord);
    char *input_correct_2 = "..\\texts\\correct\\input_correct_2.txt";
    char *output_correct_2 = "..\\texts\\correct\\results\\output_correct_2.txt";
    int returnCode = replaceWords(input_correct_2, output_correct_2, findWord, changeWord, sizeFindWord, sizeChangeWord);
    return returnCode;
}
int testCorrect3() {
    char *findWord = (char *)malloc(0);
    char *changeWord = (char *)malloc(0);
    char *config_correct_3 = "..\\texts\\correct\\config_correct_3.txt";
    int checkConfig = getFindWordAndChangeWord(config_correct_3, findWord, changeWord, &sizeFindWord, &sizeChangeWord);
    char *input_correct_3 = "..\\texts\\correct\\input_correct_3.txt";
    char *output_correct_3 = "..\\texts\\correct\\results\\output_correct_3.txt";
    int returnCode = replaceWords(input_correct_3, output_correct_3, findWord, changeWord, sizeFindWord, sizeChangeWord);
    return returnCode;
}


int testIncorrect2() {
    char *findWord = (char *)malloc(0);
    char *changeWord = (char *)malloc(0);
    int returnCode = getFindWordAndChangeWord("..\\texts\\incorrect\\config_incorrect_2.txt", findWord, changeWord, &sizeFindWord, &sizeChangeWord);
    return returnCode;
}
int testIncorrect3() {
    char *findWord = (char *)malloc(0);
    char *changeWord = (char *)malloc(0);
    int returnCode = getFindWordAndChangeWord("..\\texts\\incorrect\\config_incorrect_3.txt", findWord, changeWord, &sizeFindWord, &sizeChangeWord);
    return returnCode;
}
int testIncorrect4() {
    char *findWord = (char *)malloc(0);
    char *changeWord = (char *)malloc(0);
    int returnCode = getFindWordAndChangeWord("..\\texts\\incorrect\\config_incorrect_4.txt", findWord, changeWord, &sizeFindWord, &sizeChangeWord);
    return returnCode;
}
int testIncorrect5() {
    char *findWord = (char *)malloc(0);
    char *changeWord = (char *)malloc(0);
    int returnCode = getFindWordAndChangeWord("..\\texts\\incorrect\\config_incorrect_5.txt", findWord, changeWord, &sizeFindWord, &sizeChangeWord);
    return returnCode;
}
int testIncorrect6() {
    char *findWord = (char *)malloc(0);
    char *changeWord = (char *)malloc(0);
    int returnCode = getFindWordAndChangeWord("..\\texts\\incorrect\\config_incorrect_6.txt", findWord, changeWord, &sizeFindWord, &sizeChangeWord);
    return returnCode;
}
int testIncorrect7() {
    char *findWord = (char *)malloc(0);
    char *changeWord = (char *)malloc(0);
    int returnCode = getFindWordAndChangeWord("..\\texts\\incorrect\\config_incorrect_7.txt", findWord, changeWord, &sizeFindWord, &sizeChangeWord);
    return returnCode;
}
int testIncorrect8() {
    char *findWord = (char *)malloc(0);
    char *changeWord = (char *)malloc(0);
    int returnCode = getFindWordAndChangeWord("..\\texts\\incorrect\\config_incorrect_8.txt", findWord, changeWord, &sizeFindWord, &sizeChangeWord);
    return returnCode;
}
int testIncorrect9() {
    char *findWord = (char *)malloc(0);
    char *changeWord = (char *)malloc(0);
    int returnCode = getFindWordAndChangeWord("..\\texts\\incorrect\\config_incorrect_9.txt", findWord, changeWord, &sizeFindWord, &sizeChangeWord);
    return returnCode;
}
int testIncorrect10() {
    char *findWord = (char *)malloc(0);
    char *changeWord = (char *)malloc(0);
    int returnCode = replaceWords("..\\texts\\correct\\config_correct_1.txt", "", findWord, changeWord, sizeFindWord, sizeChangeWord);
    return returnCode;
}
int testIncorrect11() {
    char *findWord = (char *)malloc(0);
    char *changeWord = (char *)malloc(0);
    int returnCode = replaceWords("..\\texts\\correct\\config_correct_1.txt","", findWord, changeWord, sizeFindWord, sizeChangeWord);
    return returnCode;
}

int testArgc(int argc) { return !argcIsCorrect(argc) ? 0 : 1; }

int doTests() {
    return 0;
}