#include <stdio.h>
#include<math.h>
int main(){
    float height,weight;
    scanf("%f %f",&height,&weight);
    height/=100;
    printf("BMI:%.2f", round(weight/height/height*100)/100);
    
}