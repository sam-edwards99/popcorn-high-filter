#include <stdio.h>
#include <stdlib.h>
int highpass(char * x, int * w, int * y){


}
int main() {
        char inputArr[200000];
        int algorithmArr[200000];
        int outputArr[200000];
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
            //w[-1] = 0
            algorithmArr[0] = 0;
            //w[k] = x[k] + 0.5 w[k-1]
            for(int k = 1; k < i; k++) {
                algorithmArr[k] = inputArr[k]+ (0.5 * algorithmArr[k-1]);
            }
            //y[k] = w[k] - w[k-1]
            for(int k = 1; k < i; k++) {
                outputArr[k] = (algorithmArr[k] - algorithmArr[k-1]);
            }
            //print to output file
            for (int j = 1; j < i; j++) {
                fprintf(output," %i\n ", algorithmArr[j]);
                printf(" %i\n ", outputArr[j]);
            }
        }
        return 0;
}