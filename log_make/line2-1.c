#include <stdio.h>
#include <stdlib.h>

#define N 10000

void main(int argc, char *argv[]){
    int count = 0;
    char buffer[N];
    FILE* fp1;
    FILE* fp2;

    fp2 = fopen("two_log.csv","w");
     fprintf(fp2, "timestamp_now1,timestamp_start1,callback1,timestamp_now2,timestamp_start2,callback2\n");

    if((fp1 = fopen(argv[1], "r")) == NULL){
        exit(1);
    }else{
        while ((fgets(buffer, 100, fp1)) != NULL)
        {
            sscanf(buffer, "%s\n", buffer);
            if(count % 2 == 0){
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