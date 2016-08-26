#include <engine/server.h>
#include <game/server/gamecontext.h>
#include <game/server/player.h>
#include <generated/server_data.h>

#include <tu/server/event.h>

#include <mod/entities/character.h>
#include <mod/entities/projectile.h>

#include "gun.h"

CMod_Weapon_Gun::CMod_Weapon_Gun(CCharacter* pCharacter, int Ammo) :
	tu::CWeapon_GenericGun07(MOD_WEAPON_GUN, WEAPON_GUN, pCharacter, Ammo)
{
	
}

void CMod_Weapon_Gun::CreateProjectile(vec2 Pos, vec2 Direction)
{
	new CProjectile(GameWorld(), WEAPON_GUN,
		Player()->GetCID(),
		Pos,
		Direction,
		(int)(Server()->TickSpeed() * GameServer()->Tuning()->m_GunLifetime),
		g_pData->m_Weapons.m_Gun.m_pBase->m_Damage, false, 0, -1, GetID());

	tu::CEvent_Sound(GameServer()).World(WorldID())
		.Send(Character()->GetPos(), SOUND_GUN_FIRE);
}
