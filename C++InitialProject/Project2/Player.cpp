#include "Player.h"

//外部定義
extern int Input, EdgeInput;

Player::Player() : GameObject(PLAYER_LAYER)
{
	playerImg = LoadGraph("res/xxx.png", true);
	x = y = z = 0;

	pos = VECTOR{ x , y , z };

	//画像の大きさは画像自身の横幅縦幅に注意
	GetGraphSizeF(playerImg, &RectW, &RectH);

	hitRect.ImgPos = pos;
	hitRect.whd = VECTOR{ RectW / 2 , RectH / 2 , 1 };
}

Player::~Player()
{
	DeleteGraph(playerImg, false);
}

void Player::move()
{
	if ((Input & PAD_INPUT_UP)) {
		y -= 5;
	}

	if ((Input & PAD_INPUT_DOWN)) {
		y += 5;
	}

	if ((Input & PAD_INPUT_LEFT)) {
		x -= 5;
	}

	if ((Input & PAD_INPUT_RIGHT)) {
		x += 5;
	}

	//Objectに情報を入力する
	pos = VECTOR{ x , y , z };
	hitRect.ImgPos = pos;

	//当たり判定を行う。相手は敵の弾との比較、帰ってくるIDはENEMY_TO_SHOT
	colliderCheckAABB_2D(ENEMYSHOT_LAYER, ENEMY_TO_SHOT);
}

void Player::render()
{
	DrawGraphF(pos.x, pos.y, playerImg, true);
}

void Player::hit(GameObject* obj, int collideID)
{
	switch (collideID) {
	case PLAYER_TO_ITEM:
		//プレイヤーとアイテムが当たった

		break;
	case ENEMY_TO_SHOT:
		//敵の弾と当たった

		break;
	}
}
