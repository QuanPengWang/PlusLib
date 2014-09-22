/*=Plus=header=begin======================================================
  Program: Plus
  Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
  See License.txt for details.
=========================================================Plus=header=end*/

#ifndef _VTKSONIXVOLUMEREADER_H_
#define _VTKSONIXVOLUMEREADER_H_

#include "PlusConfigure.h"
#include "vtkDataCollectionExport.h"

#include "vtkImageAlgorithm.h" 

#include <vector>
#include <string>

#include "ulterius_def.h"

#if PLUS_ULTRASONIX_SDK_MAJOR_VERSION == 1
#include "utx_imaging_modes.h"
#endif

class ulterius; 
class vtkTrackedFrameList; 

/*!
  \class vtkSonixVolumeReader 
  \brief Reads a volume from file to tracked frame list
  \ingroup PlusLibDataCollection
*/ 
class vtkDataCollectionExport vtkSonixVolumeReader: public vtkImageAlgorithm
{
public:
  vtkTypeRevisionMacro(vtkSonixVolumeReader,vtkImageAlgorithm);
  static vtkSonixVolumeReader *New();
  virtual void PrintSelf(ostream& os, vtkIndent indent);

  /*! Read a volume from Ultrasonix format (.b8, .b32, .bpr, .rf) and convert it to tracked frame */
  static PlusStatus GenerateTrackedFrameFromSonixVolume(const char* volumeFileName, vtkTrackedFrameList* trackedFrameList, double acquisitionFrameRate = 10); 

protected:
  /*! Constructor */
  vtkSonixVolumeReader();
  /*! Destructor */
  ~vtkSonixVolumeReader();
private:
  vtkSonixVolumeReader(const vtkSonixVolumeReader&);
  void operator=(const vtkSonixVolumeReader&);
}; 

#endif 
