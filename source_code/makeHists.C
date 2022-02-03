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
 md_occupancies_module = new TH1D("md_occupancies_module","md_occupancies_module",20,0,20);
 md_occupancies_event = new TH1D("md_occupancies_event","md_occupancies_event",100,40000,100000);
 sg_occupancies_module = new TH1D("sg_occupancies_module","sg_occupancies_module",20,0,20);
 sg_occupancies_event = new TH1D("sg_occupancies_event","sg_occupancies_event",100,50000,200000);
 t3_occupancies_module = new TH1D("t3_occupancies_module","t3_occupancies_module",20,0,20);
 t3_occupancies_event = new TH1D("t3_occupancies_event","t3_occupancies_event",100,20000,120000);
 t4_occupancies_module = new TH1D("t4_occupancies_module","t4_occupancies_module",20,0,20);
 t4_occupancies_event = new TH1D("t4_occupancies_event","t4_occupancies_event",100,20000,120000);
 t5_occupancies_module = new TH1D("t5_occupancies_module","t5_occupancies_module",10,0,10);
 t5_occupancies_event = new TH1D("t5_occupancies_event","t5_occupancies_event",100,4000,10000);
}

void makeHists::saveHists()
{
 hf->cd();
 hf->Write();
 hf->Close();
}
