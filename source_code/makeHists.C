#include "makeHists.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TH3F.h"
#include "TFile.h"
#include "TProfile.h"
#include "TProfile2D.h"
#include "TMath.h"
#include "TTree.h"

using namespace std;
void makeHists::createHists(const char* fileName)
{
 hf = new TFile(fileName,"RECREATE");

 pT5_occupancies = new TH1D("pT5_occupancies","pT5_occupancies",100,0,1500);
 pT3_occupancies = new TH1D("pT3_occupancies","pT3_occupancies",100,0,2000);
 tc_occupancies = new TH1D("tc_occupancies","tc_occupancies",100,0,2200);
 md_occupancies_module = new TH1D("md_occupancies_module","md_occupancies_module",100,0,100);
 md_occupancies_event = new TH1D("md_occupancies_event","md_occupancies_event",100,40000,100000);
 sg_occupancies_module = new TH1D("sg_occupancies_module","sg_occupancies_module",600,0,600);
 sg_occupancies_event = new TH1D("sg_occupancies_event","sg_occupancies_event",100,50000,200000);
 t3_occupancies_module = new TH1D("t3_occupancies_module","t3_occupancies_module",1200,0,1200);
 t3_occupancies_event = new TH1D("t3_occupancies_event","t3_occupancies_event",100,20000,120000);
 t4_occupancies_module = new TH1D("t4_occupancies_module","t4_occupancies_module",20,0,20);
 t4_occupancies_event = new TH1D("t4_occupancies_event","t4_occupancies_event",100,20000,120000);
 t5_occupancies_module = new TH1D("t5_occupancies_module","t5_occupancies_module",600,0,600);
 t5_occupancies_event = new TH1D("t5_occupancies_event","t5_occupancies_event",100,4000,10000);

 char plotname[50];
 for (int icategory = 0; icategory < 7; icategory++)
 {
   for(int ieta = 0; ieta<4; ieta++){
      sprintf(plotname, "md_occupancies_module_by_eta%i_%i", icategory, ieta);
      md_occupancies_module_by_eta[icategory][ieta] = new TH1D(plotname, plotname, 100, 0, 100);
      sprintf(plotname, "md_occupancies_module_by_r%i_%i", icategory, ieta);
      md_occupancies_module_by_r[icategory][ieta] = new TH1D(plotname, plotname, 100, 0, 100);
      sprintf(plotname, "sg_occupancies_module_by_eta%i_%i", icategory, ieta);
      sg_occupancies_module_by_eta[icategory][ieta] = new TH1D(plotname, plotname, 600, 0, 600);
      sprintf(plotname, "sg_occupancies_module_by_r%i_%i", icategory, ieta);
      sg_occupancies_module_by_r[icategory][ieta] = new TH1D(plotname, plotname, 600, 0, 600);
      sprintf(plotname, "t3_occupancies_module_by_eta%i_%i", icategory, ieta);
      t3_occupancies_module_by_eta[icategory][ieta] = new TH1D(plotname, plotname, 1200, 0, 1200);
      sprintf(plotname, "t3_occupancies_module_by_r%i_%i", icategory, ieta);
      t3_occupancies_module_by_r[icategory][ieta] = new TH1D(plotname, plotname, 1200, 0, 1200);
      sprintf(plotname, "t4_occupancies_module_by_eta%i_%i", icategory, ieta);
      t4_occupancies_module_by_eta[icategory][ieta] = new TH1D(plotname, plotname, 20, 0, 20);
      sprintf(plotname, "t4_occupancies_module_by_r%i_%i", icategory, ieta);
      t4_occupancies_module_by_r[icategory][ieta] = new TH1D(plotname, plotname, 20, 0, 20);
      sprintf(plotname, "t5_occupancies_module_by_eta%i_%i", icategory, ieta);
      t5_occupancies_module_by_eta[icategory][ieta] = new TH1D(plotname, plotname, 600, 0, 600);
      sprintf(plotname, "t5_occupancies_module_by_r%i_%i", icategory, ieta);
      t5_occupancies_module_by_r[icategory][ieta] = new TH1D(plotname, plotname, 600, 0, 600);
   }
 }

 module_layers = new TH1D("module_layers", "module_layers", 10,0,10);
 module_subdets = new TH1D("module_subdets", "module_subdets", 10,0,10);
 module_rings = new TH1D("module_rings", "module_rings", 10,0,10);
}

void makeHists::saveHists()
{
 hf->cd();
 hf->Write();
 hf->Close();
}
