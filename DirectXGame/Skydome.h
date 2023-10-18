#pragma once
#include "WorldTransform.h"
#include "Model.h"

class Skydome {
public:
	void Initialize(Model* model);

	void Update();

	void Draw(ViewProjection& viewProjection_);

private:
	// ワールド変換データ
	WorldTransform worldTransform_;
	// モデル
	Model* modelSkydome_ = nullptr;

	ViewProjection viewprojection_;
};
