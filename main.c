#include <main.h>

// void check (*cell)
// {

// }

int main( int argc, char *argv[]){

	char inExt[4], outExt[4];
	char line[MAX_LINE_LENGTH];
	char cell[MAX_CELL_LENGTH];
	char* rest;

	if(argc < 5){ //? Error handling
		fprintf(stderr, "too few args\n");
		exit(1);
	}
	else if(argc > 5){ //? Error handling
		fprintf(stderr, "too many args\n");
		exit(1);
	}
	if(!strcmp(argv[1], "-i")){ //? if it is an input data
		strncpy(inExt, argv[2], 3); //? get the input format (csv or tl5) and save it in inExt
		strncpy(outExt, argv[4], 3); //? get the output format (csv or tl5) and save it in outExt
	}
	else if(!strcmp(argv[1], "-o")){ //? if it is an output data
		strncpy(outExt, argv[2], 3); //? get the output format (csv or tl5) and save it in outExt
		strncpy(inExt, argv[4], 3); //? get the input format (csv or tl5) and save it in inExt
	}else{ //? Error handling
		fprintf(stderr, "Error: usage of converter: -i inExt -o outExt\n");
		exit(1);
	}
	fprintf(stderr, "in format is %s, out format is %s\n", inExt, outExt);
	
	//* csv to tl5
	if(!strcmp(inExt, "csv") && !strcmp(outExt, "tl5")){ //? if inExt == csv and outExt == tl5
		while(fgets(line, MAX_LINE_LENGTH, stdin)){ //? getting first line from 
			while(sscanf(line,"%[^,],%[^\n]\n",cell , line) == 
			2)//(strchr(rest, ',')){ //? this is getting the first cell value stored in cell and the rest of the cells of that row stored in line
			{
				if(strlen(cell) >= 5)
				{
					printf("%.5s|",cell);
				}
				else if(strlen(cell) < 5)
				{
					printf("%-5s|",cell);
				}
			}
			if(strlen(cell) >= 5)
			{
				printf("%.5s",cell);
			}
			else if(strlen(cell) < 5)
			{
				printf("%-5s\n",cell);
			}
			
		}
	}
	//* csv to csv
	else if(!strcmp(inExt, "csv") && !strcmp(outExt, "csv")){ //? if inExt == csv and outExt == csv
		while(fgets(line, MAX_LINE_LENGTH, stdin)){ //? getting first line
			while(sscanf(line,"%[^,],%[^\n]\n",cell , line) == 
			2)//(strchr(rest, ',')){ //? this is getting the first cell value stored in cell and the rest of the cells of that row stored in line
			{
				//printf("intern
				printf("%s,",cell);
			}
			printf("%s\n",cell);
		}
	}
	//* tl5 to tl5
	else if(!strcmp(inExt, "tl5") && !strcmp(outExt, "tl5")){ //? if inExt == tl5 and outExt == tl5
		while(fgets(line, MAX_LINE_LENGTH, stdin)){ //? getting first line
			while(sscanf(line,"%[^|]|%[^\n]\n",cell , line) == 
			2)//(strchr(rest, ',')){ //? this is getting the first cell value stored in cell and the rest of the cells of that row stored in line
			{
				printf("%s|", cell);
			}
			printf("%s\n",cell);
		}
	}
	//* tl5 to csv
	else if(!strcmp(inExt, "tl5") && !strcmp(outExt, "csv")){ //? if inExt == tl5 and outExt == csv
		while(fgets(line, MAX_LINE_LENGTH, stdin)){ //? getting first line
			while(sscanf(line,"%[^|]|%[^\n]\n",cell , line) == 
			2)//(strchr(rest, ',')){ //? this is getting the first cell value stored in cell and the rest of the cells of that row stored in line
			{
				sscanf(cell,"%[^ ]",cell);
				printf("%s,", cell);
			}
			sscanf(cell,"%[^ ]",cell);
			printf("%s\n", cell);
		}
	}

}