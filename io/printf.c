/*
** do printf
*/

#include <stdio.h>

void
t_str(void)
{
    printf("** width 5 ** \n");
    printf("%5s \n", "AB");
    printf("%5s \n", "ABCDEFGH");
    printf("** precision 5  **\n");
    printf("%.5s \n", "AB");
    printf("%.5s \n", "ABCDEFGH");
    printf("** width 5, precision 5 ** \n");
    printf("%5.5s \n", "AB");
    printf("%5.5s \n", "ABCDEFGH");
    printf("** left align with width 5 ** \n");
    printf("%-5s \n", "AB");
    printf("%-5s \n", "ABCDEFGH");
    printf("** left align with width 5 and prcision 5 ** \n");
    printf("%-5.5s %-5.5s %-5.5s \n", "AB", "12", "abcdef");
    printf("%-5.5s %-5.5s %-5.5s \n", "ABCDEFG  ", "1234567", "abcdef");
}

void
t_n(void)
{
    printf("** width 5 ** \n");
    printf("%5d %5d \n", -77, 88);
    printf("%5d %5d \n", 77777777, 8888888);
    printf("** width 5 with 0+ pre ** \n");
    printf("%+05d %+05d \n", -77, 88);
    printf("%+05d %+05d \n", 77777777, 8888888);
    printf("** left align with width 5 ** \n");
    printf("%-5d %-5d \n", -77, 88);
    printf("%-5d %-5d \n", 77777777, 8888888);
    printf("** left align with width 5 and prcision 5 ** \n");
    printf("%-5.5d %-5.5d \n", -77, 88);
    printf("%-5.5d %-5.5d \n", 77777777, 8888888);
    printf("** width 5 and prcision 5 ** \n");
    printf("%5.5d %5.5d \n", -77, 88);
    printf("%5.5d %5.5d \n", 77777777, 8888888);
}

void
t_x(void)
{
    printf("** no width and width 5 ** \n");
    printf("%2$-55o %1$#x \n", 77, 7777);
    printf("%5o %-5x \n", 77, 77);
    printf("%#o %#x \n", 77777777, 8888888);
    printf("%#015o %#015x \n", 77777777, 8888888);
    printf("%''d %#015x \n", 77777777, 8888888);
}

void
t_f(void)
{
    printf("** width 5 ** \n");
    printf("%10.2f %f \n", -77., 88.);
    printf("%10.5f %f \n", 77777777., 8888888.);
    printf("%.2e %.2g \n", 7000000., 8888888.);
}

int
main( void )
{
    t_f();
	return 1;
}
