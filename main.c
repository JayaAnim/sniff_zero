#include <stdio.h>


int main() {
    char answer;
    printMemoryUsage();
    printf("Do you want to continue capturing more packets? (y/n): ");
    scanf(" %c", &answer);
}
