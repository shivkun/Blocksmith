#include "visualization.h"
#include <stdio.h>

void display_plan(Plan *plan)
{
    if (!plan)
    {
        fprintf(stderr, "Plan is NULL\n");
        return;
    }

    printf("Plan dimensions: %u x %u x %u\n", plan->width, plan->height, plan->depth);
    for (uint32_t z = 0; z < plan->depth; z++)
    {
        printf("Layer %u:\n", z);
        for (uint32_t y = 0; y < plan->height; y++)
        {
            for (uint32_t x = 0; x < plan->width; x++)
            {
                printf("%2d", plan->grid[z * plan->width * plan->height + y * plan->width + x]);
            }
            printf("\n");
        }
        printf("\n");
    }
}