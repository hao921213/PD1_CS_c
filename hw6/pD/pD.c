#include<stdio.h>
#include "pD.h"
void modify(int (*arr)[20][20] ,int *id,int x,int y,int z,long long int val){
    arr[x][y][z]=val;
    int num=x+y+z;
    *id=num;
}
void exchange(int (*arr1)[20][20],int (*arr2)[20][20]){
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            for(int k=0;k<20;k++){
                int temp=arr1[i][j][k];
                arr1[i][j][k]=arr2[i][j][k];
                arr2[i][j][k]=temp;
            }
        }
    }
}
long long int get_value(int arr[10][20][20][20],int id,int x,int y,int z){
    return arr[id][x][y][z];
}