#include "../interface/Histgram.h"

void BaseHistgram::BookHistgram(const char *outFileName)
{
  oFile = new TFile(outFileName, "recreate");
  h_Charge_Diff = new TH1D("h_Charge_Diff","",4000,-2,2);
}

