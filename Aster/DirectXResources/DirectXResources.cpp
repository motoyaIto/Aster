//
//DirectX�̃f�o�C�X
//ito motoya
//2017.12.20
#include "DirectXResources.h"

//�ÓI�ϐ��̎���
Microsoft::WRL::ComPtr<ID3D11Device> DirectXResources::m_d3dDevice;//�f�o�C�X
Microsoft::WRL::ComPtr<ID3D11DeviceContext> DirectXResources::m_d3dContext;//�f�o�C�X�e�L�X�g
DirectXResources* DirectXResources::m_instans;
//�����֐�============================================================
/// <summary>
/// �R���X�g���N�^
/// </summary>
DirectXResources::DirectXResources()
{

}

/// <summary>
/// �R�s�[�R���X�g���N�^
/// </summary>
/// <param name="cp">�R���X�g���N�^</param>
DirectXResources::DirectXResources(const DirectXResources& cp)
{

}

/// <summary>
/// �f�X�g���N�^
/// </summary>
DirectXResources::~DirectXResources()
{

}

//public============================================================
/// <summary>
/// �ÓI�����o�̏�����
/// </summary>
/// <param name="d3dDevice">�f�o�C�X</param>
/// <param name="d3dContext">�f�o�C�X�e�L�X�g</param>
void DirectXResources::InitializeStatic(Microsoft::WRL::ComPtr<ID3D11Device> d3dDevice, Microsoft::WRL::ComPtr<ID3D11DeviceContext> d3dContext)
{
	m_d3dDevice = d3dDevice;
	m_d3dContext = d3dContext;
}

/// <summary>
/// �C���X�^���X�̎擾
/// </summary>
/// <returns>�C���X�^���X</returns>
DirectXResources* DirectXResources::GetInstans()
{
	if (m_instans == nullptr)
	{
		m_instans = new DirectXResources();
	}

	return m_instans;
}
