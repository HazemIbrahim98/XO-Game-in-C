#include<stdio.h>
#include<stdlib.h>

void start(char arr[3][3]) {
	int count = 49;
	for (int row = 0; row<3; row++)
		for (int col = 0; col<3; col++)
		{
			arr[row][col] = count;
			count++;
		}
}

int checkfull(char arr[3][3]) {
	int count = 0;

	for (int row = 0; row < 3; row++)
		for (int col = 0; col<3; col++)
			if (arr[row][col] < 58 && arr[row][col] > 48)
				return 0;
	return 1;
}

int adjustturn(int turn) {
	if (turn == 1)
		turn = 2;
	else
		turn = 1;
	return turn;
}

int winner(char arr[3][3]) {
	for (int row = 0; row<3; row++)
		if (arr[row][0] == 'X'&&arr[row][1] == 'X'&&arr[row][2] == 'X')
			return 1;
		else if (arr[row][0] == 'O'&&arr[row][1] == 'O'&&arr[row][2] == 'O')
			return 2;

	for (int col = 0; col<3; col++)
		if (arr[0][col] == 'X'&&arr[1][col] == 'X'&&arr[2][col] == 'X')
			return 1;
		else if (arr[0][col] == 'O'&&arr[1][col] == 'O'&&arr[2][col] == 'O')
			return 2;

	if (arr[0][0] == 'X'&&arr[1][1] == 'X'&&arr[2][2] == 'X')
		return 1;
	else if (arr[0][0] == 'O'&&arr[1][1] == 'O'&&arr[2][2] == 'O')
		return 2;

	if (arr[0][2] == 'X'&&arr[1][1] == 'X'&&arr[2][0] == 'X')
		return 1;
	else if (arr[0][2] == 'O'&&arr[1][1] == 'O'&&arr[2][0] == 'O')
		return 2;
	return 0;
}

void main() {
	char arr[3][3];
	int row, col, turn = 1, win, input, i, j;
	char replay;

restart:
	start(arr);

	printf("Would You Like To Start With\n1)X\n2)O\n");
	scanf_s("%d", &turn);

	system("cls");

	while (1)
	{
		printf("Its player %d Turn\n", turn);

		for (int row = 0; row<3; row++)
		{
			for (int col = 0; col < 3; col++)
				printf("%c ", arr[row][col]);
			printf("\n");
		}

	invalid:

		scanf_s("%d", &input);

		if (input > 9 || input < 1)
		{
			printf("Invalid Input\n");
			goto invalid;
		}

		for (int row = 0; row<3; row++)
			for (int col = 0; col < 3; col++)
				if (arr[row][col] == input + 48)
				{
					i = row;
					j = col;
					break;
				}
		if (arr[i][j] == 'X' || arr[i][j] == 'O')
		{
			printf("Area Allready Used\n");
			goto invalid;
		}

		if (turn == 1)
			arr[i][j] = 'X';
		else
			arr[i][j] = 'O';

		win = winner(arr);

		if (win == 1 || win == 2)
			break;

		if (checkfull(arr) == 1)
		{
			printf("It's A Draw\n");
			goto draw;
		}

		turn = adjustturn(turn);

		system("cls");
	}

	system("cls");
	for (int row = 0; row<3; row++)
	{
		for (int col = 0; col<3; col++)
			printf("%c ", arr[row][col]);
		printf("\n");
	}
	printf("Player %d Is The Winner\n", turn);

draw:
	printf("Play Again? (Y / N)\n");
	scanf_s("%c", &replay);
	scanf_s("%c", &replay);
	if (replay == 'Y' || replay == 'y')
	{
		system("cls");
		goto restart;
	}
	else
		exit;

}