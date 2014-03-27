/**
* @file Vad.h
* @author created by: Peter Hlavaty
*
* Variables not likely to change, seems to be 'safe' to implement it
*
*/

#ifndef __VAD_H__
#define __VAD_H__

#include "ntifs.h"

typedef void* MM_AVL_TABLE;

#pragma pack(push, 1)

struct SAME_THREAD_APC_FLAGS 
{
	struct
	{
		UCHAR Spare : 1;
		UCHAR StartAddressInvalid : 1;
		UCHAR EtwCalloutActive : 1;
		UCHAR OwnsProcessWorkingSetExclusive : 1;
		UCHAR OwnsProcessWorkingSetShared : 1;
		UCHAR OwnsSystemCacheWorkingSetExclusive : 1;
		UCHAR OwnsSystemCacheWorkingSetShared : 1;
		UCHAR OwnsSessionWorkingSetExclusive : 1;
	};
	struct
	{
		UCHAR OwnsSessionWorkingSetShared : 1;
		UCHAR OwnsProcessAddressSpaceExclusive : 1;
		UCHAR OwnsProcessAddressSpaceShared : 1;
		UCHAR SuppressSymbolLoad : 1;
		UCHAR Prefetching : 1;
		UCHAR OwnsVadExclusive : 1;
		UCHAR OwnsChangeControlAreaExclusive : 1;
		UCHAR OwnsChangeControlAreaShared : 1;
	};
};

struct VM_FLAGS
{
	ULONG CreateReported : 1;
	ULONG NoDebugInherit   : 1;
	ULONG ProcessExiting   : 1;
	ULONG ProcessDelete    : 1;
	ULONG Wow64SplitPages  : 1;
	ULONG VmDeleted        : 1;
	ULONG OutswapEnabled   : 1;
	ULONG Outswapped       : 1;
	ULONG ForkFailed       : 1;
	ULONG Wow64VaSpace4Gb  : 1;
	ULONG AddressSpaceInitialized : 1;
	ULONG SetTimerResolution : 1;
	ULONG BreakOnTermination : 1;
	ULONG DeprioritizeViews : 1;
	ULONG WriteWatch       : 1;
	ULONG ProcessInSession : 1;
	ULONG OverrideAddressSpace : 1;
	ULONG HasAddressSpace  : 1;
	ULONG LaunchPrefetched : 1;
	ULONG Background       : 1;
	ULONG VmTopDown        : 1;
	ULONG ImageNotifyDone  : 1;
	ULONG PdeUpdateNeeded  : 1;
	ULONG VdmAllowed       : 1;
	ULONG CrossSessionCreate : 1;
	ULONG ProcessInserted  : 1;
	ULONG DefaultIoPriority : 1;
	ULONG ProcessSelfDelete : 1;
	ULONG SetTimerResolutionLink : 1;
};

struct MMVAD_FLAGS
{
	union
	{
		ULONG UFlags;
		struct  
		{
			ULONG VadType          : 3;
			ULONG Protection       : 5;
			ULONG PreferredNode    : 6;
			ULONG NoChange         : 1;
			ULONG PrivateMemory    : 1;
			ULONG Teb              : 1;
			ULONG PrivateFixup     : 1;
			ULONG Spare            : 13;
			ULONG DeleteInProgress : 1;
		};
	};
};

#pragma pack(pop)

#endif
