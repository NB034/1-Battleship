#include "Header.h"
#include <iostream>
#include <conio.h>

using namespace std;

s_fleet create_fleet() {

	s_fleet fleet;
	int decks = 4;

	for (int i = 0; i < 10; i++) {

		fleet.ships[i].size = decks;
		fleet.ships[i].location = fleet.ships[i].set_location(decks);

		for (int j = 0; j < decks; j++) {
			fleet.ships[i].location[j].status = false;
		}

		fleet.ships[i].status = false;

		if (i == 0 || i == 2 || i == 5) {
			decks--;
		}
	}

	fleet.status = false;

	return fleet;
}
for_AI init_memory() {

	for_AI mem;
	mem.check_of_horizontal_axis = false;
	mem.check_of_vertical_axis = false;
	mem.check_of_first_direction = false;
	mem.check_of_second_direction = false;
	mem.axis = 0;
	mem.direction = rand() % 2;
	mem.decks = 0;
	mem.last_hit.i = -1;
	mem.last_hit.j = -1;

	return mem;
}
void auto_placement(int** field, s_fleet& fleet) {

	s_point point;
	int direction;
	int check;
	int i;
	int j;

	for (int ship = 0; ship < 10; ship++) {
		while(!fleet.ships[ship].status){
			while (true) {
				point.i = rand() % 10;
				point.j = rand() % 10;
				if (field[point.i][point.j] == EMPTY_CELL) {
					break;
				}
			}

			direction = rand() % 2;
			check = 0;
			i = 0;
			j = 0;

			while (i < fleet.ships[ship].size && j < fleet.ships[ship].size) {
				if (point.i + i < 10 && point.j + j < 10 && field[point.i + i][point.j + j] == EMPTY_CELL) {
					check++;
				}
				if (direction) {
					j++;
				}
				else {
					i++;
				}
			}

			if (fleet.ships[ship].size == check) {

				check = 0;
				i = 0;
				j = 0;

				while (i < fleet.ships[ship].size && j < fleet.ships[ship].size) {

					fleet.ships[ship].location[check].i = point.i + i;
					fleet.ships[ship].location[check].j = point.j + j;
					fleet.ships[ship].location[check].status = true;
					field[point.i + i][point.j + j] = SHIP_DECK;
					check++;

					if (direction) {
						j++;
					}
					else {
						i++;
					}
				}

				fleet.ships[ship].status = true;
				area_around_the_ship(field, fleet.ships[ship]);
			}
		}
	}
	fleet.status = true;
}
void area_around_the_ship(int** field, s_ship& ship, bool for_pc) {
	// Marks the area around the ships for AI and  placement functions

	for (int i = 0; i < ship.size; i++) {

		// Angles
		if (ship.location[i].i - 1 >= 0 && ship.location[i].j - 1 >= 0) {
			if (field[ship.location[i].i - 1][ship.location[i].j - 1] == EMPTY_CELL || field[ship.location[i].i - 1][ship.location[i].j - 1] == CELL_NEAR_THE_SHIP) {
				if (for_pc) {
					field[ship.location[i].i - 1][ship.location[i].j - 1] = CELL_NEAR_THE_SHIP_THAT_PC_SEES;
				}
				else {
					field[ship.location[i].i - 1][ship.location[i].j - 1] = CELL_NEAR_THE_SHIP;
				}
			}
		}

		if (ship.location[i].i - 1 >= 0 && ship.location[i].j + 1 <= 9) {
			if (field[ship.location[i].i - 1][ship.location[i].j + 1] == EMPTY_CELL || field[ship.location[i].i - 1][ship.location[i].j + 1] == CELL_NEAR_THE_SHIP) {
				if (for_pc) {
					field[ship.location[i].i - 1][ship.location[i].j + 1] = CELL_NEAR_THE_SHIP_THAT_PC_SEES;
				}
				else {
					field[ship.location[i].i - 1][ship.location[i].j + 1] = CELL_NEAR_THE_SHIP;
				}
			}
		}

		if (ship.location[i].i + 1 <= 9 && ship.location[i].j + 1 <= 9) {
			if (field[ship.location[i].i + 1][ship.location[i].j + 1] == EMPTY_CELL || field[ship.location[i].i + 1][ship.location[i].j + 1] == CELL_NEAR_THE_SHIP) {
				if (for_pc) {
					field[ship.location[i].i + 1][ship.location[i].j + 1] = CELL_NEAR_THE_SHIP_THAT_PC_SEES;
				}
				else {
					field[ship.location[i].i + 1][ship.location[i].j + 1] = CELL_NEAR_THE_SHIP;
				}
			}
		}

		if (ship.location[i].i + 1 <= 9 && ship.location[i].j - 1 >= 0) {
			if (field[ship.location[i].i + 1][ship.location[i].j - 1] == EMPTY_CELL || field[ship.location[i].i + 1][ship.location[i].j - 1] == CELL_NEAR_THE_SHIP) {
				if (for_pc) {
					field[ship.location[i].i + 1][ship.location[i].j - 1] = CELL_NEAR_THE_SHIP_THAT_PC_SEES;
				}
				else {
					field[ship.location[i].i + 1][ship.location[i].j - 1] = CELL_NEAR_THE_SHIP;
				}
			}
		}

		// Edges
		if (ship.location[i].i - 1 >= 0) {
			if (field[ship.location[i].i - 1][ship.location[i].j] == EMPTY_CELL || field[ship.location[i].i - 1][ship.location[i].j] == CELL_NEAR_THE_SHIP) {
				if (for_pc) {
					field[ship.location[i].i - 1][ship.location[i].j] = CELL_NEAR_THE_SHIP_THAT_PC_SEES;
				}
				else {
					field[ship.location[i].i - 1][ship.location[i].j] = CELL_NEAR_THE_SHIP;
				}
			}
		}

		if (ship.location[i].i + 1 <= 9) {
			if (field[ship.location[i].i + 1][ship.location[i].j] == EMPTY_CELL || field[ship.location[i].i + 1][ship.location[i].j] == CELL_NEAR_THE_SHIP) {
				if (for_pc) {
					field[ship.location[i].i + 1][ship.location[i].j] = CELL_NEAR_THE_SHIP_THAT_PC_SEES;
				}
				else {
					field[ship.location[i].i + 1][ship.location[i].j] = CELL_NEAR_THE_SHIP;
				}
			}
		}

		if (ship.location[i].j + 1 >= 0) {
			if (field[ship.location[i].i][ship.location[i].j - 1] == EMPTY_CELL || field[ship.location[i].i][ship.location[i].j - 1] == CELL_NEAR_THE_SHIP) {
				if (for_pc) {
					field[ship.location[i].i][ship.location[i].j - 1] = CELL_NEAR_THE_SHIP_THAT_PC_SEES;
				}
				else {
					field[ship.location[i].i][ship.location[i].j - 1] = CELL_NEAR_THE_SHIP;
				}
			}
		}

		if (ship.location[i].j <= 9) {
			if (field[ship.location[i].i][ship.location[i].j + 1] == EMPTY_CELL || field[ship.location[i].i][ship.location[i].j + 1] == CELL_NEAR_THE_SHIP) {
				if (for_pc) {
					field[ship.location[i].i][ship.location[i].j + 1] = CELL_NEAR_THE_SHIP_THAT_PC_SEES;
				}
				else {
					field[ship.location[i].i][ship.location[i].j + 1] = CELL_NEAR_THE_SHIP;
				}
			}
		}
	}
}
void fleet_status_refresh(s_fleet& fleet) {

	int defeat = 0;
	for (int i = 0; i < 10; i++) {

		int destroyed = 0;
		for (int j = 0; j < fleet.ships[i].size; j++) {
			if (fleet.ships[i].location[j].status == false) {
				destroyed++;
			}
		}

		if (destroyed == fleet.ships[i].size) {
			fleet.ships[i].status = false;
		}

		if (fleet.ships[i].status == false) {
			defeat++;
		}
	}
	if (defeat == 10) {
		fleet.status = false;
	}
}
void pc_turn(int** field_1, int** field_2, s_fleet& fleet_1, s_fleet& fleet_2, int mode, int turn, s_point& cursor_1, s_point& cursor_2, for_AI& memory) {
	// AI

	int ship;
	while (true) {

		intermediate_for_show_fields(field_1, field_2, fleet_1, fleet_2, mode, turn, cursor_1, cursor_2);

		for (int i = 0; i < 10; i++) {
			if (fleet_1.ships[i].status) {
				ship = i;
				break;
			}
		}

		// Search for a cell for a shot
		if (memory.decks == 0) {

			int size_of_area = 1;
			int side = 1;

			while (true) {

				cursor_1.i = rand() % 10;
				cursor_1.j = rand() % 10;

				if (field_1[cursor_1.i][cursor_1.j] != MISS && field_1[cursor_1.i][cursor_1.j] != DAMAGED_DECK_OF_DESTROYED_SHIP && field_1[cursor_1.i][cursor_1.j] != CELL_NEAR_THE_SHIP_THAT_PC_SEES) {
					
					memory.axis = rand() % 2;
					if (memory.axis) {

						int i = 0;
						while (true) {

							i++;
							if (side) {
								if (cursor_1.i + i < 10) {
									if (field_1[cursor_1.i + i][cursor_1.j] != MISS && field_1[cursor_1.i + i][cursor_1.j] != CELL_NEAR_THE_SHIP_THAT_PC_SEES) {
										size_of_area++;
									}
								}
								else {
									side = 0;
									i = 0;
								}
							}
							else {
								if (cursor_1.i - i >= 0) {
									if (field_1[cursor_1.i - i][cursor_1.j] != MISS && field_1[cursor_1.i - i][cursor_1.j] != CELL_NEAR_THE_SHIP_THAT_PC_SEES) {
										size_of_area++;
									}
								}
								else {
									side = 1;
									break;
								}
							}
						}
					}
					else {

						int j = 0;
						while (true) {

							j++;
							if (side) {
								if (cursor_1.j + j < 10) {
									if (field_1[cursor_1.i][cursor_1.j + j] != MISS && field_1[cursor_1.i][cursor_1.j + j] != CELL_NEAR_THE_SHIP_THAT_PC_SEES) {
										size_of_area++;
									}
								}
								else {
									side = 0;
									j = 0;
								}
							}
							else {
								if (cursor_1.j - j >= 0) {
									if (field_1[cursor_1.i][cursor_1.j + j] != MISS && field_1[cursor_1.i][cursor_1.j + j] != CELL_NEAR_THE_SHIP_THAT_PC_SEES) {
										size_of_area++;
									}
								}
								else {
									side = 1;
									break;
								}
							}
						}
					}
					if (size_of_area >= fleet_1.ships[ship].size) {
						break;
					}
				}
			}
		}

		// Search for the second cell of the wrecked ship
		else if (memory.decks == 1) {

			cursor_1.i = memory.last_hit.i;
			cursor_1.j = memory.last_hit.j;

			while (true) {
				if (memory.check_of_second_direction && memory.check_of_first_direction) {

					if (memory.axis) {
						memory.check_of_vertical_axis = true;
						memory.check_of_second_direction = false;
						memory.check_of_first_direction = false;
						memory.axis = 0;
					}
					else {
						memory.check_of_horizontal_axis = true;
						memory.check_of_second_direction = false;
						memory.check_of_first_direction = false;
						memory.axis = 1;
					}
				}

				if (memory.axis) {
					if (memory.direction) {
						if (memory.last_hit.i - 1 < 0 || field_1[memory.last_hit.i - 1][memory.last_hit.j] == CELL_NEAR_THE_SHIP_THAT_PC_SEES || field_1[memory.last_hit.i - 1][memory.last_hit.j] == MISS) {
							memory.check_of_first_direction = true;
							memory.direction = 0;
						}
						else {
							cursor_1.i--;
							break;
						}
					}
					else {
						if (memory.last_hit.i + 1 > 9 || field_1[memory.last_hit.i + 1][memory.last_hit.j] == CELL_NEAR_THE_SHIP_THAT_PC_SEES || field_1[memory.last_hit.i + 1][memory.last_hit.j] == MISS) {
							memory.check_of_second_direction = true;
							memory.direction = 1;
						}
						else {
							cursor_1.i++;
							break;
						}
					}
				}
				else {
					if (memory.direction) {
						if (memory.last_hit.j - 1 < 0 || field_1[memory.last_hit.i][memory.last_hit.j - 1] == CELL_NEAR_THE_SHIP_THAT_PC_SEES || field_1[memory.last_hit.i][memory.last_hit.j - 1] == MISS) {
							memory.check_of_first_direction = true;
							memory.direction = 0;
						}
						else {
							cursor_1.j--;
							break;
						}
					}
					else {
						if (memory.last_hit.j + 1 > 9 || field_1[memory.last_hit.i][memory.last_hit.j + 1] == CELL_NEAR_THE_SHIP_THAT_PC_SEES || field_1[memory.last_hit.i][memory.last_hit.j + 1] == MISS) {
							memory.check_of_second_direction = true;
							memory.direction = 1;
						}
						else {
							cursor_1.j++;
							break;
						}
					}
				}
			}
		}

		// Search for remaining cells
		else if (memory.decks == 2 || memory.decks == 3) {

			cursor_1.i = memory.last_hit.i;
			cursor_1.j = memory.last_hit.j;
			int shift = 1;

			if (memory.axis) {
				while (true) {
					if (memory.direction) {
						if (memory.last_hit.i - shift < 0 || field_1[memory.last_hit.i - shift][memory.last_hit.j] == CELL_NEAR_THE_SHIP_THAT_PC_SEES || field_1[memory.last_hit.i - shift][memory.last_hit.j] == MISS) {
							memory.direction = 0;
							shift = 1;
						}
						else if (field_1[memory.last_hit.i - shift][memory.last_hit.j] == DAMAGED_DECK) {
							shift++;
						}
						else {
							cursor_1.i -= shift;
							break;
						}
					}
					else {
						if (memory.last_hit.i + shift > 9 || field_1[memory.last_hit.i + shift][memory.last_hit.j] == CELL_NEAR_THE_SHIP_THAT_PC_SEES || field_1[memory.last_hit.i + shift][memory.last_hit.j] == MISS) {
							memory.direction = 1;
							shift = 1;
						}
						else if (field_1[memory.last_hit.i + shift][memory.last_hit.j] == DAMAGED_DECK) {
							shift++;
						}
						else {
							cursor_1.i += shift;
							break;
						}
					}
				}
			}
			else {
				while (true) {
					if (memory.direction) {
						if (memory.last_hit.j - shift < 0 || field_1[memory.last_hit.i][memory.last_hit.j - shift] == CELL_NEAR_THE_SHIP_THAT_PC_SEES || field_1[memory.last_hit.i][memory.last_hit.j - shift] == MISS) {
							memory.direction = 0;
							shift = 1;
						}
						else if (field_1[memory.last_hit.i][memory.last_hit.j - shift] == DAMAGED_DECK) {
							shift++;
						}
						else {
							cursor_1.j -= shift;
							break;
						}
					}
					else {
						if (memory.last_hit.j + shift > 9 || field_1[memory.last_hit.i][memory.last_hit.j + shift] == CELL_NEAR_THE_SHIP_THAT_PC_SEES || field_1[memory.last_hit.i][memory.last_hit.j + shift] == MISS) {						
							memory.direction = 1;
							shift = 1;
						}
						else if (field_1[memory.last_hit.i][memory.last_hit.j + shift] == DAMAGED_DECK) {
							shift++;
						}
						else {
							cursor_1.j += shift;
							break;
						}
					}
				}
			}
		}

		// If miss
		if (field_1[cursor_1.i][cursor_1.j] == EMPTY_CELL || field_1[cursor_1.i][cursor_1.j] == CELL_NEAR_THE_SHIP) {

			intermediate_for_show_fields(field_1, field_2, fleet_1, fleet_2, mode, turn, cursor_1, cursor_2);
			field_1[cursor_1.i][cursor_1.j] = MISS;
			intermediate_for_show_fields(field_1, field_2, fleet_1, fleet_2, mode, turn, cursor_1, cursor_2);

			if (memory.direction) {
				memory.check_of_second_direction = true;
				memory.direction = 0;
			}
			else {
				memory.check_of_first_direction = true;
				memory.direction = 1;
			}

			if (memory.decks == 1) {
				if (memory.check_of_second_direction && memory.check_of_first_direction) {

					if (memory.axis) {
						memory.check_of_vertical_axis = true;
						memory.check_of_second_direction = false;
						memory.check_of_first_direction = false;
						memory.axis = 0;
					}
					else {
						memory.check_of_horizontal_axis = true;
						memory.check_of_second_direction = false;
						memory.check_of_first_direction = false;
						memory.axis = 1;
					}
				}
			}
			break;
		}

		// If hit
		else if (field_1[cursor_1.i][cursor_1.j] == SHIP_DECK) {
			intermediate_for_show_fields(field_1, field_2, fleet_1, fleet_2, mode, turn, cursor_1, cursor_2);

			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < fleet_1.ships[i].size; j++) {
					if (fleet_1.ships[i].location[j].i == cursor_1.i && fleet_1.ships[i].location[j].j == cursor_1.j) {

						fleet_1.ships[i].location[j].status = false;
						fleet_status_refresh(fleet_1);

						if (fleet_1.ships[i].status) {

							field_1[cursor_1.i][cursor_1.j] = DAMAGED_DECK;
							memory.last_hit.i = cursor_1.i;
							memory.last_hit.j = cursor_1.j;
							memory.decks++;
							if (memory.decks == 2 || memory.decks == 3) {
								memory.direction = rand() % 2;
							}
						}
						else {

							for (int a = 0; a < fleet_1.ships[i].size; a++) {
								field_1[fleet_1.ships[i].location[a].i][fleet_1.ships[i].location[a].j] = DAMAGED_DECK_OF_DESTROYED_SHIP;
							}
							area_around_the_ship(field_1, fleet_1.ships[i], true);
							memory = init_memory();
						}
						i = 9;
					}
				}
			}
			if (fleet_1.status == false) {
				break;
			}
		}
	}
}