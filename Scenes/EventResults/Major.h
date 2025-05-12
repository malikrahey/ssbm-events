#ifndef EVENT_MAJOR_H
#define EVENT_MAJOR_H

#include "../../m-ex/MexTK/mex.h"

#define MAJOR_ID 43

typedef enum MINOR_ID {
    MINOR_CSS,
    MINOR_VS,
    MINOR_RST,
    MINOR_COUNT
} MINOR_ID;

typedef enum MINOR_KIND {
    KIND_VS = 2,
    KIND_SDNDEATH,
    KIND_TRNMODE,
    KIND_RST,
    KIND_DBGMENU = 7,
    KIND_CSS,
    KIND_SSS,
    KIND_TYGALLERY = 11,
    KIND_TYLOTTERY,
    KIND_TYCOLLECT,
    KIND_ADVSPLASH,
    KIND_TYFALL,
    KIND_CONGRATS,
    KIND_ADVLUIGI,
} KIND_ID;

// same as MatchStandings except with team_winner_num
// easier to put it here so others dont have to manually change/fork mex
typedef struct MatchResults
{
    int x0;                           // 0x24c
    u8 end_kind;                      // 0x250
    u8 x5;                            // 0x251
    u8 is_teams;                      // 0x252
    int time_frames;                  // 0x254 how many frames passed in the match
    u8 xc;                            // 0x258
    u8 winner_num;                    // 0x259 is greater than 1 when a tie occurs
    u8 team_winner_num;
    u8 placings[4];                   // 0x25a - 0x25d, array of player indices in order of placement
    int x14;                          // 0x260
    int x18;                          // 0x264
    TeamStandings team_standings[5];  // 0x268
    PlayerStandings ply_standings[6]; // 0x2a4
}MatchResults;

typedef struct ScDataVictory
{
    int x0;
    int x4;
    MatchResults match_standings;
    u8 unk[0x2278];
}ScDataVictory;

void ResultsPrep(MinorScene* minor);
void VsDecide(MinorScene* minor); 



static u8 *stc_pending_major_change = 0x80479d3c;
static ScDataRst *stc_rst_data = 0x8047C020;

static void* (*Scene_GetEnterData)(MinorScene *scene) = (void *) 0x801a427c;
static void* (*Scene_GetExitData)(MinorScene *scene) = (void *) 0x801a4284;
static void* (*Scene_SetMajorPendingChange)(bool change) = (void *) 0x801a42e8;

static void* (*Match_VsDecide)(MinorScene *scene) = (void *) 0x801b15c8;
static void* (*Match_Exit)(MinorScene *scene) = (void *) 0x8016e9c8;

static void* (*Event_MajorLoad)(void) = (void *) 0x801bbea8;
static void* (*Event_CssPrep)(MinorScene *scene) = (void *) 0x801BAA60;
static void* (*Event_CssDecide)(MinorScene *scene) = (void *) 0x801BAAD0;
static void* (*Event_VsPrep)(MinorScene *scene) = (void *) 0x801BAD70;
static void* (*Event_VsDecide)(MinorScene *scene) = (void *) 0x801BB758;
static void* (*Event_RstPrep)(MinorScene *scene) = (void *) 0x801B16A8;
static void* (*Event_RstDecide)(MinorScene *scene) = (void *) 0x801B16C8;
static void* (*Event_ZeroSceneMem)(void *buf) = (void *) 0x80177724;

#endif