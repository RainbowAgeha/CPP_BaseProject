#include "GameMain.h"
#include "GameSceneMain.h"
#include "Game1Scene.h"

#include "Player.h"

//�O����`
extern int Input, EdgeInput;

// �V�[���J�n�O�̏��������s��
BOOL initGame1Scene(void) {

	//�v���C���[�𐶐�
	new Player();
	
	return TRUE;
}

//	�t���[������
void moveGame1Scene() {

	//�f�o�b�N�{�^��
	if ((EdgeInput & PAD_INPUT_1)) {
		changeScene(SCENE_MENU);
	}

	//�v���C���[�����Ȃ��Ȃ�����^�C�g���ɖ߂��
	if (GameObjectList::instance()->getObjectNum(PLAYER_LAYER) == 0) {
		changeScene(SCENE_MENU);
	}

	//�I�u�W�F�N�g�ɓo�^����Ă���I�u�W�F�N�g�S��������
	GameObjectList::instance()->moveAll();

}


//	�����_�����O����
void renderGame1Scene(void){

	DrawString(30, 50, "�Q�[����ʂP�ł�", GetColor(255, 255, 255));
	DrawString(30, 100, "�{�^���P�Ń^�C�g���ɖ߂�", GetColor(255, 255, 255));


	//�I�u�W�F�N�g�ɓo�^����Ă���I�u�W�F�N�g�S���\������
	GameObjectList::instance()->renderAll();

}

//	�V�[���I�����̌㏈��
void releaseGame1Scene(void) {

	//�g���Ă����I�u�W�F�N�g��S�폜����
	GameObjectList::instance()->destruct();

}

// ���蔻��R�[���o�b�N �@�@�@�����ł͗v�f���폜���Ȃ����ƁI�I
void  Game1SceneCollideCallback(int nSrc, int nTarget, int nCollideID) {

}
