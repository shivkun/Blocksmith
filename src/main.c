#include "blocksmith.h"
#include "file_io.h"
#include "visualization.h"

int main()
{
    // Create a sample plan
    Plan *plan = create_plan(3, 3, 2);

    // Fill the grid with a sample pattern
    for (int i = 0; i < plan->width * plan->height * plan->depth; i++)
    {
        plan->grid[i] = (i % 3) + 1;
    }

    // Save the plan
    save_plan("example.blks", plan);

    // Free the original plan memory
    free_plan(plan);

    // Load the plan
    Plan *loaded_plan = load_plan("example.blks");

    // Display the loaded plan
    display_plan(loaded_plan);

    // Free the loaded plan memory
    free_plan(loaded_plan);

    return 0;
}
