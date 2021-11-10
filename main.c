#include <main.h>

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
	
	if(!strcmp(inExt, "csv") && !strcmp(outExt, "txt")){ //? if inExt == csv and outExt == txt
		while(fgets(line, MAX_LINE_LENGTH, stdin)){ //? getting first line from 
			while(sscanf(line,"%[^,],%[^\n]\n",cell , line) == 
			2)//(strchr(rest, ',')){ //? this is getting the first cell value stored in cell and the rest of the cells of that row stored in line
			{
				printf("internal cell followed by a tab: %s\t", cell);//internal cell followed by tab
			}
		printf("last cell followed by new line: %s\n",cell);//last cell followed by new line
	}
	}else if(!strcmp(inExt, "txt") && !strcmp(outExt, "csv")){ //? if inExt == txt and outExt == csv
		while(fgets(line, MAX_LINE_LENGTH, stdin)){ //? getting first line
			while(sscanf(line,"%[^\t]\t%[^\n]\n",cell , line) == 
			2)//(strchr(rest, ',')){ //? this is getting the first cell value stored in cell and the rest of the cells of that row stored in line
			{
				printf("internal cell followed by a tab: %s,", cell);//internal cell followed by tab
			}
			printf("last cell followed by new line: %s\n",cell);//last cell followed by new line
		}
	}

}