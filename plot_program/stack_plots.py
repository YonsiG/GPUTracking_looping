from curses import can_change_color
from hashlib import new
from numbers import Integral
import ROOT
import copy

def draw_plot(plotname="fatjet_msoftdrop", title="myTitle", log=True):
    #open file
    signalfile = ROOT.TFile("../outfiles/PU200_selected.root")

    #get historam
    signalplot = signalfile.Get(plotname)

    #draw overflow
    signalplot.SetBinContent(1, signalplot.GetBinContent(1) + signalplot.GetBinContent(0))
    signalplot.SetBinContent(signalplot.GetNbinsX(), signalplot.GetBinContent(signalplot.GetNbinsX() + 1) + signalplot.GetBinContent(signalplot.GetNbinsX()))

#    #plot legends, ranges
#    legend = ROOT.TLegend(0.7,0.83,0.95,0.97)
#    legend.SetTextFont(60)
#    legend.SetTextSize(0.02)
#    legend.AddEntry(signalplot,"signal %.2f"%(signalplot.Integral()))

    #stat box
    label = []
    label_name = "Entries: " + str(signalplot.Integral())
    label.append(label_name)
    label_name = "Mean: " + str("{:.2f}".format(signalplot.GetMean()))
    label.append(label_name)
    label_name = "Maximum bin entries(bin 0): " + str(signalplot.GetMaximum())
    label.append(label_name)
    legoffset = 0.0
    latexSel = ROOT. TLatex()
    latexSel.SetTextAlign(11)
    latexSel.SetTextFont(42)
    latexSel.SetTextSize(0.03-0.1*legoffset)
    latexSel.SetNDC(True)

    if log==True:
        signalplot.GetYaxis().SetRangeUser(10e-2,10e8)

    #define canvas
    canvas = ROOT.TCanvas("canvas","canvas",800,800)
    pad1 = ROOT.TPad("pad1","pad1",0,0,1,1)
    pad1.Draw()

    pad1.cd()
    if log==True:
        pad1.SetLogy()

    #plot signal 
    signalplot.Draw("Hist")
#    legend.Draw()
    for ts in range(0,3):
        latexSel.DrawLatex(0.45+3*legoffset, 0.81-ts*(0.03-legoffset), label[ts])

    #print and save
    if log==True:
        canvas.SaveAs("../plots/" + plotname + "_s+b_log.png")

    if log==False:
        canvas.SaveAs("../plots/" + plotname + "_s+b_linear.png")

ROOT.gStyle.SetOptStat(0000)
ROOT.gROOT.SetBatch(1)

listofplots1=["t3_occupancies_module_by_eta0_0", "t3_occupancies_module_by_eta0_1", "t3_occupancies_module_by_eta0_2","t3_occupancies_module_by_eta0_3",
                "t3_occupancies_module_by_eta1_0", "t3_occupancies_module_by_eta1_1", 
                "t3_occupancies_module_by_eta2_1", "t3_occupancies_module_by_eta2_2", 
                "t3_occupancies_module_by_eta3_1", "t3_occupancies_module_by_eta3_2", "t3_occupancies_module_by_eta3_3"]

for plot in listofplots1:
    title=plot
    draw_plot(plot, title, False)
    draw_plot(plot, title, True)
