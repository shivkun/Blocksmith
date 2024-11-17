#ifndef PLAN_H
#define PLAN_H

/**
 * @file plan.h
 * @brief Defines the Plan structure and related functions.
 */

#include <stdint.h>
#include <stdlib.h>

/**
 * @struct Plan
 * @brief Represents a 3D grid plan for a Minecraft build.
 *
 * The Plan structure stores the dimensions of the build and a grid of block IDs.
 */
typedef struct
{
    uint32_t width;
    uint32_t height;
    uint32_t depth;
    uint16_t *grid;
} Plan;

/**
 * @brief Create a new Plan with the specificed dimensions.
 *
 * @param width The width of the plan
 * @param height The height of the plan
 * @param depth The depth of the plan
 * @return A pointer to the newly created Plan.
 */
Plan *create_plan(uint32_t width, uint32_t height, uint32_t depth);

/**
 * @brief Frees the memory allocated for a Plan.
 *
 * @param plan A pointer to the Plan to free.
 */
void free_plan(Plan *plan);

#endif // PLAN_H