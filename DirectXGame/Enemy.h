#pragma once
#include "Model.h"
#include "WorldTransform.h"
#include "MathUtilityForText.h"
class Enemy {
public:
	void Initialize(Model* model);

	void Update();

	void Draw(ViewProjection& viewProjection_);

	// 座標の獲得
	float GetX() { return worldTransform_.matWorld_.m[3][0]; }
	float GetY() { return worldTransform_.matWorld_.m[3][1]; }
	float GetZ() { return worldTransform_.matWorld_.m[3][2]; }

	// 衝突処理
	void Hit();

private:
	// ワールド変換データ
	WorldTransform worldTransform_;
	// モデル
	Model* modelSkydome_ = nullptr;

	// ジャンプ
	bool jumpFlag_ = false;
	float jumpSpeed_ = 0;
};