#include <stdio.h>
#include <stdlib.h>
int highpass(int len, int *x, FILE * output){
    int w[len];
    int y[len];
    w[0] = 0;
    y[0] = 0;
    for(int k = 1; k < len; k++) {
       w[k] = x[k]+ (0.5 * w[k-1]);
    }
    for(int k = 1; k < len; k++) {
        y[k] = (w[k] - w[k-1]);
    }
    //print to output file
    for (int k = 1; k < len; k++) {
        fprintf(output," %i\n ", y[k]);
    }
}
int main() {
        int inputArr[200000];
        FILE *input, *output;
        input = fopen("popcorn-audio2.dat", "r");
        output = fopen("cleaned-audio2.dat", "w");
        char numstring[4];
        int i=1;
        if(input != NULL) {
            //x[-1] = 0
            inputArr[0] = 0;
            while (fscanf(input, "%s\n", &numstring) != EOF) {
                inputArr[i] = atoi(numstring);
                i++;
            }
            highpass(i,inputArr,output);
        }
        return 0;
}