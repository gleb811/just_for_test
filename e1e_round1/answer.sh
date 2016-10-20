rm answer.dvi answer.dvi.ps
pdflatex answer.tex
pdflatex answer.tex
#dvips -oanswer.dvi.ps answer.dvi
#gv answer.dvi.ps
acroread answer.pdf
