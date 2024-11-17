#ifndef PLAN_H
#define PLAN_H

#include <stdint.h>
#include <stdlib.h>

// Plan structure
typedef struct
{
    uint32_t width;
    uint32_t height;
    uint32_t depth;
    uint16_t *grid;
} Plan;

/**
 * @brief Create a new plan
 *
 * @param width The width of the plan
 * @param height The height of the plan
 * @param depth The depth of the plan
 */
Plan *create_plan(uint32_t width, uint32_t height, uint32_t depth);

/**
 * @brief Destroy a plan
 *
 * @param plan The plan to destroy
 */
void free_plan(Plan *plan);

#endif // PLAN_H