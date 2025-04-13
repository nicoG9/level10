#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fileutil.h"

// DIRECTIONS
// Choose whether you are doing the 2D array or
// the array of arrays.
// For the 2D array,
//    implement loadFile2D, substringSearch2D, and free2D.
// For the array of arrays, 
//    implement loadFileAA, substringSearchAA, and freeAA.


// Load the text file from the given filename.
// Return a pointer to the array of strings.
// Sets the value of size to be the number of valid
// entries in the array (not the total array length).
char ** loadFileAA(char *filename, int *size)
{
	FILE *in = fopen(filename, "r");
	if (!in)
	{
	    perror("Can't open file");
	    exit(1);
	}
	// File is opened for reading.

	size_t CAPACITY = 100; // Unsigned integer because we aren't gonna be using negative numbers
	char ** arr = malloc(CAPACITY * sizeof(char *)); // Create an array of arrays, aka array of pointers, aka pointer to pointers.
	size_t arrSize = 0; // Unsigned integer, keeps track of where in the array we are
	
	size_t buffSize = 999; 
	char *buff = malloc((buffSize + 1) * sizeof(char));
	while (fgets(buff, buffSize, in) != NULL)
	{
		// Trim newline using cool way I found on stack overflow
		buff[strcspn(buff, "\n")] = 0; // Finds the first \n in the buff, then sets that index to null terminator \0 = 0

		// Check if the array needs to be extended using realloc
		if (arrSize == CAPACITY)
		{
			printf("Reallocating memory.\n");
			CAPACITY = CAPACITY * 1.5; // Reallocated by +50%
			arr = realloc(arr, CAPACITY * sizeof(char *));
		}
		size_t lineSize = strlen(buff);
		arr[arrSize] = malloc(lineSize + 1); // For null terminator
		strcpy(arr[arrSize], buff);
		arrSize = arrSize + 1;
	}

	// Free the buffer memory, and close the file
	free(buff);
	fclose(in); 
	
	// Set size to array size
	*size = arrSize;
	// Return pointer to the array of strings.
	return arr;
}

char (*loadFile2D(char *filename, int *size))[COLS]
{
	FILE *in = fopen(filename, "r");
	if (!in)
	{
	    perror("Can't open file");
	    exit(1);
	}
	
	// TODO
	// Allocate memory for an 2D array, using COLS as the width.
	// Read the file line by line into a buffer.
    //   Trim newline.
	//   Expand array if necessary (realloc).
	//   Copy each line from the buffer into the array (use strcpy).
    // Close the file.
	
	// The size should be the number of entries in the array.
	*size = 0;
	
	// Return pointer to the array.
	return NULL;
}

// Search the array for the target string.
// Return the found string or NULL if not found.
char * substringSearchAA(char *target, char **lines, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (strstr(lines[i], target))
		{
			return(strstr(lines[i], target));
		}
	}
	return NULL;
}

char * substringSearch2D(char *target, char (*lines)[COLS], int size)
{
    
    return NULL;
}

// Free the memory used by the array
void freeAA(char ** arr, int size)
{
	if (!arr)
		return;
	for (int i = 0; i < size; i++)
	{
		if (arr[i])
		{
			free(arr[i]);
		}
	}
	
	free(arr);
}

void free2D(char (*arr)[COLS])
{

}