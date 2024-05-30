
#ifndef GAME_MAP_H_
#define GAME_MAP_H_
#include "CommonFunction.h"
#include "BaseObject.h"


#define SCROLL_SPEED 4
#define MAX_TILES 20


class TileMat : public BaseObject
{
public:
	TileMat() {;}
	~TileMat() {;}
};

class GameMap
{
public:
	GameMap(){;}
	~GameMap(){;}
	void LoadMap(char* name);
	void DrawMap(SDL_Renderer* des);
	void LoadMapTiles(SDL_Renderer* screen);
	Map GetMap() const {return game_map_;}
	void SetMap(Map& g_map) {game_map_ = g_map;};
	Map getMap() const {return game_map_;};
private:
	Map game_map_;
	TileMat tile_mat_[MAX_TILES];
};

#endif