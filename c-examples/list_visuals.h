#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xatom.h>
#include <stdio.h>
#include <stdlib.h>
#include <Fl_C.h>

Display *fl_display;
int fl_screen;
const char *dname;
void fl_open_display() {
  fl_display = XOpenDisplay(dname);
  if (!fl_display) {
    fprintf(stderr,"Can't open display: %s\n",XDisplayName(dname));
    exit(1);
  }
  fl_screen = DefaultScreen(fl_display);
}

const char *ClassNames[] = {
  "StaticGray ",
  "GrayScale  ",
  "StaticColor",
  "PseudoColor",
  "TrueColor  ",
  "DirectColor"
};

// SERVER_OVERLAY_VISUALS property element:
typedef struct _OverlayInfo {
  long overlay_visual;
  long transparent_type;
  long value;
  long layer;
} OverlayInfo;

#if HAVE_XDBE
#include <X11/extensions/Xdbe.h>
#endif
static void print_mask(XVisualInfo* p) {
  int n = 0;
  int what = 0;
  int print_anything = 0;
  char buf[20];
  char *q = buf;
  *q = 0;
  int b; unsigned int m; for (b=32,m=0x80000000; ; b--,m>>=1) {
    int new_what = 0;
    if (p->red_mask&m) new_what = 'r';
    else if (p->green_mask&m) new_what = 'g';
    else if (p->blue_mask&m) new_what = 'b';
    else new_what = '?';
    if (new_what != what) {
      if (what && (what != '?' || print_anything)) {
	q += sprintf(q,"%d%c", n, what);
	print_anything = 1;
      }
      what = new_what;
      n = 1;
    } else {
      n++;
    }
    if (!b) break;
  }
  printf("%7s", buf);
}

void list_visuals() {
  fl_open_display();
  XVisualInfo vTemplate;
  int num;
  XVisualInfo *visualList = XGetVisualInfo(fl_display,0,&vTemplate,&num);

  XPixmapFormatValues *pfvlist;
  static int numpfv;
  pfvlist = XListPixmapFormats(fl_display, &numpfv);

  OverlayInfo *overlayInfo = 0;
  int numoverlayinfo = 0;
  Atom overlayVisualsAtom = XInternAtom(fl_display,"SERVER_OVERLAY_VISUALS",1);
  if (overlayVisualsAtom) {
    unsigned long sizeData, bytesLeft;
    Atom actualType;
    int actualFormat;
    if (!XGetWindowProperty(fl_display, RootWindow(fl_display, fl_screen),
			   overlayVisualsAtom, 0L, 10000L, False,
			   overlayVisualsAtom, &actualType, &actualFormat,
			   &sizeData, &bytesLeft,
			   (unsigned char **) &overlayInfo))
      numoverlayinfo = (int)(sizeData/4);
  }

#if HAVE_XDBE
  int event_base, error_base;
  int numdouble = 0;
  XdbeVisualInfo *dbe = 0;
  if (XdbeQueryExtension(fl_display, &event_base, &error_base)) {
    Drawable root = RootWindow(fl_display,fl_screen);
    int numscreens = 1;
    XdbeScreenVisualInfo *a = XdbeGetVisualInfo(fl_display,&root,&numscreens);
    if (!a) printf("error getting double buffer visuals\n");
    else {
      dbe = a->visinfo;
      numdouble = a->count;
    }
  }
#endif

  int i = 0;
  for (; i<num; i++) {
    XVisualInfo *p = visualList+i;

    XPixmapFormatValues *pfv;
    for (pfv = pfvlist; ; pfv++) {
      if (pfv >= pfvlist+numpfv) {pfv = 0; break;} // should not happen!
      if (pfv->depth == p->depth) break;
    }

    int j = pfv ? pfv->bits_per_pixel : 0;
    printf(" %2ld: %s %2d/%d", p->visualid, ClassNames[p->class],
	   p->depth, j);
    if (j < 10) putchar(' ');

    print_mask(p);

    for (j=0; j<numoverlayinfo; j++) {
      OverlayInfo *o = &overlayInfo[j];
      if (o->overlay_visual == (long)(p->visualid)) {
	printf(" overlay(");
	if (o->transparent_type==1) printf("transparent pixel %ld, ",o->value);
	else if (o->transparent_type==2) printf("transparent mask %ld, ",o->value);
	else printf("opaque, ");
	printf("layer %ld)", o->layer);
      }
    }
#if HAVE_XDBE
    for (j = 0; j < numdouble; j++) if (dbe[j].visual == p->visualid)
      printf(" doublebuf(perflevel %d)",dbe[j].perflevel);
#endif

    if (p->visualid==XVisualIDFromVisual(DefaultVisual(fl_display,fl_screen)))
      printf(" (default visual)");

    putchar('\n');
  }
}
