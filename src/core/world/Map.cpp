#include "Map.h"
#include <cstdlib>  // for rand()
#include <ctime>    // for time()
#include <vector>

#ifndef RELEASE_BUILD
#include "utils/debug/DebugUI.h"
#endif

Map::Map() {
    std::srand(static_cast<unsigned int>(time(nullptr)));
    tileset = { 0 };
    // treeTexture = { 0 };
}

Map::~Map() {
    Unload();
}

void Map::Load(const char* tilesetPath) {
    if (tileset.id == 0) 
        tileset = LoadTexture(tilesetPath);
  
}

// void Map::LoadTree(const char* treePath) {
//     if (treeTexture.id == 0) 
//         treeTexture = LoadTexture(treePath);
// }

void Map::Unload() {
    if (tileset.id != 0) {
        UnloadTexture(tileset);
        tileset.id = 0;
    }
    // if (treeTexture.id != 0) {
    //     UnloadTexture(treeTexture);
    //     treeTexture.id = 0;
    // }
}

void Map::GenerateRandom() {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            int r = std::rand() % TILE_COUNT;
            tiles[y][x].type = static_cast<TileType>(r);
        }
    }
}

// void Map::PlaceTree(int tileX, int tileY, int spriteX, int spriteY) {
//     const float SPRITE_SIZE = 128.0f; // assuming each tree is 128x128
//     Rectangle src = {
//         spriteX * SPRITE_SIZE,
//         spriteY * SPRITE_SIZE,
//         SPRITE_SIZE,
//         SPRITE_SIZE
//     };
//     trees.push_back({
//         Vector2{ (float)tileX, (float)tileY },
//         src
//     });
// }

// std::vector<Rectangle> Map::GetTreeCollisionBounds() const {
//     std::vector<Rectangle> bounds;
//     for (const Tree& tree : trees) {
//         Rectangle dest = {
//             tree.position.x * TILE_SIZE * scale,
//             tree.position.y * TILE_SIZE * scale,
//             tree.srcRect.width * (scale / 2),   // same as used in Draw
//             tree.srcRect.height * (scale / 2)
//         };
//         bounds.push_back(dest);
//     }
//     return bounds;
// }

void Map::Draw() const {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            Rectangle sourceRect;

            switch (tiles[y][x].type) {
                case TILE_FLOOR: sourceRect = { 0 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE }; break;
                case TILE_WALL:  sourceRect = { 1 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE }; break;
                case TILE_GRASS: sourceRect = { 2 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE }; break;
                case TILE_WATER: sourceRect = { 3 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE }; break;
                default:         sourceRect = { 0, 0, TILE_SIZE, TILE_SIZE }; break;
            }

            Rectangle destRect = {
                x * TILE_SIZE * scale,
                y * TILE_SIZE * scale,
                TILE_SIZE * scale,
                TILE_SIZE * scale
            };

            DrawTexturePro(tileset, sourceRect, destRect, {0, 0}, 0.0f, WHITE);
            #ifndef RELEASE_BUILD
            if(debug)
            DrawRectangleLines(
                (int)(x * TILE_SIZE * scale), 
                (int)(y * TILE_SIZE * scale), 
                (int)(TILE_SIZE * scale), 
                (int)(TILE_SIZE * scale), 
                DARKGREEN
            );
            #endif
        }
    }

    // // --- Draw trees ---
    // for (const Tree& tree : trees) {
    //     Rectangle dest = {
    //         tree.position.x * TILE_SIZE * scale,
    //         tree.position.y * TILE_SIZE * scale,
    //         tree.srcRect.width * (scale / 2),   // adjust scale as needed
    //         tree.srcRect.height * (scale / 2)
    //     };

    //     DrawTexturePro(treeTexture, tree.srcRect, dest, {0, 0}, 0.0f, WHITE);
    //     #ifndef RELEASE_BUILD
    //     if(debug)
    //     DrawRectangleLines(
    //         (int)(tree.position.x * TILE_SIZE * scale), 
    //         (int)(tree.position.y * TILE_SIZE * scale), 
    //         (int)(TILE_SIZE * scale *2), 
    //         (int)(TILE_SIZE * scale*2), 
    //         YELLOW
    //     );
    //     #endif
    // }
}

void Map::LoadAssets() {
    Load("assets/tileset.png");
    // LoadTree("assets/tree.png");
    GenerateRandom();
    // PlaceTree(9, 3, 0, 0);
    // PlaceTree(6, 0, 0, 0);
    // PlaceTree(1, 5, 0, 0);
}
