#include <stdio.h>
#include <stdlib.h>

#define N 10000

void main(int argc, char *argv[]){
    int count = 0;
    char buffer[N];
    FILE* fp1;
    FILE* fp2;

    fp2 = fopen("four_log.csv","w");
    fprintf(fp2, "timestamp1,communicate_time1,timestamp2,communicate_time2,timestamp3,communicate_time3,timestamp4,communicate_time4\n");

    if((fp1 = fopen(argv[1], "r")) == NULL){
        exit(1);
    }else{
        while ((fgets(buffer, 100, fp1)) != NULL)
        {
            sscanf(buffer, "%s\n", buffer);
            if(count % 4 == 0){
                fprintf(fp2, "%s,",buffer);
            }else if(count % 4 == 1){
                fprintf(fp2, "%s,",buffer);
            }else if(count % 4 == 2){
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