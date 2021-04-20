#include "../Replacement.h"

int testCorrect1() {
    char *config_correct_1 = "..\\texts\\correct\\config_correct_1.txt";
    char *input_correct_1 = "..\\texts\\correct\\input_correct_1.txt";
    char *output_correct_1 = "..\\texts\\correct\\results\\output_correct_1.txt";
    return replaceWords(config_correct_1, input_correct_1, output_correct_1);
}
int testCorrect2() {
    char *config_correct_2 = "..\\texts\\correct\\config_correct_2.txt";
    char *input_correct_2 = "..\\texts\\correct\\input_correct_2.txt";
    char *output_correct_2 = "..\\texts\\correct\\results\\output_correct_2.txt";
    return replaceWords(config_correct_2, input_correct_2, output_correct_2);
}
int testCorrect3() {
    char *config_correct_3 = "..\\texts\\correct\\config_correct_3.txt";
    char *input_correct_3 = "..\\texts\\correct\\input_correct_3.txt";
    char *output_correct_3 = "..\\texts\\correct\\results\\output_correct_3.txt";
    return replaceWords(config_correct_3, input_correct_3, output_correct_3);
}


int testIncorrect2() { return replaceWords("", "", ""); }

int testIncorrect3() { return replaceWords("..\\texts\\incorrect\\config_incorrect_3.txt", "", ""); }
int testIncorrect4() { return replaceWords("..\\texts\\incorrect\\config_incorrect_4.txt", "", ""); }
int testIncorrect5() { return replaceWords("..\\texts\\incorrect\\config_incorrect_5.txt", "", ""); }
int testIncorrect6() { return replaceWords("..\\texts\\incorrect\\config_incorrect_6.txt", "", ""); }
int testIncorrect7() { return replaceWords("..\\texts\\incorrect\\config_incorrect_7.txt", "", ""); }
int testIncorrect8() { return replaceWords("..\\texts\\incorrect\\config_incorrect_8.txt", "", ""); }
int testIncorrect9() { return replaceWords("..\\texts\\incorrect\\config_incorrect_9.txt", "", ""); }

int testIncorrect10() { return replaceWords("..\\texts\\correct\\config_correct_1.txt", "", ""); }
int testIncorrect11() { return replaceWords("..\\texts\\correct\\config_correct_1.txt","..\\texts\\correct\\input_correct_1.txt",""); }


int testArgc(int argc) { return !argcIsCorrect(argc) ? 0 : 1; }

int doTests() {
    // return test();
}


