#ifndef FILE_IO_H
#define FILE_IO_H

#include "plan.h"

/**
 * @brief Save a plan to the Blocksmith binary file format.
 *
 * @param filename The name of the file to save the plan to.
 * @param plan The plan to save.
 */
void save_plan(const char *filename, Plan *plan);

/**
 * @brief Load a plan from the Blocksmith binary file format.
 *
 * @param filename The name of the file to load the plan from.
 * @return The loaded plan.
 */
Plan *load_plan(const char *filename);

#endif // FILE_IO_H