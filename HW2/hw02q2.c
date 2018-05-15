#include <stdio.h>
#define subm(a,b) (a - b)
#define cubem(a) (a * a * a)
#define minm(a,b) ((a <= b) ? (a) : (b))
#define oddm(a) ((a%2 == 0) ? (0) : (1))
int subf(int a, int b) {
    return (a - b);
}
int cubef(int a) {
    return (a * a * a);
}
int minf( int a, int b) {
    if ( a <= b) {
        return a;
    } else {
        return b;
    }
}
int oddf(int a) {
    if(a % 2 == 0) {
    return 0;
    } else {
    return 1;
    }
}
int main()
{
    int a = 5, b = 7;
    printf("For a = 5 and b = 7:\n");
    printf("%s: %i\n", "subf(a, b)", subf(a, b));
    printf("%s: %i\n", "subm(a, b)",subm(a, b));
    printf("%s: %i\n", "subf(a++, b--)",subf(a++, b--));
    printf("%s: %i\n", "subm(a++, b--)",subm(a++, b--));
    printf("%s: %i\n", "cubef(a)",cubef(a));
    printf("%s: %i\n", "cubem(a)",cubem(a));
    printf("%s: %i\n", "cubef(--a)",cubef(--a));
    printf("%s: %i\n", "cubem(--a)",cubem(--a));
    printf("%s: %i\n", "minf(a, b)", minf(a, b));
    printf("%s: %i\n", "minm(a, b)", minm(a, b));
    printf("%s: %i\n", "minf(--a, --b)", minf(--a, --b));
    printf("%s: %i\n", "minm(--a, --b)",minm(--a, --b));
    printf("%s: %i\n", "oddf(a)",oddf(a));
    printf("%s: %i\n", "oddm(a)",oddm(a));
    printf("%s: %i\n", "oddf(a++)",oddf(a++));
    printf("%s: %i\n", "oddm(a++)",oddm(a++));
 
 
    return 0;
}
