On Vista: it can't find GetGestureInfo in USER32.dll

fix dll

Summary:
  * Disable Windows7 Multi-touch APIs(GetGestureInfo, GetGestureConfig, SetGestureConfig, CloseGestureInfoHandle) for WindowsVista.
  * Multi-touch APIs always return 1. (non-zero = success)

How to use:
  * Copy ASER32.dll to target dir.
  * Find target.exe using Gesture APIs.
  * Open Binary Editor
  * USER32.dll -> ASER32.dll
  * Save & Run

![http://1.bp.blogspot.com/_Lj2tsQEbPRY/TBvxiEJ_FcI/AAAAAAAAABo/GSMf3yDgUKs/s400/aser32.jpg](http://1.bp.blogspot.com/_Lj2tsQEbPRY/TBvxiEJ_FcI/AAAAAAAAABo/GSMf3yDgUKs/s400/aser32.jpg)