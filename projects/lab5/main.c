#include <windows.h>
#include "Replacement.h"
#include "tests/test.h"

int main(int argc, char *args[]) {
    // doTests();

    SetConsoleOutputCP(CP_UTF8);

    if (argcIsCorrect(argc) == 1)
        return 1;

    char *configFileName = args[1];
    char *inputFileName = args[2];
    char *outputFileName = args[3];

    return replaceWords(configFileName, inputFileName, outputFileName);
}