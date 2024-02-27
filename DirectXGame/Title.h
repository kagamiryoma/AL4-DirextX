#pragma once
#include "Sprite.h"
#include "Input.h"

class Title {
public:
	void Initialize(Sprite* sprite, uint32_t textureHandle, Sprite* spriteKey, uint32_t textureHandleKey);

	bool Update();

	void Draw();

private:
	// 背景
	uint32_t textureHandle_ = 0u;
	Sprite* sprite_;
	// 
	uint32_t textureHandleKey_ = 0u;
	Sprite* spriteKey_;

	Input* input_ = nullptr;
	
	uint32_t timer_ = 0;
};