/*
 * Copyright (c) 1987, 1988, 1989, 1990, 1991 Stanford University
 * Copyright (c) 1991 Silicon Graphics, Inc.
 *
 * Permission to use, copy, modify, distribute, and sell this software and 
 * its documentation for any purpose is hereby granted without fee, provided
 * that (i) the above copyright notices and this permission notice appear in
 * all copies of the software and related documentation, and (ii) the names of
 * Stanford and Silicon Graphics may not be used in any advertising or
 * publicity relating to the software without the specific, prior written
 * permission of Stanford and Silicon Graphics.
 * 
 * THE SOFTWARE IS PROVIDED "AS-IS" AND WITHOUT WARRANTY OF ANY KIND, 
 * EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY 
 * WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.  
 *
 * IN NO EVENT SHALL STANFORD OR SILICON GRAPHICS BE LIABLE FOR
 * ANY SPECIAL, INCIDENTAL, INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY KIND,
 * OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
 * WHETHER OR NOT ADVISED OF THE POSSIBILITY OF DAMAGE, AND ON ANY THEORY OF 
 * LIABILITY, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE 
 * OF THIS SOFTWARE.
 */

/*
 * X11-dependent Raster representation.
 */

#ifndef iv_xraster_h
#define iv_xraster_h

// should be defined externally
#if !defined(__CYGWIN__)&&(!defined(__APPLE__)||__GNUC__>2)
#define XSHM
#endif

#include <InterViews/coord.h>
#include <IV-X11/Xlib.h>

#ifdef XSHM
#include <IV-X11/Xdefs.h>
#include <X11/extensions/XShm.h>
#include <IV-X11/Xundefs.h>
#endif

#include <InterViews/_enter.h>

class Display;

class RasterRep {
public:
#ifdef _DELTA_EXTENSIONS
#pragma __static_class
#endif
    Display* display_;
    boolean modified_;
    Coord left_;
    Coord bottom_;
    Coord right_;
    Coord top_;
    Coord width_;
    Coord height_;
    unsigned int pwidth_;
    unsigned int pheight_;
    XImage* image_;
    Pixmap pixmap_;
    GC gc_;
    boolean shared_memory_;

#ifdef XSHM
    static void free_shared_memory(Display&, XShmSegmentInfo&);
    static boolean init_shared_memory(
        boolean& shared_memory, Display&, XShmSegmentInfo&,  
        unsigned int pwidth, unsigned int pheight, XImage*&, Pixmap
    );
    XShmSegmentInfo shminfo_;
#endif
};

#include <InterViews/_leave.h>

#endif
