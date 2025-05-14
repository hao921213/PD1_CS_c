#include <stdio.h>
int nums[200001]={0};
int n=0;
void init(){
    for(int i=0;i<n;i++){
        nums[i]=i+1;
    }
    return;
}
void find_index(int p){
    printf("%d\n",nums[p-1]);
    return;
}
int find_n(int num){
    for(int i=0;i<n;i++){
        if(nums[i]==num){
            return i;
        }
    }
    return -1;
}
void change(int n1,int n2){
    int p1=find_n(n1);
    int p2=find_n(n2);
    int temp=n1;
    if(p1>p2){
        for(int i=p1;i>p2;i--){
            nums[i]=nums[i-1];
        }
        nums[p2]=temp;
    }
    else{
        for(int i=p1;i<p2-1;i++){
            nums[i]=nums[i+1];
        }
        nums[p2-1]=temp;
    }
    return;
}
int main(){
    int choose=0;
    int end=0;
    scanf("%d",&n);
    init(n);
    while(1){
        scanf("%d",&choose);
        switch(choose){
            case 1:
                int a=0;
                int b=0;
                scanf("%d %d",&a,&b);
                change(a,b);
                break;
            case 2:
                int p=0;
                scanf("%d",&p);
                find_index(p);
                break;
            case 3:
                end=1;
                break;
        }
        if(end==1){
            break;
        }
    }
}