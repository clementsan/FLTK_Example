#ifndef INTERFACEGUICONTROLS_H
#define INTERFACEGUICONTROLS_H

#include <iostream>
#include <string.h>

#include "InterfaceGUI.h"

#include <FL/Fl_File_Chooser.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Group.H>


class InterfaceGUIControls : public InterfaceGUI
{
 public:
  InterfaceGUIControls(int x, int y, int w, int h, const char *label);
  ~InterfaceGUIControls();
  
  
  void OpenFileButtonPressed();
  void SelectDataDirectoryGUI();
  void SelectReferenceImageGUI();
  void SelectSegmentationAtlasDirectoryGUI();
  void EMS15ButtonPressed();
  void EMS17ButtonPressed();
  void QCPicButtonPressed();
  void QCMontageButtonPressed();
  void Compute();   
  void print();

 private:
  
  
  char *m_DataDirectory;
  char *m_ReferenceImage;
  char *m_SegmentationAtlasDirectory;
  
  float m_EMSRelease;
  bool m_QCPic;
  bool m_QCMontage;
};

#endif
