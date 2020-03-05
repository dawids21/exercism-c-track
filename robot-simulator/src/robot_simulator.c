#include "robot_simulator.h"
#include <string.h>

robot_grid_status_t robot_init(void) {
    robot_grid_status_t robot = {
        .bearing = DEFAULT_BEARING,
        .grid.x_position = DEFAULT_X_COORDINATE,
        .grid.y_position = DEFAULT_Y_COORDINATE,
    };
    return robot;
}

robot_grid_status_t robot_init_with_position(int bearing, int x, int y) {
    robot_grid_status_t robot = {
        .bearing = (bearing < HEADING_MAX ? bearing : DEFAULT_BEARING),
        .grid.x_position = x,
        .grid.y_position = y,
    };
    return robot;
}

void robot_turn_left(robot_grid_status_t * robot) {
    robot->bearing = (robot->bearing == HEADING_NORTH) ? HEADING_WEST : robot->bearing - 1;
}

void robot_turn_right(robot_grid_status_t * robot) {
    robot->bearing = (robot->bearing == HEADING_WEST) ? HEADING_NORTH : robot->bearing + 1;
}

void robot_advance(robot_grid_status_t * robot) {
    switch (robot->bearing) {
        case HEADING_NORTH:
            robot->grid.y_position++;
            break;
        case HEADING_EAST:
            robot->grid.x_position++;
            break;
        case HEADING_SOUTH:
            robot->grid.y_position--;
            break;
        case HEADING_WEST:
            robot->grid.x_position--;
            break;
        default:
            break;
    }
}

void robot_simulator(robot_grid_status_t * robot, const char *commands) {
    for (unsigned int command = 0; command <= strlen(commands); command++) {
        switch (commands[command]) {
            case COMMAND_LEFT:
                robot_turn_left(robot);
                break;
            case COMMAND_RIGHT:
                robot_turn_right(robot);
                break;
            case COMMAND_ADVANCE:
                robot_advance(robot);
                break;
            default:
                break;
        }
    }
}