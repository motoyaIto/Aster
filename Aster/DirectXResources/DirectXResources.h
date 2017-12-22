//
//DirectX�̃f�o�C�X
//ito motoya
//2017.12.20
#pragma once

#include <d3d11_1.h>
#include <wrl/client.h>

class DirectXResources
{
private:

private://�ÓI�ϐ�
	friend class Obj3D;
	static DirectXResources* m_instans;

	static Microsoft::WRL::ComPtr<ID3D11Device> m_d3dDevice;//�f�o�C�X
	static Microsoft::WRL::ComPtr<ID3D11DeviceContext> m_d3dContext;//�f�o�C�X�e�L�X�g

private://�����֐�
	DirectXResources();
	DirectXResources(const DirectXResources& cp);
	~DirectXResources();

public:
	static void InitializeStatic(static Microsoft::WRL::ComPtr<ID3D11Device> d3dDevice
									, static Microsoft::WRL::ComPtr<ID3D11DeviceContext> d3dContext);
	
	static DirectXResources* GetInstans();
};