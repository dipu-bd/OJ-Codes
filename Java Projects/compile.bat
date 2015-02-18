@cls
@echo          JAVA COMPILER
@echo =================================
@echo CREATED BY, Sudipto Chandra Dipu 
@echo          (dipu.sudipta@gmail.com)
@echo _

@set /p fileName=Filename:%=%
@echo COMPILING "%fileName%"
@javac "%fileName%"

@set /p className=Classname:%=%
@echo _
@echo ==== PROGRAM STARTED ====
@java %className%

@echo _
@set /p exit=Press any key to exit...%=%
@exit