/*
 * SDK ��� Light Alloy
 * ������ 4.6 RC2 +
 */
#define LA_API_VERSION       0x10


/*
 * ���������
 */

//�������� ��������� ������������ � ����� ��� �������������
typedef struct {
	char     *version;
	char     *name;
	char     *description;
	char     *AppData_Dir;  
    char     *LogFile_Name;
    char     *PrefsFile_Name;
    char     *DLLName;
    int       SDK_MIN_VER;     // ���������� ��������� ������ ���������� ����������� (LA v4.6 = 0x10).
    int       hasOptions;      // ������ ����� ��������� (0 - ���, 1 - ��)?
    int       (*InitProc)();
	void      (*ConfigProc)();
    void      (*QuitProc)();
    HWND      hwndParent;
    HINSTANCE hDllInst;
} LA_GenPluginInfoStruct;


// ����������� ��������:
// LAG = Light Alloy Get - ���������� �������� -- ��������� ���� ��������.
// LAC = Light Alloy Command - ��������� �������, ������ �� �������� � �� ����������.
// LAE = Light Alloy Event - �������� ������� � ������, ����� ��������� �� ��� ���� ������� � ������.
// LAS = Light Alloy Set - ������������� ��������� ���� ��������.
#define LAC_VERSION                 000
#define LAC_FILE_OPEN               050
#define LAC_FILE_INFO               051
#define LAC_FILE_OSD_INFO           052
#define LAC_FILE_OPEN_URL           053
#define LAC_FILE_INFO_PLAYLIST      054
#define LAC_FILE_MEDIAHISTORY_CLEAR 055
#define LAC_FILE_PLAY_DVD_DISC      056
#define LAC_FILE_OPEN_DVD_FOLDER    057
#define LAC_FILE_OPEN_TV            058

#define LAC_PLAYBACK_REAL_STOP      100
#define LAC_PLAYBACK_PLAY           101
#define LAC_PLAYBACK_STOP_PLAY      102
#define LAC_PLAYBACK_SPEED_PLAY     103
#define LAC_PLAYBACK_STOP           104
#define LAC_PLAYBACK_DISK           105
#define LAC_PLAYBACK_FILTERS        106
#define LAC_PLAYBACK_SPEED_PLAY_UP  107
#define LAC_PLAYBACK_SPEED_PLAY_DN  108

#define LAC_SEEK_FRAME_STEP         150
#define LAC_SEEK_FRAME_BACK         151
#define LAC_SEEK_FORWARD            152
#define LAC_SEEK_BACKWARD           153
#define LAC_SEEK_JUMP_FORWARD       154
#define LAC_SEEK_JUMP_BACKWARD      155
#define LAC_SEEK_REWIND             156
#define LAC_SEEK_SET_BOOKMARK       157
#define LAC_SEEK_SET_OE_OFFSET      158
#define LAC_SEEK_LAST_POS           159
#define LAC_SEEK_A_B                160

#define LAC_WINDOW_CONTROL_PANEL    200
#define LAC_WINDOW_PLAYLIST         201
#define LAC_WINDOW_FULLSCREEN       202
#define LAC_WINDOW_ORIGINAL         203
#define LAC_WINDOW_STAY_ON_TOP      204
#define LAC_WINDOW_MINIMIZE         205
#define LAC_WINDOW_MAXIMIZE         206
#define LAC_WINDOW_EX_PLAYLIST      207
#define LAC_WINDOW_HIDE_FROM_BOSS   208

#define LAC_PLAYLIST_NEXT           250
#define LAC_PLAYLIST_PREV           251
#define LAC_PLAYLIST_PLAY           252
#define LAC_PLAYLIST_ADD_FILES      253
#define LAC_PLAYLIST_ADD_FOLDER     254
#define LAC_PLAYLIST_DELETE         255
#define LAC_PLAYLIST_CLEAR          256
#define LAC_PLAYLIST_SAVE           257
#define LAC_PLAYLIST_MOVE_UP        258
#define LAC_PLAYLIST_MOVE_DOWN      259
#define LAC_PLAYLIST_SHUFFLE        260
#define LAC_PLAYLIST_SORT           261
#define LAC_PLAYLIST_REPORT         262
#define LAC_PLAYLIST_REPEAT         263
#define LAC_PLAYLIST_BOOKMARKS      264
#define LAC_PLAYLIST_JUMP           265
#define LAC_PLAYLIST_SEARCH_FILE    266
#define LAC_PLAYLIST_DELETE_FILE    267
#define LAC_PLAYLIST_REPEAT_FILE    268
#define LAC_PLAYLIST_VISUALSHUFFLE  269

