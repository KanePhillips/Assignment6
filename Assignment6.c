#include <stdio.h>

int main(){

    float inputFloat = 0.0;
    int binaryArray[32];
    int floatAsInt;
    int i = 0;
    float floatDecimal = 0.0;

        printf("This program will convert a decimal to a binary number.");
        printf("Please enter a decimal value to be converted to a 32-bit binary value: ");
        scanf("%f", &inputFloat);

        floatAsInt = (int)inputFloat;

        //Determine signed bit
        if (inputFloat >= 0){
            binaryArray[0] = 0;
        }
        else{
            binaryArray[0] = 1;
        }

        //Determine next 8 bits
        i = 0;
        while (floatAsInt != 0){
            if ((floatAsInt % 2) == 1){
                binaryArray[8-i] = 1;
            }
            else if ((floatAsInt % 2) == 0){
                binaryArray[8-i] = 0;
            }
            floatAsInt /= 2;
            i++;


        }

        //Fills in any remaining bits of the group of 8 with 0's if they weren't already changed
        if (i < 8){
            for (i; i < 8; i++){
                binaryArray[8-i] = 0;
            }
        }

        floatDecimal = inputFloat - (int)inputFloat;

        //Determine remaining bits
        //SHOULD LOOK LIKE: x*2, if x>1, array[index]=1 and x-1, else array[index]=0, repeat
        for (int k = 9; k < 32; k++){
            floatDecimal *= 2.0;
            if (floatDecimal >= 1){
                binaryArray[k] = 1;
                floatDecimal -= 1.0;
            }
            else if (floatDecimal < 1){
                binaryArray[k] = 0;
            }
            if (k>13){
                //Checks if bits are looping and finishes loop if they are
                if (binaryArray[k] == binaryArray[k-4] && binaryArray[k-1] == binaryArray[k-5] && binaryArray[k-2] == binaryArray[k-6] && binaryArray[k-3] == binaryArray[k-7]){
                    int first = binaryArray[k-3];
                    int second = binaryArray[k-2];
                    int third = binaryArray[k-1];
                    int fourth = binaryArray[k];


                    for (k; k<32; k+=4){
                        binaryArray[k] = first;
                        binaryArray[k+1] = second;
                        binaryArray[k+2] = third;
                        binaryArray[k+3] = fourth;
                    }
                }
            }
        }

        //Print out binary conversion
        printf("The binary conversion is: \n");
        for (int m = 0; m < 32; m++){
            printf("%d", binaryArray[m]);
            if ((m+1) % 4 == 0){
                printf(" ");
            }
            if ((m+1) % 8 == 0){
                printf("\n");
            }
        }


}
    
