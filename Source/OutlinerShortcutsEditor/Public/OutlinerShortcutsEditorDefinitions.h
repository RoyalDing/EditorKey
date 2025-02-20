// Copyright Voulz 2021-2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(LogOutlinerShortcutsEditor, Log, All);


#undef CURRENT_LOG_CATEGORY
#define CURRENT_LOG_CATEGORY LogOutlinerShortcutsEditor

#undef DEBUG_OUTLINER_SHORTCUTS
#define DEBUG_OUTLINER_SHORTCUTS 0



// ----------- For Mac where these are not available. To be tested -------------
#ifndef _CRT_WIDE_
#define _CRT_WIDE_(s) L ## s
#endif
#ifndef _CRT_WIDE
#define _CRT_WIDE(s) _CRT_WIDE_(s)
#endif
#ifndef __FILEW__
#define __FILEW__     _CRT_WIDE(__FILE__)
#endif
#ifndef __FUNCTIONW__
#define __FUNCTIONW__ _CRT_WIDE(__FUNCTION__)
#endif
// ---------------------------------------------------------------



#ifndef LOG
/**
* @brief LOG. Calls UE_LOG(CURRENT_LOG_CATEGORY, Display, ...). Make sure to define CURRENT_LOG_CATEGORY first with
* #define CURRENT_LOG_CATEGORY LogOutlinerShortcutsEditor
*/
#define LOG(Format, ...) __LOG__(CURRENT_LOG_CATEGORY, Format, __VA_ARGS__);
#define __LOG__(LogCategory, Format, ...) UE_LOG(LogCategory, Display, TEXT(Format), __VA_ARGS__);
#endif

#ifndef LOG_H
/**
* @brief LOG + HERE. Calls UE_LOG(CURRENT_LOG_CATEGORY, Display, ...). Make sure to define CURRENT_LOG_CATEGORY first with
* #define CURRENT_LOG_CATEGORY LogOutlinerShortcutsEditor
*/
#define LOG_H(Format, ...) __LOGH__(CURRENT_LOG_CATEGORY, Format, __VA_ARGS__);
#define __LOGH__(LogCategory, Format, ...) UE_LOG(LogCategory, Display, TEXT("[%s]  " Format), __FUNCTIONW__, __VA_ARGS__);
#endif

#ifndef LOG_D
#if DEBUG_OUTLINER_SHORTCUTS
/**
* @brief LOG DEBUG. Calls UE_LOG(CURRENT_LOG_CATEGORY, Display, ...) if DEBUG_OUTLINER_SHORTCUTS is set to 1. Make sure to define CURRENT_LOG_CATEGORY first with
* #define CURRENT_LOG_CATEGORY LogOutlinerShortcutsEditor
*/
#define LOG_D(Format, ...) LOG_H(Format,__VA_ARGS__);
#else // not DEBUG_OUTLINER_SHORTCUTS
/**
* @brief LOG DEBUG. Calls UE_LOG(CURRENT_LOG_CATEGORY, Display, ...) if DEBUG_OUTLINER_SHORTCUTS is set to 1. Make sure to define CURRENT_LOG_CATEGORY first with
* #define CURRENT_LOG_CATEGORY LogOutlinerShortcutsEditor
*/
#define LOG_D(Format, ...) {}
#endif //DEBUG_OUTLINER_SHORTCUTS
#endif


#ifndef LOGV
/**
* @brief LOG VERBOSE. Calls UE_LOG(CURRENT_LOG_CATEGORY, Log, ...). Make sure to define CURRENT_LOG_CATEGORY first with
* #define CURRENT_LOG_CATEGORY LogOutlinerShortcutsEditor
*/
#define LOGV(Format, ...) __LOGV__(CURRENT_LOG_CATEGORY, Format, __VA_ARGS__);
#define __LOGV__(LogCategory, Format, ...) UE_LOG(LogCategory, Log, TEXT(Format), __VA_ARGS__);
#endif

#ifndef LOGV_H
/**
* @brief LOG VERBOSE + HERE. Calls UE_LOG(CURRENT_LOG_CATEGORY, Log, ...). Make sure to define CURRENT_LOG_CATEGORY first with
* #define CURRENT_LOG_CATEGORY LogOutlinerShortcutsEditor
*/
#define LOGV_H(Format, ...) __LOGVH__(CURRENT_LOG_CATEGORY, Format, __VA_ARGS__);
#define __LOGVH__(LogCategory, Format, ...) UE_LOG(LogCategory, Log, TEXT("[%s]  " Format), __FUNCTIONW__, __VA_ARGS__);
#endif

