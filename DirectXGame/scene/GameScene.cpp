#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>
#include "AxisIndicator.h"

GameScene::GameScene() {}

GameScene::~GameScene() { 
	 }

void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();
	// ファイル名を指定してテクスチャを読み込む
	textureHandle_ = TextureManager::Load("./Resources/mario.jpg");
	viewProjection_.translation_ = {0, 3, -50};
	// ビュープロジェクションの初期化
	viewProjection_.Initialize();

	// 3Dモデルの生成
	modelFighterBody_.reset(Model::CreateFromOBJ("float_Body", true));
	modelFighterHead_.reset(Model::CreateFromOBJ("float_Head", true));
	modelFighterL_arm_.reset(Model::CreateFromOBJ("float_L_arm", true));
	modelFighterR_arm_.reset(Model::CreateFromOBJ("float_R_arm", true));
	modelEnemy_.reset(Model::CreateFromOBJ("needle_Body", true));
	// 自キャラの生成
	player_ = std::make_unique<Player>();
	// 自キャラの初期化
	player_->Initialize(
		modelFighterBody_.get(), modelFighterHead_.get(),
		modelFighterL_arm_.get(),modelFighterR_arm_.get());

	

	// 天球の3Dモデル
	modelSkydome_.reset (Model::CreateFromOBJ("skydome", true));
	// 天球の生成
	skydome_ = std::make_unique<Skydome>();
	// 天球の初期化
	skydome_->Initialize(modelSkydome_.get());

	// 地面の3Dモデル
	modelGround_.reset(Model::CreateFromOBJ("ground", true));
	// 地面の生成
	ground_ = std::make_unique<Ground>();
	// 地面の初期化
	ground_->Initialize(modelGround_.get());

	// デバッグカメラ
	debugCamera_ = std::make_unique<DebugCamera>(WinApp::kWindowWidth, WinApp::kWindowHeight);
	debugCamera_->SetFarZ(2000.0f);

	// 追従カメラ
	followCamera_ = std::make_unique<FollowCamera>();
	followCamera_->Initialize();

	// 自キャラのワールドトランスフォームを追従カメラにセット
	followCamera_->SetTarget(&player_->GetWorldTransform());

	// 敵の生成
	enemy_ = std::make_unique<Enemy>();
	enemy_->Initialize(modelEnemy_.get());
	
	// タイトル背景
	textureHandleTitle_ = TextureManager::Load("title.png");
	spriteTitle_.reset(Sprite::Create(textureHandleTitle_, {0, 0}));

	// キー
	textureHandleKey_ = TextureManager::Load("enter.png");
	spriteKey_.reset(Sprite::Create(textureHandleKey_, {400, 500}));

	// タイトルの生成
	title_ = std::make_unique<Title>();
	title_->Initialize(
	    spriteTitle_.get(), textureHandleTitle_, spriteKey_.get(), textureHandleKey_);

	// 軸方向表示の表示を有効にする
	//AxisIndicator::GetInstance()->SetVisible(true);
	// 軸方向表示が参照するビュープロジェクションを指定する（アドレス渡し）
	//AxisIndicator::GetInstance()->SetTargetViewProjection(&debugCamera_->GetViewProjection());

}

void GameScene::Update() {
	switch (sceneMode_) {
	case 0:
		// 自キャラの更新
		player_->Update();

		skydome_->Update();

		ground_->Update();

		enemy_->Update();

		followCamera_->Update();

		// 追従カメラのびゅ0行列をゲームシーンのビュープロジェクションにコピー
		viewProjection_.matView = followCamera_->GetViewProjection().matView;

		// 追従カメラのプロジェクション行列をゲームシーンのビュープロジェクションにコピー
		viewProjection_.matProjection = followCamera_->GetViewProjection().matProjection;

		// ゲームシーンのビュープロジェクション行列の転送処理
		viewProjection_.TransferMatrix();

		// 衝突判定
		if (enemy_->GetY() == 0) {
			float dx = abs(player_->GetX() - enemy_->GetX());
			float dz = abs(player_->GetZ() - enemy_->GetZ());
			if (dx < 2 && dz < 2) {
				enemy_->Hit();
			}
		}
		break;
	case 1:
		if (title_->Update() == true) {
			sceneMode_ = 0u;
		}
		break;
	}
}

void GameScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);
	switch (sceneMode_) {
	case 0:
		// 自キャラの描画
		player_->Draw(viewProjection_);

		skydome_->Draw(viewProjection_);

		ground_->Draw(viewProjection_);

		enemy_->Draw(viewProjection_);
		break;
	}
	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>

	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

		switch (sceneMode_) {
	case 1:
		title_->Draw();
		break;
	}
	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}
