﻿Light-Alloy C++ SDK
===================
This attempt to rewrite the original SDK (written in Delphi) in C++.
This is not official SDK!

Please visit official site: [http://www.light-alloy.ru](http://www.light-alloy.ru)


Create plugin
-------------
#### 1. Make dll project in your dev tools
#### 2. Include LA_SDK.h
#### 3. Create and include resource file.

_mypack.rc_

	MYPREFS RCDATA "MYPREFS.xml"
	LANGEN  RCDATA "LANGEN.txt"
	LANGRU	RCDATA "LANGRU.txt"
	
_MYPREFS.xml_

	<?xml version="1.0" encoding="UTF-16"?>
	<APP name="MyPlugin" version="1.0" build="1">
		<FrontEnd Language="Russian"/>
	</APP>

_LANGEN.txt_

	;Comment
	Test.Caption=Test plugin

_LANGRU.txt_

	;Пример комментария.
	Test.Caption=Тестовый плагин

#### 4. Create and fill structure LA_GenPluginInfoStruct


	LA_GenPluginInfoStruct plugin = {
		"1.0",           //version
		"Test",          //name
		"description",   //description
		"Test",          //AppData_Dir
		"Test",          //LogFile_Name
		"Test",          //PrefsFile_Name
		"Test.dll",      //DLLName
		LA_API_VERSION,  //SDK_MIN_VER (LA v4.6 = 0x10).
		1,               //hasOptions (0 - no, 1 - yes)?
		onInit,          //InitProc
		onConfig,        //ConfigProc
		onQuite,         //QuitProc
		0,               //hwndParent
		0                //hDllInst
	};


#### 5. Export function LA_GenPluginInfo

	LA_GenPluginInfoStruct *LA_GenPluginInfo() {
		return &plugin;
	}


#### 6. Build
#### 7. Move Plugin.dll and MYPREFS.xml (must be renamed to Test.xml) in Light-Alloy\Plugins\General
