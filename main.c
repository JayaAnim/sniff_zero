#include <stdio.h>
#include <sys/resource.h>

void printMemoryUsage() 
{
    struct rusage usage;
    if (0 == getrusage(RUSAGE_SELF, &usage)) {
        printf("Memory Usage: %ld bytes\n", usage.ru_maxrss);
    } else {
        printf("Error getting memory usage.\n");
    }
}

int main() {
    char answer;
    printMemoryUsage();
    printf("Do you want to continue capturing more packets? (y/n): ");
    scanf(" %c", &answer);
}
