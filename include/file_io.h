#ifndef FILE_IO_H
#define FILE_IO_H

/**
 * @file file_io.h
 * @brief Functions for saving and loading plans to and from files.
 */

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
 * @return A pointer to the loaded Plan, or NULL if the operation fails.
 */
Plan *load_plan(const char *filename);

#endif // FILE_IO_H