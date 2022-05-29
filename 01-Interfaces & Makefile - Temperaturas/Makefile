all: TP1
	make clean


TP1: TablasDeConversion.exe ConversionTest.exe
	ConversionTest.exe
	TablasDeConversion.exe


runTP: TablasDeConversion.exe
	TablasDeConversion.exe
	del TablasDeConversion.exe


runTest:ConversionTest.exe
	ConversionTest.exe
	del ConversionTest.exe


TablasDeConversion.exe: TablasDeConversion.c Conversion.c Conversion.h
	gcc TablasDeConversion.c Conversion.c -o TablasDeConversion.exe


ConversionTest.exe: ConversionTest.c Conversion.c Conversion.h
	gcc ConversionTest.c Conversion.c -o ConversionTest.exe


clean:
	del TablasDeConversion.exe -f
	del ConversionTest.exe -f