#ifndef WARN
/**
* @brief WARN. Calls UE_LOG(CURRENT_LOG_CATEGORY, Warning, ...). Make sure to define CURRENT_LOG_CATEGORY first with
* #define CURRENT_LOG_CATEGORY LogOutlinerShortcutsEditor
*/
#define WARN(Format, ...) __WARN__(CURRENT_LOG_CATEGORY, Format, __VA_ARGS__);
#define __WARN__(LogCategory, Format, ...) UE_LOG(LogCategory, Warning, TEXT(Format), __VA_ARGS__);
#endif

#ifndef WARN_H
/**
* @brief WARN + HERE. Calls UE_LOG(CURRENT_LOG_CATEGORY, Warning, ...). Make sure to define CURRENT_LOG_CATEGORY first with
* #define CURRENT_LOG_CATEGORY LogOutlinerShortcutsEditor
*/
#define WARN_H(Format, ...) __WARNH__(CURRENT_LOG_CATEGORY, Format, __VA_ARGS__);
#define __WARNH__(LogCategory, Format, ...) UE_LOG(LogCategory, Warning, TEXT("[%s]  " Format), __FUNCTIONW__, __VA_ARGS__);
#endif

#ifndef ERROR
/**
* @brief ERROR. Calls UE_LOG(CURRENT_LOG_CATEGORY, Error, ...). Make sure to define CURRENT_LOG_CATEGORY first with
* #define CURRENT_LOG_CATEGORY LogOutlinerShortcutsEditor
*/
#define ERROR(Format, ...) __ERROR__(CURRENT_LOG_CATEGORY, Format, __VA_ARGS__);
#define __ERROR__(LogCategory, Format, ...) UE_LOG(LogCategory, Error, TEXT(Format), __VA_ARGS__);
#endif

#ifndef ERROR_H
/**
* @brief ERROR + HERE. Calls UE_LOG(CURRENT_LOG_CATEGORY, Error, ...). Make sure to define CURRENT_LOG_CATEGORY first with
* #define CURRENT_LOG_CATEGORY LogOutlinerShortcutsEditor
*/
#define ERROR_H(Format, ...) __ERRORH__(CURRENT_LOG_CATEGORY, Format, __VA_ARGS__);
#define __ERRORH__(LogCategory, Format, ...) UE_LOG(LogCategory, Error, TEXT("[%s]  " Format), __FUNCTIONW__, __VA_ARGS__);
#endif


#ifndef __FILENAME__
/**
* @brief Returns the current Filename
*/
#define __FILENAME__ (wcsrchr(__FILEW__, '\\') ? wcsrchr(__FILEW__, '\\') + 1 : __FILEW__)
#endif

#ifndef WHERE
/**
* @brief Logs where this function has been called. Make sure to define CURRENT_LOG_CATEGORY first with
* #define CURRENT_LOG_CATEGORY LogOutlinerShortcutsEditor
*/
#define WHERE LOG("%s - R%i - %s", __FILENAME__, __LINE__, __FUNCTIONW__);
#endif

#ifndef HERE
/**
* @brief Prints the current function name in the Output. Make sure to define CURRENT_LOG_CATEGORY first with
* #define CURRENT_LOG_CATEGORY LogOutlinerShortcutsEditor
*/
#define HERE LOGV(" ==== [%s] ==== ", __FUNCTIONW__);
#endif

#ifndef HERE_D
#if DEBUG_OUTLINER_SHORTCUTS
/**
* @brief Prints the current function name in the Output if DEBUG_OUTLINER_SHORTCUTS is set to 1. Make sure to define CURRENT_LOG_CATEGORY first with
* #define CURRENT_LOG_CATEGORY LogOutlinerShortcutsEditor
*/
#define HERE_D HERE;
#else // not def DEBUG_OUTLINER_SHORTCUTS
/**
* @brief Prints the current function name in the Output if DEBUG_OUTLINER_SHORTCUTS is set to 1. Make sure to define CURRENT_LOG_CATEGORY first with
* #define CURRENT_LOG_CATEGORY LogOutlinerShortcutsEditor
*/
#define HERE_D {}
#endif //DEBUG_OUTLINER_SHORTCUTS
#endif


#ifndef BtoS
/**
* @brief Converts a bool to *CHAR for logging
*/
#define BtoS(var) var ? TEXT("True") : TEXT("False")
#endif

#pragma message("  [OutlinerShortcutsEditorDefinitions] Loaded")
