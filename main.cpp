#include <Windows.h>

LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
	switch (msg) {

	case WM_DESTROY:

		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, msg, wparam, lparam);
}

int  WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	OutputDebugStringA("Hello,DirectX!!\n");

	//�E�B���h�E�T�C�Y
	const int window_width = 1280;
	const int window_height = 720;

	//�E�B���h�E�N���X�̐ݒ�
	WNDCLASSEX w{};
	w.cbSize = sizeof(WNDCLASSEX);
	w.lpfnWndProc = (WNDPROC)WindowProc;
	w.lpszClassName = L"DirectXgame";
	w.hInstance = GetModuleHandle(nullptr);
	w.hCursor = LoadCursor(NULL, IDC_ARROW);

	//�E�B���h�E�N���X��OS�ɓo�^����
	RegisterClassEx(&w);
	//�E�B���h�E�T�C�Y{ X���W Y���W ���� �c�� }
	RECT wrc = { 0, 0, window_width, window_height };
	//�����ŃT�C�Y��␳����
	AdjustWindowRect(&wrc, WS_OVERLAPPEDWINDOW, false);

	//�E�B���h�E�I�u�W�F�N�g�̐���
	HWND hwnd = CreateWindow(w.lpszClassName,
		L"DirectXGame",         //�^�C�g���o�[�̕���
		WS_OVERLAPPEDWINDOW,    //�W���I�ȃE�B���h�E�X�^�C��
		CW_USEDEFAULT,          //�\��X���W(OS�ɔC����)
		CW_USEDEFAULT,          //�\��Y���W(OS�ɔC����)
		wrc.right - wrc.left,   //�E�B���h�E����
		wrc.bottom - wrc.top,   //�E�B���h�E�c��
		nullptr,                //�e�E�B���h�E�n���h��
		nullptr,                //���j���[�n���h��
		w.hInstance,            // �Ăяo���A�v���P�[�V�����n���h��
		nullptr);               // �I�v�V����                          
	//�E�B���h�E��\����Ԃɂ���
	ShowWindow(hwnd, SW_SHOW);

	MSG msg{}; //���b�Z�[�W

	// DirectX���������� ��������
	HRESULT result;
	//�@DirectX���������� �����܂�

	//�Q�[�����[�v
	while (true) {
		// ���b�Z�[�W������H
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg); // �L�[���̓��b�Z�[�W�̏���
			DispatchMessage(&msg); //	�v���V�[�W���Ƀ��b�Z�[�W�𑗂�
		}

		// �{�^���ŏI�����b�Z�[�W��������Q�[�����[�v�𔲂���
		if (msg.message == WM_QUIT) {
			break;
		}
		// DirectX���t���[������ ��������

		// DirectX���t���[������ �����܂�
	}

	// �E�B���h�E�N���X��o�^����
	UnregisterClass(w.lpszClassName, w.hInstance);

	return 0;
}