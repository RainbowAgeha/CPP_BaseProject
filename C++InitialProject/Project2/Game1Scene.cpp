#include "GameMain.h"
#include "GameSceneMain.h"
#include "Game1Scene.h"

#include "Player.h"

//外部定義
extern int Input, EdgeInput;

// シーン開始前の初期化を行う
BOOL initGame1Scene(void) {

	//プレイヤーを生成
	new Player();
	
	return TRUE;
}

//	フレーム処理
void moveGame1Scene() {

	//デバックボタン
	if ((EdgeInput & PAD_INPUT_1)) {
		changeScene(SCENE_MENU);
	}

	//プレイヤーがいなくなったらタイトルに戻る例
	if (GameObjectList::instance()->getObjectNum(PLAYER_LAYER) == 0) {
		changeScene(SCENE_MENU);
	}

	//オブジェクトに登録されているオブジェクト全部動かす
	GameObjectList::instance()->moveAll();

}


//	レンダリング処理
void renderGame1Scene(void){

	DrawString(30, 50, "ゲーム画面１です", GetColor(255, 255, 255));
	DrawString(30, 100, "ボタン１でタイトルに戻る", GetColor(255, 255, 255));


	//オブジェクトに登録されているオブジェクト全部表示する
	GameObjectList::instance()->renderAll();

}

//	シーン終了時の後処理
void releaseGame1Scene(void) {

	//使っていたオブジェクトを全削除する
	GameObjectList::instance()->destruct();

}

// 当り判定コールバック 　　　ここでは要素を削除しないこと！！
void  Game1SceneCollideCallback(int nSrc, int nTarget, int nCollideID) {

}
