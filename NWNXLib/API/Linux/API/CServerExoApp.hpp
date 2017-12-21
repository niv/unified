#pragma once

#include <cstdint>

#include "CBaseExoApp.hpp"
#include "CExoArrayListTemplatedunsignedlong.hpp"
#include "CExoLocString.hpp"
#include "CExoString.hpp"
#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CCodeBase;
struct CExoArrayListTemplatedCExoString;
struct CExoLinkedListTemplatedunsignedlong;
struct CExtendedServerInfo;
struct CGameObject;
struct CGameObjectArray;
struct CNWPlaceMeshManager;
struct CNWSArea;
struct CNWSAreaOfEffectObject;
struct CNWSClient;
struct CNWSCreature;
struct CNWSDoor;
struct CNWSEncounter;
struct CNWSItem;
struct CNWSModule;
struct CNWSPlaceable;
struct CNWSPlayer;
struct CNWSSoundObject;
struct CNWSStore;
struct CNWSTrigger;
struct CNWSWaypoint;
struct CNetLayer;
struct CServerAIMaster;
struct CServerExoAppInternal;
struct CServerInfo;
struct CWorldTimer;

struct CServerExoApp
    : CBaseExoApp
{
    CServerExoAppInternal* m_pcExoAppInternal;

    // The below are auto generated stubs.
    CServerExoApp(const CServerExoApp&) = default;
    CServerExoApp& operator=(const CServerExoApp&) = default;

    CServerExoApp();
    ~CServerExoApp();
    void AddCDKeyToBannedList(CExoString);
    void AddCharListRequest(uint32_t);
    void AddExportPlayersCharacterRequest(uint32_t);
    void AddIPToBannedList(CExoString);
    void AddPlayerNameToBannedList(CExoString);
    void AddSubNetProfileSendSize(uint32_t, uint32_t);
    void AddToExclusionList(uint32_t, unsigned char);
    int32_t AdmitNetworkAddress(uint32_t, CExoString);
    int32_t AdmitPlayerName(CExoString);
    int32_t CheckStickyPlayerNameReserved(CExoString, CExoString, CExoString, int32_t);
    void ClearExportPlayerCharacterRequests();
    int32_t ContinueMessageProcessing();
    int32_t ExportAllPlayers();
    CExoLinkedListTemplatedunsignedlong* GetActiveExclusionList();
    unsigned char GetActivePauseState();
    CWorldTimer* GetActiveTimer(uint32_t);
    uint32_t GetApplicationId();
    CNWSArea* GetAreaByGameObjectID(uint32_t);
    CNWSAreaOfEffectObject* GetAreaOfEffectByGameObjectID(uint32_t);
    int32_t GetAutoSavePending();
    CExoString GetBannedListString();
    int32_t GetCDKeys(CExoArrayListTemplatedCExoString**);
    CNWSPlayer* GetClientObjectByObjectId(uint32_t);
    CNWSClient* GetClientObjectByPlayerId(uint32_t, unsigned char);
    uint32_t GetClientsRequiredToDisableCPUSleep();
    CCodeBase* GetCodeBase();
    void GetConnectionLib();
    CNWSCreature* GetCreatureByGameObjectID(uint32_t);
    int32_t GetCreatureDeathLogging();
    int32_t GetDebugMode();
    int32_t GetDifficultyOption(int32_t);
    CNWSDoor* GetDoorByGameObjectID(uint32_t);
    CNWSEncounter* GetEncounterByGameObjectID(uint32_t);
    int32_t GetExportCharacterPending();
    const CExoArrayListTemplatedunsignedlong& GetExportPlayersCharacterRequests();
    CExtendedServerInfo* GetExtendedServerInfo();
    void GetExtendedServerInfo(CExtendedServerInfo*);
    int32_t GetFactionOfObject(uint32_t, int32_t*);
    uint32_t GetFirstPCObject();
    float GetFPS();
    CGameObject* GetGameObject(uint32_t);
    int32_t GetGameSpyEnabled();
    int32_t GetImportingChar();
    int32_t GetIsCDKeyOnBannedList(CExoString);
    int32_t GetIsControlledByPlayer(uint32_t);
    int32_t GetIsIPOnBannedList(CExoString);
    int32_t GetIsPlayerNameOnBannedList(CExoString);
    CNWSItem* GetItemByGameObjectID(uint32_t);
    int32_t GetLoadingModule();
    void* GetModule();
    CNWSModule* GetModuleByGameObjectID(uint32_t);
    CExoLocString GetModuleDescription();
    int32_t GetModuleLanguage();
    CExoString GetModuleName();
    int32_t GetMoveToModulePending();
    CExoString GetMoveToModuleString();
    int32_t GetMultiplayerEnabled();
    CNetLayer* GetNetLayer();
    uint32_t GetNextPCObject();
    void* GetNWSMessage();
    CGameObjectArray* GetObjectArray();
    int32_t GetPauseState(unsigned char);
    CWorldTimer* GetPauseTimer();
    CNWSPlaceable* GetPlaceableByGameObjectID(uint32_t);
    CNWPlaceMeshManager* GetPlaceMeshManager();
    int32_t GetPlayerAddressData(uint32_t, uint32_t*, unsigned char**, unsigned char**, uint32_t*);
    uint32_t GetPlayerIDByGameObjectID(uint32_t);
    int32_t GetPlayerLanguage(uint32_t);
    void* GetPlayerList();
    CExoString GetPlayerListString();
    CExoString GetPortalListString();
    int32_t GetReloadModuleWhenEmpty();
    CServerAIMaster* GetServerAIMaster();
    CServerInfo* GetServerInfo();
    int16_t GetServerMode();
    CNWSSoundObject* GetSoundObjectByGameObjectID(uint32_t);
    int32_t GetStickyCombatModesEnabled();
    CNWSStore* GetStoreByGameObjectID(uint32_t);
    void* GetSysAdminList();
    CWorldTimer* GetTimestopTimer();
    CNWSTrigger* GetTriggerByGameObjectID(uint32_t);
    CNWSWaypoint* GetWaypointByGameObjectID(uint32_t);
    CWorldTimer* GetWorldTimer();
    void GSClientAddServer(void*, char*, char*, int32_t, int32_t, int32_t, int32_t, char*, int32_t, int32_t, char*, int32_t, int32_t, int32_t, char*, char*, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t);
    void GSClientChatMessage(int32_t, CExoString, CExoString);
    void GSClientClearServers();
    void GSClientGroupRoomAdded(int32_t, uint32_t);
    void GSClientRemoveServer(void*);
    void GSClientUpdateConnectionPhase(unsigned char, const CExoString&);
    void GSClientUpdateServer(void*, char*, char*, int32_t, int32_t, int32_t, int32_t, char*, int32_t, int32_t, char*, int32_t, int32_t, int32_t, char*, char*, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t);
    void HandleGameSpyToServerMessage(int32_t, void*, int32_t);
    int32_t HandleMessage(uint32_t, unsigned char*, uint32_t, int32_t);
    void HandleOldServerVaultMigration(CExoString, CExoString, CExoString);
    int32_t Initialize();
    void InitiateModuleForPlayer(void*);
    int32_t IsOnActiveExclusionList(uint32_t);
    int32_t IsOnExclusionList(uint32_t);
    int32_t IsPlayerNameSticky();
    int32_t LoadCharacterFinish(CNWSPlayer*, int32_t, int32_t);
    int32_t LoadCharacterStart(unsigned char, CNWSPlayer*, CResRef, void*, uint32_t);
    int32_t LoadGame(uint32_t, CExoString&, CExoString&, CNWSPlayer*);
    int32_t LoadModule(CExoString, int32_t, CNWSPlayer*);
    int32_t LoadPrimaryPlayer(CNWSPlayer*);
    int32_t MainLoop();
    void MovePlayerToArea(void*);
    void OnCDChange();
    void OnExit();
    void OnGainFocus();
    void OnLostFocus();
    void OnVideoChange();
    void PlayerListChange(uint32_t, int32_t, int32_t);
    void PushMessageOverWall(unsigned char*, uint32_t);
    void RemoveCDKeyFromBannedList(CExoString);
    void RemoveFromExclusionList(uint32_t, unsigned char);
    void RemoveIPFromBannedList(CExoString);
    void RemovePCFromWorld(CNWSPlayer*);
    void RemovePlayerNameFromBannedList(CExoString);
    uint32_t ResolvePlayerByFirstName(const CExoString&);
    void RestartNetLayer();
    int32_t RunModule();
    int32_t SaveGame(uint32_t, CExoString&, CExoString&, CNWSPlayer*, int32_t, CExoString&);
    int32_t SendCharacterQuery(CNWSPlayer*);
    void SetApplicationIdsMatch(int32_t);
    void SetAutoSavePending(int32_t);
    void SetDebugMode(int32_t);
    void SetEndGamePending(int32_t);
    void SetEndGameString(CExoString&);
    void SetExportCharacterPending(int32_t);
    void SetForceUpdate();
    void SetGameSpyEnabled(int32_t);
    void SetGameSpyReporting(int32_t);
    void SetImportingChar(int32_t);
    void SetLoadingModule(int32_t);
    void SetMoveToModulePending(int32_t);
    void SetMoveToModuleString(CExoString&);
    int32_t SetNetworkAddressBan(uint32_t, CExoString, int32_t);
    void SetPauseState(unsigned char, int32_t);
    void SetReloadModuleWhenEmpty(int32_t);
    void SetWeGotDisconnected();
    void Shutdown(int32_t, int32_t);
    void ShutdownNetLayer();
    void ShutDownToMainMenu();
    int32_t StartNewModule(CExoString&);
    void StartServices();
    void StopServices();
    int32_t StripColorTokens(CExoString&);
    void TogglePauseState(unsigned char);
    void Uninitialize();
    int32_t UnloadModule();
    int32_t ValidatePlayerLogin(void*);
    void VomitServerOptionsToLog();
};

