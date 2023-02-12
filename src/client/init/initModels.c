#include "includes.h"

typedef struct {
    model_e type;
    const char *path;
} relation_t;

static const relation_t relation[] = {
    {MODEL_BATARANG, "resources/batarang/Batarang.obj"},
    {MODEL_DORION, "resources/dorion/Dorion.glb"},
    {MODEL_DORION2, "resources/dorion/Dorion2.glb"},
    {MODEL_AMMO_BOX, "resources/ammo_box.glb"},
    {MODEL_DEADPOOL, "resources/deadpool/Deadpool.glb"},
    {MODEL_MIDORIYA, "resources/midoriya/Midoriya.glb"},
    {MODEL_BALD_MIDORIYA, "resources/midoriya/bald_Midoriya.glb"},
    {MODEL_MAXWELL, "resources/maxwell/Maxwell.obj"},
};

Model *getModel(list_t *list, model_e type)
{
    node_t *node = NULL;
    model_t *model = NULL;

    foreach(list->head, node) {
        model = (model_t *)node->data;
        if (model->type == type) {
            return &(model->model);
        }
    }
    return NULL;
}

Model getModelbyModel_t(list_t *list, model_t *model)
{
    node_t *node = NULL;
    model_t *tmp = NULL;

    foreach(list->head, node) {
        tmp = (model_t *)node->data;
        if (tmp == model) {
            return tmp->model;
        }
    }
    return (Model){0};
}

bool isModel(node_t *node, model_e type)
{
    model_t *model = (model_t *)node->data;

    if (model->type == type) {
        return true;
    }
    return false;
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
