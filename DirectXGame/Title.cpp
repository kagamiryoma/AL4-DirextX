#include "Title.h"
#include <cassert>

void Title::Initialize(Sprite* sprite, uint32_t textureHandle) {
	// NULLポインタチェック
	assert(sprite);

	// 引数として受け取ったデータをメンバ変数に記録する
	sprite_ = sprite;
	textureHandle_ = textureHandle;

	input_ = Input::GetInstance();
}

bool Title::Update() { 
	if (input_->TriggerKey(DIK_RETURN)) {
		return true;
	}
	return false;
}

void Title::Draw() { 
	sprite_->Draw();
}
