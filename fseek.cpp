#include <stdio.h>

int main ()
{
	FILE * pFile;
	pFile = fopen ( "example.txt" , "wb" );
	fputs ( "hello world                    \n" , pFile );
	fseek ( pFile , 0 , SEEK_SET );
	fputs ( "sam\n" , pFile );
	fseek ( pFile , 0 , SEEK_SET );
	fputs ( "I am\n" , pFile );
	fclose ( pFile );
	return 0;
}
