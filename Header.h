#pragma once
#include <iostream>
#include <windows.h>

// Macros for colouring
#define red SetConsoleTextAttribute(hStdOut, 4)
#define red_1 if (turn == -1) { SetConsoleTextAttribute(hStdOut, 4); }
#define red_2 if (turn == 1) { SetConsoleTextAttribute(hStdOut, 4); }
#define white SetConsoleTextAttribute(hStdOut, start_attribute.wAttributes)

// Enumeration for the cells of fields
enum types_of_cells {

	CELL_NEAR_THE_SHIP_THAT_PC_SEES = -2,
	CELL_NEAR_THE_SHIP = -1,
	EMPTY_CELL = 0,
	SHIP_DECK = 1,
	DAMAGED_DECK = 2,
	DAMAGED_DECK_OF_DESTROYED_SHIP = 3,
	MISS = 4
};

struct s_point {

	int i;
	int j;
	bool status;
};
struct s_ship {

	int size;
	int direction;
	bool status;
	s_point* location;

	s_point* set_location(const int Size) {
		s_point* location = new s_point[Size];
		return location;
	}
	void delete_location(s_point* location) {
		delete[] location;
	}
};
struct s_fleet {

	s_ship ships[10];
	bool status;
};
struct for_AI {
	// Need for the AI to finish off the damaged ships

	bool check_of_horizontal_axis : 1;
	bool check_of_vertical_axis : 1;
	bool check_of_first_direction : 1;
	bool check_of_second_direction : 1;
	int axis : 1;
	int direction : 1;
	int decks : 3;
	s_point last_hit;
};

// Output
void title(bool shift = false);
void command_list();
void frame(int position, int item, int type, bool shift = false);
void command_list();
int mode_menu();
int placement_menu();
bool show_one_field(int** field, s_ship& ship);
void show_fields(int** field_1, int** field_2, s_fleet& fleet_1, s_fleet& fleet_2, int mode, int turn, s_point& cursor_1, s_point& cursor_2);
void signatures(int mode);
void whose_turn(int turn, int mode);
void intermediate_for_show_fields(int** field_1, int** field_2, s_fleet& fleet_1, s_fleet& fleet_2, int mode, int turn, s_point& cursor_1, s_point& cursor_2);

// Input
int keys_input();
void manual_placement(int** field, s_fleet& fleet);
int player_turn(int** field_1, int** field_2, s_fleet& fleet_1, s_fleet& fleet_2, int mode, int turn, s_point& cursor_1, s_point& cursor_2);

// Inner logic
s_fleet create_fleet();
for_AI init_memory();
void auto_placement(int** field, s_fleet& fleet);
void area_around_the_ship(int** field, s_ship& ship, bool for_pc = false);
void fleet_status_refresh(s_fleet& fleet);
void pc_turn(int** field_1, int** field_2, s_fleet& fleet_1, s_fleet& fleet_2, int mode, int turn, s_point& cursor_1, s_point& cursor_2, for_AI& memory);