
#include "stdafx.h"
#include "BulletObjects.h"

BulletObject::BulletObject()
{
	x_val_ = 0;
	y_val_ = 0;
	is_move_ = false;
	bullet_type_ = SPHERE_BULLET1;
	//move_type_ = LINE_TYPE;
}

BulletObject::~BulletObject()
{

}

bool BulletObject::LoadImgBullet(SDL_Renderer* des)
{
	bool ret = false;
	if (bullet_type_ == SPHERE_BULLET1)
	{
		ret = LoadImg("img//player_bullet.png", des);
	}
	else if (bullet_type_ == SPHERE_BULLET2)
	{
		ret = LoadImg("img//player_bullet1.png", des);
	}
	else if (bullet_type_ == LASER_BULLET1)
	{
		ret = LoadImg("img//player_bullet2.png", des);
	}
	else if (bullet_type_ == LASER_BULLET2)
	{
		ret = LoadImg("img//player_bullet3.png", des);
	}
	return ret;
}
//BulletObject* BulletObject::Clone()
//{
//	BulletObject* p_object_clone = new BulletObject();
//	p_object_clone->bullet_dir_ = this->bullet_dir_;
//	p_object_clone->is_move_ = this->is_move_;
//	p_object_clone->move_type_ = this->move_type_;
//	p_object_clone->x_val_ = this->x_val_;
//	p_object_clone->y_val_ = this->y_val_;
//
//	return p_object_clone;
//}

void BulletObject::HandleMove(const int& x_border, const int& y_border, bool is_player /*true*/)
{	
	if (bullet_dir_ == DIR_RIGHT)
	{
		//if (move_type_ == LINE_TYPE)
		//{
			rect_.x += x_val_;
			if (rect_.x > x_border) 
			{
				is_move_ = false;
			}
		//}
		//else if (move_type_ == SIN_TYPE)
		//{
		//	rect_.x += x_val_;
		//	rect_.y += 50*cos(rect_.x);

		//	if (rect_.x > x_border) 
		//	{
		//		is_move_ = false;
		//	}
		//}
	}
	else if (bullet_dir_ == DIR_LEFT)
	{
		//if (move_type_ == LINE_TYPE)
		//{
			rect_.x -= x_val_;
			if (rect_.x < 0) 
			{
				is_move_ = false;
			}
	//	}
	else if (bullet_dir_ == DIR_UP)
	{
		rect_.y -= y_val_;
		if (rect_.y < 0) 
		{
			is_move_ = false;
		}
	}
	else if (bullet_dir_ == DIR_UP_LEFT)
	{
		rect_.x -= x_val_;
		if (rect_.x < 0) 
		{
			is_move_ = false;
		}

		rect_.y -= y_val_;
		if (rect_.y < 0) 
		{
			is_move_ = false;
		}
	}
		else if (bullet_dir_ == DIR_UP_RIGHT)
	{
		rect_.x += x_val_;
		if (rect_.x > x_border) 
		{
			is_move_ = false;
		}

		rect_.y -= y_val_;
		if (rect_.y < 0) 
		{
			is_move_ = false;
		}
	}
	//	else if (move_type_ == SIN_TYPE)
	//	{
	//		rect_.x -= x_val_;
	//		rect_.y -= 50*cos(rect_.x);

	//		if (rect_.x < 0) 
	//		{
	//			is_move_ = false;
	//		}
	//	}
	}
}


//void BulletObject::HandleMoveRightToLeft(const int& origin_x)
//{
//	if (move_type_ == LINE_TYPE)
//	{
//		rect_.x -= x_val_;
//	}
//	else if (move_type_ == SIN_TYPE)
//	{
//		rect_.x -= x_val_;
//		if (rect_.x < SCREEN_WIDTH*0.5)
//		{
//			rect_.y -= 100*cos(rect_.x);
//		}
//	}
//
//	int distance_bullet = origin_x - rect_.x;
//	if (distance_bullet > 400) 
//	{
//		is_move_ = false;
//	}
//}
//
//void BulletObject::HandleInputAction(SDL_Event events)
//{
//
//}