void CServerExoApp__CServerExoAppCtor(CServerExoApp* thisPtr);
void CServerExoApp__CServerExoAppDtor__0(CServerExoApp* thisPtr);
void CServerExoApp__AddCDKeyToBannedList(CServerExoApp* thisPtr, CExoString);
void CServerExoApp__AddCharListRequest(CServerExoApp* thisPtr, uint32_t);
void CServerExoApp__AddExportPlayersCharacterRequest(CServerExoApp* thisPtr, uint32_t);
void CServerExoApp__AddIPToBannedList(CServerExoApp* thisPtr, CExoString);
void CServerExoApp__AddPlayerNameToBannedList(CServerExoApp* thisPtr, CExoString);
void CServerExoApp__AddSubNetProfileSendSize(CServerExoApp* thisPtr, uint32_t, uint32_t);
void CServerExoApp__AddToExclusionList(CServerExoApp* thisPtr, uint32_t, unsigned char);
int32_t CServerExoApp__AdmitNetworkAddress(CServerExoApp* thisPtr, uint32_t, CExoString);
int32_t CServerExoApp__AdmitPlayerName(CServerExoApp* thisPtr, CExoString);
int32_t CServerExoApp__CheckStickyPlayerNameReserved(CServerExoApp* thisPtr, CExoString, CExoString, CExoString, int32_t);
void CServerExoApp__ClearExportPlayerCharacterRequests(CServerExoApp* thisPtr);
int32_t CServerExoApp__ContinueMessageProcessing(CServerExoApp* thisPtr);
int32_t CServerExoApp__ExportAllPlayers(CServerExoApp* thisPtr);
CExoLinkedListTemplatedunsignedlong* CServerExoApp__GetActiveExclusionList(CServerExoApp* thisPtr);
unsigned char CServerExoApp__GetActivePauseState(CServerExoApp* thisPtr);
CWorldTimer* CServerExoApp__GetActiveTimer(CServerExoApp* thisPtr, uint32_t);
uint32_t CServerExoApp__GetApplicationId(CServerExoApp* thisPtr);
CNWSArea* CServerExoApp__GetAreaByGameObjectID(CServerExoApp* thisPtr, uint32_t);
CNWSAreaOfEffectObject* CServerExoApp__GetAreaOfEffectByGameObjectID(CServerExoApp* thisPtr, uint32_t);
int32_t CServerExoApp__GetAutoSavePending(CServerExoApp* thisPtr);
CExoString CServerExoApp__GetBannedListString(CServerExoApp* thisPtr);
int32_t CServerExoApp__GetCDKeys(CServerExoApp* thisPtr, CExoArrayListTemplatedCExoString**);
CNWSPlayer* CServerExoApp__GetClientObjectByObjectId(CServerExoApp* thisPtr, uint32_t);
CNWSClient* CServerExoApp__GetClientObjectByPlayerId(CServerExoApp* thisPtr, uint32_t, unsigned char);
uint32_t CServerExoApp__GetClientsRequiredToDisableCPUSleep(CServerExoApp* thisPtr);
CCodeBase* CServerExoApp__GetCodeBase(CServerExoApp* thisPtr);
void CServerExoApp__GetConnectionLib(CServerExoApp* thisPtr);
CNWSCreature* CServerExoApp__GetCreatureByGameObjectID(CServerExoApp* thisPtr, uint32_t);
int32_t CServerExoApp__GetCreatureDeathLogging(CServerExoApp* thisPtr);
int32_t CServerExoApp__GetDebugMode(CServerExoApp* thisPtr);
int32_t CServerExoApp__GetDifficultyOption(CServerExoApp* thisPtr, int32_t);
CNWSDoor* CServerExoApp__GetDoorByGameObjectID(CServerExoApp* thisPtr, uint32_t);
CNWSEncounter* CServerExoApp__GetEncounterByGameObjectID(CServerExoApp* thisPtr, uint32_t);
int32_t CServerExoApp__GetExportCharacterPending(CServerExoApp* thisPtr);
const CExoArrayListTemplatedunsignedlong& CServerExoApp__GetExportPlayersCharacterRequests(CServerExoApp* thisPtr);
CExtendedServerInfo* CServerExoApp__GetExtendedServerInfo__0(CServerExoApp* thisPtr);
void CServerExoApp__GetExtendedServerInfo__1(CServerExoApp* thisPtr, CExtendedServerInfo*);
int32_t CServerExoApp__GetFactionOfObject(CServerExoApp* thisPtr, uint32_t, int32_t*);
uint32_t CServerExoApp__GetFirstPCObject(CServerExoApp* thisPtr);
float CServerExoApp__GetFPS(CServerExoApp* thisPtr);
CGameObject* CServerExoApp__GetGameObject(CServerExoApp* thisPtr, uint32_t);
int32_t CServerExoApp__GetGameSpyEnabled(CServerExoApp* thisPtr);
int32_t CServerExoApp__GetImportingChar(CServerExoApp* thisPtr);
int32_t CServerExoApp__GetIsCDKeyOnBannedList(CServerExoApp* thisPtr, CExoString);
int32_t CServerExoApp__GetIsControlledByPlayer(CServerExoApp* thisPtr, uint32_t);
int32_t CServerExoApp__GetIsIPOnBannedList(CServerExoApp* thisPtr, CExoString);
int32_t CServerExoApp__GetIsPlayerNameOnBannedList(CServerExoApp* thisPtr, CExoString);
CNWSItem* CServerExoApp__GetItemByGameObjectID(CServerExoApp* thisPtr, uint32_t);
int32_t CServerExoApp__GetLoadingModule(CServerExoApp* thisPtr);
void* CServerExoApp__GetModule(CServerExoApp* thisPtr);
CNWSModule* CServerExoApp__GetModuleByGameObjectID(CServerExoApp* thisPtr, uint32_t);
CExoLocString CServerExoApp__GetModuleDescription(CServerExoApp* thisPtr);
int32_t CServerExoApp__GetModuleLanguage(CServerExoApp* thisPtr);
CExoString CServerExoApp__GetModuleName(CServerExoApp* thisPtr);
int32_t CServerExoApp__GetMoveToModulePending(CServerExoApp* thisPtr);
CExoString CServerExoApp__GetMoveToModuleString(CServerExoApp* thisPtr);
int32_t CServerExoApp__GetMultiplayerEnabled(CServerExoApp* thisPtr);
CNetLayer* CServerExoApp__GetNetLayer(CServerExoApp* thisPtr);
uint32_t CServerExoApp__GetNextPCObject(CServerExoApp* thisPtr);
void* CServerExoApp__GetNWSMessage(CServerExoApp* thisPtr);
CGameObjectArray* CServerExoApp__GetObjectArray(CServerExoApp* thisPtr);
int32_t CServerExoApp__GetPauseState(CServerExoApp* thisPtr, unsigned char);
CWorldTimer* CServerExoApp__GetPauseTimer(CServerExoApp* thisPtr);
CNWSPlaceable* CServerExoApp__GetPlaceableByGameObjectID(CServerExoApp* thisPtr, uint32_t);
CNWPlaceMeshManager* CServerExoApp__GetPlaceMeshManager(CServerExoApp* thisPtr);
int32_t CServerExoApp__GetPlayerAddressData(CServerExoApp* thisPtr, uint32_t, uint32_t*, unsigned char**, unsigned char**, uint32_t*);
uint32_t CServerExoApp__GetPlayerIDByGameObjectID(CServerExoApp* thisPtr, uint32_t);
int32_t CServerExoApp__GetPlayerLanguage(CServerExoApp* thisPtr, uint32_t);
void* CServerExoApp__GetPlayerList(CServerExoApp* thisPtr);
CExoString CServerExoApp__GetPlayerListString(CServerExoApp* thisPtr);
CExoString CServerExoApp__GetPortalListString(CServerExoApp* thisPtr);
int32_t CServerExoApp__GetReloadModuleWhenEmpty(CServerExoApp* thisPtr);
CServerAIMaster* CServerExoApp__GetServerAIMaster(CServerExoApp* thisPtr);
CServerInfo* CServerExoApp__GetServerInfo(CServerExoApp* thisPtr);
int16_t CServerExoApp__GetServerMode(CServerExoApp* thisPtr);
CNWSSoundObject* CServerExoApp__GetSoundObjectByGameObjectID(CServerExoApp* thisPtr, uint32_t);
int32_t CServerExoApp__GetStickyCombatModesEnabled(CServerExoApp* thisPtr);
CNWSStore* CServerExoApp__GetStoreByGameObjectID(CServerExoApp* thisPtr, uint32_t);
void* CServerExoApp__GetSysAdminList(CServerExoApp* thisPtr);
CWorldTimer* CServerExoApp__GetTimestopTimer(CServerExoApp* thisPtr);
CNWSTrigger* CServerExoApp__GetTriggerByGameObjectID(CServerExoApp* thisPtr, uint32_t);
CNWSWaypoint* CServerExoApp__GetWaypointByGameObjectID(CServerExoApp* thisPtr, uint32_t);
CWorldTimer* CServerExoApp__GetWorldTimer(CServerExoApp* thisPtr);
void CServerExoApp__GSClientAddServer(CServerExoApp* thisPtr, void*, char*, char*, int32_t, int32_t, int32_t, int32_t, char*, int32_t, int32_t, char*, int32_t, int32_t, int32_t, char*, char*, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t);
void CServerExoApp__GSClientChatMessage(CServerExoApp* thisPtr, int32_t, CExoString, CExoString);
void CServerExoApp__GSClientClearServers(CServerExoApp* thisPtr);
void CServerExoApp__GSClientGroupRoomAdded(CServerExoApp* thisPtr, int32_t, uint32_t);
void CServerExoApp__GSClientRemoveServer(CServerExoApp* thisPtr, void*);
void CServerExoApp__GSClientUpdateConnectionPhase(CServerExoApp* thisPtr, unsigned char, const CExoString&);
void CServerExoApp__GSClientUpdateServer(CServerExoApp* thisPtr, void*, char*, char*, int32_t, int32_t, int32_t, int32_t, char*, int32_t, int32_t, char*, int32_t, int32_t, int32_t, char*, char*, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t);
void CServerExoApp__HandleGameSpyToServerMessage(CServerExoApp* thisPtr, int32_t, void*, int32_t);
int32_t CServerExoApp__HandleMessage(CServerExoApp* thisPtr, uint32_t, unsigned char*, uint32_t, int32_t);
void CServerExoApp__HandleOldServerVaultMigration(CServerExoApp* thisPtr, CExoString, CExoString, CExoString);
int32_t CServerExoApp__Initialize(CServerExoApp* thisPtr);
void CServerExoApp__InitiateModuleForPlayer(CServerExoApp* thisPtr, void*);
int32_t CServerExoApp__IsOnActiveExclusionList(CServerExoApp* thisPtr, uint32_t);
int32_t CServerExoApp__IsOnExclusionList(CServerExoApp* thisPtr, uint32_t);
int32_t CServerExoApp__IsPlayerNameSticky(CServerExoApp* thisPtr);
int32_t CServerExoApp__LoadCharacterFinish(CServerExoApp* thisPtr, CNWSPlayer*, int32_t, int32_t);
int32_t CServerExoApp__LoadCharacterStart(CServerExoApp* thisPtr, unsigned char, CNWSPlayer*, CResRef, void*, uint32_t);
int32_t CServerExoApp__LoadGame(CServerExoApp* thisPtr, uint32_t, CExoString&, CExoString&, CNWSPlayer*);
int32_t CServerExoApp__LoadModule(CServerExoApp* thisPtr, CExoString, int32_t, CNWSPlayer*);
int32_t CServerExoApp__LoadPrimaryPlayer(CServerExoApp* thisPtr, CNWSPlayer*);
int32_t CServerExoApp__MainLoop(CServerExoApp* thisPtr);
void CServerExoApp__MovePlayerToArea(CServerExoApp* thisPtr, void*);
void CServerExoApp__OnCDChange(CServerExoApp* thisPtr);
void CServerExoApp__OnExit(CServerExoApp* thisPtr);
void CServerExoApp__OnGainFocus(CServerExoApp* thisPtr);
void CServerExoApp__OnLostFocus(CServerExoApp* thisPtr);
void CServerExoApp__OnVideoChange(CServerExoApp* thisPtr);
void CServerExoApp__PlayerListChange(CServerExoApp* thisPtr, uint32_t, int32_t, int32_t);
void CServerExoApp__PushMessageOverWall(CServerExoApp* thisPtr, unsigned char*, uint32_t);
void CServerExoApp__RemoveCDKeyFromBannedList(CServerExoApp* thisPtr, CExoString);
void CServerExoApp__RemoveFromExclusionList(CServerExoApp* thisPtr, uint32_t, unsigned char);
void CServerExoApp__RemoveIPFromBannedList(CServerExoApp* thisPtr, CExoString);
void CServerExoApp__RemovePCFromWorld(CServerExoApp* thisPtr, CNWSPlayer*);
void CServerExoApp__RemovePlayerNameFromBannedList(CServerExoApp* thisPtr, CExoString);
uint32_t CServerExoApp__ResolvePlayerByFirstName(CServerExoApp* thisPtr, const CExoString&);
void CServerExoApp__RestartNetLayer(CServerExoApp* thisPtr);
int32_t CServerExoApp__RunModule(CServerExoApp* thisPtr);
int32_t CServerExoApp__SaveGame(CServerExoApp* thisPtr, uint32_t, CExoString&, CExoString&, CNWSPlayer*, int32_t, CExoString&);
int32_t CServerExoApp__SendCharacterQuery(CServerExoApp* thisPtr, CNWSPlayer*);
void CServerExoApp__SetApplicationIdsMatch(CServerExoApp* thisPtr, int32_t);
void CServerExoApp__SetAutoSavePending(CServerExoApp* thisPtr, int32_t);
void CServerExoApp__SetDebugMode(CServerExoApp* thisPtr, int32_t);
void CServerExoApp__SetEndGamePending(CServerExoApp* thisPtr, int32_t);
void CServerExoApp__SetEndGameString(CServerExoApp* thisPtr, CExoString&);
void CServerExoApp__SetExportCharacterPending(CServerExoApp* thisPtr, int32_t);
void CServerExoApp__SetForceUpdate(CServerExoApp* thisPtr);
void CServerExoApp__SetGameSpyEnabled(CServerExoApp* thisPtr, int32_t);
void CServerExoApp__SetGameSpyReporting(CServerExoApp* thisPtr, int32_t);
void CServerExoApp__SetImportingChar(CServerExoApp* thisPtr, int32_t);
void CServerExoApp__SetLoadingModule(CServerExoApp* thisPtr, int32_t);
void CServerExoApp__SetMoveToModulePending(CServerExoApp* thisPtr, int32_t);
void CServerExoApp__SetMoveToModuleString(CServerExoApp* thisPtr, CExoString&);
int32_t CServerExoApp__SetNetworkAddressBan(CServerExoApp* thisPtr, uint32_t, CExoString, int32_t);
void CServerExoApp__SetPauseState(CServerExoApp* thisPtr, unsigned char, int32_t);
void CServerExoApp__SetReloadModuleWhenEmpty(CServerExoApp* thisPtr, int32_t);
void CServerExoApp__SetWeGotDisconnected(CServerExoApp* thisPtr);
void CServerExoApp__Shutdown(CServerExoApp* thisPtr, int32_t, int32_t);
void CServerExoApp__ShutdownNetLayer(CServerExoApp* thisPtr);
void CServerExoApp__ShutDownToMainMenu(CServerExoApp* thisPtr);
int32_t CServerExoApp__StartNewModule(CServerExoApp* thisPtr, CExoString&);
void CServerExoApp__StartServices(CServerExoApp* thisPtr);
void CServerExoApp__StopServices(CServerExoApp* thisPtr);
int32_t CServerExoApp__StripColorTokens(CServerExoApp* thisPtr, CExoString&);
void CServerExoApp__TogglePauseState(CServerExoApp* thisPtr, unsigned char);
void CServerExoApp__Uninitialize(CServerExoApp* thisPtr);
int32_t CServerExoApp__UnloadModule(CServerExoApp* thisPtr);
int32_t CServerExoApp__ValidatePlayerLogin(CServerExoApp* thisPtr, void*);
void CServerExoApp__VomitServerOptionsToLog(CServerExoApp* thisPtr);

}

}
