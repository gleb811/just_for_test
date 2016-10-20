void mass() {

TCanvas *c = new TCanvas("c", "c", 1000, 500);
c->Divide(3,2);

gStyle->SetOptStat(0);
gPad->SetLogz();

gStyle->SetTitleSize(0.5,"t"); 
gStyle->SetTitleX(0.6); //title X location 
gStyle->SetTitleY(1.0); //title Y location 
gStyle->SetTitleW(0.7); //title width 
gStyle->SetTitleH(0.1); //title height 

ostringstream qqq;

TGaxis::SetMaxDigits(3);
//Int_t TGaxis::fgMaxDigits = 3;

TFile *MyFile = new TFile("mass.root","READ");

TH2F *h;
h = (TH2F*)MyFile->Get("h301");
TH1 *h1;

TLine *line = new TLine(-25.,0.8,25.,0.8);
line->SetLineColor(2);
line->SetLineWidth(2);

for (Int_t i=0; i<6; i++)
{


c->cd(i+1);
c->cd(i+1)->SetLogz();;
c->cd(i+1)->SetTopMargin(0.1);
c->cd(i+1)->SetBottomMargin(0.2);
c->cd(i+1)->SetLeftMargin(0.2);
c->cd(i+1)->SetRightMargin(0.1);
qqq.str("");
qqq << "padd_prot_mass_" << i;

h = (TH2F*)MyFile->Get(qqq.str().c_str());


qqq.str("");
qqq << "sector " << i+1;
h->SetTitle(qqq.str().c_str());
h->SetTitleSize(2.);
h->GetYaxis()->SetTitle("hadron mass (GeV)");
h->GetYaxis()->SetTitleSize(0.07);
h->GetYaxis()->SetTitleOffset(1.15);

h->GetXaxis()->SetTitle("paddle number");
h->GetXaxis()->SetTitleSize(0.09);
h->GetXaxis()->SetTitleOffset(0.9);
h->SetLabelSize(0.07,"x");
h->SetLabelSize(0.07,"y");
h->GetXaxis()->SetNdivisions(505);


h->Draw("colz");
//line->Draw();

};

//c->Print("mass_no_th_vs_p.pdf");

/*
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
*/
}
