/*
** This program test how to use c lib scanf
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define	MAX_COLS	20	/* max # of columns to process */

int	read_column_numbers( int columns[], int max );

int
main( void )
{
	int	n_columns;		/* # of columns to process */
	int	columns[MAX_COLS];	/* the columns to process */

	n_columns = read_column_numbers( columns, MAX_COLS );

	return EXIT_SUCCESS;
}

int
read_column_numbers( int columns[], int max )
{
	int	num = 0;
	int	ch;

	/*
	** Get the numbers, stopping at eof or when a number is < 0.
	*/
	while( num < max && scanf( "%d", &columns[num] ) == 1 && columns[num] >= 0 ){
		num += 1;
		printf( "got number: %d\n", columns[num] );
		printf( "times: %d\n", num );
    }

	/*
	** Make sure we have an even number of inputs, as they are
	** supposed to be paired.
	*/
	while( (ch = getchar()) != EOF && ch != '\n' )
		printf( "Last column number is not paired %d", ch );

	return num;
}
