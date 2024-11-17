#ifndef VISUALIZATION_H
#define VISUALIZATION_H

/**
 * @file visualization.h
 * @brief Functions for visualizing a Plan.
 */

#include "plan.h"

/**
 * @brief Display the plan as a 2D grid (console output). This is a helper function for debugging, and will be replaced by a GUI in the future.
 */
void display_plan(Plan *plan);

#endif // VISUALIZATION_H