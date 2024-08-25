//MAX'y i configi itd
#undef MAX_PLAYERS
#define MAX_PLAYERS 500
#define MAX_CPS 256
#define MAP_MAXTIME 25
#define MAX_ODLICZANIE 30
#define REPICK_TIME 2000
#define MAX_TOP 11
#define INFO_DIALOG 111
#define MAX_VALUE 2147483600
#define MAX_PING 450
const def_pcolor = 2005441023;
//pliki
#define CFG "ServerConfig.cfg"
//kolorki
#define COL_EASY           "{FFF1AF}"
#define COL_WHITE          "{FFFFFF}"
#define COL_BLACK          "{0E0101}"
#define COL_BROWN          "{6E2500}"
#define COL_GREY           "{C3C3C3}"
#define COL_RED            "{F81414}"
#define COL_YELLOW         "{F3FF02}"
#define COL_ORANGE         "{FFAF00}"
#define COL_LIME           "{B7FF00}"
#define COL_CYAN           "{00FFEE}"
#define COL_BLUE           "{00C0FF}"
#define COL_GREEN          "{009933}"
#define COL_DBLUE          "{333399}"
//dla klawiszy
// PRESSED(keys)
#define PRESSED(%0) \
(((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))
//flagi obiektów
#define F_NONE 0
#define F_CP 1
#define F_ARROW 2
#define F_MOBJECT 3
#define F_WEAP 4
#define F_NEON 5
//funkcjonalność
#define NONE 0
#define FIX_VEH 0//Fix vehicle | FUNCTION | value = NONE
#define CHANGE_VEH 1//Change vehicle | FUNCTION | value = vehicle model id
#define NITRO 2//Give nitro | FUNCTION | value = NONE
#define TAKE_NITRO 3//Take nitro | FUNCTION | value = NONE
#define W_ROCKET 4//Adds a rocket for the player, which can fire from the vehicle. | WEAPON | value = NONE
#define W_RAMP 5//Create a ramp on back the player | WEAPON | value = NONE
#define W_HAY 6//Create a hay on back the player | WEAPON | VALUE = NONE
#define W_SPIKE 7//Create a spike strip on back the player | WEAPON | VALUE = NONE