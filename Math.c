#include <stdio.h>
#include <math.h>

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	double delta=1e-12;
    double a, b;
    //inputs and converting degrees into rads
    printf("please input a in degrees: ");
    if (scanf("%lf", &a) != 1) return 1;
    a=a/57.2958;
    printf("please input b in degrees: ");
    if (scanf("%lf", &b) != 1) return 1;
    b=b/57.2958;
    //calculation formula z1 and z2
    double z1 = (cos(a) - cos(b))*(cos(a) - cos(b)) - (sin(a) - sin(b))*(sin(a) - sin(b));
    double z2 = -4*(sin((a-b)/2))*(sin((a-b)/2))*cos(a+b);
    //filter float error -0 and etc
    if (z1<delta && z1>-delta){
    	z1=0.0;
    }
    if (z2<delta && z2>-delta){
    	z2=0.0;
    }
    //output
    printf("z1 = %.10f\n", z1);
    printf("z2 = %.10f\n", z2);
    return 0;
}
