#ifndef _MAKEHIST_H_
#define _MAKEHIST_H_

#include <iostream>
#include "TTree.h"
#include "TH1D.h"
#include "TH2D.h"

class makeHists
{
  public:

  TFile *hf;

  TH1D *pT5_occupancies;
  TH1D *pT3_occupancies;
  TH1D *tc_occupancies;

  TH1D *md_occupancies_module;
  TH1D *md_occupancies_event;
  TH1D *sg_occupancies_module;
  TH1D *sg_occupancies_event;
  TH1D *t3_occupancies_module;
  TH1D *t3_occupancies_event;
  TH1D *t4_occupancies_module;
  TH1D *t4_occupancies_event;
  TH1D *t5_occupancies_module;
  TH1D *t5_occupancies_event;

  TH1D *module_layers;
  TH1D *module_subdets;
  TH1D *module_rings;

  void createHists(const char* fileName); 
  void saveHists();
};
#endif
