﻿#include "Title.h"
#include <cassert>

void Title::Initialize(
    Sprite* sprite, uint32_t textureHandle, Sprite* spriteKey, uint32_t textureHandleKey) {
	// NULLポインタチェック
	assert(sprite);

	// 引数として受け取ったデータをメンバ変数に記録する
	sprite_ = sprite;
	textureHandle_ = textureHandle;
	spriteKey_ = spriteKey;
	textureHandleKey_ = textureHandleKey;

	input_ = Input::GetInstance();
}

bool Title::Update() { 
	timer_++;

	if (input_->TriggerKey(DIK_RETURN)) {
		return true;
	}
	return false;
}

void Title::Draw() { 
	sprite_->Draw();
	if (timer_ % 40 < 20) {
		spriteKey_->Draw();
	}
}
