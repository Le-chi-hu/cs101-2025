#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    int a[3] = {0, 1, 2};
    int ar[3];
    char b[4] = "ABC";
    char br[4];
    float c[3] = {1.1, 1.2, 1.3};
    float cr[3];
    
    fp = fopen("a.bin", "wb+");
   
 
    fwrite(b, sizeof(char), 4, fp);
    fwrite(a, sizeof(int), 3, fp);
    fwrite(c, sizeof(float), 3, fp);
    

    fseek(fp, 0, SEEK_SET);

    fread(br, sizeof(char), 4, fp);
    fread(ar, sizeof(int), 3, fp);
    fread(cr, sizeof(float), 3, fp);
    
   
    for (int i = 0; i < 3; i++) {
        printf("%d ", ar[i]);  
    }
    printf("\n");

    for (int t = 0; t < 4; t++) {
        printf("%c ", br[t]); 
    }
    printf("\n");

    for (int g = 0; g < 3; g++) {
        printf("%f ", cr[g]);  
    }
    printf("\n");

    fclose(fp);
    return 0;
}

