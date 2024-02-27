﻿#include "Fade.h"
#include <cassert>

void Fade::Initialize(Sprite* sprite, uint32_t textureHandle) {
	// NULLポインタチェック
	assert(sprite);

	// 引数として受け取ったデータをメンバ変数に記録する
	sprite_ = sprite;
	textureHandle_ = textureHandle;
}

void Fade::Update() { 
	sprite_->SetColor({1, 1, 1, timer_});
	timer_-=0.01f; 
	if (timer_ < 0) {
		timer_ = 0;
	}
}

void Fade::Draw() {sprite_->Draw(); }

void Fade::FadeInStart() { timer_ = 1.0f; }
