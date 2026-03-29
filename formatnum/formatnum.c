#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int ordMag(long double n) {
    if (n<0) n=-n;
    if (n != 0) return floorl(log10l(n));
    return 0;
}
char *formatNum(long double n, char mode) {
    char *buf = malloc(64);
    char split = mode; //Fallback if mode is something else.
    if (mode=='E') { //Engineering notation
        int oom = floorl((long double) ordMag(n) / 3)*3;
        long double coeff = n / powl(10.0L,oom);
        snprintf(buf, 64, "%Lf%c%i", coeff, 'E', oom);
    } else if (mode=='S') { //Scientific notation
        int oom = ordMag(n);
        long double coeff = n / powl(10.0L,oom);
        snprintf(buf, 64, "%Lf%c%i", coeff, 'E', oom);
    } else { // Fallback
        int oom = ordMag(n);
        long double coeff = n / powl(10.0L,oom);
        snprintf(buf, 64, "%Lf%c%i", coeff, split, oom);
    }
    return buf;
}
int main(int argc, char *argv[]) {
    char *end = NULL;
    if (argc > 2) {
        char *mode = argv[1];
        for (int i=2;i<argc;i++) {
            long double num = strtold(argv[i],&end);
            char *out = formatNum(num, *mode);
            printf("%.2Lf = %s\n",num,out);
            free(out);
        }
    } else {
        printf("Error: Not enough paramers given. \n     Usage of command is as follows:\n     snt-formatnum [E|S|other splitter] [numbers separated by spaces]\n");
    }
}