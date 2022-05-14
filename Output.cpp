#include "Header.h"
#include <iostream>
#include <conio.h>

using namespace std;

void title(bool shift) {

	cout << endl;
	if (shift) {
		cout << "\t\t\t      ";
	}

	cout << char(254) << char(254) << char(254) << char(254) << "   ";				
	cout << " " << char(254) << char(254) << char(254) << "   ";					
	cout << char(254) << char(254) << char(254) << char(254) << char(254) << "  ";	
	cout << char(254) << char(254) << char(254) << char(254) << char(254) << "  ";	
	cout << char(254) << "      ";													
	cout << char(254) << char(254) << char(254) << char(254) << char(254) << "  ";	
	cout << char(254) << char(254) << char(254) << char(254) << char(254) << "  ";	
	cout << char(254) << "      ";													
	cout << "  " << char(254) << "    ";											
	cout << char(254) << char(254) << char(254) << char(254) << "   ";				
	cout << endl;

	if (shift) {
		cout << "\t\t\t      ";
	}

	cout << char(219) << "   " << char(219) << "  ";
	cout << char(219) << "   " << char(219) << "  ";
	cout << "  " << char(219) << "    ";
	cout << "  " << char(219) << "    ";
	cout << char(219) << "      ";
	cout << char(219) << "      ";
	cout << char(219) << "      ";
	cout << char(219) << "      ";
	cout << "  " << char(219) << "    ";
	cout << char(219) << "   " << char(219) << "  ";
	cout << endl;

	if (shift) {
		cout << "\t\t\t      ";
	}

	cout << char(254) << char(254) << char(254) << char(254) << char(254) << "  ";
	cout << char(254) << char(254) << char(254) << char(254) << char(254) << "  ";
	cout << "  " << char(254) << "    ";
	cout << "  " << char(254) << "    ";
	cout << char(254) << "      ";
	cout << char(254) << char(254) << char(254) << char(254) << char(254) << "  ";
	cout << char(254) << char(254) << char(254) << char(254) << char(254) << "  ";
	cout << char(254) << char(254) << char(254) << char(254) << char(254) << "  ";
	cout << "  " << char(254) << "    ";
	cout << char(254) << char(254) << char(254) << char(254) << "   ";
	cout << endl;

	if (shift) {
		cout << "\t\t\t      ";
	}

	cout << char(219) << "   " << char(219) << "  ";
	cout << char(219) << "   " << char(219) << "  ";
	cout << "  " << char(219) << "    ";
	cout << "  " << char(219) << "    ";
	cout << char(219) << "      ";
	cout << char(219) << "      ";
	cout << "    " << char(219) << "  ";
	cout << char(219) << "   " << char(219) << "  ";
	cout << "  " << char(219) << "    ";
	cout << char(219) << "      ";
	cout << endl;

	if (shift) {
		cout << "\t\t\t      ";
	}

	cout << char(254) << char(254) << char(254) << char(254) << char(254) << "  ";
	cout << char(254) << "   " << char(254) << "  ";
	cout << "  " << char(254) << "    ";
	cout << "  " << char(254) << "    ";
	cout << char(254) << char(254) << char(254) << char(254) << char(254) << "  ";
	cout << char(254) << char(254) << char(254) << char(254) << char(254) << "  ";
	cout << char(254) << char(254) << char(254) << char(254) << char(254) << "  ";
	cout << char(254) << "   " << char(254) << "  ";
	cout << "  " << char(254) << "    ";
	cout << char(254) << "     ";
	cout << endl << endl;
}
void frame(int position, int item, int type, bool shift) {
	// Frames for textboxes
	if (position == item && type == 1) {

		if (shift) {
			cout << "\t\t\t\t";
		}
		cout << "\t\t     " << char(201);

		for (int i = 0; i < 22; i++) {
			cout << char(205);
		}
		cout << char(187) << endl;

		if (shift) {
			cout << "\t\t\t\t";
		}
		cout << "\t\t     " << char(186);
	}

	else if (position == item && type == 2) {

		cout << char(186) << endl;
		if (shift) {
			cout << "\t\t\t\t";
		}
		cout << "\t\t     " << char(200);

		for (int i = 0; i < 22; i++) {
			cout << char(205);
		}
		cout << char(188) << endl;
	}

	else if (position != item && type == 1) {

		cout << "\t\t     " << char(218);
		for (int i = 0; i < 22; i++) {
			cout << char(196);
		}
		cout << char(191) << endl;
		cout << "\t\t     " << char(179);
	}

	else if (position != item && type == 2) {

		cout << char(179) << endl;
		cout << "\t\t     " << char(192);
		for (int i = 0; i < 22; i++) {
			cout << char(196);
		}
		cout << char(217) << endl;
	}
}
void command_list() {

	system("cls");
	title();

	cout << char(201);
	for (int i = 0; i < 67; i++) {
		cout << char(205);
	}
	cout << char(187) << endl;

	cout << char(186) << "[m] - ends the game and returns to the main menu;\t\t    " << char(186);
	cout << endl;

	cout << char(204);
	for (int i = 0; i < 67; i++) {
		cout << char(205);
	}
	cout << char(185) << endl;

	cout << char(186) << "[p] - blocks the possibility of firing;\t\t\t    " << char(186);
	cout << endl;

	cout << char(204);
	for (int i = 0; i < 67; i++) {
		cout << char(205);
	}
	cout << char(185) << endl;

	cout << char(186) << "[c] - unlocks the possibility of firing;\t\t\t    " << char(186);
	cout << endl;

	cout << char(204);
	for (int i = 0; i < 67; i++) {
		cout << char(205);
	}
	cout << char(185) << endl;

	cout << char(186) << "[n] - starts new game.\t\t\t\t\t\t    " << char(186);
	cout << endl;

	cout << char(200);
	for (int i = 0; i < 67; i++) {
		cout << char(205);
	}
	cout << char(188) << endl << endl;

	system("pause");
}
int mode_menu() {

	int position = 1;
	while (true) {

		system("cls");
		title();
		frame(position, 1, 1);
		cout << " Player VS Computer   ";
		frame(position, 1, 2);

		frame(position, 2, 1);
		cout << " Computer VS Computer ";
		frame(position, 2, 2);

		cout << endl << "\t\t        Use " << char(25) << char(24) << " to navigate!" << endl;

		int input = keys_input();
		switch (input) {

		case 1: {
			if (position == 2) {
				position = 1;
			}
			else {
				position++;
			}
		}break;

		case -1: {
			if (position == 1) {
				position = 2;
			}
			else {
				position--;
			}
		}break;

		case 0: {
			return position;
		}break;
		}
	}
}
int placement_menu() {

	int position = 1;
	while (true) {

		system("cls");
		title();

		frame(position, 1, 1);
		cout << "   Manual placement   ";
		frame(position, 1, 2);

		frame(position, 2, 1);
		cout << "   Auto placement     ";
		frame(position, 2, 2);

		cout << endl << "\t\t        Use " << char(25) << char(24) << " to navigate!" << endl;

		int input = keys_input();
		switch (input) {

		case 1: {
			if (position == 2) {
				position = 1;
			}
			else {
				position++;
			}
		}break;

		case -1: {
			if (position == 1) {
				position = 2;
			}
			else {
				position--;
			}
		}break;

		case 0: {
			return position;
		}break;
		}
	}
}
void signatures(int mode) {

	// Frame
	cout << "\t\t   " << char(201);
	for (int i = 0; i < 39; i++) {
		cout << char(205);
	}
	cout << char(187);

	cout << "\t      " << char(201);
	for (int i = 0; i < 39; i++) {
		cout << char(205);
	}
	cout << char(187) << endl;

	// Signatures
	cout << "\t\t   " << char(186);
	if (mode == 1) {
		cout << "\t\t  Your field" << "\t\t   ";
		cout << char(186);
	}
	else {
		cout << "\t\t  PC 2 field" << "\t\t   ";
		cout << char(186);
	}

	cout << "\t      " << char(186);
	cout << "\t\t     PC 1 field" << "\t\t      ";
	cout << char(186) << endl;

	// Frame
	cout << "\t\t   " << char(200);
	for (int i = 0; i < 39; i++) {
		cout << char(205);
	}
	cout << char(188);

	cout << "\t      " << char(200);
	for (int i = 0; i < 39; i++) {
		cout << char(205);
	}
	cout << char(188) << endl;
}
void whose_turn(int turn, int mode) {

	if (turn == 1) {

		frame(1, 1, 1, true);
		if (mode == 1) {
			cout << "\t    Your turn!      ";
		}

		else {
			cout << "\t    PC2's turn!     ";
		}
		frame(1, 1, 2, true);
	}

	else if (turn == -1) {

		frame(1, 1, 1, true);
		cout << "\t    PC1's turn!     ";
		frame(1, 1, 2, true);
	}
}
void show_fields(int** field_1, int** field_2, s_fleet& fleet_1, s_fleet& fleet_2, int mode, int turn, s_point& cursor_1, s_point& cursor_2) {
	// Output of the fields

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO start_attribute;
	GetConsoleScreenBufferInfo(hStdOut, &start_attribute);

	system("cls");
	title(true);

	// Letters
	cout << "\t\t  ";
	for (int i = 65; i < 75; i++) {
		cout << "   " << char(i);
	}
	cout << "\t     ";

	for (int i = 65; i < 75; i++) {
		cout << "   " << char(i);
	}
	cout << endl;

	// Upper parts of the frames
	red_1;
	if (cursor_1.i == 0 && cursor_1.j == 0) {
		red;
	}
	cout << "\t\t   " << char(201);
	white;

	for (int i = 0; i < 39; i++) {

		red_1;
		if (cursor_1.i == 0) {
			red_1;
			if (cursor_1.j * 4 - 1 == i) {
				red;
				cout << char(201);
			}
			else if (cursor_1.j * 4 == i) {
				red;
				cout << char(205);
			}
			else if (cursor_1.j * 4 + 3 == i) {
				cout << char(187);
				white;
			}
			else {
				cout << char(205);
			}
		}
		else {
			cout << char(205);
		}
	}

	red_1
	if (cursor_1.i == 0 && cursor_1.j == 9) {
		red;
	}
	cout << char(187);
	white;

	//
	red_2;
	if (cursor_2.i == 0 && cursor_2.j == 0) {
		red;
	}
	cout << "\t      " << char(201);
	white;

	for (int i = 0; i < 39; i++) {

		red_2;
		if (cursor_2.i == 0) {
			red_2;
			if (cursor_2.j * 4 - 1 == i) {
				red;
				cout << char(201);
			}
			else if (cursor_2.j * 4 == i) {
				red;
				cout << char(205);
			}
			else if (cursor_2.j * 4 + 3 == i) {
				cout << char(187);
				white;
			}
			else {
				cout << char(205);
			}
		}
		else {
			cout << char(205);
		}
	}

	red_2;
	if (cursor_2.i == 0 && cursor_2.j == 9) {
		red;
	}
	cout << char(187) << endl;
	white;

	// Fields
	for (int i = 0; i < 10; i++) {
		// First field

		if (i != 9) {
			cout << "\t\t " << i + 1 << " ";
			red_1;
			if (cursor_1.i == i && cursor_1.j == 0) {
				red;
			}
			cout << char(186);
			white;
		}

		else {
			cout << "\t\t" << i + 1 << " ";
			red_1;
			if (cursor_1.i == i && cursor_1.j == 0) {
				red;
			}
			cout<<char(186);
			white;
		}

		for (int j = 0; j < 10; j++) {

			if (j > 0) {
				if (cursor_1.i == i && cursor_1.j == j) {
					red;
					cout << char(186);
					white;
				}
				else if (cursor_1.i == i && cursor_1.j + 1 == j) {
					red;
					cout << char(186);
					white;
				}
				else {
					cout << char(179);
				}
			}

			if (field_1[i][j] == SHIP_DECK) {
				cout << " " << char(254) << " ";
			}
			else if (field_1[i][j] == DAMAGED_DECK) {
				red;
				cout << " " << char(254) << " ";
				white;
			}
			else if (field_1[i][j] == DAMAGED_DECK_OF_DESTROYED_SHIP) {
				red;
				cout << " " << char(254) << " ";
				white;
			}
			else if (field_1[i][j] == MISS) {
				cout << " " << char(15) << " ";
			}
			else {
				cout << "   ";
			}
		}

		red_1;
		if (cursor_1.i == i && cursor_1.j == 9) {
			red;
		}
		cout << char(186);
		white;

		// Second
		cout << "\t   ";
		if (i != 9) {
			cout << " " << i + 1 << " ";
			red_2;
			if (cursor_2.i == i && cursor_2.j == 0) {
				red;
			}
			cout << char(186);
			white;
		}

		else {
			cout << "" << i + 1 << " ";
			red_2;
			if (cursor_2.i == i && cursor_2.j == 0) {
				red;
			}
			cout << char(186);
			white;
		}

		// "Player VS Computer" mode
		if (mode == 1) {
			for (int j = 0; j < 10; j++) {

				if (j > 0) {
					if (cursor_2.i == i && cursor_2.j == j) {
						red;
						cout << char(186);
						white;
					}
					else if (cursor_2.i == i && cursor_2.j + 1 == j) {
						red;
						cout << char(186);
						white;
					}
					else {
						cout << char(179);
					}
				}

				if (field_2[i][j] == DAMAGED_DECK) {
					red;
					cout << " " << char(253) << " ";
					white;
				}
				else if (field_2[i][j] == DAMAGED_DECK_OF_DESTROYED_SHIP) {
					red;
					cout << " " << char(254) << " ";
					white;
				}
				else if (field_2[i][j] == MISS) {
					cout << " " << char(15) << " ";
				}
				else {
					cout << "   ";
				}
			}
		}

		// "Computer VS Computer" mode
		else {
			for (int j = 0; j < 10; j++) {

				if (j > 0) {
					if (cursor_2.i == i && cursor_2.j == j) {
						red;
						cout << char(186);
						white;
					}
					else if (cursor_2.i == i && cursor_2.j + 1 == j) {
						red;
						cout << char(186);
						white;
					}
					else {
						cout << char(179);
					}
				}

				if (field_2[i][j] == SHIP_DECK) {
					cout << " " << char(254) << " ";

				}
				else if (field_2[i][j] == DAMAGED_DECK) {
					red;
					cout << " " << char(254) << " ";
					white;
				}
				else if (field_2[i][j] == DAMAGED_DECK_OF_DESTROYED_SHIP) {
					red;
					cout << " " << char(254) << " ";
					white;
				}
				else if (field_2[i][j] == MISS) {
					cout << " " << char(15) << " ";
				}
				else {
					cout << "   ";
				}
			}
		}

		red_2;
		if (cursor_2.i == i && cursor_2.j == 9) {
			red;
		}
		cout << char(186) << endl;
		white;

		// Dividing lines
		if (i < 9) {

			// First field
			red_1;
			if (cursor_1.i == i && cursor_1.j == 0) {
				red;
				cout << "\t\t   " << char(200);
			}
			else if (cursor_1.i - 1 == i && cursor_1.j == 0) {
				red;
				cout << "\t\t   " << char(201);
			}
			else {
				cout << "\t\t   " << char(186);
			}
			white;

			for (int j = 0; j < 39; j++) {

				if ((j + 1) % 4 != 0) {
					if (cursor_1.j * 4 == j && (cursor_1.i == i || cursor_1.i - 1 == i)) {
						red;
						cout << char(205);
					}
					else if (cursor_1.j * 4 + 1 == j && (cursor_1.i == i || cursor_1.i - 1 == i)) {
						cout << char(205);
					}
					else if (cursor_1.j * 4 + 2 == j && (cursor_1.i == i || cursor_1.i - 1 == i)) {
						cout << char(205);
						white;
					}
					else {
						cout << char(196);
					}
				}

				else {
					if (cursor_1.j * 4 - 1 == j && cursor_1.i - 1 == i) {
						red;
						cout << char(201);
					}
					else if (cursor_1.j * 4 + 3 == j && cursor_1.i - 1 == i) {
						red;
						cout << char(187);
						white;
					}
					else if (cursor_1.j * 4 - 1 == j && cursor_1.i == i) {
						red;
						cout << char(200);
					}
					else if (cursor_1.j * 4 + 3 == j && cursor_1.i == i) {
						red;
						cout << char(188);
						white;
					}
					else {
						cout << char(197);
					}
				}
			}

			red_1;
			if (cursor_1.i == i && cursor_1.j == 9) {
				red;
				cout << char(188);
			}
			else if (cursor_1.i - 1 == i && cursor_1.j == 9) {
				red;
				cout << char(187);
			}
			else {
				cout << char(186);
			}
			white;

			// Second
			red_2;
			if (cursor_2.i == i && cursor_2.j == 0) {
				red;
				cout << "\t      " << char(200);
			}
			else if (cursor_2.i - 1 == i && cursor_2.j == 0) {
				red;
				cout << "\t      " << char(201);
			}
			else {
				cout << "\t      " << char(186);
			}
			white;

			for (int j = 0; j < 39; j++) {

				if ((j + 1) % 4 != 0) {
					if (cursor_2.j * 4 == j && (cursor_2.i == i || cursor_2.i - 1 == i)) {
						red;
						cout << char(205);
					}
					else if (cursor_2.j * 4 + 1 == j && (cursor_2.i == i || cursor_2.i - 1 == i)) {
						cout << char(205);
					}
					else if (cursor_2.j * 4 + 2 == j && (cursor_2.i == i || cursor_2.i - 1 == i)) {
						cout << char(205);
						white;
					}
					else {
						cout << char(196);
					}
				}
				else {
					if (cursor_2.j * 4 - 1 == j && cursor_2.i - 1 == i) {
						red;
						cout << char(201);
					}
					else if (cursor_2.j * 4 + 3 == j && cursor_2.i - 1 == i) {
						red;
						cout << char(187);
						white;
					}
					else if (cursor_2.j * 4 - 1 == j && cursor_2.i == i) {
						red;
						cout << char(200);
					}
					else if (cursor_2.j * 4 + 3 == j && cursor_2.i == i) {
						red;
						cout << char(188);
						white;
					}
					else {
						cout << char(197);
					}
				}
			}

			red_2;
			if (cursor_2.i == i && cursor_2.j == 9) {
				red;
				cout << char(188) << endl;
			}
			else if (cursor_2.i - 1 == i && cursor_2.j == 9) {
				red;
				cout << char(187) << endl;
			}
			else {
				cout << char(186) << endl;
			}
			white;
		}
	}

	// Lower parts of the frames
	red_1;
	if (cursor_1.i == 9 && cursor_1.j == 0) {
		red;
	}
	cout << "\t\t   " << char(200);
	white;


	for (int i = 0; i < 39; i++) {

		red_1;
		if (cursor_1.i == 9) {
			red_1;
			if (cursor_1.j * 4 - 1 == i) {
				red;
				cout << char(200);
			}
			else if (cursor_1.j * 4 == i) {
				red;
				cout << char(205);
			}
			else if (cursor_1.j * 4 + 3 == i) {
				cout << char(188);
				white;
			}
			else {
				cout << char(205);
			}
		}
		else {
			cout << char(205);
		}
	}

	red_1;
	if (cursor_1.i == 9 && cursor_1.j == 9) {
		red;
	}
	cout << char(188);
	white;

	//
	red_2;
	if (cursor_2.i == 9 && cursor_2.j == 0) {
		red;
	}
	cout << "\t      " << char(200);
	white;

	for (int i = 0; i < 39; i++) {

		red_2;
		if (cursor_2.i == 9) {
			red_2;
			if (cursor_2.j * 4 - 1 == i) {
				red;
				cout << char(200);
			}
			else if (cursor_2.j * 4 == i) {
				red;
				cout << char(205);
			}
			else if (cursor_2.j * 4 + 3 == i) {
				cout << char(188);
				white;
			}
			else {
				cout << char(205);
			}
		}
		else {
			cout << char(205);
		}
	}

	red_2;
	if (cursor_2.i == 9 && cursor_2.j == 9) {
		red;
	}
	cout << char(188) << endl;
	white;

	signatures(mode);
	whose_turn(turn, mode);
}
bool show_one_field(int** field, s_ship& ship) {
	// Output for the manual placement

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO start_attribute;
	GetConsoleScreenBufferInfo(hStdOut, &start_attribute);

	bool check = true;

	system("cls");
	title(true);

	// Letters
	cout << "\t\t  ";
	for (int i = 65; i < 75; i++) {
		cout << "   " << char(i);
	}
	cout << "\t     " << endl;

	// Frame
	cout << "\t\t   " << char(201);
	for (int i = 0; i < 39; i++) {
		cout << char(205);
	}
	cout << char(187) << endl;

	// Field
	bool skip;
	for (int i = 0; i < 10; i++) {

		if (i != 9) {
			cout << "\t\t " << i + 1 << " ";
			cout << char(186);
		}
		else {
			cout << "\t\t" << i + 1 << " ";
			cout << char(186);
		}

		for (int j = 0; j < 10; j++) {

			if (j > 0) {
				cout << char(179);
			}
			
			skip = false;
			for (int a = 0; a < ship.size; a++) {

				if (ship.location[a].i == i && ship.location[a].j == j) {

					if (field[i][j] == SHIP_DECK || field[i][j] == CELL_NEAR_THE_SHIP) {
						red;
						cout << " " << char(254) << " ";
						white;
						check = false;
						skip = true;
					}

					else {
						cout << " " << char(254) << " ";
						skip = true;
					}
				}
			}

			if (field[i][j] == SHIP_DECK && !skip) {
				cout << " " << char(254) << " ";
			}
			else if (!skip) {
				cout << "   ";
			}
		}
		cout << char(186) << endl;

		// Dividing lines
		if (i < 9) {
			cout << "\t\t   " << char(186);

			for (int j = 0; j < 39; j++) {

				if ((j + 1) % 4 != 0) {
					cout << char(196);
				}

				else {
					cout << char(197);
				}
			}
			cout << char(186) << endl;
		}
	}

	// Frame
	cout << "\t\t   " << char(200);
	for (int i = 0; i < 39; i++) {
		cout << char(205);

	}
	cout << char(188) << endl;

	cout << "\t\t\tUse arrows to move the ship  " << endl;
	cout << "\t\t\tPress [d] to change the direction" << endl;
	cout << "\t\t\tPress [enter] to place the ship " << endl;

	return check;
}
void intermediate_for_show_fields(int** field_1, int** field_2, s_fleet& fleet_1, s_fleet& fleet_2, int mode, int turn, s_point& cursor_1, s_point& cursor_2) {
	// Function for the correct transmission of parameters

	if (mode == 1) {
		show_fields(field_1, field_2, fleet_1, fleet_2, mode, turn, cursor_1, cursor_2);
	}

	else {

		if (turn == 1) {
			show_fields(field_2, field_1, fleet_2, fleet_1, mode, turn, cursor_2, cursor_1);
		}
		else {
			show_fields(field_1, field_2, fleet_1, fleet_2, mode, turn, cursor_1, cursor_2);
		}
	}

	Sleep(1000);
}