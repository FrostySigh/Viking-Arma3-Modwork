class CfgVehicles
{
	class Land;
	class Man: Land	{
		class EventHandlers;
	};
	class CAManBase: Man {
		class HitPoints;
	};
	class SoldierWB: CAManBase {
		class HitPoints: HitPoints
		{
			class HitFace;
			class HitNeck;
			class HitHead;
			class HitPelvis;
			class HitAbdomen;
			class HitDiaphragm;
			class HitChest;
			class HitBody;
			class HitArms;
			class HitHands;
			class HitLegs;
		};
	};
	class ARMCO_Soldier_Base: SoldierWB	{
		class HitPoints: HitPoints
		{
			class HitFace
			{
				armor               = 1; // "Healthpoints" of this hitpoint is armor value (of hitpoint) * armor value ( coefficient of the total armor defined below for the whole object
				material            = -1; // damage material (-1 means "unused")
				name                = "face_hub"; // selection name from hit points LOD in object
				passThrough         = 0.1; // coefficient defining how much damage will pass into total damage when this hit point is damaged
				radius              = 0.08; // size of the hit point sphere, this is how it works: https://community.bistudio.com/wiki/Arma_3_Damage_Description
				explosionShielding  = 0.1; // multiplier of explosive damage (parameter: explosive > 0 in ammunition type)
				minimalHit          = 0.01; // minimal damage value that can be applied (based on armor value), damage below this threshold is ignored
                //example: total hit point armor = 2 and hitpoint class armor = 10 and minimalHit = 0.04  -> all damage below a hit value of 2*10*0.04= 0.8 is ignored
			};
			class HitNeck: HitFace
			{
				armor               = 1;
				material            = -1;
				name                = "neck";
				passThrough         = 0.1;
				radius              = 0.1;
				explosionShielding  = 0.1;
				minimalHit          = 0.01;
			};
			class HitHead: HitNeck
			{
				armor               = 1;
				material            = -1;
				name                = "head";
				passThrough         = 0.1;
				radius              = 0.2;
				explosionShielding  = 0.1;
				minimalHit          = 0.01;
				depends             = "HitFace max HitNeck"; // returns the greater of HitFace and HitNeck.
                // for depends to work, HitHead must be inheriting from HitFace and HitNeck.
                // "max" is not the only operator you can use. + and *  are confirmed working. 
                // Other operators from the https://community.bistudio.com/wiki/Simple_Expression list may be usable as well.
			};
			class HitPelvis
			{
				armor               = 1;
				material            = -1;
				name                = "pelvis";
				passThrough         = 0.1;
				radius              = 0.2;
				explosionShielding  = 0.25;
				visual              = "injury_body";
				minimalHit          = 0.01;
			};
			class HitAbdomen: HitPelvis
			{
				armor               = 1;
				material            = -1;
				name                = "spine1";
				passThrough         = 0.1;
				radius              = 0.15;
				explosionShielding  = 0.25;
				visual              = "injury_body";
				minimalHit          = 0.01;
			};
			class HitDiaphragm: HitAbdomen
			{
				armor               = 1;
				material            = -1;
				name                = "spine2";
				passThrough         = 0.1;
				radius              = 0.15;
				explosionShielding  = 2;
				visual              = "injury_body";
				minimalHit          = 0.01;
			};
			class HitChest: HitDiaphragm
			{
				armor               = 1;
				material            = -1;
				name                = "spine3";
				passThrough         = 0.1;
				radius              = 0.15;
				explosionShielding  = 2;
				visual              = "injury_body";
				minimalHit          = 0.01;
			};
			class HitBody: HitChest
			{
				armor               = 1000; // not supposed to take damage directly
				material            = -1;
				name                = "body";
				passThrough         = 0.1;
				radius              = 0.16;
				explosionShielding  = 2;
				visual              = "injury_body";
				minimalHit          = 0.01;
				depends             = "HitPelvis max HitAbdomen max HitDiaphragm max HitChest"; // depends work only for hit points defined in inheritance chain
                //arbitrary example for different operator usage: = "(2* (HitPelvis + HitAbdomen) * HitDiaphragm) max HitChest";
			};
			class HitArms
			{
				armor               = 1;
				material            = -1;
				name                = "arms";
				passThrough         = 0.1;
				radius              = 0.1;
				explosionShielding  = 0.25;
				visual              = "injury_hands";
				minimalHit          = 0.01;
			};
			class HitHands: HitArms
			{
				armor               = 1;
				material            = -1;
				name                = "hands";
				passThrough         = 0.1;
				radius              = 0.1;
				explosionShielding  = 0.25;
				visual              = "injury_hands";
				minimalHit          = 0.01;
				depends             = "HitArms";
			};
			class HitLegs
			{
				armor               = 1;
				material            = -1;
				name                = "legs";
				passThrough         = 0.1;
				radius              = 0.12;
				explosionShielding  = 0.25;
				visual              = "injury_legs";
				minimalHit          = 0.01;
			};
			
			// ACE
			
			class HitLeftArm
			{
				armor               = 1;
				material            = -1;
				name                = "hand_l";
				passThrough         = 0.1;
				radius              = 0.1;
				explosionShielding  = 0.25;
				visual              = "injury_hands";
				minimalHit          = 0.01;
			};
			class HitRightArm: HitLeftArm
			{
				name                = "hand_r";
			};
			class HitLeftLeg
			{
				armor               = 1;
				material            = -1;
				name                = "leg_l";
				passThrough         = 0.1;
				radius              = 0.1;
				explosionShielding  = 0.25;
				visual              = "injury_hands";
				minimalHit          = 0.01;
			};
			class HitRightLeg: HitLeftLeg
			{
				name                = "leg_r";
			};
		};
	};
};

class cfgWeapons
{
	class HeadgearItem;
	class H_Beret_02;
	class CA_Magazine;
	class Viking_Dunce: H_Beret_02
	{
		displayName="Dunce Cap";
		scope=2;
		mass=2;
		scopeArsenal=2;
		author="Viking Warrior";
		picture="\Viking_Warrior\ARMA_3_Armour\Dunce_cap\Dunce_cap.paa"; //Where is this in relation to the config file?
		model="\Dunce_Cap_Helmet\Dunce_cap.p3d";
		descriptionShort="A Dunce Cap for all the Dunces";
		hiddenSelections[]   											= 
		{
			"camo",
		};
		hiddenSelectionsTextures[]= 
		{
			"\Dunce_Cap_Helmet\Dunce_Cap_Texture.paa",
		};
		class ItemInfo: HeadgearItem
		{				
			uniformModel= "\Dunce_Cap_Helmet\Dunce_cap.p3d";
			hiddenSelections[]=
			{
				"camo",
			};
			hiddenSelectionsTextures[]   								= 
			{
				"\Dunce_Cap_Helmet\Dunce_Cap_Texture.paa",
			};
			ace_hearing_protection = 1.50;  // Protection against deafening (0 to 1, higher means more protection)
			ace_hearing_lowerVolume = 0.10;  // Muffling of the sound (0 to 1, higher means more muffling)
		class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointName 										= "HitHead";
					armor 												= 20;
					passThrough 										= 0.1;
				};
			};
		};
	};
};
