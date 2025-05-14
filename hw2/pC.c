#include <stdio.h>
#include <string.h>

int main() {
    char input1[100],input2[100];
    while (1) {
        int a,b,c,d;
        printf("Please enter the name of the file to read from.\n");
        scanf("%s",input1);

        FILE *file=fopen(input1,"r");
        if (strcmp(input1,"exit")==0) {
            break;
        }

        if (file==NULL) { // the file name of input the file doesn't exist.
            printf("the file doesn't exist.\n");
            continue;
        }
        else{
                fscanf(file,"%d %d %d %d",&a,&b,&c,&d);
        }

        printf("Please enter the name of the file to write the output to.\n");
        scanf("%s",input2);


        int denominator,numerator;
        FILE *fptr;
        denominator=a*d+b*c;
        numerator=b*d;
        fptr=fopen(input2,"w");
        fprintf(fptr,"%d/%d\n",denominator,numerator);

        fclose(file);
        fclose(fptr);

        printf("Calculation complete!\n");

    }

    return 0;
}

         
                    