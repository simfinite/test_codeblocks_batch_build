### Example application to examine codeblocks batch build stalling

See also: http://forums.codeblocks.org/index.php/topic,22824.0.html

### Compilers

This has been tested with the following compilers:
- msvc8 (MS Visual Studio 2005)
- msvc10 (MS Visual Studio 2010)
- TDM gcc 5.1.0
- MinGW-W64 gcc 5.4.0

### Steps to reproduce

- Unzip sources
- Download boost sources from https://dl.bintray.com/boostorg/release/1.68.0/source/
- Unpack boost headers from archive folder "boost_1_68_0/boost" into subfolder "boost" of the source folder
- Open project and set the compiler you want to build with, add compiler option "/EHs" for Visual Studio compilers
- Configure your compiler to use 4 build processes
- Compile project from a terminal/command prompt using Code::Blocks batch build mode:
  codeblocks.exe boost_msm_codeblocks_test.cbp --rebuild --no-check-associations --no-dde --no-splash-screen --no-batch-window-close --target=Debug
- Once the batch build log window opens put it into one corner of your screen
- Open the Windows task manager and put it into the other corner of your screen
- Keep the task manager window focussed, watch the cl.exe processes work and consume cpu time 
- At some point, the build should stall (no more output scrolling through log window)
- Hover your mouse over the batch build log window to see the build resume

NOTE: Although the problem is very well reproducible, once it occurs, it may need some tweaking of the amount of warnings produced (see fsm.hpp, line #206) and the number of build jobs.