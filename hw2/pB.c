#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]){

        FILE *f;
        f=fopen(argv[1], "r");
        int a,b,c,d;
        fscanf(f,"%d %d %d %d",&a,&b,&c,&d);

        int denominator,numerator;
        denominator=a*d+c*b;
        numerator=b*d;

        FILE *fw;
        fw=fopen("answer.txt","w");
        fprintf(fw,"%d/%d\n",denominator,numerator);

        fclose(f);
        fclose(fw);

        return 0;

}