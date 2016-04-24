//===============================================================================================================================================================================================================200
//	INCLUDE/DEFINE
//===============================================================================================================================================================================================================200

#include <stdio.h>										// needed by types/functions related to file handling

//===============================================================================================================================================================================================================200
//	READ PARAMETERS FUNCTION
//===============================================================================================================================================================================================================200

#include "./../../main.h"								// needed for definition of fp

//===============================================================================================================================================================================================================200
//	INCLUDE HEADER
//===============================================================================================================================================================================================================200

#include "./file.h"

//===============================================================================================================================================================================================================200
//	READ PARAMETERS FUNCTION
//===============================================================================================================================================================================================================200

void 
read_parameters(char* filename,
				int* tSize,
				int* sSize,
				int* maxMove,
				fp* alpha){

	//================================================================================80
	//	VARIABLES
	//================================================================================80

	FILE* fid;

	//================================================================================80
	//	OPEN FILE FOR READING
	//================================================================================80

	fid = fopen(filename, "r");
	if( fid == NULL ){
		printf( "The file was not opened for reading\n" );
		return;
	}

	//================================================================================80
	//	READ VALUES FROM THE FILE
	//================================================================================80

	fscanf(fid, "%d", &tSize[0]);
	fscanf(fid, "%d", &sSize[0]);
	fscanf(fid, "%d", &maxMove[0]);
	fscanf(fid, "%f", &alpha[0]);

	//================================================================================80
	//	CLOSE FILE
	//================================================================================80

	fclose(fid);

}

//===============================================================================================================================================================================================================200
//	READ HEADER FUNCTION
//===============================================================================================================================================================================================================200

void 
read_header(char* filename,
			int* size,
			int* size_2){

	//================================================================================80
	//	VARIABLES
	//================================================================================80

	FILE* fid;
	int i;
	char c;

	//================================================================================80
	//	OPEN FILE FOR READING
	//================================================================================80

	fid = fopen(filename, "r");
	if( fid == NULL ){
		printf( "The file was not opened for reading\n" );
		return;
	}

	//================================================================================80
	//	SKIP LINES
	//================================================================================80

	i = 0;
	while(i<1){
		c = fgetc(fid);
		if(c == '\n'){
			i = i+1;
		}
	};

	//================================================================================80
	//	READ VALUES FROM THE FILE
	//================================================================================80

	fscanf(fid, "%d", &size[0]);

	fscanf(fid, "%d", &size_2[0]);

	//================================================================================80
	//	CLOSE FILE
	//================================================================================80

	fclose(fid);

}

//===============================================================================================================================================================================================================200
//	READ DATA FUNCTION
//===============================================================================================================================================================================================================200

void 
read_data(	char* filename,
			int size,
			int* input_a,
			int* input_b,
			int size_2,
			int* input_2a,
			int* input_2b){

	//================================================================================80
	//	VARIABLES
	//================================================================================80

	FILE* fid;
	int i;
	char c;

	//================================================================================80
	//	OPEN FILE FOR READING
	//================================================================================80

	fid = fopen(filename, "r");
	if( fid == NULL ){
		printf( "The file was not opened for reading\n" );
		return;
	}

	//================================================================================80
	//	SKIP LINES
	//================================================================================80

	i = 0;
	while(i<2){
		c = fgetc(fid);
		if(c == '\n'){
			i = i+1;
		}
	};

	//================================================================================80
	//	READ VALUES FROM THE FILE
	//================================================================================80

	for(i=0; i<size; i++){
		fscanf(fid, "%d", &input_a[i]);
	}
	for(i=0; i<size; i++){
		fscanf(fid, "%d", &input_b[i]);
	}

	for(i=0; i<size_2; i++){
		fscanf(fid, "%d", &input_2a[i]);
	}
	for(i=0; i<size_2; i++){
		fscanf(fid, "%d", &input_2b[i]);
	}

	//================================================================================80
	//	CLOSE FILE
	//================================================================================80

	fclose(fid);

}

//===============================================================================================================================================================================================================200
//	End
//===============================================================================================================================================================================================================200
