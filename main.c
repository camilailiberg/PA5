#include <main.h>

int main( int argc, char *argv[]){

	char inExt[4], outExt[4];
	char line[MAX_LINE_LENGTH];
	char cell[MAX_CELL_LENGTH];
	char* rest;

	if(argc < 5){
		fprintf(stderr, "too few args\n");
		exit(1);
	}
	else if(argc > 5){
		fprintf(stderr, "too many args\n");
		exit(1);
	}
	if(!strcmp(argv[1], "-i")){
		strncpy(inExt, argv[2], 3);
		strncpy(outExt, argv[4], 3);
	}
	else if(!strcmp(argv[1], "-o")){
		strncpy(outExt, argv[2], 3);
		strncpy(inExt, argv[4], 3);
	}else{
		fprintf(stderr, "Error: usage of converter: -i inExt -o outExt\n");
		exit(1);
	}
	fprintf(stderr, "in format is %s, out format is %s\n", inExt, outExt);
	
	if(!strcmp(inExt, "csv") && !strcmp(outExt, "txt")){
		while(fgets(line, MAX_LINE_LENGTH, stdin)){
		while(sscanf(line,"%[^,],%[^\n]\n",cell , line) == 
		2)//(strchr(rest, ',')){
		printf("%s\t", cell);//internal cell followed by tab
		printf("%s\n",cell);//last cell followed by new line
	}
	}else if(!strcmp(inExt, "txt") && !strcmp(outExt, "csv")){
		while(fgets(line, MAX_LINE_LENGTH, stdin)){
			while(sscanf(line,"%[^\t]\t%[^\n]\n",cell , line) == 
			2)//(strchr(rest, ',')){
			printf("%s,", cell);//internal cell followed by tab
			printf("%s\n",cell);//last cell followed by new line
			}
	}

}