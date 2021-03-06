#ifndef __TYPES_H__
#define __TYPES_H__

#pragma pack(1)

#define CACHE_FILE_NAME             _T(".cache.dat")
#define MAX_CHAPTER_LENGTH          256
#define MAX_MARK_COUNT              256

#define USING_MENU_CHAPTERS         0
#define ENABLE_NETWORK              1

#define IDM_CUSTOM_BEGIN            (50000)
#define IDM_CHAPTER_BEGIN           (IDM_CUSTOM_BEGIN + 1)
#define IDM_CHAPTER_END             (IDM_CHAPTER_BEGIN + 2000)

#define IDM_OPEN_BEGIN              (IDM_CHAPTER_END + 1)
#define IDM_OPEN_END                (IDM_OPEN_BEGIN + 2000)

#define IDI_SYSTRAY                 (IDM_OPEN_END + 1)
#define IDM_ST_OPEN                 (IDM_OPEN_END + 2)
#define IDM_ST_EXIT                 (IDM_OPEN_END + 3)
#define IDM_MK_DEL                  (IDM_OPEN_END + 4)

#if ENABLE_NETWORK
#define WM_NEW_VERSION              (WM_USER + 100)
#endif
#define WM_UPDATE_CHAPTERS          (WM_USER + 101)
#define WM_OPEN_BOOK                (WM_USER + 102)
#define WM_SYSTRAY                  (WM_USER + 103)
#define WM_TASKBAR_CREATED          (RegisterWindowMessage(_T("TaskbarCreated")))


#define ID_HOTKEY_SHOW_HIDE_WINDOW  100
#define IDT_TIMER_PAGE              102
#if ENABLE_NETWORK
#define IDT_TIMER_UPGRADE           103
#endif
#define IDT_TIMER_LOADING           104


typedef unsigned char   u8;
typedef unsigned long   u32;

typedef struct 
{
    u8 data[16];
} u128_t;

typedef struct 
{
	u128_t md5;
	int id;
	int index; // save text current pos
    TCHAR file_name[MAX_PATH];
    int mark_size;
    int mark[MAX_MARK_COUNT]; // book mark
} item_t;

typedef enum
{
    Stretch,
    Tile,
    TileFlip
} bg_image_mode_t;

typedef struct
{
    BOOL enable;
    TCHAR file_name[MAX_PATH];
    int mode; // bg_image_mode_t
} bg_image_t;

typedef struct  
{
    BOOL enable;
    WCHAR addr[64];
    int port;
    WCHAR user[64];
    WCHAR pass[64];
} proxy_t;

typedef struct 
{
	int flag;
    UINT version;
    RECT rect;
	LOGFONT font;
    u32 font_color;
	u32 bg_color;
    BYTE alpha;
	int item_id;
	int size;
    int line_gap;
    int internal_border;
    int wheel_speed;
    int page_mode;
    int autopage_mode;
    bg_image_t bg_image;
    UINT uElapse;
    proxy_t proxy;
    TCHAR ingore_version[16];
    int hide_taskbar;
    int show_systray;
    int disable_lrhide;
    BYTE isDefault;
    unsigned long keyset[64];
    int reserved[64];
} header_t;

struct body_t
{
	item_t items[1];
};

typedef enum
{
    Unknown = 0,
    utf8,
    utf16_le,
    utf16_be,
    utf32_le,
    utf32_be
} type_t;

struct upmenu_t
{
    BYTE op;        // 0: delete, 1: append, 2: insert
    HMENU hMenu;
    UINT uPosition;
    UINT uFlags;
    INT_PTR uIDNewItem;
    LPCTSTR lpNewItem;
};

typedef struct
{
    HMENU hMenu;
    HWND hStatusBar;
    BOOL bHideBorder;
    BOOL bFullScreen;

    // hide border restore data
    DWORD hbStyle;
    DWORD hbExStyle;
    RECT hbRect;

    // full screen restore data
    DWORD fsStyle;
    DWORD fsExStyle;
    RECT fsRect;
} window_info_t;


#endif