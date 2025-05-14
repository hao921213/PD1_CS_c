#include <stdio.h>
int main(){
    union input{
        int integer_type;
        float float_type;
    }a={.integer_type=1024};
    printf("%d\n",a.integer_type); 
    printf("%f\n",a.float_type); 
}