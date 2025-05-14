#include <stdio.h>
int n1;
int n2;
int m[2000][2000]={};
int row_max[2000];
int col_max[2000];
int find_colmax(int m[2000][2000]);
int find_rowmax(int m[2000][2000]);

int main(){
    scanf("%d %d",&n1,&n2);
    long long int count=0;
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            scanf("%d",&m[i][j]);
        }
    }
    find_colmax(m);
    find_rowmax(m);
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(col_max[j]!=m[i][j] && row_max[i]!=m[i][j]){
                int min=col_max[j]<=row_max[i]?col_max[j]:row_max[i];
                count+=min-m[i][j];
                m[i][j]=min;
            }
        }
    }
    printf("%lld\n",count);
}
int find_rowmax(int m[2000][2000]){
    for(int i=0;i<n1;i++){
        int row=0;
        for(int j=0;j<n2;j++){
            row=m[i][j]>row?m[i][j]:row;
        }
        row_max[i]=row;
    }
}
int find_colmax(int m[2000][2000]){
    for(int i=0;i<n2;i++){
        int col=0;
        for(int j=0;j<n1;j++){
            col=m[j][i]>col?m[j][i]:col;
        }
        col_max[i]=col;
    }
}