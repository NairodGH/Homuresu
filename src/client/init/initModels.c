#include "includes.h"

typedef struct {
    model_e type;
    const char *path;
} relation_t;

static const relation_t relation[] = {
    {MODEL_BATARANG, "resources/batarang/Batarang.obj"},
    {MODEL_DORION, "resources/dorion/Dorion.glb"},
    {MODEL_DORION2, "resources/dorion/Dorion2.glb"},
};

Model *getModel(game_t *game, model_e type)
{
    node_t *node = NULL;
    model_t *model = NULL;

    foreach(game->model->head, node) {
        model = (model_t *)node->data;
        if (model->type == type) {
            return &(model->model);
        }
    }
    return NULL;
}

void initModels(game_t *game)
{
    model_t *model = NULL;

    game->model = list_create();
    for (int i = 0; i < sizeof(relation) / sizeof(relation_t); i++) {
        model = calloc(1, sizeof(model_t));
        model->type = relation[i].type;
        model->model = LoadModel(relation[i].path);

        list_push_data(game->model, model);
    }
}
