#include <stdio.h>
#include <stdlib.h>

#define N 10000

void main(int argc, char *argv[]){
    int count = 0;
    char buffer[N];
    FILE* fp1;
    FILE* fp2;

    char *temp,*filename;
    temp = strtok(argv[1], "_.");
    sscanf(filename, "eight_log_%s.csv", temp[1]);

    fp2 = fopen(filename,"w");
    fprintf(fp2, "timestamp_now1,timestamp_start1,callback1,timestamp_now2,timestamp_start2,callback2,timestamp_now3,timestamp_start3,callback3,timestamp_now4,timestamp_start4,callback4,timestamp_now5,timestamp_start5,callback5,timestamp_now6,timestamp_start6,callback6,timestamp_now7,timestamp_start7,callback7,timestamp_now8,timestamp_start8,callback8\n");

    if((fp1 = fopen(argv[1], "r")) == NULL){
        exit(1);
    }else{
        while ((fgets(buffer, 100, fp1)) != NULL)
        {
            sscanf(buffer, "%s\n", buffer);
            if(count % 8 == 0){
                fprintf(fp2, "%s,",buffer);
            }else if(count % 8 == 1){
                fprintf(fp2, "%s,",buffer);
            }else if(count % 8 == 2){
                fprintf(fp2, "%s,",buffer);
            }else if(count % 8 == 3){
                fprintf(fp2, "%s,",buffer);
            }else if(count % 8 == 4){
                fprintf(fp2, "%s,",buffer);
            }else if(count % 8 == 5){
                fprintf(fp2, "%s,",buffer);
            }else if(count % 8 == 6){
                fprintf(fp2, "%s,",buffer);
            }else{
                fprintf(fp2, "%s\n",buffer);
            }
        count++;
            }
        count = 0;
    }
    fclose(fp1);
    fclose(fp2);
}
