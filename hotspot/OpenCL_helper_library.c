#include "OpenCL_helper_library.h"

// Loads the kernel source code from the specified file into a C string and returns the string pointer
char *load_kernel_source(const char *filename) {
	// Open the source file
	FILE *file = fopen(filename, "r");
	if (file == NULL) fatal("Error opening kernel source file\n");
	
	// Determine the size of the file
	if (fseek(file, 0, SEEK_END)) fatal("Error reading kernel source file\n");
	size_t size = ftell(file);
	
	// Allocate space for the source code (plus one for null-terminator)
	char *source = (char *) malloc(size + 1);
	
	// Read the source code into the string
	fseek(file, 0, SEEK_SET);
	// printf("Number of elements: %lu\nSize = %lu", fread(source, 1, size, file), size);
	// exit(1);
	if (fread(source, 1, size, file) != size) fatal("Error reading kernel source file\n");
	
	// Null-terminate the string
	source[size] = '\0';
	
	// Return the pointer to the string
	return source;
}


// Returns the current system time in microseconds
long long get_time() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000) + tv.tv_usec;
}

void fatal(const char *s) {
	fprintf(stderr, "Error: %s\n", s);
	exit(1);
}

