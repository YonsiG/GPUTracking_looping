#ifndef _ZZZANA_H_
#define _ZZZANA_H_

#include "makeHists.h"
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TMath.h>
#include <TH1F.h>
#include <TH1D.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLorentzVector.h>
#include <TH3F.h>
#include <TRandom3.h>
#include <TMinuit.h>
#include <TApplication.h>
#include <TEnv.h>
#include <TComplex.h>
#include <TH2D.h>
#include "Math/LorentzVector.h"

using namespace std;
class ZZZAna
{
 public:
 
 /***************test variables*****************/
 bool isRead;

 /*****************Tree input*******************/
 TTree *fChain;

 /***********Tree branch vairables**************/
 Int_t                              pT5_occupancies;
 Int_t                              pT3_occupancies;
 Int_t                              tc_occupancies;
 std::vector<int>*                  md_occupancies=0;
 std::vector<int>*                  sg_occupancies=0;
 std::vector<int>*                  t3_occupancies=0;
 std::vector<int>*                  t4_occupancies=0;
 std::vector<int>*                  t5_occupancies=0;
 
 /************tatistical variables**************/
 Int_t                             Sta_TotalNumber;

 /******************functions*******************/
 ZZZAna(const char* infileName, const char* typeName);
 virtual ~ZZZAna();
 virtual void Initial(const char* rootName, int rootNumber);
 virtual void Loop(const char* typeName);
 virtual void End(int rootNumber);
 virtual void Save(int rootNumber);

 /********************plots*********************/
 makeHists* myHists;

};//class ZZZAna definition ends

#endif //end define _ZZZANA_H_

#ifdef _ZZZANA_C_ //if already defined, then add functions
ZZZAna::ZZZAna(const char* infileName, const char* typeName)
{
 myHists = new makeHists();
 TString histName = "../outfiles/" + (TString) typeName + "_selected.root";
 myHists->createHists(histName);
}

ZZZAna::~ZZZAna(){}

void ZZZAna::Initial(const char* rootName, int rootNumber)
{
 Sta_TotalNumber = 0;
 cout<<"**Running starting Rootfile: "<<rootNumber<<endl;

 TTree *tree;
 TFile *file = (TFile *)gROOT->GetListOfFiles()->FindObject(rootName);
 if(!file) file = new TFile(rootName);
 tree = (TTree *)gDirectory->Get("tree");

 fChain = tree;
 isRead = true;

 double fileEntries = fChain->GetEntries();
 if(fileEntries == 0) isRead = false;

 /***************set branches**************/
 fChain->SetBranchAddress("pT5_occupancies",&pT5_occupancies);
 fChain->SetBranchAddress("pT3_occupancies",&pT3_occupancies);
 fChain->SetBranchAddress("tc_occupancies",&tc_occupancies);
 fChain->SetBranchAddress("md_occupancies",&md_occupancies);
 fChain->SetBranchAddress("sg_occupancies",&sg_occupancies);
 fChain->SetBranchAddress("t3_occupancies",&t3_occupancies);
 fChain->SetBranchAddress("t4_occupancies",&t4_occupancies);
 fChain->SetBranchAddress("t5_occupancies",&t5_occupancies);
}

void ZZZAna::End(int rootNumber)
{
 cout<< "**Running: Free Rootfile: "<<rootNumber<<endl;
 cout<< "*************************"<<endl;
 cout<< "*********outputs*********"<<endl;
 cout<< "Total event number in this file:      "<<Sta_TotalNumber<<endl;
 delete fChain->GetCurrentFile();
}

void ZZZAna::Save(int rootNumber)
{
 cout<<"**Running: "<<rootNumber<<"  rootfiles finished"<<endl;
 cout<<"**The files contain "<<Sta_TotalNumber<<" events"<<endl;
 if(myHists)
 {
  myHists->saveHists();
  delete myHists;
 }
 cout<<"**Running histograms saved"<<endl;
}
#endif //end ifdef _ZZZANA_C_
