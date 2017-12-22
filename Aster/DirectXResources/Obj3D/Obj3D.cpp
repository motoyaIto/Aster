//
//3Dオブジェクト
//ito motoya
//2017.12.20
#include "Obj3D.h"

#include "..//DirectXResources.h"

Obj3D::Obj3D()
	: m_world(Matrix::Identity)
	, m_view(Matrix::Identity)
	, m_proj(Matrix::Identity)
{
	//エフェクトファクトリの作成
	m_EffectFactory = std::make_unique<DirectX::EffectFactory>(DirectXResources::m_d3dDevice.Get());
	
	//テクスチャパス
	m_EffectFactory->SetDirectory(L"Resources");

	//汎用描画ステート
	m_states = std::make_unique<DirectX::CommonStates>(DirectXResources::m_d3dDevice.Get());
}

Obj3D::~Obj3D()
{
}

void Obj3D::Initialize()
{
	
}

void Obj3D::UpdateO()
{

}

void Obj3D::Render()
{
	if (m_model)
	{
		m_model->Draw(DirectXResources::m_d3dContext.Get(), *m_states, m_world, m_view, m_proj);
	}
}

/// <summary>
/// モデル読み込み
/// </summary>
/// <param name="fileName">モデル名</param>
void Obj3D::LoadModel(const wchar_t * fileName)
{
	m_model = DirectX::Model::CreateFromCMO(DirectXResources::m_d3dDevice.Get(), fileName, *m_EffectFactory);
}
