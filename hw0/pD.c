#include <stdio.h>
#include <math.h>
int a_nums[100];
int b_nums[100];
int main(){
    int n=0;
    int ans1=0;
    int ans2=1;
    int ans3=1;
    float ans=0.0;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&a_nums[i]);
    }

    for(int i=0;i<n;i++){
        scanf("%d",&b_nums[i]);
    }

    for(int i=0;i<n;i++){
        ans1+=(a_nums[i]*b_nums[i]);
        ans2+=a_nums[i]*a_nums[i];
        ans3+=b_nums[i]*b_nums[i];
    }
    printf("%.2f",(float)(ans1/(pow(ans2,0.5) * pow(ans3,0.5))));
}