#define LAC_VIDEO_PROPERTIES        300
#define LAC_VIDEO_SCREENSHOT        301
#define LAC_VIDEO_SCREENSHOT_CB     302
#define LAC_VIDEO_SAVE_THUMBNAILS   303
#define LAC_VIDEO_SAVE_SCREENS_PACK 304
#define LAC_VIDEO_SCALE_50          305
#define LAC_VIDEO_SCALE_100         306
#define LAC_VIDEO_SCALE_200         307
#define LAC_VIDEO_RATIO_ASIS        308
#define LAC_VIDEO_RATIO_16_9        309
#define LAC_VIDEO_RATIO_4_3         310
#define LAC_VIDEO_RATIO_WIDTH       311
#define LAC_VIDEO_RATIO_HEIGHT      312
#define LAC_VIDEO_RATIO_CUSTOM      313
#define LAC_VIDEO_RATIO_CUSTOM_SET  314
#define LAC_VIDEO_RATIO_FREE        315
#define LAC_VIDEO_ZOOM_IN           316
#define LAC_VIDEO_ZOOM_OUT          317
#define LAC_VIDEO_BRIGHTNESS_INC    318
#define LAC_VIDEO_BRIGHTNESS_DEC    319
#define LAC_VIDEO_CONTRAST_INC      320
#define LAC_VIDEO_CONTRAST_DEC      321
#define LAC_VIDEO_SATURATION_INC    322
#define LAC_VIDEO_SATURATION_DEC    323
#define LAC_VIDEO_COLOR_RESET       324
#define LAC_VIDEO_SETS_RESTORE      325
#define LAC_VIDEO_RATIO_SWITCH      326
#define LAC_VIDEO_SHOW_DEBUG_OSD    327
#define LAC_VIDEO_OSD_INFO_CB       328

#define LAC_SUBTITLES_LOAD          350
#define LAC_SUBTITLES_SHOW          351
#define LAC_SUBTITLES_PROPERTIES    352
#define LAC_SUBTITLES_TS_INC        353
#define LAC_SUBTITLES_TS_DEC        354
#define LAC_SUBTITLES_SWITCH        355
#define LAC_SUBTITLES_DEBUG_OSD     356
#define LAC_SUBTITLES_LOAD_TV       357
#define LAC_SUBTITLES_EXPLORER      358

#define LAC_SOUND_PROPERTIES        400
#define LAC_SOUND_VOLUME_INC        401
#define LAC_SOUND_VOLUME_DEC        402
#define LAC_SOUND_MUTE              403
#define LAC_SOUND_ADD               404
#define LAC_SOUND_SWITCH_STREAM     405
#define LAC_SOUND_TS_PLUS           406
#define LAC_SOUND_TS_MINUS          407

#define LAC_APPLICATION_PREFERENCES          450
#define LAC_APPLICATION_HELP                 451
#define LAC_APPLICATION_ABOUT                452
#define LAC_APPLICATION_EXIT                 453
#define LAC_APPLICATION_POWER_OFF            454
#define LAC_APPLICATION_HIBERNATE            455
#define LAC_APPLICATION_MONITOR_OFF          456
#define LAC_APPLICATION_HIB_ONPLDONE         457
#define LAC_APPLICATION_POW_ONPLDONE         458
#define LAC_APPLICATION_CLEAR_MEDIA_SETTINGS 459
#define LAC_APPLICATION_WL_KEYS_REMINDER     460
#define LAC_APPLICATION_SCHEDULER            461
#define LAC_APPLICATION_AGENT_CLOSE          462
#define LAC_APPLICATION_OPEN_SCR_FOLDER      463

#define LAC_NAVIGATION_TITLE  500
#define LAC_NAVIGATION_ROOT   501
#define LAC_NAVIGATION_SUBS   502
#define LAC_NAVIGATION_AUDIO  503
#define LAC_NAVIGATION_ANGLE  504
#define LAC_NAVIGATION_SCENES 505
#define LAC_NAVIGATION_PREV   506
#define LAC_NAVIGATION_NEXT   507

#define LAC_CD_PLAYDISC_A     854
#define LAC_CD_PLAYDISC_B     855
#define LAC_CD_PLAYDISC_C     856
#define LAC_CD_PLAYDISC_D     857
#define LAC_CD_PLAYDISC_E     858
#define LAC_CD_PLAYDISC_F     859
#define LAC_CD_PLAYDISC_G     860
#define LAC_CD_PLAYDISC_H     861
#define LAC_CD_PLAYDISC_I     862
#define LAC_CD_PLAYDISC_J     863
#define LAC_CD_PLAYDISC_K     864
#define LAC_CD_PLAYDISC_L     865
#define LAC_CD_PLAYDISC_M     866
#define LAC_CD_PLAYDISC_N     867
#define LAC_CD_PLAYDISC_O     868
#define LAC_CD_PLAYDISC_P     869
#define LAC_CD_PLAYDISC_Q     870
#define LAC_CD_PLAYDISC_R     871
#define LAC_CD_PLAYDISC_S     872
#define LAC_CD_PLAYDISC_T     873
#define LAC_CD_PLAYDISC_U     874
#define LAC_CD_PLAYDISC_V     875
#define LAC_CD_PLAYDISC_W     876
#define LAC_CD_PLAYDISC_X     877
#define LAC_CD_PLAYDISC_Y     878
#define LAC_CD_PLAYDISC_Z     879

