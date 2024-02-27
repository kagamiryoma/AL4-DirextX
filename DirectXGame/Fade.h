#pragma once
#include "Sprite.h"

class Fade {
public:
	void Initialize(Sprite* sprite, uint32_t textureHandle);

	void Update();

	void Draw();

	void FadeInStart();
	void FadeOutStart();

	bool IsEnd() { return endFlag_; }

private:
	// 背景
	uint32_t textureHandle_ = 0u;
	Sprite* sprite_;

	float timer_ = 1.0f;

	// フェードモード（１ : フェードイン、 ２ : フェードアウト）
	uint32_t mode_ = 1u;

	bool endFlag_ = false;
};