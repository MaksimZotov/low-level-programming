#include "../Replacement.h"

void testCorrect1() {
    char *config_correct_1 = "..\\texts\\correct\\config_correct_1.txt";
    char *input_correct_1 = "..\\texts\\correct\\input_correct_1.txt";
    char *output_correct_1 = "..\\texts\\correct\\results\\output_correct_1.txt";
    replaceWords(config_correct_1, input_correct_1, output_correct_1);
}
void testCorrect2() {
    char *config_correct_2 = "..\\texts\\correct\\config_correct_2.txt";
    char *input_correct_2 = "..\\texts\\correct\\input_correct_2.txt";
    char *output_correct_2 = "..\\texts\\correct\\results\\output_correct_2.txt";
    replaceWords(config_correct_2, input_correct_2, output_correct_2);
}
void testCorrect3() {
    char *config_correct_3 = "..\\texts\\correct\\config_correct_3.txt";
    char *input_correct_3 = "..\\texts\\correct\\input_correct_3.txt";
    char *output_correct_3 = "..\\texts\\correct\\results\\output_correct_3.txt";
    replaceWords(config_correct_3, input_correct_3, output_correct_3);
}


void testIncorrect2() { replaceWords("", "", ""); }

void testIncorrect3() { replaceWords("..\\texts\\incorrect\\config_incorrect_3.txt", "", ""); }
void testIncorrect4() { replaceWords("..\\texts\\incorrect\\config_incorrect_4.txt", "", ""); }
void testIncorrect5() { replaceWords("..\\texts\\incorrect\\config_incorrect_5.txt", "", ""); }
void testIncorrect6() { replaceWords("..\\texts\\incorrect\\config_incorrect_6.txt", "", ""); }
void testIncorrect7() { replaceWords("..\\texts\\incorrect\\config_incorrect_7.txt", "", ""); }
void testIncorrect8() { replaceWords("..\\texts\\incorrect\\config_incorrect_8.txt", "", ""); }
void testIncorrect9() { replaceWords("..\\texts\\incorrect\\config_incorrect_9.txt", "", ""); }

void testIncorrect10() { replaceWords("..\\texts\\correct\\config_correct_1.txt", "", ""); }
void testIncorrect11() { replaceWords("..\\texts\\correct\\config_correct_1.txt","..\\texts\\correct\\input_correct_1.txt",""); }


void testArgc(int argc) { argcIsCorrect(argc); }

void doTests() {
    // Здесь можно выбрать любую из выше написанных функций для проверки
}