#define LAC_SYSTEM_CPU        1000
#define LAC_SYSTEM_CRC        1001

#define LAG_FILE_INFO          1500 // ���������� ��������� ����������� �����������
                                      // � �����. ��������� ������ ����� � ������. -1 = ������� ���������������.
#define LAG_FILE_POS           1501 // ���������� ������� ������� ���������������� ����� � ������������.
#define LAG_FILE_DUR           1502 // ���������� ������������ ���������������� ����� � ������������.
#define LAG_SOUND_VOLUME       1503 // ���������� ������� ��������� ������ (0-100)
#define LAG_CONFIG_STR         1504 // �������� �� LA.xml ��������, ���������� � ���� ������.
#define LAG_SUPPORTED_EXTS     1505 // ���������� ������ �������������� ����������. ���������� � ��� �������, � ����� ��� �������� � ������� ���������� ������ ������. (0 - ��� ����������).
#define LAG_LANG_STR           1506 // ���������� �������� ������ �� �������� ��������� ��������� ����� � ������.
#define LAG_PLAYLIST_SEL_INDEX 1507 // ������ �������� _�����������_ �������� � ������. (������ -1, ���� ������� �� �������).
#define LAG_PLAYLIST_PP_INDEX  1508 // ������ �������� _��������������_ �������� � ������ (����� -1, ���� ������� ���� ������ �� �������������).

#define LAE_ON_APP_START            1600 // ������� ���������, ����� ����� �������, �� ������� ���� ��� �� ��������.
#define LAE_ON_FILE_LOAD            1601 // ��������� ����� �������� �����-����
#define LAE_ON_FILE_CLOSE           1602 // ��������� ����� �����-���� �������.
#define LAE_ON_OSD_MESSAGE          1603 // �������� ������� ����� � ������� OSD ���������� ��������� � ������.
#define LAE_ON_FILE_POS_CHANGED     1604 // ��������� ����� � ������ �������(������� �� ���������, ���� ��������� �� �����) �������� ������� ������.
#define LAE_ON_SOUND_VOLUME_CHANGED 1605 // ��������� ����� ������� �������� ���������.
#define LAE_CONTEXT_MENU_ITEM_CLK   1606 // ��������� ����� ������������ ������� �� ������ ������ ����. ���� (������� ��� ��� id ����� �������)
#define LAE_FILE_INFO_CALLBACK      1607 // ��������� ����� ������������ ������� �� ������, ���������� ��� [tag=callback id=�����_������� hint="������. ���������" cmd=�����_�������]�����[/tag],
                                         // ������� ������ ���������� LAE_CONTEXT_MENU_ITEM_CLK.
#define LAE_ON_FILE_INFO_OPEN       1608 // ��������� ����� ������������ ��������� *���������� � �����*.
                                         // ������ � ���� ������� �������� ������ ����� � ������, ������� ������������ ������������� � *���������� � �����*.
#define LAE_ON_FILE_INFO_CLOSE      1609 // ���������, ����� ������������ ��������� ������ ���������� � �����.                                    


#define LAS_VIDEOUT_SURFACE         1700 // � �������� ��������� ��������� Handle ������
                                         // ���� �� ����� �������� �����.
#define LAS_WINDOW_VISIBLE          1701 // ��������/���������� ������� ���� ������ (0 - ������, 1 - ��������).
#define LAS_SOUND_VOLUME            1702 // ������������� ��������� ������ � ��������� �������� (0-100)
#define LAS_FILE_POS                1703 // ������������� ��������������� � ��������� ������� (�����������)
#define LAS_CONTEXT_MENU_ADD        1704 // ����������� ������. ���� ������� � ����������� ���� ������ (������� ������ ���� ������� ��������!).
#define LAS_CONTEXT_MENU_UPD        1705 // ��������� ������������ ������. ���� ��� �������� �������.
#define LAS_OSD_TEXT                1706 // ��������� ����� � ����� ������� ����� ������� �� OSD
#define LAS_FILE_INFO_ADD           1707 // ������������� � ���� *���������� � �����* ������. (������� ������ ���� ������� ��������!)
#define LAS_FILE_INFO_UPD           1708 // ��������� ���� ������ � *���������� � �����* ������.

#define LAC_UPDATE_VIDEO            1800 // ���������� �� �������� ����� ����� (�����, ��������, ��� ��������� �������� ����)

   // ������� ����� ����������.
#define LAC_SET_INTEROP             2000 // ������������ ������ � ������.
#define LAC_INTEROP_LISTEN_ME       2001 // ������� ������ ����� ������ ��� �������.
                                         // ��������� � �������� ��������� ����� �������, �� ������� ����� ������� ������ �� ������.
#define LAC_REQUIRE_RELOAD_APP      2002 // ��������� ������, ��� ��� ���������� �������������.        