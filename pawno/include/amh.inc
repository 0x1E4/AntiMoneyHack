#include <a_samp>
#include <YSI\y_bit> // don't know why but i like this <3

//Dont touch if dont understood.
#define         PUB->%0(%1)                   public %0(%1)
#define         STR->%0(%1)                   stock %0(%1)    
#define         FUNC->%0(%1)                  forward %0(%1); public %0(%1)       
#define         FORM->%0(%1)                  format(%0, sizeof(%0), %1)
#define         FRE->%0                       TogglePlayerControllable(%0, false)
#define         UNFRE->%0                     TogglePlayerControllable(%0, true)
#define         TIM->%0(%1, %2, %3, %4)       SetTimerEx(%0, %1, %2, %3, %4)
#define         PLAYERNAME->%0(%1)            GetPlayerName(%1, %0, sizeof(%0))


static
    ac_MoneyVal[MAX_PLAYERS],
    ac_MoneyTick[MAX_PLAYERS],
    BitArray:ac_MoneyValid<MAX_PLAYERS>,   
;
PUB->OnPlayerUpdate(playerid)
{
    if (GetPlayerMoney(playerid) != ac_MoneyVal[playerid])
    {
        ResetPlayerMoney(playerid);
        GivePlayerMoney(playerid, ac_MoneyVal[playerid]);
    }
    #if defined kon_OnPlayerUpdate
        kon_OnPlayerUpdate(playerid);
    #endif
    return 1;
}

#if defined _ALS_OnPlayerUpdate
    #undef OnPlayerUpdate
#else
    #define _ALS_OnPlayerUpdate

#define OnPlayerUpdate kon_OnPlayerUpdate

#if defined kon_OnPlayerUpdate
    forward kon_OnPlayerUpdate(playerid);
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

