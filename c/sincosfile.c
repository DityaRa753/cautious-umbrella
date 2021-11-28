#include<stdio.h>
#include<math.h>

int main()
{
    FILE *f;
    int grad;

    f = fopen("sincos.txt", "w");
    if(!f) {
        perror("sincos.txt");
        return 1;
    }
    fprintf(f, "%3s %6.3s %8.3s\n", "rad", "sin", "cos");
    for(grad = 0; grad <= 360; grad++){
        double rads = (double)grad * M_PI / 180.0;
        double s, c;
        s = sin(rads);
        c = cos(rads);
        fprintf(f, "%03d % 7.5f % 7.5f\n", grad, s, c);
    }
    fclose(f);
    return 0;
}
