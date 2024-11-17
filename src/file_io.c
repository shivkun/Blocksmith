#include "file_io.h"
#include "blocksmith.h"

void save_plan(const char *filename, Plan *plan)
{
    FILE *file = fopen(filename, "wb");
    if (!file)
    {
        fprintf(stderr, "Error: Could not open file %s for writing.\n", filename);
        return;
    }

    // Write header
    uint32_t magic = BLKS_MAGIC_NUMBER;
    fwrite(&magic, sizeof(uint32_t), 1, file);
    uint16_t version = BLKS_VERSION;
    fwrite(&version, sizeof(uint16_t), 1, file);

    // Write dimensions
    fwrite(&plan->width, sizeof(uint32_t), 1, file);
    fwrite(&plan->height, sizeof(uint32_t), 1, file);
    fwrite(&plan->depth, sizeof(uint32_t), 1, file);

    // Write grid data
    size_t grid_size = plan->width * plan->height * plan->depth;
    fwrite(plan->grid, sizeof(uint16_t), grid_size, file);

    // Write a checksum (dummy for now)
    uint32_t checksum = 0xDEADBEEF;
    fwrite(&checksum, sizeof(uint32_t), 1, file);

    fclose(file);
}

Plan *load_plan(const char *filename)
{
    FILE *file = fopen(filename, "rb");
    if (!file)
    {
        fprintf(stderr, "Error: Could not open file %s for reading.\n", filename);
        return NULL;
    }

    // Read header
    uint32_t magic;
    fread(&magic, sizeof(uint32_t), 1, file);
    if (magic != BLKS_MAGIC_NUMBER)
    {
        fprintf(stderr, "Error: File %s is not a Blocksmith file.\n", filename);
        fclose(file);
        return NULL;
    }

    uint16_t version;
    fread(&version, sizeof(uint16_t), 1, file);
    if (version != BLKS_VERSION)
    {
        fprintf(stderr, "Error: File %s has an unsupported version.\n", filename);
        fclose(file);
        return NULL;
    }

    // Read dimensions
    Plan *plan = malloc(sizeof(Plan));
    fread(&plan->width, sizeof(uint32_t), 1, file);
    fread(&plan->height, sizeof(uint32_t), 1, file);
    fread(&plan->depth, sizeof(uint32_t), 1, file);

    // Allocate memory for grid data
    size_t grid_size = plan->width * plan->height * plan->depth;
    plan->grid = malloc(sizeof(uint16_t) * grid_size);
    fread(plan->grid, sizeof(uint16_t), grid_size, file);

    // Read and ignore checksum
    uint32_t checksum;
    fread(&checksum, sizeof(uint32_t), 1, file);

    fclose(file);
    return plan;
}