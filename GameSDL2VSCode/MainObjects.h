#ifndef MAIN_OBJECTS_H_
#define MAIN_OBJECTS_H_

#include "CommonFunctions.h"
#include "BaseObjects.h"
#include "BulletObjects.h"
#include <vector>

#define GRAVITY_SPEED 0.8
#define MAX_FALL_SPEED 10
#define PLAYER_SPEED 10
#define PLAYER_HIGHT_VAL 18
#define PLAYER_JUMP_VAL 18

class MainObject : public BaseObject
{
public:
	MainObject();
	~MainObject();


	enum WalkType
	{
		WALK_NONE = 0,
		WALK_RIGHT = 0,
		WALK_LEFT = 1,
	};

	void set_clips();
	bool LoadImg(std::string path, SDL_Renderer* screen);
	void Show(SDL_Renderer* des);
	void HandleInputAction(SDL_Event events, SDL_Renderer* screen); 
	void SetMapXY(const int map_x, const int map_y) {map_x_ = map_x, map_y_ = map_y;};
	void DoPlayer(Map& g_map);

	void CenterEntityOnMap(Map& g_map);
	void CheckToMap(Map& g_map);

	void set_bullet_list(std::vector<BulletObject*> bullet_list)
	{
		p_bullet_list_ = bullet_list;
	}
	std::vector<BulletObject*> get_bullet_list() const {return p_bullet_list_;}

	void HandleBullet(SDL_Renderer* des);
	void RemoveBullet(const int& idx);

	int get_frame_width() const {return width_frame_;}
	int get_frame_height() const {return height_frame_;}
	void set_think_time(const int& think_time) {think_time_ = think_time;}
	SDL_Rect GetRectFrame();
	void UpdateImagePlayer(SDL_Renderer* des);
	void IncreaseMoney();
	int GetMoneyCount() const { return money_count_; };

private:
	int money_count_;
	std::vector<BulletObject*> p_bullet_list_;
	float x_val_;
	float y_val_;
	float x_pos_;
	float y_pos_;

	int width_frame_;
	int height_frame_;

	SDL_Rect frame_clip_[8];
	Input input_type_;
	int frame_;
	int status_;
	bool on_ground_;

	int map_x_;
	int map_y_;

	int think_time_;
};


#endif