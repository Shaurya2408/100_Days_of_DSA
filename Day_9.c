#include <stdio.h>
#include <string.h>
void mirrorCodeName(char* s) {
    int left = 0;
    int right = strlen(s) - 1;
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}
int main() {
    char codeName[100001];
    if (scanf("%s", codeName) == 1) {
        mirrorCodeName(codeName);
        printf("%s\n", codeName);
    }
    return 0;
}