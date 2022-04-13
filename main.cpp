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

	//ウィンドウサイズ
	const int window_width = 1280;
	const int window_height = 720;

	//ウィンドウクラスの設定
	WNDCLASSEX w{};
	w.cbSize = sizeof(WNDCLASSEX);
	w.lpfnWndProc = (WNDPROC)WindowProc;
	w.lpszClassName = L"DirectXgame";
	w.hInstance = GetModuleHandle(nullptr);
	w.hCursor = LoadCursor(NULL, IDC_ARROW);

	//ウィンドウクラスをOSに登録する
	RegisterClassEx(&w);
	//ウィンドウサイズ{ X座標 Y座標 横幅 縦幅 }
	RECT wrc = { 0, 0, window_width, window_height };
	//自動でサイズを補正する
	AdjustWindowRect(&wrc, WS_OVERLAPPEDWINDOW, false);

	//ウィンドウオブジェクトの生成
	HWND hwnd = CreateWindow(w.lpszClassName,
		L"DirectXGame",         //タイトルバーの文字
		WS_OVERLAPPEDWINDOW,    //標準的なウィンドウスタイル
		CW_USEDEFAULT,          //表示X座標(OSに任せる)
		CW_USEDEFAULT,          //表示Y座標(OSに任せる)
		wrc.right - wrc.left,   //ウィンドウ横幅
		wrc.bottom - wrc.top,   //ウィンドウ縦幅
		nullptr,                //親ウィンドウハンドル
		nullptr,                //メニューハンドル
		w.hInstance,            // 呼び出しアプリケーションハンドル
		nullptr);               // オプション                          
	//ウィンドウを表示状態にする
	ShowWindow(hwnd, SW_SHOW);

	MSG msg{}; //メッセージ

	// DirectX初期化処理 ここから
	HRESULT result;
	//　DirectX初期化処理 ここまで

	//ゲームループ
	while (true) {
		// メッセージがある？
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg); // キー入力メッセージの処理
			DispatchMessage(&msg); //	プロシージャにメッセージを送る
		}

		// ボタンで終了メッセージが来たらゲームループを抜ける
		if (msg.message == WM_QUIT) {
			break;
		}
		// DirectX毎フレーム処理 ここから

		// DirectX毎フレーム処理 ここまで
	}

	// ウィンドウクラスを登録解除
	UnregisterClass(w.lpszClassName, w.hInstance);

	return 0;
}