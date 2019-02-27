#include <stdio.h>
#include <stdlib.h>

typedef struct stu{
    int num;
    int score;
}stu;
//划分
int partition(stu s[],int low,int high){
    stu pivot = s[low];
    while(low < high){
        while(low < high && s[high].score >= pivot.score)
            --high;
        s[low] = s[high];
        while(low < high && s[low].score <= pivot.score)
            ++low;
        s[high] = s[low];
    }
    s[low] = pivot;
    return low;
}
//快速排序
void QuickSort(stu s[],int low,int high){
    if(low < high){
        int pivotpos = partition(s,low,high);
        QuickSort(s,low,pivotpos - 1);
        QuickSort(s,pivotpos + 1,high);
    }
}

int main()
{
    int i,n;
    printf("请输入学生人数 学号 成绩：\n");
    while(scanf("%d",&n) != EOF){
        if(n < 1 || n>100) break;
        stu s[n];
        for(i = 0;i < n;i++){
            scanf("%d %d",&s[i].num,&s[i].score);
        }
        QuickSort(s,0,n - 1);
        printf("成绩由低到高排序\n");
        printf("result:\n");
        for(i = 0;i < n;i++){
            printf("%d %d\n",s[i].num,s[i].score);
        }
    }
    return 0;
}
