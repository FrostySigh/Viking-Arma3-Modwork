class HeadgearItem: InventoryItem_Base_F
{
	allowedSlots[] = {BACKPACK_SLOT, HEADGEAR_SLOT}; /// defines where can be the cap placed, it is small enough to fit in backpack
	type = HEADGEAR_SLOT;		/// standard slot for the cap is on head
	hiddenSelections[] = {};	/// default caps don't have any changeable selections
	hitpointName = "HitHead";	/// what hitpoint is covered with the cap to have additional protection
};

class H_Test_Headgear: ItemCore
{
	scope = 2; /// scope needs to be 2 to have a visible class
	displayName  = "Dunce Cap"; /// how would the stuff be displayed in inventory and on ground
	picture = "\A3\characters_f\Data\UI\icon_H_Cap_blk_CA.paa"; /// this looks fairly similar
	model   = "\@Test\Dunce_Cap_Helmet\Dunce_Cap.p3d"; /// what model does the cap use

	class ItemInfo: HeadgearItem
	{
		mass = 10; /// combined weight and volume of the cap, this equals to single magazine
		uniformModel = "\Samples_f\Test_Character_01\A3_headgear_example.p3d";	/// what model is used for this cap
		allowedSlots[] = {UNIFORM_SLOT, BACKPACK_SLOT, VEST_SLOT, HEADGEAR_SLOT};	/// this cap is so small and flexible that it fits everywhere
		modelSides[] = {6}; /// available for all sides
		hiddenSelections[] = {"camo"}; /// what selection in model could have different textures
		//subItems[] = {"Integrated_NVG_F"}; //if defined, this headgear item gains functionality (visual modes) of given NVG item and will occupy its slot as well. Currently works only for Headgear + NVG + Radio item combinations.
		
		class HitpointsProtectionInfo
		{
			class Head
			{
				hitpointName	= "HitHead"; // reference to the hit point class defined in the man base class
				armor		= 6; // addition to armor of referenced hitpoint
				passThrough	= 0.5; // multiplier of base passThrough defined in referenced hitpoint
			};
		};
	};
};

class H_Test_Headgear_2: H_Test_Headgear
{
	displayName = "Test headgear (random facewear)";
	allowedFacewear[] =
	{
		/* [facewear1, probability1, facewear2, probability2, ...] */
		"G_Bandanna_aviator", 1, // If every value are the same, it's just a default random, otherwise, weighted random
		"G_Bandanna_beast", 1,
		"G_Bandanna_blk", 1,
		"G_Bandanna_khk", 1,
		"G_Bandanna_oli", 1,
		"G_Bandanna_shades", 1,
		"G_Bandanna_sport", 1,
		"", 1
	};
};

class H_Test_Headgear_Fake
{
	scope = 0;
	allowedFacewear[] =
	{
		"G_Aviator",
		"G_Balaclava_blk",
		"G_Balaclava_oli",
		"G_Bandanna_aviator",
		"G_Bandanna_beast",
		"G_Bandanna_blk",
		"G_Bandanna_khk",
		"G_Bandanna_oli",
		"G_Bandanna_shades",
		"G_Bandanna_sport",
		"G_Bandanna_tan",
		"G_Shades_Black",
		"G_Shades_Blue",
		"G_Shades_Red",
		"G_Shades_Green"
	};
};