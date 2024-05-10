#include "Player.h"

//�O����`
extern int Input, EdgeInput;

Player::Player() : GameObject(PLAYER_LAYER)
{
	playerImg = LoadGraph("res/xxx.png", true);
	x = y = z = 0;

	pos = VECTOR{ x , y , z };

	//�摜�̑傫���͉摜���g�̉����c���ɒ���
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

	//Object�ɏ�����͂���
	pos = VECTOR{ x , y , z };
	hitRect.ImgPos = pos;

	//�����蔻����s���B����͓G�̒e�Ƃ̔�r�A�A���Ă���ID��ENEMY_TO_SHOT
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
		//�v���C���[�ƃA�C�e������������

		break;
	case ENEMY_TO_SHOT:
		//�G�̒e�Ɠ�������

		break;
	}
}
