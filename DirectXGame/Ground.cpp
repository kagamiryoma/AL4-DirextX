#include "Ground.h"
#include <cassert>

void Ground::Initialize(Model* model) {
	// NULLポインタチェック
	assert(model);

	modelGround_ = model;

	worldTransform_.Initialize();

	
}

void Ground::Update() { 
	worldTransform_.TransferMatrix();
}

void Ground::Draw(ViewProjection& viewProjection_) {
	modelGround_->Draw(worldTransform_, viewProjection_);
}