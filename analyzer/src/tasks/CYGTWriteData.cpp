////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// CYGTWriteData                                                              //
//                                                                            //
// Begin_Html <!--
/*-->

<!--*/
// --> End_Html
//                                                                            //
//                                                                            //
// Please note: The following information is only correct after executing     //
// the ROMEBuilder.                                                           //
//                                                                            //
// This task accesses the following folders :                                 //
//     Event                                                                  //
//     RawOutput                                                              //
//                                                                            //
//                                                                            //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

/* Generated header file containing necessary includes                        */
#include "generated/CYGTWriteDataGeneratedIncludes.h"

////////////////////////////////////////////////////////////////////////////////
/*  This header was generated by ROMEBuilder. Manual changes above the        *
 * following line will be lost next time ROMEBuilder is executed.             */
/////////////////////////////////////----///////////////////////////////////////

#include "generated/CYGAnalyzer.h"
#include "tasks/CYGTWriteData.h"
#include "generated/CYGRawOutput.h"
#include "ROMEiostream.h"

// uncomment if you want to include headers of all folders
//#include "CYGAllFolders.h"


ClassImp(CYGTWriteData)

//______________________________________________________________________________
void CYGTWriteData::Init()
{
  
}

//______________________________________________________________________________
void CYGTWriteData::BeginOfRun()
{
}

//______________________________________________________________________________
void CYGTWriteData::Event()
{

  CYGEvent *event = gAnalyzer->GetEvent();
  CYGRawOutput *output = gAnalyzer->GetRawOutput();
  
  if(event->GetCamPictureSize() > 0){


    Picture *pic = event->GetCamPictureAt(0);
    TH2F *th2 = (TH2F*)pic->GetHisto()->Clone(Form("Event%d_th2",event->GetEventTime()));
    
    Waveform *wf0 = event->GetDGTZWaveformAt(0);
    TGraph *gr0 = (TGraph*)wf0->GetGraph()->Clone(Form("Event%d_wf0",event->GetEventTime()));
    
    Waveform *wf1 = event->GetDGTZWaveformAt(1);
    TGraph *gr1 = (TGraph*)wf1->GetGraph()->Clone(Form("Event%d_wf1",event->GetEventTime()));

    ///Write to file
    output->SetCamPicture(*th2);
    output->SetPMT(*gr0);
    output->SetWF1(*gr1);
  }

}

//______________________________________________________________________________
void CYGTWriteData::EndOfRun()
{
}

//______________________________________________________________________________
void CYGTWriteData::Terminate()
{
}

