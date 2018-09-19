### Example application to examine codeblocks batch build stalling

See also: http://forums.codeblocks.org/index.php/topic,22824.0.html

### Steps to reproduce

- Unzip sources
- Download boost sources from https://dl.bintray.com/boostorg/release/1.68.0/source/
- Unpack boost headers from archive folder "boost_1_68_0/boost" into subfolder "boost" of the source folder
- Configure your msvc8 (MS Visual Studio 2005) or msvc10 (MS Visual Studio 2010) compiler to use 4 build processes
- Compile project with msvc8 or msvc10 using Code::Blocks batch build mode:
  codeblocks.exe boost_msm_codeblocks_test.cbp --rebuild --no-check-associations --no-dde --no-splash-screen --no-batch-window-close --target=Debug
- Once the batch build log window opens put it into one corner of your screen
- Open the Windows task manager and put it into the other corner of your screen
- Keep the task manager window focussed, watch the cl.exe processes work and consume cpu time 
- At some point, the build should stall (no more output scrolling through log window)
- Hover your mouse over the batch build log window to see the build resume

 