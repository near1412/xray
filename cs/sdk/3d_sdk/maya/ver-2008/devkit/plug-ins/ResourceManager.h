//-
// ==========================================================================
// Copyright (C) 2005 ATI Technologies Inc. All rights reserved.
//
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
#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <vector>

#include "glExtensions.h"

//this class is a static place holder for now, it may need to be a singleton
//Presently it only manages the destruction of resources, it should also
//manage a resource pool, so that shader nodes can share texture instances.
class ResourceManager {
  public:

    //these mark GL objects for deletion, since a context might not be available
    static void destroyTexture( GLuint tex);
    static void destroyAsmProgram( GLuint prog);
    static void destroyProgram( GLuint prog);
    static void destroyShader( GLuint shad);

    //clean up the resources we have been unable to previously
    static void recover();

  private:

    static std::vector<GLuint> sTextureList;
    static std::vector<GLuint> sAsmProgramList;
    static std::vector<GLuint> sProgramList;
    static std::vector<GLuint> sShaderList;

    //prevent construction
    ResourceManager() {};
};



#endif //RESOURCE_MANAGER_H

