/* -----------------------------------------------------------------

GEM - Graphics Environment for Multimedia

Load a digital video (like AVI, Mpeg, Quicktime) into a pix block 
(OS independant parent-class)

Copyright (c) 1997-1999 Mark Danks. mark@danks.org
Copyright (c) G�nther Geiger. geiger@epy.co.at
Copyright (c) 2001-2003 IOhannes m zmoelnig. forum::f�r::uml�ute. IEM. zmoelnig@iem.kug.ac.at
For information on usage and redistribution, and for a DISCLAIMER OF ALL
WARRANTIES, see the file, "GEM.LICENSE.TERMS" in this distribution.

-----------------------------------------------------------------*/

#ifndef INCLUDE_FILMDARWIN_H_
#define INCLUDE_FILMDARWIN_H_

#if defined __APPLE__ && !defined __x86_64__
// with OSX10.6, apple has removed loads of Carbon functionality (in 64bit mode)
// LATER make this a real check in configure
# define HAVE_CARBONQUICKTIME
#endif

#include "plugins/film.h"

#ifdef HAVE_CARBONQUICKTIME
# include <Carbon/carbon.h>
# include <QuickTime/quicktime.h>
#endif /* HAVE_CARBONQUICKTIME */

/*-----------------------------------------------------------------
  -------------------------------------------------------------------
  CLASS
  filmDarwin
    
  film-loader class for MacOS-X (Darwin)
    
  KEYWORDS
  pix film movie
    
  DESCRIPTION

  -----------------------------------------------------------------*/
namespace gem { class GEM_EXTERN filmDarwin : public film {
 public:
  
  //////////
  // Constructor
  filmDarwin(int format=0);

  //////////
  // Destructor
  virtual ~filmDarwin();

  //////////
  // open a movie up
  virtual bool open(char *filename, int format=0);
  //////////
  // close the movie file
  virtual void close(void);

  //////////
  // get the next frame
  virtual pixBlock* getFrame();

  //////////
  // set the next frame to read;
  virtual int changeImage(int imgNum, int trackNum=-1);

 protected:
#ifdef HAVE_CARBONQUICKTIME
  Movie			m_movie; 
  GWorldPtr		m_srcGWorld;
  TimeValue		m_movieTime;
  Track			m_movieTrack;
  Media			m_movieMedia;
  TimeValue		m_timeScale;
  TimeValue		duration;
#endif //HAVE_CARBONQUICKTIME

  //////////
  // frame data
  unsigned char*m_frame;  /* this points to the main texture (might be black) */
  unsigned char*m_data;   /* this points always to the real data */

//  pixBlock    	m_pixBlock;
  imageStruct   m_imageStruct;
  

  int		m_xsize;
  int		m_ysize;
  int           m_csize;

  int           m_format;

  bool          m_film; // are we in film- or in movie-mode

  //////////
  // a outlet for information like #frames and "reached end"
  t_outlet     *m_outNumFrames;
  t_outlet     *m_outEnd;
  
  int m_auto;
 // int m_reqFrame;

};};

#endif	// for header file