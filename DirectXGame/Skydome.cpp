#include "Skydome.h"
#include <cassert>

void Skydome::Initialize(Model* model) {
	// NULLポインタチェック
	assert(model);

	modelSkydome_ = model;

	worldTransform_.Initialize();

	worldTransform_.scale_ = {40.0f, 40.0f, 40.0f};

	worldTransform_.translation_.z = 8.0f;
}

void Skydome::Update() { 
	worldTransform_.TransferMatrix(); 
}

void Skydome::Draw(ViewProjection& viewProjection_) {
	modelSkydome_->Draw(worldTransform_, viewProjection_);
}
