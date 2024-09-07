

#include <X11/Xlib.h>
#include <webkit2/webkit2.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    Display *dpy;
    Window root, win;
    XEvent event;
    WebKitWebView *web_view;
    WebKitWebContext *web_context;
    WebKitSettings *settings;
    GdkWindow *gdk_window;

    // Initialize Xlib
    dpy = XOpenDisplay(NULL);
    if (!dpy) {
        fprintf(stderr, "Unable to open X display\n");
        return 1;
    }

    root = DefaultRootWindow(dpy);

    win = XCreateSimpleWindow(dpy, root, 0, 0, DisplayWidth(dpy, DefaultScreen(dpy)), DisplayHeight(dpy, DefaultScreen(dpy)), 0, BlackPixel(dpy, DefaultScreen(dpy)), WhitePixel(dpy, DefaultScreen(dpy)));
    XMapWindow(dpy, win);
    XFlush(dpy);

    // Initialize WebKit
    web_context = webkit_web_context_new();
    settings = webkit_settings_new();
    web_view = WEBKIT_WEB_VIEW(webkit_web_view_new_with_context(web_context));
    
    // Create a GdkWindow from the Xlib window
    gdk_window = gdk_window_new_for_display(gdk_display_get_default(), win, NULL);

    // Set the WebKitWebView's GdkWindow
    webkit_web_view_set_window(web_view, gdk_window);

    // Load a URL
    webkit_web_view_load_uri(web_view, "http://www.example.com");

    while (1) {
        XNextEvent(dpy, &event);
        // Handle events
    }

    XCloseDisplay(dpy);
    return 0;
}
