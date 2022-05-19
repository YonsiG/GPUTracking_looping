#define _ZZZANA_C_
#include "ZZZAna.h"
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include "TMath.h"
#include "TH1D.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "TLorentzVector.h"
#include "Math/LorentzVector.h"
#include "Math/Point3D.h"
#include "Math/VectorUtil.h"
#include "TH3F.h"
#include <TRandom3.h>
#include "TMinuit.h"
#include <TApplication.h>
#include <TEnv.h>
#include <TComplex.h>
#include <TGraph.h>
#include <TProfile.h>
#include <TProfile2D.h>
#include <TTree.h>

using namespace std;
void ZZZAna::Loop(const char* typeName)
{
 if(isRead == false || fChain == 0)
 {
  cout<<"This file contains no events, skip to next file"<<endl;
  return;
 }

 Int_t Nentries = fChain->GetEntries();

/*****************************************/
/*********Main Looping Code Start*********/
/*****************************************/

 for(int iLoop=0; iLoop<Nentries; iLoop++)
  {
   fChain->GetEntry(iLoop);
   Sta_TotalNumber++;

/**************plot filling****************/
   myHists->pT5_occupancies->Fill(pT5_occupancies);
   myHists->pT3_occupancies->Fill(pT3_occupancies);
   myHists->tc_occupancies->Fill(tc_occupancies);

   int category_number;
   int eta_number;

   int sum_md_occupancies=0;
   int sum_sg_occupancies=0;
   int sum_t3_occupancies=0;
   int sum_t5_occupancies=0;
   for (int i=0;i<md_occupancies->size()-1;i++)
   {
      if (module_layers->at(i)<=3 && module_subdets->at(i)==5) category_number = 0;
      if (module_layers->at(i)>=4 && module_subdets->at(i)==5) category_number = 1;
      if (module_layers->at(i)<=2 && module_subdets->at(i)==4 && module_rings->at(i)>=11) category_number = 2;
      if (module_layers->at(i)>=3 && module_subdets->at(i)==4 && module_rings->at(i)>=8) category_number = 2;
      if (module_layers->at(i)<=2 && module_subdets->at(i)==4 && module_rings->at(i)<=10) category_number = 3;
      if (module_layers->at(i)>=3 && module_subdets->at(i)==4 && module_rings->at(i)<=7) category_number = 3;
//      if (module_layers->at(i)==4 && module_subdets->at(i)==5) category_number = 4;
//      if (module_layers->at(i)==5 && module_subdets->at(i)==5) category_number = 5;
//      if (module_layers->at(i)==6 && module_subdets->at(i)==5) category_number = 6;

      if (abs(module_eta->at(i))<0.75) eta_number=0;
      if (abs(module_eta->at(i))>0.75 && abs(module_eta->at(i))<1.5) eta_number=1;
      if (abs(module_eta->at(i))>1.5 && abs(module_eta->at(i))<2.25) eta_number=2;
      if (abs(module_eta->at(i))>2.25 && abs(module_eta->at(i))<3) eta_number=3;
      
      myHists->md_occupancies_module_by_eta[category_number][eta_number]->Fill(md_occupancies->at(i));
      myHists->sg_occupancies_module_by_eta[category_number][eta_number]->Fill(sg_occupancies->at(i));
      myHists->t3_occupancies_module_by_eta[category_number][eta_number]->Fill(t3_occupancies->at(i));
      myHists->t5_occupancies_module_by_eta[category_number][eta_number]->Fill(t5_occupancies->at(i));  

      if (max_md_occupancies_module < md_occupancies->at(i)) max_md_occupancies_module = md_occupancies->at(i);
      sum_md_occupancies = sum_md_occupancies + md_occupancies->at(i);
      myHists->md_occupancies_module->Fill(md_occupancies->at(i));

      if (max_sg_occupancies_module < sg_occupancies->at(i)) max_sg_occupancies_module = sg_occupancies->at(i);
      sum_sg_occupancies = sum_sg_occupancies + sg_occupancies->at(i);
      myHists->sg_occupancies_module->Fill(sg_occupancies->at(i));

      if (max_t3_occupancies_module < t3_occupancies->at(i)) max_t3_occupancies_module = t3_occupancies->at(i);
      sum_t3_occupancies = sum_t3_occupancies + t3_occupancies->at(i);
      myHists->t3_occupancies_module->Fill(t3_occupancies->at(i));

      if (max_t5_occupancies_module < t5_occupancies->at(i)) max_t5_occupancies_module = t5_occupancies->at(i);
      sum_t5_occupancies = sum_t5_occupancies + t5_occupancies->at(i);
      myHists->t5_occupancies_module->Fill(t5_occupancies->at(i));
   }

   myHists->md_occupancies_event->Fill(sum_md_occupancies);
   myHists->sg_occupancies_event->Fill(sum_sg_occupancies);
   myHists->t3_occupancies_event->Fill(sum_t3_occupancies);
   myHists->t5_occupancies_event->Fill(sum_t5_occupancies);

   int sum_t4_occupancies=0;
   for (int i=0;i<t4_occupancies->size();i++)
   {
      sum_t4_occupancies+=t4_occupancies->at(i);
      myHists->t4_occupancies_module->Fill(t4_occupancies->at(i));
   }
   myHists->t4_occupancies_event->Fill(sum_t4_occupancies);

  }//main looping
}//ZZZAna::loop ends
