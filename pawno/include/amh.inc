#include <a_samp>

//Dont touch if dont understood.
#define         PUB->%0(%1)                   public %0(%1)
#define         STR->%0(%1)                   stock %0(%1)

//static <3
static
    ac_MoneyVal[MAX_PLAYERS],
    ac_MoneyTick[MAX_PLAYERS]  
;

//begin!
PUB->OnPlayerUpdate(playerid)
{
    if (GetPlayerMoney(playerid) != ac_MoneyVal[playerid])
    {
        ResetPlayerMoney(playerid);
        Bit_Set(ac_MoneyValid, playerid, false);
        GivePlayerMoney(playerid, ac_MoneyVal[playerid]);
    }
    #if defined kon_OnPlayerUpdate
        kon_OnPlayerUpdate(playerid);
    #endif
    return true;
}

#if defined _ALS_OnPlayerUpdate
    #undef OnPlayerUpdate
#else
    #define _ALS_OnPlayerUpdate

#define OnPlayerUpdate kon_OnPlayerUpdate

#if defined kon_OnPlayerUpdate
    forward kon_OnPlayerUpdate(playerid);
#endif

PUB->OnPlayerDisconnect(playerid, reason)
{
    //resetting the val
    ac_MoneyVal[playerid] = 0;
    #if defined kon_OnPlayerDisconnect
        kon_OnPlayerDisconnect(playerid, reason);
    #endif
    return true;
}

#if defined _ALS_OnPlayerDisconnect
    #undef OnPlayerDisconnect
#else
    #define _ALS_OnPlayerDisconnect

#define OnPlayerDisconnect kon_OnPlayerDisconnect

#if defined kon_OnPlayerDisconnect
    forward kon_OnPlayerDisconnect(playerid, reason);
#endif

STR->kon_GivePlayerMoney(playerid, amount)
{
    ac_MoneyVal[playerid] = GetPlayerMoney(playerid);
    Bit_Set(ac_MoneyValid, playerid, true);
    return GivePlayerMoney(playerid, amount);
}

#if defined _ALS_GivePlayerMoney
    #undef GivePlayerMoney
#else
    #define _ALS_GivePlayerMoney
#endif

#define GivePlayerMoney kon_GivePlayerMoney

