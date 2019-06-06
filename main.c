#include <stdio.h>
#include <stdlib.h>

int main()
{
    int goatsNumber;
    int maxCoursesNumber;
    int wrongInputFlag=1;
    while(wrongInputFlag)
    {
    printf("\nEnter the number of goats and max number of courses\n");
    scanf("\n%d %d",&goatsNumber,&maxCoursesNumber);

    if((goatsNumber>1000||goatsNumber<1)||(maxCoursesNumber>1000||maxCoursesNumber<1))
    {
        printf("Please enter valid numbers for goats and courses (Between 1 and 1000)");
    }
    else{
        wrongInputFlag=0;
    }
    }

    int goatsWeight[goatsNumber];
    int newGoatsWeight[goatsNumber];
    int sum=0;
    for(int i=0;i<goatsNumber;i++){
        printf("\nEnter the weight of goat ¹ %d\n",i+1);
        scanf("\n%d",&goatsWeight[i]);
        if((goatsWeight[i]>1000000||goatsWeight[i]<1))
        {
        printf("Please enter valid number for the weight of goat (Between 1 and 1000000)");
        i--;
        continue;
        }
        sum+=goatsWeight[i];
    }
    int repeatedKgsIndexes[goatsNumber];
    for(int p=0;p<goatsNumber;p++){
        repeatedKgsIndexes[p]=-1;
    }
    int maxNumber=0;
    int flagFinal=0;
    int prevMax=sum;
    int prevInd=-1;
    int currInd=-1;
    for(int n=0;n<goatsNumber;n++)
    {
        maxNumber=0;
        flagFinal=0;
        for(int o=0;o<goatsNumber;o++){
            flagFinal=0;
             if(maxNumber<goatsWeight[o]&&prevMax>=goatsWeight[o]&&prevInd!=o){
                for(int p=0;p<goatsNumber;p++){
                    if(repeatedKgsIndexes[p]==o){

                        flagFinal++;
                    }
                }
                if(flagFinal==0){
                    maxNumber=goatsWeight[o];
                    currInd=o;
                    if(maxNumber==prevMax){
                        repeatedKgsIndexes[prevInd]=prevInd;
                        repeatedKgsIndexes[currInd]=currInd;
                    }
                }
            }
        }
        prevMax=maxNumber;
        prevInd=currInd;
        newGoatsWeight[n]=maxNumber;
    }

    int answer=sum/maxCoursesNumber-1;
    int neededCapacity=0;
    int currCapacity=0;
    int finalCapacity=0;
    int flag=1;
    int flag2=0;

    while(flag){
        for(int i=0;i<goatsNumber;i++){
        goatsWeight[i]=newGoatsWeight[i];
        }
        neededCapacity=0;
        currCapacity=0;
        for(int m=0;m<maxCoursesNumber;m++){
            int curr=answer;
            while(1)
            {
                int currMax=0;
                int currMin=sum;
                for(int l=0;l<goatsNumber;l++){
                    if(currMax<goatsWeight[l]&&curr>=goatsWeight[l]){
                        currMax=goatsWeight[l];
                        goatsWeight[l]=0;
                    }
                    if(currMin>goatsWeight[l]&&goatsWeight[l]!=0){
                        currMin=goatsWeight[l];
                    }
                }
                curr-=currMax;
                currCapacity+=currMax;
                if(curr<currMin){
                    break;
                }
            }
            if(sum==currCapacity+neededCapacity)
                {
                    flag2=1;
                }
                neededCapacity+=currCapacity;
                if(finalCapacity<currCapacity)
                {
                finalCapacity=currCapacity;
                }
            currCapacity=0;
        }
        if(flag2){
        flag=0;
        }
        answer++;
   }
   printf("The minimal capacity of the raft is: %d",finalCapacity);
    return 0;
}

