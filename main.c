#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
    char fileLoc[256];
    printf("Input the file name: ");
    fgets(fileLoc, sizeof(fileLoc), stdin);
    fileLoc[strcspn(fileLoc, "\n")] = 0;
    FILE *inputFile; 
    inputFile = fopen(fileLoc, "r");
    if(inputFile == NULL){
        printf("invalid file");
        return -1;
    }
    unsigned char byteLine[16];
    size_t bytes;
    while((bytes = fread(byteLine, 1, 16, inputFile)) > 0){
        long position = ftell(inputFile);
        printf("%08x", position);
        printf("|");
        for(int i = 0; i < 16; i++){
            if(i < 16){
                printf("%02x ", byteLine[i]);
            }else{
                printf(" ");
            }
        }
        printf("|");
        for(int i = 0; i < 16; i++){
            if(isprint(byteLine[i])){
                printf("%c", byteLine[i]);
            }else{
                printf(".");
            }
        }
        printf("\n");
    }
    fclose(inputFile);
    return 0;
}
