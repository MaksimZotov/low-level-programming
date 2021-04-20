#include <windows.h>
#include "Replacement.h"
#include "tests/test.h"

int main(int argc, char *args[]) {
    SetConsoleOutputCP(CP_UTF8);

    //doTests();

    if (argcIsCorrect(argc) == 1)
        return 1;

    char *configFileName = args[1];
    char *inputFileName = args[2];
    char *outputFileName = args[3];

    return replaceWords(configFileName, inputFileName, outputFileName);
}