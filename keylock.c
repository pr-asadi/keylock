#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>

int main(void)
{
	Display *xdisplay = XOpenDisplay(NULL);
	if (xdisplay == NULL) {
		fprintf(stderr, "%s\n", "Failed to open X display");
		exit(1);
	}

	Window root_win = DefaultRootWindow(xdisplay);

	int rc = 1;
	rc = XGrabKeyboard(xdisplay, root_win, False, GrabModeAsync, GrabModeAsync, CurrentTime);
	if (rc != GrabSuccess) {
		perror("XGrabKeyboard");
		return (EXIT_FAILURE);
	}
	rc = XGrabPointer(xdisplay, root_win, False, ButtonPressMask, GrabModeAsync, GrabModeAsync, None, None, CurrentTime);
	if (rc != GrabSuccess) {
		perror("XGrabPointer");
		return (EXIT_FAILURE);
	}

	KeySym quit_key = XK_u;
	XEvent event;
	unsigned int cntrl_mask = ControlMask;
	unsigned int alt_mask = Mod1Mask;

	for (;;) {
		XNextEvent(xdisplay, &event);

		if (event.type == KeyPress) {
			if (event.xkey.keycode ==  XKeysymToKeycode(xdisplay, quit_key) && 
			event.xkey.state & cntrl_mask &&
			event.xkey.state & alt_mask) {

				break;

			} else {

				continue;
			}
		} 

		/* You could quit/unlock with mouse/mice as well.
		 * Uncomment the following lines and re-compile.
		 * The unlock/quit sequence with mouse/mice is a quick left-click then right-click.
		 * It needs to be really quick.
		 */
		 
		/* else if (event.type == ButtonPress) {
			if (event.xbutton.state & Button1Mask) {

				break;
			} else {

				continue;
			}
		} */
	}

	XCloseDisplay(xdisplay);
	return (EXIT_SUCCESS);
}
