#include "GameMain.h"
#include "GameSceneMain.h"
#include "MenuScene.h"

//メニュー項目のシーン番号の配列
#define MENU_MAX 3
SCENE_NO menu[MENU_MAX] = { SCENE_GAME1, SCENE_GAME2, SCENE_GAME3 };
char *menuList[3] = { "ゲームスタート","ランキング","終了" };
//選択されたゲームを表すメニュー番号の初期化（menuの添え字）
static int selectedGame = 0;

//外部定義(GameMain.cppにて宣言)
extern int Input, EdgeInput;

//シーン開始前の初期化を行う
BOOL initMenuScene(void) {

	SetFontSize(32);
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE_8X8);

	return TRUE;
}

//フレーム処理
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
	
	//オブジェクトに登録されているオブジェクト全部動かす
	GameObjectList::instance()->moveAll();
}

//レンダリング処理
void renderMenuScene(void) {

	DrawString(30, 50, "タイトル画面", GetColor(255, 255, 255));

	//オブジェクトに登録されているオブジェクト全部表示する
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

//シーン終了時の後処理
void releaseMenuScene(void) {

	//使っていたオブジェクトを全削除する
	GameObjectList::instance()->destruct();
}

//当り判定コールバック 　　　ここでは要素を削除しないこと！！
void  MenuSceneCollideCallback(int nSrc, int nTarget, int nCollideID) {
}
