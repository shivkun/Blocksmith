#include "plan.h"

Plan *create_plan(uint32_t width, uint32_t height, uint32_t depth)
{
    Plan *plan = malloc(sizeof(Plan));
    plan->width = width;
    plan->height = height;
    plan->depth = depth;
    plan->grid = calloc(width * height * depth, sizeof(uint16_t));
    return plan;
}

void free_plan(Plan *plan)
{
    free(plan->grid);
    free(plan);
}