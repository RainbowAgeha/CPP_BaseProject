#pragma once
#include "GameObject.h"
class Player :
    public GameObject
{
private:
	float x, y, z;
	int playerImg;
	float RectW, RectH;
public:
	Player();
	~Player();

	virtual void move() override;
	virtual void render() override;
	virtual void hit(GameObject* obj, int collideID) override;
};

