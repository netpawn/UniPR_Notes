TARGET=doc
SRC=${TARGET}.tex

LATEX = latex
L2H = latex2html
PDFLATEX = ps2pdf
DVIPS = dvips 
LATEX2HTML = latex2html

## targets

all: ${TARGET}.dvi

ps: ${TARGET}.ps

pdf: ${TARGET}.pdf

ps2on1: ${TARGET}_2on1.ps

pdf2on1: ${TARGET}_2on1.pdf


html: ${SRC}
	${LATEX} ${TARGET}.tex
	${LATEX2HTML} -numbered_footnotes -no_footnode \
	-antialias -html_version 4.0 \
	-white ${TARGET}.tex

${TARGET}.ps: ${TARGET}.dvi
	${DVIPS} -o ${TARGET}.ps ${TARGET}.dvi

${TARGET}.pdf: ${TARGET}.ps 
	${PDFLATEX} ${TARGET}.ps

${TARGET}.dvi: ${SRC}
	echo "Running latex..."
	${LATEX} ${TARGET}.tex
	@latex_count=5 ; \
	while egrep -s 'Rerun (LaTeX|to get cross-references right)' ${TARGET}.log && [ $$latex_count -gt 0 ] ;\
	    do \
	      echo "Rerunning latex...." ;\
	      latex ${TARGET}.tex ;\
	      latex_count=`expr $$latex_count - 1` ;\
	    done
${TARGET}_2on1.ps: ${TARGET}.ps
	psnup -2 ${TARGET}.ps > ${TARGET}_2on1.ps

${TARGET}_2on1.pdf: ${TARGET}_2on1.ps
	${PS2PDF} ${TARGET}_2on1.ps ${TARGET}_2on1.pdf

clean: 
	rm -f *.aux *.log *.bbl *.blg *.brf *.cb *.ind *.idx *.ilg  \
	*.inx *.ps *.dvi *.pdf *.toc *.out

