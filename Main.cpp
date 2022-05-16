#include "Header.h"
#include <iostream>
#include <conio.h>
#include <ctime>
#include <windows.h>

using namespace std;

int main()
{
	srand(time(NULL));

	int position = 1;
	int selection;
	int mode;
	int placement;
	int command = 0;

	while (true) {

		if (command != 'n') {

			system("cls");
			title();
			frame(position, 1, 1);
			cout << "     Start game\t    ";
			frame(position, 1, 2);

			frame(position, 2, 1);
			cout << "     Command list\t    ";
			frame(position, 2, 2);

			frame(position, 3, 1);
			cout << "     Quit\t\t    ";
			frame(position, 3, 2);
			cout << endl << "\t\t        Use " << char(25) << char(24) << " to navigate!" << endl;

			selection = 0;
			int input = keys_input();
			switch (input) {

			case 1: {
				if (position == 3) {
					position = 1;
				}
				else {
					position++;
				}
			}break;

			case -1: {
				if (position == 1) {
					position = 3;
				}
				else {
					position--;
				}
			}break;

			case 0: {
				selection = position;
			}break;
			}
		}

		switch (selection) {

		case 1: {

			HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
			CONSOLE_SCREEN_BUFFER_INFO start_attribute;
			GetConsoleScreenBufferInfo(hStdOut, &start_attribute);

			if (command != 'n') {

				mode = mode_menu();
				placement = 0;

				if (mode == 1) {
					placement = placement_menu();
				}
			}

			s_fleet fleet_player = create_fleet();
			s_fleet fleet_PC = create_fleet();

			int** field_player = new int* [10];
			int** field_PC = new int* [10];

			for (int i = 0; i < 10; i++) {
				field_player[i] = new int[10]{ EMPTY_CELL };
				field_PC[i] = new int[10]{ EMPTY_CELL };
			}

			for_AI pc1_memory;
			for_AI pc2_memory;

			if (mode == 1 && placement == 1) {
				manual_placement(field_player, fleet_player);
			}
			else {
				auto_placement(field_player, fleet_player);
				pc2_memory = init_memory();
			}
			auto_placement(field_PC, fleet_PC);
			pc1_memory = init_memory();

			int turn;
			if (rand() % 2) {
				turn = 1;
			}
			else {
				turn = -1;
			}

			s_point cursor_player;
			cursor_player.i = 4;
			cursor_player.j = 4;
			cursor_player.status = false;

			s_point cursor_PC;
			cursor_PC.i = 4;
			cursor_PC.j = 4;
			cursor_PC.status = false;

			command = 0;
			while (true) {	

				if (turn == 1) {

					if (mode == 1) {
						command = player_turn(field_player, field_PC, fleet_player, fleet_PC, mode, turn, cursor_player, cursor_PC);
						Sleep(1000);
					}
					else {
						pc_turn(field_PC, field_player, fleet_PC, fleet_player, mode, turn, cursor_PC, cursor_player, pc2_memory);
					}
				}

				else {
					pc_turn(field_player, field_PC, fleet_player, fleet_PC, mode, turn, cursor_player, cursor_PC, pc1_memory);
				}

				if (command == 'm' || command == 'n') {
					break;
				}

				turn *= -1;

				if (fleet_PC.status == false) {

					turn = 0;
					show_fields(field_player, field_PC, fleet_player, fleet_PC, mode, turn, cursor_player, cursor_PC);
					SetConsoleTextAttribute(hStdOut, 2);
					frame(1, 1, 1, true);
					white;

					if (mode == 1) {
						cout << "\t     You Win!       ";
					}
					else {
						cout << "\t     PC2 Wins!      ";
					}

					SetConsoleTextAttribute(hStdOut, 2);
					frame(1, 1, 2, true);
					white;
					system("pause");
					break;
				}
				else if (fleet_player.status == false) {

					turn = 0;
					show_fields(field_player, field_PC, fleet_player, fleet_PC, mode, turn, cursor_player, cursor_PC);
					frame(1, 1, 1, true);
					cout << "\t     PC1 Wins!      ";
					frame(1, 1, 2, true);
					system("pause");
					break;
				}
			}
			
			for (int i = 0; i < 10; i++) {

				fleet_player.ships[i].delete_location(fleet_player.ships[i].location);
				fleet_PC.ships[i].delete_location(fleet_PC.ships[i].location);
				delete[] field_player[i];
				delete[] field_PC[i];
			}
			delete[] field_player;
			delete[] field_PC;

		}break;

		case 2: {
			command_list();
		}break;

		case 3: {
			return 0;
		}break;
		}
	}
}