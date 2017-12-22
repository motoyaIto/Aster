//
//DirectXのデバイス
//ito motoya
//2017.12.20
#include "DirectXResources.h"

//静的変数の実体
Microsoft::WRL::ComPtr<ID3D11Device> DirectXResources::m_d3dDevice;//デバイス
Microsoft::WRL::ComPtr<ID3D11DeviceContext> DirectXResources::m_d3dContext;//デバイステキスト
DirectXResources* DirectXResources::m_instans;
//内部関数============================================================
/// <summary>
/// コンストラクタ
/// </summary>
DirectXResources::DirectXResources()
{

}

/// <summary>
/// コピーコンストラクタ
/// </summary>
/// <param name="cp">コンストラクタ</param>
DirectXResources::DirectXResources(const DirectXResources& cp)
{

}

/// <summary>
/// デストラクタ
/// </summary>
DirectXResources::~DirectXResources()
{

}

//public============================================================
/// <summary>
/// 静的メンバの初期化
/// </summary>
/// <param name="d3dDevice">デバイス</param>
/// <param name="d3dContext">デバイステキスト</param>
void DirectXResources::InitializeStatic(Microsoft::WRL::ComPtr<ID3D11Device> d3dDevice, Microsoft::WRL::ComPtr<ID3D11DeviceContext> d3dContext)
{
	m_d3dDevice = d3dDevice;
	m_d3dContext = d3dContext;
}

/// <summary>
/// インスタンスの取得
/// </summary>
/// <returns>インスタンス</returns>
DirectXResources* DirectXResources::GetInstans()
{
	if (m_instans == nullptr)
	{
		m_instans = new DirectXResources();
	}

	return m_instans;
}
