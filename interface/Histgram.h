#include "TFile.h"
#include "TH1D.h"
#include "TChain.h"

class BaseHistgram
{
 public:
  void BookHistgram(const char *);

  TFile *oFile;
  TH1D *h_Charge_Diff;
};

