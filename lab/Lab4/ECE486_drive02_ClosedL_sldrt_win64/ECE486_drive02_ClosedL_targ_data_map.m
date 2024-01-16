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
    ;% Auto data (ECE486_drive02_ClosedL_P)
    ;%
      section.nData     = 55;
      section.data(55)  = dumData; %prealloc
      
	  ;% ECE486_drive02_ClosedL_P.SliderGain_gain
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ECE486_drive02_ClosedL_P.GTS400PVsInitialization_P1_Size
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ECE486_drive02_ClosedL_P.GTS400PVsInitialization_P1
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3;
	
	  ;% ECE486_drive02_ClosedL_P.GTS400PVsInitialization_P2_Size
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4;
	
	  ;% ECE486_drive02_ClosedL_P.GTS400PVsInitialization_P2
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 6;
	
	  ;% ECE486_drive02_ClosedL_P.GTS400PVsInitialization_P3_Size
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 7;
	
	  ;% ECE486_drive02_ClosedL_P.GTS400PVsInitialization_P3
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 9;
	
	  ;% ECE486_drive02_ClosedL_P.GTS400PVsInitialization_P4_Size
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 13;
	
	  ;% ECE486_drive02_ClosedL_P.GTS400PVsInitialization_P4
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 15;
	
	  ;% ECE486_drive02_ClosedL_P.GTS400PVsInitialization_P5_Size
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 19;
	
	  ;% ECE486_drive02_ClosedL_P.GTS400PVsInitialization_P5
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 21;
	
	  ;% ECE486_drive02_ClosedL_P.GTS400PVsInitialization_P6_Size
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 24;
	
	  ;% ECE486_drive02_ClosedL_P.GTS400PVsInitialization_P6
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 26;
	
	  ;% ECE486_drive02_ClosedL_P.GTS400PVsInitialization_P7_Size
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 29;
	
	  ;% ECE486_drive02_ClosedL_P.GTS400PVsInitialization_P7
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 31;
	
	  ;% ECE486_drive02_ClosedL_P.GTS400PVsInitialization_P8_Size
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 34;
	
	  ;% ECE486_drive02_ClosedL_P.GTS400PVsInitialization_P8
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 36;
	
	  ;% ECE486_drive02_ClosedL_P.GTS400PVsInitialization_P9_Size
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 39;
	
	  ;% ECE486_drive02_ClosedL_P.GTS400PVsInitialization_P9
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 41;
	
	  ;% ECE486_drive02_ClosedL_P.GTS400PVsInitialization_P10_Size
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 42;
	
	  ;% ECE486_drive02_ClosedL_P.GTS400PVsInitialization_P10
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 44;
	
	  ;% ECE486_drive02_ClosedL_P.GTS400PVsInitialization_P11_Size
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 45;
	
	  ;% ECE486_drive02_ClosedL_P.GTS400PVsInitialization_P11
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 47;
	
	  ;% ECE486_drive02_ClosedL_P.GTS400PVsInitialization_P12_Size
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 48;
	
	  ;% ECE486_drive02_ClosedL_P.GTS400PVsInitialization_P12
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 50;
	
	  ;% ECE486_drive02_ClosedL_P.GTS400PVsInitialization_P13_Size
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 51;
	
	  ;% ECE486_drive02_ClosedL_P.GTS400PVsInitialization_P13
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 53;
	
	  ;% ECE486_drive02_ClosedL_P.GTS400PVsInitialization_P14_Size
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 54;
	
	  ;% ECE486_drive02_ClosedL_P.GTS400PVsInitialization_P14
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 56;
	
	  ;% ECE486_drive02_ClosedL_P.GTS400PVsInitialization_P15_Size
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 57;
	
	  ;% ECE486_drive02_ClosedL_P.GTS400PVsInitialization_P15
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 59;
	
	  ;% ECE486_drive02_ClosedL_P.GTS400PVsInitialization_P16_Size
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 60;
	
	  ;% ECE486_drive02_ClosedL_P.GTS400PVsInitialization_P16
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 62;
	
	  ;% ECE486_drive02_ClosedL_P.GTS400PVsInitialization_P17_Size
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 63;
	
	  ;% ECE486_drive02_ClosedL_P.GTS400PVsInitialization_P17
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 65;
	
	  ;% ECE486_drive02_ClosedL_P.GTSGetPos_P1_Size
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 66;
	
	  ;% ECE486_drive02_ClosedL_P.GTSGetPos_P1
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 68;
	
	  ;% ECE486_drive02_ClosedL_P.Gain_Gain
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 69;
	
	  ;% ECE486_drive02_ClosedL_P.Step_Time
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 70;
	
	  ;% ECE486_drive02_ClosedL_P.Step_Y0
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 71;
	
	  ;% ECE486_drive02_ClosedL_P.Step_YFinal
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 72;
	
	  ;% ECE486_drive02_ClosedL_P.SineWave_Amp
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 73;
	
	  ;% ECE486_drive02_ClosedL_P.SineWave_Bias
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 74;
	
	  ;% ECE486_drive02_ClosedL_P.SineWave_Freq
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 75;
	
	  ;% ECE486_drive02_ClosedL_P.SineWave_Phase
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 76;
	
	  ;% ECE486_drive02_ClosedL_P.GTSSetAccVel_P1_Size
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 77;
	
	  ;% ECE486_drive02_ClosedL_P.GTSSetAccVel_P1
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 79;
	
	  ;% ECE486_drive02_ClosedL_P.GTSSetAccVel_P2_Size
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 80;
	
	  ;% ECE486_drive02_ClosedL_P.GTSSetAccVel_P2
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 82;
	
	  ;% ECE486_drive02_ClosedL_P.GTSSetAccVel_P3_Size
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 83;
	
	  ;% ECE486_drive02_ClosedL_P.GTSSetAccVel_P3
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 85;
	
	  ;% ECE486_drive02_ClosedL_P.Constant_Value
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 86;
	
	  ;% ECE486_drive02_ClosedL_P.Gain1_Gain
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 87;
	
	  ;% ECE486_drive02_ClosedL_P.GTSGetPos1_P1_Size
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 88;
	
	  ;% ECE486_drive02_ClosedL_P.GTSGetPos1_P1
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 90;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ECE486_drive02_ClosedL_P.ManualSwitch1_CurrentSetting
	  section.data(1).logicalSrcIdx = 55;
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
    ;% Auto data (ECE486_drive02_ClosedL_B)
    ;%
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% ECE486_drive02_ClosedL_B.GTSGetPos
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ECE486_drive02_ClosedL_B.Gain
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ECE486_drive02_ClosedL_B.Derivative
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ECE486_drive02_ClosedL_B.Constant
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% ECE486_drive02_ClosedL_B.Gain1
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% ECE486_drive02_ClosedL_B.GTSGetPos1
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
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
    ;% Auto data (ECE486_drive02_ClosedL_DW)
    ;%
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% ECE486_drive02_ClosedL_DW.TimeStampA
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ECE486_drive02_ClosedL_DW.LastUAtTimeA
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ECE486_drive02_ClosedL_DW.TimeStampB
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ECE486_drive02_ClosedL_DW.LastUAtTimeB
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% ECE486_drive02_ClosedL_DW.GTS400PVsInitialization_PWORK
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ECE486_drive02_ClosedL_DW.GTSGetPos_PWORK
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ECE486_drive02_ClosedL_DW.Scope_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ECE486_drive02_ClosedL_DW.GTSSetAccVel_PWORK
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 3;
	
	  ;% ECE486_drive02_ClosedL_DW.GTSGetPos1_PWORK
	  section.data(5).logicalSrcIdx = 8;
	  section.data(5).dtTransOffset = 4;
	
	  ;% ECE486_drive02_ClosedL_DW.Scope_PWORK_j.LoggedData
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


  targMap.checksum0 = 295160732;
  targMap.checksum1 = 675972705;
  targMap.checksum2 = 818872532;
  targMap.checksum3 = 107246422;

