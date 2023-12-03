#include "Platforms.h"

#if PLATFORM_WINDOWS
#include <windows.h>

namespace Platform {
    float GetImGuiDpiScale()
    {
        HDC hdc = GetDC(NULL);
        int dpi = GetDeviceCaps(hdc, LOGPIXELSX);
        ReleaseDC(NULL, hdc);

        float defaultDpi = 96.0f;
        float scale = static_cast<float>(dpi) / defaultDpi;

        return scale;
    }
}

#elif PLATFORM_LINUX
#include <X11/Xlib.h>

namespace Platform {
    float GetImGuiDpiScale()
    {
        Display* display = XOpenDisplay(NULL);

        if (!display) {
            return 1.0f;
        }

        Window root = DefaultRootWindow(display);

        int widthMM = DisplayWidthMM(display, DefaultScreen(display));
        int heightMM = DisplayHeightMM(display, DefaultScreen(display));

        float dpi = 96.0f * static_cast<float>(WidthOfScreen(ScreenOfDisplay(display, DefaultScreen(display)))) / widthMM;

        XCloseDisplay(display);

        return dpi / 96.0f;
    }
}

#endif



