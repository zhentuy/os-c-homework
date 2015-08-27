/*
** do file
*/

#include <stdio.h>
#include <stdlib.h>
#define LINE_LENGTH 1024

void
t_open(void)
{
    char *fname = "/tmp/cstream.test";
    printf("** open file  %s ** \n", fname);
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
t_read(void)
{
    t_open();
    char *fname = "/tmp/cstream.test";
    FILE *input;
    char buffer[LINE_LENGTH];
    input = fopen(fname, "r");
    if( input == NULL ){
        perror(fname);
        exit(EXIT_FAILURE);
    }
    while( fgets(buffer, LINE_LENGTH, input) != NULL)
        printf("%s", buffer);
    if( fclose(input) != 0 ){
        perror( "fclose" );
        exit(EXIT_FAILURE);
    }
}

void
t_scf(void)
{
    char *fname = "/tmp/formated.txt";
    FILE *input;
    input = fopen(fname, "w");
    fputs("1 5 \n", input);
    fputs("12 56 \n", input);
    fputs("123 567 \n", input);
    fputs("1234 5678 \n", input);
    fclose(input);

    int a, b;
    input = fopen(fname, "r");
    while( fscanf( input, "%d %d", &a, &b) == 2 ){
        printf("%-10d, %-10d \n", a, b);
    }
    fclose(input);
}

void
t_seek(void)
{
    t_scf();
    char *fname = "/tmp/formated.txt";
    char buffer[LINE_LENGTH];
    FILE *input;
    input = fopen(fname, "r");
    fgets(buffer, LINE_LENGTH, input);
    printf("%s \n", "=============");
    printf("%s", buffer);
    printf("now on pos: %ld \n", ftell(input));
    fseek(input, 16, SEEK_CUR);
    printf("after on pos: %ld\n", ftell(input));
    fgets(buffer, LINE_LENGTH, input);
    printf("%s", buffer);
    rewind(input);
    printf("rewind on pos: %ld\n", ftell(input));
    fgets(buffer, LINE_LENGTH, input);
    printf("%s", buffer);
    fclose(input);
    /* remove(fname); */
}

int
main( void )
{
    t_seek();
	return 1;
}
