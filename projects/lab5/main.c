#include <windows.h>
#include "Replacement.h"
#include "ConfigChecker.h"

int main(int argc, char *args[]) {
    SetConsoleOutputCP(CP_UTF8);

    int checkArgc = argcIsCorrect(argc);
    if (checkArgc != 0)
        return checkArgc;

    char *configFileName = args[1];
    char *findWord = (char *)malloc(0);
    char *changeWord = (char *)malloc(0);
    int sizeFindWord;
    int sizeChangeWord;
    int checkConfig = getFindWordAndChangeWord(configFileName, findWord, changeWord, &sizeFindWord, &sizeChangeWord);
    if (checkConfig != 0)
        return checkConfig;

    char *inputFileName = args[2];
    char *outputFileName = args[3];
    int returnCode = replaceWords(inputFileName, outputFileName, findWord, changeWord, sizeFindWord, sizeChangeWord);

    return returnCode;
}