#ifndef TU_COMPATIBILITY_H
#define TU_COMPATIBILITY_H

#define TU_NETVERSION_TW06 "0.6 626fce9a778df4d4"
#define TU_NETVERSION_TW07 "0.7 be5937118401c37c"

namespace tu
{

enum
{
	SERVERPROTOCOL_TW06 = 0,
	SERVERPROTOCOL_TW07,
	SERVERPROTOCOL_TU07,
};

enum
{
	CLIENTPROTOCOL_TW06 = 0,
	CLIENTPROTOCOL_TW07,
	CLIENTPROTOCOL_TU07,
};

enum
{
	SNAPSHOT_TW06 = 0,
	SNAPSHOT_TW07,
	SNAPSHOT_TU07,
	NUM_SNAPSHOT,
};

}

#endif
