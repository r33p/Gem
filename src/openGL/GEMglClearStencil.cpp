////////////////////////////////////////////////////////
//
// GEM - Graphics Environment for Multimedia
//
// Implementation file
//
// Copyright (c) 2002-2011 IOhannes m zmölnig. forum::für::umläute. IEM. zmoelnig@iem.at
//	zmoelnig@iem.kug.ac.at
//  For information on usage and redistribution, and for a DISCLAIMER
//  *  OF ALL WARRANTIES, see the file, "GEM.LICENSE.TERMS"
//
//  this file has been generated...
////////////////////////////////////////////////////////

#include "GEMglClearStencil.h"

CPPEXTERN_NEW_WITH_ONE_ARG ( GEMglClearStencil , t_floatarg, A_DEFFLOAT);

/////////////////////////////////////////////////////////
//
// GEMglViewport
//
/////////////////////////////////////////////////////////
// Constructor
//
GEMglClearStencil :: GEMglClearStencil	(t_floatarg arg0) :
		s(static_cast<GLint>(arg0))
{
	m_inlet[0] = inlet_new(this->x_obj, &this->x_obj->ob_pd, &s_float, gensym("s"));
}
/////////////////////////////////////////////////////////
// Destructor
//
GEMglClearStencil :: ~GEMglClearStencil () {
inlet_free(m_inlet[0]);
}

/////////////////////////////////////////////////////////
// Render
//
void GEMglClearStencil :: render(GemState *state) {
	glClearStencil (s);
}

/////////////////////////////////////////////////////////
// Variables
//
void GEMglClearStencil :: sMess (t_float arg1) {	// FUN
	s = static_cast<GLint>(arg1);
	setModified();
}


/////////////////////////////////////////////////////////
// static member functions
//

void GEMglClearStencil :: obj_setupCallback(t_class *classPtr) {
	 class_addmethod(classPtr, reinterpret_cast<t_method>(&GEMglClearStencil::sMessCallback),  	gensym("s"), A_DEFFLOAT, A_NULL);
};

void GEMglClearStencil :: sMessCallback (void* data, t_float arg0){
	GetMyClass(data)->sMess ( static_cast<t_float>(arg0));
}
