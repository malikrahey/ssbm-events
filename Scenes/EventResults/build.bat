SET "TKPATH=../../m-ex/MexTK/"
SET "FSPATH=./"
SET "FNAME=EventMajor.dat"

"%TKPATH%MexTK.exe" -ff -i "Major.c" -s mjFunction -t "%TKPATH%mjFunction.txt" -l "%TKPATH%melee.link" -dat "%FSPATH%%FNAME%"
"%TKPATH%MexTK.exe" -trim "%FSPATH%%FNAME%"

copy "%FSPATH%%FNAME%" "..\..\fs\files\%FNAME%" /Y