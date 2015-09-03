/*
** how to use random
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void
t_open(void)
{
    char *fname = "/tmp/cstream.test";
    FILE *input;
    input = fopen(fname, "w");
    if( input == NULL ){
        perror(fname);
        exit(EXIT_FAILURE);
    }
    fputs("1234 5678 \n", input);
    fputs("1234 5678 ", input);
    fputs("1234 5678 ", input);
    if( fclose(input) != 0 ){
        perror( "fclose" );
        exit(EXIT_FAILURE);
    }
}

void
t_cl(void)
{
    clock_t start = clock();
    t_open();
    clock_t end = clock();
    unsigned long cost = end - start;
    printf("clock is :%lu \n", cost);
    printf("clock_per_sec is :%d \n", CLOCKS_PER_SEC);
    printf("write file cost %f \n", (double)cost/CLOCKS_PER_SEC);
}

void
t_time(void)
{
    //time return seconds
    time_t now = time(NULL);
    time_t end;
    printf("time is :%lu \n", now);
    for(int i=0; i<10000; i++)
        t_open();
    time(&end);
    printf("pn time is :%lu \n", end);
    // return value is double 
    printf("==  result of difftime ===\n");
    printf("   :%f \n", difftime(end, now));
}

void
t_tch(void)
{
    time_t now = time(NULL);
    printf("time is :%lu \n", now);
    char * pt = ctime(&now);
    printf("time is :%s \n", pt);
}

void
t_tm(void)
{
    time_t now = time(NULL);
    printf("time is :%lu \n", now);
    struct tm *sta = gmtime(&now);
    printf("tm_year is :%d \n", sta->tm_year);
    printf("tm_mon is :%d \n", sta->tm_mon);
    printf("tm_mday is :%d \n", sta->tm_mday);
    printf("tm_hour is :%d \n", sta->tm_hour);
    printf("tm_min is :%d \n", sta->tm_min);
    printf("tm_sec is :%d \n", sta->tm_sec);
    printf("=== strftime  ====\n");
    char str[100];
    char * fmt = "weekday: %a, %A";
    strftime( str, 100, fmt, sta);
    printf("%s\n", str);

    fmt = "month: %b, %B";
    strftime( str, 100, fmt, sta);
    printf("%s\n", str);

    fmt = "date: %c";
    strftime( str, 100, fmt, sta);
    printf("%s\n", str);

    fmt = "yday: %J, month: %m mdays: %d, hours: %H---%I";
    strftime( str, 100, fmt, sta);
    printf("%s\n", str);

    fmt = "minters: %M, seconds: %S. \n date: %x";
    strftime( str, 100, fmt, sta);
    printf("%s\n", str);
}

int
main( void )
{
    t_tm();
	return 1;
}
