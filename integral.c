#include <stdio.h>
#include <math.h>

float v = 0.0;
float c = 0.0;
float dx = 0.0;

float function(float x) {
  return 1/x ;
}

float rightRiemann(float a, float b, int n) {
    c=0;v=0;
    dx = (float)(b-a)/n;
    for (int k=1; k<=n; k++) {
        c = a+k*dx;
        v += function(c);
    }
    return dx*v;
}

float leftRiemann(float a, float b, int n) {
    c=0;v=0;
    dx = (float)(b-a)/n;
    for (int k=0; k<n; k++) {
        c = a+dx*k;
        v+=function(c);
    }
    return dx*v;
}

float trapezoidal(float a, float b, int n) {
    c=0;v=0;
    dx = (float)(b-a)/n;
    for (int k=0; k<=n; k++) {
        c = (a+k*dx);
        if (k==0 || k==n) {
        v+=(function(c));
        } else {
        v+=2*function(c);
        }
    }
    return 0.5*dx*v;
}

float simpson(float a, float b, int n) {
    if (n % 2 != 0) {n++;}
    c=a;v=0;
    dx = (float)(b - a) / n;
    for (int k = 0; k <= n; k++) {
        if (k == 0 || k == n) {
            v += function(c);
        } else if (k % 2 == 0) {
            v += 2 * function(c);
        } else {
            v += 4 * function(c);
        }
        c += dx;
    }
    return (dx / 3) * v;
}

int main () {
  int a = 1;
  int b = 2;
  int n = 100;
  printf("Right Riemann : %f\n", rightRiemann(a, b,n));
  printf("Left Riemann : %f\n",leftRiemann(a,b,n));
  printf("Trapezoidal : %f\n",trapezoidal(a,b,n));
  printf("Simpson : %f\n", simpson(a,b,n));
  return 0;
}
