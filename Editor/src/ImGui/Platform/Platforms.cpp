#include "Platforms.h"

#if PLATFORM_WINDOWS
#include <windows.h>

namespace Platform {
    float GetImGuiDpiScale()
    {
        // Retrieve DPI from the main screen
        HDC hdc = GetDC(NULL);
        int dpi = GetDeviceCaps(hdc, LOGPIXELSX);
        ReleaseDC(NULL, hdc);

        // ImGui uses a default scale of 96 DPI. Adjust the scale factor accordingly.
        float defaultDpi = 96.0f;
        float scale = static_cast<float>(dpi) / defaultDpi;

        return scale;
    }
}

#elif PLATFORM_LINUX
#include <X11/Xlib.h>

namespace Platform
    float GetImGuiDpiScale()
    {
        Display* display = XOpenDisplay(NULL);

        if (!display) {
            // Handle error, e.g., return a default scale factor
            return 1.0f;
        }

        // Get the root window of the default screen
        Window root = DefaultRootWindow(display);

        // Get the width and height of the default screen in millimeters
        int widthMM = DisplayWidthMM(display, DefaultScreen(display));
        int heightMM = DisplayHeightMM(display, DefaultScreen(display));

        // Calculate DPI based on a reference DPI (e.g., 96)
        float dpi = 96.0f * static_cast<float>(WidthOfScreen(ScreenOfDisplay(display, DefaultScreen(display)))) / widthMM;

        // Close the display
        XCloseDisplay(display);

        // Return the calculated DPI scale factor
        return dpi / 96.0f;
    }
}

#endif



