#ifndef MOD_WEAPON_LASER_H
#define MOD_WEAPON_LASER_H

#include <base/vmath.h>
#include <tu/server/weapon.h>

class CMod_Weapon_Laser : public tu::CWeapon_GenericGun07
{
public:
	CMod_Weapon_Laser(class CCharacter* pCharacter, int Ammo);
	
	virtual bool IsAutomatic() const { return true; }
	virtual void CreateProjectile(vec2 Pos, vec2 Direction);
};

#endif
