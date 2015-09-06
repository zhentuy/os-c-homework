/*
** how to use setjmp
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void
t_env(void)
{
    char * keyl = "LANG";
    char * lang = getenv(keyl);
    printf("get env %s value is %s \n", keyl, lang);
    char * keyh = "HOME";
    lang = getenv(keyh);
    printf("get env %s value is %s \n", keyh, lang);
}

void
t_sys(void)
{
    system("ls -al ~");
}

void
t_locate(void)
{
    char * locate_all = setlocale(LC_ALL, NULL);
    printf("locate all is \n: %s \n", locate_all);
    locate_all = setlocale(LC_TIME, NULL);
    printf("locate time is \n: %s \n", locate_all);
    locate_all = setlocale(LC_CTYPE, NULL);
    printf("locate ctype is \n: %s \n", locate_all);
}

int
main( void )
{
    t_locate();
	return 1;
}
