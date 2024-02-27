#pragma once
#include "Sprite.h"
#include "Input.h"

class Title {
public:
	void Initialize(Sprite* sprite, uint32_t textureHandle);

	bool Update();

	void Draw();

private:
	// テクスチャハンドル
	uint32_t textureHandle_ = 0u;
	// スプライト
	Sprite* sprite_;

	Input* input_ = nullptr;
};