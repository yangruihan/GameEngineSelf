#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <xcb/xcb.h>

int main(void) {
        xcb_connection_t        *pConn;
        xcb_screen_t            *pScreen;
        xcb_window_t            window;
        xcb_gcontext_t          foreground;
        xcb_gcontext_t          background;
        xcb_generic_event_t     *pEvent;
        uint32_t                mask = 0;
        uint32_t                values[2];
        uint8_t                 isQuit = 0;

        char title[] = "Hello, Engine!";
        char title_icon[] = "Hello, Engine! (iconified)";

        pConn = xcb_connect(0, 0);

        pScreen = xcb_setup_roots_iterator(xcb_get_setup(pConn)).data;

        window = pScreen->root;

        foreground = xcb_generate_id(pConn);
        mask = XCB_GC_FOREGROUND | XCB_GC_GRAPHICS_EXPOSURES;
        values[0] = pScreen->black_pixel;
        values[1] = 0;
        xcb_create_gc(pConn, foreground, window, mask, values);

        background = xcb_generate_id(pConn);
        mask = XCB_GC_BACKGROUND | XCB_GC_GRAPHICS_EXPOSURES;
        values[0] = pScreen->white_pixel;
        values[1] = 0;
        xcb_create_gc(pConn, background, window, mask, values);

        window = xcb_generate_id(pConn);
        mask = XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK;
        values[0] = pScreen->white_pixel;
        values[1] = XCB_EVENT_MASK_EXPOSURE | XCB_EVENT_MASK_KEY_PRESS;
        xcb_create_window (pConn,
                            XCB_COPY_FROM_PARENT,
                            window,
                            pScreen->root,
                            20, 20,
                            640, 480,
                            10,
                            XCB_WINDOW_CLASS_INPUT_OUTPUT,
                            pScreen->root_visual,
                            mask, values);

        xcb_change_property(pConn, XCB_PROP_MODE_REPLACE, window,
                            XCB_ATOM_WM_NAME, XCB_ATOM_STRING, 8,
                            strlen(title), title);

        xcb_change_property(pConn, XCB_PROP_MODE_REPLACE, window,
                            XCB_ATOM_WM_ICON_NAME, XCB_ATOM_STRING, 8,
                            strlen(title_icon), title_icon);

        xcb_map_window(pConn, window);

        xcb_flush(pConn);

        while((pEvent = xcb_wait_for_event(pConn)) && !isQuit) {
                switch(pEvent->response_type & ~0x80) {
                case XCB_EXPOSE:
                        break;
                case XCB_KEY_PRESS:
                        isQuit = 1;
                        break;
                }
                free(pEvent);
        }

        return 0;
}