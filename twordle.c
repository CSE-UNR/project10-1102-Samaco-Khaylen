//Author: Khaylen Samaco
//Date: 5/1/2026

#include <stdio.h>
#define R 6
#define C 7

void getGuess(int rows, char array_words[][C]);
void numletters(int rows, char array_words[][C]);
void lowercase(int rows, char array_words[][C]);
void guesses(int cRow, char array_words[][C]);
void spotchecker(char mystery[], int rows, char array_words[][C], char result[], int used[]);
void spotpointer(char mystery[], int rows, char array_words[][C], char result[], int used[]);
void checkletters(int rows, char array_words[][C]);

int main(){
	char array_words[R][C], mystery[C], result[C];
	int rows, cols, used[C];
	
	FILE *word;
	word = fopen("mystery.txt", "r");
	
	if(word == NULL){
		printf("Couldn't open file.\n");
		return 1;
	}
	
	fscanf(word, "%5s", mystery);
	fclose(word);
	
	for(rows = 0; rows < R; rows++){
		getGuess(rows, array_words);
		numletters(rows, array_words);
		checkletters(rows, array_words);
		lowercase(rows, array_words);
		
	}
	
	printf("FINAL GUESS: ");
	scanf(" %s", array_words[rows]);
	numletters(rows, array_words);
	checkletters(rows, array_words);
	lowercase(rows, array_words);
	printf("==================================\n");
	
	
	for(int i = 0; i < 5; i++){
		result[i] = '_';
		used[i] = 0;
	}
	result[5] = '\0';
	
	int win = 1;
	for(int i = 0; i < 5; i++){
		if(result[i] != '*'){
			win = 0;
			break;
		}
	}
	
	if(win){
		printf("          You won in %d guesses!", rows + 1);
		return 0;
	}
	
	
	
	
	
	
return 0;
}


//checks if there's any non-letter characters and if theres 5 letters.
void numletters(int rows, int cols, char array_words[][cols]){
	int i, j;
	
	for(i = 0; i < rows; i++){
		int length = 0;
	for(j = 0; array_words[i][j] != '\0'; j++){
		length++;
	}
	
	if(length == 5){
		lowercase(R, C, array_words);
	}
	else{
		printf("Your guess must be 5 letters long.\n");
		printf("Please try again: ");
		scanf(" %s", array_words[rows]);
	}
	}
}

void getGuess(int rows, char array_words[][C]){
	
	printf("Guess %d! Enter your guess: ", row + 1);
	scanf(" %5s", array_words[rows]);
	printf("==================================\n");

}

// Gets user word and turns it all into lower-case.
void lowercase(int rows, char array_words[][C]){
	int i;
	for(i = 0; array_words[row][i] != '\0'; i++){
		if(array_words[row][i] >= 'A' && array_words[row][i] <= 'Z'){
			array_words[row][i] += ('a' - 'A');
		}
	}
}


//stores the user's previous guesses into an array of strings and displays it.
void guesses(int cRow, char array_words[][C]){
	for(int i = 0; i <= cRow; i++){
		printf("%s\n\n", array_words[i]);
	}
}


//Capitalizes letters in correct spots.
//F6 can go here with an if statement
void spotchecker(char mystery[], int rows, char array_words[][C], char result[], int used[]){
	for(int i = 0; i < 5; i++){
		if(array_words[row][i] == mystery[i]){
			result[i] = '*';
			used[i] = 1;
		}
	}
}


void spotpointer(char mystery[], int rows, char array_words[][C], char result[], int used[]){
	for(int i = 0; i < 5; i++){
		if(result[i] == '*'){
			for(int j = 0; j < 5; j++){
				if(!used[j] && array_words[row][i] == mystery[j]){
		result[i] = '^';
		used[j] = 1;
		break;		
				}
			}
		}
	}
}


//Checks for double letters for function 5.
void checkletters(int rows, char array_words[][C]){
	int valid;
	
	while(1){
		valid = 1;
		
		for(int i = 0; i < 5; i++){
			char ch = array_words[row][i];
			
			if(!((ch >= 'A && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))){
				
				valid = 0;
				break;
				
			}		
	
		}
		
		if(valid) break;
		
		printf("Your guess must only contain letters.\n");
		printf("Please try again: ");
		scanf("%5s", array_words[row]);
		numletters(row, array_words);
	
	}
	
}





