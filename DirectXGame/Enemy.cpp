﻿#include "Enemy.h"
#include <cassert>

void Enemy::Initialize(Model* model) {
	// NULLポインタチェック
	assert(model);

	modelSkydome_ = model;

	worldTransform_.Initialize();

}

void Enemy::Update() { 
	// 移動
	const float speed = 0.1f;
	worldTransform_.rotation_.y += 0.01f;
	// 移動量
	Vector3 move = {0.0f, 0.0f, speed};
	// 回転行列
	Matrix4x4 matRotY = MakeRotateYMatrix(worldTransform_.rotation_.y);
	// 移動量を回転に合わせて回転させる
	move = TransformNormal(move, matRotY);
	// 移動
	worldTransform_.translation_ += move;

	// ジャンプ処理
	if (jumpFlag_ == true) {
		worldTransform_.translation_.y += jumpSpeed_;
		// 重力
		jumpSpeed_ -= 0.1f;
		//	もしもY座標が地面よりもしたいかだったら着地
		if (worldTransform_.translation_.y <= 0) {
			jumpFlag_ = false;
			worldTransform_.translation_.y = 0;
		}
	}

	// 行列を更新
	worldTransform_.UpdateMatrix();
}

void Enemy::Draw(ViewProjection& viewProjection_) {
	modelSkydome_->Draw(worldTransform_, viewProjection_);
}

void Enemy::Hit() { 
	jumpFlag_ = true;
	jumpSpeed_ = 1.0f;
}
