#ifndef __stereoCameraView_h 
#define __stereoCameraView_h 
//-
// ==========================================================================
// Copyright (C) 1995 - 2006 Autodesk, Inc. and/or its licensors.  All
// rights reserved.
//
// The coded instructions, statements, computer programs, and/or related
// material (collectively the "Data") in these files contain unpublished
// information proprietary to Autodesk, Inc. ("Autodesk") and/or its
// licensors, which is protected by U.S. and Canadian federal copyright
// law and by international treaties.
//
// The Data is provided for use exclusively by You. You have the right
// to use, modify, and incorporate this Data into other products for
// purposes authorized by the Autodesk software license agreement,
// without fee.
//
// The copyright notices in the Software and this entire statement,
// including the above license grant, this restriction and the
// following disclaimer, must be included in all copies of the
// Software, in whole or in part, and all derivative works of
// the Software, unless such copies or derivative works are solely
// in the form of machine-executable object code generated by a
// source language processor.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND.
// AUTODESK DOES NOT MAKE AND HEREBY DISCLAIMS ANY EXPRESS OR IMPLIED
// WARRANTIES INCLUDING, BUT NOT LIMITED TO, THE WARRANTIES OF
// NON-INFRINGEMENT, MERCHANTABILITY OR FITNESS FOR A PARTICULAR
// PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE, OR
// TRADE PRACTICE. IN NO EVENT WILL AUTODESK AND/OR ITS LICENSORS
// BE LIABLE FOR ANY LOST REVENUES, DATA, OR PROFITS, OR SPECIAL,
// DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES, EVEN IF AUTODESK
// AND/OR ITS LICENSORS HAS BEEN ADVISED OF THE POSSIBILITY
// OR PROBABILITY OF SUCH DAMAGES.
//
// ==========================================================================
//+

//	File Name: stereoCameraView.cpp
//	
//	Date:	Sept 26, 2006
//
//	Description:
//		A simple test of the MPx3dModelView code.
//		A view that allows multiple cameras to be added is made.
//

#include <maya/MDGModifier.h>

#include <maya/MPx3dModelView.h>
#include <maya/M3dView.h>
#include <maya/MDagPath.h>
#include <maya/MDagPathArray.h>
#include <maya/MStringArray.h>

#if defined(OSMac_MachO_)
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#endif

class MFnDependencyNode;
class MPlug;
class MDGModifier;
class MObject;
class MObjectArray;
class MSelectionList;

class stereoCameraView : public MPx3dModelView { 
public:
	stereoCameraView();
	virtual ~stereoCameraView();

	virtual MString				viewType() const;
	virtual MString				getCameraHUDName();

	virtual bool				wantStereoGLBuffer() const; 
	static void*				creator();

	enum DisplayMode { 
		kLeftCamera, 
		kRightCamera, 
		kCenterCamera,
		kStereo
	};

	void						setLeftCamera( MDagPath &camera ); 
	MDagPath					leftCamera( ) const; 

	void						setRightCamera( MDagPath &camera ); 
	MDagPath					rightCamera( ) const; 

	void						setCenterCamera( MDagPath &camera ); 
	MDagPath					centerCamera( ) const; 
	
	void						setDisplayMode( DisplayMode ); 
	DisplayMode					displayMode( ) const; 

	void						swapLeftRightBuffer( );

	void						setOverrideHUDDraw( bool ); 
	bool						overrideHUDDraw() const; 

	void						setOverrideAdornmentDraw( bool ); 
	bool						overrideAdornmentDraw( ) const; 

protected:
    virtual void				preMultipleDraw();
    virtual void				postMultipleDraw();
    virtual void				preMultipleDrawPass(unsigned index);
    virtual void				postMultipleDrawPass(unsigned index);
    virtual bool				okForMultipleDraw(const MDagPath &);
    virtual unsigned			multipleDrawPassCount();

private:
	static const char*			className();

	MDagPath					fLeftCamera; 
	MDagPath					fRightCamera;
	MDagPath					fCenterCamera; 
	MDagPath					fOldCamera;
	GLenum						fLeftBuffer; 
	GLenum						fRightBuffer; 
	bool						fValidView; 
	bool						fOverrideHUDDraw; 
	bool						fOverrideAdornmentDraw; 
		
	DisplayMode					fDisplayMode; 
};

#endif 