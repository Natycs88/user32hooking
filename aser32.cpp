#include <windows.h>
#include <winuser.h>

/*
The MIT License

Copyright (c) 2010 teraapi.com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

/*
 * Gesture defines and functions
 */

/*
 * Gesture information handle
 */
DECLARE_HANDLE(HGESTUREINFO);

/*
 * Gesture information structure
 *   - Pass the HGESTUREINFO received in the WM_GESTURE message lParam into the
 *     GetGestureInfo function to retrieve this information.
 *   - If cbExtraArgs is non-zero, pass the HGESTUREINFO received in the WM_GESTURE
 *     message lParam into the GetGestureExtraArgs function to retrieve extended
 *     argument information.
 */
typedef struct tagGESTUREINFO {
    UINT cbSize;                    // size, in bytes, of this structure (including variable length Args field)
    DWORD dwFlags;                  // see GF_* flags
    DWORD dwID;                     // gesture ID, see GID_* defines
    HWND hwndTarget;                // handle to window targeted by this gesture
    POINTS ptsLocation;             // current location of this gesture
    DWORD dwInstanceID;             // internally used
    DWORD dwSequenceID;             // internally used
    ULONGLONG ullArguments;         // arguments for gestures whose arguments fit in 8 BYTES
    UINT cbExtraArgs;               // size, in bytes, of extra arguments, if any, that accompany this gesture
} GESTUREINFO, *PGESTUREINFO;
typedef GESTUREINFO const * PCGESTUREINFO;

/*
 * Gesture configuration structure
 *   - Used in SetGestureConfig and GetGestureConfig
 *   - Note that any setting not included in either GESTURECONFIG.dwWant or
 *     GESTURECONFIG.dwBlock will use the parent window's preferences or
 *     system defaults.
 */
typedef struct tagGESTURECONFIG {
    DWORD dwID;                     // gesture ID
    DWORD dwWant;                   // settings related to gesture ID that are to be turned on
    DWORD dwBlock;                  // settings related to gesture ID that are to be turned off
} GESTURECONFIG, *PGESTURECONFIG;

FARPROC p_NONAME1;
FARPROC p_ActivateKeyboardLayout;
FARPROC p_AddClipboardFormatListener;
FARPROC p_AdjustWindowRect;
FARPROC p_AdjustWindowRectEx;
FARPROC p_AlignRects;
FARPROC p_AllowForegroundActivation;
FARPROC p_AllowSetForegroundWindow;
FARPROC p_AnimateWindow;
FARPROC p_AnyPopup;
FARPROC p_AppendMenuA;
FARPROC p_AppendMenuW;
FARPROC p_ArrangeIconicWindows;
FARPROC p_AttachThreadInput;
FARPROC p_BeginDeferWindowPos;
FARPROC p_BeginPaint;
FARPROC p_BlockInput;
FARPROC p_BringWindowToTop;
FARPROC p_BroadcastSystemMessage;
FARPROC p_BroadcastSystemMessageA;
FARPROC p_BroadcastSystemMessageExA;
FARPROC p_BroadcastSystemMessageExW;
FARPROC p_BroadcastSystemMessageW;
FARPROC p_BuildReasonArray;
FARPROC p_CalcMenuBar;
FARPROC p_CallMsgFilter;
FARPROC p_CallMsgFilterA;
FARPROC p_CallMsgFilterW;
FARPROC p_CallNextHookEx;
FARPROC p_CallWindowProcA;
FARPROC p_CallWindowProcW;
FARPROC p_CancelShutdown;
FARPROC p_CascadeChildWindows;
FARPROC p_CascadeWindows;
FARPROC p_ChangeClipboardChain;
FARPROC p_ChangeDisplaySettingsA;
FARPROC p_ChangeDisplaySettingsExA;
FARPROC p_ChangeDisplaySettingsExW;
FARPROC p_ChangeDisplaySettingsW;
FARPROC p_ChangeMenuA;
FARPROC p_ChangeMenuW;
FARPROC p_ChangeWindowMessageFilter;
FARPROC p_CharLowerA;
FARPROC p_CharLowerBuffA;
FARPROC p_CharLowerBuffW;
FARPROC p_CharLowerW;
FARPROC p_CharNextA;
FARPROC p_CharNextExA;
FARPROC p_CharNextW;
FARPROC p_CharPrevA;
FARPROC p_CharPrevExA;
FARPROC p_CharPrevW;
FARPROC p_CharToOemA;
FARPROC p_CharToOemBuffA;
FARPROC p_CharToOemBuffW;
FARPROC p_CharToOemW;
FARPROC p_CharUpperA;
FARPROC p_CharUpperBuffA;
FARPROC p_CharUpperBuffW;
FARPROC p_CharUpperW;
FARPROC p_CheckDesktopByThreadId;
FARPROC p_CheckDlgButton;
FARPROC p_CheckMenuItem;
FARPROC p_CheckMenuRadioItem;
FARPROC p_CheckRadioButton;
FARPROC p_CheckWindowThreadDesktop;
FARPROC p_ChildWindowFromPoint;
FARPROC p_ChildWindowFromPointEx;
FARPROC p_CliImmSetHotKey;
FARPROC p_ClientThreadSetup;
FARPROC p_ClientToScreen;
FARPROC p_ClipCursor;
FARPROC p_CloseClipboard;
FARPROC p_CloseDesktop;
FARPROC p_CloseWindow;
FARPROC p_CloseWindowStation;
FARPROC p_CopyAcceleratorTableA;
FARPROC p_CopyAcceleratorTableW;
FARPROC p_CopyIcon;
FARPROC p_CopyImage;
FARPROC p_CopyRect;
FARPROC p_CountClipboardFormats;
FARPROC p_CreateAcceleratorTableA;
FARPROC p_CreateAcceleratorTableW;
FARPROC p_CreateCaret;
FARPROC p_CreateCursor;
FARPROC p_CreateDesktopA;
FARPROC p_CreateDesktopExA;
FARPROC p_CreateDesktopExW;
FARPROC p_CreateDesktopW;
FARPROC p_CreateDialogIndirectParamA;
FARPROC p_CreateDialogIndirectParamAorW;
FARPROC p_CreateDialogIndirectParamW;
FARPROC p_CreateDialogParamA;
FARPROC p_CreateDialogParamW;
FARPROC p_CreateIcon;
FARPROC p_CreateIconFromResource;
FARPROC p_CreateIconFromResourceEx;
FARPROC p_CreateIconIndirect;
FARPROC p_CreateMDIWindowA;
FARPROC p_CreateMDIWindowW;
FARPROC p_CreateMenu;
FARPROC p_CreatePopupMenu;
FARPROC p_CreateSystemThreads;
FARPROC p_CreateWindowExA;
FARPROC p_CreateWindowExW;
FARPROC p_CreateWindowStationA;
FARPROC p_CreateWindowStationW;
FARPROC p_CsrBroadcastSystemMessageExW;
FARPROC p_CtxInitUser32;
FARPROC p_DdeAbandonTransaction;
FARPROC p_DdeAccessData;
FARPROC p_DdeAddData;
FARPROC p_DdeClientTransaction;
FARPROC p_DdeCmpStringHandles;
FARPROC p_DdeConnect;
FARPROC p_DdeConnectList;
FARPROC p_DdeCreateDataHandle;
FARPROC p_DdeCreateStringHandleA;
FARPROC p_DdeCreateStringHandleW;
FARPROC p_DdeDisconnect;
FARPROC p_DdeDisconnectList;
FARPROC p_DdeEnableCallback;
FARPROC p_DdeFreeDataHandle;
FARPROC p_DdeFreeStringHandle;
FARPROC p_DdeGetData;
FARPROC p_DdeGetLastError;
FARPROC p_DdeGetQualityOfService;
FARPROC p_DdeImpersonateClient;
FARPROC p_DdeInitializeA;
FARPROC p_DdeInitializeW;
FARPROC p_DdeKeepStringHandle;
FARPROC p_DdeNameService;
FARPROC p_DdePostAdvise;
FARPROC p_DdeQueryConvInfo;
FARPROC p_DdeQueryNextServer;
FARPROC p_DdeQueryStringA;
FARPROC p_DdeQueryStringW;
FARPROC p_DdeReconnect;
FARPROC p_DdeSetQualityOfService;
FARPROC p_DdeSetUserHandle;
FARPROC p_DdeUnaccessData;
FARPROC p_DdeUninitialize;
FARPROC p_DefDlgProcA;
FARPROC p_DefDlgProcW;
FARPROC p_DefFrameProcA;
FARPROC p_DefFrameProcW;
FARPROC p_DefMDIChildProcA;
FARPROC p_DefMDIChildProcW;
FARPROC p_DefRawInputProc;
FARPROC p_DefWindowProcA;
FARPROC p_DefWindowProcW;
FARPROC p_DeferWindowPos;
FARPROC p_DeleteMenu;
FARPROC p_DeregisterShellHookWindow;
FARPROC p_DestroyAcceleratorTable;
FARPROC p_DestroyCaret;
FARPROC p_DestroyCursor;
FARPROC p_DestroyIcon;
FARPROC p_DestroyMenu;
FARPROC p_DestroyReasons;
FARPROC p_DestroyWindow;
FARPROC p_DeviceEventWorker;
FARPROC p_DialogBoxIndirectParamA;
FARPROC p_DialogBoxIndirectParamAorW;
FARPROC p_DialogBoxIndirectParamW;
FARPROC p_DialogBoxParamA;
FARPROC p_DialogBoxParamW;
FARPROC p_DisableProcessWindowsGhosting;
FARPROC p_DispatchMessageA;
FARPROC p_DispatchMessageW;
FARPROC p_DisplayExitWindowsWarnings;
FARPROC p_DlgDirListA;
FARPROC p_DlgDirListComboBoxA;
FARPROC p_DlgDirListComboBoxW;
FARPROC p_DlgDirListW;
FARPROC p_DlgDirSelectComboBoxExA;
FARPROC p_DlgDirSelectComboBoxExW;
FARPROC p_DlgDirSelectExA;
FARPROC p_DlgDirSelectExW;
FARPROC p_DoSoundConnect;
FARPROC p_DoSoundDisconnect;
FARPROC p_DragDetect;
FARPROC p_DragObject;
FARPROC p_DrawAnimatedRects;
FARPROC p_DrawCaption;
FARPROC p_DrawCaptionTempA;
FARPROC p_DrawCaptionTempW;
FARPROC p_DrawEdge;
FARPROC p_DrawFocusRect;
FARPROC p_DrawFrame;
FARPROC p_DrawFrameControl;
FARPROC p_DrawIcon;
FARPROC p_DrawIconEx;
FARPROC p_DrawMenuBar;
FARPROC p_DrawMenuBarTemp;
FARPROC p_DrawStateA;
FARPROC p_DrawStateW;
FARPROC p_DrawTextA;
FARPROC p_DrawTextExA;
FARPROC p_DrawTextExW;
FARPROC p_DrawTextW;
FARPROC p_DwmGetDxRgn;
FARPROC p_DwmHintDxUpdate;
FARPROC p_DwmStartRedirection;
FARPROC p_DwmStopRedirection;
FARPROC p_EditWndProc;
FARPROC p_EmptyClipboard;
FARPROC p_EnableMenuItem;
FARPROC p_EnableScrollBar;
FARPROC p_EnableWindow;
FARPROC p_EndDeferWindowPos;
FARPROC p_EndDialog;
FARPROC p_EndMenu;
FARPROC p_EndPaint;
FARPROC p_EndTask;
FARPROC p_EnterReaderModeHelper;
FARPROC p_EnumChildWindows;
FARPROC p_EnumClipboardFormats;
FARPROC p_EnumDesktopWindows;
FARPROC p_EnumDesktopsA;
FARPROC p_EnumDesktopsW;
FARPROC p_EnumDisplayDevicesA;
FARPROC p_EnumDisplayDevicesW;
FARPROC p_EnumDisplayMonitors;
FARPROC p_EnumDisplaySettingsA;
FARPROC p_EnumDisplaySettingsExA;
FARPROC p_EnumDisplaySettingsExW;
FARPROC p_EnumDisplaySettingsW;
FARPROC p_EnumPropsA;
FARPROC p_EnumPropsExA;
FARPROC p_EnumPropsExW;
FARPROC p_EnumPropsW;
FARPROC p_EnumThreadWindows;
FARPROC p_EnumWindowStationsA;
FARPROC p_EnumWindowStationsW;
FARPROC p_EnumWindows;
FARPROC p_EqualRect;
FARPROC p_ExcludeUpdateRgn;
FARPROC p_ExitWindowsEx;
FARPROC p_FillRect;
FARPROC p_FindWindowA;
FARPROC p_FindWindowExA;
FARPROC p_FindWindowExW;
FARPROC p_FindWindowW;
FARPROC p_FlashWindow;
FARPROC p_FlashWindowEx;
FARPROC p_FrameRect;
FARPROC p_FreeDDElParam;
FARPROC p_FrostCrashedWindow;
FARPROC p_GetActiveWindow;
FARPROC p_GetAltTabInfo;
FARPROC p_GetAltTabInfoA;
FARPROC p_GetAltTabInfoW;
FARPROC p_GetAncestor;
FARPROC p_GetAppCompatFlags2;
FARPROC p_GetAppCompatFlags;
FARPROC p_GetAsyncKeyState;
FARPROC p_GetCapture;
FARPROC p_GetCaretBlinkTime;
FARPROC p_GetCaretPos;
FARPROC p_GetClassInfoA;
FARPROC p_GetClassInfoExA;
FARPROC p_GetClassInfoExW;
FARPROC p_GetClassInfoW;
FARPROC p_GetClassLongA;
FARPROC p_GetClassLongW;
FARPROC p_GetClassNameA;
FARPROC p_GetClassNameW;
FARPROC p_GetClassWord;
FARPROC p_GetClientRect;
FARPROC p_GetClipCursor;
FARPROC p_GetClipboardData;
FARPROC p_GetClipboardFormatNameA;
FARPROC p_GetClipboardFormatNameW;
FARPROC p_GetClipboardOwner;
FARPROC p_GetClipboardSequenceNumber;
FARPROC p_GetClipboardViewer;
FARPROC p_GetComboBoxInfo;
FARPROC p_GetCursor;
FARPROC p_GetCursorFrameInfo;
FARPROC p_GetCursorInfo;
FARPROC p_GetCursorPos;
FARPROC p_GetDC;
FARPROC p_GetDCEx;
FARPROC p_GetDesktopWindow;
FARPROC p_GetDialogBaseUnits;
FARPROC p_GetDlgCtrlID;
FARPROC p_GetDlgItem;
FARPROC p_GetDlgItemInt;
FARPROC p_GetDlgItemTextA;
FARPROC p_GetDlgItemTextW;
FARPROC p_GetDoubleClickTime;
FARPROC p_GetFocus;
FARPROC p_GetForegroundWindow;
FARPROC p_GetGUIThreadInfo;
FARPROC p_GetGuiResources;
FARPROC p_GetIconInfo;
FARPROC p_GetIconInfoExA;
FARPROC p_GetIconInfoExW;
FARPROC p_GetInputDesktop;
FARPROC p_GetInputState;
FARPROC p_GetInternalWindowPos;
FARPROC p_GetKBCodePage;
FARPROC p_GetKeyNameTextA;
FARPROC p_GetKeyNameTextW;
FARPROC p_GetKeyState;
FARPROC p_GetKeyboardLayout;
FARPROC p_GetKeyboardLayoutList;
FARPROC p_GetKeyboardLayoutNameA;
FARPROC p_GetKeyboardLayoutNameW;
FARPROC p_GetKeyboardState;
FARPROC p_GetKeyboardType;
FARPROC p_GetLastActivePopup;
FARPROC p_GetLastInputInfo;
FARPROC p_GetLayeredWindowAttributes;
FARPROC p_GetListBoxInfo;
FARPROC p_GetMenu;
FARPROC p_GetMenuBarInfo;
FARPROC p_GetMenuCheckMarkDimensions;
FARPROC p_GetMenuContextHelpId;
FARPROC p_GetMenuDefaultItem;
FARPROC p_GetMenuInfo;
FARPROC p_GetMenuItemCount;
FARPROC p_GetMenuItemID;
FARPROC p_GetMenuItemInfoA;
FARPROC p_GetMenuItemInfoW;
FARPROC p_GetMenuItemRect;
FARPROC p_GetMenuState;
FARPROC p_GetMenuStringA;
FARPROC p_GetMenuStringW;
FARPROC p_GetMessageA;
FARPROC p_GetMessageExtraInfo;
FARPROC p_GetMessagePos;
FARPROC p_GetMessageTime;
FARPROC p_GetMessageW;
FARPROC p_GetMonitorInfoA;
FARPROC p_GetMonitorInfoW;
FARPROC p_GetMouseMovePointsEx;
FARPROC p_GetNextDlgGroupItem;
FARPROC p_GetNextDlgTabItem;
FARPROC p_GetOpenClipboardWindow;
FARPROC p_GetParent;
FARPROC p_GetPhysicalCursorPos;
FARPROC p_GetPriorityClipboardFormat;
FARPROC p_GetProcessDefaultLayout;
FARPROC p_GetProcessWindowStation;
FARPROC p_GetProgmanWindow;
FARPROC p_GetPropA;
FARPROC p_GetPropW;
FARPROC p_GetQueueStatus;
FARPROC p_GetRawInputBuffer;
FARPROC p_GetRawInputData;
FARPROC p_GetRawInputDeviceInfoA;
FARPROC p_GetRawInputDeviceInfoW;
FARPROC p_GetRawInputDeviceList;
FARPROC p_GetReasonTitleFromReasonCode;
FARPROC p_GetRegisteredRawInputDevices;
FARPROC p_GetScrollBarInfo;
FARPROC p_GetScrollInfo;
FARPROC p_GetScrollPos;
FARPROC p_GetScrollRange;
FARPROC p_GetSendMessageReceiver;
FARPROC p_GetShellWindow;
FARPROC p_GetSubMenu;
FARPROC p_GetSysColor;
FARPROC p_GetSysColorBrush;
FARPROC p_GetSystemMenu;
FARPROC p_GetSystemMetrics;
FARPROC p_GetTabbedTextExtentA;
FARPROC p_GetTabbedTextExtentW;
FARPROC p_GetTaskmanWindow;
FARPROC p_GetThreadDesktop;
FARPROC p_GetTitleBarInfo;
FARPROC p_GetTopWindow;
FARPROC p_GetUpdateRect;
FARPROC p_GetUpdateRgn;
FARPROC p_GetUpdatedClipboardFormats;
FARPROC p_GetUserObjectInformationA;
FARPROC p_GetUserObjectInformationW;
FARPROC p_GetUserObjectSecurity;
FARPROC p_GetWinStationInfo;
FARPROC p_GetWindow;
FARPROC p_GetWindowContextHelpId;
FARPROC p_GetWindowDC;
FARPROC p_GetWindowInfo;
FARPROC p_GetWindowLongA;
FARPROC p_GetWindowLongW;
FARPROC p_GetWindowMinimizeRect;
FARPROC p_GetWindowModuleFileName;
FARPROC p_GetWindowModuleFileNameA;
FARPROC p_GetWindowModuleFileNameW;
FARPROC p_GetWindowPlacement;
FARPROC p_GetWindowRect;
FARPROC p_GetWindowRgn;
FARPROC p_GetWindowRgnBox;
FARPROC p_GetWindowRgnEx;
FARPROC p_GetWindowTextA;
FARPROC p_GetWindowTextLengthA;
FARPROC p_GetWindowTextLengthW;
FARPROC p_GetWindowTextW;
FARPROC p_GetWindowThreadProcessId;
FARPROC p_GetWindowWord;
FARPROC p_GhostWindowFromHungWindow;
FARPROC p_GrayStringA;
FARPROC p_GrayStringW;
FARPROC p_HideCaret;
FARPROC p_HiliteMenuItem;
FARPROC p_HungWindowFromGhostWindow;
FARPROC p_IMPGetIMEA;
FARPROC p_IMPGetIMEW;
FARPROC p_IMPQueryIMEA;
FARPROC p_IMPQueryIMEW;
FARPROC p_IMPSetIMEA;
FARPROC p_IMPSetIMEW;
FARPROC p_ImpersonateDdeClientWindow;
FARPROC p_InSendMessage;
FARPROC p_InSendMessageEx;
FARPROC p_InflateRect;
FARPROC p_InitializeLpkHooks;
FARPROC p_InsertMenuA;
FARPROC p_InsertMenuItemA;
FARPROC p_InsertMenuItemW;
FARPROC p_InsertMenuW;
FARPROC p_InternalGetWindowIcon;
FARPROC p_InternalGetWindowText;
FARPROC p_IntersectRect;
FARPROC p_InvalidateRect;
FARPROC p_InvalidateRgn;
FARPROC p_InvertRect;
FARPROC p_IsCharAlphaA;
FARPROC p_IsCharAlphaNumericA;
FARPROC p_IsCharAlphaNumericW;
FARPROC p_IsCharAlphaW;
FARPROC p_IsCharLowerA;
FARPROC p_IsCharLowerW;
FARPROC p_IsCharUpperA;
FARPROC p_IsCharUpperW;
FARPROC p_IsChild;
FARPROC p_IsClipboardFormatAvailable;
FARPROC p_IsDialogMessage;
FARPROC p_IsDialogMessageA;
FARPROC p_IsDialogMessageW;
FARPROC p_IsDlgButtonChecked;
FARPROC p_IsGUIThread;
FARPROC p_IsHungAppWindow;
FARPROC p_IsIconic;
FARPROC p_IsMenu;
FARPROC p_IsProcessDPIAware;
FARPROC p_IsRectEmpty;
FARPROC p_IsSETEnabled;
FARPROC p_IsServerSideWindow;
FARPROC p_IsThreadDesktopComposited;
FARPROC p_IsWinEventHookInstalled;
FARPROC p_IsWindow;
FARPROC p_IsWindowEnabled;
FARPROC p_IsWindowInDestroy;
FARPROC p_IsWindowRedirectedForPrint;
FARPROC p_IsWindowUnicode;
FARPROC p_IsWindowVisible;
FARPROC p_IsWow64Message;
FARPROC p_IsZoomed;
FARPROC p_KillTimer;
FARPROC p_LoadAcceleratorsA;
FARPROC p_LoadAcceleratorsW;
FARPROC p_LoadBitmapA;
FARPROC p_LoadBitmapW;
FARPROC p_LoadCursorA;
FARPROC p_LoadCursorFromFileA;
FARPROC p_LoadCursorFromFileW;
FARPROC p_LoadCursorW;
FARPROC p_LoadIconA;
FARPROC p_LoadIconW;
FARPROC p_LoadImageA;
FARPROC p_LoadImageW;
FARPROC p_LoadKeyboardLayoutA;
FARPROC p_LoadKeyboardLayoutEx;
FARPROC p_LoadKeyboardLayoutW;
FARPROC p_LoadLocalFonts;
FARPROC p_LoadMenuA;
FARPROC p_LoadMenuIndirectA;
FARPROC p_LoadMenuIndirectW;
FARPROC p_LoadMenuW;
FARPROC p_LoadRemoteFonts;
FARPROC p_LoadStringA;
FARPROC p_LoadStringW;
FARPROC p_LockSetForegroundWindow;
FARPROC p_LockWindowStation;
FARPROC p_LockWindowUpdate;
FARPROC p_LockWorkStation;
FARPROC p_LogicalToPhysicalPoint;
FARPROC p_LookupIconIdFromDirectory;
FARPROC p_LookupIconIdFromDirectoryEx;
FARPROC p_MBToWCSEx;
FARPROC p_MB_GetString;
FARPROC p_MapDialogRect;
FARPROC p_MapVirtualKeyA;
FARPROC p_MapVirtualKeyExA;
FARPROC p_MapVirtualKeyExW;
FARPROC p_MapVirtualKeyW;
FARPROC p_MapWindowPoints;
FARPROC p_MenuItemFromPoint;
FARPROC p_MenuWindowProcA;
FARPROC p_MenuWindowProcW;
FARPROC p_MessageBeep;
FARPROC p_MessageBoxA;
FARPROC p_MessageBoxExA;
FARPROC p_MessageBoxExW;
FARPROC p_MessageBoxIndirectA;
FARPROC p_MessageBoxIndirectW;
FARPROC p_MessageBoxTimeoutA;
FARPROC p_MessageBoxTimeoutW;
FARPROC p_MessageBoxW;
FARPROC p_ModifyMenuA;
FARPROC p_ModifyMenuW;
FARPROC p_MonitorFromPoint;
FARPROC p_MonitorFromRect;
FARPROC p_MonitorFromWindow;
FARPROC p_MoveWindow;
FARPROC p_MsgWaitForMultipleObjects;
FARPROC p_MsgWaitForMultipleObjectsEx;
FARPROC p_NotifyWinEvent;
FARPROC p_OemKeyScan;
FARPROC p_OemToCharA;
FARPROC p_OemToCharBuffA;
FARPROC p_OemToCharBuffW;
FARPROC p_OemToCharW;
FARPROC p_OffsetRect;
FARPROC p_OpenClipboard;
FARPROC p_OpenDesktopA;
FARPROC p_OpenDesktopW;
FARPROC p_OpenIcon;
FARPROC p_OpenInputDesktop;
FARPROC p_OpenThreadDesktop;
FARPROC p_OpenWindowStationA;
FARPROC p_OpenWindowStationW;
FARPROC p_PackDDElParam;
FARPROC p_PaintDesktop;
FARPROC p_PaintMenuBar;
FARPROC p_PaintMonitor;
FARPROC p_PeekMessageA;
FARPROC p_PeekMessageW;
FARPROC p_PhysicalToLogicalPoint;
FARPROC p_PostMessageA;
FARPROC p_PostMessageW;
FARPROC p_PostQuitMessage;
FARPROC p_PostThreadMessageA;
FARPROC p_PostThreadMessageW;
FARPROC p_PrintWindow;
FARPROC p_PrivateExtractIconExA;
FARPROC p_PrivateExtractIconExW;
FARPROC p_PrivateExtractIconsA;
FARPROC p_PrivateExtractIconsW;
FARPROC p_PrivateRegisterICSProc;
FARPROC p_PtInRect;
FARPROC p_QuerySendMessage;
FARPROC p_RealChildWindowFromPoint;
FARPROC p_RealGetWindowClass;
FARPROC p_RealGetWindowClassA;
FARPROC p_RealGetWindowClassW;
FARPROC p_ReasonCodeNeedsBugID;
FARPROC p_ReasonCodeNeedsComment;
FARPROC p_RecordShutdownReason;
FARPROC p_RedrawWindow;
FARPROC p_RegisterClassA;
FARPROC p_RegisterClassExA;
FARPROC p_RegisterClassExW;
FARPROC p_RegisterClassW;
FARPROC p_RegisterClipboardFormatA;
FARPROC p_RegisterClipboardFormatW;
FARPROC p_RegisterDeviceNotificationA;
FARPROC p_RegisterDeviceNotificationW;
FARPROC p_RegisterErrorReportingDialog;
FARPROC p_RegisterFrostWindow;
FARPROC p_RegisterGhostWindow;
FARPROC p_RegisterHotKey;
FARPROC p_RegisterLogonProcess;
FARPROC p_RegisterMessagePumpHook;
FARPROC p_RegisterPowerSettingNotification;
FARPROC p_RegisterRawInputDevices;
FARPROC p_RegisterServicesProcess;
FARPROC p_RegisterSessionPort;
FARPROC p_RegisterShellHookWindow;
FARPROC p_RegisterSystemThread;
FARPROC p_RegisterTasklist;
FARPROC p_RegisterUserApiHook;
FARPROC p_RegisterWindowMessageA;
FARPROC p_RegisterWindowMessageW;
FARPROC p_ReleaseCapture;
FARPROC p_ReleaseDC;
FARPROC p_RemoveClipboardFormatListener;
FARPROC p_RemoveMenu;
FARPROC p_RemovePropA;
FARPROC p_RemovePropW;
FARPROC p_ReplyMessage;
FARPROC p_ResolveDesktopForWOW;
FARPROC p_ReuseDDElParam;
FARPROC p_ScreenToClient;
FARPROC p_ScrollChildren;
FARPROC p_ScrollDC;
FARPROC p_ScrollWindow;
FARPROC p_ScrollWindowEx;
FARPROC p_SendDlgItemMessageA;
FARPROC p_SendDlgItemMessageW;
FARPROC p_SendIMEMessageExA;
FARPROC p_SendIMEMessageExW;
FARPROC p_SendInput;
FARPROC p_SendMessageA;
FARPROC p_SendMessageCallbackA;
FARPROC p_SendMessageCallbackW;
FARPROC p_SendMessageTimeoutA;
FARPROC p_SendMessageTimeoutW;
FARPROC p_SendMessageW;
FARPROC p_SendNotifyMessageA;
FARPROC p_SendNotifyMessageW;
FARPROC p_SetActiveWindow;
FARPROC p_SetCapture;
FARPROC p_SetCaretBlinkTime;
FARPROC p_SetCaretPos;
FARPROC p_SetClassLongA;
FARPROC p_SetClassLongW;
FARPROC p_SetClassWord;
FARPROC p_SetClipboardData;
FARPROC p_SetClipboardViewer;
FARPROC p_SetConsoleReserveKeys;
FARPROC p_SetCursor;
FARPROC p_SetCursorContents;
FARPROC p_SetCursorPos;
FARPROC p_SetDebugErrorLevel;
FARPROC p_SetDeskWallpaper;
FARPROC p_SetDlgItemInt;
FARPROC p_SetDlgItemTextA;
FARPROC p_SetDlgItemTextW;
FARPROC p_SetDoubleClickTime;
FARPROC p_SetFocus;
FARPROC p_SetForegroundWindow;
FARPROC p_SetInternalWindowPos;
FARPROC p_SetKeyboardState;
FARPROC p_SetLastErrorEx;
FARPROC p_SetLayeredWindowAttributes;
FARPROC p_SetMenu;
FARPROC p_SetMenuContextHelpId;
FARPROC p_SetMenuDefaultItem;
FARPROC p_SetMenuInfo;
FARPROC p_SetMenuItemBitmaps;
FARPROC p_SetMenuItemInfoA;
FARPROC p_SetMenuItemInfoW;
FARPROC p_SetMessageExtraInfo;
FARPROC p_SetMessageQueue;
FARPROC p_SetMirrorRendering;
FARPROC p_SetParent;
FARPROC p_SetPhysicalCursorPos;
FARPROC p_SetProcessDPIAware;
FARPROC p_SetProcessDefaultLayout;
FARPROC p_SetProcessWindowStation;
FARPROC p_SetProgmanWindow;
FARPROC p_SetPropA;
FARPROC p_SetPropW;
FARPROC p_SetRect;
FARPROC p_SetRectEmpty;
FARPROC p_SetScrollInfo;
FARPROC p_SetScrollPos;
FARPROC p_SetScrollRange;
FARPROC p_SetShellWindow;
FARPROC p_SetShellWindowEx;
FARPROC p_SetSysColors;
FARPROC p_SetSysColorsTemp;
FARPROC p_SetSystemCursor;
FARPROC p_SetSystemMenu;
FARPROC p_SetTaskmanWindow;
FARPROC p_SetThreadDesktop;
FARPROC p_SetTimer;
FARPROC p_SetUserObjectInformationA;
FARPROC p_SetUserObjectInformationW;
FARPROC p_SetUserObjectSecurity;
FARPROC p_SetWinEventHook;
FARPROC p_SetWindowContextHelpId;
FARPROC p_SetWindowLongA;
FARPROC p_SetWindowLongW;
FARPROC p_SetWindowPlacement;
FARPROC p_SetWindowPos;
FARPROC p_SetWindowRgn;
FARPROC p_SetWindowRgnEx;
FARPROC p_SetWindowStationUser;
FARPROC p_SetWindowTextA;
FARPROC p_SetWindowTextW;
FARPROC p_SetWindowWord;
FARPROC p_SetWindowsHookA;
FARPROC p_SetWindowsHookExA;
FARPROC p_SetWindowsHookExW;
FARPROC p_SetWindowsHookW;
FARPROC p_ShowCaret;
FARPROC p_ShowCursor;
FARPROC p_ShowOwnedPopups;
FARPROC p_ShowScrollBar;
FARPROC p_ShowStartGlass;
FARPROC p_ShowSystemCursor;
FARPROC p_ShowWindow;
FARPROC p_ShowWindowAsync;
FARPROC p_ShutdownBlockReasonCreate;
FARPROC p_ShutdownBlockReasonDestroy;
FARPROC p_ShutdownBlockReasonQuery;
FARPROC p_SoftModalMessageBox;
FARPROC p_SoundSentry;
FARPROC p_SubtractRect;
FARPROC p_SwapMouseButton;
FARPROC p_SwitchDesktop;
FARPROC p_SwitchDesktopWithFade;
FARPROC p_SwitchToThisWindow;
FARPROC p_SystemParametersInfoA;
FARPROC p_SystemParametersInfoW;
FARPROC p_TabbedTextOutA;
FARPROC p_TabbedTextOutW;
FARPROC p_TileChildWindows;
FARPROC p_TileWindows;
FARPROC p_ToAscii;
FARPROC p_ToAsciiEx;
FARPROC p_ToUnicode;
FARPROC p_ToUnicodeEx;
FARPROC p_TrackMouseEvent;
FARPROC p_TrackPopupMenu;
FARPROC p_TrackPopupMenuEx;
FARPROC p_TranslateAccelerator;
FARPROC p_TranslateAcceleratorA;
FARPROC p_TranslateAcceleratorW;
FARPROC p_TranslateMDISysAccel;
FARPROC p_TranslateMessage;
FARPROC p_TranslateMessageEx;
FARPROC p_UnhookWinEvent;
FARPROC p_UnhookWindowsHook;
FARPROC p_UnhookWindowsHookEx;
FARPROC p_UnionRect;
FARPROC p_UnloadKeyboardLayout;
FARPROC p_UnlockWindowStation;
FARPROC p_UnpackDDElParam;
FARPROC p_UnregisterClassA;
FARPROC p_UnregisterClassW;
FARPROC p_UnregisterDeviceNotification;
FARPROC p_UnregisterHotKey;
FARPROC p_UnregisterMessagePumpHook;
FARPROC p_UnregisterPowerSettingNotification;
FARPROC p_UnregisterSessionPort;
FARPROC p_UnregisterUserApiHook;
FARPROC p_UpdateLayeredWindow;
FARPROC p_UpdateLayeredWindowIndirect;
FARPROC p_UpdatePerUserSystemParameters;
FARPROC p_UpdateWindow;
FARPROC p_UpdateWindowTransform;
FARPROC p_User32InitializeImmEntryTable;
FARPROC p_UserClientDllInitialize;
FARPROC p_UserHandleGrantAccess;
FARPROC p_UserLpkPSMTextOut;
FARPROC p_UserLpkTabbedTextOut;
FARPROC p_UserRealizePalette;
FARPROC p_UserRegisterWowHandlers;
FARPROC p_ValidateRect;
FARPROC p_ValidateRgn;
FARPROC p_VkKeyScanA;
FARPROC p_VkKeyScanExA;
FARPROC p_VkKeyScanExW;
FARPROC p_VkKeyScanW;
FARPROC p_WCSToMBEx;
FARPROC p_WINNLSEnableIME;
FARPROC p_WINNLSGetEnableStatus;
FARPROC p_WINNLSGetIMEHotkey;
FARPROC p_WaitForInputIdle;
FARPROC p_WaitMessage;
FARPROC p_Win32PoolAllocationStats;
FARPROC p_WinHelpA;
FARPROC p_WinHelpW;
FARPROC p_WindowFromDC;
FARPROC p_WindowFromPhysicalPoint;
FARPROC p_WindowFromPoint;
FARPROC p__UserTestTokenForInteractive;
FARPROC p_keybd_event;
FARPROC p_mouse_event;
FARPROC p_wsprintfA;
FARPROC p_wsprintfW;
FARPROC p_wvsprintfA;
FARPROC p_wvsprintfW;

