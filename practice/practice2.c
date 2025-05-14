#include <stdio.h>

int main(){

    float speed;
    scanf("%f",&speed);
    if(0<=speed && speed<=1){
        printf("Calm");
    }
    else if(2<=speed && speed<=5){
        printf("Light air");
    }
    else if(6<=speed && speed<=49){
        printf("Breeze");
    }
    else if(50<=speed && speed<=61){
        printf("High wind");
    }
    else if(62<=speed && speed<=88){
        printf("Gale");
    }
    else if(89<=speed && speed<=117){
        printf("Storm");
    }
    else{
        printf("Hurricane");
    }

}