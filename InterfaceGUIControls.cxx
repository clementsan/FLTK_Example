#include "InterfaceGUIControls.h"

InterfaceGUIControls::InterfaceGUIControls(int x, int y, int w, int h, const char *label)
: InterfaceGUI(x,y,w,h,label)
{
  g_MainWindow->show();

  m_EMSRelease = 1.5;
  m_QCPic = 0;
  m_QCMontage = 0;

  m_DataDirectory = new char [512];
  m_ReferenceImage = new char [512];
  m_SegmentationAtlasDirectory = new char [512];
}


InterfaceGUIControls::~InterfaceGUIControls()
{
  delete m_DataDirectory;
  delete m_ReferenceImage;
  delete m_SegmentationAtlasDirectory;
}


void InterfaceGUIControls::OpenFileButtonPressed()
{
  //display the file chooser interface
  Fl_File_Chooser fc(".","*",Fl_File_Chooser::SINGLE,"Load a file");
  fc.show();
  
  while (fc.shown())
    Fl::wait();
  
  //if a name has been set
  if (fc.count())
  {  
    //The name is displayed
    std::cout<<"Open File: "<<fc.value()<<std::endl;      
  }
}

void InterfaceGUIControls::SelectDataDirectoryGUI()
{
  Fl_File_Chooser fc(".","*",Fl_File_Chooser::DIRECTORY,"Set the general data directory");
  fc.show();
  
  while(fc.shown())
    Fl::wait();  

  //if a name has been set
  if(fc.count())
  {
    strcpy (m_DataDirectory,fc.value());
    g_DataDirectoryDisp->value(fc.value());
  }
}

void InterfaceGUIControls::SelectReferenceImageGUI()
{
  Fl_File_Chooser fc(".","*",Fl_File_Chooser::SINGLE,"Set the Reference Image");
  fc.show();
  
  while(fc.shown())
    Fl::wait();  

  //if a name has been set
  if(fc.count())
  {
    strcpy (m_ReferenceImage , fc.value());
    g_ReferenceImageDisp->value(fc.value());
  }
}

void InterfaceGUIControls::SelectSegmentationAtlasDirectoryGUI()
{
  Fl_File_Chooser fc(".","*",Fl_File_Chooser::DIRECTORY,"Set the Segmentation Atlas directory");
  fc.show();
  
  while(fc.shown())
    Fl::wait();  

  //if a name has been set
  if(fc.count())
  {
    strcpy (m_SegmentationAtlasDirectory , fc.value());
    g_SegmentationAtlasDisp->value(fc.value());
  }
}



void InterfaceGUIControls::EMS15ButtonPressed()
{
  if (g_EMS15Button->value())
  {
    m_EMSRelease = 1.5;
    g_EMS17Button->clear();
    g_MyGroup->show();
    g_MyGroup2->hide();
  }
}


void InterfaceGUIControls::EMS17ButtonPressed()
{
  if (g_EMS15Button->value())
  {
    m_EMSRelease = 1.7;
    g_EMS15Button->clear();
    g_MyGroup->hide();
    g_MyGroup2->show();
  }  
}


void InterfaceGUIControls::QCPicButtonPressed()
{
  if (g_QCPicButton->value())
    m_QCPic = 1;
  else
  {
    m_QCPic = 0;
    m_QCMontage = 0;
    g_QCMontageButton->clear();
  }
}


void InterfaceGUIControls::QCMontageButtonPressed()
{
  if (g_QCMontageButton->value())
    m_QCMontage = 1;
  else
    m_QCMontage = 0;
  
}


void InterfaceGUIControls::Compute()
{
  InterfaceGUIControls::print();
}


void InterfaceGUIControls::print()
{

  std::cout<<"Data Directory: "<<m_DataDirectory<<std::endl;
  std::cout<<"Reference Image: "<<m_ReferenceImage<<std::endl;
  std::cout<<"Segmentation Atlas Directory: "<<m_SegmentationAtlasDirectory<<std::endl;
  std::cout<<"EMSRelease: "<<m_EMSRelease<<std::endl;
  std::cout<<"QCPic: "<<m_QCPic<<std::endl;
  std::cout<<"QCMontage: "<<m_QCMontage<<std::endl;
  std::cout<<"Computation Done!"<<std::endl;
}