FARPROC p_GetGestureInfo;
FARPROC p_GetGestureConfig;
FARPROC p_SetGestureConfig;
FARPROC p_CloseGestureInfoHandle;


extern "C" {
__declspec( naked ) void WINAPI d_NONAME1() { _asm{ jmp p_NONAME1 } }
__declspec( naked ) void WINAPI d_ActivateKeyboardLayout() { _asm{ jmp p_ActivateKeyboardLayout } }
__declspec( naked ) void WINAPI d_AddClipboardFormatListener() { _asm{ jmp p_AddClipboardFormatListener } }
__declspec( naked ) void WINAPI d_AdjustWindowRect() { _asm{ jmp p_AdjustWindowRect } }
__declspec( naked ) void WINAPI d_AdjustWindowRectEx() { _asm{ jmp p_AdjustWindowRectEx } }
__declspec( naked ) void WINAPI d_AlignRects() { _asm{ jmp p_AlignRects } }
__declspec( naked ) void WINAPI d_AllowForegroundActivation() { _asm{ jmp p_AllowForegroundActivation } }
__declspec( naked ) void WINAPI d_AllowSetForegroundWindow() { _asm{ jmp p_AllowSetForegroundWindow } }
__declspec( naked ) void WINAPI d_AnimateWindow() { _asm{ jmp p_AnimateWindow } }
__declspec( naked ) void WINAPI d_AnyPopup() { _asm{ jmp p_AnyPopup } }
__declspec( naked ) void WINAPI d_AppendMenuA() { _asm{ jmp p_AppendMenuA } }
__declspec( naked ) void WINAPI d_AppendMenuW() { _asm{ jmp p_AppendMenuW } }
__declspec( naked ) void WINAPI d_ArrangeIconicWindows() { _asm{ jmp p_ArrangeIconicWindows } }
__declspec( naked ) void WINAPI d_AttachThreadInput() { _asm{ jmp p_AttachThreadInput } }
__declspec( naked ) void WINAPI d_BeginDeferWindowPos() { _asm{ jmp p_BeginDeferWindowPos } }
__declspec( naked ) void WINAPI d_BeginPaint() { _asm{ jmp p_BeginPaint } }
__declspec( naked ) void WINAPI d_BlockInput() { _asm{ jmp p_BlockInput } }
__declspec( naked ) void WINAPI d_BringWindowToTop() { _asm{ jmp p_BringWindowToTop } }
__declspec( naked ) void WINAPI d_BroadcastSystemMessage() { _asm{ jmp p_BroadcastSystemMessage } }
__declspec( naked ) void WINAPI d_BroadcastSystemMessageA() { _asm{ jmp p_BroadcastSystemMessageA } }
__declspec( naked ) void WINAPI d_BroadcastSystemMessageExA() { _asm{ jmp p_BroadcastSystemMessageExA } }
__declspec( naked ) void WINAPI d_BroadcastSystemMessageExW() { _asm{ jmp p_BroadcastSystemMessageExW } }
__declspec( naked ) void WINAPI d_BroadcastSystemMessageW() { _asm{ jmp p_BroadcastSystemMessageW } }
__declspec( naked ) void WINAPI d_BuildReasonArray() { _asm{ jmp p_BuildReasonArray } }
__declspec( naked ) void WINAPI d_CalcMenuBar() { _asm{ jmp p_CalcMenuBar } }
__declspec( naked ) void WINAPI d_CallMsgFilter() { _asm{ jmp p_CallMsgFilter } }
__declspec( naked ) void WINAPI d_CallMsgFilterA() { _asm{ jmp p_CallMsgFilterA } }
__declspec( naked ) void WINAPI d_CallMsgFilterW() { _asm{ jmp p_CallMsgFilterW } }
__declspec( naked ) void WINAPI d_CallNextHookEx() { _asm{ jmp p_CallNextHookEx } }
__declspec( naked ) void WINAPI d_CallWindowProcA() { _asm{ jmp p_CallWindowProcA } }
__declspec( naked ) void WINAPI d_CallWindowProcW() { _asm{ jmp p_CallWindowProcW } }
__declspec( naked ) void WINAPI d_CancelShutdown() { _asm{ jmp p_CancelShutdown } }
__declspec( naked ) void WINAPI d_CascadeChildWindows() { _asm{ jmp p_CascadeChildWindows } }
__declspec( naked ) void WINAPI d_CascadeWindows() { _asm{ jmp p_CascadeWindows } }
__declspec( naked ) void WINAPI d_ChangeClipboardChain() { _asm{ jmp p_ChangeClipboardChain } }
__declspec( naked ) void WINAPI d_ChangeDisplaySettingsA() { _asm{ jmp p_ChangeDisplaySettingsA } }
__declspec( naked ) void WINAPI d_ChangeDisplaySettingsExA() { _asm{ jmp p_ChangeDisplaySettingsExA } }
__declspec( naked ) void WINAPI d_ChangeDisplaySettingsExW() { _asm{ jmp p_ChangeDisplaySettingsExW } }
__declspec( naked ) void WINAPI d_ChangeDisplaySettingsW() { _asm{ jmp p_ChangeDisplaySettingsW } }
__declspec( naked ) void WINAPI d_ChangeMenuA() { _asm{ jmp p_ChangeMenuA } }
__declspec( naked ) void WINAPI d_ChangeMenuW() { _asm{ jmp p_ChangeMenuW } }
__declspec( naked ) void WINAPI d_ChangeWindowMessageFilter() { _asm{ jmp p_ChangeWindowMessageFilter } }
__declspec( naked ) void WINAPI d_CharLowerA() { _asm{ jmp p_CharLowerA } }
__declspec( naked ) void WINAPI d_CharLowerBuffA() { _asm{ jmp p_CharLowerBuffA } }
__declspec( naked ) void WINAPI d_CharLowerBuffW() { _asm{ jmp p_CharLowerBuffW } }
__declspec( naked ) void WINAPI d_CharLowerW() { _asm{ jmp p_CharLowerW } }
__declspec( naked ) void WINAPI d_CharNextA() { _asm{ jmp p_CharNextA } }
__declspec( naked ) void WINAPI d_CharNextExA() { _asm{ jmp p_CharNextExA } }
__declspec( naked ) void WINAPI d_CharNextW() { _asm{ jmp p_CharNextW } }
__declspec( naked ) void WINAPI d_CharPrevA() { _asm{ jmp p_CharPrevA } }
__declspec( naked ) void WINAPI d_CharPrevExA() { _asm{ jmp p_CharPrevExA } }
__declspec( naked ) void WINAPI d_CharPrevW() { _asm{ jmp p_CharPrevW } }
__declspec( naked ) void WINAPI d_CharToOemA() { _asm{ jmp p_CharToOemA } }
__declspec( naked ) void WINAPI d_CharToOemBuffA() { _asm{ jmp p_CharToOemBuffA } }
__declspec( naked ) void WINAPI d_CharToOemBuffW() { _asm{ jmp p_CharToOemBuffW } }
__declspec( naked ) void WINAPI d_CharToOemW() { _asm{ jmp p_CharToOemW } }
__declspec( naked ) void WINAPI d_CharUpperA() { _asm{ jmp p_CharUpperA } }
__declspec( naked ) void WINAPI d_CharUpperBuffA() { _asm{ jmp p_CharUpperBuffA } }
__declspec( naked ) void WINAPI d_CharUpperBuffW() { _asm{ jmp p_CharUpperBuffW } }
__declspec( naked ) void WINAPI d_CharUpperW() { _asm{ jmp p_CharUpperW } }
__declspec( naked ) void WINAPI d_CheckDesktopByThreadId() { _asm{ jmp p_CheckDesktopByThreadId } }
__declspec( naked ) void WINAPI d_CheckDlgButton() { _asm{ jmp p_CheckDlgButton } }
__declspec( naked ) void WINAPI d_CheckMenuItem() { _asm{ jmp p_CheckMenuItem } }
__declspec( naked ) void WINAPI d_CheckMenuRadioItem() { _asm{ jmp p_CheckMenuRadioItem } }
__declspec( naked ) void WINAPI d_CheckRadioButton() { _asm{ jmp p_CheckRadioButton } }
__declspec( naked ) void WINAPI d_CheckWindowThreadDesktop() { _asm{ jmp p_CheckWindowThreadDesktop } }
__declspec( naked ) void WINAPI d_ChildWindowFromPoint() { _asm{ jmp p_ChildWindowFromPoint } }
__declspec( naked ) void WINAPI d_ChildWindowFromPointEx() { _asm{ jmp p_ChildWindowFromPointEx } }
__declspec( naked ) void WINAPI d_CliImmSetHotKey() { _asm{ jmp p_CliImmSetHotKey } }
__declspec( naked ) void WINAPI d_ClientThreadSetup() { _asm{ jmp p_ClientThreadSetup } }
__declspec( naked ) void WINAPI d_ClientToScreen() { _asm{ jmp p_ClientToScreen } }
__declspec( naked ) void WINAPI d_ClipCursor() { _asm{ jmp p_ClipCursor } }
__declspec( naked ) void WINAPI d_CloseClipboard() { _asm{ jmp p_CloseClipboard } }
__declspec( naked ) void WINAPI d_CloseDesktop() { _asm{ jmp p_CloseDesktop } }
__declspec( naked ) void WINAPI d_CloseWindow() { _asm{ jmp p_CloseWindow } }
__declspec( naked ) void WINAPI d_CloseWindowStation() { _asm{ jmp p_CloseWindowStation } }
__declspec( naked ) void WINAPI d_CopyAcceleratorTableA() { _asm{ jmp p_CopyAcceleratorTableA } }
__declspec( naked ) void WINAPI d_CopyAcceleratorTableW() { _asm{ jmp p_CopyAcceleratorTableW } }
__declspec( naked ) void WINAPI d_CopyIcon() { _asm{ jmp p_CopyIcon } }
__declspec( naked ) void WINAPI d_CopyImage() { _asm{ jmp p_CopyImage } }
__declspec( naked ) void WINAPI d_CopyRect() { _asm{ jmp p_CopyRect } }
__declspec( naked ) void WINAPI d_CountClipboardFormats() { _asm{ jmp p_CountClipboardFormats } }
__declspec( naked ) void WINAPI d_CreateAcceleratorTableA() { _asm{ jmp p_CreateAcceleratorTableA } }
__declspec( naked ) void WINAPI d_CreateAcceleratorTableW() { _asm{ jmp p_CreateAcceleratorTableW } }
__declspec( naked ) void WINAPI d_CreateCaret() { _asm{ jmp p_CreateCaret } }
__declspec( naked ) void WINAPI d_CreateCursor() { _asm{ jmp p_CreateCursor } }
__declspec( naked ) void WINAPI d_CreateDesktopA() { _asm{ jmp p_CreateDesktopA } }
__declspec( naked ) void WINAPI d_CreateDesktopExA() { _asm{ jmp p_CreateDesktopExA } }
__declspec( naked ) void WINAPI d_CreateDesktopExW() { _asm{ jmp p_CreateDesktopExW } }
__declspec( naked ) void WINAPI d_CreateDesktopW() { _asm{ jmp p_CreateDesktopW } }
__declspec( naked ) void WINAPI d_CreateDialogIndirectParamA() { _asm{ jmp p_CreateDialogIndirectParamA } }
__declspec( naked ) void WINAPI d_CreateDialogIndirectParamAorW() { _asm{ jmp p_CreateDialogIndirectParamAorW } }
__declspec( naked ) void WINAPI d_CreateDialogIndirectParamW() { _asm{ jmp p_CreateDialogIndirectParamW } }
__declspec( naked ) void WINAPI d_CreateDialogParamA() { _asm{ jmp p_CreateDialogParamA } }
__declspec( naked ) void WINAPI d_CreateDialogParamW() { _asm{ jmp p_CreateDialogParamW } }
__declspec( naked ) void WINAPI d_CreateIcon() { _asm{ jmp p_CreateIcon } }
__declspec( naked ) void WINAPI d_CreateIconFromResource() { _asm{ jmp p_CreateIconFromResource } }
__declspec( naked ) void WINAPI d_CreateIconFromResourceEx() { _asm{ jmp p_CreateIconFromResourceEx } }
__declspec( naked ) void WINAPI d_CreateIconIndirect() { _asm{ jmp p_CreateIconIndirect } }
__declspec( naked ) void WINAPI d_CreateMDIWindowA() { _asm{ jmp p_CreateMDIWindowA } }
__declspec( naked ) void WINAPI d_CreateMDIWindowW() { _asm{ jmp p_CreateMDIWindowW } }
__declspec( naked ) void WINAPI d_CreateMenu() { _asm{ jmp p_CreateMenu } }
__declspec( naked ) void WINAPI d_CreatePopupMenu() { _asm{ jmp p_CreatePopupMenu } }
__declspec( naked ) void WINAPI d_CreateSystemThreads() { _asm{ jmp p_CreateSystemThreads } }
__declspec( naked ) void WINAPI d_CreateWindowExA() { _asm{ jmp p_CreateWindowExA } }
__declspec( naked ) void WINAPI d_CreateWindowExW() { _asm{ jmp p_CreateWindowExW } }
__declspec( naked ) void WINAPI d_CreateWindowStationA() { _asm{ jmp p_CreateWindowStationA } }
__declspec( naked ) void WINAPI d_CreateWindowStationW() { _asm{ jmp p_CreateWindowStationW } }
__declspec( naked ) void WINAPI d_CsrBroadcastSystemMessageExW() { _asm{ jmp p_CsrBroadcastSystemMessageExW } }
__declspec( naked ) void WINAPI d_CtxInitUser32() { _asm{ jmp p_CtxInitUser32 } }
__declspec( naked ) void WINAPI d_DdeAbandonTransaction() { _asm{ jmp p_DdeAbandonTransaction } }
__declspec( naked ) void WINAPI d_DdeAccessData() { _asm{ jmp p_DdeAccessData } }
__declspec( naked ) void WINAPI d_DdeAddData() { _asm{ jmp p_DdeAddData } }
__declspec( naked ) void WINAPI d_DdeClientTransaction() { _asm{ jmp p_DdeClientTransaction } }
__declspec( naked ) void WINAPI d_DdeCmpStringHandles() { _asm{ jmp p_DdeCmpStringHandles } }
__declspec( naked ) void WINAPI d_DdeConnect() { _asm{ jmp p_DdeConnect } }
__declspec( naked ) void WINAPI d_DdeConnectList() { _asm{ jmp p_DdeConnectList } }
__declspec( naked ) void WINAPI d_DdeCreateDataHandle() { _asm{ jmp p_DdeCreateDataHandle } }
__declspec( naked ) void WINAPI d_DdeCreateStringHandleA() { _asm{ jmp p_DdeCreateStringHandleA } }
__declspec( naked ) void WINAPI d_DdeCreateStringHandleW() { _asm{ jmp p_DdeCreateStringHandleW } }
__declspec( naked ) void WINAPI d_DdeDisconnect() { _asm{ jmp p_DdeDisconnect } }
__declspec( naked ) void WINAPI d_DdeDisconnectList() { _asm{ jmp p_DdeDisconnectList } }
__declspec( naked ) void WINAPI d_DdeEnableCallback() { _asm{ jmp p_DdeEnableCallback } }
__declspec( naked ) void WINAPI d_DdeFreeDataHandle() { _asm{ jmp p_DdeFreeDataHandle } }
__declspec( naked ) void WINAPI d_DdeFreeStringHandle() { _asm{ jmp p_DdeFreeStringHandle } }
__declspec( naked ) void WINAPI d_DdeGetData() { _asm{ jmp p_DdeGetData } }
__declspec( naked ) void WINAPI d_DdeGetLastError() { _asm{ jmp p_DdeGetLastError } }
__declspec( naked ) void WINAPI d_DdeGetQualityOfService() { _asm{ jmp p_DdeGetQualityOfService } }
__declspec( naked ) void WINAPI d_DdeImpersonateClient() { _asm{ jmp p_DdeImpersonateClient } }
__declspec( naked ) void WINAPI d_DdeInitializeA() { _asm{ jmp p_DdeInitializeA } }
__declspec( naked ) void WINAPI d_DdeInitializeW() { _asm{ jmp p_DdeInitializeW } }
__declspec( naked ) void WINAPI d_DdeKeepStringHandle() { _asm{ jmp p_DdeKeepStringHandle } }
__declspec( naked ) void WINAPI d_DdeNameService() { _asm{ jmp p_DdeNameService } }
__declspec( naked ) void WINAPI d_DdePostAdvise() { _asm{ jmp p_DdePostAdvise } }
__declspec( naked ) void WINAPI d_DdeQueryConvInfo() { _asm{ jmp p_DdeQueryConvInfo } }
__declspec( naked ) void WINAPI d_DdeQueryNextServer() { _asm{ jmp p_DdeQueryNextServer } }
__declspec( naked ) void WINAPI d_DdeQueryStringA() { _asm{ jmp p_DdeQueryStringA } }
__declspec( naked ) void WINAPI d_DdeQueryStringW() { _asm{ jmp p_DdeQueryStringW } }
__declspec( naked ) void WINAPI d_DdeReconnect() { _asm{ jmp p_DdeReconnect } }
__declspec( naked ) void WINAPI d_DdeSetQualityOfService() { _asm{ jmp p_DdeSetQualityOfService } }
__declspec( naked ) void WINAPI d_DdeSetUserHandle() { _asm{ jmp p_DdeSetUserHandle } }
__declspec( naked ) void WINAPI d_DdeUnaccessData() { _asm{ jmp p_DdeUnaccessData } }
__declspec( naked ) void WINAPI d_DdeUninitialize() { _asm{ jmp p_DdeUninitialize } }
__declspec( naked ) void WINAPI d_DefDlgProcA() { _asm{ jmp p_DefDlgProcA } }
__declspec( naked ) void WINAPI d_DefDlgProcW() { _asm{ jmp p_DefDlgProcW } }
__declspec( naked ) void WINAPI d_DefFrameProcA() { _asm{ jmp p_DefFrameProcA } }
__declspec( naked ) void WINAPI d_DefFrameProcW() { _asm{ jmp p_DefFrameProcW } }
__declspec( naked ) void WINAPI d_DefMDIChildProcA() { _asm{ jmp p_DefMDIChildProcA } }
__declspec( naked ) void WINAPI d_DefMDIChildProcW() { _asm{ jmp p_DefMDIChildProcW } }
__declspec( naked ) void WINAPI d_DefRawInputProc() { _asm{ jmp p_DefRawInputProc } }
__declspec( naked ) void WINAPI d_DefWindowProcA() { _asm{ jmp p_DefWindowProcA } }
__declspec( naked ) void WINAPI d_DefWindowProcW() { _asm{ jmp p_DefWindowProcW } }
__declspec( naked ) void WINAPI d_DeferWindowPos() { _asm{ jmp p_DeferWindowPos } }
__declspec( naked ) void WINAPI d_DeleteMenu() { _asm{ jmp p_DeleteMenu } }
__declspec( naked ) void WINAPI d_DeregisterShellHookWindow() { _asm{ jmp p_DeregisterShellHookWindow } }
__declspec( naked ) void WINAPI d_DestroyAcceleratorTable() { _asm{ jmp p_DestroyAcceleratorTable } }
__declspec( naked ) void WINAPI d_DestroyCaret() { _asm{ jmp p_DestroyCaret } }
__declspec( naked ) void WINAPI d_DestroyCursor() { _asm{ jmp p_DestroyCursor } }
__declspec( naked ) void WINAPI d_DestroyIcon() { _asm{ jmp p_DestroyIcon } }
__declspec( naked ) void WINAPI d_DestroyMenu() { _asm{ jmp p_DestroyMenu } }
__declspec( naked ) void WINAPI d_DestroyReasons() { _asm{ jmp p_DestroyReasons } }
__declspec( naked ) void WINAPI d_DestroyWindow() { _asm{ jmp p_DestroyWindow } }
__declspec( naked ) void WINAPI d_DeviceEventWorker() { _asm{ jmp p_DeviceEventWorker } }
__declspec( naked ) void WINAPI d_DialogBoxIndirectParamA() { _asm{ jmp p_DialogBoxIndirectParamA } }
__declspec( naked ) void WINAPI d_DialogBoxIndirectParamAorW() { _asm{ jmp p_DialogBoxIndirectParamAorW } }
__declspec( naked ) void WINAPI d_DialogBoxIndirectParamW() { _asm{ jmp p_DialogBoxIndirectParamW } }
__declspec( naked ) void WINAPI d_DialogBoxParamA() { _asm{ jmp p_DialogBoxParamA } }
__declspec( naked ) void WINAPI d_DialogBoxParamW() { _asm{ jmp p_DialogBoxParamW } }
__declspec( naked ) void WINAPI d_DisableProcessWindowsGhosting() { _asm{ jmp p_DisableProcessWindowsGhosting } }
__declspec( naked ) void WINAPI d_DispatchMessageA() { _asm{ jmp p_DispatchMessageA } }
__declspec( naked ) void WINAPI d_DispatchMessageW() { _asm{ jmp p_DispatchMessageW } }
__declspec( naked ) void WINAPI d_DisplayExitWindowsWarnings() { _asm{ jmp p_DisplayExitWindowsWarnings } }
__declspec( naked ) void WINAPI d_DlgDirListA() { _asm{ jmp p_DlgDirListA } }
__declspec( naked ) void WINAPI d_DlgDirListComboBoxA() { _asm{ jmp p_DlgDirListComboBoxA } }
__declspec( naked ) void WINAPI d_DlgDirListComboBoxW() { _asm{ jmp p_DlgDirListComboBoxW } }
__declspec( naked ) void WINAPI d_DlgDirListW() { _asm{ jmp p_DlgDirListW } }
__declspec( naked ) void WINAPI d_DlgDirSelectComboBoxExA() { _asm{ jmp p_DlgDirSelectComboBoxExA } }
__declspec( naked ) void WINAPI d_DlgDirSelectComboBoxExW() { _asm{ jmp p_DlgDirSelectComboBoxExW } }
__declspec( naked ) void WINAPI d_DlgDirSelectExA() { _asm{ jmp p_DlgDirSelectExA } }
__declspec( naked ) void WINAPI d_DlgDirSelectExW() { _asm{ jmp p_DlgDirSelectExW } }
__declspec( naked ) void WINAPI d_DoSoundConnect() { _asm{ jmp p_DoSoundConnect } }
__declspec( naked ) void WINAPI d_DoSoundDisconnect() { _asm{ jmp p_DoSoundDisconnect } }
__declspec( naked ) void WINAPI d_DragDetect() { _asm{ jmp p_DragDetect } }
__declspec( naked ) void WINAPI d_DragObject() { _asm{ jmp p_DragObject } }
__declspec( naked ) void WINAPI d_DrawAnimatedRects() { _asm{ jmp p_DrawAnimatedRects } }
__declspec( naked ) void WINAPI d_DrawCaption() { _asm{ jmp p_DrawCaption } }
__declspec( naked ) void WINAPI d_DrawCaptionTempA() { _asm{ jmp p_DrawCaptionTempA } }
__declspec( naked ) void WINAPI d_DrawCaptionTempW() { _asm{ jmp p_DrawCaptionTempW } }
__declspec( naked ) void WINAPI d_DrawEdge() { _asm{ jmp p_DrawEdge } }
__declspec( naked ) void WINAPI d_DrawFocusRect() { _asm{ jmp p_DrawFocusRect } }
__declspec( naked ) void WINAPI d_DrawFrame() { _asm{ jmp p_DrawFrame } }
__declspec( naked ) void WINAPI d_DrawFrameControl() { _asm{ jmp p_DrawFrameControl } }
__declspec( naked ) void WINAPI d_DrawIcon() { _asm{ jmp p_DrawIcon } }
__declspec( naked ) void WINAPI d_DrawIconEx() { _asm{ jmp p_DrawIconEx } }
__declspec( naked ) void WINAPI d_DrawMenuBar() { _asm{ jmp p_DrawMenuBar } }
__declspec( naked ) void WINAPI d_DrawMenuBarTemp() { _asm{ jmp p_DrawMenuBarTemp } }
__declspec( naked ) void WINAPI d_DrawStateA() { _asm{ jmp p_DrawStateA } }
__declspec( naked ) void WINAPI d_DrawStateW() { _asm{ jmp p_DrawStateW } }
__declspec( naked ) void WINAPI d_DrawTextA() { _asm{ jmp p_DrawTextA } }
__declspec( naked ) void WINAPI d_DrawTextExA() { _asm{ jmp p_DrawTextExA } }
__declspec( naked ) void WINAPI d_DrawTextExW() { _asm{ jmp p_DrawTextExW } }
__declspec( naked ) void WINAPI d_DrawTextW() { _asm{ jmp p_DrawTextW } }
__declspec( naked ) void WINAPI d_DwmGetDxRgn() { _asm{ jmp p_DwmGetDxRgn } }
__declspec( naked ) void WINAPI d_DwmHintDxUpdate() { _asm{ jmp p_DwmHintDxUpdate } }
__declspec( naked ) void WINAPI d_DwmStartRedirection() { _asm{ jmp p_DwmStartRedirection } }
__declspec( naked ) void WINAPI d_DwmStopRedirection() { _asm{ jmp p_DwmStopRedirection } }
__declspec( naked ) void WINAPI d_EditWndProc() { _asm{ jmp p_EditWndProc } }
__declspec( naked ) void WINAPI d_EmptyClipboard() { _asm{ jmp p_EmptyClipboard } }
__declspec( naked ) void WINAPI d_EnableMenuItem() { _asm{ jmp p_EnableMenuItem } }
__declspec( naked ) void WINAPI d_EnableScrollBar() { _asm{ jmp p_EnableScrollBar } }
__declspec( naked ) void WINAPI d_EnableWindow() { _asm{ jmp p_EnableWindow } }
__declspec( naked ) void WINAPI d_EndDeferWindowPos() { _asm{ jmp p_EndDeferWindowPos } }
__declspec( naked ) void WINAPI d_EndDialog() { _asm{ jmp p_EndDialog } }
__declspec( naked ) void WINAPI d_EndMenu() { _asm{ jmp p_EndMenu } }
__declspec( naked ) void WINAPI d_EndPaint() { _asm{ jmp p_EndPaint } }
__declspec( naked ) void WINAPI d_EndTask() { _asm{ jmp p_EndTask } }
__declspec( naked ) void WINAPI d_EnterReaderModeHelper() { _asm{ jmp p_EnterReaderModeHelper } }
__declspec( naked ) void WINAPI d_EnumChildWindows() { _asm{ jmp p_EnumChildWindows } }
__declspec( naked ) void WINAPI d_EnumClipboardFormats() { _asm{ jmp p_EnumClipboardFormats } }
__declspec( naked ) void WINAPI d_EnumDesktopWindows() { _asm{ jmp p_EnumDesktopWindows } }
__declspec( naked ) void WINAPI d_EnumDesktopsA() { _asm{ jmp p_EnumDesktopsA } }
__declspec( naked ) void WINAPI d_EnumDesktopsW() { _asm{ jmp p_EnumDesktopsW } }
__declspec( naked ) void WINAPI d_EnumDisplayDevicesA() { _asm{ jmp p_EnumDisplayDevicesA } }
__declspec( naked ) void WINAPI d_EnumDisplayDevicesW() { _asm{ jmp p_EnumDisplayDevicesW } }
__declspec( naked ) void WINAPI d_EnumDisplayMonitors() { _asm{ jmp p_EnumDisplayMonitors } }
__declspec( naked ) void WINAPI d_EnumDisplaySettingsA() { _asm{ jmp p_EnumDisplaySettingsA } }
__declspec( naked ) void WINAPI d_EnumDisplaySettingsExA() { _asm{ jmp p_EnumDisplaySettingsExA } }
__declspec( naked ) void WINAPI d_EnumDisplaySettingsExW() { _asm{ jmp p_EnumDisplaySettingsExW } }
__declspec( naked ) void WINAPI d_EnumDisplaySettingsW() { _asm{ jmp p_EnumDisplaySettingsW } }
__declspec( naked ) void WINAPI d_EnumPropsA() { _asm{ jmp p_EnumPropsA } }
__declspec( naked ) void WINAPI d_EnumPropsExA() { _asm{ jmp p_EnumPropsExA } }
__declspec( naked ) void WINAPI d_EnumPropsExW() { _asm{ jmp p_EnumPropsExW } }
__declspec( naked ) void WINAPI d_EnumPropsW() { _asm{ jmp p_EnumPropsW } }
__declspec( naked ) void WINAPI d_EnumThreadWindows() { _asm{ jmp p_EnumThreadWindows } }
__declspec( naked ) void WINAPI d_EnumWindowStationsA() { _asm{ jmp p_EnumWindowStationsA } }
__declspec( naked ) void WINAPI d_EnumWindowStationsW() { _asm{ jmp p_EnumWindowStationsW } }
__declspec( naked ) void WINAPI d_EnumWindows() { _asm{ jmp p_EnumWindows } }
__declspec( naked ) void WINAPI d_EqualRect() { _asm{ jmp p_EqualRect } }
__declspec( naked ) void WINAPI d_ExcludeUpdateRgn() { _asm{ jmp p_ExcludeUpdateRgn } }
__declspec( naked ) void WINAPI d_ExitWindowsEx() { _asm{ jmp p_ExitWindowsEx } }
__declspec( naked ) void WINAPI d_FillRect() { _asm{ jmp p_FillRect } }
__declspec( naked ) void WINAPI d_FindWindowA() { _asm{ jmp p_FindWindowA } }
__declspec( naked ) void WINAPI d_FindWindowExA() { _asm{ jmp p_FindWindowExA } }
__declspec( naked ) void WINAPI d_FindWindowExW() { _asm{ jmp p_FindWindowExW } }
__declspec( naked ) void WINAPI d_FindWindowW() { _asm{ jmp p_FindWindowW } }
__declspec( naked ) void WINAPI d_FlashWindow() { _asm{ jmp p_FlashWindow } }
__declspec( naked ) void WINAPI d_FlashWindowEx() { _asm{ jmp p_FlashWindowEx } }
__declspec( naked ) void WINAPI d_FrameRect() { _asm{ jmp p_FrameRect } }
__declspec( naked ) void WINAPI d_FreeDDElParam() { _asm{ jmp p_FreeDDElParam } }
__declspec( naked ) void WINAPI d_FrostCrashedWindow() { _asm{ jmp p_FrostCrashedWindow } }
__declspec( naked ) void WINAPI d_GetActiveWindow() { _asm{ jmp p_GetActiveWindow } }
__declspec( naked ) void WINAPI d_GetAltTabInfo() { _asm{ jmp p_GetAltTabInfo } }
__declspec( naked ) void WINAPI d_GetAltTabInfoA() { _asm{ jmp p_GetAltTabInfoA } }
__declspec( naked ) void WINAPI d_GetAltTabInfoW() { _asm{ jmp p_GetAltTabInfoW } }
__declspec( naked ) void WINAPI d_GetAncestor() { _asm{ jmp p_GetAncestor } }
__declspec( naked ) void WINAPI d_GetAppCompatFlags2() { _asm{ jmp p_GetAppCompatFlags2 } }
__declspec( naked ) void WINAPI d_GetAppCompatFlags() { _asm{ jmp p_GetAppCompatFlags } }
__declspec( naked ) void WINAPI d_GetAsyncKeyState() { _asm{ jmp p_GetAsyncKeyState } }
__declspec( naked ) void WINAPI d_GetCapture() { _asm{ jmp p_GetCapture } }
__declspec( naked ) void WINAPI d_GetCaretBlinkTime() { _asm{ jmp p_GetCaretBlinkTime } }
__declspec( naked ) void WINAPI d_GetCaretPos() { _asm{ jmp p_GetCaretPos } }
__declspec( naked ) void WINAPI d_GetClassInfoA() { _asm{ jmp p_GetClassInfoA } }
__declspec( naked ) void WINAPI d_GetClassInfoExA() { _asm{ jmp p_GetClassInfoExA } }
__declspec( naked ) void WINAPI d_GetClassInfoExW() { _asm{ jmp p_GetClassInfoExW } }
__declspec( naked ) void WINAPI d_GetClassInfoW() { _asm{ jmp p_GetClassInfoW } }
__declspec( naked ) void WINAPI d_GetClassLongA() { _asm{ jmp p_GetClassLongA } }
__declspec( naked ) void WINAPI d_GetClassLongW() { _asm{ jmp p_GetClassLongW } }
__declspec( naked ) void WINAPI d_GetClassNameA() { _asm{ jmp p_GetClassNameA } }
__declspec( naked ) void WINAPI d_GetClassNameW() { _asm{ jmp p_GetClassNameW } }
__declspec( naked ) void WINAPI d_GetClassWord() { _asm{ jmp p_GetClassWord } }
__declspec( naked ) void WINAPI d_GetClientRect() { _asm{ jmp p_GetClientRect } }
__declspec( naked ) void WINAPI d_GetClipCursor() { _asm{ jmp p_GetClipCursor } }
__declspec( naked ) void WINAPI d_GetClipboardData() { _asm{ jmp p_GetClipboardData } }
__declspec( naked ) void WINAPI d_GetClipboardFormatNameA() { _asm{ jmp p_GetClipboardFormatNameA } }
__declspec( naked ) void WINAPI d_GetClipboardFormatNameW() { _asm{ jmp p_GetClipboardFormatNameW } }
__declspec( naked ) void WINAPI d_GetClipboardOwner() { _asm{ jmp p_GetClipboardOwner } }
__declspec( naked ) void WINAPI d_GetClipboardSequenceNumber() { _asm{ jmp p_GetClipboardSequenceNumber } }
__declspec( naked ) void WINAPI d_GetClipboardViewer() { _asm{ jmp p_GetClipboardViewer } }
__declspec( naked ) void WINAPI d_GetComboBoxInfo() { _asm{ jmp p_GetComboBoxInfo } }
__declspec( naked ) void WINAPI d_GetCursor() { _asm{ jmp p_GetCursor } }
__declspec( naked ) void WINAPI d_GetCursorFrameInfo() { _asm{ jmp p_GetCursorFrameInfo } }
__declspec( naked ) void WINAPI d_GetCursorInfo() { _asm{ jmp p_GetCursorInfo } }
__declspec( naked ) void WINAPI d_GetCursorPos() { _asm{ jmp p_GetCursorPos } }
__declspec( naked ) void WINAPI d_GetDC() { _asm{ jmp p_GetDC } }
__declspec( naked ) void WINAPI d_GetDCEx() { _asm{ jmp p_GetDCEx } }
__declspec( naked ) void WINAPI d_GetDesktopWindow() { _asm{ jmp p_GetDesktopWindow } }
__declspec( naked ) void WINAPI d_GetDialogBaseUnits() { _asm{ jmp p_GetDialogBaseUnits } }
__declspec( naked ) void WINAPI d_GetDlgCtrlID() { _asm{ jmp p_GetDlgCtrlID } }
__declspec( naked ) void WINAPI d_GetDlgItem() { _asm{ jmp p_GetDlgItem } }
__declspec( naked ) void WINAPI d_GetDlgItemInt() { _asm{ jmp p_GetDlgItemInt } }
__declspec( naked ) void WINAPI d_GetDlgItemTextA() { _asm{ jmp p_GetDlgItemTextA } }
__declspec( naked ) void WINAPI d_GetDlgItemTextW() { _asm{ jmp p_GetDlgItemTextW } }
__declspec( naked ) void WINAPI d_GetDoubleClickTime() { _asm{ jmp p_GetDoubleClickTime } }
__declspec( naked ) void WINAPI d_GetFocus() { _asm{ jmp p_GetFocus } }
__declspec( naked ) void WINAPI d_GetForegroundWindow() { _asm{ jmp p_GetForegroundWindow } }
__declspec( naked ) void WINAPI d_GetGUIThreadInfo() { _asm{ jmp p_GetGUIThreadInfo } }
__declspec( naked ) void WINAPI d_GetGuiResources() { _asm{ jmp p_GetGuiResources } }
__declspec( naked ) void WINAPI d_GetIconInfo() { _asm{ jmp p_GetIconInfo } }
__declspec( naked ) void WINAPI d_GetIconInfoExA() { _asm{ jmp p_GetIconInfoExA } }
__declspec( naked ) void WINAPI d_GetIconInfoExW() { _asm{ jmp p_GetIconInfoExW } }
__declspec( naked ) void WINAPI d_GetInputDesktop() { _asm{ jmp p_GetInputDesktop } }
__declspec( naked ) void WINAPI d_GetInputState() { _asm{ jmp p_GetInputState } }
__declspec( naked ) void WINAPI d_GetInternalWindowPos() { _asm{ jmp p_GetInternalWindowPos } }
__declspec( naked ) void WINAPI d_GetKBCodePage() { _asm{ jmp p_GetKBCodePage } }
__declspec( naked ) void WINAPI d_GetKeyNameTextA() { _asm{ jmp p_GetKeyNameTextA } }
__declspec( naked ) void WINAPI d_GetKeyNameTextW() { _asm{ jmp p_GetKeyNameTextW } }
__declspec( naked ) void WINAPI d_GetKeyState() { _asm{ jmp p_GetKeyState } }
__declspec( naked ) void WINAPI d_GetKeyboardLayout() { _asm{ jmp p_GetKeyboardLayout } }
__declspec( naked ) void WINAPI d_GetKeyboardLayoutList() { _asm{ jmp p_GetKeyboardLayoutList } }
__declspec( naked ) void WINAPI d_GetKeyboardLayoutNameA() { _asm{ jmp p_GetKeyboardLayoutNameA } }
__declspec( naked ) void WINAPI d_GetKeyboardLayoutNameW() { _asm{ jmp p_GetKeyboardLayoutNameW } }
__declspec( naked ) void WINAPI d_GetKeyboardState() { _asm{ jmp p_GetKeyboardState } }
__declspec( naked ) void WINAPI d_GetKeyboardType() { _asm{ jmp p_GetKeyboardType } }
__declspec( naked ) void WINAPI d_GetLastActivePopup() { _asm{ jmp p_GetLastActivePopup } }
__declspec( naked ) void WINAPI d_GetLastInputInfo() { _asm{ jmp p_GetLastInputInfo } }
__declspec( naked ) void WINAPI d_GetLayeredWindowAttributes() { _asm{ jmp p_GetLayeredWindowAttributes } }
__declspec( naked ) void WINAPI d_GetListBoxInfo() { _asm{ jmp p_GetListBoxInfo } }
__declspec( naked ) void WINAPI d_GetMenu() { _asm{ jmp p_GetMenu } }
__declspec( naked ) void WINAPI d_GetMenuBarInfo() { _asm{ jmp p_GetMenuBarInfo } }
__declspec( naked ) void WINAPI d_GetMenuCheckMarkDimensions() { _asm{ jmp p_GetMenuCheckMarkDimensions } }
__declspec( naked ) void WINAPI d_GetMenuContextHelpId() { _asm{ jmp p_GetMenuContextHelpId } }
__declspec( naked ) void WINAPI d_GetMenuDefaultItem() { _asm{ jmp p_GetMenuDefaultItem } }
__declspec( naked ) void WINAPI d_GetMenuInfo() { _asm{ jmp p_GetMenuInfo } }
__declspec( naked ) void WINAPI d_GetMenuItemCount() { _asm{ jmp p_GetMenuItemCount } }
__declspec( naked ) void WINAPI d_GetMenuItemID() { _asm{ jmp p_GetMenuItemID } }
__declspec( naked ) void WINAPI d_GetMenuItemInfoA() { _asm{ jmp p_GetMenuItemInfoA } }
__declspec( naked ) void WINAPI d_GetMenuItemInfoW() { _asm{ jmp p_GetMenuItemInfoW } }
__declspec( naked ) void WINAPI d_GetMenuItemRect() { _asm{ jmp p_GetMenuItemRect } }
__declspec( naked ) void WINAPI d_GetMenuState() { _asm{ jmp p_GetMenuState } }
__declspec( naked ) void WINAPI d_GetMenuStringA() { _asm{ jmp p_GetMenuStringA } }
__declspec( naked ) void WINAPI d_GetMenuStringW() { _asm{ jmp p_GetMenuStringW } }
__declspec( naked ) void WINAPI d_GetMessageA() { _asm{ jmp p_GetMessageA } }
__declspec( naked ) void WINAPI d_GetMessageExtraInfo() { _asm{ jmp p_GetMessageExtraInfo } }
__declspec( naked ) void WINAPI d_GetMessagePos() { _asm{ jmp p_GetMessagePos } }
__declspec( naked ) void WINAPI d_GetMessageTime() { _asm{ jmp p_GetMessageTime } }
__declspec( naked ) void WINAPI d_GetMessageW() { _asm{ jmp p_GetMessageW } }
__declspec( naked ) void WINAPI d_GetMonitorInfoA() { _asm{ jmp p_GetMonitorInfoA } }
__declspec( naked ) void WINAPI d_GetMonitorInfoW() { _asm{ jmp p_GetMonitorInfoW } }
__declspec( naked ) void WINAPI d_GetMouseMovePointsEx() { _asm{ jmp p_GetMouseMovePointsEx } }
__declspec( naked ) void WINAPI d_GetNextDlgGroupItem() { _asm{ jmp p_GetNextDlgGroupItem } }
__declspec( naked ) void WINAPI d_GetNextDlgTabItem() { _asm{ jmp p_GetNextDlgTabItem } }
__declspec( naked ) void WINAPI d_GetOpenClipboardWindow() { _asm{ jmp p_GetOpenClipboardWindow } }
__declspec( naked ) void WINAPI d_GetParent() { _asm{ jmp p_GetParent } }
__declspec( naked ) void WINAPI d_GetPhysicalCursorPos() { _asm{ jmp p_GetPhysicalCursorPos } }
__declspec( naked ) void WINAPI d_GetPriorityClipboardFormat() { _asm{ jmp p_GetPriorityClipboardFormat } }
__declspec( naked ) void WINAPI d_GetProcessDefaultLayout() { _asm{ jmp p_GetProcessDefaultLayout } }
__declspec( naked ) void WINAPI d_GetProcessWindowStation() { _asm{ jmp p_GetProcessWindowStation } }
__declspec( naked ) void WINAPI d_GetProgmanWindow() { _asm{ jmp p_GetProgmanWindow } }
__declspec( naked ) void WINAPI d_GetPropA() { _asm{ jmp p_GetPropA } }
__declspec( naked ) void WINAPI d_GetPropW() { _asm{ jmp p_GetPropW } }
__declspec( naked ) void WINAPI d_GetQueueStatus() { _asm{ jmp p_GetQueueStatus } }
__declspec( naked ) void WINAPI d_GetRawInputBuffer() { _asm{ jmp p_GetRawInputBuffer } }
__declspec( naked ) void WINAPI d_GetRawInputData() { _asm{ jmp p_GetRawInputData } }
__declspec( naked ) void WINAPI d_GetRawInputDeviceInfoA() { _asm{ jmp p_GetRawInputDeviceInfoA } }
__declspec( naked ) void WINAPI d_GetRawInputDeviceInfoW() { _asm{ jmp p_GetRawInputDeviceInfoW } }
__declspec( naked ) void WINAPI d_GetRawInputDeviceList() { _asm{ jmp p_GetRawInputDeviceList } }
__declspec( naked ) void WINAPI d_GetReasonTitleFromReasonCode() { _asm{ jmp p_GetReasonTitleFromReasonCode } }
__declspec( naked ) void WINAPI d_GetRegisteredRawInputDevices() { _asm{ jmp p_GetRegisteredRawInputDevices } }
__declspec( naked ) void WINAPI d_GetScrollBarInfo() { _asm{ jmp p_GetScrollBarInfo } }
__declspec( naked ) void WINAPI d_GetScrollInfo() { _asm{ jmp p_GetScrollInfo } }
__declspec( naked ) void WINAPI d_GetScrollPos() { _asm{ jmp p_GetScrollPos } }
__declspec( naked ) void WINAPI d_GetScrollRange() { _asm{ jmp p_GetScrollRange } }
__declspec( naked ) void WINAPI d_GetSendMessageReceiver() { _asm{ jmp p_GetSendMessageReceiver } }
__declspec( naked ) void WINAPI d_GetShellWindow() { _asm{ jmp p_GetShellWindow } }
__declspec( naked ) void WINAPI d_GetSubMenu() { _asm{ jmp p_GetSubMenu } }
__declspec( naked ) void WINAPI d_GetSysColor() { _asm{ jmp p_GetSysColor } }
__declspec( naked ) void WINAPI d_GetSysColorBrush() { _asm{ jmp p_GetSysColorBrush } }
__declspec( naked ) void WINAPI d_GetSystemMenu() { _asm{ jmp p_GetSystemMenu } }
__declspec( naked ) void WINAPI d_GetSystemMetrics() { _asm{ jmp p_GetSystemMetrics } }
__declspec( naked ) void WINAPI d_GetTabbedTextExtentA() { _asm{ jmp p_GetTabbedTextExtentA } }
__declspec( naked ) void WINAPI d_GetTabbedTextExtentW() { _asm{ jmp p_GetTabbedTextExtentW } }
__declspec( naked ) void WINAPI d_GetTaskmanWindow() { _asm{ jmp p_GetTaskmanWindow } }
__declspec( naked ) void WINAPI d_GetThreadDesktop() { _asm{ jmp p_GetThreadDesktop } }
__declspec( naked ) void WINAPI d_GetTitleBarInfo() { _asm{ jmp p_GetTitleBarInfo } }
__declspec( naked ) void WINAPI d_GetTopWindow() { _asm{ jmp p_GetTopWindow } }
__declspec( naked ) void WINAPI d_GetUpdateRect() { _asm{ jmp p_GetUpdateRect } }
__declspec( naked ) void WINAPI d_GetUpdateRgn() { _asm{ jmp p_GetUpdateRgn } }
__declspec( naked ) void WINAPI d_GetUpdatedClipboardFormats() { _asm{ jmp p_GetUpdatedClipboardFormats } }
__declspec( naked ) void WINAPI d_GetUserObjectInformationA() { _asm{ jmp p_GetUserObjectInformationA } }
__declspec( naked ) void WINAPI d_GetUserObjectInformationW() { _asm{ jmp p_GetUserObjectInformationW } }
__declspec( naked ) void WINAPI d_GetUserObjectSecurity() { _asm{ jmp p_GetUserObjectSecurity } }
__declspec( naked ) void WINAPI d_GetWinStationInfo() { _asm{ jmp p_GetWinStationInfo } }
__declspec( naked ) void WINAPI d_GetWindow() { _asm{ jmp p_GetWindow } }
__declspec( naked ) void WINAPI d_GetWindowContextHelpId() { _asm{ jmp p_GetWindowContextHelpId } }
__declspec( naked ) void WINAPI d_GetWindowDC() { _asm{ jmp p_GetWindowDC } }
__declspec( naked ) void WINAPI d_GetWindowInfo() { _asm{ jmp p_GetWindowInfo } }
__declspec( naked ) void WINAPI d_GetWindowLongA() { _asm{ jmp p_GetWindowLongA } }
__declspec( naked ) void WINAPI d_GetWindowLongW() { _asm{ jmp p_GetWindowLongW } }
__declspec( naked ) void WINAPI d_GetWindowMinimizeRect() { _asm{ jmp p_GetWindowMinimizeRect } }
__declspec( naked ) void WINAPI d_GetWindowModuleFileName() { _asm{ jmp p_GetWindowModuleFileName } }
__declspec( naked ) void WINAPI d_GetWindowModuleFileNameA() { _asm{ jmp p_GetWindowModuleFileNameA } }
__declspec( naked ) void WINAPI d_GetWindowModuleFileNameW() { _asm{ jmp p_GetWindowModuleFileNameW } }
__declspec( naked ) void WINAPI d_GetWindowPlacement() { _asm{ jmp p_GetWindowPlacement } }
__declspec( naked ) void WINAPI d_GetWindowRect() { _asm{ jmp p_GetWindowRect } }
__declspec( naked ) void WINAPI d_GetWindowRgn() { _asm{ jmp p_GetWindowRgn } }
__declspec( naked ) void WINAPI d_GetWindowRgnBox() { _asm{ jmp p_GetWindowRgnBox } }
__declspec( naked ) void WINAPI d_GetWindowRgnEx() { _asm{ jmp p_GetWindowRgnEx } }
__declspec( naked ) void WINAPI d_GetWindowTextA() { _asm{ jmp p_GetWindowTextA } }
__declspec( naked ) void WINAPI d_GetWindowTextLengthA() { _asm{ jmp p_GetWindowTextLengthA } }
__declspec( naked ) void WINAPI d_GetWindowTextLengthW() { _asm{ jmp p_GetWindowTextLengthW } }
__declspec( naked ) void WINAPI d_GetWindowTextW() { _asm{ jmp p_GetWindowTextW } }
__declspec( naked ) void WINAPI d_GetWindowThreadProcessId() { _asm{ jmp p_GetWindowThreadProcessId } }
__declspec( naked ) void WINAPI d_GetWindowWord() { _asm{ jmp p_GetWindowWord } }
__declspec( naked ) void WINAPI d_GhostWindowFromHungWindow() { _asm{ jmp p_GhostWindowFromHungWindow } }
__declspec( naked ) void WINAPI d_GrayStringA() { _asm{ jmp p_GrayStringA } }
__declspec( naked ) void WINAPI d_GrayStringW() { _asm{ jmp p_GrayStringW } }
__declspec( naked ) void WINAPI d_HideCaret() { _asm{ jmp p_HideCaret } }
__declspec( naked ) void WINAPI d_HiliteMenuItem() { _asm{ jmp p_HiliteMenuItem } }
__declspec( naked ) void WINAPI d_HungWindowFromGhostWindow() { _asm{ jmp p_HungWindowFromGhostWindow } }
__declspec( naked ) void WINAPI d_IMPGetIMEA() { _asm{ jmp p_IMPGetIMEA } }
__declspec( naked ) void WINAPI d_IMPGetIMEW() { _asm{ jmp p_IMPGetIMEW } }
__declspec( naked ) void WINAPI d_IMPQueryIMEA() { _asm{ jmp p_IMPQueryIMEA } }
__declspec( naked ) void WINAPI d_IMPQueryIMEW() { _asm{ jmp p_IMPQueryIMEW } }
__declspec( naked ) void WINAPI d_IMPSetIMEA() { _asm{ jmp p_IMPSetIMEA } }
__declspec( naked ) void WINAPI d_IMPSetIMEW() { _asm{ jmp p_IMPSetIMEW } }
__declspec( naked ) void WINAPI d_ImpersonateDdeClientWindow() { _asm{ jmp p_ImpersonateDdeClientWindow } }
__declspec( naked ) void WINAPI d_InSendMessage() { _asm{ jmp p_InSendMessage } }
__declspec( naked ) void WINAPI d_InSendMessageEx() { _asm{ jmp p_InSendMessageEx } }
__declspec( naked ) void WINAPI d_InflateRect() { _asm{ jmp p_InflateRect } }
__declspec( naked ) void WINAPI d_InitializeLpkHooks() { _asm{ jmp p_InitializeLpkHooks } }
__declspec( naked ) void WINAPI d_InsertMenuA() { _asm{ jmp p_InsertMenuA } }
__declspec( naked ) void WINAPI d_InsertMenuItemA() { _asm{ jmp p_InsertMenuItemA } }
__declspec( naked ) void WINAPI d_InsertMenuItemW() { _asm{ jmp p_InsertMenuItemW } }
__declspec( naked ) void WINAPI d_InsertMenuW() { _asm{ jmp p_InsertMenuW } }
__declspec( naked ) void WINAPI d_InternalGetWindowIcon() { _asm{ jmp p_InternalGetWindowIcon } }
__declspec( naked ) void WINAPI d_InternalGetWindowText() { _asm{ jmp p_InternalGetWindowText } }
__declspec( naked ) void WINAPI d_IntersectRect() { _asm{ jmp p_IntersectRect } }
__declspec( naked ) void WINAPI d_InvalidateRect() { _asm{ jmp p_InvalidateRect } }
__declspec( naked ) void WINAPI d_InvalidateRgn() { _asm{ jmp p_InvalidateRgn } }
__declspec( naked ) void WINAPI d_InvertRect() { _asm{ jmp p_InvertRect } }
__declspec( naked ) void WINAPI d_IsCharAlphaA() { _asm{ jmp p_IsCharAlphaA } }
__declspec( naked ) void WINAPI d_IsCharAlphaNumericA() { _asm{ jmp p_IsCharAlphaNumericA } }
__declspec( naked ) void WINAPI d_IsCharAlphaNumericW() { _asm{ jmp p_IsCharAlphaNumericW } }
__declspec( naked ) void WINAPI d_IsCharAlphaW() { _asm{ jmp p_IsCharAlphaW } }
__declspec( naked ) void WINAPI d_IsCharLowerA() { _asm{ jmp p_IsCharLowerA } }
__declspec( naked ) void WINAPI d_IsCharLowerW() { _asm{ jmp p_IsCharLowerW } }
__declspec( naked ) void WINAPI d_IsCharUpperA() { _asm{ jmp p_IsCharUpperA } }
__declspec( naked ) void WINAPI d_IsCharUpperW() { _asm{ jmp p_IsCharUpperW } }
__declspec( naked ) void WINAPI d_IsChild() { _asm{ jmp p_IsChild } }
__declspec( naked ) void WINAPI d_IsClipboardFormatAvailable() { _asm{ jmp p_IsClipboardFormatAvailable } }
__declspec( naked ) void WINAPI d_IsDialogMessage() { _asm{ jmp p_IsDialogMessage } }
__declspec( naked ) void WINAPI d_IsDialogMessageA() { _asm{ jmp p_IsDialogMessageA } }
__declspec( naked ) void WINAPI d_IsDialogMessageW() { _asm{ jmp p_IsDialogMessageW } }
__declspec( naked ) void WINAPI d_IsDlgButtonChecked() { _asm{ jmp p_IsDlgButtonChecked } }
__declspec( naked ) void WINAPI d_IsGUIThread() { _asm{ jmp p_IsGUIThread } }
__declspec( naked ) void WINAPI d_IsHungAppWindow() { _asm{ jmp p_IsHungAppWindow } }
__declspec( naked ) void WINAPI d_IsIconic() { _asm{ jmp p_IsIconic } }
__declspec( naked ) void WINAPI d_IsMenu() { _asm{ jmp p_IsMenu } }
__declspec( naked ) void WINAPI d_IsProcessDPIAware() { _asm{ jmp p_IsProcessDPIAware } }
__declspec( naked ) void WINAPI d_IsRectEmpty() { _asm{ jmp p_IsRectEmpty } }
__declspec( naked ) void WINAPI d_IsSETEnabled() { _asm{ jmp p_IsSETEnabled } }
__declspec( naked ) void WINAPI d_IsServerSideWindow() { _asm{ jmp p_IsServerSideWindow } }
__declspec( naked ) void WINAPI d_IsThreadDesktopComposited() { _asm{ jmp p_IsThreadDesktopComposited } }
__declspec( naked ) void WINAPI d_IsWinEventHookInstalled() { _asm{ jmp p_IsWinEventHookInstalled } }
__declspec( naked ) void WINAPI d_IsWindow() { _asm{ jmp p_IsWindow } }
__declspec( naked ) void WINAPI d_IsWindowEnabled() { _asm{ jmp p_IsWindowEnabled } }
__declspec( naked ) void WINAPI d_IsWindowInDestroy() { _asm{ jmp p_IsWindowInDestroy } }
__declspec( naked ) void WINAPI d_IsWindowRedirectedForPrint() { _asm{ jmp p_IsWindowRedirectedForPrint } }
__declspec( naked ) void WINAPI d_IsWindowUnicode() { _asm{ jmp p_IsWindowUnicode } }
__declspec( naked ) void WINAPI d_IsWindowVisible() { _asm{ jmp p_IsWindowVisible } }
__declspec( naked ) void WINAPI d_IsWow64Message() { _asm{ jmp p_IsWow64Message } }
__declspec( naked ) void WINAPI d_IsZoomed() { _asm{ jmp p_IsZoomed } }
__declspec( naked ) void WINAPI d_KillTimer() { _asm{ jmp p_KillTimer } }
__declspec( naked ) void WINAPI d_LoadAcceleratorsA() { _asm{ jmp p_LoadAcceleratorsA } }
__declspec( naked ) void WINAPI d_LoadAcceleratorsW() { _asm{ jmp p_LoadAcceleratorsW } }
__declspec( naked ) void WINAPI d_LoadBitmapA() { _asm{ jmp p_LoadBitmapA } }
__declspec( naked ) void WINAPI d_LoadBitmapW() { _asm{ jmp p_LoadBitmapW } }
__declspec( naked ) void WINAPI d_LoadCursorA() { _asm{ jmp p_LoadCursorA } }
__declspec( naked ) void WINAPI d_LoadCursorFromFileA() { _asm{ jmp p_LoadCursorFromFileA } }
__declspec( naked ) void WINAPI d_LoadCursorFromFileW() { _asm{ jmp p_LoadCursorFromFileW } }
__declspec( naked ) void WINAPI d_LoadCursorW() { _asm{ jmp p_LoadCursorW } }
__declspec( naked ) void WINAPI d_LoadIconA() { _asm{ jmp p_LoadIconA } }
__declspec( naked ) void WINAPI d_LoadIconW() { _asm{ jmp p_LoadIconW } }
__declspec( naked ) void WINAPI d_LoadImageA() { _asm{ jmp p_LoadImageA } }
__declspec( naked ) void WINAPI d_LoadImageW() { _asm{ jmp p_LoadImageW } }
__declspec( naked ) void WINAPI d_LoadKeyboardLayoutA() { _asm{ jmp p_LoadKeyboardLayoutA } }
__declspec( naked ) void WINAPI d_LoadKeyboardLayoutEx() { _asm{ jmp p_LoadKeyboardLayoutEx } }
__declspec( naked ) void WINAPI d_LoadKeyboardLayoutW() { _asm{ jmp p_LoadKeyboardLayoutW } }
__declspec( naked ) void WINAPI d_LoadLocalFonts() { _asm{ jmp p_LoadLocalFonts } }
__declspec( naked ) void WINAPI d_LoadMenuA() { _asm{ jmp p_LoadMenuA } }
__declspec( naked ) void WINAPI d_LoadMenuIndirectA() { _asm{ jmp p_LoadMenuIndirectA } }
__declspec( naked ) void WINAPI d_LoadMenuIndirectW() { _asm{ jmp p_LoadMenuIndirectW } }
__declspec( naked ) void WINAPI d_LoadMenuW() { _asm{ jmp p_LoadMenuW } }
__declspec( naked ) void WINAPI d_LoadRemoteFonts() { _asm{ jmp p_LoadRemoteFonts } }
__declspec( naked ) void WINAPI d_LoadStringA() { _asm{ jmp p_LoadStringA } }
__declspec( naked ) void WINAPI d_LoadStringW() { _asm{ jmp p_LoadStringW } }
__declspec( naked ) void WINAPI d_LockSetForegroundWindow() { _asm{ jmp p_LockSetForegroundWindow } }
__declspec( naked ) void WINAPI d_LockWindowStation() { _asm{ jmp p_LockWindowStation } }
__declspec( naked ) void WINAPI d_LockWindowUpdate() { _asm{ jmp p_LockWindowUpdate } }
__declspec( naked ) void WINAPI d_LockWorkStation() { _asm{ jmp p_LockWorkStation } }
__declspec( naked ) void WINAPI d_LogicalToPhysicalPoint() { _asm{ jmp p_LogicalToPhysicalPoint } }
__declspec( naked ) void WINAPI d_LookupIconIdFromDirectory() { _asm{ jmp p_LookupIconIdFromDirectory } }
__declspec( naked ) void WINAPI d_LookupIconIdFromDirectoryEx() { _asm{ jmp p_LookupIconIdFromDirectoryEx } }
__declspec( naked ) void WINAPI d_MBToWCSEx() { _asm{ jmp p_MBToWCSEx } }
__declspec( naked ) void WINAPI d_MB_GetString() { _asm{ jmp p_MB_GetString } }
__declspec( naked ) void WINAPI d_MapDialogRect() { _asm{ jmp p_MapDialogRect } }
__declspec( naked ) void WINAPI d_MapVirtualKeyA() { _asm{ jmp p_MapVirtualKeyA } }
__declspec( naked ) void WINAPI d_MapVirtualKeyExA() { _asm{ jmp p_MapVirtualKeyExA } }
__declspec( naked ) void WINAPI d_MapVirtualKeyExW() { _asm{ jmp p_MapVirtualKeyExW } }
__declspec( naked ) void WINAPI d_MapVirtualKeyW() { _asm{ jmp p_MapVirtualKeyW } }
__declspec( naked ) void WINAPI d_MapWindowPoints() { _asm{ jmp p_MapWindowPoints } }
__declspec( naked ) void WINAPI d_MenuItemFromPoint() { _asm{ jmp p_MenuItemFromPoint } }
__declspec( naked ) void WINAPI d_MenuWindowProcA() { _asm{ jmp p_MenuWindowProcA } }
__declspec( naked ) void WINAPI d_MenuWindowProcW() { _asm{ jmp p_MenuWindowProcW } }
__declspec( naked ) void WINAPI d_MessageBeep() { _asm{ jmp p_MessageBeep } }
__declspec( naked ) void WINAPI d_MessageBoxA() { _asm{ jmp p_MessageBoxA } }
__declspec( naked ) void WINAPI d_MessageBoxExA() { _asm{ jmp p_MessageBoxExA } }
__declspec( naked ) void WINAPI d_MessageBoxExW() { _asm{ jmp p_MessageBoxExW } }
__declspec( naked ) void WINAPI d_MessageBoxIndirectA() { _asm{ jmp p_MessageBoxIndirectA } }
__declspec( naked ) void WINAPI d_MessageBoxIndirectW() { _asm{ jmp p_MessageBoxIndirectW } }
__declspec( naked ) void WINAPI d_MessageBoxTimeoutA() { _asm{ jmp p_MessageBoxTimeoutA } }
__declspec( naked ) void WINAPI d_MessageBoxTimeoutW() { _asm{ jmp p_MessageBoxTimeoutW } }
__declspec( naked ) void WINAPI d_MessageBoxW() { _asm{ jmp p_MessageBoxW } }
__declspec( naked ) void WINAPI d_ModifyMenuA() { _asm{ jmp p_ModifyMenuA } }
__declspec( naked ) void WINAPI d_ModifyMenuW() { _asm{ jmp p_ModifyMenuW } }
__declspec( naked ) void WINAPI d_MonitorFromPoint() { _asm{ jmp p_MonitorFromPoint } }
__declspec( naked ) void WINAPI d_MonitorFromRect() { _asm{ jmp p_MonitorFromRect } }
__declspec( naked ) void WINAPI d_MonitorFromWindow() { _asm{ jmp p_MonitorFromWindow } }
__declspec( naked ) void WINAPI d_MoveWindow() { _asm{ jmp p_MoveWindow } }
__declspec( naked ) void WINAPI d_MsgWaitForMultipleObjects() { _asm{ jmp p_MsgWaitForMultipleObjects } }
__declspec( naked ) void WINAPI d_MsgWaitForMultipleObjectsEx() { _asm{ jmp p_MsgWaitForMultipleObjectsEx } }
__declspec( naked ) void WINAPI d_NotifyWinEvent() { _asm{ jmp p_NotifyWinEvent } }
__declspec( naked ) void WINAPI d_OemKeyScan() { _asm{ jmp p_OemKeyScan } }
__declspec( naked ) void WINAPI d_OemToCharA() { _asm{ jmp p_OemToCharA } }
__declspec( naked ) void WINAPI d_OemToCharBuffA() { _asm{ jmp p_OemToCharBuffA } }
__declspec( naked ) void WINAPI d_OemToCharBuffW() { _asm{ jmp p_OemToCharBuffW } }
__declspec( naked ) void WINAPI d_OemToCharW() { _asm{ jmp p_OemToCharW } }
__declspec( naked ) void WINAPI d_OffsetRect() { _asm{ jmp p_OffsetRect } }
__declspec( naked ) void WINAPI d_OpenClipboard() { _asm{ jmp p_OpenClipboard } }
__declspec( naked ) void WINAPI d_OpenDesktopA() { _asm{ jmp p_OpenDesktopA } }
__declspec( naked ) void WINAPI d_OpenDesktopW() { _asm{ jmp p_OpenDesktopW } }
__declspec( naked ) void WINAPI d_OpenIcon() { _asm{ jmp p_OpenIcon } }
__declspec( naked ) void WINAPI d_OpenInputDesktop() { _asm{ jmp p_OpenInputDesktop } }
__declspec( naked ) void WINAPI d_OpenThreadDesktop() { _asm{ jmp p_OpenThreadDesktop } }
__declspec( naked ) void WINAPI d_OpenWindowStationA() { _asm{ jmp p_OpenWindowStationA } }
__declspec( naked ) void WINAPI d_OpenWindowStationW() { _asm{ jmp p_OpenWindowStationW } }
__declspec( naked ) void WINAPI d_PackDDElParam() { _asm{ jmp p_PackDDElParam } }
__declspec( naked ) void WINAPI d_PaintDesktop() { _asm{ jmp p_PaintDesktop } }
__declspec( naked ) void WINAPI d_PaintMenuBar() { _asm{ jmp p_PaintMenuBar } }
__declspec( naked ) void WINAPI d_PaintMonitor() { _asm{ jmp p_PaintMonitor } }
__declspec( naked ) void WINAPI d_PeekMessageA() { _asm{ jmp p_PeekMessageA } }
__declspec( naked ) void WINAPI d_PeekMessageW() { _asm{ jmp p_PeekMessageW } }
__declspec( naked ) void WINAPI d_PhysicalToLogicalPoint() { _asm{ jmp p_PhysicalToLogicalPoint } }
__declspec( naked ) void WINAPI d_PostMessageA() { _asm{ jmp p_PostMessageA } }
__declspec( naked ) void WINAPI d_PostMessageW() { _asm{ jmp p_PostMessageW } }
__declspec( naked ) void WINAPI d_PostQuitMessage() { _asm{ jmp p_PostQuitMessage } }
__declspec( naked ) void WINAPI d_PostThreadMessageA() { _asm{ jmp p_PostThreadMessageA } }
__declspec( naked ) void WINAPI d_PostThreadMessageW() { _asm{ jmp p_PostThreadMessageW } }
__declspec( naked ) void WINAPI d_PrintWindow() { _asm{ jmp p_PrintWindow } }
__declspec( naked ) void WINAPI d_PrivateExtractIconExA() { _asm{ jmp p_PrivateExtractIconExA } }
__declspec( naked ) void WINAPI d_PrivateExtractIconExW() { _asm{ jmp p_PrivateExtractIconExW } }
__declspec( naked ) void WINAPI d_PrivateExtractIconsA() { _asm{ jmp p_PrivateExtractIconsA } }
__declspec( naked ) void WINAPI d_PrivateExtractIconsW() { _asm{ jmp p_PrivateExtractIconsW } }
__declspec( naked ) void WINAPI d_PrivateRegisterICSProc() { _asm{ jmp p_PrivateRegisterICSProc } }
__declspec( naked ) void WINAPI d_PtInRect() { _asm{ jmp p_PtInRect } }
__declspec( naked ) void WINAPI d_QuerySendMessage() { _asm{ jmp p_QuerySendMessage } }
__declspec( naked ) void WINAPI d_RealChildWindowFromPoint() { _asm{ jmp p_RealChildWindowFromPoint } }
__declspec( naked ) void WINAPI d_RealGetWindowClass() { _asm{ jmp p_RealGetWindowClass } }
__declspec( naked ) void WINAPI d_RealGetWindowClassA() { _asm{ jmp p_RealGetWindowClassA } }
__declspec( naked ) void WINAPI d_RealGetWindowClassW() { _asm{ jmp p_RealGetWindowClassW } }
__declspec( naked ) void WINAPI d_ReasonCodeNeedsBugID() { _asm{ jmp p_ReasonCodeNeedsBugID } }
__declspec( naked ) void WINAPI d_ReasonCodeNeedsComment() { _asm{ jmp p_ReasonCodeNeedsComment } }
__declspec( naked ) void WINAPI d_RecordShutdownReason() { _asm{ jmp p_RecordShutdownReason } }
__declspec( naked ) void WINAPI d_RedrawWindow() { _asm{ jmp p_RedrawWindow } }
__declspec( naked ) void WINAPI d_RegisterClassA() { _asm{ jmp p_RegisterClassA } }
__declspec( naked ) void WINAPI d_RegisterClassExA() { _asm{ jmp p_RegisterClassExA } }
__declspec( naked ) void WINAPI d_RegisterClassExW() { _asm{ jmp p_RegisterClassExW } }
__declspec( naked ) void WINAPI d_RegisterClassW() { _asm{ jmp p_RegisterClassW } }
__declspec( naked ) void WINAPI d_RegisterClipboardFormatA() { _asm{ jmp p_RegisterClipboardFormatA } }
__declspec( naked ) void WINAPI d_RegisterClipboardFormatW() { _asm{ jmp p_RegisterClipboardFormatW } }
__declspec( naked ) void WINAPI d_RegisterDeviceNotificationA() { _asm{ jmp p_RegisterDeviceNotificationA } }
__declspec( naked ) void WINAPI d_RegisterDeviceNotificationW() { _asm{ jmp p_RegisterDeviceNotificationW } }
__declspec( naked ) void WINAPI d_RegisterErrorReportingDialog() { _asm{ jmp p_RegisterErrorReportingDialog } }
__declspec( naked ) void WINAPI d_RegisterFrostWindow() { _asm{ jmp p_RegisterFrostWindow } }
__declspec( naked ) void WINAPI d_RegisterGhostWindow() { _asm{ jmp p_RegisterGhostWindow } }
__declspec( naked ) void WINAPI d_RegisterHotKey() { _asm{ jmp p_RegisterHotKey } }
__declspec( naked ) void WINAPI d_RegisterLogonProcess() { _asm{ jmp p_RegisterLogonProcess } }
__declspec( naked ) void WINAPI d_RegisterMessagePumpHook() { _asm{ jmp p_RegisterMessagePumpHook } }
__declspec( naked ) void WINAPI d_RegisterPowerSettingNotification() { _asm{ jmp p_RegisterPowerSettingNotification } }
__declspec( naked ) void WINAPI d_RegisterRawInputDevices() { _asm{ jmp p_RegisterRawInputDevices } }
__declspec( naked ) void WINAPI d_RegisterServicesProcess() { _asm{ jmp p_RegisterServicesProcess } }
__declspec( naked ) void WINAPI d_RegisterSessionPort() { _asm{ jmp p_RegisterSessionPort } }
__declspec( naked ) void WINAPI d_RegisterShellHookWindow() { _asm{ jmp p_RegisterShellHookWindow } }
__declspec( naked ) void WINAPI d_RegisterSystemThread() { _asm{ jmp p_RegisterSystemThread } }
__declspec( naked ) void WINAPI d_RegisterTasklist() { _asm{ jmp p_RegisterTasklist } }
__declspec( naked ) void WINAPI d_RegisterUserApiHook() { _asm{ jmp p_RegisterUserApiHook } }
__declspec( naked ) void WINAPI d_RegisterWindowMessageA() { _asm{ jmp p_RegisterWindowMessageA } }
__declspec( naked ) void WINAPI d_RegisterWindowMessageW() { _asm{ jmp p_RegisterWindowMessageW } }
__declspec( naked ) void WINAPI d_ReleaseCapture() { _asm{ jmp p_ReleaseCapture } }
__declspec( naked ) void WINAPI d_ReleaseDC() { _asm{ jmp p_ReleaseDC } }
__declspec( naked ) void WINAPI d_RemoveClipboardFormatListener() { _asm{ jmp p_RemoveClipboardFormatListener } }
__declspec( naked ) void WINAPI d_RemoveMenu() { _asm{ jmp p_RemoveMenu } }
__declspec( naked ) void WINAPI d_RemovePropA() { _asm{ jmp p_RemovePropA } }
__declspec( naked ) void WINAPI d_RemovePropW() { _asm{ jmp p_RemovePropW } }
__declspec( naked ) void WINAPI d_ReplyMessage() { _asm{ jmp p_ReplyMessage } }
__declspec( naked ) void WINAPI d_ResolveDesktopForWOW() { _asm{ jmp p_ResolveDesktopForWOW } }
__declspec( naked ) void WINAPI d_ReuseDDElParam() { _asm{ jmp p_ReuseDDElParam } }
__declspec( naked ) void WINAPI d_ScreenToClient() { _asm{ jmp p_ScreenToClient } }
__declspec( naked ) void WINAPI d_ScrollChildren() { _asm{ jmp p_ScrollChildren } }
__declspec( naked ) void WINAPI d_ScrollDC() { _asm{ jmp p_ScrollDC } }
__declspec( naked ) void WINAPI d_ScrollWindow() { _asm{ jmp p_ScrollWindow } }
__declspec( naked ) void WINAPI d_ScrollWindowEx() { _asm{ jmp p_ScrollWindowEx } }
__declspec( naked ) void WINAPI d_SendDlgItemMessageA() { _asm{ jmp p_SendDlgItemMessageA } }
__declspec( naked ) void WINAPI d_SendDlgItemMessageW() { _asm{ jmp p_SendDlgItemMessageW } }
__declspec( naked ) void WINAPI d_SendIMEMessageExA() { _asm{ jmp p_SendIMEMessageExA } }
__declspec( naked ) void WINAPI d_SendIMEMessageExW() { _asm{ jmp p_SendIMEMessageExW } }
__declspec( naked ) void WINAPI d_SendInput() { _asm{ jmp p_SendInput } }
__declspec( naked ) void WINAPI d_SendMessageA() { _asm{ jmp p_SendMessageA } }
__declspec( naked ) void WINAPI d_SendMessageCallbackA() { _asm{ jmp p_SendMessageCallbackA } }
__declspec( naked ) void WINAPI d_SendMessageCallbackW() { _asm{ jmp p_SendMessageCallbackW } }
__declspec( naked ) void WINAPI d_SendMessageTimeoutA() { _asm{ jmp p_SendMessageTimeoutA } }
__declspec( naked ) void WINAPI d_SendMessageTimeoutW() { _asm{ jmp p_SendMessageTimeoutW } }
__declspec( naked ) void WINAPI d_SendMessageW() { _asm{ jmp p_SendMessageW } }
__declspec( naked ) void WINAPI d_SendNotifyMessageA() { _asm{ jmp p_SendNotifyMessageA } }
__declspec( naked ) void WINAPI d_SendNotifyMessageW() { _asm{ jmp p_SendNotifyMessageW } }
__declspec( naked ) void WINAPI d_SetActiveWindow() { _asm{ jmp p_SetActiveWindow } }
__declspec( naked ) void WINAPI d_SetCapture() { _asm{ jmp p_SetCapture } }
__declspec( naked ) void WINAPI d_SetCaretBlinkTime() { _asm{ jmp p_SetCaretBlinkTime } }
__declspec( naked ) void WINAPI d_SetCaretPos() { _asm{ jmp p_SetCaretPos } }
__declspec( naked ) void WINAPI d_SetClassLongA() { _asm{ jmp p_SetClassLongA } }
__declspec( naked ) void WINAPI d_SetClassLongW() { _asm{ jmp p_SetClassLongW } }
__declspec( naked ) void WINAPI d_SetClassWord() { _asm{ jmp p_SetClassWord } }
__declspec( naked ) void WINAPI d_SetClipboardData() { _asm{ jmp p_SetClipboardData } }
__declspec( naked ) void WINAPI d_SetClipboardViewer() { _asm{ jmp p_SetClipboardViewer } }
__declspec( naked ) void WINAPI d_SetConsoleReserveKeys() { _asm{ jmp p_SetConsoleReserveKeys } }
__declspec( naked ) void WINAPI d_SetCursor() { _asm{ jmp p_SetCursor } }
__declspec( naked ) void WINAPI d_SetCursorContents() { _asm{ jmp p_SetCursorContents } }
__declspec( naked ) void WINAPI d_SetCursorPos() { _asm{ jmp p_SetCursorPos } }
__declspec( naked ) void WINAPI d_SetDebugErrorLevel() { _asm{ jmp p_SetDebugErrorLevel } }
__declspec( naked ) void WINAPI d_SetDeskWallpaper() { _asm{ jmp p_SetDeskWallpaper } }
__declspec( naked ) void WINAPI d_SetDlgItemInt() { _asm{ jmp p_SetDlgItemInt } }
__declspec( naked ) void WINAPI d_SetDlgItemTextA() { _asm{ jmp p_SetDlgItemTextA } }
__declspec( naked ) void WINAPI d_SetDlgItemTextW() { _asm{ jmp p_SetDlgItemTextW } }
__declspec( naked ) void WINAPI d_SetDoubleClickTime() { _asm{ jmp p_SetDoubleClickTime } }
__declspec( naked ) void WINAPI d_SetFocus() { _asm{ jmp p_SetFocus } }
__declspec( naked ) void WINAPI d_SetForegroundWindow() { _asm{ jmp p_SetForegroundWindow } }
__declspec( naked ) void WINAPI d_SetInternalWindowPos() { _asm{ jmp p_SetInternalWindowPos } }
__declspec( naked ) void WINAPI d_SetKeyboardState() { _asm{ jmp p_SetKeyboardState } }
__declspec( naked ) void WINAPI d_SetLastErrorEx() { _asm{ jmp p_SetLastErrorEx } }
__declspec( naked ) void WINAPI d_SetLayeredWindowAttributes() { _asm{ jmp p_SetLayeredWindowAttributes } }
__declspec( naked ) void WINAPI d_SetMenu() { _asm{ jmp p_SetMenu } }
__declspec( naked ) void WINAPI d_SetMenuContextHelpId() { _asm{ jmp p_SetMenuContextHelpId } }
__declspec( naked ) void WINAPI d_SetMenuDefaultItem() { _asm{ jmp p_SetMenuDefaultItem } }
__declspec( naked ) void WINAPI d_SetMenuInfo() { _asm{ jmp p_SetMenuInfo } }
__declspec( naked ) void WINAPI d_SetMenuItemBitmaps() { _asm{ jmp p_SetMenuItemBitmaps } }
__declspec( naked ) void WINAPI d_SetMenuItemInfoA() { _asm{ jmp p_SetMenuItemInfoA } }
__declspec( naked ) void WINAPI d_SetMenuItemInfoW() { _asm{ jmp p_SetMenuItemInfoW } }
__declspec( naked ) void WINAPI d_SetMessageExtraInfo() { _asm{ jmp p_SetMessageExtraInfo } }
__declspec( naked ) void WINAPI d_SetMessageQueue() { _asm{ jmp p_SetMessageQueue } }
__declspec( naked ) void WINAPI d_SetMirrorRendering() { _asm{ jmp p_SetMirrorRendering } }
__declspec( naked ) void WINAPI d_SetParent() { _asm{ jmp p_SetParent } }
__declspec( naked ) void WINAPI d_SetPhysicalCursorPos() { _asm{ jmp p_SetPhysicalCursorPos } }
__declspec( naked ) void WINAPI d_SetProcessDPIAware() { _asm{ jmp p_SetProcessDPIAware } }
__declspec( naked ) void WINAPI d_SetProcessDefaultLayout() { _asm{ jmp p_SetProcessDefaultLayout } }
__declspec( naked ) void WINAPI d_SetProcessWindowStation() { _asm{ jmp p_SetProcessWindowStation } }
__declspec( naked ) void WINAPI d_SetProgmanWindow() { _asm{ jmp p_SetProgmanWindow } }
__declspec( naked ) void WINAPI d_SetPropA() { _asm{ jmp p_SetPropA } }
__declspec( naked ) void WINAPI d_SetPropW() { _asm{ jmp p_SetPropW } }
__declspec( naked ) void WINAPI d_SetRect() { _asm{ jmp p_SetRect } }
__declspec( naked ) void WINAPI d_SetRectEmpty() { _asm{ jmp p_SetRectEmpty } }
__declspec( naked ) void WINAPI d_SetScrollInfo() { _asm{ jmp p_SetScrollInfo } }
__declspec( naked ) void WINAPI d_SetScrollPos() { _asm{ jmp p_SetScrollPos } }
__declspec( naked ) void WINAPI d_SetScrollRange() { _asm{ jmp p_SetScrollRange } }
__declspec( naked ) void WINAPI d_SetShellWindow() { _asm{ jmp p_SetShellWindow } }
__declspec( naked ) void WINAPI d_SetShellWindowEx() { _asm{ jmp p_SetShellWindowEx } }
__declspec( naked ) void WINAPI d_SetSysColors() { _asm{ jmp p_SetSysColors } }
__declspec( naked ) void WINAPI d_SetSysColorsTemp() { _asm{ jmp p_SetSysColorsTemp } }
__declspec( naked ) void WINAPI d_SetSystemCursor() { _asm{ jmp p_SetSystemCursor } }
__declspec( naked ) void WINAPI d_SetSystemMenu() { _asm{ jmp p_SetSystemMenu } }
__declspec( naked ) void WINAPI d_SetTaskmanWindow() { _asm{ jmp p_SetTaskmanWindow } }
__declspec( naked ) void WINAPI d_SetThreadDesktop() { _asm{ jmp p_SetThreadDesktop } }
__declspec( naked ) void WINAPI d_SetTimer() { _asm{ jmp p_SetTimer } }
__declspec( naked ) void WINAPI d_SetUserObjectInformationA() { _asm{ jmp p_SetUserObjectInformationA } }
__declspec( naked ) void WINAPI d_SetUserObjectInformationW() { _asm{ jmp p_SetUserObjectInformationW } }
__declspec( naked ) void WINAPI d_SetUserObjectSecurity() { _asm{ jmp p_SetUserObjectSecurity } }
__declspec( naked ) void WINAPI d_SetWinEventHook() { _asm{ jmp p_SetWinEventHook } }
__declspec( naked ) void WINAPI d_SetWindowContextHelpId() { _asm{ jmp p_SetWindowContextHelpId } }
__declspec( naked ) void WINAPI d_SetWindowLongA() { _asm{ jmp p_SetWindowLongA } }
__declspec( naked ) void WINAPI d_SetWindowLongW() { _asm{ jmp p_SetWindowLongW } }
__declspec( naked ) void WINAPI d_SetWindowPlacement() { _asm{ jmp p_SetWindowPlacement } }
__declspec( naked ) void WINAPI d_SetWindowPos() { _asm{ jmp p_SetWindowPos } }
__declspec( naked ) void WINAPI d_SetWindowRgn() { _asm{ jmp p_SetWindowRgn } }
__declspec( naked ) void WINAPI d_SetWindowRgnEx() { _asm{ jmp p_SetWindowRgnEx } }
__declspec( naked ) void WINAPI d_SetWindowStationUser() { _asm{ jmp p_SetWindowStationUser } }
__declspec( naked ) void WINAPI d_SetWindowTextA() { _asm{ jmp p_SetWindowTextA } }
__declspec( naked ) void WINAPI d_SetWindowTextW() { _asm{ jmp p_SetWindowTextW } }
__declspec( naked ) void WINAPI d_SetWindowWord() { _asm{ jmp p_SetWindowWord } }
__declspec( naked ) void WINAPI d_SetWindowsHookA() { _asm{ jmp p_SetWindowsHookA } }
__declspec( naked ) void WINAPI d_SetWindowsHookExA() { _asm{ jmp p_SetWindowsHookExA } }
__declspec( naked ) void WINAPI d_SetWindowsHookExW() { _asm{ jmp p_SetWindowsHookExW } }
__declspec( naked ) void WINAPI d_SetWindowsHookW() { _asm{ jmp p_SetWindowsHookW } }
__declspec( naked ) void WINAPI d_ShowCaret() { _asm{ jmp p_ShowCaret } }
__declspec( naked ) void WINAPI d_ShowCursor() { _asm{ jmp p_ShowCursor } }
__declspec( naked ) void WINAPI d_ShowOwnedPopups() { _asm{ jmp p_ShowOwnedPopups } }
__declspec( naked ) void WINAPI d_ShowScrollBar() { _asm{ jmp p_ShowScrollBar } }
__declspec( naked ) void WINAPI d_ShowStartGlass() { _asm{ jmp p_ShowStartGlass } }
__declspec( naked ) void WINAPI d_ShowSystemCursor() { _asm{ jmp p_ShowSystemCursor } }
__declspec( naked ) void WINAPI d_ShowWindow() { _asm{ jmp p_ShowWindow } }
__declspec( naked ) void WINAPI d_ShowWindowAsync() { _asm{ jmp p_ShowWindowAsync } }
__declspec( naked ) void WINAPI d_ShutdownBlockReasonCreate() { _asm{ jmp p_ShutdownBlockReasonCreate } }
__declspec( naked ) void WINAPI d_ShutdownBlockReasonDestroy() { _asm{ jmp p_ShutdownBlockReasonDestroy } }
__declspec( naked ) void WINAPI d_ShutdownBlockReasonQuery() { _asm{ jmp p_ShutdownBlockReasonQuery } }
__declspec( naked ) void WINAPI d_SoftModalMessageBox() { _asm{ jmp p_SoftModalMessageBox } }
__declspec( naked ) void WINAPI d_SoundSentry() { _asm{ jmp p_SoundSentry } }
__declspec( naked ) void WINAPI d_SubtractRect() { _asm{ jmp p_SubtractRect } }
__declspec( naked ) void WINAPI d_SwapMouseButton() { _asm{ jmp p_SwapMouseButton } }
__declspec( naked ) void WINAPI d_SwitchDesktop() { _asm{ jmp p_SwitchDesktop } }
__declspec( naked ) void WINAPI d_SwitchDesktopWithFade() { _asm{ jmp p_SwitchDesktopWithFade } }
__declspec( naked ) void WINAPI d_SwitchToThisWindow() { _asm{ jmp p_SwitchToThisWindow } }
__declspec( naked ) void WINAPI d_SystemParametersInfoA() { _asm{ jmp p_SystemParametersInfoA } }
__declspec( naked ) void WINAPI d_SystemParametersInfoW() { _asm{ jmp p_SystemParametersInfoW } }
__declspec( naked ) void WINAPI d_TabbedTextOutA() { _asm{ jmp p_TabbedTextOutA } }
__declspec( naked ) void WINAPI d_TabbedTextOutW() { _asm{ jmp p_TabbedTextOutW } }
__declspec( naked ) void WINAPI d_TileChildWindows() { _asm{ jmp p_TileChildWindows } }
__declspec( naked ) void WINAPI d_TileWindows() { _asm{ jmp p_TileWindows } }
__declspec( naked ) void WINAPI d_ToAscii() { _asm{ jmp p_ToAscii } }
__declspec( naked ) void WINAPI d_ToAsciiEx() { _asm{ jmp p_ToAsciiEx } }
__declspec( naked ) void WINAPI d_ToUnicode() { _asm{ jmp p_ToUnicode } }
__declspec( naked ) void WINAPI d_ToUnicodeEx() { _asm{ jmp p_ToUnicodeEx } }
__declspec( naked ) void WINAPI d_TrackMouseEvent() { _asm{ jmp p_TrackMouseEvent } }
__declspec( naked ) void WINAPI d_TrackPopupMenu() { _asm{ jmp p_TrackPopupMenu } }
__declspec( naked ) void WINAPI d_TrackPopupMenuEx() { _asm{ jmp p_TrackPopupMenuEx } }
__declspec( naked ) void WINAPI d_TranslateAccelerator() { _asm{ jmp p_TranslateAccelerator } }
__declspec( naked ) void WINAPI d_TranslateAcceleratorA() { _asm{ jmp p_TranslateAcceleratorA } }
__declspec( naked ) void WINAPI d_TranslateAcceleratorW() { _asm{ jmp p_TranslateAcceleratorW } }
__declspec( naked ) void WINAPI d_TranslateMDISysAccel() { _asm{ jmp p_TranslateMDISysAccel } }
__declspec( naked ) void WINAPI d_TranslateMessage() { _asm{ jmp p_TranslateMessage } }
__declspec( naked ) void WINAPI d_TranslateMessageEx() { _asm{ jmp p_TranslateMessageEx } }
__declspec( naked ) void WINAPI d_UnhookWinEvent() { _asm{ jmp p_UnhookWinEvent } }
__declspec( naked ) void WINAPI d_UnhookWindowsHook() { _asm{ jmp p_UnhookWindowsHook } }
__declspec( naked ) void WINAPI d_UnhookWindowsHookEx() { _asm{ jmp p_UnhookWindowsHookEx } }
__declspec( naked ) void WINAPI d_UnionRect() { _asm{ jmp p_UnionRect } }
__declspec( naked ) void WINAPI d_UnloadKeyboardLayout() { _asm{ jmp p_UnloadKeyboardLayout } }
__declspec( naked ) void WINAPI d_UnlockWindowStation() { _asm{ jmp p_UnlockWindowStation } }
__declspec( naked ) void WINAPI d_UnpackDDElParam() { _asm{ jmp p_UnpackDDElParam } }
__declspec( naked ) void WINAPI d_UnregisterClassA() { _asm{ jmp p_UnregisterClassA } }
__declspec( naked ) void WINAPI d_UnregisterClassW() { _asm{ jmp p_UnregisterClassW } }
__declspec( naked ) void WINAPI d_UnregisterDeviceNotification() { _asm{ jmp p_UnregisterDeviceNotification } }
__declspec( naked ) void WINAPI d_UnregisterHotKey() { _asm{ jmp p_UnregisterHotKey } }
__declspec( naked ) void WINAPI d_UnregisterMessagePumpHook() { _asm{ jmp p_UnregisterMessagePumpHook } }
__declspec( naked ) void WINAPI d_UnregisterPowerSettingNotification() { _asm{ jmp p_UnregisterPowerSettingNotification } }
__declspec( naked ) void WINAPI d_UnregisterSessionPort() { _asm{ jmp p_UnregisterSessionPort } }
__declspec( naked ) void WINAPI d_UnregisterUserApiHook() { _asm{ jmp p_UnregisterUserApiHook } }
__declspec( naked ) void WINAPI d_UpdateLayeredWindow() { _asm{ jmp p_UpdateLayeredWindow } }
__declspec( naked ) void WINAPI d_UpdateLayeredWindowIndirect() { _asm{ jmp p_UpdateLayeredWindowIndirect } }
__declspec( naked ) void WINAPI d_UpdatePerUserSystemParameters() { _asm{ jmp p_UpdatePerUserSystemParameters } }
__declspec( naked ) void WINAPI d_UpdateWindow() { _asm{ jmp p_UpdateWindow } }
__declspec( naked ) void WINAPI d_UpdateWindowTransform() { _asm{ jmp p_UpdateWindowTransform } }
__declspec( naked ) void WINAPI d_User32InitializeImmEntryTable() { _asm{ jmp p_User32InitializeImmEntryTable } }
__declspec( naked ) void WINAPI d_UserClientDllInitialize() { _asm{ jmp p_UserClientDllInitialize } }
__declspec( naked ) void WINAPI d_UserHandleGrantAccess() { _asm{ jmp p_UserHandleGrantAccess } }
__declspec( naked ) void WINAPI d_UserLpkPSMTextOut() { _asm{ jmp p_UserLpkPSMTextOut } }
__declspec( naked ) void WINAPI d_UserLpkTabbedTextOut() { _asm{ jmp p_UserLpkTabbedTextOut } }
__declspec( naked ) void WINAPI d_UserRealizePalette() { _asm{ jmp p_UserRealizePalette } }
__declspec( naked ) void WINAPI d_UserRegisterWowHandlers() { _asm{ jmp p_UserRegisterWowHandlers } }
__declspec( naked ) void WINAPI d_ValidateRect() { _asm{ jmp p_ValidateRect } }
__declspec( naked ) void WINAPI d_ValidateRgn() { _asm{ jmp p_ValidateRgn } }
__declspec( naked ) void WINAPI d_VkKeyScanA() { _asm{ jmp p_VkKeyScanA } }
__declspec( naked ) void WINAPI d_VkKeyScanExA() { _asm{ jmp p_VkKeyScanExA } }
__declspec( naked ) void WINAPI d_VkKeyScanExW() { _asm{ jmp p_VkKeyScanExW } }
__declspec( naked ) void WINAPI d_VkKeyScanW() { _asm{ jmp p_VkKeyScanW } }
__declspec( naked ) void WINAPI d_WCSToMBEx() { _asm{ jmp p_WCSToMBEx } }
__declspec( naked ) void WINAPI d_WINNLSEnableIME() { _asm{ jmp p_WINNLSEnableIME } }
__declspec( naked ) void WINAPI d_WINNLSGetEnableStatus() { _asm{ jmp p_WINNLSGetEnableStatus } }
__declspec( naked ) void WINAPI d_WINNLSGetIMEHotkey() { _asm{ jmp p_WINNLSGetIMEHotkey } }
__declspec( naked ) void WINAPI d_WaitForInputIdle() { _asm{ jmp p_WaitForInputIdle } }
__declspec( naked ) void WINAPI d_WaitMessage() { _asm{ jmp p_WaitMessage } }
__declspec( naked ) void WINAPI d_Win32PoolAllocationStats() { _asm{ jmp p_Win32PoolAllocationStats } }
__declspec( naked ) void WINAPI d_WinHelpA() { _asm{ jmp p_WinHelpA } }
__declspec( naked ) void WINAPI d_WinHelpW() { _asm{ jmp p_WinHelpW } }
__declspec( naked ) void WINAPI d_WindowFromDC() { _asm{ jmp p_WindowFromDC } }
__declspec( naked ) void WINAPI d_WindowFromPhysicalPoint() { _asm{ jmp p_WindowFromPhysicalPoint } }
__declspec( naked ) void WINAPI d_WindowFromPoint() { _asm{ jmp p_WindowFromPoint } }
__declspec( naked ) void WINAPI d__UserTestTokenForInteractive() { _asm{ jmp p__UserTestTokenForInteractive } }
__declspec( naked ) void WINAPI d_keybd_event() { _asm{ jmp p_keybd_event } }
__declspec( naked ) void WINAPI d_mouse_event() { _asm{ jmp p_mouse_event } }
__declspec( naked ) void WINAPI d_wsprintfA() { _asm{ jmp p_wsprintfA } }
__declspec( naked ) void WINAPI d_wsprintfW() { _asm{ jmp p_wsprintfW } }
__declspec( naked ) void WINAPI d_wvsprintfA() { _asm{ jmp p_wvsprintfA } }
__declspec( naked ) void WINAPI d_wvsprintfW() { _asm{ jmp p_wvsprintfW } }


  BOOL WINAPI d_GetGestureInfo(
    __in HGESTUREINFO hGestureInfo,
    __out PGESTUREINFO pGestureInfo)
  {
	  return 1;
  }
  BOOL WINAPI d_GetGestureConfig(
  __in     HWND hwnd,
  __in     DWORD dwReserved,
  __in     DWORD dwFlags,
  __in     PUINT pcIDs,
  __inout  PGESTURECONFIG pGestureConfig,
  __in     UINT cbSize
  )
  {
	  return 1;
  }
  BOOL WINAPI d_SetGestureConfig(
  __in  HWND hwnd,
  __in  DWORD dwReserved,
  __in  UINT cIDs,
  __in  PGESTURECONFIG pGestureConfig,
  __in  UINT cbSize
  )
  {
	  return 1;
  }
  BOOL WINAPI d_CloseGestureInfoHandle(
    HGESTUREINFO hGestureInfo
  )
  {
	  return 1;
  }



}
HINSTANCE h_original;
BOOL APIENTRY DllMain(HANDLE hModule,
                      DWORD  ul_reason_for_call,
                      LPVOID lpReserved)
{
    switch(ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        h_original = LoadLibrary("user32.dll");
        if(h_original == NULL)
            return FALSE;
        p_NONAME1 = GetProcAddress(h_original, MAKEINTRESOURCE(2000));
        p_ActivateKeyboardLayout = GetProcAddress(h_original, "ActivateKeyboardLayout");
        p_AddClipboardFormatListener = GetProcAddress(h_original, "AddClipboardFormatListener");
        p_AdjustWindowRect = GetProcAddress(h_original, "AdjustWindowRect");
        p_AdjustWindowRectEx = GetProcAddress(h_original, "AdjustWindowRectEx");
        p_AlignRects = GetProcAddress(h_original, "AlignRects");
        p_AllowForegroundActivation = GetProcAddress(h_original, "AllowForegroundActivation");
        p_AllowSetForegroundWindow = GetProcAddress(h_original, "AllowSetForegroundWindow");
        p_AnimateWindow = GetProcAddress(h_original, "AnimateWindow");
        p_AnyPopup = GetProcAddress(h_original, "AnyPopup");
        p_AppendMenuA = GetProcAddress(h_original, "AppendMenuA");
        p_AppendMenuW = GetProcAddress(h_original, "AppendMenuW");
        p_ArrangeIconicWindows = GetProcAddress(h_original, "ArrangeIconicWindows");
        p_AttachThreadInput = GetProcAddress(h_original, "AttachThreadInput");
        p_BeginDeferWindowPos = GetProcAddress(h_original, "BeginDeferWindowPos");
        p_BeginPaint = GetProcAddress(h_original, "BeginPaint");
        p_BlockInput = GetProcAddress(h_original, "BlockInput");
        p_BringWindowToTop = GetProcAddress(h_original, "BringWindowToTop");
        p_BroadcastSystemMessage = GetProcAddress(h_original, "BroadcastSystemMessage");
        p_BroadcastSystemMessageA = GetProcAddress(h_original, "BroadcastSystemMessageA");
        p_BroadcastSystemMessageExA = GetProcAddress(h_original, "BroadcastSystemMessageExA");
        p_BroadcastSystemMessageExW = GetProcAddress(h_original, "BroadcastSystemMessageExW");
        p_BroadcastSystemMessageW = GetProcAddress(h_original, "BroadcastSystemMessageW");
        p_BuildReasonArray = GetProcAddress(h_original, "BuildReasonArray");
        p_CalcMenuBar = GetProcAddress(h_original, "CalcMenuBar");
        p_CallMsgFilter = GetProcAddress(h_original, "CallMsgFilter");
        p_CallMsgFilterA = GetProcAddress(h_original, "CallMsgFilterA");
        p_CallMsgFilterW = GetProcAddress(h_original, "CallMsgFilterW");
        p_CallNextHookEx = GetProcAddress(h_original, "CallNextHookEx");
        p_CallWindowProcA = GetProcAddress(h_original, "CallWindowProcA");
        p_CallWindowProcW = GetProcAddress(h_original, "CallWindowProcW");
        p_CancelShutdown = GetProcAddress(h_original, "CancelShutdown");
        p_CascadeChildWindows = GetProcAddress(h_original, "CascadeChildWindows");
        p_CascadeWindows = GetProcAddress(h_original, "CascadeWindows");
        p_ChangeClipboardChain = GetProcAddress(h_original, "ChangeClipboardChain");
        p_ChangeDisplaySettingsA = GetProcAddress(h_original, "ChangeDisplaySettingsA");
        p_ChangeDisplaySettingsExA = GetProcAddress(h_original, "ChangeDisplaySettingsExA");
        p_ChangeDisplaySettingsExW = GetProcAddress(h_original, "ChangeDisplaySettingsExW");
        p_ChangeDisplaySettingsW = GetProcAddress(h_original, "ChangeDisplaySettingsW");
        p_ChangeMenuA = GetProcAddress(h_original, "ChangeMenuA");
        p_ChangeMenuW = GetProcAddress(h_original, "ChangeMenuW");
        p_ChangeWindowMessageFilter = GetProcAddress(h_original, "ChangeWindowMessageFilter");
        p_CharLowerA = GetProcAddress(h_original, "CharLowerA");
        p_CharLowerBuffA = GetProcAddress(h_original, "CharLowerBuffA");
        p_CharLowerBuffW = GetProcAddress(h_original, "CharLowerBuffW");
        p_CharLowerW = GetProcAddress(h_original, "CharLowerW");
        p_CharNextA = GetProcAddress(h_original, "CharNextA");
        p_CharNextExA = GetProcAddress(h_original, "CharNextExA");
        p_CharNextW = GetProcAddress(h_original, "CharNextW");
        p_CharPrevA = GetProcAddress(h_original, "CharPrevA");
        p_CharPrevExA = GetProcAddress(h_original, "CharPrevExA");
        p_CharPrevW = GetProcAddress(h_original, "CharPrevW");
        p_CharToOemA = GetProcAddress(h_original, "CharToOemA");
        p_CharToOemBuffA = GetProcAddress(h_original, "CharToOemBuffA");
        p_CharToOemBuffW = GetProcAddress(h_original, "CharToOemBuffW");
        p_CharToOemW = GetProcAddress(h_original, "CharToOemW");
        p_CharUpperA = GetProcAddress(h_original, "CharUpperA");
        p_CharUpperBuffA = GetProcAddress(h_original, "CharUpperBuffA");
        p_CharUpperBuffW = GetProcAddress(h_original, "CharUpperBuffW");
        p_CharUpperW = GetProcAddress(h_original, "CharUpperW");
        p_CheckDesktopByThreadId = GetProcAddress(h_original, "CheckDesktopByThreadId");
        p_CheckDlgButton = GetProcAddress(h_original, "CheckDlgButton");
        p_CheckMenuItem = GetProcAddress(h_original, "CheckMenuItem");
        p_CheckMenuRadioItem = GetProcAddress(h_original, "CheckMenuRadioItem");
        p_CheckRadioButton = GetProcAddress(h_original, "CheckRadioButton");
        p_CheckWindowThreadDesktop = GetProcAddress(h_original, "CheckWindowThreadDesktop");
        p_ChildWindowFromPoint = GetProcAddress(h_original, "ChildWindowFromPoint");
        p_ChildWindowFromPointEx = GetProcAddress(h_original, "ChildWindowFromPointEx");
        p_CliImmSetHotKey = GetProcAddress(h_original, "CliImmSetHotKey");
        p_ClientThreadSetup = GetProcAddress(h_original, "ClientThreadSetup");
        p_ClientToScreen = GetProcAddress(h_original, "ClientToScreen");
        p_ClipCursor = GetProcAddress(h_original, "ClipCursor");
        p_CloseClipboard = GetProcAddress(h_original, "CloseClipboard");
        p_CloseDesktop = GetProcAddress(h_original, "CloseDesktop");
        p_CloseWindow = GetProcAddress(h_original, "CloseWindow");
        p_CloseWindowStation = GetProcAddress(h_original, "CloseWindowStation");
        p_CopyAcceleratorTableA = GetProcAddress(h_original, "CopyAcceleratorTableA");
        p_CopyAcceleratorTableW = GetProcAddress(h_original, "CopyAcceleratorTableW");
        p_CopyIcon = GetProcAddress(h_original, "CopyIcon");
        p_CopyImage = GetProcAddress(h_original, "CopyImage");
        p_CopyRect = GetProcAddress(h_original, "CopyRect");
        p_CountClipboardFormats = GetProcAddress(h_original, "CountClipboardFormats");
        p_CreateAcceleratorTableA = GetProcAddress(h_original, "CreateAcceleratorTableA");
        p_CreateAcceleratorTableW = GetProcAddress(h_original, "CreateAcceleratorTableW");
        p_CreateCaret = GetProcAddress(h_original, "CreateCaret");
        p_CreateCursor = GetProcAddress(h_original, "CreateCursor");
        p_CreateDesktopA = GetProcAddress(h_original, "CreateDesktopA");
        p_CreateDesktopExA = GetProcAddress(h_original, "CreateDesktopExA");
        p_CreateDesktopExW = GetProcAddress(h_original, "CreateDesktopExW");
        p_CreateDesktopW = GetProcAddress(h_original, "CreateDesktopW");
        p_CreateDialogIndirectParamA = GetProcAddress(h_original, "CreateDialogIndirectParamA");
        p_CreateDialogIndirectParamAorW = GetProcAddress(h_original, "CreateDialogIndirectParamAorW");
        p_CreateDialogIndirectParamW = GetProcAddress(h_original, "CreateDialogIndirectParamW");
        p_CreateDialogParamA = GetProcAddress(h_original, "CreateDialogParamA");
        p_CreateDialogParamW = GetProcAddress(h_original, "CreateDialogParamW");
        p_CreateIcon = GetProcAddress(h_original, "CreateIcon");
        p_CreateIconFromResource = GetProcAddress(h_original, "CreateIconFromResource");
        p_CreateIconFromResourceEx = GetProcAddress(h_original, "CreateIconFromResourceEx");
        p_CreateIconIndirect = GetProcAddress(h_original, "CreateIconIndirect");
        p_CreateMDIWindowA = GetProcAddress(h_original, "CreateMDIWindowA");
        p_CreateMDIWindowW = GetProcAddress(h_original, "CreateMDIWindowW");
        p_CreateMenu = GetProcAddress(h_original, "CreateMenu");
        p_CreatePopupMenu = GetProcAddress(h_original, "CreatePopupMenu");
        p_CreateSystemThreads = GetProcAddress(h_original, "CreateSystemThreads");
        p_CreateWindowExA = GetProcAddress(h_original, "CreateWindowExA");
        p_CreateWindowExW = GetProcAddress(h_original, "CreateWindowExW");
        p_CreateWindowStationA = GetProcAddress(h_original, "CreateWindowStationA");
        p_CreateWindowStationW = GetProcAddress(h_original, "CreateWindowStationW");
        p_CsrBroadcastSystemMessageExW = GetProcAddress(h_original, "CsrBroadcastSystemMessageExW");
        p_CtxInitUser32 = GetProcAddress(h_original, "CtxInitUser32");
        p_DdeAbandonTransaction = GetProcAddress(h_original, "DdeAbandonTransaction");
        p_DdeAccessData = GetProcAddress(h_original, "DdeAccessData");
        p_DdeAddData = GetProcAddress(h_original, "DdeAddData");
        p_DdeClientTransaction = GetProcAddress(h_original, "DdeClientTransaction");
        p_DdeCmpStringHandles = GetProcAddress(h_original, "DdeCmpStringHandles");
        p_DdeConnect = GetProcAddress(h_original, "DdeConnect");
        p_DdeConnectList = GetProcAddress(h_original, "DdeConnectList");
        p_DdeCreateDataHandle = GetProcAddress(h_original, "DdeCreateDataHandle");
        p_DdeCreateStringHandleA = GetProcAddress(h_original, "DdeCreateStringHandleA");
        p_DdeCreateStringHandleW = GetProcAddress(h_original, "DdeCreateStringHandleW");
        p_DdeDisconnect = GetProcAddress(h_original, "DdeDisconnect");
        p_DdeDisconnectList = GetProcAddress(h_original, "DdeDisconnectList");
        p_DdeEnableCallback = GetProcAddress(h_original, "DdeEnableCallback");
        p_DdeFreeDataHandle = GetProcAddress(h_original, "DdeFreeDataHandle");
        p_DdeFreeStringHandle = GetProcAddress(h_original, "DdeFreeStringHandle");
        p_DdeGetData = GetProcAddress(h_original, "DdeGetData");
        p_DdeGetLastError = GetProcAddress(h_original, "DdeGetLastError");
        p_DdeGetQualityOfService = GetProcAddress(h_original, "DdeGetQualityOfService");
        p_DdeImpersonateClient = GetProcAddress(h_original, "DdeImpersonateClient");
        p_DdeInitializeA = GetProcAddress(h_original, "DdeInitializeA");
        p_DdeInitializeW = GetProcAddress(h_original, "DdeInitializeW");
        p_DdeKeepStringHandle = GetProcAddress(h_original, "DdeKeepStringHandle");
        p_DdeNameService = GetProcAddress(h_original, "DdeNameService");
        p_DdePostAdvise = GetProcAddress(h_original, "DdePostAdvise");
        p_DdeQueryConvInfo = GetProcAddress(h_original, "DdeQueryConvInfo");
        p_DdeQueryNextServer = GetProcAddress(h_original, "DdeQueryNextServer");
        p_DdeQueryStringA = GetProcAddress(h_original, "DdeQueryStringA");
        p_DdeQueryStringW = GetProcAddress(h_original, "DdeQueryStringW");
        p_DdeReconnect = GetProcAddress(h_original, "DdeReconnect");
        p_DdeSetQualityOfService = GetProcAddress(h_original, "DdeSetQualityOfService");
        p_DdeSetUserHandle = GetProcAddress(h_original, "DdeSetUserHandle");
        p_DdeUnaccessData = GetProcAddress(h_original, "DdeUnaccessData");
        p_DdeUninitialize = GetProcAddress(h_original, "DdeUninitialize");
        p_DefDlgProcA = GetProcAddress(h_original, "DefDlgProcA");
        p_DefDlgProcW = GetProcAddress(h_original, "DefDlgProcW");
        p_DefFrameProcA = GetProcAddress(h_original, "DefFrameProcA");
        p_DefFrameProcW = GetProcAddress(h_original, "DefFrameProcW");
        p_DefMDIChildProcA = GetProcAddress(h_original, "DefMDIChildProcA");
        p_DefMDIChildProcW = GetProcAddress(h_original, "DefMDIChildProcW");
        p_DefRawInputProc = GetProcAddress(h_original, "DefRawInputProc");
        p_DefWindowProcA = GetProcAddress(h_original, "DefWindowProcA");
        p_DefWindowProcW = GetProcAddress(h_original, "DefWindowProcW");
        p_DeferWindowPos = GetProcAddress(h_original, "DeferWindowPos");
        p_DeleteMenu = GetProcAddress(h_original, "DeleteMenu");
        p_DeregisterShellHookWindow = GetProcAddress(h_original, "DeregisterShellHookWindow");
        p_DestroyAcceleratorTable = GetProcAddress(h_original, "DestroyAcceleratorTable");
        p_DestroyCaret = GetProcAddress(h_original, "DestroyCaret");
        p_DestroyCursor = GetProcAddress(h_original, "DestroyCursor");
        p_DestroyIcon = GetProcAddress(h_original, "DestroyIcon");
        p_DestroyMenu = GetProcAddress(h_original, "DestroyMenu");
        p_DestroyReasons = GetProcAddress(h_original, "DestroyReasons");
        p_DestroyWindow = GetProcAddress(h_original, "DestroyWindow");
        p_DeviceEventWorker = GetProcAddress(h_original, "DeviceEventWorker");
        p_DialogBoxIndirectParamA = GetProcAddress(h_original, "DialogBoxIndirectParamA");
        p_DialogBoxIndirectParamAorW = GetProcAddress(h_original, "DialogBoxIndirectParamAorW");
        p_DialogBoxIndirectParamW = GetProcAddress(h_original, "DialogBoxIndirectParamW");
        p_DialogBoxParamA = GetProcAddress(h_original, "DialogBoxParamA");
        p_DialogBoxParamW = GetProcAddress(h_original, "DialogBoxParamW");
        p_DisableProcessWindowsGhosting = GetProcAddress(h_original, "DisableProcessWindowsGhosting");
        p_DispatchMessageA = GetProcAddress(h_original, "DispatchMessageA");
        p_DispatchMessageW = GetProcAddress(h_original, "DispatchMessageW");
        p_DisplayExitWindowsWarnings = GetProcAddress(h_original, "DisplayExitWindowsWarnings");
        p_DlgDirListA = GetProcAddress(h_original, "DlgDirListA");
        p_DlgDirListComboBoxA = GetProcAddress(h_original, "DlgDirListComboBoxA");
        p_DlgDirListComboBoxW = GetProcAddress(h_original, "DlgDirListComboBoxW");
        p_DlgDirListW = GetProcAddress(h_original, "DlgDirListW");
        p_DlgDirSelectComboBoxExA = GetProcAddress(h_original, "DlgDirSelectComboBoxExA");
        p_DlgDirSelectComboBoxExW = GetProcAddress(h_original, "DlgDirSelectComboBoxExW");
        p_DlgDirSelectExA = GetProcAddress(h_original, "DlgDirSelectExA");
        p_DlgDirSelectExW = GetProcAddress(h_original, "DlgDirSelectExW");
        p_DoSoundConnect = GetProcAddress(h_original, "DoSoundConnect");
        p_DoSoundDisconnect = GetProcAddress(h_original, "DoSoundDisconnect");
        p_DragDetect = GetProcAddress(h_original, "DragDetect");
        p_DragObject = GetProcAddress(h_original, "DragObject");
        p_DrawAnimatedRects = GetProcAddress(h_original, "DrawAnimatedRects");
        p_DrawCaption = GetProcAddress(h_original, "DrawCaption");
        p_DrawCaptionTempA = GetProcAddress(h_original, "DrawCaptionTempA");
        p_DrawCaptionTempW = GetProcAddress(h_original, "DrawCaptionTempW");
        p_DrawEdge = GetProcAddress(h_original, "DrawEdge");
        p_DrawFocusRect = GetProcAddress(h_original, "DrawFocusRect");
        p_DrawFrame = GetProcAddress(h_original, "DrawFrame");
        p_DrawFrameControl = GetProcAddress(h_original, "DrawFrameControl");
        p_DrawIcon = GetProcAddress(h_original, "DrawIcon");
        p_DrawIconEx = GetProcAddress(h_original, "DrawIconEx");
        p_DrawMenuBar = GetProcAddress(h_original, "DrawMenuBar");
        p_DrawMenuBarTemp = GetProcAddress(h_original, "DrawMenuBarTemp");
        p_DrawStateA = GetProcAddress(h_original, "DrawStateA");
        p_DrawStateW = GetProcAddress(h_original, "DrawStateW");
        p_DrawTextA = GetProcAddress(h_original, "DrawTextA");
        p_DrawTextExA = GetProcAddress(h_original, "DrawTextExA");
        p_DrawTextExW = GetProcAddress(h_original, "DrawTextExW");
        p_DrawTextW = GetProcAddress(h_original, "DrawTextW");
        p_DwmGetDxRgn = GetProcAddress(h_original, "DwmGetDxRgn");
        p_DwmHintDxUpdate = GetProcAddress(h_original, "DwmHintDxUpdate");
        p_DwmStartRedirection = GetProcAddress(h_original, "DwmStartRedirection");
        p_DwmStopRedirection = GetProcAddress(h_original, "DwmStopRedirection");
        p_EditWndProc = GetProcAddress(h_original, "EditWndProc");
        p_EmptyClipboard = GetProcAddress(h_original, "EmptyClipboard");
        p_EnableMenuItem = GetProcAddress(h_original, "EnableMenuItem");
        p_EnableScrollBar = GetProcAddress(h_original, "EnableScrollBar");
        p_EnableWindow = GetProcAddress(h_original, "EnableWindow");
        p_EndDeferWindowPos = GetProcAddress(h_original, "EndDeferWindowPos");
        p_EndDialog = GetProcAddress(h_original, "EndDialog");
        p_EndMenu = GetProcAddress(h_original, "EndMenu");
        p_EndPaint = GetProcAddress(h_original, "EndPaint");
        p_EndTask = GetProcAddress(h_original, "EndTask");
        p_EnterReaderModeHelper = GetProcAddress(h_original, "EnterReaderModeHelper");
        p_EnumChildWindows = GetProcAddress(h_original, "EnumChildWindows");
        p_EnumClipboardFormats = GetProcAddress(h_original, "EnumClipboardFormats");
        p_EnumDesktopWindows = GetProcAddress(h_original, "EnumDesktopWindows");
        p_EnumDesktopsA = GetProcAddress(h_original, "EnumDesktopsA");
        p_EnumDesktopsW = GetProcAddress(h_original, "EnumDesktopsW");
        p_EnumDisplayDevicesA = GetProcAddress(h_original, "EnumDisplayDevicesA");
        p_EnumDisplayDevicesW = GetProcAddress(h_original, "EnumDisplayDevicesW");
        p_EnumDisplayMonitors = GetProcAddress(h_original, "EnumDisplayMonitors");
        p_EnumDisplaySettingsA = GetProcAddress(h_original, "EnumDisplaySettingsA");
        p_EnumDisplaySettingsExA = GetProcAddress(h_original, "EnumDisplaySettingsExA");
        p_EnumDisplaySettingsExW = GetProcAddress(h_original, "EnumDisplaySettingsExW");
        p_EnumDisplaySettingsW = GetProcAddress(h_original, "EnumDisplaySettingsW");
        p_EnumPropsA = GetProcAddress(h_original, "EnumPropsA");
        p_EnumPropsExA = GetProcAddress(h_original, "EnumPropsExA");
        p_EnumPropsExW = GetProcAddress(h_original, "EnumPropsExW");
        p_EnumPropsW = GetProcAddress(h_original, "EnumPropsW");
        p_EnumThreadWindows = GetProcAddress(h_original, "EnumThreadWindows");
        p_EnumWindowStationsA = GetProcAddress(h_original, "EnumWindowStationsA");
        p_EnumWindowStationsW = GetProcAddress(h_original, "EnumWindowStationsW");
        p_EnumWindows = GetProcAddress(h_original, "EnumWindows");
        p_EqualRect = GetProcAddress(h_original, "EqualRect");
        p_ExcludeUpdateRgn = GetProcAddress(h_original, "ExcludeUpdateRgn");
        p_ExitWindowsEx = GetProcAddress(h_original, "ExitWindowsEx");
        p_FillRect = GetProcAddress(h_original, "FillRect");
        p_FindWindowA = GetProcAddress(h_original, "FindWindowA");
        p_FindWindowExA = GetProcAddress(h_original, "FindWindowExA");
        p_FindWindowExW = GetProcAddress(h_original, "FindWindowExW");
        p_FindWindowW = GetProcAddress(h_original, "FindWindowW");
        p_FlashWindow = GetProcAddress(h_original, "FlashWindow");
        p_FlashWindowEx = GetProcAddress(h_original, "FlashWindowEx");
        p_FrameRect = GetProcAddress(h_original, "FrameRect");
        p_FreeDDElParam = GetProcAddress(h_original, "FreeDDElParam");
        p_FrostCrashedWindow = GetProcAddress(h_original, "FrostCrashedWindow");
        p_GetActiveWindow = GetProcAddress(h_original, "GetActiveWindow");
        p_GetAltTabInfo = GetProcAddress(h_original, "GetAltTabInfo");
        p_GetAltTabInfoA = GetProcAddress(h_original, "GetAltTabInfoA");
        p_GetAltTabInfoW = GetProcAddress(h_original, "GetAltTabInfoW");
        p_GetAncestor = GetProcAddress(h_original, "GetAncestor");
        p_GetAppCompatFlags2 = GetProcAddress(h_original, "GetAppCompatFlags2");
        p_GetAppCompatFlags = GetProcAddress(h_original, "GetAppCompatFlags");
        p_GetAsyncKeyState = GetProcAddress(h_original, "GetAsyncKeyState");
        p_GetCapture = GetProcAddress(h_original, "GetCapture");
        p_GetCaretBlinkTime = GetProcAddress(h_original, "GetCaretBlinkTime");
        p_GetCaretPos = GetProcAddress(h_original, "GetCaretPos");
        p_GetClassInfoA = GetProcAddress(h_original, "GetClassInfoA");
        p_GetClassInfoExA = GetProcAddress(h_original, "GetClassInfoExA");
        p_GetClassInfoExW = GetProcAddress(h_original, "GetClassInfoExW");
        p_GetClassInfoW = GetProcAddress(h_original, "GetClassInfoW");
        p_GetClassLongA = GetProcAddress(h_original, "GetClassLongA");
        p_GetClassLongW = GetProcAddress(h_original, "GetClassLongW");
        p_GetClassNameA = GetProcAddress(h_original, "GetClassNameA");
        p_GetClassNameW = GetProcAddress(h_original, "GetClassNameW");
        p_GetClassWord = GetProcAddress(h_original, "GetClassWord");
        p_GetClientRect = GetProcAddress(h_original, "GetClientRect");
        p_GetClipCursor = GetProcAddress(h_original, "GetClipCursor");
        p_GetClipboardData = GetProcAddress(h_original, "GetClipboardData");
        p_GetClipboardFormatNameA = GetProcAddress(h_original, "GetClipboardFormatNameA");
        p_GetClipboardFormatNameW = GetProcAddress(h_original, "GetClipboardFormatNameW");
        p_GetClipboardOwner = GetProcAddress(h_original, "GetClipboardOwner");
        p_GetClipboardSequenceNumber = GetProcAddress(h_original, "GetClipboardSequenceNumber");
        p_GetClipboardViewer = GetProcAddress(h_original, "GetClipboardViewer");
        p_GetComboBoxInfo = GetProcAddress(h_original, "GetComboBoxInfo");
        p_GetCursor = GetProcAddress(h_original, "GetCursor");
        p_GetCursorFrameInfo = GetProcAddress(h_original, "GetCursorFrameInfo");
        p_GetCursorInfo = GetProcAddress(h_original, "GetCursorInfo");
        p_GetCursorPos = GetProcAddress(h_original, "GetCursorPos");
        p_GetDC = GetProcAddress(h_original, "GetDC");
        p_GetDCEx = GetProcAddress(h_original, "GetDCEx");
        p_GetDesktopWindow = GetProcAddress(h_original, "GetDesktopWindow");
        p_GetDialogBaseUnits = GetProcAddress(h_original, "GetDialogBaseUnits");
        p_GetDlgCtrlID = GetProcAddress(h_original, "GetDlgCtrlID");
        p_GetDlgItem = GetProcAddress(h_original, "GetDlgItem");
        p_GetDlgItemInt = GetProcAddress(h_original, "GetDlgItemInt");
        p_GetDlgItemTextA = GetProcAddress(h_original, "GetDlgItemTextA");
        p_GetDlgItemTextW = GetProcAddress(h_original, "GetDlgItemTextW");
        p_GetDoubleClickTime = GetProcAddress(h_original, "GetDoubleClickTime");
        p_GetFocus = GetProcAddress(h_original, "GetFocus");
        p_GetForegroundWindow = GetProcAddress(h_original, "GetForegroundWindow");
        p_GetGUIThreadInfo = GetProcAddress(h_original, "GetGUIThreadInfo");
        p_GetGuiResources = GetProcAddress(h_original, "GetGuiResources");
        p_GetIconInfo = GetProcAddress(h_original, "GetIconInfo");
        p_GetIconInfoExA = GetProcAddress(h_original, "GetIconInfoExA");
        p_GetIconInfoExW = GetProcAddress(h_original, "GetIconInfoExW");
        p_GetInputDesktop = GetProcAddress(h_original, "GetInputDesktop");
        p_GetInputState = GetProcAddress(h_original, "GetInputState");
        p_GetInternalWindowPos = GetProcAddress(h_original, "GetInternalWindowPos");
        p_GetKBCodePage = GetProcAddress(h_original, "GetKBCodePage");
        p_GetKeyNameTextA = GetProcAddress(h_original, "GetKeyNameTextA");
        p_GetKeyNameTextW = GetProcAddress(h_original, "GetKeyNameTextW");
        p_GetKeyState = GetProcAddress(h_original, "GetKeyState");
        p_GetKeyboardLayout = GetProcAddress(h_original, "GetKeyboardLayout");
        p_GetKeyboardLayoutList = GetProcAddress(h_original, "GetKeyboardLayoutList");
        p_GetKeyboardLayoutNameA = GetProcAddress(h_original, "GetKeyboardLayoutNameA");
        p_GetKeyboardLayoutNameW = GetProcAddress(h_original, "GetKeyboardLayoutNameW");
        p_GetKeyboardState = GetProcAddress(h_original, "GetKeyboardState");
        p_GetKeyboardType = GetProcAddress(h_original, "GetKeyboardType");
        p_GetLastActivePopup = GetProcAddress(h_original, "GetLastActivePopup");
        p_GetLastInputInfo = GetProcAddress(h_original, "GetLastInputInfo");
        p_GetLayeredWindowAttributes = GetProcAddress(h_original, "GetLayeredWindowAttributes");
        p_GetListBoxInfo = GetProcAddress(h_original, "GetListBoxInfo");
        p_GetMenu = GetProcAddress(h_original, "GetMenu");
        p_GetMenuBarInfo = GetProcAddress(h_original, "GetMenuBarInfo");
        p_GetMenuCheckMarkDimensions = GetProcAddress(h_original, "GetMenuCheckMarkDimensions");
        p_GetMenuContextHelpId = GetProcAddress(h_original, "GetMenuContextHelpId");
        p_GetMenuDefaultItem = GetProcAddress(h_original, "GetMenuDefaultItem");
        p_GetMenuInfo = GetProcAddress(h_original, "GetMenuInfo");
        p_GetMenuItemCount = GetProcAddress(h_original, "GetMenuItemCount");
        p_GetMenuItemID = GetProcAddress(h_original, "GetMenuItemID");
        p_GetMenuItemInfoA = GetProcAddress(h_original, "GetMenuItemInfoA");
        p_GetMenuItemInfoW = GetProcAddress(h_original, "GetMenuItemInfoW");
        p_GetMenuItemRect = GetProcAddress(h_original, "GetMenuItemRect");
        p_GetMenuState = GetProcAddress(h_original, "GetMenuState");
        p_GetMenuStringA = GetProcAddress(h_original, "GetMenuStringA");
        p_GetMenuStringW = GetProcAddress(h_original, "GetMenuStringW");
        p_GetMessageA = GetProcAddress(h_original, "GetMessageA");
        p_GetMessageExtraInfo = GetProcAddress(h_original, "GetMessageExtraInfo");
        p_GetMessagePos = GetProcAddress(h_original, "GetMessagePos");
        p_GetMessageTime = GetProcAddress(h_original, "GetMessageTime");
        p_GetMessageW = GetProcAddress(h_original, "GetMessageW");
        p_GetMonitorInfoA = GetProcAddress(h_original, "GetMonitorInfoA");
        p_GetMonitorInfoW = GetProcAddress(h_original, "GetMonitorInfoW");
        p_GetMouseMovePointsEx = GetProcAddress(h_original, "GetMouseMovePointsEx");
        p_GetNextDlgGroupItem = GetProcAddress(h_original, "GetNextDlgGroupItem");
        p_GetNextDlgTabItem = GetProcAddress(h_original, "GetNextDlgTabItem");
        p_GetOpenClipboardWindow = GetProcAddress(h_original, "GetOpenClipboardWindow");
        p_GetParent = GetProcAddress(h_original, "GetParent");
        p_GetPhysicalCursorPos = GetProcAddress(h_original, "GetPhysicalCursorPos");
        p_GetPriorityClipboardFormat = GetProcAddress(h_original, "GetPriorityClipboardFormat");
        p_GetProcessDefaultLayout = GetProcAddress(h_original, "GetProcessDefaultLayout");
        p_GetProcessWindowStation = GetProcAddress(h_original, "GetProcessWindowStation");
        p_GetProgmanWindow = GetProcAddress(h_original, "GetProgmanWindow");
        p_GetPropA = GetProcAddress(h_original, "GetPropA");
        p_GetPropW = GetProcAddress(h_original, "GetPropW");
        p_GetQueueStatus = GetProcAddress(h_original, "GetQueueStatus");
        p_GetRawInputBuffer = GetProcAddress(h_original, "GetRawInputBuffer");
        p_GetRawInputData = GetProcAddress(h_original, "GetRawInputData");
        p_GetRawInputDeviceInfoA = GetProcAddress(h_original, "GetRawInputDeviceInfoA");
        p_GetRawInputDeviceInfoW = GetProcAddress(h_original, "GetRawInputDeviceInfoW");
        p_GetRawInputDeviceList = GetProcAddress(h_original, "GetRawInputDeviceList");
        p_GetReasonTitleFromReasonCode = GetProcAddress(h_original, "GetReasonTitleFromReasonCode");
        p_GetRegisteredRawInputDevices = GetProcAddress(h_original, "GetRegisteredRawInputDevices");
        p_GetScrollBarInfo = GetProcAddress(h_original, "GetScrollBarInfo");
        p_GetScrollInfo = GetProcAddress(h_original, "GetScrollInfo");
        p_GetScrollPos = GetProcAddress(h_original, "GetScrollPos");
        p_GetScrollRange = GetProcAddress(h_original, "GetScrollRange");
        p_GetSendMessageReceiver = GetProcAddress(h_original, "GetSendMessageReceiver");
        p_GetShellWindow = GetProcAddress(h_original, "GetShellWindow");
        p_GetSubMenu = GetProcAddress(h_original, "GetSubMenu");
        p_GetSysColor = GetProcAddress(h_original, "GetSysColor");
        p_GetSysColorBrush = GetProcAddress(h_original, "GetSysColorBrush");
        p_GetSystemMenu = GetProcAddress(h_original, "GetSystemMenu");
        p_GetSystemMetrics = GetProcAddress(h_original, "GetSystemMetrics");
        p_GetTabbedTextExtentA = GetProcAddress(h_original, "GetTabbedTextExtentA");
        p_GetTabbedTextExtentW = GetProcAddress(h_original, "GetTabbedTextExtentW");
        p_GetTaskmanWindow = GetProcAddress(h_original, "GetTaskmanWindow");
        p_GetThreadDesktop = GetProcAddress(h_original, "GetThreadDesktop");
        p_GetTitleBarInfo = GetProcAddress(h_original, "GetTitleBarInfo");
        p_GetTopWindow = GetProcAddress(h_original, "GetTopWindow");
        p_GetUpdateRect = GetProcAddress(h_original, "GetUpdateRect");
        p_GetUpdateRgn = GetProcAddress(h_original, "GetUpdateRgn");
        p_GetUpdatedClipboardFormats = GetProcAddress(h_original, "GetUpdatedClipboardFormats");
        p_GetUserObjectInformationA = GetProcAddress(h_original, "GetUserObjectInformationA");
        p_GetUserObjectInformationW = GetProcAddress(h_original, "GetUserObjectInformationW");
        p_GetUserObjectSecurity = GetProcAddress(h_original, "GetUserObjectSecurity");
        p_GetWinStationInfo = GetProcAddress(h_original, "GetWinStationInfo");
        p_GetWindow = GetProcAddress(h_original, "GetWindow");
        p_GetWindowContextHelpId = GetProcAddress(h_original, "GetWindowContextHelpId");
        p_GetWindowDC = GetProcAddress(h_original, "GetWindowDC");
        p_GetWindowInfo = GetProcAddress(h_original, "GetWindowInfo");
        p_GetWindowLongA = GetProcAddress(h_original, "GetWindowLongA");
        p_GetWindowLongW = GetProcAddress(h_original, "GetWindowLongW");
        p_GetWindowMinimizeRect = GetProcAddress(h_original, "GetWindowMinimizeRect");
        p_GetWindowModuleFileName = GetProcAddress(h_original, "GetWindowModuleFileName");
        p_GetWindowModuleFileNameA = GetProcAddress(h_original, "GetWindowModuleFileNameA");
        p_GetWindowModuleFileNameW = GetProcAddress(h_original, "GetWindowModuleFileNameW");
        p_GetWindowPlacement = GetProcAddress(h_original, "GetWindowPlacement");
        p_GetWindowRect = GetProcAddress(h_original, "GetWindowRect");
        p_GetWindowRgn = GetProcAddress(h_original, "GetWindowRgn");
        p_GetWindowRgnBox = GetProcAddress(h_original, "GetWindowRgnBox");
        p_GetWindowRgnEx = GetProcAddress(h_original, "GetWindowRgnEx");
        p_GetWindowTextA = GetProcAddress(h_original, "GetWindowTextA");
        p_GetWindowTextLengthA = GetProcAddress(h_original, "GetWindowTextLengthA");
        p_GetWindowTextLengthW = GetProcAddress(h_original, "GetWindowTextLengthW");
        p_GetWindowTextW = GetProcAddress(h_original, "GetWindowTextW");
        p_GetWindowThreadProcessId = GetProcAddress(h_original, "GetWindowThreadProcessId");
        p_GetWindowWord = GetProcAddress(h_original, "GetWindowWord");
        p_GhostWindowFromHungWindow = GetProcAddress(h_original, "GhostWindowFromHungWindow");
        p_GrayStringA = GetProcAddress(h_original, "GrayStringA");
        p_GrayStringW = GetProcAddress(h_original, "GrayStringW");
        p_HideCaret = GetProcAddress(h_original, "HideCaret");
        p_HiliteMenuItem = GetProcAddress(h_original, "HiliteMenuItem");
        p_HungWindowFromGhostWindow = GetProcAddress(h_original, "HungWindowFromGhostWindow");
        p_IMPGetIMEA = GetProcAddress(h_original, "IMPGetIMEA");
        p_IMPGetIMEW = GetProcAddress(h_original, "IMPGetIMEW");
        p_IMPQueryIMEA = GetProcAddress(h_original, "IMPQueryIMEA");
        p_IMPQueryIMEW = GetProcAddress(h_original, "IMPQueryIMEW");
        p_IMPSetIMEA = GetProcAddress(h_original, "IMPSetIMEA");
        p_IMPSetIMEW = GetProcAddress(h_original, "IMPSetIMEW");
        p_ImpersonateDdeClientWindow = GetProcAddress(h_original, "ImpersonateDdeClientWindow");
        p_InSendMessage = GetProcAddress(h_original, "InSendMessage");
        p_InSendMessageEx = GetProcAddress(h_original, "InSendMessageEx");
        p_InflateRect = GetProcAddress(h_original, "InflateRect");
        p_InitializeLpkHooks = GetProcAddress(h_original, "InitializeLpkHooks");
        p_InsertMenuA = GetProcAddress(h_original, "InsertMenuA");
        p_InsertMenuItemA = GetProcAddress(h_original, "InsertMenuItemA");
        p_InsertMenuItemW = GetProcAddress(h_original, "InsertMenuItemW");
        p_InsertMenuW = GetProcAddress(h_original, "InsertMenuW");
        p_InternalGetWindowIcon = GetProcAddress(h_original, "InternalGetWindowIcon");
        p_InternalGetWindowText = GetProcAddress(h_original, "InternalGetWindowText");
        p_IntersectRect = GetProcAddress(h_original, "IntersectRect");
        p_InvalidateRect = GetProcAddress(h_original, "InvalidateRect");
        p_InvalidateRgn = GetProcAddress(h_original, "InvalidateRgn");
        p_InvertRect = GetProcAddress(h_original, "InvertRect");
        p_IsCharAlphaA = GetProcAddress(h_original, "IsCharAlphaA");
        p_IsCharAlphaNumericA = GetProcAddress(h_original, "IsCharAlphaNumericA");
        p_IsCharAlphaNumericW = GetProcAddress(h_original, "IsCharAlphaNumericW");
        p_IsCharAlphaW = GetProcAddress(h_original, "IsCharAlphaW");
        p_IsCharLowerA = GetProcAddress(h_original, "IsCharLowerA");
        p_IsCharLowerW = GetProcAddress(h_original, "IsCharLowerW");
        p_IsCharUpperA = GetProcAddress(h_original, "IsCharUpperA");
        p_IsCharUpperW = GetProcAddress(h_original, "IsCharUpperW");
        p_IsChild = GetProcAddress(h_original, "IsChild");
        p_IsClipboardFormatAvailable = GetProcAddress(h_original, "IsClipboardFormatAvailable");
        p_IsDialogMessage = GetProcAddress(h_original, "IsDialogMessage");
        p_IsDialogMessageA = GetProcAddress(h_original, "IsDialogMessageA");
        p_IsDialogMessageW = GetProcAddress(h_original, "IsDialogMessageW");
        p_IsDlgButtonChecked = GetProcAddress(h_original, "IsDlgButtonChecked");
        p_IsGUIThread = GetProcAddress(h_original, "IsGUIThread");
        p_IsHungAppWindow = GetProcAddress(h_original, "IsHungAppWindow");
        p_IsIconic = GetProcAddress(h_original, "IsIconic");
        p_IsMenu = GetProcAddress(h_original, "IsMenu");
        p_IsProcessDPIAware = GetProcAddress(h_original, "IsProcessDPIAware");
        p_IsRectEmpty = GetProcAddress(h_original, "IsRectEmpty");
        p_IsSETEnabled = GetProcAddress(h_original, "IsSETEnabled");
        p_IsServerSideWindow = GetProcAddress(h_original, "IsServerSideWindow");
        p_IsThreadDesktopComposited = GetProcAddress(h_original, "IsThreadDesktopComposited");
        p_IsWinEventHookInstalled = GetProcAddress(h_original, "IsWinEventHookInstalled");
        p_IsWindow = GetProcAddress(h_original, "IsWindow");
        p_IsWindowEnabled = GetProcAddress(h_original, "IsWindowEnabled");
        p_IsWindowInDestroy = GetProcAddress(h_original, "IsWindowInDestroy");
        p_IsWindowRedirectedForPrint = GetProcAddress(h_original, "IsWindowRedirectedForPrint");
        p_IsWindowUnicode = GetProcAddress(h_original, "IsWindowUnicode");
        p_IsWindowVisible = GetProcAddress(h_original, "IsWindowVisible");
        p_IsWow64Message = GetProcAddress(h_original, "IsWow64Message");
        p_IsZoomed = GetProcAddress(h_original, "IsZoomed");
        p_KillTimer = GetProcAddress(h_original, "KillTimer");
        p_LoadAcceleratorsA = GetProcAddress(h_original, "LoadAcceleratorsA");
        p_LoadAcceleratorsW = GetProcAddress(h_original, "LoadAcceleratorsW");
        p_LoadBitmapA = GetProcAddress(h_original, "LoadBitmapA");
        p_LoadBitmapW = GetProcAddress(h_original, "LoadBitmapW");
        p_LoadCursorA = GetProcAddress(h_original, "LoadCursorA");
        p_LoadCursorFromFileA = GetProcAddress(h_original, "LoadCursorFromFileA");
        p_LoadCursorFromFileW = GetProcAddress(h_original, "LoadCursorFromFileW");
        p_LoadCursorW = GetProcAddress(h_original, "LoadCursorW");
        p_LoadIconA = GetProcAddress(h_original, "LoadIconA");
        p_LoadIconW = GetProcAddress(h_original, "LoadIconW");
        p_LoadImageA = GetProcAddress(h_original, "LoadImageA");
        p_LoadImageW = GetProcAddress(h_original, "LoadImageW");
        p_LoadKeyboardLayoutA = GetProcAddress(h_original, "LoadKeyboardLayoutA");
        p_LoadKeyboardLayoutEx = GetProcAddress(h_original, "LoadKeyboardLayoutEx");
        p_LoadKeyboardLayoutW = GetProcAddress(h_original, "LoadKeyboardLayoutW");
        p_LoadLocalFonts = GetProcAddress(h_original, "LoadLocalFonts");
        p_LoadMenuA = GetProcAddress(h_original, "LoadMenuA");
        p_LoadMenuIndirectA = GetProcAddress(h_original, "LoadMenuIndirectA");
        p_LoadMenuIndirectW = GetProcAddress(h_original, "LoadMenuIndirectW");
        p_LoadMenuW = GetProcAddress(h_original, "LoadMenuW");
        p_LoadRemoteFonts = GetProcAddress(h_original, "LoadRemoteFonts");
        p_LoadStringA = GetProcAddress(h_original, "LoadStringA");
        p_LoadStringW = GetProcAddress(h_original, "LoadStringW");
        p_LockSetForegroundWindow = GetProcAddress(h_original, "LockSetForegroundWindow");
        p_LockWindowStation = GetProcAddress(h_original, "LockWindowStation");
        p_LockWindowUpdate = GetProcAddress(h_original, "LockWindowUpdate");
        p_LockWorkStation = GetProcAddress(h_original, "LockWorkStation");
        p_LogicalToPhysicalPoint = GetProcAddress(h_original, "LogicalToPhysicalPoint");
        p_LookupIconIdFromDirectory = GetProcAddress(h_original, "LookupIconIdFromDirectory");
        p_LookupIconIdFromDirectoryEx = GetProcAddress(h_original, "LookupIconIdFromDirectoryEx");
        p_MBToWCSEx = GetProcAddress(h_original, "MBToWCSEx");
        p_MB_GetString = GetProcAddress(h_original, "MB_GetString");
        p_MapDialogRect = GetProcAddress(h_original, "MapDialogRect");
        p_MapVirtualKeyA = GetProcAddress(h_original, "MapVirtualKeyA");
        p_MapVirtualKeyExA = GetProcAddress(h_original, "MapVirtualKeyExA");
        p_MapVirtualKeyExW = GetProcAddress(h_original, "MapVirtualKeyExW");
        p_MapVirtualKeyW = GetProcAddress(h_original, "MapVirtualKeyW");
        p_MapWindowPoints = GetProcAddress(h_original, "MapWindowPoints");
        p_MenuItemFromPoint = GetProcAddress(h_original, "MenuItemFromPoint");
        p_MenuWindowProcA = GetProcAddress(h_original, "MenuWindowProcA");
        p_MenuWindowProcW = GetProcAddress(h_original, "MenuWindowProcW");
        p_MessageBeep = GetProcAddress(h_original, "MessageBeep");
        p_MessageBoxA = GetProcAddress(h_original, "MessageBoxA");
        p_MessageBoxExA = GetProcAddress(h_original, "MessageBoxExA");
        p_MessageBoxExW = GetProcAddress(h_original, "MessageBoxExW");
        p_MessageBoxIndirectA = GetProcAddress(h_original, "MessageBoxIndirectA");
        p_MessageBoxIndirectW = GetProcAddress(h_original, "MessageBoxIndirectW");
        p_MessageBoxTimeoutA = GetProcAddress(h_original, "MessageBoxTimeoutA");
        p_MessageBoxTimeoutW = GetProcAddress(h_original, "MessageBoxTimeoutW");
        p_MessageBoxW = GetProcAddress(h_original, "MessageBoxW");
        p_ModifyMenuA = GetProcAddress(h_original, "ModifyMenuA");
        p_ModifyMenuW = GetProcAddress(h_original, "ModifyMenuW");
        p_MonitorFromPoint = GetProcAddress(h_original, "MonitorFromPoint");
        p_MonitorFromRect = GetProcAddress(h_original, "MonitorFromRect");
        p_MonitorFromWindow = GetProcAddress(h_original, "MonitorFromWindow");
        p_MoveWindow = GetProcAddress(h_original, "MoveWindow");
        p_MsgWaitForMultipleObjects = GetProcAddress(h_original, "MsgWaitForMultipleObjects");
        p_MsgWaitForMultipleObjectsEx = GetProcAddress(h_original, "MsgWaitForMultipleObjectsEx");
        p_NotifyWinEvent = GetProcAddress(h_original, "NotifyWinEvent");
        p_OemKeyScan = GetProcAddress(h_original, "OemKeyScan");
        p_OemToCharA = GetProcAddress(h_original, "OemToCharA");
        p_OemToCharBuffA = GetProcAddress(h_original, "OemToCharBuffA");
        p_OemToCharBuffW = GetProcAddress(h_original, "OemToCharBuffW");
        p_OemToCharW = GetProcAddress(h_original, "OemToCharW");
        p_OffsetRect = GetProcAddress(h_original, "OffsetRect");
        p_OpenClipboard = GetProcAddress(h_original, "OpenClipboard");
        p_OpenDesktopA = GetProcAddress(h_original, "OpenDesktopA");
        p_OpenDesktopW = GetProcAddress(h_original, "OpenDesktopW");
        p_OpenIcon = GetProcAddress(h_original, "OpenIcon");
        p_OpenInputDesktop = GetProcAddress(h_original, "OpenInputDesktop");
        p_OpenThreadDesktop = GetProcAddress(h_original, "OpenThreadDesktop");
        p_OpenWindowStationA = GetProcAddress(h_original, "OpenWindowStationA");
        p_OpenWindowStationW = GetProcAddress(h_original, "OpenWindowStationW");
        p_PackDDElParam = GetProcAddress(h_original, "PackDDElParam");
        p_PaintDesktop = GetProcAddress(h_original, "PaintDesktop");
        p_PaintMenuBar = GetProcAddress(h_original, "PaintMenuBar");
        p_PaintMonitor = GetProcAddress(h_original, "PaintMonitor");
        p_PeekMessageA = GetProcAddress(h_original, "PeekMessageA");
        p_PeekMessageW = GetProcAddress(h_original, "PeekMessageW");
        p_PhysicalToLogicalPoint = GetProcAddress(h_original, "PhysicalToLogicalPoint");
        p_PostMessageA = GetProcAddress(h_original, "PostMessageA");
        p_PostMessageW = GetProcAddress(h_original, "PostMessageW");
        p_PostQuitMessage = GetProcAddress(h_original, "PostQuitMessage");
        p_PostThreadMessageA = GetProcAddress(h_original, "PostThreadMessageA");
        p_PostThreadMessageW = GetProcAddress(h_original, "PostThreadMessageW");
        p_PrintWindow = GetProcAddress(h_original, "PrintWindow");
        p_PrivateExtractIconExA = GetProcAddress(h_original, "PrivateExtractIconExA");
        p_PrivateExtractIconExW = GetProcAddress(h_original, "PrivateExtractIconExW");
        p_PrivateExtractIconsA = GetProcAddress(h_original, "PrivateExtractIconsA");
        p_PrivateExtractIconsW = GetProcAddress(h_original, "PrivateExtractIconsW");
        p_PrivateRegisterICSProc = GetProcAddress(h_original, "PrivateRegisterICSProc");
        p_PtInRect = GetProcAddress(h_original, "PtInRect");
        p_QuerySendMessage = GetProcAddress(h_original, "QuerySendMessage");
        p_RealChildWindowFromPoint = GetProcAddress(h_original, "RealChildWindowFromPoint");
        p_RealGetWindowClass = GetProcAddress(h_original, "RealGetWindowClass");
        p_RealGetWindowClassA = GetProcAddress(h_original, "RealGetWindowClassA");
        p_RealGetWindowClassW = GetProcAddress(h_original, "RealGetWindowClassW");
        p_ReasonCodeNeedsBugID = GetProcAddress(h_original, "ReasonCodeNeedsBugID");
        p_ReasonCodeNeedsComment = GetProcAddress(h_original, "ReasonCodeNeedsComment");
        p_RecordShutdownReason = GetProcAddress(h_original, "RecordShutdownReason");
        p_RedrawWindow = GetProcAddress(h_original, "RedrawWindow");
        p_RegisterClassA = GetProcAddress(h_original, "RegisterClassA");
        p_RegisterClassExA = GetProcAddress(h_original, "RegisterClassExA");
        p_RegisterClassExW = GetProcAddress(h_original, "RegisterClassExW");
        p_RegisterClassW = GetProcAddress(h_original, "RegisterClassW");
        p_RegisterClipboardFormatA = GetProcAddress(h_original, "RegisterClipboardFormatA");
        p_RegisterClipboardFormatW = GetProcAddress(h_original, "RegisterClipboardFormatW");
        p_RegisterDeviceNotificationA = GetProcAddress(h_original, "RegisterDeviceNotificationA");
        p_RegisterDeviceNotificationW = GetProcAddress(h_original, "RegisterDeviceNotificationW");
        p_RegisterErrorReportingDialog = GetProcAddress(h_original, "RegisterErrorReportingDialog");
        p_RegisterFrostWindow = GetProcAddress(h_original, "RegisterFrostWindow");
        p_RegisterGhostWindow = GetProcAddress(h_original, "RegisterGhostWindow");
        p_RegisterHotKey = GetProcAddress(h_original, "RegisterHotKey");
        p_RegisterLogonProcess = GetProcAddress(h_original, "RegisterLogonProcess");
        p_RegisterMessagePumpHook = GetProcAddress(h_original, "RegisterMessagePumpHook");
        p_RegisterPowerSettingNotification = GetProcAddress(h_original, "RegisterPowerSettingNotification");
        p_RegisterRawInputDevices = GetProcAddress(h_original, "RegisterRawInputDevices");
        p_RegisterServicesProcess = GetProcAddress(h_original, "RegisterServicesProcess");
        p_RegisterSessionPort = GetProcAddress(h_original, "RegisterSessionPort");
        p_RegisterShellHookWindow = GetProcAddress(h_original, "RegisterShellHookWindow");
        p_RegisterSystemThread = GetProcAddress(h_original, "RegisterSystemThread");
        p_RegisterTasklist = GetProcAddress(h_original, "RegisterTasklist");
        p_RegisterUserApiHook = GetProcAddress(h_original, "RegisterUserApiHook");
        p_RegisterWindowMessageA = GetProcAddress(h_original, "RegisterWindowMessageA");
        p_RegisterWindowMessageW = GetProcAddress(h_original, "RegisterWindowMessageW");
        p_ReleaseCapture = GetProcAddress(h_original, "ReleaseCapture");
        p_ReleaseDC = GetProcAddress(h_original, "ReleaseDC");
        p_RemoveClipboardFormatListener = GetProcAddress(h_original, "RemoveClipboardFormatListener");
        p_RemoveMenu = GetProcAddress(h_original, "RemoveMenu");
        p_RemovePropA = GetProcAddress(h_original, "RemovePropA");
        p_RemovePropW = GetProcAddress(h_original, "RemovePropW");
        p_ReplyMessage = GetProcAddress(h_original, "ReplyMessage");
        p_ResolveDesktopForWOW = GetProcAddress(h_original, "ResolveDesktopForWOW");
        p_ReuseDDElParam = GetProcAddress(h_original, "ReuseDDElParam");
        p_ScreenToClient = GetProcAddress(h_original, "ScreenToClient");
        p_ScrollChildren = GetProcAddress(h_original, "ScrollChildren");
        p_ScrollDC = GetProcAddress(h_original, "ScrollDC");
        p_ScrollWindow = GetProcAddress(h_original, "ScrollWindow");
        p_ScrollWindowEx = GetProcAddress(h_original, "ScrollWindowEx");
        p_SendDlgItemMessageA = GetProcAddress(h_original, "SendDlgItemMessageA");
        p_SendDlgItemMessageW = GetProcAddress(h_original, "SendDlgItemMessageW");
        p_SendIMEMessageExA = GetProcAddress(h_original, "SendIMEMessageExA");
        p_SendIMEMessageExW = GetProcAddress(h_original, "SendIMEMessageExW");
        p_SendInput = GetProcAddress(h_original, "SendInput");
        p_SendMessageA = GetProcAddress(h_original, "SendMessageA");
        p_SendMessageCallbackA = GetProcAddress(h_original, "SendMessageCallbackA");
        p_SendMessageCallbackW = GetProcAddress(h_original, "SendMessageCallbackW");
        p_SendMessageTimeoutA = GetProcAddress(h_original, "SendMessageTimeoutA");
        p_SendMessageTimeoutW = GetProcAddress(h_original, "SendMessageTimeoutW");
        p_SendMessageW = GetProcAddress(h_original, "SendMessageW");
        p_SendNotifyMessageA = GetProcAddress(h_original, "SendNotifyMessageA");
        p_SendNotifyMessageW = GetProcAddress(h_original, "SendNotifyMessageW");
        p_SetActiveWindow = GetProcAddress(h_original, "SetActiveWindow");
        p_SetCapture = GetProcAddress(h_original, "SetCapture");
        p_SetCaretBlinkTime = GetProcAddress(h_original, "SetCaretBlinkTime");
        p_SetCaretPos = GetProcAddress(h_original, "SetCaretPos");
        p_SetClassLongA = GetProcAddress(h_original, "SetClassLongA");
        p_SetClassLongW = GetProcAddress(h_original, "SetClassLongW");
        p_SetClassWord = GetProcAddress(h_original, "SetClassWord");
        p_SetClipboardData = GetProcAddress(h_original, "SetClipboardData");
        p_SetClipboardViewer = GetProcAddress(h_original, "SetClipboardViewer");
        p_SetConsoleReserveKeys = GetProcAddress(h_original, "SetConsoleReserveKeys");
        p_SetCursor = GetProcAddress(h_original, "SetCursor");
        p_SetCursorContents = GetProcAddress(h_original, "SetCursorContents");
        p_SetCursorPos = GetProcAddress(h_original, "SetCursorPos");
        p_SetDebugErrorLevel = GetProcAddress(h_original, "SetDebugErrorLevel");
        p_SetDeskWallpaper = GetProcAddress(h_original, "SetDeskWallpaper");
        p_SetDlgItemInt = GetProcAddress(h_original, "SetDlgItemInt");
        p_SetDlgItemTextA = GetProcAddress(h_original, "SetDlgItemTextA");
        p_SetDlgItemTextW = GetProcAddress(h_original, "SetDlgItemTextW");
        p_SetDoubleClickTime = GetProcAddress(h_original, "SetDoubleClickTime");
        p_SetFocus = GetProcAddress(h_original, "SetFocus");
        p_SetForegroundWindow = GetProcAddress(h_original, "SetForegroundWindow");
        p_SetInternalWindowPos = GetProcAddress(h_original, "SetInternalWindowPos");
        p_SetKeyboardState = GetProcAddress(h_original, "SetKeyboardState");
        p_SetLastErrorEx = GetProcAddress(h_original, "SetLastErrorEx");
        p_SetLayeredWindowAttributes = GetProcAddress(h_original, "SetLayeredWindowAttributes");
        p_SetMenu = GetProcAddress(h_original, "SetMenu");
        p_SetMenuContextHelpId = GetProcAddress(h_original, "SetMenuContextHelpId");
        p_SetMenuDefaultItem = GetProcAddress(h_original, "SetMenuDefaultItem");
        p_SetMenuInfo = GetProcAddress(h_original, "SetMenuInfo");
        p_SetMenuItemBitmaps = GetProcAddress(h_original, "SetMenuItemBitmaps");
        p_SetMenuItemInfoA = GetProcAddress(h_original, "SetMenuItemInfoA");
        p_SetMenuItemInfoW = GetProcAddress(h_original, "SetMenuItemInfoW");
        p_SetMessageExtraInfo = GetProcAddress(h_original, "SetMessageExtraInfo");
        p_SetMessageQueue = GetProcAddress(h_original, "SetMessageQueue");
        p_SetMirrorRendering = GetProcAddress(h_original, "SetMirrorRendering");
        p_SetParent = GetProcAddress(h_original, "SetParent");
        p_SetPhysicalCursorPos = GetProcAddress(h_original, "SetPhysicalCursorPos");
        p_SetProcessDPIAware = GetProcAddress(h_original, "SetProcessDPIAware");
        p_SetProcessDefaultLayout = GetProcAddress(h_original, "SetProcessDefaultLayout");
        p_SetProcessWindowStation = GetProcAddress(h_original, "SetProcessWindowStation");
        p_SetProgmanWindow = GetProcAddress(h_original, "SetProgmanWindow");
        p_SetPropA = GetProcAddress(h_original, "SetPropA");
        p_SetPropW = GetProcAddress(h_original, "SetPropW");
        p_SetRect = GetProcAddress(h_original, "SetRect");
        p_SetRectEmpty = GetProcAddress(h_original, "SetRectEmpty");
        p_SetScrollInfo = GetProcAddress(h_original, "SetScrollInfo");
        p_SetScrollPos = GetProcAddress(h_original, "SetScrollPos");
        p_SetScrollRange = GetProcAddress(h_original, "SetScrollRange");
        p_SetShellWindow = GetProcAddress(h_original, "SetShellWindow");
        p_SetShellWindowEx = GetProcAddress(h_original, "SetShellWindowEx");
        p_SetSysColors = GetProcAddress(h_original, "SetSysColors");
        p_SetSysColorsTemp = GetProcAddress(h_original, "SetSysColorsTemp");
        p_SetSystemCursor = GetProcAddress(h_original, "SetSystemCursor");
        p_SetSystemMenu = GetProcAddress(h_original, "SetSystemMenu");
        p_SetTaskmanWindow = GetProcAddress(h_original, "SetTaskmanWindow");
        p_SetThreadDesktop = GetProcAddress(h_original, "SetThreadDesktop");
        p_SetTimer = GetProcAddress(h_original, "SetTimer");
        p_SetUserObjectInformationA = GetProcAddress(h_original, "SetUserObjectInformationA");
        p_SetUserObjectInformationW = GetProcAddress(h_original, "SetUserObjectInformationW");
        p_SetUserObjectSecurity = GetProcAddress(h_original, "SetUserObjectSecurity");
        p_SetWinEventHook = GetProcAddress(h_original, "SetWinEventHook");
        p_SetWindowContextHelpId = GetProcAddress(h_original, "SetWindowContextHelpId");
        p_SetWindowLongA = GetProcAddress(h_original, "SetWindowLongA");
        p_SetWindowLongW = GetProcAddress(h_original, "SetWindowLongW");
        p_SetWindowPlacement = GetProcAddress(h_original, "SetWindowPlacement");
        p_SetWindowPos = GetProcAddress(h_original, "SetWindowPos");
        p_SetWindowRgn = GetProcAddress(h_original, "SetWindowRgn");
        p_SetWindowRgnEx = GetProcAddress(h_original, "SetWindowRgnEx");
        p_SetWindowStationUser = GetProcAddress(h_original, "SetWindowStationUser");
        p_SetWindowTextA = GetProcAddress(h_original, "SetWindowTextA");
        p_SetWindowTextW = GetProcAddress(h_original, "SetWindowTextW");
        p_SetWindowWord = GetProcAddress(h_original, "SetWindowWord");
        p_SetWindowsHookA = GetProcAddress(h_original, "SetWindowsHookA");
        p_SetWindowsHookExA = GetProcAddress(h_original, "SetWindowsHookExA");
        p_SetWindowsHookExW = GetProcAddress(h_original, "SetWindowsHookExW");
        p_SetWindowsHookW = GetProcAddress(h_original, "SetWindowsHookW");
        p_ShowCaret = GetProcAddress(h_original, "ShowCaret");
        p_ShowCursor = GetProcAddress(h_original, "ShowCursor");
        p_ShowOwnedPopups = GetProcAddress(h_original, "ShowOwnedPopups");
        p_ShowScrollBar = GetProcAddress(h_original, "ShowScrollBar");
        p_ShowStartGlass = GetProcAddress(h_original, "ShowStartGlass");
        p_ShowSystemCursor = GetProcAddress(h_original, "ShowSystemCursor");
        p_ShowWindow = GetProcAddress(h_original, "ShowWindow");
        p_ShowWindowAsync = GetProcAddress(h_original, "ShowWindowAsync");
        p_ShutdownBlockReasonCreate = GetProcAddress(h_original, "ShutdownBlockReasonCreate");
        p_ShutdownBlockReasonDestroy = GetProcAddress(h_original, "ShutdownBlockReasonDestroy");
        p_ShutdownBlockReasonQuery = GetProcAddress(h_original, "ShutdownBlockReasonQuery");
        p_SoftModalMessageBox = GetProcAddress(h_original, "SoftModalMessageBox");
        p_SoundSentry = GetProcAddress(h_original, "SoundSentry");
        p_SubtractRect = GetProcAddress(h_original, "SubtractRect");
        p_SwapMouseButton = GetProcAddress(h_original, "SwapMouseButton");
        p_SwitchDesktop = GetProcAddress(h_original, "SwitchDesktop");
        p_SwitchDesktopWithFade = GetProcAddress(h_original, "SwitchDesktopWithFade");
        p_SwitchToThisWindow = GetProcAddress(h_original, "SwitchToThisWindow");
        p_SystemParametersInfoA = GetProcAddress(h_original, "SystemParametersInfoA");
        p_SystemParametersInfoW = GetProcAddress(h_original, "SystemParametersInfoW");
        p_TabbedTextOutA = GetProcAddress(h_original, "TabbedTextOutA");
        p_TabbedTextOutW = GetProcAddress(h_original, "TabbedTextOutW");
        p_TileChildWindows = GetProcAddress(h_original, "TileChildWindows");
        p_TileWindows = GetProcAddress(h_original, "TileWindows");
        p_ToAscii = GetProcAddress(h_original, "ToAscii");
        p_ToAsciiEx = GetProcAddress(h_original, "ToAsciiEx");
        p_ToUnicode = GetProcAddress(h_original, "ToUnicode");
        p_ToUnicodeEx = GetProcAddress(h_original, "ToUnicodeEx");
        p_TrackMouseEvent = GetProcAddress(h_original, "TrackMouseEvent");
        p_TrackPopupMenu = GetProcAddress(h_original, "TrackPopupMenu");
        p_TrackPopupMenuEx = GetProcAddress(h_original, "TrackPopupMenuEx");
        p_TranslateAccelerator = GetProcAddress(h_original, "TranslateAccelerator");
        p_TranslateAcceleratorA = GetProcAddress(h_original, "TranslateAcceleratorA");
        p_TranslateAcceleratorW = GetProcAddress(h_original, "TranslateAcceleratorW");
        p_TranslateMDISysAccel = GetProcAddress(h_original, "TranslateMDISysAccel");
        p_TranslateMessage = GetProcAddress(h_original, "TranslateMessage");
        p_TranslateMessageEx = GetProcAddress(h_original, "TranslateMessageEx");
        p_UnhookWinEvent = GetProcAddress(h_original, "UnhookWinEvent");
        p_UnhookWindowsHook = GetProcAddress(h_original, "UnhookWindowsHook");
        p_UnhookWindowsHookEx = GetProcAddress(h_original, "UnhookWindowsHookEx");
        p_UnionRect = GetProcAddress(h_original, "UnionRect");
        p_UnloadKeyboardLayout = GetProcAddress(h_original, "UnloadKeyboardLayout");
        p_UnlockWindowStation = GetProcAddress(h_original, "UnlockWindowStation");
        p_UnpackDDElParam = GetProcAddress(h_original, "UnpackDDElParam");
        p_UnregisterClassA = GetProcAddress(h_original, "UnregisterClassA");
        p_UnregisterClassW = GetProcAddress(h_original, "UnregisterClassW");
        p_UnregisterDeviceNotification = GetProcAddress(h_original, "UnregisterDeviceNotification");
        p_UnregisterHotKey = GetProcAddress(h_original, "UnregisterHotKey");
        p_UnregisterMessagePumpHook = GetProcAddress(h_original, "UnregisterMessagePumpHook");
        p_UnregisterPowerSettingNotification = GetProcAddress(h_original, "UnregisterPowerSettingNotification");
        p_UnregisterSessionPort = GetProcAddress(h_original, "UnregisterSessionPort");
        p_UnregisterUserApiHook = GetProcAddress(h_original, "UnregisterUserApiHook");
        p_UpdateLayeredWindow = GetProcAddress(h_original, "UpdateLayeredWindow");
        p_UpdateLayeredWindowIndirect = GetProcAddress(h_original, "UpdateLayeredWindowIndirect");
        p_UpdatePerUserSystemParameters = GetProcAddress(h_original, "UpdatePerUserSystemParameters");
        p_UpdateWindow = GetProcAddress(h_original, "UpdateWindow");
        p_UpdateWindowTransform = GetProcAddress(h_original, "UpdateWindowTransform");
        p_User32InitializeImmEntryTable = GetProcAddress(h_original, "User32InitializeImmEntryTable");
        p_UserClientDllInitialize = GetProcAddress(h_original, "UserClientDllInitialize");
        p_UserHandleGrantAccess = GetProcAddress(h_original, "UserHandleGrantAccess");
        p_UserLpkPSMTextOut = GetProcAddress(h_original, "UserLpkPSMTextOut");
        p_UserLpkTabbedTextOut = GetProcAddress(h_original, "UserLpkTabbedTextOut");
        p_UserRealizePalette = GetProcAddress(h_original, "UserRealizePalette");
        p_UserRegisterWowHandlers = GetProcAddress(h_original, "UserRegisterWowHandlers");
        p_ValidateRect = GetProcAddress(h_original, "ValidateRect");
        p_ValidateRgn = GetProcAddress(h_original, "ValidateRgn");
        p_VkKeyScanA = GetProcAddress(h_original, "VkKeyScanA");
        p_VkKeyScanExA = GetProcAddress(h_original, "VkKeyScanExA");
        p_VkKeyScanExW = GetProcAddress(h_original, "VkKeyScanExW");
        p_VkKeyScanW = GetProcAddress(h_original, "VkKeyScanW");
        p_WCSToMBEx = GetProcAddress(h_original, "WCSToMBEx");
        p_WINNLSEnableIME = GetProcAddress(h_original, "WINNLSEnableIME");
        p_WINNLSGetEnableStatus = GetProcAddress(h_original, "WINNLSGetEnableStatus");
        p_WINNLSGetIMEHotkey = GetProcAddress(h_original, "WINNLSGetIMEHotkey");
        p_WaitForInputIdle = GetProcAddress(h_original, "WaitForInputIdle");
        p_WaitMessage = GetProcAddress(h_original, "WaitMessage");
        p_Win32PoolAllocationStats = GetProcAddress(h_original, "Win32PoolAllocationStats");
        p_WinHelpA = GetProcAddress(h_original, "WinHelpA");
        p_WinHelpW = GetProcAddress(h_original, "WinHelpW");
        p_WindowFromDC = GetProcAddress(h_original, "WindowFromDC");
        p_WindowFromPhysicalPoint = GetProcAddress(h_original, "WindowFromPhysicalPoint");
        p_WindowFromPoint = GetProcAddress(h_original, "WindowFromPoint");
        p__UserTestTokenForInteractive = GetProcAddress(h_original, "_UserTestTokenForInteractive");
        p_keybd_event = GetProcAddress(h_original, "keybd_event");
        p_mouse_event = GetProcAddress(h_original, "mouse_event");
        p_wsprintfA = GetProcAddress(h_original, "wsprintfA");
        p_wsprintfW = GetProcAddress(h_original, "wsprintfW");
        p_wvsprintfA = GetProcAddress(h_original, "wvsprintfA");
        p_wvsprintfW = GetProcAddress(h_original, "wvsprintfW");

		p_GetGestureInfo = GetProcAddress(h_original, "GetGestureInfo");
		p_GetGestureConfig = GetProcAddress(h_original, "GetGestureConfig");
		p_SetGestureConfig = GetProcAddress(h_original, "SetGestureConfig");
		p_CloseGestureInfoHandle = GetProcAddress(h_original, "CloseGestureInfoHandle");
		
        break;
    case DLL_THREAD_ATTACH:
        break;
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        FreeLibrary(h_original);
        break;
    default:
        break;
    }
    return TRUE;
}
