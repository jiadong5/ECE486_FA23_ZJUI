  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (ECE486_drive_OpenL_P)
    ;%
      section.nData     = 47;
      section.data(47)  = dumData; %prealloc
      
	  ;% ECE486_drive_OpenL_P.Ramp_InitialOutput
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ECE486_drive_OpenL_P.SliderGain1_gain
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ECE486_drive_OpenL_P.Ramp_slope
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ECE486_drive_OpenL_P.Ramp_start
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% ECE486_drive_OpenL_P.GTS400PVsInitialization_P1_Size
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% ECE486_drive_OpenL_P.GTS400PVsInitialization_P1
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 6;
	
	  ;% ECE486_drive_OpenL_P.GTS400PVsInitialization_P2_Size
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 7;
	
	  ;% ECE486_drive_OpenL_P.GTS400PVsInitialization_P2
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 9;
	
	  ;% ECE486_drive_OpenL_P.GTS400PVsInitialization_P3_Size
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 10;
	
	  ;% ECE486_drive_OpenL_P.GTS400PVsInitialization_P3
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 12;
	
	  ;% ECE486_drive_OpenL_P.GTS400PVsInitialization_P4_Size
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 16;
	
	  ;% ECE486_drive_OpenL_P.GTS400PVsInitialization_P4
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 18;
	
	  ;% ECE486_drive_OpenL_P.GTS400PVsInitialization_P5_Size
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 22;
	
	  ;% ECE486_drive_OpenL_P.GTS400PVsInitialization_P5
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 24;
	
	  ;% ECE486_drive_OpenL_P.GTS400PVsInitialization_P6_Size
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 27;
	
	  ;% ECE486_drive_OpenL_P.GTS400PVsInitialization_P6
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 29;
	
	  ;% ECE486_drive_OpenL_P.GTS400PVsInitialization_P7_Size
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 32;
	
	  ;% ECE486_drive_OpenL_P.GTS400PVsInitialization_P7
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 34;
	
	  ;% ECE486_drive_OpenL_P.GTS400PVsInitialization_P8_Size
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 37;
	
	  ;% ECE486_drive_OpenL_P.GTS400PVsInitialization_P8
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 39;
	
	  ;% ECE486_drive_OpenL_P.GTS400PVsInitialization_P9_Size
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 42;
	
	  ;% ECE486_drive_OpenL_P.GTS400PVsInitialization_P9
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 44;
	
	  ;% ECE486_drive_OpenL_P.GTS400PVsInitialization_P10_Size
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 45;
	
	  ;% ECE486_drive_OpenL_P.GTS400PVsInitialization_P10
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 47;
	
	  ;% ECE486_drive_OpenL_P.GTS400PVsInitialization_P11_Size
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 48;
	
	  ;% ECE486_drive_OpenL_P.GTS400PVsInitialization_P11
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 50;
	
	  ;% ECE486_drive_OpenL_P.GTS400PVsInitialization_P12_Size
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 51;
	
	  ;% ECE486_drive_OpenL_P.GTS400PVsInitialization_P12
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 53;
	
	  ;% ECE486_drive_OpenL_P.GTS400PVsInitialization_P13_Size
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 54;
	
	  ;% ECE486_drive_OpenL_P.GTS400PVsInitialization_P13
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 56;
	
	  ;% ECE486_drive_OpenL_P.GTS400PVsInitialization_P14_Size
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 57;
	
	  ;% ECE486_drive_OpenL_P.GTS400PVsInitialization_P14
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 59;
	
	  ;% ECE486_drive_OpenL_P.GTS400PVsInitialization_P15_Size
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 60;
	
	  ;% ECE486_drive_OpenL_P.GTS400PVsInitialization_P15
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 62;
	
	  ;% ECE486_drive_OpenL_P.GTS400PVsInitialization_P16_Size
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 63;
	
	  ;% ECE486_drive_OpenL_P.GTS400PVsInitialization_P16
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 65;
	
	  ;% ECE486_drive_OpenL_P.GTS400PVsInitialization_P17_Size
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 66;
	
	  ;% ECE486_drive_OpenL_P.GTS400PVsInitialization_P17
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 68;
	
	  ;% ECE486_drive_OpenL_P.GTSSetDAC_P1_Size
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 69;
	
	  ;% ECE486_drive_OpenL_P.GTSSetDAC_P1
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 71;
	
	  ;% ECE486_drive_OpenL_P.Step1_Time
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 72;
	
	  ;% ECE486_drive_OpenL_P.Step1_Y0
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 73;
	
	  ;% ECE486_drive_OpenL_P.Step1_YFinal
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 74;
	
	  ;% ECE486_drive_OpenL_P.Step_Y0
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 75;
	
	  ;% ECE486_drive_OpenL_P.GTSGetPos_P1_Size
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 76;
	
	  ;% ECE486_drive_OpenL_P.GTSGetPos_P1
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 78;
	
	  ;% ECE486_drive_OpenL_P.Gain_Gain
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 79;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ECE486_drive_OpenL_P.ManualSwitch_CurrentSetting
	  section.data(1).logicalSrcIdx = 47;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (ECE486_drive_OpenL_B)
    ;%
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% ECE486_drive_OpenL_B.ManualSwitch
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ECE486_drive_OpenL_B.GTSGetPos
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ECE486_drive_OpenL_B.Gain
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ECE486_drive_OpenL_B.Derivative
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (ECE486_drive_OpenL_DW)
    ;%
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% ECE486_drive_OpenL_DW.TimeStampA
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ECE486_drive_OpenL_DW.LastUAtTimeA
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ECE486_drive_OpenL_DW.TimeStampB
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ECE486_drive_OpenL_DW.LastUAtTimeB
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% ECE486_drive_OpenL_DW.GTS400PVsInitialization_PWORK
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ECE486_drive_OpenL_DW.GTSSetDAC_PWORK
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ECE486_drive_OpenL_DW.Scope2_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ECE486_drive_OpenL_DW.GTSGetPos_PWORK
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 3;
	
	  ;% ECE486_drive_OpenL_DW.Scope1_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 8;
	  section.data(5).dtTransOffset = 4;
	
	  ;% ECE486_drive_OpenL_DW.Scope3_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 9;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 1102316243;
  targMap.checksum1 = 1035392534;
  targMap.checksum2 = 229541780;
  targMap.checksum3 = 1516516342;

