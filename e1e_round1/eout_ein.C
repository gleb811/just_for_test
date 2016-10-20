void eout_ein() {

TCanvas *c = new TCanvas("c", "c", 1000, 500);
c->Divide(2,1);

gStyle->SetOptStat(0);


TGaxis::SetMaxDigits(3);
//Int_t TGaxis::fgMaxDigits = 3;

TFile *MyFile = new TFile("eout_vs_ein.root","READ");

TH2F *before,*after;

before = (TH2F*)MyFile->Get("eout_vs_ein_before");

after = (TH2F*)MyFile->Get("eout_vs_ein_after");

before->SetTitle("");
before->GetYaxis()->SetTitle("E_{out} (GeV)");
before->GetYaxis()->SetTitleSize(0.05);
before->GetYaxis()->SetTitleOffset(1.35);

before->GetXaxis()->SetTitle("E_{in} (GeV)");
before->GetXaxis()->SetTitleSize(0.05);
before->GetXaxis()->SetTitleOffset(0.9);

c->cd(1);
c->cd(1)->SetTopMargin(0.05);
c->cd(1)->SetLeftMargin(0.15);
c->cd(1)->SetRightMargin(0.12);
before->Draw("colz");



after->SetTitle("");
after->GetYaxis()->SetTitle("E_{out} (GeV)");
after->GetYaxis()->SetTitleSize(0.05);
after->GetYaxis()->SetTitleOffset(1.35);

after->GetXaxis()->SetTitle("E_{in} (GeV)");
after->GetXaxis()->SetTitleSize(0.05);
after->GetXaxis()->SetTitleOffset(0.9);

c->cd(2);
c->cd(2)->SetTopMargin(0.05);
c->cd(2)->SetLeftMargin(0.15);
c->cd(2)->SetRightMargin(0.12);
after->Draw("colz");

c->Print("eout_vs_ein.pdf");

}
