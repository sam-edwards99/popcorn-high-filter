#include <stdio.h>
int highpass(int k){


}
int main() {
        char inputArr[200000];
        int outputArr[200000];
        FILE *input, *output;
        input = fopen("popcorn-audio2.dat", "r");
        output = fopen("cleaned-audio.dat", "w");
        int i=0;
        if(input != NULL) {
            while (fscanf(input, "%s\n", &inputArr[i]) != EOF) {
                fprintf(output,"%s,", &inputArr[i]);
                i++;
            }
            //  for (int j = 0; j < i; j++) {
            //       printf(" %i\n ", pageArr[j]);
            //   }
        }
        return 0;
}