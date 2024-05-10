#include "GameMain.h"
#include "GameSceneMain.h"
#include "MenuScene.h"

//���j���[���ڂ̃V�[���ԍ��̔z��
#define MENU_MAX 3
SCENE_NO menu[MENU_MAX] = { SCENE_GAME1, SCENE_GAME2, SCENE_GAME3 };
char *menuList[3] = { "�Q�[���X�^�[�g","�����L���O","�I��" };
//�I�����ꂽ�Q�[����\�����j���[�ԍ��̏������imenu�̓Y�����j
static int selectedGame = 0;

//�O����`(GameMain.cpp�ɂĐ錾)
extern int Input, EdgeInput;

//�V�[���J�n�O�̏��������s��
BOOL initMenuScene(void) {

	SetFontSize(32);
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE_8X8);

	return TRUE;
}

//�t���[������
void moveMenuScene() {

	if ((EdgeInput & PAD_INPUT_UP)) {
		if (--selectedGame < 0) {
			selectedGame = MENU_MAX - 1;
		}
	}

	if ((EdgeInput & PAD_INPUT_DOWN)) {
		if (++selectedGame >= MENU_MAX) {
			selectedGame = 0;
		}
	}

	if ((EdgeInput & PAD_INPUT_1)) {
		changeScene(menu[selectedGame]);
	}
	
	//�I�u�W�F�N�g�ɓo�^����Ă���I�u�W�F�N�g�S��������
	GameObjectList::instance()->moveAll();
}

//�����_�����O����
void renderMenuScene(void) {

	DrawString(30, 50, "�^�C�g�����", GetColor(255, 255, 255));

	//�I�u�W�F�N�g�ɓo�^����Ă���I�u�W�F�N�g�S���\������
	GameObjectList::instance()->renderAll();

	int x = 220, y = 140, gapY = 60;
	for (int i = 0; i < MENU_MAX; i++, y += gapY) {

		if (i == selectedGame) {
			DrawString(x, y, menuList[i], GetColor(255, 0, 0));
		}
		else {
			DrawString(x, y, menuList[i], GetColor(255, 255, 255));
		}

	}
}

//�V�[���I�����̌㏈��
void releaseMenuScene(void) {

	//�g���Ă����I�u�W�F�N�g��S�폜����
	GameObjectList::instance()->destruct();
}

//���蔻��R�[���o�b�N �@�@�@�����ł͗v�f���폜���Ȃ����ƁI�I
void  MenuSceneCollideCallback(int nSrc, int nTarget, int nCollideID) {
}
