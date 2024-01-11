#include <string>

static bool running = true;

bool platform_create_window(int32_t width, int32_t height, std::string_view title);
void platform_update_window();

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <Windows.h>

HWND window;

LRESULT CALLBACK windows_window_callback(HWND window, UINT msg, WPARAM wParam, LPARAM lParam)
{
    LRESULT result = 0;

    switch (msg)
    {
        case WM_CLOSE:
        {
            running = false;
            break;
        }
        
        default:
        {
            result = DefWindowProc(window, msg, wParam, lParam);
        }
    }
    return result;
}

bool platform_create_window(int32_t width, int32_t height, std::string_view title)
{
    HINSTANCE instance = GetModuleHandle(0);

    WNDCLASS wc{};
    wc.hInstance = instance;
    wc.hIcon = LoadIcon(instance, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = title.data();
    wc.lpfnWndProc = windows_window_callback;

    if (!RegisterClass(&wc)) {
        return false;
    }

    int32_t dwStyle = WS_OVERLAPPEDWINDOW;

    window = CreateWindowEx(0, 
        title.data(), 
        title.data(), 
        dwStyle,
        100,
        100,
        width,
        height,
        NULL,
        NULL,
        instance,
        NULL);
    if (window == NULL) {
        return false;
    }

    ShowWindow(window, SW_SHOW);
    return true;
}

void platform_update_window()
{
    MSG msg{};

    while (PeekMessage(&msg, window, 0, 0, PM_REMOVE)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

#endif

int main()
{
    if (!platform_create_window(1024, 768, "Engine")) {
        return 1;
    }
    while (running) {
        platform_update_window();
    }
    return 0;
}