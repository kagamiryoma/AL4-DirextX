#pragma once
#include "Sprite.h"

class Fade {
public:
	void Initialize(Sprite* sprite, uint32_t textureHandle);

	void Update();

	void Draw();

	void FadeInStart();

private:
	// 背景
	uint32_t textureHandle_ = 0u;
	Sprite* sprite_;

	float timer_ = 1.0f;
};