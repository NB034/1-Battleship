#include "Header.h"
#include <iostream>
#include <conio.h>

using namespace std;

int keys_input() {
	// For the arrows input

	int arrow;
	arrow = _getch();

	if (arrow == 224) {

		arrow = _getch();

		if (arrow == 72) {
			return -1;
		}
		else if (arrow == 80) {
			return 1;
		}
	}

	else if (arrow == 13) {
		return 0;
	}
}
void manual_placement(int** field, s_fleet& fleet) {

	bool check;
	for (int ship = 0; ship < 10; ship++) {

		if (!fleet.ships[ship].status) {
			for (int i = 0; i < fleet.ships[ship].size; i++) {

				fleet.ships[ship].location[i].i = 0;
				fleet.ships[ship].location[i].j = i;
				fleet.ships[ship].direction = 0;
			}
		}

		while (!fleet.ships[ship].status) {

			check = show_one_field(field, fleet.ships[ship]);
			int arrow;
			arrow = _getch();

			if (arrow == 224) {

				arrow = _getch();
				if (arrow == 72) {
					if (fleet.ships[ship].location[0].i > 0) {
						for (int i = 0; i < fleet.ships[ship].size; i++) {
							fleet.ships[ship].location[i].i--;
						}
					}
				}

				else if (arrow == 80) {
					if (fleet.ships[ship].location[fleet.ships[ship].size - 1].i < 9) {
						for (int i = 0; i < fleet.ships[ship].size; i++) {
							fleet.ships[ship].location[i].i++;
						}
					}
				}

				else if (arrow == 75) {
					if (fleet.ships[ship].location[0].j > 0) {
						for (int i = 0; i < fleet.ships[ship].size; i++) {
							fleet.ships[ship].location[i].j--;
						}
					}
				}

				else if (arrow == 77) {
					if (fleet.ships[ship].location[fleet.ships[ship].size - 1].j < 9) {
						for (int i = 0; i < fleet.ships[ship].size; i++) {
							fleet.ships[ship].location[i].j++;
						}
					}
				}
			}

			else if (arrow == 100) {
				if (fleet.ships[ship].direction) {
					if (fleet.ships[ship].location[0].j + fleet.ships[ship].size - 1 <= 9) {

						for (int i = 1; i < fleet.ships[ship].size; i++) {
							fleet.ships[ship].location[i].i = fleet.ships[ship].location[0].i;
							fleet.ships[ship].location[i].j = fleet.ships[ship].location[0].j + i;
						}
						fleet.ships[ship].direction = 0;
					}
				}
				else {
					if (fleet.ships[ship].location[0].i + fleet.ships[ship].size - 1 <= 9) {

						for (int i = 1; i < fleet.ships[ship].size; i++) {
							fleet.ships[ship].location[i].i = fleet.ships[ship].location[0].i + i;
							fleet.ships[ship].location[i].j = fleet.ships[ship].location[0].j;
						}
						fleet.ships[ship].direction = 1;
					}
				}
			}
			else if (arrow == 13) {
				if (check) {

					for (int i = 0; i < fleet.ships[ship].size; i++) {
						field[fleet.ships[ship].location[i].i][fleet.ships[ship].location[i].j] = SHIP_DECK;
						fleet.ships[ship].location[i].status = true;
						area_around_the_ship(field, fleet.ships[ship]);
					}
					fleet.ships[ship].status = true;
				}
			}
		}
	}
	fleet.status = true;
}
int player_turn(int** field_1, int** field_2, s_fleet& fleet_1, s_fleet& fleet_2, int mode, int turn, s_point& cursor_1, s_point& cursor_2) {

	bool pause = false;
	int action = 0;

	while (true) {

		show_fields(field_1, field_2, fleet_1, fleet_2, mode, turn, cursor_1, cursor_2);
		action = _getch();

		if (action == 224) {

			action = _getch();
			if (action == 72) {
				if (cursor_2.i > 0) {
					cursor_2.i--;
				}
			}
			else if (action == 80) {
				if (cursor_2.i < 9) {
					cursor_2.i++;
				}
			}
			else if (action == 75) {
				if (cursor_2.j > 0) {
					cursor_2.j--;
				}
			}
			else if (action == 77) {
				if (cursor_2.j < 9) {
					cursor_2.j++;
				}
			}
		}

		else if (action == 109) {
			return action;
		}
		else if (action == 112) {
			pause = true;
		}
		else if (action == 99) {
			pause = false;
		}
		else if (action == 110) {
			return action;
		}

		else if (action == 13) {
			if (!pause) {

				if (field_2[cursor_2.i][cursor_2.j] == EMPTY_CELL || field_2[cursor_2.i][cursor_2.j] == CELL_NEAR_THE_SHIP) {
					field_2[cursor_2.i][cursor_2.j] = MISS;
					show_fields(field_1, field_2, fleet_1, fleet_2, mode, turn, cursor_1, cursor_2);
					return 0;
				}

				else if (field_2[cursor_2.i][cursor_2.j] == SHIP_DECK) {
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < fleet_2.ships[i].size; j++) {

							if (fleet_2.ships[i].location[j].i == cursor_2.i && fleet_2.ships[i].location[j].j == cursor_2.j) {

								fleet_2.ships[i].location[j].status = false;
								fleet_status_refresh(fleet_2);

								if (fleet_2.ships[i].status) {
									field_2[cursor_2.i][cursor_2.j] = DAMAGED_DECK;
								}
								else {
									for (int a = 0; a < fleet_2.ships[i].size; a++) {
										field_2[fleet_2.ships[i].location[a].i][fleet_2.ships[i].location[a].j] = DAMAGED_DECK_OF_DESTROYED_SHIP;
									}
								}
								i = 9;
							}
						}
					}
					if (fleet_2.status == false) {
						return 0;
					}
				}
			}
			else {
				cout << "\t\t\t\t\t\t      Press [c] to continue!" << endl;
				Sleep(1000);
			}
		}
	}
}