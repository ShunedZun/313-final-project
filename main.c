#include <stdio.h>
#include <string.h>
#include <ctype.h>

//main function to execute code
int main(){

    //variable to hold user input for file
    char fileLoc[256];

    //prompt message
    printf("Input the file name: ");

    //convert the file input into a readable filename format
    fgets(fileLoc, sizeof(fileLoc), stdin);
    fileLoc[strcspn(fileLoc, "\n")] = 0;

    //find and open the file
    FILE *inputFile; 
    inputFile = fopen(fileLoc, "r");

    //ensure the file exists and correctly obtained
    if(inputFile == NULL){
        printf("invalid file");
        return -1;
    }

    //the character output holder for output
    unsigned char byteLine[16];

    //number of bytes retrieved
    size_t bytes;

    //iterate through it until there are no more bytes remaining
    while((bytes = fread(byteLine, 1, 16, inputFile)) > 0){

        //long of the current address in the file
        long position = ftell(inputFile);

        //output the address
        printf("%08x", position);
        printf("|");

        //retrieves 16 bytes and prints each out in its hex value
        for(int i = 0; i < 16; i++){
            if(i < 16){
                printf("%02x ", byteLine[i]);
            }else{
                printf(" ");
            }
        }
        printf("|");

        //retrieves the 16 again but this time outputs the ascii values if printable as ascii
        for(int i = 0; i < 16; i++){
            if(isprint(byteLine[i])){
                printf("%c", byteLine[i]);
            }else{
                printf(".");
            }
        }

        //start a new line
        printf("\n");
    }

    //close the input file
    fclose(inputFile);
    return 0;
}
