#include "../plugin_sdk/plugin_sdk.hpp"
#include "utility.h"
#include "A_Klee.h"


namespace utility
{
	script_spell* q = nullptr;
	script_spell* w = nullptr;
	script_spell* e = nullptr;
	script_spell* r = nullptr;
	//召唤师技能
	script_spell* smite = nullptr;
	script_spell* cleanse = nullptr;
	script_spell* exhaust = nullptr;
	//菜单
	TreeTab* main_tab = nullptr;

	namespace summoner
	{
		TreeEntry* only_show = nullptr;

		TreeEntry* smite = nullptr;
		TreeEntry* use_smite_key = nullptr;
		TreeEntry* use_heal_pred = nullptr;
		TreeEntry* smite_range = nullptr;
		TreeEntry* smite_key = nullptr;
		TreeEntry* smite_draw_range = nullptr;
		//monster
		TreeEntry* baron = nullptr;
		TreeEntry* dragon = nullptr;
		TreeEntry* big_crab = nullptr;
		TreeEntry* small_crab = nullptr;
		TreeEntry* red_buff = nullptr;
		TreeEntry* blue_buff = nullptr;
		TreeEntry* three_wolf = nullptr;
		TreeEntry* stone = nullptr;
		TreeEntry* six_bird = nullptr;
		TreeEntry* gromp = nullptr;
		//monster
		TreeEntry* hotkey_use_baron = nullptr;
		TreeEntry* hotkey_use_dragon = nullptr;
		TreeEntry* hotkey_use_big_crab = nullptr;
		TreeEntry* hotkey_use_small_crab = nullptr;
		TreeEntry* hotkey_use_red_buff = nullptr;
		TreeEntry* hotkey_use_blue_buff = nullptr;
		TreeEntry* hotkey_use_three_wolf = nullptr;
		TreeEntry* hotkey_use_stone = nullptr;
		TreeEntry* hotkey_use_six_bird = nullptr;
		TreeEntry* hotkey_use_gromp = nullptr;
		//seiga
		TreeEntry* smite_siege_minion = nullptr;
		//hero
		TreeEntry* smite_hero_key = nullptr;
		TreeEntry* auto_smite_ks = nullptr;

		TreeEntry* cleanse = nullptr;
		//1
		TreeEntry* cleanse_danger_level_1_alway_use = nullptr;
		TreeEntry* cleanse_danger_level_1_hp = nullptr;
		TreeEntry* cleanse_danger_level_1_enemy_range = nullptr;
		TreeEntry* cleanse_danger_level_1_enemy_count = nullptr;
		TreeEntry* cleanse_danger_level_1_delay = nullptr;
		TreeEntry* cleanse_danger_level_1_duration = nullptr;
		TreeEntry* cleanse_danger_level_1_combo = nullptr;
		TreeEntry* cleanse_danger_level_1_harass = nullptr;
		TreeEntry* cleanse_danger_level_1_other = nullptr;
		//2
		TreeEntry* cleanse_danger_level_2_alway_use = nullptr;
		TreeEntry* cleanse_danger_level_2_hp = nullptr;
		TreeEntry* cleanse_danger_level_2_enemy_range = nullptr;
		TreeEntry* cleanse_danger_level_2_enemy_count = nullptr;
		TreeEntry* cleanse_danger_level_2_delay = nullptr;
		TreeEntry* cleanse_danger_level_2_duration = nullptr;
		TreeEntry* cleanse_danger_level_2_combo = nullptr;
		TreeEntry* cleanse_danger_level_2_harass = nullptr;
		TreeEntry* cleanse_danger_level_2_other = nullptr;
		//3
		TreeEntry* cleanse_danger_level_3_alway_use = nullptr;
		TreeEntry* cleanse_danger_level_3_hp = nullptr;
		TreeEntry* cleanse_danger_level_3_enemy_range = nullptr;
		TreeEntry* cleanse_danger_level_3_enemy_count = nullptr;
		TreeEntry* cleanse_danger_level_3_delay = nullptr;
		TreeEntry* cleanse_danger_level_3_duration = nullptr;
		TreeEntry* cleanse_danger_level_3_combo = nullptr;
		TreeEntry* cleanse_danger_level_3_harass = nullptr;
		TreeEntry* cleanse_danger_level_3_other = nullptr;
		//4
		TreeEntry* cleanse_danger_level_4_alway_use = nullptr;
		TreeEntry* cleanse_danger_level_4_hp = nullptr;
		TreeEntry* cleanse_danger_level_4_enemy_range = nullptr;
		TreeEntry* cleanse_danger_level_4_enemy_count = nullptr;
		TreeEntry* cleanse_danger_level_4_delay = nullptr;
		TreeEntry* cleanse_danger_level_4_duration = nullptr;
		TreeEntry* cleanse_danger_level_4_combo = nullptr;
		TreeEntry* cleanse_danger_level_4_harass = nullptr;
		TreeEntry* cleanse_danger_level_4_other = nullptr;
		//CC
		TreeEntry* Exhaust_cleanse = nullptr;				//虛弱
		TreeEntry* Ignite_cleanse = nullptr;				//點火
		TreeEntry* Slow_cleanse = nullptr;					//減速
		TreeEntry* Snare_cleanse = nullptr;					//禁錮
		TreeEntry* Stun_cleanse = nullptr;					//暈眩
		TreeEntry* Taunt_cleanse = nullptr;					//嘲諷
		TreeEntry* Berserk_cleanse = nullptr;				//狂暴
		TreeEntry* Polymorph_cleanse = nullptr;				//變形
		TreeEntry* Fear_cleanse = nullptr;					//恐懼
		TreeEntry* Charm_cleanse = nullptr;					//魅惑
		TreeEntry* NearSight_cleanse = nullptr;				//近视
		TreeEntry* Blind_cleanse = nullptr;					//盲人
		TreeEntry* Disarm_cleanse = nullptr;				//解除武装
		TreeEntry* Drowsy_cleanse = nullptr;				//昏昏欲睡
		TreeEntry* Asleep_cleanse = nullptr;				//睡覺
		TreeEntry* Silence_cleanse = nullptr;				//沉默

		//虛弱
		TreeEntry* exhaust = nullptr;
		TreeEntry* xayah_e_count = nullptr;
		TreeEntry* twitch_e_count = nullptr;
	}
	namespace item
	{
		TreeEntry* qss = nullptr;
		//CC
		TreeEntry* Slow_qss = nullptr;					//減速
		TreeEntry* Snare_qss = nullptr;					//禁錮
		TreeEntry* Stun_qss = nullptr;					//暈眩
		TreeEntry* Taunt_qss = nullptr;					//嘲諷
		TreeEntry* Berserk_qss = nullptr;				//狂暴
		TreeEntry* Polymorph_qss = nullptr;				//變形
		TreeEntry* Fear_qss = nullptr;					//恐懼
		TreeEntry* Charm_qss = nullptr;					//魅惑
		TreeEntry* Suppression_qss = nullptr;			//壓制
		TreeEntry* NearSight_qss = nullptr;				//近视
		TreeEntry* Blind_qss = nullptr;					//盲人
		TreeEntry* Disarm_qss = nullptr;				//解除武装
		TreeEntry* Drowsy_qss = nullptr;				//昏昏欲睡
		TreeEntry* Asleep_qss = nullptr;				//睡覺
		TreeEntry* Silence_qss = nullptr;				//沉默

		TreeEntry* mikael = nullptr;
		std::map<std::uint32_t, TreeEntry*> mikael_use_on;
		//CC
		TreeEntry* Slow_mikael = nullptr;					//減速
		TreeEntry* Snare_mikael = nullptr;					//禁錮
		TreeEntry* Stun_mikael = nullptr;					//暈眩
		TreeEntry* Taunt_mikael = nullptr;					//嘲諷
		TreeEntry* Berserk_mikael = nullptr;				//狂暴
		TreeEntry* Polymorph_mikael = nullptr;				//變形
		TreeEntry* Fear_mikael = nullptr;					//恐懼
		TreeEntry* Charm_mikael = nullptr;					//魅惑
		TreeEntry* Drowsy_mikael = nullptr;					//昏昏欲睡
		TreeEntry* Asleep_mikael = nullptr;					//睡覺
		TreeEntry* Silence_mikael = nullptr;				//沉默

		TreeEntry* ironspike = nullptr;
		TreeEntry* ironspike_combo = nullptr;
		TreeEntry* ironspike_harass = nullptr;
		TreeEntry* ironspike_lane_clear = nullptr;
		TreeEntry* ironspike_lane_clear_reset_aa = nullptr;
		TreeEntry* ironspike_jungle_clear = nullptr;
		TreeEntry* ironspike_jungle_clear_reset_aa = nullptr;
		TreeEntry* ironspike_fast_lane_clear = nullptr;

		TreeEntry* goredrinker = nullptr;
		TreeEntry* goredrinker_combo_count_hero = nullptr;
		TreeEntry* goredrinker_combo_hp = nullptr;
		TreeEntry* goredrinker_harass = nullptr;
		TreeEntry* goredrinker_lane_clear = nullptr;
		TreeEntry* goredrinker_lane_clear_reset_aa = nullptr;
		TreeEntry* goredrinker_jungle_clear = nullptr;
		TreeEntry* goredrinker_jungle_clear_reset_aa = nullptr;
		TreeEntry* goredrinker_fast_lane_clear = nullptr;
		TreeEntry* goredrinker_auto_use = nullptr;

		TreeEntry* stridebreaker = nullptr;
		TreeEntry* stridebreaker_combo_count_hero = nullptr;
		TreeEntry* stridebreaker_harass = nullptr;
		TreeEntry* stridebreaker_lane_clear = nullptr;
		TreeEntry* stridebreaker_lane_clear_reset_aa = nullptr;
		TreeEntry* stridebreaker_jungle_clear = nullptr;
		TreeEntry* stridebreaker_jungle_clear_reset_aa = nullptr;
		TreeEntry* stridebreaker_fast_lane_clear = nullptr;
		std::map<std::uint32_t, TreeEntry*> stridebreaker_always_use_on;

		TreeEntry* randuins = nullptr;
		std::map<std::uint32_t, TreeEntry*> randuins_always_use_on;

		TreeEntry* gargoyle_stoneplate = nullptr;
		TreeEntry* gargoyle_stoneplate_hp = nullptr;
		TreeEntry* gargoyle_stoneplate_damage = nullptr;
		TreeEntry* gargoyle_stoneplate_damage_hp = nullptr;
	}
	namespace hero
	{
		TreeEntry* taric_e_magnet = nullptr;
		TreeEntry* taric_e_magnet_combo_mode = nullptr;
		TreeEntry* taric_e_magnet_evade = nullptr;
		TreeEntry* taric_e_tower = nullptr;

		TreeEntry* jax_e = nullptr;
		TreeEntry* jax_e_aatrox_p = nullptr;
		TreeEntry* jax_e_camille_q2 = nullptr;
		TreeEntry* jax_e_darius_w = nullptr;
		TreeEntry* jax_e_garen_q = nullptr;
		TreeEntry* jax_e_monkey_q = nullptr;
		TreeEntry* jax_e_renekton_w = nullptr;
		TreeEntry* jax_e_renekton_angry_w = nullptr;
		TreeEntry* jax_e_bear_q = nullptr;
		TreeEntry* jax_e_gold_card = nullptr;

		TreeEntry* cassiopeia_r_dodge = nullptr;

		TreeEntry* xayah_e = nullptr;
	}
	namespace afk
	{
		TreeEntry* afk_mode;
		std::map<std::uint32_t, TreeEntry*> afk_mode_on;
	}
	namespace level_up
	{
		TreeEntry* level_up;
		TreeEntry* level_up_1;
		TreeEntry* level_up_2;
		TreeEntry* level_up_3;
		TreeEntry* level_up_4;
		TreeEntry* level_up_5;
		TreeEntry* level_up_6;
		TreeEntry* level_up_7;
		TreeEntry* level_up_8;
		TreeEntry* level_up_9;
		TreeEntry* force_level_up;
		TreeEntry* force_level_ult;
	}
	namespace dev
	{
		TreeEntry* cd_item;
	}
	namespace draw_settings
	{
		TreeEntry* state_smite = nullptr;
		TreeEntry* state_exhaust = nullptr;
	}
	namespace hotkey
	{
	}

	void on_update();
	void on_draw();
	void on_issue_order(game_object_script& target, vector& pos, _issue_order_type& type, bool* process);
	game_object_script ally_base;
	game_object_script enemy_base;
	void on_after_attack_orbwalker(game_object_script target);
	void on_process_spell_cast(game_object_script sender, spell_instance_script spell);
	void on_create_object(game_object_script sender);
	void on_delete_object(game_object_script sender);

	void afk_logic();
	void level_up_logic();
	void level_up_Priority();
	void buy_cd_item();
	float buy_item_loop;
	//惩戒
	void smite_monster();
	void monster_chose();
	void cast_smite_monster(game_object_script target);
	void semi_smite_hero();
	void auto_smite_ks();
	float smite_semi_key_delay;
	float smite_damage_hero;
	float smite_ks_delay;
	float use_smite_key_loop;
	//淨化
	void cc_logic();
	void clean_cc_logic(float time, float duration, bool use_cleanse, int cleanse_danger, bool use_qss, int qss_danger, bool use_mikael, game_object_script target, int mikael_danger);
	void cast_qss();
	float cc_time_loop = 0.0f;
	float cc_clean_loop = 0.0f;
	float Exhaust_time;
	float Ignite_time;
	float CombatDehancer_time;		//虛弱
	float Slow_time;				//減速
	float AttackSpeedSlow_time;		//攻速降低
	float Snare_time;				//禁錮
	float Stun_time;				//暈眩
	float Taunt_time;				//嘲諷
	float Berserk_time;				//狂暴
	float Polymorph_time;			//變形
	float Fear_time;				//恐懼
	float Flee_time;				//逃跑
	float Charm_time;				//魅惑
	float Poison_time;				//毒药
	float Suppression_time;			//壓制
	float NearSight_time;			//近视
	float Blind_time;				//盲人
	float Disarm_time;				//解除武装
	float Knockup_time;				//擊飛
	float Knockback_time;			//推開
	float Drowsy_time;				//昏昏欲睡
	float Asleep_time;				//睡覺
	float Silence_time;				//沉默

	class Item {
	public:
		Item(ItemId id, float range) : _id(id), _range(range) {}
		bool is_ready() {
			return myhero->is_item_ready(_id);
		}
		void cast(game_object_script target) {
			if (is_ready()) {
				auto slot = myhero->has_item(_id);
				if (slot != spellslot::invalid && target->get_distance(myhero) <= _range) {
					myhero->cast_spell(slot, target);
				}
			}
		}
		void cast() {
			if (is_ready()) {
				auto slot = myhero->has_item(_id);
				if (slot != spellslot::invalid) {
					myhero->cast_spell(slot);
				}
			}
		}
		void cast(vector vec) {
			if (is_ready()) {
				auto slot = myhero->has_item(_id);
				if (slot != spellslot::invalid) {
					myhero->cast_spell(slot, vec);
				}
			}
		}

	private:
		ItemId _id;
		float _range;
	};

	//鐵刺
	void use_ironspike();
	//渴血
	void use_goredrinker();
	//挺進
	void use_stridebreaker();
	//石像鬼
	void use_gargoyle_stoneplate();
	float gargoyle_stoneplate_shield;
	//蘭頓
	void use_randuins();

	//taric
	float taric_last_e_time;
	auto taric_e_115_pos = vector(0, 0, 0);
	float e_115_distance;
	auto taric_e_230_pos = vector(0, 0, 0);
	float e_230_distance;
	auto taric_e_345_pos = vector(0, 0, 0);
	float e_345_distance;
	auto taric_e_460_pos = vector(0, 0, 0);
	float e_460_distance;
	auto taric_e_575_pos = vector(0, 0, 0);
	float e_575_distance;
	void taric_e_logic();

	//cassiopeia
	auto cassiopeia_start_pos = vector(0, 0, 0);
	auto cassiopeia_end_pos = vector(0, 0, 0);
	float cassiopeia_r_time;
	void cassiopeia_r_dodge_logic();

	//xayah
	int count_xayah_e();
	float xayah_use_e;

	//twitch
	int count_twitch_e;
	float twitch_use_e;

	//evade
	bool previous_evade_state;

	//orb
	bool orb_check = true;


	bool Afk_state = true;
	float Afk_delay = 0;

	struct lantern
	{
		game_object_script object;
		int lantern_id;
		float start_time;
		float expire_time;

		lantern(game_object_script obj, int id)
		{
			object = obj;
			lantern_id = id;
			start_time = gametime->get_time();
			expire_time = gametime->get_time() + 4.0f;
		}
	};
	std::vector<lantern> lanterns;

	struct xayah_e
	{
		game_object_script object;
		int xayah_id;
		float start_time;
		float expire_time;

		xayah_e(game_object_script obj, int id)
		{
			object = obj;
			xayah_id = id;
			start_time = gametime->get_time();
			expire_time = gametime->get_time() + 6.0f;
		}
	};
	std::vector<xayah_e> xayah_es;

	float lantern_time;

	void load()
	{
		if (language_info* lang = translation->add_language("cn", "CN"))
		{
			A_Klee::loadTranslation();
		}

		const auto icon = draw_manager->load_texture_from_file(L"Klee/klee.png");
		const auto goredrinker_icon = draw_manager->load_texture_from_file(L"Klee/goredrinker.png");
		const auto smite_icon = draw_manager->load_texture_from_file(L"Klee/smite.png");
		const auto gargoyle_stoneplate_icon = draw_manager->load_texture_from_file(L"Klee/gargoyle_stoneplate.png");
		const auto jax_icon = draw_manager->load_texture_from_file(L"Klee/jax.png");
		const auto taric_icon = draw_manager->load_texture_from_file(L"Klee/taric.png");
		const auto qss_icon = draw_manager->load_texture_from_file(L"Klee/qss.png");
		const auto cleanse_icon = draw_manager->load_texture_from_file(L"Klee/cleanse.png");
		//const auto heal_icon = draw_manager->load_texture_from_file(L"Klee/heal.png");
		//const auto barrier_icon = draw_manager->load_texture_from_file(L"Klee/barrier.png");
		//const auto exhaust_icon = draw_manager->load_texture_from_file(L"Klee/exhaust.png");
		//const auto ignite_icon = draw_manager->load_texture_from_file(L"Klee/ignite.png");
		const auto stridebreaker_icon = draw_manager->load_texture_from_file(L"Klee/stridebreaker.png");
		const auto ironspike_icon = draw_manager->load_texture_from_file(L"Klee/ironspike.png");
		const auto mikael_icon = draw_manager->load_texture_from_file(L"Klee/mikael.png");
		const auto randuin_icon = draw_manager->load_texture_from_file(L"Klee/randuin.png");

		q = plugin_sdk->register_spell(spellslot::q, 0);
		w = plugin_sdk->register_spell(spellslot::w, 0);
		e = plugin_sdk->register_spell(spellslot::e, 0);
		r = plugin_sdk->register_spell(spellslot::r, 0);

		q->set_spell_lock(false);
		w->set_spell_lock(false);
		e->set_spell_lock(false);
		r->set_spell_lock(false);

		main_tab = menu->create_tab("utility", "Klee Utility");
		main_tab->set_texture(icon->texture);
		{
			main_tab->add_separator("klee_utility", " ~ ~ Klee Utility ~ ~ ");

			auto qss_cleanse = main_tab->add_tab("qss_cleanse", "Cleanse/Qss/Mikael");
			{
				qss_cleanse->set_texture(cleanse_icon->texture);
				qss_cleanse->add_separator("qss_cleanse_setting", " ~ ~ Setting ~ ~ ");
				//qss_cleanse->set_revert_enabled(true);
				auto item_mikael = qss_cleanse->add_tab("mikael", "Mikael");
				{
					item_mikael->set_texture(mikael_icon->texture);
					item_mikael->add_separator("mikael", " ~ ~ Mikael ~ ~ ");
					item::mikael = item_mikael->add_checkbox("use_mikael", "Mikael", true);
					item_mikael->set_assigned_active(item::mikael);

					item_mikael->add_separator("cleanse_setting1", "Mikael use on");
					for (auto& ally : entitylist->get_ally_heroes())
					{
						if (!ally->is_me())
						{
							item::mikael_use_on[ally->get_network_id()] = item_mikael->add_checkbox(std::to_string(ally->get_network_id()), ally->get_model(), true, false);
							item::mikael_use_on[ally->get_network_id()]->set_texture(ally->get_square_icon_portrait());
						}
					}

					item_mikael->add_separator("mikael_setting2", " ~ ~ Mikael setting ~ ~ ");

					item::Berserk_mikael = item_mikael->add_slider("Berserk_mikael", "Danger level : Berserk", 4, 0, 4);
					item::Stun_mikael = item_mikael->add_slider("Stun_mikael", "Danger level : Stun", 3, 0, 4);
					item::Taunt_mikael = item_mikael->add_slider("Taunt_mikael", "Danger level : Taunt", 3, 0, 4);
					item::Polymorph_mikael = item_mikael->add_slider("Polymorph_mikael", "Danger level : Polymorph", 3, 0, 4);
					item::Fear_mikael = item_mikael->add_slider("Fear_mikael", "Danger level : Fear", 3, 0, 4);
					item::Charm_mikael = item_mikael->add_slider("Charm_mikael", "Danger level : Charm", 3, 0, 4);
					item::Drowsy_mikael = item_mikael->add_slider("Drowsy_mikael", "Danger level : Drowsy", 3, 0, 4);
					item::Asleep_mikael = item_mikael->add_slider("Asleep_mikael", "Danger level : Asleep", 3, 0, 4);
					item::Snare_mikael = item_mikael->add_slider("Snare_mikael", "Danger level : Snare", 2, 0, 4);
					item::Slow_mikael = item_mikael->add_slider("Slow_mikael", "Danger level : Slow", 1, 0, 4);
					item::Silence_mikael = item_mikael->add_slider("Silence_mikael", "Danger level : Silence", 0, 0, 4);
				}
				auto summoner_cleanse = qss_cleanse->add_tab("cleanse", "Cleanse");
				{
					summoner_cleanse->set_texture(cleanse_icon->texture);
					summoner_cleanse->add_separator("cleanse", " ~ ~ Cleanse ~ ~ ");
					summoner::cleanse = summoner_cleanse->add_checkbox("use_cleanse", "Cleanse", true);
					summoner_cleanse->set_assigned_active(summoner::cleanse);

					summoner_cleanse->add_separator("cleanse_setting", " ~ ~ Cleanse setting ~ ~ ");
					summoner::Exhaust_cleanse = summoner_cleanse->add_slider("Exhaust_cleanse", "Danger level : Exhaust", 2, 0, 4);
					summoner::Ignite_cleanse = summoner_cleanse->add_slider("Ignite_cleanse", "Danger level : Ignite", 2, 0, 4);
					summoner::Berserk_cleanse = summoner_cleanse->add_slider("Berserk_cleanse", "Danger level : Berserk", 4, 0, 4);
					summoner::Stun_cleanse = summoner_cleanse->add_slider("Stun_cleanse", "Danger level : Stun", 3, 0, 4);
					summoner::Taunt_cleanse = summoner_cleanse->add_slider("Taunt_cleanse", "Danger level : Taunt", 3, 0, 4);
					summoner::Polymorph_cleanse = summoner_cleanse->add_slider("Polymorph_cleanse", "Danger level : Polymorph", 3, 0, 4);
					summoner::Fear_cleanse = summoner_cleanse->add_slider("Fear_cleanse", "Danger level : Fear", 3, 0, 4);
					summoner::Charm_cleanse = summoner_cleanse->add_slider("Charm_cleanse", "Danger level : Charm", 3, 0, 4);
					summoner::Drowsy_cleanse = summoner_cleanse->add_slider("Drowsy_cleanse", "Danger level : Drowsy", 3, 0, 4);
					summoner::Asleep_cleanse = summoner_cleanse->add_slider("Asleep_cleanse", "Danger level : Asleep", 3, 0, 4);
					summoner::Snare_cleanse = summoner_cleanse->add_slider("Snare_cleanse", "Danger level : Snare", 2, 0, 4);
					summoner::Slow_cleanse = summoner_cleanse->add_slider("Slow_cleanse", "Danger level : Slow", 1, 0, 4);
					summoner::Blind_cleanse = summoner_cleanse->add_slider("Blind_cleanse", "Danger level : Blind", 1, 0, 4);
					summoner::Disarm_cleanse = summoner_cleanse->add_slider("Disarm_cleanse", "Danger level : Disarm", 1, 0, 4);
					summoner::Silence_cleanse = summoner_cleanse->add_slider("Silence_cleanse", "Danger level : Silence", 0, 0, 4);
					summoner::NearSight_cleanse = summoner_cleanse->add_slider("NearSight_cleanse", "Danger level : NearSight", 0, 0, 4);
					if (myhero->get_spell(spellslot::summoner1)->get_spell_data()->get_name_hash() == spell_hash("SummonerBoost"))
					{
						summoner_cleanse->set_texture(myhero->get_spell(spellslot::summoner1)->get_icon_texture());
					}
					else if (myhero->get_spell(spellslot::summoner2)->get_spell_data()->get_name_hash() == spell_hash("SummonerBoost"))
					{
						summoner_cleanse->set_texture(myhero->get_spell(spellslot::summoner2)->get_icon_texture());
					}
				}
				auto item_qss = qss_cleanse->add_tab("qss", "Qss");
				{
					item_qss->set_texture(qss_icon->texture);
					item_qss->add_separator("qss", " ~ ~ Qss ~ ~ ");
					item::qss = item_qss->add_checkbox("use_qss", "Qss", true);
					item_qss->set_assigned_active(item::qss);

					item_qss->add_separator("cleanse_setting", " ~ ~ Qss setting ~ ~ ");

					item::Berserk_qss = item_qss->add_slider("Berserk_qss", "Danger level : Berserk", 4, 0, 4);
					item::Suppression_qss = item_qss->add_slider("Suppression_qss", "Danger level : Suppression", 4, 0, 4);
					item::Stun_qss = item_qss->add_slider("Stun_qss", "Danger level : Stun", 3, 0, 4);
					item::Taunt_qss = item_qss->add_slider("Taunt_qss", "Danger level : Taunt", 3, 0, 4);
					item::Polymorph_qss = item_qss->add_slider("Polymorph_qss", "Danger level : Polymorph", 3, 0, 4);
					item::Fear_qss = item_qss->add_slider("Fear_qss", "Danger level : Fear", 3, 0, 4);
					item::Charm_qss = item_qss->add_slider("Charm_qss", "Danger level : Charm", 3, 0, 4);
					item::Drowsy_qss = item_qss->add_slider("Drowsy_qss", "Danger level : Drowsy", 3, 0, 4);
					item::Asleep_qss = item_qss->add_slider("Asleep_qss", "Danger level : Asleep", 3, 0, 4);
					item::Snare_qss = item_qss->add_slider("Snare_qss", "Danger level : Snare", 2, 0, 4);
					item::Slow_qss = item_qss->add_slider("Slow_qss", "Danger level : Slow", 1, 0, 4);
					item::Blind_qss = item_qss->add_slider("Blind_qss", "Danger level : Blind", 1, 0, 4);
					item::Disarm_qss = item_qss->add_slider("Disarm_qss", "Danger level : Disarm", 1, 0, 4);
					item::Silence_qss = item_qss->add_slider("Silence_qss", "Danger level : Silence", 0, 0, 4);
					item::NearSight_qss = item_qss->add_slider("NearSight_qss", "Danger level : NearSight", 0, 0, 4);
				}
				auto cleanse_danger = qss_cleanse->add_tab("cleanse_danger", "Danger level setting");
				{
					cleanse_danger->add_separator("cleanse_danger", " ~ ~ Danger Level ~ ~ ");
					auto cleanse_danger_0 = cleanse_danger->add_tab("cleanse_danger_0", "Danger level 0");
					{
						cleanse_danger_0->add_separator("cleanse_danger_0_1", "Danger level 0 = Disable");
					}
					auto cleanse_danger_1 = cleanse_danger->add_tab("cleanse_danger_1", "Danger level 1");
					{
						summoner::cleanse_danger_level_1_alway_use = cleanse_danger_1->add_checkbox("alway_use", "Alway use", false);
						summoner::cleanse_danger_level_1_delay = cleanse_danger_1->add_slider("cleanse_danger_level_1_delay", "Delay x ms", 200, 0, 1000);
						summoner::cleanse_danger_level_1_hp = cleanse_danger_1->add_slider("cleanse_danger_level_1_hp", "Hp <= x %", 40, 0, 100);
						summoner::cleanse_danger_level_1_enemy_range = cleanse_danger_1->add_slider("cleanse_danger_level_1_enemy_range", "When x range", 500, 0, 1000);
						summoner::cleanse_danger_level_1_enemy_count = cleanse_danger_1->add_slider("cleanse_danger_level_1_enemy_count", " ^- >= x enemy", 2, 1, 5);
						summoner::cleanse_danger_level_1_duration = cleanse_danger_1->add_slider("cleanse_danger_level_1_duration", "CC duration >= x ms", 1001, 0, 2000);
						summoner::cleanse_danger_level_1_combo = cleanse_danger_1->add_checkbox("cleanse_danger_level_1_combo", "Use on combo mode", true);
						summoner::cleanse_danger_level_1_harass = cleanse_danger_1->add_checkbox("cleanse_danger_level_1_harass", "Use on harass mode", false);
						summoner::cleanse_danger_level_1_other = cleanse_danger_1->add_checkbox("cleanse_danger_level_1_other", "Use on other mode", false);
					}
					auto cleanse_danger_2 = cleanse_danger->add_tab("cleanse_danger_2", "Danger level 2");
					{
						summoner::cleanse_danger_level_2_alway_use = cleanse_danger_2->add_checkbox("alway_use", "Alway use", false);
						summoner::cleanse_danger_level_2_delay = cleanse_danger_2->add_slider("cleanse_danger_level_2_delay", "Delay x ms", 100, 0, 1000);
						summoner::cleanse_danger_level_2_hp = cleanse_danger_2->add_slider("cleanse_danger_level_2_hp", "Hp <= x %", 70, 0, 100);
						summoner::cleanse_danger_level_2_enemy_range = cleanse_danger_2->add_slider("cleanse_danger_level_2_enemy_range", "When x range", 500, 0, 1000);
						summoner::cleanse_danger_level_2_enemy_count = cleanse_danger_2->add_slider("cleanse_danger_level_2_enemy_count", " ^- >= x enemy", 2, 1, 5);
						summoner::cleanse_danger_level_2_duration = cleanse_danger_2->add_slider("cleanse_danger_level_2_duration", "CC duration >= x ms", 700, 0, 2000);
						summoner::cleanse_danger_level_2_combo = cleanse_danger_2->add_checkbox("cleanse_danger_level_2_combo", "Use on combo mode", true);
						summoner::cleanse_danger_level_2_harass = cleanse_danger_2->add_checkbox("cleanse_danger_level_2_harass", "Use on harass mode", true);
						summoner::cleanse_danger_level_2_other = cleanse_danger_2->add_checkbox("cleanse_danger_level_2_other", "Use on other mode", false);
					}
					auto cleanse_danger_3 = cleanse_danger->add_tab("cleanse_danger_3", "Danger level 3");
					{
						summoner::cleanse_danger_level_3_alway_use = cleanse_danger_3->add_checkbox("alway_use", "Alway use", false);
						summoner::cleanse_danger_level_3_delay = cleanse_danger_3->add_slider("cleanse_danger_level_3_delay", "Delay x ms", 50, 0, 1000);
						summoner::cleanse_danger_level_3_hp = cleanse_danger_3->add_slider("cleanse_danger_level_3_hp", "Hp <= x %", 90, 0, 100);
						summoner::cleanse_danger_level_3_enemy_range = cleanse_danger_3->add_slider("cleanse_danger_level_3_enemy_range", "When x range", 500, 0, 1000);
						summoner::cleanse_danger_level_3_enemy_count = cleanse_danger_3->add_slider("cleanse_danger_level_3_enemy_count", " ^- >= x enemy", 1, 1, 5);
						summoner::cleanse_danger_level_3_duration = cleanse_danger_3->add_slider("cleanse_danger_level_3_duration", "CC duration >= x ms", 400, 0, 2000);
						summoner::cleanse_danger_level_3_combo = cleanse_danger_3->add_checkbox("cleanse_danger_level_3_combo", "Use on combo mode", true);
						summoner::cleanse_danger_level_3_harass = cleanse_danger_3->add_checkbox("cleanse_danger_level_3_harass", "Use on harass mode", true);
						summoner::cleanse_danger_level_3_other = cleanse_danger_3->add_checkbox("cleanse_danger_level_3_other", "Use on other mode", true);
					}
					auto cleanse_danger_4 = cleanse_danger->add_tab("cleanse_danger_4", "Danger level 4");
					{
						summoner::cleanse_danger_level_4_alway_use = cleanse_danger_4->add_checkbox("alway_use", "Alway use", true);
						summoner::cleanse_danger_level_4_delay = cleanse_danger_4->add_slider("cleanse_danger_level_4_delay", "Delay x ms", 0, 0, 1000);
						summoner::cleanse_danger_level_4_hp = cleanse_danger_4->add_slider("cleanse_danger_level_4_hp", "Hp <= x %", 100, 0, 100);
						summoner::cleanse_danger_level_4_enemy_range = cleanse_danger_4->add_slider("cleanse_danger_level_4_enemy_range", "When x range", 500, 0, 1000);
						summoner::cleanse_danger_level_4_enemy_count = cleanse_danger_4->add_slider("cleanse_danger_level_4_enemy_count", " ^- >= x enemy", 1, 1, 5);
						summoner::cleanse_danger_level_4_duration = cleanse_danger_4->add_slider("cleanse_danger_level_4_duration", "CC duration x ms", 0, 0, 2000);
						summoner::cleanse_danger_level_4_combo = cleanse_danger_4->add_checkbox("cleanse_danger_level_4_combo", "Use on combo mode", true);
						summoner::cleanse_danger_level_4_harass = cleanse_danger_4->add_checkbox("cleanse_danger_level_4_harass", "Use on harass mode", true);
						summoner::cleanse_danger_level_4_other = cleanse_danger_4->add_checkbox("cleanse_danger_level_4_other", "Use on other mode", true);
					}
				}
			}

			auto summoner = main_tab->add_tab("summoner", "Summoner");
			{
				summoner->add_separator("summoner_spell", " ~ ~ Summoner spell ~ ~ ");

				auto summoner_smite = summoner->add_tab("summoner_smite", "Smite");
				{
					summoner_smite->set_texture(smite_icon->texture);
					summoner_smite->add_separator("smite_monster", " ~ ~ Smite ~ ~ ");
					summoner::smite = summoner_smite->add_checkbox("smite", "Smite", true, true);
					summoner::use_smite_key = summoner_smite->add_hotkey("use_smite_key", " ^- Use smite key", TreeHotkeyMode::Hold, '9', false);
					summoner::use_heal_pred = summoner_smite->add_checkbox("use_heal_pred", "Smite use health prediction", false, true);
					summoner_smite->add_separator("smite_monster1", " ~ ~ Monster ~ ~ ");
					auto use_smite_black_list = summoner_smite->add_tab("use_smite_black_list", "Use monster");
					{
						summoner::baron = use_smite_black_list->add_checkbox("smite_baron", "Baron", true, true);
						summoner::dragon = use_smite_black_list->add_checkbox("smite_dragon", "Dragon", true, true);
						summoner::big_crab = use_smite_black_list->add_checkbox("smite_big_crab", "Rift Herald", true, true);
						summoner::small_crab = use_smite_black_list->add_checkbox("smite_small_crab", "Small Crab", true, true);
						summoner::red_buff = use_smite_black_list->add_checkbox("smite_red_buff", "Red Buff", true, true);
						summoner::blue_buff = use_smite_black_list->add_checkbox("smite_blue_buff", "Blue Buff", true, true);
						summoner::three_wolf = use_smite_black_list->add_checkbox("smite_three_wolf", "Three Wolf", true, true);
						summoner::stone = use_smite_black_list->add_checkbox("smite_stone", "Stone", true, true);
						summoner::six_bird = use_smite_black_list->add_checkbox("smite_six_bird", "Six Bird", true, true);
						summoner::gromp = use_smite_black_list->add_checkbox("smite_gromp", "Gromp", true, true);
					}

					summoner::smite_range = summoner_smite->add_slider("smite_range", "Use smite when enemy <= x range (0 = disable)", 0, 0, 1000);
					summoner_smite->set_assigned_active(summoner::smite);
					summoner::smite_key = summoner_smite->add_hotkey("smite_key", "Monster selector key", TreeHotkeyMode::Hold, 'F', false);
					auto hotkey_use_smite_key = summoner_smite->add_tab("dont_use_smite_key", " ^- Use selector hotkey monster");
					{
						summoner::hotkey_use_baron = hotkey_use_smite_key->add_checkbox("hotkey_smite_baron", "Baron", true, true);
						summoner::hotkey_use_dragon = hotkey_use_smite_key->add_checkbox("hotkey_smite_dragon", "Dragon", true, true);
						summoner::hotkey_use_big_crab = hotkey_use_smite_key->add_checkbox("hotkey_smite_big_crab", "Rift Herald", true, true);
						summoner::hotkey_use_small_crab = hotkey_use_smite_key->add_checkbox("hotkey_smite_small_crab", "Small Crab", true, true);
						summoner::hotkey_use_red_buff = hotkey_use_smite_key->add_checkbox("hotkey_smite_red_buff", "Red Buff", true, true);
						summoner::hotkey_use_blue_buff = hotkey_use_smite_key->add_checkbox("hotkey_smite_blue_buff", "Blue Buff", true, true);
						summoner::hotkey_use_three_wolf = hotkey_use_smite_key->add_checkbox("hotkey_smite_three_wolf", "Three Wolf", true, true);
						summoner::hotkey_use_stone = hotkey_use_smite_key->add_checkbox("hotkey_smite_stone", "Stone", true, true);
						summoner::hotkey_use_six_bird = hotkey_use_smite_key->add_checkbox("hotkey_smite_six_bird", "Six Bird", true, true);
						summoner::hotkey_use_gromp = hotkey_use_smite_key->add_checkbox("hotkey_smite_gromp", "Gromp", true, true);
					}
					summoner::smite_draw_range = summoner_smite->add_slider("smite_draw_range", " ^- Hotkey Smite range", 560, 300, 560);

					summoner_smite->add_separator("smite_hero", " ~ ~ Smite Hero ~ ~ ");

					summoner::smite_hero_key = summoner_smite->add_hotkey("smite_hero_key", "Semi smite hero", TreeHotkeyMode::Hold, 'F', false);
					summoner::auto_smite_ks = summoner_smite->add_checkbox("auto_smite_ks", "Auto smite ks", true, true);

					summoner_smite->add_separator("Warning", " ~ ~ Warning ~ ~ ");
					summoner_smite->add_separator("Warning1", "  Using this feature may make your teammates AFK  ");
					summoner::smite_siege_minion = summoner_smite->add_checkbox("smite_siege_minion", "Smite siege minion", false, true);
				}

				auto summoner_exhaust = summoner->add_tab("summoner_exhaust", "Exhausr");
				{
					summoner::exhaust = summoner_exhaust->add_hotkey("exhaust_key", "Use Exhaust", TreeHotkeyMode::Toggle, 'F', true);
					summoner_exhaust->set_assigned_active(summoner::exhaust);
					summoner::twitch_e_count = summoner_exhaust->add_slider("exhaust_twitch", "Twitch's E >= x", 5, 1, 6);
					summoner::xayah_e_count = summoner_exhaust->add_slider("exhaust_xayah", "Xayah's E >= x", 5, 1, 20);
				}

				summoner::only_show = summoner->add_checkbox("only_show", "Show all", true, false);
			}

			auto item = main_tab->add_tab("item", "Item");
			{
				item->add_separator("item", " ~ ~ Item ~ ~ ");

				auto ironspike = item->add_tab("ironspike", "Ironspike");
				{
					ironspike->set_texture(ironspike_icon->texture);
					ironspike->add_separator("ironspike", " ~ ~ Ironspike ~ ~ ");
					item::ironspike = ironspike->add_checkbox("use_ironspike", "Ironspike", true);
					ironspike->set_assigned_active(item::ironspike);
					ironspike->add_separator("ironspike_1", " ~ ~ Combo ~ ~ ");
					item::ironspike_combo = ironspike->add_checkbox("ironspike_combo", "Use ironspike combo", true);
					ironspike->add_separator("ironspike_5", " ~ ~ Harass ~ ~ ");
					item::ironspike_harass = ironspike->add_checkbox("ironspike_harass", "Use ironspike harass", true);
					ironspike->add_separator("ironspike_2", " ~ ~ LaneClear ~ ~ ");
					item::ironspike_lane_clear = ironspike->add_slider("ironspike_lane_clear", "Use ironspike >= x minion", 5, 1, 10);
					item::ironspike_lane_clear_reset_aa = ironspike->add_slider("ironspike_lane_clear_reset_aa", "Use ironspike >= x minion (after aa)", 3, 1, 10);
					item::ironspike_jungle_clear = ironspike->add_slider("ironspike_jungle_clear", "Use ironspike >= x monster", 2, 1, 10);
					item::ironspike_jungle_clear_reset_aa = ironspike->add_slider("ironspike_jungle_clear_reset_aa", "Use ironspike >= x monster (after aa)", 1, 1, 10);
					ironspike->add_separator("ironspike_3", " ~ ~ Fast LaneClear ~ ~ ");
					item::ironspike_fast_lane_clear = ironspike->add_checkbox("ironspike_fast_lane_clear", "Use ironspike fast laneclear", true);
				}

				auto stridebreaker = item->add_tab("stridebreaker", "Stridebreaker");
				{
					stridebreaker->set_texture(stridebreaker_icon->texture);
					stridebreaker->add_separator("stridebreaker", " ~ ~ Stridebreaker ~ ~ ");
					item::stridebreaker = stridebreaker->add_checkbox("use_stridebreaker", "Stridebreaker", true);
					stridebreaker->set_assigned_active(item::stridebreaker);
					stridebreaker->add_separator("stridebreaker_1", " ~ ~ Combo ~ ~ ");
					item::stridebreaker_combo_count_hero = stridebreaker->add_slider("stridebreaker_combo_count_hero", "Use stridebreaker >= x hero", 2, 1, 6);
					stridebreaker->add_separator("stridebreaker_5", " ~ ~ Harass ~ ~ ");
					item::stridebreaker_harass = stridebreaker->add_checkbox("stridebreaker_harass", "Use stridebreaker harass", true);
					stridebreaker->add_separator("stridebreaker_2", " ~ ~ LaneClear ~ ~ ");
					item::stridebreaker_lane_clear = stridebreaker->add_slider("stridebreaker_lane_clear", "Use stridebreaker >= x minion", 5, 1, 10);
					item::stridebreaker_lane_clear_reset_aa = stridebreaker->add_slider("stridebreaker_lane_clear_reset_aa", "Use stridebreaker >= x minion (after aa)", 3, 1, 10);
					item::stridebreaker_jungle_clear = stridebreaker->add_slider("stridebreaker_jungle_clear", "Use stridebreaker >= x monster", 2, 1, 10);
					item::stridebreaker_jungle_clear_reset_aa = stridebreaker->add_slider("stridebreaker_jungle_clear_reset_aa", "Use stridebreaker >= x monster (after aa)", 1, 1, 10);
					stridebreaker->add_separator("stridebreaker_3", " ~ ~ Fast LaneClear ~ ~ ");
					item::stridebreaker_fast_lane_clear = stridebreaker->add_checkbox("stridebreaker_fast_lane_clear", "Use stridebreaker fast laneclear", true);
					stridebreaker->add_separator("stridebreaker_4", " ~ ~ Auto use on ~ ~ ");
					for (auto& enemy : entitylist->get_enemy_heroes())
					{
						item::stridebreaker_always_use_on[enemy->get_network_id()] = stridebreaker->add_checkbox(std::to_string(enemy->get_network_id()), enemy->get_model(), false, true);
						item::stridebreaker_always_use_on[enemy->get_network_id()]->set_texture(enemy->get_square_icon_portrait());
					}
				}

				auto goredrinker = item->add_tab("goredrinker", "Goredrinker");
				{
					goredrinker->set_texture(goredrinker_icon->texture);
					goredrinker->add_separator("goredrinker", " ~ ~ Goredrinker ~ ~ ");
					item::goredrinker = goredrinker->add_checkbox("use_goredrinker", "Goredrinker", true);
					goredrinker->set_assigned_active(item::goredrinker);
					goredrinker->add_separator("goredrinker_1", " ~ ~ Combo ~ ~ ");
					item::goredrinker_combo_count_hero = goredrinker->add_slider("goredrinker_combo_count_hero", "Use Goredrinker >= x hero", 2, 1, 6);
					item::goredrinker_combo_hp = goredrinker->add_slider("goredrinker_combo_hp", "Use Goredrinker <= x% hp", 30, 0, 100);
					goredrinker->add_separator("goredrinker_5", " ~ ~ Harass ~ ~ ");
					item::goredrinker_harass = goredrinker->add_checkbox("goredrinker_harass", "Use Goredrinker harass", true);
					goredrinker->add_separator("goredrinker_2", " ~ ~ LaneClear ~ ~ ");
					item::goredrinker_lane_clear = goredrinker->add_slider("goredrinker_lane_clear", "Use Goredrinker >= x minion", 5, 1, 10);
					item::goredrinker_lane_clear_reset_aa = goredrinker->add_slider("goredrinker_lane_clear_reset_aa", "Use Goredrinker >= x minion (after aa)", 3, 1, 10);
					item::goredrinker_jungle_clear = goredrinker->add_slider("goredrinker_jungle_clear", "Use Goredrinker >= x monster", 2, 1, 10);
					item::goredrinker_jungle_clear_reset_aa = goredrinker->add_slider("goredrinker_jungle_clear_reset_aa", "Use Goredrinker >= x monster (after aa)", 1, 1, 10);
					goredrinker->add_separator("goredrinker_3", " ~ ~ Fast LaneClear ~ ~ ");
					item::goredrinker_fast_lane_clear = goredrinker->add_checkbox("goredrinker_fast_lane_clear", "Use Goredrinker fast laneclear", true);
					goredrinker->add_separator("goredrinker_4", " ~ ~ Auto ~ ~ ");
					item::goredrinker_auto_use = goredrinker->add_slider("goredrinker_auto_use", "Auto Goredrinker >= x hero", 3, 1, 6);
				}

				auto gargoyle_stoneplate = item->add_tab("gargoyle_stoneplate", "Gargoyle Stoneplate");
				{
					gargoyle_stoneplate->set_texture(gargoyle_stoneplate_icon->texture);
					gargoyle_stoneplate->add_separator("gargoyle_stoneplate", " ~ ~ Gargoyle Stoneplate ~ ~ ");
					item::gargoyle_stoneplate = gargoyle_stoneplate->add_checkbox("use_gargoyle_stoneplate", "Gargoyle Stoneplate", true);
					gargoyle_stoneplate->set_assigned_active(item::gargoyle_stoneplate);
					gargoyle_stoneplate->add_separator("gargoyle_stoneplate_1", " ~ ~ Auto ~ ~ ");
					item::gargoyle_stoneplate_hp = gargoyle_stoneplate->add_slider("gargoyle_stoneplate_hp", "Use Gargoyle Stoneplate <= x% hp", 15, 0, 50);
					item::gargoyle_stoneplate_damage = gargoyle_stoneplate->add_slider("gargoyle_stoneplate_damage", "Use Gargoyle Stoneplate incoming damage >= x% Gargoyle Stoneplate shield", 80, 0, 100);
					item::gargoyle_stoneplate_damage_hp = gargoyle_stoneplate->add_slider("gargoyle_stoneplate_damage_hp", " ^- Only <= x % hp", 30, 0, 100);
				}

				auto randuins = item->add_tab("randuins", "Randuins");
				{
					randuins->set_texture(randuin_icon->texture);
					randuins->add_separator("randuins", " ~ ~ Randuins ~ ~ ");
					item::randuins = randuins->add_checkbox("use_randuins", "Randuins", true);
					randuins->set_assigned_active(item::randuins);
					randuins->add_separator("randuins_1", " ~ ~ Auto use on ~ ~ ");
					for (auto& enemy : entitylist->get_enemy_heroes())
					{
						item::randuins_always_use_on[enemy->get_network_id()] = randuins->add_checkbox(std::to_string(enemy->get_network_id()), enemy->get_model(), false, true);
						item::randuins_always_use_on[enemy->get_network_id()]->set_texture(enemy->get_square_icon_portrait());
					}
				}
			}

			auto hero = main_tab->add_tab("hero", "Hero");
			{
				hero->add_separator("hero", " ~ ~ Hero ~ ~ ");

				auto taric = hero->add_tab("hero_taric", "Taric");
				{
					taric->set_texture(taric_icon->texture);
					hero::taric_e_magnet = taric->add_checkbox("taric_e_magnet", "Taric E magnet", false);
					taric->set_assigned_active(hero::taric_e_magnet);
					hero::taric_e_magnet_combo_mode = taric->add_checkbox("taric_e_magnet_combo_mode", " ^- Only with combo mode", true);
					hero::taric_e_magnet_evade = taric->add_checkbox("taric_e_magnet_evade", " ^- E Magnet disable evade", true);
					hero::taric_e_tower = taric->add_checkbox("taric_e_tower", " ^- Dont use magnet in turret", true);
				}

				auto jax = hero->add_tab("hero_jax", "Jax");
				{
					jax->set_texture(jax_icon->texture);
					hero::jax_e = jax->add_checkbox("jax_e", "Use Jax E", true);
					jax->set_assigned_active(hero::jax_e);
					hero::jax_e_aatrox_p = jax->add_checkbox("jax_e_aatrox_p", "Aatrox P", true);
					hero::jax_e_camille_q2 = jax->add_checkbox("jax_e_camille_q2", "Camille Q2", true);
					hero::jax_e_darius_w = jax->add_checkbox("jax_e_darius_w", "Darius W", true);
					hero::jax_e_garen_q = jax->add_checkbox("jax_e_garen_q", "Garen Q", true);
					hero::jax_e_monkey_q = jax->add_checkbox("jax_e_monkey_q", "Monkey Q", true);
					hero::jax_e_renekton_w = jax->add_checkbox("jax_e_renekton_w", "Renekton W", true);
					hero::jax_e_renekton_angry_w = jax->add_checkbox("jax_e_renekton_angry_w", "Renekton angry W", true);
					hero::jax_e_bear_q = jax->add_checkbox("jax_e_bear_q", "Volibear Q", true);
					hero::jax_e_gold_card = jax->add_checkbox("jax_e_gold_card", "Twisted Fate W (Gold)", true);
				}

				auto cassiopeia = hero->add_tab("hero_cassiopeia", "Cassiopeia");
				{
					hero::cassiopeia_r_dodge = cassiopeia->add_checkbox("cassiopeia_r", "Dodge cassiopeia r", true);
					cassiopeia->set_assigned_active(hero::cassiopeia_r_dodge);
				}

				auto xayah = hero->add_tab("hero_xayah", "Xayah");
				{
					hero::xayah_e = xayah->add_checkbox("xayah_e", "Draw xayah e", true);
					xayah->set_assigned_active(hero::xayah_e);
					
				}
			}

			auto level_up = main_tab->add_tab("level_up", "Auto level up");
			{
				level_up->add_separator("Lv0", " ~ ~ Auto level up ~ ~ ");
				level_up::level_up = level_up->add_checkbox("level_up", "Auto level up", false, true);

				level_up->set_assigned_active(level_up::level_up);

				level_up->add_separator("Priority", " ~ ~ Priority ~ ~ ");
				level_up::level_up_7 = level_up->add_combobox(myhero->get_model() + "lv7", "Priority 1", { {"Q",nullptr},{"W",nullptr },{"E",nullptr } }, 0, true);
				level_up::level_up_8 = level_up->add_combobox(myhero->get_model() + "lv8", "Priority 2", { {"Q",nullptr},{"W",nullptr },{"E",nullptr } }, 0, true);
				level_up::level_up_9 = level_up->add_combobox(myhero->get_model() + "lv9", "Priority 3", { {"Q",nullptr},{"W",nullptr },{"E",nullptr } }, 0, true);
				level_up::force_level_up = level_up->add_checkbox(myhero->get_model() + "force_level_up", "Priority 3 spell level up to 1", true, true);
				level_up::force_level_ult = level_up->add_checkbox(myhero->get_model() + "force_level_ult", "Force levelup ult", true, true);

				level_up->add_separator("Lv1~6", " ~ ~ Details ~ ~ ");
				level_up::level_up_1 = level_up->add_combobox(myhero->get_model() + "lv1", "Lv.1", { {"Q",nullptr},{"W",nullptr },{"E",nullptr },{"Use priority",nullptr },{"Dont level up",nullptr } }, 3, true);
				level_up::level_up_2 = level_up->add_combobox(myhero->get_model() + "lv2", "Lv.2", { {"Q",nullptr},{"W",nullptr },{"E",nullptr },{"Use priority",nullptr },{"Dont level up",nullptr } }, 3, true);
				level_up::level_up_3 = level_up->add_combobox(myhero->get_model() + "lv3", "Lv.3", { {"Q",nullptr},{"W",nullptr },{"E",nullptr },{"Use priority",nullptr },{"Dont level up",nullptr } }, 3, true);
				level_up::level_up_4 = level_up->add_combobox(myhero->get_model() + "lv4", "Lv.4", { {"Q",nullptr},{"W",nullptr },{"E",nullptr },{"Use priority",nullptr },{"Dont level up",nullptr } }, 3, true);
				level_up::level_up_5 = level_up->add_combobox(myhero->get_model() + "lv5", "Lv.5", { {"Q",nullptr},{"W",nullptr },{"E",nullptr },{"Use priority",nullptr },{"Dont level up",nullptr } }, 3, true);
				level_up::level_up_6 = level_up->add_combobox(myhero->get_model() + "lv6", "Lv.6 (This is lv.6 !!!)", { {"Q",nullptr},{"W",nullptr },{"E",nullptr },{"R",nullptr },{"Use priority",nullptr } ,{"Dont level up",nullptr } }, 4, true);

			}

			auto afk = main_tab->add_tab("afk", "Follow ally mode");
			{
				afk::afk_mode = afk->add_checkbox("afk_mode", "Follow ally mode", false, true);
				afk->set_assigned_active(afk::afk_mode);
				for (auto& ally : entitylist->get_ally_heroes())
				{
					if (!ally->is_me())
					{
						afk::afk_mode_on[ally->get_network_id()] = afk->add_checkbox(std::to_string(ally->get_network_id()), ally->get_model(), true, false);
						afk::afk_mode_on[ally->get_network_id()]->set_texture(ally->get_square_icon_portrait());
					}
				}
			}

			auto translate = main_tab->add_tab("translate", "Translate");
			{
				translate->add_separator("note1", "Now in Chinese only");
				translate->add_separator("note2", "You need change langue to chinese");
				translate->add_separator("note3", "The following plugins are supported");
				translate->add_separator("note4", "Kiri");
				translate->add_separator("note5", "Shadow");
				translate->add_separator("note6", "OpenUtilities");
				translate->add_separator("note7", "Wafend");
				translate->add_separator("note8", "CSXAIO");


			}

			auto dev = main_tab->add_tab("dev", "Practice Tools");
			{
				dev::cd_item = dev->add_checkbox("dev_cd_item", "CD item", false, false);
			}

			auto draw_settings = main_tab->add_tab("utility_draw", "Drawings Settings");
			{
				//State
				auto draw_state = draw_settings->add_tab("utility_draw_state", " ~ ~ Draw State ~ ~ ");
				{
					draw_state->add_separator("draw_state", " ~ ~ Draw State ~ ~ ");
					draw_settings::state_smite = draw_state->add_checkbox("utility_draw_settings_state_smite", "Draw Smite Range", true);
					draw_settings::state_exhaust = draw_state->add_checkbox("settings_state_exhaust", "Draw Exhaust", true);
				}
			}

			//main_tab->add_separator("Hotkey", " ~ ~ Hotkey ~ ~ ");

			main_tab->add_separator("Version", " ~ Version : 3 ~ ");
		}


		event_handler<events::on_update>::add_callback(on_update);
		event_handler<events::on_draw>::add_callback(on_draw);
		event_handler<events::on_issue_order>::add_callback(on_issue_order);
		event_handler<events::on_after_attack_orbwalker>::add_callback(on_after_attack_orbwalker);
		event_handler<events::on_process_spell_cast>::add_callback(on_process_spell_cast);
		event_handler< events::on_create_object >::add_callback(on_create_object);
		event_handler< events::on_delete_object >::add_callback(on_delete_object);

		for (auto&& target : entitylist->get_all_spawnpoints())
		{
			if (target->is_ally())
			{
				ally_base = target;
			}
			else
			{
				enemy_base = target;
			}
		}
		A_Klee::on_load();

	}

	void unload()
	{
		menu->delete_tab(main_tab);
		plugin_sdk->remove_spell(q);
		plugin_sdk->remove_spell(w);
		plugin_sdk->remove_spell(e);
		plugin_sdk->remove_spell(r);
		plugin_sdk->remove_spell(smite);
		plugin_sdk->remove_spell(cleanse);
		event_handler<events::on_update>::remove_handler(on_update);
		event_handler<events::on_draw>::remove_handler(on_draw);
		event_handler<events::on_issue_order>::remove_handler(on_issue_order);
		event_handler<events::on_after_attack_orbwalker>::remove_handler(on_after_attack_orbwalker);
		event_handler<events::on_process_spell_cast>::remove_handler(on_process_spell_cast);
		event_handler< events::on_create_object >::remove_handler(on_create_object);
		event_handler< events::on_delete_object >::remove_handler(on_delete_object);
	}

	void on_update()
	{
		if (myhero->is_dead())
		{
			return;
		}
		Item ironspike(ItemId::Ironspike_Whip, 400);
		Item goredrinker(ItemId::Goredrinker, 400);
		Item stridebreaker(ItemId::Stridebreaker, 400);
		Item gargoyle_stoneplate(ItemId::Gargoyle_Stoneplate, 0);
		Item qss_1(ItemId::Quicksilver_Sash, 0);
		Item qss_2(ItemId::Mercurial_Scimitar, 0);
		Item qss_3(ItemId::Silvermere_Dawn, 0);
		Item mikael(ItemId::Mikaels_Blessing, 650);
		Item randuins(ItemId::Randuins_Omen, 450);

		//重擊
		if (myhero->get_spell(spellslot::summoner1)->get_spell_data()->get_name_hash() == spell_hash("SummonerSmite"))
			smite = plugin_sdk->register_spell(spellslot::summoner1, 560.f);
		else if (myhero->get_spell(spellslot::summoner2)->get_spell_data()->get_name_hash() == spell_hash("SummonerSmite"))
			smite = plugin_sdk->register_spell(spellslot::summoner2, 560.f);
		//红藍綠重
		if (myhero->get_spell(spellslot::summoner1)->get_spell_data()->get_name_hash() == spell_hash("S5_SummonerSmitePlayerGanker"))
			smite = plugin_sdk->register_spell(spellslot::summoner1, 560.f);
		else if (myhero->get_spell(spellslot::summoner2)->get_spell_data()->get_name_hash() == spell_hash("S5_SummonerSmitePlayerGanker"))
			smite = plugin_sdk->register_spell(spellslot::summoner2, 560.f);
		//紅重重
		if (myhero->get_spell(spellslot::summoner1)->get_spell_data()->get_name_hash() == spell_hash("SummonerSmiteAvatarOffensive"))
			smite = plugin_sdk->register_spell(spellslot::summoner1, 560.f);
		else if (myhero->get_spell(spellslot::summoner2)->get_spell_data()->get_name_hash() == spell_hash("SummonerSmiteAvatarOffensive"))
			smite = plugin_sdk->register_spell(spellslot::summoner2, 560.f);
		//藍重擊
		if (myhero->get_spell(spellslot::summoner1)->get_spell_data()->get_name_hash() == spell_hash("SummonerSmiteAvatarUtility"))
			smite = plugin_sdk->register_spell(spellslot::summoner1, 560.f);
		else if (myhero->get_spell(spellslot::summoner2)->get_spell_data()->get_name_hash() == spell_hash("SummonerSmiteAvatarUtility"))
			smite = plugin_sdk->register_spell(spellslot::summoner2, 560.f);
		//綠重擊
		if (myhero->get_spell(spellslot::summoner1)->get_spell_data()->get_name_hash() == spell_hash("SummonerSmiteAvatarDefensive"))
			smite = plugin_sdk->register_spell(spellslot::summoner1, 560.f);
		else if (myhero->get_spell(spellslot::summoner2)->get_spell_data()->get_name_hash() == spell_hash("SummonerSmiteAvatarDefensive"))
			smite = plugin_sdk->register_spell(spellslot::summoner2, 560.f);
		//净化
		if (myhero->get_spell(spellslot::summoner1)->get_spell_data()->get_name_hash() == spell_hash("SummonerBoost"))
			cleanse = plugin_sdk->register_spell(spellslot::summoner1, 0.f);
		else if (myhero->get_spell(spellslot::summoner2)->get_spell_data()->get_name_hash() == spell_hash("SummonerBoost"))
			cleanse = plugin_sdk->register_spell(spellslot::summoner2, 0.f);
		//虛弱
		if (myhero->get_spell(spellslot::summoner1)->get_spell_data()->get_name_hash() == spell_hash("SummonerExhaust"))
			exhaust = plugin_sdk->register_spell(spellslot::summoner1, 650.f);
		else if (myhero->get_spell(spellslot::summoner2)->get_spell_data()->get_name_hash() == spell_hash("SummonerExhaust"))
			exhaust = plugin_sdk->register_spell(spellslot::summoner2, 650.f);

		//裝備過去
		/*for (spellslot i = spellslot::item_1; i <= spellslot::item_6; i = static_cast<spellslot>(static_cast<int>(i) + 1))
		{

			if (myhero->get_spell(i) != nullptr)
			{
				if (myhero->get_spell(i)->get_spell_data()->get_name_hash() == spell_hash("6029Active") )
				{
					//ironspike = plugin_sdk->register_spell(i, 450.f);
				}
				if (myhero->get_spell(i)->get_spell_data()->get_name_hash() == spell_hash("6630Active"))
				{
					goredrinker = plugin_sdk->register_spell(i, 450.f);
				}
				if (myhero->get_spell(i)->get_spell_data()->get_name_hash() == spell_hash("6631Active"))
				{
					stridebreaker = plugin_sdk->register_spell(i, 450.f);
				}
				if (myhero->get_spell(i)->get_spell_data()->get_name_hash() == spell_hash("Item3193Active"))
				{
					gargoyle_stoneplate = plugin_sdk->register_spell(i, 0.0f);
				}
				if (myhero->get_spell(i)->get_spell_data()->get_name_hash() == spell_hash("RanduinsOmen"))
				{
					randuins = plugin_sdk->register_spell(i, 0.0f);
				}
				if (myhero->get_spell(i)->get_spell_data()->get_name_hash() == spell_hash("ItemMercurial"))
				{
					qss = plugin_sdk->register_spell(i, 0.0f);
				}
				if (myhero->get_spell(i)->get_spell_data()->get_name_hash() == spell_hash("QuicksilverSash"))
				{
					qss = plugin_sdk->register_spell(i, 0.0f);
				}
				if (myhero->get_spell(i)->get_spell_data()->get_name_hash() == spell_hash("6035_Spell"))
				{
					qss = plugin_sdk->register_spell(i, 0.0f);
				}
				if (myhero->get_spell(i)->get_spell_data()->get_name_hash() == spell_hash("3222Active"))
				{
					qss = plugin_sdk->register_spell(i, 0.0f);
				}
				if (myhero->get_spell(i)->get_spell_data()->get_name_hash() != spell_hash("6029Active"))
				{
					ironspike = nullptr;
				}
				if (myhero->get_spell(i)->get_spell_data()->get_name_hash() != spell_hash("6630Active"))
				{
					goredrinker = nullptr;
				}
				if (myhero->get_spell(i)->get_spell_data()->get_name_hash() != spell_hash("6631Active"))
				{
					stridebreaker = nullptr;
					myhero->print_chat(1, "stridebreaker B");
				}
				if (myhero->get_spell(i)->get_spell_data()->get_name_hash() != spell_hash("Item3193Active"))
				{
					gargoyle_stoneplate = nullptr;
				}
				if (myhero->get_spell(i)->get_spell_data()->get_name_hash() != spell_hash("RanduinsOmen"))
				{
					randuins = nullptr;
				}
				if (myhero->get_spell(i)->get_spell_data()->get_name_hash() != spell_hash("ItemMercurial")
					&& myhero->get_spell(i)->get_spell_data()->get_name_hash() == spell_hash("QuicksilverSash")
					&& myhero->get_spell(i)->get_spell_data()->get_name_hash() == spell_hash("6035_Spell")
					&& myhero->get_spell(i)->get_spell_data()->get_name_hash() == spell_hash("3222Active"))
				{
					qss = nullptr;
				}
			}

		}
		*/

		//latern
		/*for (lantern lantern : lanterns)
		{
			if (lantern.object->is_valid() && !lantern.object->is_dead() && gametime->get_time() > lantern_time)
			{
				myhero->issue_order(lantern.object, true, false);
				lantern_time = gametime->get_time() + 0.3f;
			}
		}

		for (auto& object : entitylist->get_other_minion_objects())
		{
			if (object->is_valid())
			{
				if (object->get_name().compare("Lantern_cas_green") == 0)
				{
					myhero->issue_order(object);
				}
			}
		}*/

		std::string model = myhero->get_model();
		std::transform(model.begin(), model.end(), model.begin(),
			[](unsigned char c) { return std::tolower(c); });
		std::string shadow = "shadowaio_" + model;

		//Hiden
		//
		if (summoner::cleanse_danger_level_1_alway_use->get_bool())
		{
			summoner::cleanse_danger_level_1_hp->is_hidden() = true;
			summoner::cleanse_danger_level_1_enemy_range->is_hidden() = true;
			summoner::cleanse_danger_level_1_enemy_count->is_hidden() = true;
			summoner::cleanse_danger_level_1_delay->is_hidden() = true;
			summoner::cleanse_danger_level_1_duration->is_hidden() = true;
			summoner::cleanse_danger_level_1_combo->is_hidden() = true;
			summoner::cleanse_danger_level_1_harass->is_hidden() = true;
			summoner::cleanse_danger_level_1_other->is_hidden() = true;
		}
		if (!summoner::cleanse_danger_level_1_alway_use->get_bool())
		{
			summoner::cleanse_danger_level_1_hp->is_hidden() = false;
			summoner::cleanse_danger_level_1_enemy_range->is_hidden() = false;
			summoner::cleanse_danger_level_1_enemy_count->is_hidden() = false;
			summoner::cleanse_danger_level_1_delay->is_hidden() = false;
			summoner::cleanse_danger_level_1_duration->is_hidden() = false;
			summoner::cleanse_danger_level_1_combo->is_hidden() = false;
			summoner::cleanse_danger_level_1_harass->is_hidden() = false;
			summoner::cleanse_danger_level_1_other->is_hidden() = false;
		}
		if (summoner::cleanse_danger_level_2_alway_use->get_bool())
		{
			summoner::cleanse_danger_level_2_hp->is_hidden() = true;
			summoner::cleanse_danger_level_2_enemy_range->is_hidden() = true;
			summoner::cleanse_danger_level_2_enemy_count->is_hidden() = true;
			summoner::cleanse_danger_level_2_delay->is_hidden() = true;
			summoner::cleanse_danger_level_2_duration->is_hidden() = true;
			summoner::cleanse_danger_level_2_combo->is_hidden() = true;
			summoner::cleanse_danger_level_2_harass->is_hidden() = true;
			summoner::cleanse_danger_level_2_other->is_hidden() = true;
		}
		if (!summoner::cleanse_danger_level_2_alway_use->get_bool())
		{
			summoner::cleanse_danger_level_2_hp->is_hidden() = false;
			summoner::cleanse_danger_level_2_enemy_range->is_hidden() = false;
			summoner::cleanse_danger_level_2_enemy_count->is_hidden() = false;
			summoner::cleanse_danger_level_2_delay->is_hidden() = false;
			summoner::cleanse_danger_level_2_duration->is_hidden() = false;
			summoner::cleanse_danger_level_2_combo->is_hidden() = false;
			summoner::cleanse_danger_level_2_harass->is_hidden() = false;
			summoner::cleanse_danger_level_2_other->is_hidden() = false;
		}
		if (summoner::cleanse_danger_level_3_alway_use->get_bool())
		{
			summoner::cleanse_danger_level_3_hp->is_hidden() = true;
			summoner::cleanse_danger_level_3_enemy_range->is_hidden() = true;
			summoner::cleanse_danger_level_3_enemy_count->is_hidden() = true;
			summoner::cleanse_danger_level_3_delay->is_hidden() = true;
			summoner::cleanse_danger_level_3_duration->is_hidden() = true;
			summoner::cleanse_danger_level_3_combo->is_hidden() = true;
			summoner::cleanse_danger_level_3_harass->is_hidden() = true;
			summoner::cleanse_danger_level_3_other->is_hidden() = true;
		}
		if (!summoner::cleanse_danger_level_3_alway_use->get_bool())
		{
			summoner::cleanse_danger_level_3_hp->is_hidden() = false;
			summoner::cleanse_danger_level_3_enemy_range->is_hidden() = false;
			summoner::cleanse_danger_level_3_enemy_count->is_hidden() = false;
			summoner::cleanse_danger_level_3_delay->is_hidden() = false;
			summoner::cleanse_danger_level_3_duration->is_hidden() = false;
			summoner::cleanse_danger_level_3_combo->is_hidden() = false;
			summoner::cleanse_danger_level_3_harass->is_hidden() = false;
			summoner::cleanse_danger_level_3_other->is_hidden() = false;
		}
		if (summoner::cleanse_danger_level_4_alway_use->get_bool())
		{
			summoner::cleanse_danger_level_4_hp->is_hidden() = true;
			summoner::cleanse_danger_level_4_enemy_range->is_hidden() = true;
			summoner::cleanse_danger_level_4_enemy_count->is_hidden() = true;
			summoner::cleanse_danger_level_4_delay->is_hidden() = true;
			summoner::cleanse_danger_level_4_duration->is_hidden() = true;
			summoner::cleanse_danger_level_4_combo->is_hidden() = true;
			summoner::cleanse_danger_level_4_harass->is_hidden() = true;
			summoner::cleanse_danger_level_4_other->is_hidden() = true;
		}
		if (!summoner::cleanse_danger_level_4_alway_use->get_bool())
		{
			summoner::cleanse_danger_level_4_hp->is_hidden() = false;
			summoner::cleanse_danger_level_4_enemy_range->is_hidden() = false;
			summoner::cleanse_danger_level_4_enemy_count->is_hidden() = false;
			summoner::cleanse_danger_level_4_delay->is_hidden() = false;
			summoner::cleanse_danger_level_4_duration->is_hidden() = false;
			summoner::cleanse_danger_level_4_combo->is_hidden() = false;
			summoner::cleanse_danger_level_4_harass->is_hidden() = false;
			summoner::cleanse_danger_level_4_other->is_hidden() = false;
		}

		//顯示召喚師技能
		if (!summoner::only_show->get_bool())
		{
			const auto summoner = (TreeTab*)main_tab->get_entry("summoner");
			//const auto show_cleanse = (TreeTab*)summoner->get_entry("cleanse");
			const auto show_smite = (TreeTab*)summoner->get_entry("summoner_smite");
			/*if (cleanse == nullptr)
			{
				show_cleanse->is_hidden() = true;
			}*/
			if (smite == nullptr)
			{
				show_smite->is_hidden() = true;
			}
		}
		if (summoner::only_show->get_bool())
		{
			const auto summoner = (TreeTab*)main_tab->get_entry("summoner");
			//const auto show_cleanse = (TreeTab*)summoner->get_entry("cleanse");
			const auto show_smite = (TreeTab*)summoner->get_entry("summoner_smite");
			/*show_cleanse->is_hidden() = false;*/
			show_smite->is_hidden() = false;
		}
		//ORB
		if (orb_check)
		{
			if (gametime->get_time() > taric_last_e_time + 1.0f || gametime->get_time() < taric_last_e_time
				|| gametime->get_time() < cassiopeia_r_time + 0.39 - ping->get_ping() / 1000.0f
				|| cassiopeia_r_time + 0.5f < gametime->get_time())

			{
				orbwalker->set_movement(true);
				orbwalker->set_attack(true);
				orb_check = false;
			}
		}
		//惩戒
		if (summoner::use_smite_key->get_bool() && gametime->get_time() > use_smite_key_loop)
		{
			if (summoner::smite->get_bool())
			{
				summoner::smite->set_bool(false);
				use_smite_key_loop = gametime->get_time() + 0.3f;
			}
			else
			{
				summoner::smite->set_bool(true);
				use_smite_key_loop = gametime->get_time() + 0.3f;
			}
		}
		if (summoner::smite->get_bool() && smite && smite->is_ready())
		{
			smite_monster();
		}
		if (summoner::smite_hero_key->get_bool() && smite && smite->is_ready())
		{
			semi_smite_hero();
		}
		if (summoner::auto_smite_ks->get_bool() && smite && smite->is_ready())
		{
			auto_smite_ks();
		}
		//净化
		cc_logic();
		if (summoner::cleanse->get_bool())
		{
			//summoner::cleanse_test->is_hidden() = false;
			/*if (myhero->has_buff_type(buff_type::Knockup))
			{
				if (Knockup_time < gametime->get_time())
				{
					for (auto&& buff : myhero->get_bufflist())
					{
						if (buff != nullptr && buff->is_valid() && buff->is_alive() && buff->get_type() == buff_type::Knockup)
						{
							myhero->print_chat(1, "Knockup : %f", buff->get_remaining_time());
							Knockup_time = gametime->get_time() + buff->get_remaining_time();
						}
					}
				}
			}*/
		}
		//虛弱
		if (summoner::exhaust->get_bool())
		{
			if (exhaust && exhaust->is_ready())
			{
				for (auto enemy : entitylist->get_enemy_heroes())
				{
					if (enemy != nullptr)
					{
						if (enemy->is_valid_target(650) && enemy->get_champion() == champion_id::Xayah)
						{
							if (xayah_use_e > gametime->get_time())
							{
								auto e_count = count_xayah_e();
								if (e_count >= summoner::xayah_e_count->get_int())
								{
									exhaust->cast(enemy);
								}
							}
						}
						if (enemy->is_valid_target(650) && enemy->get_champion() == champion_id::Twitch)
						{
							if (twitch_use_e > gametime->get_time())
							{
								auto e_count = count_twitch_e;
								if (e_count >= summoner::twitch_e_count->get_int())
								{
									exhaust->cast(enemy);
								}
							}
						}
					}
				}
			}
		}
		//宝石
		if (hero::taric_e_magnet->get_bool() && (myhero->has_buff(buff_hash("taricwleashactive")) || myhero->get_champion() == champion_id::Taric))
		{
			if (!hero::taric_e_magnet_combo_mode->get_bool())
			{
				taric_e_logic();
			}
			bool e_active = gametime->get_time() > taric_last_e_time && gametime->get_time() < taric_last_e_time + 1.0f;
			if (hero::taric_e_magnet_evade->get_bool() && !hero::taric_e_magnet_combo_mode->get_bool())
			{
				if (e_active)
				{
					evade->disable_evade();
					previous_evade_state = true;
				}
				else if (previous_evade_state)
				{
					evade->enable_evade();
					previous_evade_state = false;
				}
			}
			if (orbwalker->combo_mode())
			{
				if (hero::taric_e_magnet_combo_mode->get_bool())
				{
					taric_e_logic();
				}
				bool e_active = gametime->get_time() > taric_last_e_time && gametime->get_time() < taric_last_e_time + 1.0f;
				if (hero::taric_e_magnet_evade->get_bool() && hero::taric_e_magnet_combo_mode->get_bool())
				{
					if (e_active)
					{
						evade->disable_evade();
						previous_evade_state = true;
					}
					else if (previous_evade_state)
					{
						evade->enable_evade();
						previous_evade_state = false;
					}
				}
			}
		}
		//cassiopeia
		if (hero::cassiopeia_r_dodge->get_bool())
		{
			cassiopeia_r_dodge_logic();
		}
		//裝備
		use_ironspike();
		use_stridebreaker();
		use_goredrinker();
		use_gargoyle_stoneplate();
		use_randuins();
		//其他
		bool shased = menu->get_tab("Klee_menu");
		bool bajks = menu->get_tab("KiriAIO" + myhero->get_model());
		bool agkvms = menu->get_tab(shadow);
		if (level_up::level_up->get_bool() && gametime->get_time() > 60)
		{
			level_up_logic();
		}
		if (summoner::smite_key->get_bool())
		{
			monster_chose();
		}
		if (afk::afk_mode->get_bool())
		{
			if ((shased || bajks || agkvms))
			{
				return;
			}
			else
			{
				if (myhero->get_distance(ally_base) < 800 && myhero->get_gold() > 900)
				{
					myhero->buy_item(ItemId::Giants_Belt);
				}

				if (myhero->get_health_percent() < 99)
				{
					if (myhero->get_distance(ally_base) < 600)
					{
						return;
					}
					else
					{
						if (gametime->get_time() > Afk_delay)
						{
							Afk_delay = gametime->get_time() + 0.5f;
							afk_logic();
						}
					}
				}
				else
				{
					if (gametime->get_time() > Afk_delay)
					{
						Afk_delay = gametime->get_time() + 0.5f;
						afk_logic();
					}
				}
			}
		}
		if (dev::cd_item->get_bool())
		{
			buy_cd_item();
		}

	}



#pragma region afk_logic
	void afk_logic()
	{
		auto team = entitylist->get_ally_heroes();

		team.erase(std::remove_if(team.begin(), team.end(), [](game_object_script x)
			{
				return x->get_distance(ally_base) < 700;
			}), team.end());

		team.erase(std::remove_if(team.begin(), team.end(), [](game_object_script x)
			{
				return x->get_champion() == champion_id::Yuumi;
			}), team.end());

		team.erase(std::remove_if(team.begin(), team.end(), [](game_object_script x)
			{
				return x->is_me();
			}), team.end());

		std::sort(team.begin(), team.end(), [](game_object_script a, game_object_script b)
			{
				return myhero->get_distance(a) < myhero->get_distance(b);
			});

		if (!team.empty())
		{
			for (auto& team : team)
			{
				if (A_Klee::checkbox(afk::afk_mode_on, team))
				{

					if (team->is_dead())
					{
						myhero->issue_order(ally_base->get_position());
						//myhero->request_to_display_emote(summoner_emote_slot::top);
					}
					if (!team->is_dead())
					{
						if (team->get_distance(ally_base->get_position()) > 800)
						{
							if (myhero->get_health_percent() > 65)
							{
								if (myhero->count_enemies_in_range(myhero->get_attack_range() + myhero->get_bounding_radius()) == 1)
								{
									myhero->issue_order(ally_base->get_position());
								}
								if (myhero->count_enemies_in_range(1500) <= 1)
								{
									auto lane_minions = entitylist->get_enemy_minions();
									auto monsters = entitylist->get_jugnle_mobs_minions();

									lane_minions.erase(std::remove_if(lane_minions.begin(), lane_minions.end(), [](game_object_script x)
										{
											return !x->is_valid_target(myhero->get_attackRange() + myhero->get_bounding_radius());
										}), lane_minions.end());

									monsters.erase(std::remove_if(monsters.begin(), monsters.end(), [](game_object_script x)
										{
											return !x->is_valid_target(myhero->get_attackRange() + myhero->get_bounding_radius());
										}), monsters.end());

									std::sort(lane_minions.begin(), lane_minions.end(), [](game_object_script a, game_object_script b)
										{
											return a->get_position().distance(myhero->get_position()) < b->get_position().distance(myhero->get_position());
										});

									std::sort(monsters.begin(), monsters.end(), [](game_object_script a, game_object_script b)
										{
											return a->get_max_health() > b->get_max_health();
										});

									if (team->get_distance(myhero) < 400 && myhero->get_distance(ally_base) < team->get_distance(ally_base))
									{
										if (!lane_minions.empty())
										{
											for (auto& minions : lane_minions)
											{
												myhero->issue_order(minions);

											}

										}
										if (!monsters.empty())
										{
											for (auto& monster : monsters)
											{
												myhero->issue_order(monster);
											}

										}
										else
										{
											auto pos = team->get_position().extend(ally_base->get_position(), 250);
											myhero->issue_order(pos);
										}
									}
									if (team->get_distance(myhero) >= 400)
									{
										auto pos = team->get_position().extend(ally_base->get_position(), 250);
										myhero->issue_order(pos);
									}
								}
								if (myhero->count_enemies_in_range(1500) > 1)
								{
									myhero->issue_order(ally_base->get_position());
								}
							}

							if (myhero->get_health_percent() <= 65)
							{
								myhero->issue_order(ally_base->get_position());
							}
						}
					}
				}
			}
		}
	}
#pragma endregion
#pragma region buy_cd_item
	void buy_cd_item()
	{
		if (myhero->get_distance(ally_base) < 800 && gametime->get_time() > buy_item_loop)
		{
			if (myhero->has_item(ItemId::Goredrinker) == spellslot::invalid)
			{
				myhero->buy_item(ItemId::Goredrinker);
				buy_item_loop = gametime->get_time() + 1.0f;
			}
			if (myhero->has_item(ItemId::Navori_Quickblades) == spellslot::invalid)
			{
				myhero->buy_item(ItemId::Navori_Quickblades);
				buy_item_loop = gametime->get_time() + 1.0f;
			}
			if (myhero->has_item(ItemId::Black_Cleaver) == spellslot::invalid)
			{
				myhero->buy_item(ItemId::Black_Cleaver);
				buy_item_loop = gametime->get_time() + 1.0f;
			}
			if (myhero->has_item(ItemId::Cosmic_Drive) == spellslot::invalid)
			{
				myhero->buy_item(ItemId::Cosmic_Drive);
				buy_item_loop = gametime->get_time() + 1.0f;
			}
			if (myhero->has_item(ItemId::Chempunk_Chainsword) == spellslot::invalid)
			{
				myhero->buy_item(ItemId::Chempunk_Chainsword);
				buy_item_loop = gametime->get_time() + 1.0f;
			}
			if (myhero->has_item(ItemId::Seryldas_Grudge) == spellslot::invalid)
			{
				myhero->buy_item(ItemId::Seryldas_Grudge);
				buy_item_loop = gametime->get_time() + 1.0f;
			}
		}
	}
#pragma endregion
#pragma region level_up_logic
	void level_up_logic()
	{
		if (myhero->get_lvlup_stacks() > 0)
		{
			if (myhero->get_level() == 1)
			{
				if (level_up::level_up_1->get_int() == 0)
				{
					myhero->levelup_spell(spellslot::q);
					level_up_Priority();
				}
				else if (level_up::level_up_1->get_int() == 1)
				{
					myhero->levelup_spell(spellslot::w);
					level_up_Priority();
				}
				else if (level_up::level_up_1->get_int() == 2)
				{
					myhero->levelup_spell(spellslot::e);
					level_up_Priority();
				}
				else if (level_up::level_up_1->get_int() == 3)
				{
					level_up_Priority();
				}
				else if (level_up::level_up_1->get_int() == 4)
				{
					return;
				}
			}
			if (myhero->get_level() == 2)
			{
				if (level_up::level_up_2->get_int() == 0)
				{
					myhero->levelup_spell(spellslot::q);
					level_up_Priority();
				}
				else if (level_up::level_up_2->get_int() == 1)
				{
					myhero->levelup_spell(spellslot::w);
					level_up_Priority();
				}
				else if (level_up::level_up_2->get_int() == 2)
				{
					myhero->levelup_spell(spellslot::e);
					level_up_Priority();
				}
				else if (level_up::level_up_2->get_int() == 3)
				{
					level_up_Priority();
				}
				else if (level_up::level_up_2->get_int() == 4)
				{
					return;
				}
			}
			if (myhero->get_level() == 3)
			{
				if (level_up::level_up_3->get_int() == 0)
				{
					myhero->levelup_spell(spellslot::q);
					level_up_Priority();
				}
				else if (level_up::level_up_3->get_int() == 1)
				{
					myhero->levelup_spell(spellslot::w);
					level_up_Priority();
				}
				else if (level_up::level_up_3->get_int() == 2)
				{
					myhero->levelup_spell(spellslot::e);
					level_up_Priority();
				}
				else if (level_up::level_up_3->get_int() == 3)
				{
					level_up_Priority();
				}
				else if (level_up::level_up_3->get_int() == 4)
				{
					return;
				}
			}
			if (myhero->get_level() == 4)
			{
				if (level_up::level_up_4->get_int() == 0)
				{
					myhero->levelup_spell(spellslot::q);
					level_up_Priority();
				}
				else if (level_up::level_up_4->get_int() == 1)
				{
					myhero->levelup_spell(spellslot::w);
					level_up_Priority();
				}
				else if (level_up::level_up_4->get_int() == 2)
				{
					myhero->levelup_spell(spellslot::e);
					level_up_Priority();
				}
				else if (level_up::level_up_4->get_int() == 3)
				{
					level_up_Priority();
				}
				else if (level_up::level_up_4->get_int() == 4)
				{
					return;
				}
			}
			if (myhero->get_level() == 5)
			{
				if (level_up::level_up_5->get_int() == 0)
				{
					myhero->levelup_spell(spellslot::q);
					level_up_Priority();
				}
				else if (level_up::level_up_5->get_int() == 1)
				{
					myhero->levelup_spell(spellslot::w);
					level_up_Priority();
				}
				else if (level_up::level_up_5->get_int() == 2)
				{
					myhero->levelup_spell(spellslot::e);
					level_up_Priority();
				}
				else if (level_up::level_up_5->get_int() == 3)
				{
					level_up_Priority();
				}
				else if (level_up::level_up_5->get_int() == 4)
				{
					return;
				}
			}
			if (myhero->get_level() == 6)
			{
				if (level_up::level_up_6->get_int() == 0)
				{
					myhero->levelup_spell(spellslot::q);
					level_up_Priority();
				}
				else if (level_up::level_up_6->get_int() == 1)
				{
					myhero->levelup_spell(spellslot::w);
					level_up_Priority();
				}
				else if (level_up::level_up_6->get_int() == 2)
				{
					myhero->levelup_spell(spellslot::e);
					level_up_Priority();
				}
				else if (level_up::level_up_6->get_int() == 3)
				{
					myhero->levelup_spell(spellslot::r);
					level_up_Priority();
				}
				else if (level_up::level_up_6->get_int() == 4)
				{
					level_up_Priority();
				}
				else if (level_up::level_up_6->get_int() == 4)
				{
					return;
				}
			}
			if (myhero->get_level() >= 7)
			{
				if (level_up::level_up_7->get_int() == level_up::level_up_8->get_int() || level_up::level_up_7->get_int() == level_up::level_up_9->get_int() || level_up::level_up_8->get_int() == level_up::level_up_9->get_int())
				{
					return;
				}
				else
				{
					level_up_Priority();
				}
			}
		}
	}
#pragma endregion
#pragma region level_up_Priority
	void level_up_Priority()
	{
		if (level_up::level_up_7->get_int() == level_up::level_up_8->get_int() || level_up::level_up_7->get_int() == level_up::level_up_9->get_int() || level_up::level_up_8->get_int() == level_up::level_up_9->get_int())
			return;
		else if (myhero->get_level() >= 6 && myhero->get_level() < 11 && r->level() < 1 && level_up::force_level_ult->get_bool())
		{
			myhero->levelup_spell(spellslot::r);
		}
		else if (myhero->get_level() >= 11 && myhero->get_level() < 16 && r->level() <= 1 && level_up::force_level_ult->get_bool())
		{
			myhero->levelup_spell(spellslot::r);
		}
		else if (myhero->get_level() >= 16 && r->level() <= 2 && level_up::force_level_ult->get_bool())
		{
			myhero->levelup_spell(spellslot::r);
		}
		else if (level_up::level_up_7->get_int() == 0)
		{
			if (!level_up::force_level_up->get_bool() || q->level() < 1)
			{
				myhero->levelup_spell(spellslot::q);
			}
			if (q->level() > 0 && level_up::force_level_up->get_bool() && w->level() > 0 && e->level() > 0)
			{
				myhero->levelup_spell(spellslot::q);
			}
			if (level_up::level_up_8->get_int() == 1)
			{
				if (e->level() < 1 && level_up::force_level_up->get_bool() && w->level() > 0)
				{
					myhero->levelup_spell(spellslot::e);
				}
				else
				{
					myhero->levelup_spell(spellslot::w);
					if (level_up::level_up_9->get_int() == 2)
					{
						myhero->levelup_spell(spellslot::e);
					}
				}
			}
			if (level_up::level_up_8->get_int() == 2)
			{
				if (w->level() < 1 && level_up::force_level_up->get_bool() && e->level() > 0)
				{
					myhero->levelup_spell(spellslot::w);
				}
				else
				{
					myhero->levelup_spell(spellslot::e);
					if (level_up::level_up_9->get_int() == 1)
					{
						myhero->levelup_spell(spellslot::w);
					}
				}
			}
		}
		else if (level_up::level_up_7->get_int() == 1)
		{
			if (!level_up::force_level_up->get_bool() || w->level() < 1)
			{
				myhero->levelup_spell(spellslot::w);
			}
			if (w->level() > 0 && level_up::force_level_up->get_bool() && q->level() > 0 && e->level() > 0)
			{
				myhero->levelup_spell(spellslot::w);
			}
			if (level_up::level_up_8->get_int() == 0)
			{
				if (e->level() < 1 && level_up::force_level_up->get_bool() && q->level() > 0)
				{
					myhero->levelup_spell(spellslot::e);
				}
				else
				{
					myhero->levelup_spell(spellslot::q);
					if (level_up::level_up_9->get_int() == 2)
					{
						myhero->levelup_spell(spellslot::e);
					}
				}
			}
			if (level_up::level_up_8->get_int() == 2)
			{
				if (q->level() < 1 && level_up::force_level_up->get_bool() && e->level() > 0)
				{
					myhero->levelup_spell(spellslot::q);
				}
				else
				{
					myhero->levelup_spell(spellslot::e);
					if (level_up::level_up_9->get_int() == 0)
					{
						myhero->levelup_spell(spellslot::q);
					}
				}
			}
		}
		else if (level_up::level_up_7->get_int() == 2)
		{
			if (!level_up::force_level_up->get_bool() || e->level() < 1)
			{
				myhero->levelup_spell(spellslot::e);
			}
			if (e->level() > 0 && level_up::force_level_up->get_bool() && q->level() > 0 && w->level() > 0)
			{
				myhero->levelup_spell(spellslot::e);
			}
			if (level_up::level_up_8->get_int() == 0)
			{
				if (w->level() < 1 && level_up::force_level_up->get_bool() && q->level() > 0)
				{
					myhero->levelup_spell(spellslot::w);
				}
				else
				{
					myhero->levelup_spell(spellslot::q);
					if (level_up::level_up_9->get_int() == 1)
					{
						myhero->levelup_spell(spellslot::w);
					}
				}
			}
			if (level_up::level_up_8->get_int() == 1)
			{
				if (q->level() < 1 && level_up::force_level_up->get_bool() && w->level() > 0)
				{
					myhero->levelup_spell(spellslot::q);
				}
				else
				{
					myhero->levelup_spell(spellslot::w);
					if (level_up::level_up_9->get_int() == 0)
					{
						myhero->levelup_spell(spellslot::q);
					}
				}
			}
		}
	}
#pragma endregion
	//惩戒
#pragma region smite_monster
	void smite_monster()
	{
		for (auto& object : entitylist->get_jugnle_mobs_minions())
		{
			if (object->is_valid())
			{
				//巴龍
				if (summoner::baron->get_bool())
				{
					if (object->get_name().compare("SRU_Baron12.1.1") == 0)
					{
						cast_smite_monster(object);
					}
				}
				//小龍
				if (summoner::dragon->get_bool())
				{
					if (object->get_name().compare("SRU_Dragon_Hextech") == 0 || object->get_name().compare("SRU_Dragon_Air") == 0 || object->get_name().compare("SRU_Dragon_Earth") == 0 || object->get_name().compare("SRU_Dragon_Fire") == 0 || object->get_name().compare("SRU_Dragon_Water") == 0 || object->get_name().compare("SRU_Dragon_Chemtech") == 0 || object->get_name().compare("SRU_Dragon_Elder") == 0)
					{
						cast_smite_monster(object);
					}
				}
				//峽谷先鋒
				if (summoner::big_crab->get_bool())
				{
					if (object->get_name().compare("SRU_RiftHerald17.1.1") == 0)
					{
						cast_smite_monster(object);
					}
				}
				//河蟹
				if (summoner::small_crab->get_bool())
				{
					if (object->get_name().compare("Sru_Crab16.1.1") == 0 || object->get_name().compare("Sru_Crab15.1.1") == 0)
					{
						cast_smite_monster(object);
					}
				}
				//紅
				if (summoner::red_buff->get_bool())
				{
					if (object->get_name().compare("SRU_Red4.1.1") == 0 || object->get_name().compare("SRU_Red10.1.1") == 0)
					{
						cast_smite_monster(object);
					}
				}
				//藍
				if (summoner::blue_buff->get_bool())
				{
					if (object->get_name().compare("SRU_Blue1.1.1") == 0 || object->get_name().compare("SRU_Blue7.1.1") == 0)
					{
						cast_smite_monster(object);
					}
				}
				//三狼
				if (summoner::three_wolf->get_bool())
				{
					if (object->get_name().compare("SRU_Murkwolf2.1.1") == 0 || object->get_name().compare("SRU_Murkwolf8.1.1") == 0)
					{
						cast_smite_monster(object);
					}
				}
				//石頭
				if (summoner::stone->get_bool())
				{
					if (object->get_name().compare("SRU_Krug5.1.1") == 0 || object->get_name().compare("SRU_Krug11.1.1") == 0)
					{
						cast_smite_monster(object);
					}
				}
				//六鳥
				if (summoner::six_bird->get_bool())
				{
					if (object->get_name().compare("SRU_Razorbeak3.1.1") == 0 || object->get_name().compare("SRU_Razorbeak9.1.1") == 0)
					{
						cast_smite_monster(object);
					}
				}
				//大蟾蜍
				if (summoner::gromp->get_bool())
				{
					if (object->get_name().compare("SRU_Gromp13.1.1") == 0 || object->get_name().compare("SRU_Gromp14.1.1") == 0)
					{
						cast_smite_monster(object);
					}
				}
			}
		}
		for (auto& minions : entitylist->get_enemy_minions())
		{
			if (minions->is_valid())
			{
				//砲車
				if (summoner::smite_siege_minion->get_bool())
				{
					if (minions->get_bounding_radius() == 65)
					{
						cast_smite_monster(minions);
					}
				}
			}
		}
	}
#pragma endregion
#pragma region monster_chose
	void monster_chose()
	{
		if (smite_semi_key_delay < gametime->get_time() && smite)
		{
			for (auto& object : entitylist->get_jugnle_mobs_minions())
			{
				if (object->is_valid())
				{
					if (object->get_distance(hud->get_hud_input_logic()->get_game_cursor_position()) < summoner::smite_draw_range->get_int())
					{
						//巴龍
						if (summoner::hotkey_use_baron->get_bool())
						{
							if (object->get_name().compare("SRU_Baron12.1.1") == 0)
							{
								if (summoner::baron->get_bool())
								{
									summoner::baron->set_bool(0);
									smite_semi_key_delay = gametime->get_time() + 0.3f;
								}
								else
								{
									summoner::baron->set_bool(1);
									smite_semi_key_delay = gametime->get_time() + 0.3f;
								}
							}
						}
						//小龍
						if (summoner::hotkey_use_dragon->get_bool())
						{
							if (object->get_name().compare("SRU_Dragon_Hextech") == 0 || object->get_name().compare("SRU_Dragon_Air") == 0 || object->get_name().compare("SRU_Dragon_Earth") == 0 || object->get_name().compare("SRU_Dragon_Fire") == 0 || object->get_name().compare("SRU_Dragon_Water") == 0 || object->get_name().compare("SRU_Dragon_Chemtech") == 0 || object->get_name().compare("SRU_Dragon_Elder") == 0)
							{
								if (summoner::dragon->get_bool())
								{
									summoner::dragon->set_bool(0);
									smite_semi_key_delay = gametime->get_time() + 0.3f;
								}
								else
								{
									summoner::dragon->set_bool(1);
									smite_semi_key_delay = gametime->get_time() + 0.3f;
								}
							}

						}
						//峽谷先鋒
						if (summoner::hotkey_use_big_crab->get_bool())
						{
							if (object->get_name().compare("SRU_RiftHerald17.1.1") == 0)
							{
								if (summoner::big_crab->get_bool())
								{
									summoner::big_crab->set_bool(0);
									smite_semi_key_delay = gametime->get_time() + 0.3f;
								}
								else
								{
									summoner::big_crab->set_bool(1);
									smite_semi_key_delay = gametime->get_time() + 0.3f;
								}
							}
						}
						//河蟹
						if (summoner::hotkey_use_small_crab->get_bool())
						{
							if (object->get_name().compare("Sru_Crab16.1.1") == 0 || object->get_name().compare("Sru_Crab15.1.1") == 0)
							{
								if (summoner::small_crab->get_bool())
								{
									summoner::small_crab->set_bool(0);
									smite_semi_key_delay = gametime->get_time() + 0.3f;
								}
								else
								{
									summoner::small_crab->set_bool(1);
									smite_semi_key_delay = gametime->get_time() + 0.3f;
								}
							}
						}
						//紅
						if (summoner::hotkey_use_red_buff->get_bool())
						{
							if (object->get_name().compare("SRU_Red4.1.1") == 0 || object->get_name().compare("SRU_Red10.1.1") == 0)
							{
								if (summoner::red_buff->get_bool())
								{
									summoner::red_buff->set_bool(0);
									smite_semi_key_delay = gametime->get_time() + 0.3f;
								}
								else
								{
									summoner::red_buff->set_bool(1);
									smite_semi_key_delay = gametime->get_time() + 0.3f;
								}
							}
						}
						//藍
						if (summoner::hotkey_use_blue_buff->get_bool())
						{
							if (object->get_name().compare("SRU_Blue1.1.1") == 0 || object->get_name().compare("SRU_Blue7.1.1") == 0)
							{
								if (summoner::blue_buff->get_bool())
								{
									summoner::blue_buff->set_bool(0);
									smite_semi_key_delay = gametime->get_time() + 0.3f;
								}
								else
								{
									summoner::blue_buff->set_bool(1);
									smite_semi_key_delay = gametime->get_time() + 0.3f;
								}
							}
						}
						//三狼
						if (summoner::hotkey_use_three_wolf->get_bool())
						{
							if (object->get_name().compare("SRU_Murkwolf2.1.1") == 0 || object->get_name().compare("SRU_Murkwolf8.1.1") == 0)
							{
								if (summoner::three_wolf->get_bool())
								{
									summoner::three_wolf->set_bool(0);
									smite_semi_key_delay = gametime->get_time() + 0.3f;
								}
								else
								{
									summoner::three_wolf->set_bool(1);
									smite_semi_key_delay = gametime->get_time() + 0.3f;
								}
							}
						}
						//石頭
						if (summoner::hotkey_use_stone->get_bool())
						{
							if (object->get_name().compare("SRU_Krug5.1.1") == 0 || object->get_name().compare("SRU_Krug11.1.1") == 0)
							{
								if (summoner::stone->get_bool())
								{
									summoner::stone->set_bool(0);
									smite_semi_key_delay = gametime->get_time() + 0.3f;
								}
								else
								{
									summoner::stone->set_bool(1);
									smite_semi_key_delay = gametime->get_time() + 0.3f;
								}
							}
						}
						//六鳥
						if (summoner::hotkey_use_six_bird->get_bool())
						{
							if (object->get_name().compare("SRU_Razorbeak3.1.1") == 0 || object->get_name().compare("SRU_Razorbeak9.1.1") == 0)
							{
								if (summoner::six_bird->get_bool())
								{
									summoner::six_bird->set_bool(0);
									smite_semi_key_delay = gametime->get_time() + 0.3f;
								}
								else
								{
									summoner::six_bird->set_bool(1);
									smite_semi_key_delay = gametime->get_time() + 0.3f;
								}
							}
						}
						//大蟾蜍
						if (summoner::hotkey_use_gromp->get_bool())
						{
							if (object->get_name().compare("SRU_Gromp13.1.1") == 0 || object->get_name().compare("SRU_Gromp14.1.1") == 0)
							{
								if (summoner::gromp->get_bool())
								{
									summoner::gromp->set_bool(0);
									smite_semi_key_delay = gametime->get_time() + 0.3f;
								}
								else
								{
									summoner::gromp->set_bool(1);
									smite_semi_key_delay = gametime->get_time() + 0.3f;
								}
							}
						}
					}
				}
			}
		}
	}
#pragma endregion
#pragma region semi_smite_hero
	void semi_smite_hero()
	{
		auto target = target_selector->get_target(smite->range(), damage_type::true_dmg);
		if (target != nullptr)
		{
			if (smite->cast(target))
			{
				return;
			}
		}
	}
#pragma endregion
#pragma region auto_smite_ks
	void auto_smite_ks()
	{
		auto enemy = entitylist->get_enemy_heroes();

		enemy.erase(std::remove_if(enemy.begin(), enemy.end(), [](game_object_script x)
			{
				return x->is_dead() || !x->is_valid_target(smite->range());
			}), enemy.end());

		if (!enemy.empty() && gametime->get_time() > smite_ks_delay)
		{
			for (auto& enemy : enemy)
			{
				//升级1惩戒
				if (myhero->get_buff(buff_hash("SmiteDamageTrackerStalker")) || myhero->get_buff(buff_hash("SmiteDamageTrackerAvatar")))
				{
					smite_damage_hero = 80 + 80 / 17 * (myhero->get_level() - 1);
					if (enemy->get_health() < smite_damage_hero)
					{
						if (smite->cast(enemy))
						{
							smite_ks_delay = gametime->get_time() + 0.2f;
							return;
						}
					}
				}
			}
		}
	}
#pragma endregion
	//qss cleanse
	//
	void cc_logic()
	{
		if (item::mikael->get_bool())
		{
			auto ally = entitylist->get_ally_heroes();

			ally.erase(std::remove_if(ally.begin(), ally.end(), [](game_object_script x)
				{
					return x->get_distance(myhero) > 650 || x->is_dead() || !A_Klee::checkbox(item::mikael_use_on, x) || x->has_buff_type(buff_type::Knockup) || x->has_buff_type(buff_type::Knockback) || x->has_buff(buff_hash("rellw_knockup"));
				}), ally.end());

			for (auto& ally : ally)
			{
				if (ally->has_buff_type(buff_type::Berserk))
				{
					auto buff = ally->get_buff_by_type(buff_type::Berserk);
					if (buff != nullptr && buff->is_valid() && buff->is_alive())
					{
						if (cc_time_loop < gametime->get_time())
						{
							Berserk_time = gametime->get_time();
							cc_time_loop = gametime->get_time() + buff->get_remaining_time();
						}
						if (cc_clean_loop < gametime->get_time())
						{
							clean_cc_logic(Berserk_time, buff->get_remaining_time(), summoner::cleanse->get_bool(), summoner::Berserk_cleanse->get_int(), item::qss->get_bool(), item::Berserk_qss->get_int(), item::mikael->get_bool(), ally, item::Berserk_mikael->get_int());
							cc_clean_loop = gametime->get_time() + 0.1f;
						}
					}
				}
				if (ally->has_buff_type(buff_type::Stun))
				{
					auto buff = ally->get_buff_by_type(buff_type::Stun);
					if (buff != nullptr && buff->is_valid() && buff->is_alive())
					{
						if (cc_time_loop < gametime->get_time())
						{
							Stun_time = gametime->get_time();
							cc_time_loop = gametime->get_time() + buff->get_remaining_time();
							//myhero->print_chat(1, "%f   %f", Stun_time, buff->get_remaining_time());
							//myhero->print_chat(1, "%f %f", cc_time, gametime->get_time());
							//myhero->print_chat(1, "Stun : %f %s !!", buff->get_remaining_time(), ally->get_name_cstr());
							//clean_cc_logic(Stun_time, buff->get_remaining_time(), summoner::cleanse->get_bool(), summoner::Stun_cleanse->get_int(), item::qss->get_bool(), item::Stun_qss->get_int(), item::mikael->get_bool(), ally, item::Stun_mikael->get_int());
						}
						//myhero->print_chat(1, "%f   %f", Stun_time, buff->get_remaining_time());
						if (cc_clean_loop < gametime->get_time())
						{
							clean_cc_logic(Stun_time, buff->get_remaining_time(), summoner::cleanse->get_bool(), summoner::Stun_cleanse->get_int(), item::qss->get_bool(), item::Stun_qss->get_int(), item::mikael->get_bool(), ally, item::Stun_mikael->get_int());
							cc_clean_loop = gametime->get_time() + 0.1f;
						}
					}
				}
				if (ally->has_buff_type(buff_type::Taunt))
				{
					auto buff = ally->get_buff_by_type(buff_type::Taunt);
					if (buff != nullptr && buff->is_valid() && buff->is_alive())
					{
						if (cc_time_loop < gametime->get_time())
						{
							Taunt_time = gametime->get_time();
							cc_time_loop = gametime->get_time() + buff->get_remaining_time();
						}
						if (cc_clean_loop < gametime->get_time())
						{
							clean_cc_logic(Taunt_time, buff->get_remaining_time(), summoner::cleanse->get_bool(), summoner::Taunt_cleanse->get_int(), item::qss->get_bool(), item::Taunt_qss->get_int(), item::mikael->get_bool(), ally, item::Taunt_mikael->get_int());
							cc_clean_loop = gametime->get_time() + 0.1f;
						}
					}
				}
				if (ally->has_buff_type(buff_type::Polymorph))
				{
					auto buff = ally->get_buff_by_type(buff_type::Polymorph);
					if (buff != nullptr && buff->is_valid() && buff->is_alive())
					{
						if (cc_time_loop < gametime->get_time())
						{
							Polymorph_time = gametime->get_time();
							cc_time_loop = gametime->get_time() + buff->get_remaining_time();
						}
						if (cc_clean_loop < gametime->get_time())
						{
							clean_cc_logic(Polymorph_time, buff->get_remaining_time(), summoner::cleanse->get_bool(), summoner::Polymorph_cleanse->get_int(), item::qss->get_bool(), item::Polymorph_qss->get_int(), item::mikael->get_bool(), ally, item::Polymorph_mikael->get_int());
							cc_clean_loop = gametime->get_time() + 0.1f;
						}
					}
				}
				if (ally->has_buff_type(buff_type::Fear))
				{
					auto buff = ally->get_buff_by_type(buff_type::Fear);
					if (buff != nullptr && buff->is_valid() && buff->is_alive())
					{
						if (cc_time_loop < gametime->get_time())
						{
							Fear_time = gametime->get_time();
							cc_time_loop = gametime->get_time() + buff->get_remaining_time();
						}
						if (cc_clean_loop < gametime->get_time())
						{
							clean_cc_logic(Fear_time, buff->get_remaining_time(), summoner::cleanse->get_bool(), summoner::Fear_cleanse->get_int(), item::qss->get_bool(), item::Fear_qss->get_int(), item::mikael->get_bool(), ally, item::Fear_mikael->get_int());
							cc_clean_loop = gametime->get_time() + 0.1f;
						}
					}
				}
				if (ally->has_buff_type(buff_type::Charm))
				{
					auto buff = ally->get_buff_by_type(buff_type::Charm);
					if (buff != nullptr && buff->is_valid() && buff->is_alive())
					{
						if (cc_time_loop < gametime->get_time())
						{
							Charm_time = gametime->get_time();
							cc_time_loop = gametime->get_time() + buff->get_remaining_time();
						}
						if (cc_clean_loop < gametime->get_time())
						{
							clean_cc_logic(Charm_time, buff->get_remaining_time(), summoner::cleanse->get_bool(), summoner::Charm_cleanse->get_int(), item::qss->get_bool(), item::Charm_qss->get_int(), item::mikael->get_bool(), ally, item::Charm_mikael->get_int());
							cc_clean_loop = gametime->get_time() + 0.1f;
						}
					}
				}
				if (ally->has_buff_type(buff_type::Drowsy))
				{
					auto buff = ally->get_buff_by_type(buff_type::Drowsy);
					if (buff != nullptr && buff->is_valid() && buff->is_alive())
					{
						if (cc_time_loop < gametime->get_time())
						{
							Drowsy_time = gametime->get_time();
							cc_time_loop = gametime->get_time() + buff->get_remaining_time();
						}
						if (cc_clean_loop < gametime->get_time())
						{
							clean_cc_logic(Drowsy_time, buff->get_remaining_time(), summoner::cleanse->get_bool(), summoner::Drowsy_cleanse->get_int(), item::qss->get_bool(), item::Drowsy_qss->get_int(), item::mikael->get_bool(), ally, item::Drowsy_mikael->get_int());
							cc_clean_loop = gametime->get_time() + 0.1f;
						}
					}
				}
				if (ally->has_buff_type(buff_type::Asleep))
				{
					auto buff = ally->get_buff_by_type(buff_type::Asleep);
					if (buff != nullptr && buff->is_valid() && buff->is_alive())
					{
						if (cc_time_loop < gametime->get_time())
						{
							Asleep_time = gametime->get_time();
							cc_time_loop = gametime->get_time() + buff->get_remaining_time();
						}
						if (cc_clean_loop < gametime->get_time())
						{
							clean_cc_logic(Asleep_time, buff->get_remaining_time(), summoner::cleanse->get_bool(), summoner::Asleep_cleanse->get_int(), item::qss->get_bool(), item::Asleep_qss->get_int(), item::mikael->get_bool(), ally, item::Asleep_mikael->get_int());
							cc_clean_loop = gametime->get_time() + 0.1f;
						}
					}
				}
				if (ally->has_buff_type(buff_type::Snare))
				{
					auto buff = ally->get_buff_by_type(buff_type::Snare);
					if (buff != nullptr && buff->is_valid() && buff->is_alive())
					{
						if (cc_time_loop < gametime->get_time())
						{
							Snare_time = gametime->get_time();
							cc_time_loop = gametime->get_time() + buff->get_remaining_time();
						}
						if (cc_clean_loop < gametime->get_time())
						{
							clean_cc_logic(Snare_time, buff->get_remaining_time(), summoner::cleanse->get_bool(), summoner::Snare_cleanse->get_int(), item::qss->get_bool(), item::Snare_qss->get_int(), item::mikael->get_bool(), ally, item::Snare_mikael->get_int());
							cc_clean_loop = gametime->get_time() + 0.1f;
						}
					}
				}
				if (ally->has_buff_type(buff_type::Slow) && ally->get_move_speed() < 250)
				{
					auto buff = ally->get_buff_by_type(buff_type::Slow);
					if (buff != nullptr && buff->is_valid() && buff->is_alive())
					{
						if (cc_time_loop < gametime->get_time())
						{
							Slow_time = gametime->get_time();
							cc_time_loop = gametime->get_time() + buff->get_remaining_time();
						}
						if (cc_clean_loop < gametime->get_time())
						{
							clean_cc_logic(Slow_time, buff->get_remaining_time(), summoner::cleanse->get_bool(), summoner::Slow_cleanse->get_int(), item::qss->get_bool(), item::Slow_qss->get_int(), item::mikael->get_bool(), ally, item::Slow_mikael->get_int());
							cc_clean_loop = gametime->get_time() + 0.1f;
						}
					}
				}
				if (ally->has_buff_type(buff_type::Silence))
				{
					auto buff = ally->get_buff_by_type(buff_type::Silence);
					if (buff != nullptr && buff->is_valid() && buff->is_alive())
					{
						if (cc_time_loop < gametime->get_time())
						{
							Silence_time = gametime->get_time();
							cc_time_loop = gametime->get_time() + buff->get_remaining_time();
						}
						if (cc_clean_loop < gametime->get_time())
						{
							clean_cc_logic(Silence_time, buff->get_remaining_time(), summoner::cleanse->get_bool(), summoner::Silence_cleanse->get_int(), item::qss->get_bool(), item::Silence_qss->get_int(), item::mikael->get_bool(), ally, item::Silence_mikael->get_int());
							cc_clean_loop = gametime->get_time() + 0.1f;
						}
					}
				}
			}

		}
		if (item::qss->get_bool() || summoner::cleanse->get_bool())
		{
			if (!myhero->has_buff_type(buff_type::Knockup) && !myhero->has_buff_type(buff_type::Knockback) && !myhero->has_buff(buff_hash("rellw_knockup")))
			{
				if (myhero->has_buff(buff_hash("SummonerExhaust")))
				{
					auto buff = myhero->get_buff(buff_hash("SummonerExhaust"));
					if (buff != nullptr && buff->is_valid() && buff->is_alive())
					{
						if (cc_time_loop < gametime->get_time())
						{
							Exhaust_time = gametime->get_time();
							cc_time_loop = gametime->get_time() + buff->get_remaining_time();
						}
						if (cc_clean_loop < gametime->get_time())
						{
							clean_cc_logic(Exhaust_time, buff->get_remaining_time(), summoner::cleanse->get_bool(), summoner::Exhaust_cleanse->get_int(), item::qss->get_bool(), 0, item::mikael->get_bool(), myhero, 0);
							cc_clean_loop = gametime->get_time() + 0.1f;
						}
					}
				}
				if (myhero->has_buff(buff_hash("SummonerDot")))
				{
					auto buff = myhero->get_buff(buff_hash("SummonerDot"));
					if (buff != nullptr && buff->is_valid() && buff->is_alive())
					{
						if (cc_time_loop < gametime->get_time())
						{
							Ignite_time = gametime->get_time();
							cc_time_loop = gametime->get_time() + buff->get_remaining_time();
						}
						if (cc_clean_loop < gametime->get_time())
						{
							clean_cc_logic(Ignite_time, buff->get_remaining_time(), summoner::cleanse->get_bool(), summoner::Ignite_cleanse->get_int(), item::qss->get_bool(), 0, item::mikael->get_bool(), myhero, 0);
							cc_clean_loop = gametime->get_time() + 0.1f;
						}
					}
				}
				if (myhero->has_buff_type(buff_type::Stun))
				{
					auto buff = myhero->get_buff_by_type(buff_type::Stun);
					if (buff != nullptr && buff->is_valid() && buff->is_alive())
					{
						if (cc_time_loop < gametime->get_time())
						{
							Stun_time = gametime->get_time();
							cc_time_loop = gametime->get_time() + buff->get_remaining_time();
							//myhero->print_chat(1, "%f   %f", Stun_time, buff->get_remaining_time());
							//myhero->print_chat(1, "%f %f", cc_time, gametime->get_time());
							//myhero->print_chat(1, "Stun : %f %s !!", buff->get_remaining_time(), myhero->get_name_cstr());
							//clean_cc_logic(Stun_time, buff->get_remaining_time(), summoner::cleanse->get_bool(), summoner::Stun_cleanse->get_int(), item::qss->get_bool(), item::Stun_qss->get_int(), item::mikael->get_bool(), myhero, item::Stun_mikael->get_int());
						}
						//myhero->print_chat(1, "%f   %f", Stun_time, buff->get_remaining_time());
						if (cc_clean_loop < gametime->get_time())
						{
							//myhero->print_chat(1, "%f", buff->get_remaining_time());
							clean_cc_logic(Stun_time, buff->get_remaining_time(), summoner::cleanse->get_bool(), summoner::Stun_cleanse->get_int(), item::qss->get_bool(), item::Stun_qss->get_int(), item::mikael->get_bool(), myhero, item::Stun_mikael->get_int());
							cc_clean_loop = gametime->get_time() + 0.1f;
						}
					}
				}
				if (myhero->has_buff_type(buff_type::Berserk))
				{
					auto buff = myhero->get_buff_by_type(buff_type::Berserk);
					if (buff != nullptr && buff->is_valid() && buff->is_alive())
					{
						if (cc_time_loop < gametime->get_time())
						{
							Berserk_time = gametime->get_time();
							cc_time_loop = gametime->get_time() + buff->get_remaining_time();
						}
						if (cc_clean_loop < gametime->get_time())
						{
							clean_cc_logic(Berserk_time, buff->get_remaining_time(), summoner::cleanse->get_bool(), summoner::Berserk_cleanse->get_int(), item::qss->get_bool(), item::Berserk_qss->get_int(), item::mikael->get_bool(), myhero, item::Berserk_mikael->get_int());
							cc_clean_loop = gametime->get_time() + 0.1f;
						}
					}
				}
				if (myhero->has_buff_type(buff_type::Taunt))
				{
					auto buff = myhero->get_buff_by_type(buff_type::Taunt);
					if (buff != nullptr && buff->is_valid() && buff->is_alive())
					{
						if (cc_time_loop < gametime->get_time())
						{
							Taunt_time = gametime->get_time();
							cc_time_loop = gametime->get_time() + buff->get_remaining_time();
						}
						if (cc_clean_loop < gametime->get_time())
						{
							clean_cc_logic(Taunt_time, buff->get_remaining_time(), summoner::cleanse->get_bool(), summoner::Taunt_cleanse->get_int(), item::qss->get_bool(), item::Taunt_qss->get_int(), item::mikael->get_bool(), myhero, item::Taunt_mikael->get_int());
							cc_clean_loop = gametime->get_time() + 0.1f;
						}
					}
				}
				if (myhero->has_buff_type(buff_type::Polymorph))
				{
					auto buff = myhero->get_buff_by_type(buff_type::Polymorph);
					if (buff != nullptr && buff->is_valid() && buff->is_alive())
					{
						if (cc_time_loop < gametime->get_time())
						{
							Polymorph_time = gametime->get_time();
							cc_time_loop = gametime->get_time() + buff->get_remaining_time();
						}
						if (cc_clean_loop < gametime->get_time())
						{
							clean_cc_logic(Polymorph_time, buff->get_remaining_time(), summoner::cleanse->get_bool(), summoner::Polymorph_cleanse->get_int(), item::qss->get_bool(), item::Polymorph_qss->get_int(), item::mikael->get_bool(), myhero, item::Polymorph_mikael->get_int());
							cc_clean_loop = gametime->get_time() + 0.1f;
						}
					}
				}
				if (myhero->has_buff_type(buff_type::Fear))
				{
					auto buff = myhero->get_buff_by_type(buff_type::Fear);
					if (buff != nullptr && buff->is_valid() && buff->is_alive())
					{
						if (cc_time_loop < gametime->get_time())
						{
							Fear_time = gametime->get_time();
							cc_time_loop = gametime->get_time() + buff->get_remaining_time();
						}
						if (cc_clean_loop < gametime->get_time())
						{
							clean_cc_logic(Fear_time, buff->get_remaining_time(), summoner::cleanse->get_bool(), summoner::Fear_cleanse->get_int(), item::qss->get_bool(), item::Fear_qss->get_int(), item::mikael->get_bool(), myhero, item::Fear_mikael->get_int());
							cc_clean_loop = gametime->get_time() + 0.1f;
						}
					}
				}
				if (myhero->has_buff_type(buff_type::Charm))
				{
					auto buff = myhero->get_buff_by_type(buff_type::Charm);
					if (buff != nullptr && buff->is_valid() && buff->is_alive())
					{
						if (cc_time_loop < gametime->get_time())
						{
							Charm_time = gametime->get_time();
							cc_time_loop = gametime->get_time() + buff->get_remaining_time();
						}
						if (cc_clean_loop < gametime->get_time())
						{
							clean_cc_logic(Charm_time, buff->get_remaining_time(), summoner::cleanse->get_bool(), summoner::Charm_cleanse->get_int(), item::qss->get_bool(), item::Charm_qss->get_int(), item::mikael->get_bool(), myhero, item::Charm_mikael->get_int());
							cc_clean_loop = gametime->get_time() + 0.1f;
						}
					}
				}
				if (myhero->has_buff_type(buff_type::Drowsy))
				{
					auto buff = myhero->get_buff_by_type(buff_type::Drowsy);
					if (buff != nullptr && buff->is_valid() && buff->is_alive())
					{
						if (cc_time_loop < gametime->get_time())
						{
							Drowsy_time = gametime->get_time();
							cc_time_loop = gametime->get_time() + buff->get_remaining_time();
						}
						if (cc_clean_loop < gametime->get_time())
						{
							clean_cc_logic(Drowsy_time, buff->get_remaining_time(), summoner::cleanse->get_bool(), summoner::Drowsy_cleanse->get_int(), item::qss->get_bool(), item::Drowsy_qss->get_int(), item::mikael->get_bool(), myhero, item::Drowsy_mikael->get_int());
							cc_clean_loop = gametime->get_time() + 0.1f;
						}
					}
				}
				if (myhero->has_buff_type(buff_type::Asleep))
				{
					auto buff = myhero->get_buff_by_type(buff_type::Asleep);
					if (buff != nullptr && buff->is_valid() && buff->is_alive())
					{
						if (cc_time_loop < gametime->get_time())
						{
							Asleep_time = gametime->get_time();
							cc_time_loop = gametime->get_time() + buff->get_remaining_time();
						}
						if (cc_clean_loop < gametime->get_time())
						{
							clean_cc_logic(Asleep_time, buff->get_remaining_time(), summoner::cleanse->get_bool(), summoner::Asleep_cleanse->get_int(), item::qss->get_bool(), item::Asleep_qss->get_int(), item::mikael->get_bool(), myhero, item::Asleep_mikael->get_int());
							cc_clean_loop = gametime->get_time() + 0.1f;
						}
					}
				}
				if (myhero->has_buff_type(buff_type::Snare))
				{
					auto buff = myhero->get_buff_by_type(buff_type::Snare);
					if (buff != nullptr && buff->is_valid() && buff->is_alive())
					{
						if (cc_time_loop < gametime->get_time())
						{
							Snare_time = gametime->get_time();
							cc_time_loop = gametime->get_time() + buff->get_remaining_time();
						}
						if (cc_clean_loop < gametime->get_time())
						{
							clean_cc_logic(Snare_time, buff->get_remaining_time(), summoner::cleanse->get_bool(), summoner::Snare_cleanse->get_int(), item::qss->get_bool(), item::Snare_qss->get_int(), item::mikael->get_bool(), myhero, item::Snare_mikael->get_int());
							cc_clean_loop = gametime->get_time() + 0.1f;
						}
					}
				}
				if (myhero->has_buff_type(buff_type::Slow) && myhero->get_move_speed() < 250)
				{
					auto buff = myhero->get_buff_by_type(buff_type::Slow);
					if (buff != nullptr && buff->is_valid() && buff->is_alive())
					{
						if (cc_time_loop < gametime->get_time())
						{
							Slow_time = gametime->get_time();
							cc_time_loop = gametime->get_time() + buff->get_remaining_time();
						}
						if (cc_clean_loop < gametime->get_time())
						{
							clean_cc_logic(Slow_time, buff->get_remaining_time(), summoner::cleanse->get_bool(), summoner::Slow_cleanse->get_int(), item::qss->get_bool(), item::Slow_qss->get_int(), item::mikael->get_bool(), myhero, item::Slow_mikael->get_int());
							cc_clean_loop = gametime->get_time() + 0.1f;
						}
					}
				}
				if (myhero->has_buff_type(buff_type::Blind))
				{
					auto buff = myhero->get_buff_by_type(buff_type::Blind);
					if (buff != nullptr && buff->is_valid() && buff->is_alive())
					{
						if (cc_time_loop < gametime->get_time())
						{
							Blind_time = gametime->get_time();
							cc_time_loop = gametime->get_time() + buff->get_remaining_time();
						}
						if (cc_clean_loop < gametime->get_time())
						{
							clean_cc_logic(Blind_time, buff->get_remaining_time(), summoner::cleanse->get_bool(), summoner::Blind_cleanse->get_int(), item::qss->get_bool(), item::Blind_qss->get_int(), item::mikael->get_bool(), myhero, 0);
							cc_clean_loop = gametime->get_time() + 0.1f;
						}
					}
				}
				if (myhero->has_buff_type(buff_type::Disarm))
				{
					auto buff = myhero->get_buff_by_type(buff_type::Disarm);
					if (buff != nullptr && buff->is_valid() && buff->is_alive())
					{
						if (cc_time_loop < gametime->get_time())
						{
							Disarm_time = gametime->get_time();
							cc_time_loop = gametime->get_time() + buff->get_remaining_time();
						}
						if (cc_clean_loop < gametime->get_time())
						{
							clean_cc_logic(Disarm_time, buff->get_remaining_time(), summoner::cleanse->get_bool(), summoner::Disarm_cleanse->get_int(), item::qss->get_bool(), item::Disarm_qss->get_int(), item::mikael->get_bool(), myhero, 0);
							cc_clean_loop = gametime->get_time() + 0.1f;
						}
					}
				}
				if (myhero->has_buff_type(buff_type::Silence))
				{
					auto buff = myhero->get_buff_by_type(buff_type::Silence);
					if (buff != nullptr && buff->is_valid() && buff->is_alive())
					{
						if (cc_time_loop < gametime->get_time())
						{
							Silence_time = gametime->get_time();
							cc_time_loop = gametime->get_time() + buff->get_remaining_time();
						}
						if (cc_clean_loop < gametime->get_time())
						{
							clean_cc_logic(Silence_time, buff->get_remaining_time(), summoner::cleanse->get_bool(), summoner::Silence_cleanse->get_int(), item::qss->get_bool(), item::Silence_qss->get_int(), item::mikael->get_bool(), myhero, item::Silence_mikael->get_int());
							cc_clean_loop = gametime->get_time() + 0.1f;
						}
					}
				}
				if (myhero->has_buff_type(buff_type::NearSight))
				{
					auto buff = myhero->get_buff_by_type(buff_type::NearSight);
					if (buff != nullptr && buff->is_valid() && buff->is_alive())
					{
						if (cc_time_loop < gametime->get_time())
						{
							NearSight_time = gametime->get_time();
							cc_time_loop = gametime->get_time() + buff->get_remaining_time();
						}
						if (cc_clean_loop < gametime->get_time())
						{
							clean_cc_logic(NearSight_time, buff->get_remaining_time(), summoner::cleanse->get_bool(), summoner::NearSight_cleanse->get_int(), item::qss->get_bool(), item::NearSight_qss->get_int(), item::mikael->get_bool(), myhero, 0);
							cc_clean_loop = gametime->get_time() + 0.1f;
						}
					}
				}
				if (myhero->has_buff_type(buff_type::Suppression))
				{
					auto buff = myhero->get_buff_by_type(buff_type::Suppression);
					if (buff != nullptr && buff->is_valid() && buff->is_alive())
					{
						if (cc_time_loop < gametime->get_time())
						{
							Suppression_time = gametime->get_time();
							cc_time_loop = gametime->get_time() + buff->get_remaining_time();
						}
						if (cc_clean_loop < gametime->get_time())
						{
							clean_cc_logic(Suppression_time, buff->get_remaining_time(), summoner::cleanse->get_bool(), 0, item::qss->get_bool(), item::Suppression_qss->get_int(), item::mikael->get_bool(), myhero, 0);
							cc_clean_loop = gametime->get_time() + 0.1f;
						}
					}
				}
			}
		}
	}
	void clean_cc_logic(float time, float duration, bool use_cleanse, int cleanse_danger, bool use_qss, int qss_danger, bool use_mikael, game_object_script target, int mikael_danger)
	{
		Item qss_1(ItemId::Quicksilver_Sash, 0);
		Item qss_2(ItemId::Mercurial_Scimitar, 0);
		Item qss_3(ItemId::Silvermere_Dawn, 0);
		Item mikael(ItemId::Mikaels_Blessing, 650);
		if (mikael.is_ready() && use_mikael == true)
		{
			if (mikael_danger == 0)
			{
				return;
			}
			else if (mikael_danger == 1)
			{
				if (summoner::cleanse_danger_level_1_alway_use->get_bool())
				{
					mikael.cast(target);
				}
				else
				{
					if ((orbwalker->combo_mode() && summoner::cleanse_danger_level_1_combo->get_bool()) || (orbwalker->mixed_mode() && summoner::cleanse_danger_level_1_harass->get_bool()) || (!orbwalker->combo_mode() && !orbwalker->mixed_mode() && summoner::cleanse_danger_level_1_other->get_bool()))
					{
						if (target->get_health_percent() <= summoner::cleanse_danger_level_1_hp->get_int() || target->get_position().count_enemies_in_range(summoner::cleanse_danger_level_1_enemy_range->get_int()) >= summoner::cleanse_danger_level_1_enemy_count->get_int())
						{
							if (duration >= summoner::cleanse_danger_level_1_duration->get_int() / 1000.0f)
							{
								float clean_time = gametime->get_time() - time > summoner::cleanse_danger_level_1_delay->get_int() / 1000.0f ? 0 : time + summoner::cleanse_danger_level_1_delay->get_int() / 1000.0f - gametime->get_time();
								//myhero->print_chat(1, "clean time : %f", clean_time);
								scheduler->delay_action(clean_time, [target]
									{
										Item mikael(ItemId::Mikaels_Blessing, 650);
										if (mikael.is_ready())
										{
											mikael.cast(target);
										}
										//myhero->print_chat(1, "clean time %f", gametime->get_time() - time);
										//myhero->print_chat(1, "%s !!", target->get_name_cstr());
									});
							}
						}
					}

				}
			}
			else if (mikael_danger == 2)
			{
				if (summoner::cleanse_danger_level_2_alway_use->get_bool())
				{
					mikael.cast(target);
				}
				else
				{
					if ((orbwalker->combo_mode() && summoner::cleanse_danger_level_2_combo->get_bool()) || (orbwalker->mixed_mode() && summoner::cleanse_danger_level_2_harass->get_bool()) || (!orbwalker->combo_mode() && !orbwalker->mixed_mode() && summoner::cleanse_danger_level_2_other->get_bool()))
					{
						if (target->get_health_percent() <= summoner::cleanse_danger_level_2_hp->get_int() || target->get_position().count_enemies_in_range(summoner::cleanse_danger_level_2_enemy_range->get_int()) >= summoner::cleanse_danger_level_2_enemy_count->get_int())
						{
							if (duration >= summoner::cleanse_danger_level_2_duration->get_int() / 1000.0f)
							{
								float clean_time = gametime->get_time() - time > summoner::cleanse_danger_level_2_delay->get_int() / 1000.0f ? 0 : time + summoner::cleanse_danger_level_2_delay->get_int() / 1000.0f - gametime->get_time();
								//myhero->print_chat(1, "clean time : %f", clean_time);
								scheduler->delay_action(clean_time, [target]
									{
										Item mikael(ItemId::Mikaels_Blessing, 650);
										if (mikael.is_ready())
										{
											mikael.cast(target);
										}
										//myhero->print_chat(1, "clean time %f", gametime->get_time() - time);
										//myhero->print_chat(1, "%s !!", target->get_name_cstr());
									});
							}
						}
					}

				}
			}
			else if (mikael_danger == 3)
			{
				if (summoner::cleanse_danger_level_3_alway_use->get_bool())
				{
					mikael.cast(target);
				}
				else
				{
					if ((orbwalker->combo_mode() && summoner::cleanse_danger_level_3_combo->get_bool()) || (orbwalker->mixed_mode() && summoner::cleanse_danger_level_3_harass->get_bool()) || (!orbwalker->combo_mode() && !orbwalker->mixed_mode() && summoner::cleanse_danger_level_3_other->get_bool()))
					{
						if (target->get_health_percent() <= summoner::cleanse_danger_level_3_hp->get_int() || target->get_position().count_enemies_in_range(summoner::cleanse_danger_level_3_enemy_range->get_int()) >= summoner::cleanse_danger_level_3_enemy_count->get_int())
						{
							if (duration >= summoner::cleanse_danger_level_3_duration->get_int() / 1000.0f)
							{
								float clean_time = gametime->get_time() - time > summoner::cleanse_danger_level_3_delay->get_int() / 1000.0f ? 0 : time + summoner::cleanse_danger_level_3_delay->get_int() / 1000.0f - gametime->get_time();
								//myhero->print_chat(1, "clean time : %f", clean_time);
								scheduler->delay_action(clean_time, [target]
									{
										Item mikael(ItemId::Mikaels_Blessing, 650);
										if (mikael.is_ready())
										{
											mikael.cast(target);
										}
										//myhero->print_chat(1, "clean time %f", gametime->get_time() - time);
										//myhero->print_chat(1, "%s !!", target->get_name_cstr());
									});
							}
						}
					}

				}
			}
			else if (mikael_danger == 4)
			{
				if (summoner::cleanse_danger_level_4_alway_use->get_bool())
				{
					mikael.cast(target);
				}
				else
				{
					if ((orbwalker->combo_mode() && summoner::cleanse_danger_level_4_combo->get_bool()) || (orbwalker->mixed_mode() && summoner::cleanse_danger_level_4_harass->get_bool()) || (!orbwalker->combo_mode() && !orbwalker->mixed_mode() && summoner::cleanse_danger_level_4_other->get_bool()))
					{
						if (target->get_health_percent() <= summoner::cleanse_danger_level_4_hp->get_int() || target->get_position().count_enemies_in_range(summoner::cleanse_danger_level_4_enemy_range->get_int()) >= summoner::cleanse_danger_level_4_enemy_count->get_int())
						{
							if (duration >= summoner::cleanse_danger_level_4_duration->get_int() / 1000.0f)
							{
								float clean_time = gametime->get_time() - time > summoner::cleanse_danger_level_4_delay->get_int() / 1000.0f ? 0 : time + summoner::cleanse_danger_level_4_delay->get_int() / 1000.0f - gametime->get_time();
								//myhero->print_chat(1, "clean time : %f", clean_time);
								scheduler->delay_action(clean_time, [target]
									{
										Item mikael(ItemId::Mikaels_Blessing, 650);
										if (mikael.is_ready())
										{
											mikael.cast(target);
										}
										//myhero->print_chat(1, "clean time %f", gametime->get_time() - time);
										//myhero->print_chat(1, "%s !!", target->get_name_cstr());
									});
							}
						}
					}

				}
			}
		}
		if ((qss_1.is_ready() || qss_2.is_ready() || qss_3.is_ready()) && use_qss == true && target == myhero)
		{
			if (qss_danger == 0)
			{
				return;
			}
			else if (qss_danger == 1)
			{
				if (summoner::cleanse_danger_level_1_alway_use->get_bool())
				{
					cast_qss();
				}
				else
				{
					if ((orbwalker->combo_mode() && summoner::cleanse_danger_level_1_combo->get_bool()) || (orbwalker->mixed_mode() && summoner::cleanse_danger_level_1_harass->get_bool()) || (!orbwalker->combo_mode() && !orbwalker->mixed_mode() && summoner::cleanse_danger_level_1_other->get_bool()))
					{
						if (myhero->get_health_percent() <= summoner::cleanse_danger_level_1_hp->get_int() || myhero->get_position().count_enemies_in_range(summoner::cleanse_danger_level_1_enemy_range->get_int()) >= summoner::cleanse_danger_level_1_enemy_count->get_int())
						{
							if (duration >= summoner::cleanse_danger_level_1_duration->get_int() / 1000.0f)
							{
								float clean_time = gametime->get_time() - time > summoner::cleanse_danger_level_1_delay->get_int() / 1000.0f ? 0 : time + summoner::cleanse_danger_level_1_delay->get_int() / 1000.0f - gametime->get_time();
								//myhero->print_chat(1, "clean time : %f", clean_time);
								scheduler->delay_action(clean_time, []
									{
										cast_qss();
										//myhero->print_chat(1, "clean time %f", gametime->get_time() - time);
										//myhero->print_chat(1, "%s !!", myhero->get_name_cstr());
									});
							}
						}
					}

				}
			}
			else if (qss_danger == 2)
			{
				if (summoner::cleanse_danger_level_2_alway_use->get_bool())
				{
					cast_qss();
				}
				else
				{
					if ((orbwalker->combo_mode() && summoner::cleanse_danger_level_2_combo->get_bool()) || (orbwalker->mixed_mode() && summoner::cleanse_danger_level_2_harass->get_bool()) || (!orbwalker->combo_mode() && !orbwalker->mixed_mode() && summoner::cleanse_danger_level_2_other->get_bool()))
					{
						if (myhero->get_health_percent() <= summoner::cleanse_danger_level_2_hp->get_int() || myhero->get_position().count_enemies_in_range(summoner::cleanse_danger_level_2_enemy_range->get_int()) >= summoner::cleanse_danger_level_2_enemy_count->get_int())
						{
							if (duration >= summoner::cleanse_danger_level_2_duration->get_int() / 1000.0f)
							{
								float clean_time = gametime->get_time() - time > summoner::cleanse_danger_level_2_delay->get_int() / 1000.0f ? 0 : time + summoner::cleanse_danger_level_2_delay->get_int() / 1000.0f - gametime->get_time();
								//myhero->print_chat(1, "clean time : %f", clean_time);
								scheduler->delay_action(clean_time, []
									{
										cast_qss();
										//myhero->print_chat(1, "clean time %f", gametime->get_time() - time);
										//myhero->print_chat(1, "%s !!", myhero->get_name_cstr());
									});
							}
						}
					}

				}
			}
			else if (qss_danger == 3)
			{
				if (summoner::cleanse_danger_level_3_alway_use->get_bool())
				{
					cast_qss();
				}
				else
				{
					if ((orbwalker->combo_mode() && summoner::cleanse_danger_level_3_combo->get_bool()) || (orbwalker->mixed_mode() && summoner::cleanse_danger_level_3_harass->get_bool()) || (!orbwalker->combo_mode() && !orbwalker->mixed_mode() && summoner::cleanse_danger_level_3_other->get_bool()))
					{
						if (myhero->get_health_percent() <= summoner::cleanse_danger_level_3_hp->get_int() || myhero->get_position().count_enemies_in_range(summoner::cleanse_danger_level_3_enemy_range->get_int()) >= summoner::cleanse_danger_level_3_enemy_count->get_int())
						{
							if (duration >= summoner::cleanse_danger_level_3_duration->get_int() / 1000.0f)
							{
								float clean_time = gametime->get_time() - time > summoner::cleanse_danger_level_3_delay->get_int() / 1000.0f ? 0 : time + summoner::cleanse_danger_level_3_delay->get_int() / 1000.0f - gametime->get_time();
								//myhero->print_chat(1, "clean time : %f", clean_time);
								scheduler->delay_action(clean_time, []
									{
										cast_qss();
										//myhero->print_chat(1, "clean time %f", gametime->get_time() - time);
										//myhero->print_chat(1, "%s !!", myhero->get_name_cstr());
									});
							}
						}
					}

				}
			}
			else if (qss_danger == 4)
			{
				if (summoner::cleanse_danger_level_4_alway_use->get_bool())
				{
					cast_qss();
				}
				else
				{
					if ((orbwalker->combo_mode() && summoner::cleanse_danger_level_4_combo->get_bool()) || (orbwalker->mixed_mode() && summoner::cleanse_danger_level_4_harass->get_bool()) || (!orbwalker->combo_mode() && !orbwalker->mixed_mode() && summoner::cleanse_danger_level_4_other->get_bool()))
					{
						if (myhero->get_health_percent() <= summoner::cleanse_danger_level_4_hp->get_int() || myhero->get_position().count_enemies_in_range(summoner::cleanse_danger_level_4_enemy_range->get_int()) >= summoner::cleanse_danger_level_4_enemy_count->get_int())
						{
							if (duration >= summoner::cleanse_danger_level_4_duration->get_int() / 1000.0f)
							{
								float clean_time = gametime->get_time() - time > summoner::cleanse_danger_level_4_delay->get_int() / 1000.0f ? 0 : time + summoner::cleanse_danger_level_4_delay->get_int() / 1000.0f - gametime->get_time();
								//myhero->print_chat(1, "clean time : %f", clean_time);
								scheduler->delay_action(clean_time, []
									{
										cast_qss();
										//myhero->print_chat(1, "clean time %f", gametime->get_time() - time);
										//myhero->print_chat(1, "%s !!", myhero->get_name_cstr());
									});
							}
						}
					}

				}
			}
		}
		if (cleanse && cleanse->is_ready() && use_cleanse == true && target == myhero &&
			((myhero->has_item(ItemId::Quicksilver_Sash) != spellslot::invalid && !qss_1.is_ready()) ||
				(myhero->has_item(ItemId::Mercurial_Scimitar) != spellslot::invalid && !qss_2.is_ready()) ||
				(myhero->has_item(ItemId::Silvermere_Dawn) != spellslot::invalid && !qss_3.is_ready()) ||
				(myhero->has_item(ItemId::Quicksilver_Sash) == spellslot::invalid &&
				myhero->has_item(ItemId::Mercurial_Scimitar) == spellslot::invalid &&
				myhero->has_item(ItemId::Silvermere_Dawn) == spellslot::invalid)))
		{
			if (cleanse_danger == 0)
			{
				return;
			}
			else if (cleanse_danger == 1)
			{
				if (summoner::cleanse_danger_level_1_alway_use->get_bool())
				{
					cleanse->cast();
				}
				else
				{
					if ((orbwalker->combo_mode() && summoner::cleanse_danger_level_1_combo->get_bool()) || (orbwalker->mixed_mode() && summoner::cleanse_danger_level_1_harass->get_bool()) || (!orbwalker->combo_mode() && !orbwalker->mixed_mode() && summoner::cleanse_danger_level_1_other->get_bool()))
					{
						if (myhero->get_health_percent() <= summoner::cleanse_danger_level_1_hp->get_int() || myhero->get_position().count_enemies_in_range(summoner::cleanse_danger_level_1_enemy_range->get_int()) >= summoner::cleanse_danger_level_1_enemy_count->get_int())
						{
							if (duration >= summoner::cleanse_danger_level_1_duration->get_int() / 1000.0f)
							{
								float clean_time = gametime->get_time() - time > summoner::cleanse_danger_level_1_delay->get_int() / 1000.0f ? 0 : time + summoner::cleanse_danger_level_1_delay->get_int() / 1000.0f - gametime->get_time();
								//myhero->print_chat(1, "clean time : %f", clean_time);
								scheduler->delay_action(clean_time, []
									{
										cleanse->cast();
										//myhero->print_chat(1, "clean time %f", gametime->get_time() - time);
										//myhero->print_chat(1, "%s !!", myhero->get_name_cstr());
									});
							}
						}
					}

				}
			}
			else if (cleanse_danger == 2)
			{
				if (summoner::cleanse_danger_level_2_alway_use->get_bool())
				{
					cleanse->cast(myhero);
				}
				else
				{
					if ((orbwalker->combo_mode() && summoner::cleanse_danger_level_2_combo->get_bool()) || (orbwalker->mixed_mode() && summoner::cleanse_danger_level_2_harass->get_bool()) || (!orbwalker->combo_mode() && !orbwalker->mixed_mode() && summoner::cleanse_danger_level_2_other->get_bool()))
					{
						if (myhero->get_health_percent() <= summoner::cleanse_danger_level_2_hp->get_int() || myhero->get_position().count_enemies_in_range(summoner::cleanse_danger_level_2_enemy_range->get_int()) >= summoner::cleanse_danger_level_2_enemy_count->get_int())
						{
							if (duration >= summoner::cleanse_danger_level_2_duration->get_int() / 1000.0f)
							{
								float clean_time = gametime->get_time() - time > summoner::cleanse_danger_level_2_delay->get_int() / 1000.0f ? 0 : time + summoner::cleanse_danger_level_2_delay->get_int() / 1000.0f - gametime->get_time();
								//myhero->print_chat(1, "clean time : %f", clean_time);
								scheduler->delay_action(clean_time, []
									{
										cleanse->cast();
										//myhero->print_chat(1, "clean time %f", gametime->get_time() - time);
										//myhero->print_chat(1, "%s !!", myhero->get_name_cstr());
									});
							}
						}
					}

				}
			}
			else if (cleanse_danger == 3)
			{
				if (summoner::cleanse_danger_level_3_alway_use->get_bool())
				{
					cleanse->cast(myhero);
				}
				else
				{
					if ((orbwalker->combo_mode() && summoner::cleanse_danger_level_3_combo->get_bool()) || (orbwalker->mixed_mode() && summoner::cleanse_danger_level_3_harass->get_bool()) || (!orbwalker->combo_mode() && !orbwalker->mixed_mode() && summoner::cleanse_danger_level_3_other->get_bool()))
					{
						if (myhero->get_health_percent() <= summoner::cleanse_danger_level_3_hp->get_int() || myhero->get_position().count_enemies_in_range(summoner::cleanse_danger_level_3_enemy_range->get_int()) >= summoner::cleanse_danger_level_3_enemy_count->get_int())
						{
							if (duration >= summoner::cleanse_danger_level_3_duration->get_int() / 1000.0f)
							{
								float clean_time = gametime->get_time() - time > summoner::cleanse_danger_level_3_delay->get_int() / 1000.0f ? 0 : time + summoner::cleanse_danger_level_3_delay->get_int() / 1000.0f - gametime->get_time();
								//myhero->print_chat(1, "clean time : %f", clean_time);
								scheduler->delay_action(clean_time, []
									{
										cleanse->cast();
										//myhero->print_chat(1, "clean time %f", gametime->get_time() - time);
										//myhero->print_chat(1, "%s !!", myhero->get_name_cstr());
									});
							}
						}
					}

				}
			}
			else if (cleanse_danger == 4)
			{
				if (summoner::cleanse_danger_level_4_alway_use->get_bool())
				{
					cleanse->cast();
				}
				else
				{
					if ((orbwalker->combo_mode() && summoner::cleanse_danger_level_4_combo->get_bool()) || (orbwalker->mixed_mode() && summoner::cleanse_danger_level_4_harass->get_bool()) || (!orbwalker->combo_mode() && !orbwalker->mixed_mode() && summoner::cleanse_danger_level_4_other->get_bool()))
					{
						if (myhero->get_health_percent() <= summoner::cleanse_danger_level_4_hp->get_int() || myhero->get_position().count_enemies_in_range(summoner::cleanse_danger_level_4_enemy_range->get_int()) >= summoner::cleanse_danger_level_4_enemy_count->get_int())
						{
							if (duration >= summoner::cleanse_danger_level_4_duration->get_int() / 1000.0f)
							{
								float clean_time = gametime->get_time() - time > summoner::cleanse_danger_level_4_delay->get_int() / 1000.0f ? 0 : time + summoner::cleanse_danger_level_4_delay->get_int() / 1000.0f - gametime->get_time();
								//myhero->print_chat(1, "clean time : %f", clean_time);
								scheduler->delay_action(clean_time, []
									{
										cleanse->cast();
										//myhero->print_chat(1, "clean time %f", gametime->get_time() - time);
										//myhero->print_chat(1, "%s !!", myhero->get_name_cstr());
									});
							}
						}
					}

				}
			}
		}
	}
	void cast_qss()
	{
		Item qss_1(ItemId::Quicksilver_Sash, 0);
		Item qss_2(ItemId::Mercurial_Scimitar, 0);
		Item qss_3(ItemId::Silvermere_Dawn, 0);
		if (qss_1.is_ready())
		{
			qss_1.cast();
		}
		else if (qss_2.is_ready())
		{
			qss_2.cast();
		}
		else if (qss_3.is_ready())
		{
			qss_3.cast();
		}
	}
	//鐵刺
	void use_ironspike()
	{
		if (item::ironspike->get_bool())
		{
			Item ironspike(ItemId::Ironspike_Whip, 400);
			if (ironspike.is_ready())
			{
				if (orbwalker->combo_mode())
				{
					auto enemy = entitylist->get_enemy_heroes();

					enemy.erase(std::remove_if(enemy.begin(), enemy.end(), [](game_object_script x)
						{
							return x->is_dead() || !x->is_valid_target(400) || myhero->is_in_auto_attack_range(x);
						}), enemy.end());

					if (!enemy.empty())
					{
						ironspike.cast();
					}
				}
				if (orbwalker->mixed_mode())
				{
					auto enemy = entitylist->get_enemy_heroes();

					enemy.erase(std::remove_if(enemy.begin(), enemy.end(), [](game_object_script x)
						{
							return x->is_dead() || !x->is_valid_target(400);
						}), enemy.end());

					if (!enemy.empty())
					{
						ironspike.cast();
					}
				}
				if (orbwalker->lane_clear_mode())
				{
					if (A_Klee::count_minions_in_range(430) >= item::ironspike_lane_clear->get_int())
					{
						ironspike.cast();
					}
					if (A_Klee::count_monsters_in_range(430) >= item::ironspike_jungle_clear->get_int())
					{
						ironspike.cast();
					}
				}
				if (orbwalker->lane_clear_mode() && (orbwalker->get_orb_state() == (orbwalker_state_flags::fast_lane_clear | orbwalker_state_flags::lane_clear)))
				{
					if (A_Klee::count_minions_in_range(430) >= 1 || A_Klee::count_monsters_in_range(430) >= 1)
					{
						ironspike.cast();
					}
				}
			}
		}
	}
	//挺進
	void use_stridebreaker()
	{
		if (item::stridebreaker->get_bool())
		{
			Item stridebreaker(ItemId::Stridebreaker, 400);
			if (stridebreaker.is_ready())
			{
				auto enemy = entitylist->get_enemy_heroes();

				enemy.erase(std::remove_if(enemy.begin(), enemy.end(), [](game_object_script x)
					{
						return x->is_dead() || !x->is_valid_target(400) || !A_Klee::checkbox(item::stridebreaker_always_use_on, x);
					}), enemy.end());

				if (!enemy.empty())
				{
					for (auto& enemy : enemy)
					{
						if (!enemy->has_buff_type(buff_type::Slow) && enemy->get_move_speed() < 250)
						{
							stridebreaker.cast();
						}
					}
				}
				if (orbwalker->combo_mode())
				{
					auto enemy = entitylist->get_enemy_heroes();

					enemy.erase(std::remove_if(enemy.begin(), enemy.end(), [](game_object_script x)
						{
							return x->is_dead() || !x->is_valid_target(400);
						}), enemy.end());

					if (!enemy.empty())
					{
						for (auto& enemy : enemy)
						{
							if (!myhero->is_in_auto_attack_range(enemy))
							{
								if (myhero->get_position().count_enemies_in_range(400) >= item::stridebreaker_combo_count_hero->get_int())
								{
									stridebreaker.cast();
								}
							}
						}
					}
				}
				if (orbwalker->mixed_mode())
				{
					auto target = target_selector->get_target(400, damage_type::true_dmg);
					if (target != nullptr)
					{
						stridebreaker.cast();
					}
				}
				if (orbwalker->lane_clear_mode())
				{
					if (A_Klee::count_minions_in_range(430) >= item::stridebreaker_lane_clear->get_int())
					{
						stridebreaker.cast();
					}
					if (A_Klee::count_monsters_in_range(430) >= item::stridebreaker_jungle_clear->get_int())
					{
						stridebreaker.cast();
					}
				}
				if (orbwalker->lane_clear_mode() && (orbwalker->get_orb_state() == (orbwalker_state_flags::fast_lane_clear | orbwalker_state_flags::lane_clear)))
				{
					if (A_Klee::count_minions_in_range(430) >= 1 || A_Klee::count_monsters_in_range(430) >= 1)
					{
						stridebreaker.cast();
					}
				}
			}
		}
	}
	//渴血
	void use_goredrinker()
	{
		if (item::goredrinker->get_bool())
		{
			Item goredrinker(ItemId::Goredrinker, 400);
			if (goredrinker.is_ready())
			{
				if (myhero->get_position().count_enemies_in_range(440) >= item::goredrinker_auto_use->get_int())
				{
					goredrinker.cast();
				}
				if (orbwalker->combo_mode())
				{
					auto enemy = entitylist->get_enemy_heroes();

					enemy.erase(std::remove_if(enemy.begin(), enemy.end(), [](game_object_script x)
						{
							return x->is_dead() || !x->is_valid_target(400);
						}), enemy.end());

					if (!enemy.empty())
					{
						for (auto& enemy : enemy)
						{
							if (!myhero->is_in_auto_attack_range(enemy))
							{
								if (myhero->get_position().count_enemies_in_range(400) >= item::goredrinker_combo_count_hero->get_int())
								{
									goredrinker.cast();
								}
								if (myhero->get_health_percent() <= item::goredrinker_combo_hp->get_int())
								{
									auto target = target_selector->get_target(400, damage_type::true_dmg);
									if (target != nullptr)
									{
										goredrinker.cast();
									}
								}
							}
						}
					}
				}
				if (orbwalker->mixed_mode())
				{
					auto target = target_selector->get_target(400, damage_type::true_dmg);
					if (target != nullptr)
					{
						goredrinker.cast();
					}
				}
				if (orbwalker->lane_clear_mode())
				{
					if (A_Klee::count_minions_in_range(430) >= item::goredrinker_lane_clear->get_int())
					{
						goredrinker.cast();
					}
					if (A_Klee::count_monsters_in_range(430) >= item::goredrinker_jungle_clear->get_int())
					{
						goredrinker.cast();
					}
				}
				if (orbwalker->lane_clear_mode() && (orbwalker->get_orb_state() == (orbwalker_state_flags::fast_lane_clear | orbwalker_state_flags::lane_clear)))
				{
					if (A_Klee::count_minions_in_range(430) >= 1 || A_Klee::count_monsters_in_range(430) >= 1)
					{
						goredrinker.cast();
					}
				}
			}
		}
	}
	//石像鬼
	void use_gargoyle_stoneplate()
	{
		if (item::gargoyle_stoneplate->get_bool())
		{
			Item gargoyle_stoneplate(ItemId::Gargoyle_Stoneplate, 0);
			if (gargoyle_stoneplate.is_ready())
			{
				if (myhero->get_health() - health_prediction->get_incoming_damage(myhero, 0.5f, false) <= 0.0f)
				{
					gargoyle_stoneplate.cast();
				}
				if (myhero->get_health_percent() <= item::gargoyle_stoneplate_hp->get_int())
				{
					if (myhero->get_position().count_enemies_in_range(600) >= 1)
					{
						gargoyle_stoneplate.cast();
					}
				}
				if (myhero->get_health_percent() <= item::gargoyle_stoneplate_damage_hp->get_int())
				{
					gargoyle_stoneplate_shield = (myhero->get_max_health() - myhero->get_base_hp() - myhero->get_hpPerLevel() * (myhero->get_level() - 1)) < 0 ? 100 : (100 + myhero->get_max_health() - myhero->get_base_hp() - myhero->get_hpPerLevel() * (myhero->get_level() - 1));
					if (health_prediction->get_incoming_damage(myhero, 0.5f, false) >= gargoyle_stoneplate_shield * item::gargoyle_stoneplate_damage->get_int() / 100.0f)
					{
						gargoyle_stoneplate.cast();
					}
				}
			}
		}
	}
	//蘭頓
	void use_randuins()
	{
		if (item::randuins->get_bool())
		{
			Item randuins(ItemId::Randuins_Omen, 450);
			if (randuins.is_ready())
			{
				auto enemy = entitylist->get_enemy_heroes();

				enemy.erase(std::remove_if(enemy.begin(), enemy.end(), [](game_object_script x)
					{
						return x->is_dead() || !x->is_valid_target(500) || !A_Klee::checkbox(item::randuins_always_use_on, x);
					}), enemy.end());

				if (!enemy.empty())
				{
					for (auto& enemy : enemy)
					{
						if (!enemy->has_buff_type(buff_type::Slow) && enemy->get_move_speed() < 250)
						{
							randuins.cast();
						}
					}
				}
			}
		}
	}
	//塔里克E
#pragma region taric_e_logic
	void taric_e_logic()
	{
		if (gametime->get_time() > taric_last_e_time && gametime->get_time() < taric_last_e_time + 1.0f)
		{
			auto target = target_selector->get_target(575 + 300, damage_type::magical);
			if (target != nullptr)
			{
				e_115_distance = target->get_distance(myhero->get_position() + taric_e_115_pos);
				e_230_distance = target->get_distance(myhero->get_position() + taric_e_230_pos);
				e_345_distance = target->get_distance(myhero->get_position() + taric_e_345_pos);
				e_460_distance = target->get_distance(myhero->get_position() + taric_e_460_pos);

				float distance[4] = { e_115_distance, e_230_distance, e_345_distance, e_460_distance }; //小>大
				std::sort(distance, distance + 4);

				geometry::rectangle e_sector = geometry::rectangle(
					myhero->get_position(),
					myhero->get_position() + taric_e_575_pos,
					50.0f);
				auto poly = e_sector.to_polygon();

				if (poly.is_inside(target->get_position()))
				{
					orbwalker->set_movement(true);
					orbwalker->set_attack(true);
					return;
				}
				else
				{
					if (distance[0] == e_115_distance)
					{
						auto move_pos = (target->get_position() - (myhero->get_position() + taric_e_115_pos)).normalized() * e_115_distance;
						if ((!(myhero->get_position() + move_pos).is_under_enemy_turret() || !hero::taric_e_tower->get_bool()) && !(myhero->get_position() + move_pos).is_wall())
						{
							orbwalker->set_movement(false);
							orbwalker->set_attack(false);
							orb_check = true;
							myhero->issue_order(myhero->get_position() + move_pos);
						}
					}
					else if (distance[0] == e_230_distance)
					{
						auto move_pos = (target->get_position() - (myhero->get_position() + taric_e_230_pos)).normalized() * e_230_distance;
						if ((!(myhero->get_position() + move_pos).is_under_enemy_turret() || !hero::taric_e_tower->get_bool()) && !(myhero->get_position() + move_pos).is_wall())
						{
							orbwalker->set_movement(false);
							orbwalker->set_attack(false);
							orb_check = true;
							myhero->issue_order(myhero->get_position() + move_pos);
						}
					}
					else if (distance[0] == e_345_distance)
					{
						auto move_pos = (target->get_position() - (myhero->get_position() + taric_e_345_pos)).normalized() * e_345_distance;
						if ((!(myhero->get_position() + move_pos).is_under_enemy_turret() || !hero::taric_e_tower->get_bool()) && !(myhero->get_position() + move_pos).is_wall())
						{
							orbwalker->set_movement(false);
							orbwalker->set_attack(false);
							orb_check = true;
							myhero->issue_order(myhero->get_position() + move_pos);
						}
					}
					else if (distance[0] == e_460_distance)
					{
						auto move_pos = (target->get_position() - (myhero->get_position() + taric_e_460_pos)).normalized() * e_460_distance;
						if ((!(myhero->get_position() + move_pos).is_under_enemy_turret() || !hero::taric_e_tower->get_bool()) && !(myhero->get_position() + move_pos).is_wall())
						{
							orbwalker->set_movement(false);
							orbwalker->set_attack(false);
							orb_check = true;
							myhero->issue_order(myhero->get_position() + move_pos);
						}
					}
					else
					{
						return;
					}
				}
			}
		}
	}
#pragma endregion
	//cassiopeia dodge r
	void cassiopeia_r_dodge_logic()
	{
		if (gametime->get_time() > cassiopeia_r_time + 0.39f - ping->get_ping() / 1000.0f && cassiopeia_r_time + 0.5f > gametime->get_time())
		{
			auto radius = 700;
			const auto perp = (cassiopeia_end_pos - cassiopeia_start_pos).normalized().perpendicular(); //垂直
			auto cassiopeia_r_left_pos = cassiopeia_end_pos + perp * (radius);
			auto cassiopeia_r_right_pos = cassiopeia_end_pos - perp * (radius);
			cassiopeia_r_left_pos = cassiopeia_r_left_pos.extend(cassiopeia_start_pos, 200.0f);
			cassiopeia_r_right_pos = cassiopeia_r_right_pos.extend(cassiopeia_start_pos, 200.0f);

			geometry::polygon q1_sector;

			q1_sector.add(cassiopeia_start_pos);
			q1_sector.add(cassiopeia_end_pos);
			q1_sector.add(cassiopeia_r_left_pos);
			q1_sector.add(cassiopeia_r_right_pos);

			orbwalker->set_attack(false);
			orbwalker->set_movement(false);
			orb_check = true;
			if (myhero->is_facing(cassiopeia_start_pos) && q1_sector.is_inside(myhero->get_position()))
			{
				auto pos = myhero->get_position().extend(cassiopeia_start_pos, -150);
				myhero->issue_order(pos);

			}
		}
	}
	//xayah e
	int count_xayah_e()
	{
		auto count = 0;
		for (xayah_e xayah_e : xayah_es)
		{
			if (xayah_e.object->is_valid() && !xayah_e.object->is_dead() && xayah_e.object->get_emitter()->is_enemy()) //
			{
				geometry::rectangle e_sector = geometry::rectangle(
					xayah_e.object->get_position(), xayah_e.object->get_emitter()->get_position(), 80.0f);
				auto poly = e_sector.to_polygon();
				if (poly.is_inside(myhero->get_position()))
				{
					count++;
				}
			}
		}
		return count;
	}
	////物件
	void on_create_object(game_object_script sender)
	{
		if (sender->get_name().find("Lantern_cas_green") != std::string::npos) //Lantern
		{
			lanterns.push_back(lantern(sender, lanterns.size() + 1));
		}
		if (sender->get_name().find("Passive_Dagger_Mark8s") != std::string::npos)
		{
			xayah_es.push_back(xayah_e(sender, xayah_es.size() + 1));
		}
		if (sender->get_name().find("E_tar") != std::string::npos)
		{
			xayah_es.push_back(xayah_e(sender, xayah_es.size() + 1));
		}
	}
	void on_delete_object(game_object_script sender)
	{
		if (sender->get_name().find("Lantern_cas_green") != std::string::npos)
		{
			lanterns.erase(std::remove_if(lanterns.begin(), lanterns.end(), [sender](lantern x)
				{
					return x.object->get_network_id() == sender->get_network_id();
				}), lanterns.end());
		}
		if (sender->get_name().find("Passive_Dagger_Mark8s") != std::string::npos)
		{
			xayah_es.erase(std::remove_if(xayah_es.begin(), xayah_es.end(), [sender](xayah_e x)
				{
					return x.object->get_network_id() == sender->get_network_id();
				}), xayah_es.end());
		}
		if (sender->get_name().find("E_tar") != std::string::npos)
		{
			xayah_es.erase(std::remove_if(xayah_es.begin(), xayah_es.end(), [sender](xayah_e x)
				{
					return x.object->get_network_id() == sender->get_network_id();
				}), xayah_es.end());
		}
	}

	//cast
	void on_process_spell_cast(game_object_script sender, spell_instance_script spell)
	{
		auto spell_hash = spell->get_spell_data()->get_name_hash();

		//taric
		if (sender->is_ai_hero())
		{
			if (spell_hash == spell_hash("TaricE") && myhero->get_distance(sender) < 800 && !sender->is_enemy())
			{
				taric_last_e_time = gametime->get_time();
				taric_e_115_pos = (spell->get_end_position() - myhero->get_position()).normalized() * 115;
				taric_e_230_pos = (spell->get_end_position() - myhero->get_position()).normalized() * 230;
				taric_e_345_pos = (spell->get_end_position() - myhero->get_position()).normalized() * 345;
				taric_e_460_pos = (spell->get_end_position() - myhero->get_position()).normalized() * 460;
				taric_e_575_pos = (spell->get_end_position() - myhero->get_position()).normalized() * 575;
			}
		}
		//enemy spell
		if (sender->is_ai_hero())
		{
			auto target = spell->get_last_target_id() > 0 ? entitylist->get_object(spell->get_last_target_id()) : nullptr;

			if (target != nullptr && target == myhero)
			{
				//P
				if (spell->get_spell_data()->get_name() == "AatroxPassiveAttack")
				{
					if (hero::jax_e_aatrox_p->get_bool())
					{
						if (hero::jax_e->get_bool() && e->is_ready() && !myhero->has_buff(buff_hash("JaxCounterStrike")) && myhero->get_champion() == champion_id::Jax)
						{
							if (e->cast())
							{
								return;
							}
						}
					}
				}
				//Q
				else if (spell->get_spell_data()->get_name() == "CamilleQAttackEmpowered")
				{
					if (hero::jax_e_camille_q2->get_bool())
					{
						if (hero::jax_e->get_bool() && e->is_ready() && !myhero->has_buff(buff_hash("JaxCounterStrike")) && myhero->get_champion() == champion_id::Jax)
						{
							if (e->cast())
							{
								return;
							}
						}
					}
				}
				//W
				else if (spell->get_spell_data()->get_name() == "DariusNoxianTacticsONHAttack")
				{
					if (hero::jax_e_darius_w->get_bool())
					{
						if (hero::jax_e->get_bool() && e->is_ready() && !myhero->has_buff(buff_hash("JaxCounterStrike")) && myhero->get_champion() == champion_id::Jax)
						{
							if (e->cast())
							{
								return;
							}
						}
					}
				}
				//Q
				else if (spell->get_spell_data()->get_name() == "GarenQAttack")
				{
					if (hero::jax_e_garen_q->get_bool())
					{
						if (hero::jax_e->get_bool() && e->is_ready() && !myhero->has_buff(buff_hash("JaxCounterStrike")) && myhero->get_champion() == champion_id::Jax)
						{
							if (e->cast())
							{
								return;
							}
						}
					}
				}
				//Q
				else if (spell->get_spell_data()->get_name() == "MonkeyKingQAttack")
				{
					if (hero::jax_e_monkey_q->get_bool())
					{
						if (hero::jax_e->get_bool() && e->is_ready() && !myhero->has_buff(buff_hash("JaxCounterStrike")) && myhero->get_champion() == champion_id::Jax)
						{
							if (e->cast())
							{
								return;
							}
						}
					}
				}
				//W
				else if (spell->get_spell_data()->get_name() == "RenektonExecute")
				{
					if (hero::jax_e_renekton_w->get_bool())
					{
						if (hero::jax_e->get_bool() && e->is_ready() && !myhero->has_buff(buff_hash("JaxCounterStrike")) && myhero->get_champion() == champion_id::Jax)
						{
							if (e->cast())
							{
								return;
							}
						}
					}
				}
				//W
				else if (spell->get_spell_data()->get_name() == "RenektonSuperExecute")
				{
					if (hero::jax_e_renekton_angry_w->get_bool())
					{
						if (hero::jax_e->get_bool() && e->is_ready() && !myhero->has_buff(buff_hash("JaxCounterStrike")) && myhero->get_champion() == champion_id::Jax)
						{
							if (e->cast())
							{
								return;
							}
						}
					}
				}
				//Q
				else if (spell->get_spell_data()->get_name() == "VolibearQAttack")
				{
					if (hero::jax_e_bear_q->get_bool())
					{
						if (hero::jax_e->get_bool() && e->is_ready() && !myhero->has_buff(buff_hash("JaxCounterStrike")) && myhero->get_champion() == champion_id::Jax)
						{
							if (e->cast())
							{
								return;
							}
						}
					}
				}
				//W 卡牌
				else if (spell->get_spell_data()->get_name() == "GoldCardPreAttack")
				{
					if (hero::jax_e_gold_card->get_bool())
					{
						if (hero::jax_e->get_bool() && e->is_ready() && !myhero->has_buff(buff_hash("JaxCounterStrike")) && myhero->get_champion() == champion_id::Jax)
						{
							if (e->cast())
							{
								return;
							}
						}
					}
				}

				else if (spell->get_spell_data()->get_name() == "JaxLeapStrike")
				{

				}
				else if (spell->get_spell_data()->get_name() == "GarenR")
				{

				}
			}
		}
		if (sender->is_ai_hero() && sender->is_enemy())
		{
			if (spell_hash == spell_hash("CassiopeiaR"))
			{
				cassiopeia_r_time = gametime->get_time();
				cassiopeia_start_pos = sender->get_position();
				cassiopeia_end_pos = sender->get_position() + (spell->get_end_position() - sender->get_position()).normalized() * 820;
			}
			if (spell_hash == spell_hash("TwitchExpunge"))
			{
				twitch_use_e = gametime->get_time() + 2.45f - ping->get_ping() / 1000.0f;
				auto buff = myhero->get_buff(buff_hash("TwitchDeadlyVenom"));
				if (buff != nullptr && buff->is_valid() && buff->is_alive())
				{
					count_twitch_e = buff->get_count();
				}
			}
			if (spell_hash == spell_hash("XayahE"))
			{
				xayah_use_e = gametime->get_time() + 0.5f - ping->get_ping() / 1000.0f;
			}
		}

	}
	//使用惩戒
	void cast_smite_monster(game_object_script target)
	{
		if (myhero->get_distance(target) < 560 &&
			(myhero->get_position().count_enemies_in_range(summoner::smite_range->get_int()) > 0 || summoner::smite_range->get_int() == 0))
		{
			//一般懲戒
			if (myhero->get_buff(buff_hash("SmiteDamageTracker")))
			{
				auto buff = myhero->get_buff(buff_hash("SmiteDamageTracker"));
				if (buff != nullptr && buff->is_valid() && buff->is_alive())
				{
					float smite_damage = buff->get_count();
					if ((summoner::use_heal_pred->get_bool() && health_prediction->get_incoming_damage(target, ping->get_ping() / 1000.0f, true)) + smite_damage >= target->get_health() || target->get_health() <= smite_damage)
					{
						if (smite->cast(target))
						{
							return;
						}
					}
				}
			}
			//升级1惩戒
			else if (myhero->get_buff(buff_hash("SmiteDamageTrackerStalker")))
			{
				auto buff = myhero->get_buff(buff_hash("SmiteDamageTrackerStalker"));
				if (buff != nullptr && buff->is_valid() && buff->is_alive())
				{
					if (target->get_bounding_radius() == 65)
					{
						float smite_damage = 500 + target->get_max_health() * 0.1;
						if ((summoner::use_heal_pred->get_bool() && health_prediction->get_incoming_damage(target, ping->get_ping() / 1000.0f, true)) + smite_damage >= target->get_health() || target->get_health() <= smite_damage)
						{
							if (smite->cast(target))
							{
								return;
							}
						}
					}
					else
					{
						float smite_damage = buff->get_count();
						if ((summoner::use_heal_pred->get_bool() && health_prediction->get_incoming_damage(target, ping->get_ping() / 1000.0f, true)) + smite_damage >= target->get_health() || target->get_health() <= smite_damage)
						{
							if (smite->cast(target))
							{
								return;
							}
						}
					}
				}
			}
			//升級2懲戒
			else if (myhero->get_buff(buff_hash("SmiteDamageTrackerAvatar")))
			{
				auto buff = myhero->get_buff(buff_hash("SmiteDamageTrackerAvatar"));
				if (buff != nullptr && buff->is_valid() && buff->is_alive())
				{
					float smite_damage = buff->get_count();
					if (health_prediction->get_incoming_damage(target, ping->get_ping() / 1000.0f, false) + smite_damage >= target->get_health() || target->get_health() <= smite_damage)
					{
						if (smite->cast(target))
						{
							return;
						}
					}
				}
			}
		}
	}
	//After AA
	void on_after_attack_orbwalker(game_object_script target)
	{
		Item ironspike(ItemId::Ironspike_Whip, 400);
		Item goredrinker(ItemId::Goredrinker, 400);
		Item stridebreaker(ItemId::Stridebreaker, 400);
		if (target->is_ai_hero() && orbwalker->combo_mode())
		{
			//鐵刺
			if (ironspike.is_ready() && item::ironspike->get_bool() && item::ironspike_combo->get_bool())
			{
				auto target = target_selector->get_target(400, damage_type::true_dmg);
				if (target != nullptr)
				{
					ironspike.cast();
				}
			}
			//挺進
			if (stridebreaker.is_ready() && item::stridebreaker->get_bool())
			{
				if (myhero->get_position().count_enemies_in_range(400) >= item::stridebreaker_combo_count_hero->get_int())
				{
					stridebreaker.cast();
				}
			}
			//渴血
			if (goredrinker.is_ready() && item::goredrinker->get_bool())
			{
				if (myhero->get_position().count_enemies_in_range(400) >= item::goredrinker_combo_count_hero->get_int())
				{
					goredrinker.cast();
				}
				if (myhero->get_health_percent() <= item::goredrinker_combo_hp->get_int())
				{
					auto target = target_selector->get_target(400, damage_type::true_dmg);
					if (target != nullptr)
					{
						goredrinker.cast();
					}
				}
			}

		}
		if ((target->is_monster() || target->is_minion()) && orbwalker->lane_clear_mode() && !target->is_plant() && target != nullptr)
		{
			if (ironspike.is_ready() && item::ironspike->get_bool())
			{
				if (A_Klee::count_minions_in_range(430) >= item::ironspike_lane_clear_reset_aa->get_int())
				{
					ironspike.cast();
				}
				if (A_Klee::count_monsters_in_range(430) >= item::ironspike_jungle_clear_reset_aa->get_int())
				{
					ironspike.cast();
				}
			}
			if (goredrinker.is_ready() && item::goredrinker->get_bool())
			{
				if (A_Klee::count_minions_in_range(430) >= item::goredrinker_lane_clear_reset_aa->get_int())
				{
					goredrinker.cast();
				}
				if (A_Klee::count_monsters_in_range(430) >= item::goredrinker_jungle_clear_reset_aa->get_int())
				{
					goredrinker.cast();
				}
			}
			if (stridebreaker.is_ready() && item::stridebreaker->get_bool())
			{
				if (A_Klee::count_minions_in_range(430) >= item::stridebreaker_lane_clear_reset_aa->get_int())
				{
					stridebreaker.cast();
				}
				if (A_Klee::count_monsters_in_range(430) >= item::stridebreaker_jungle_clear_reset_aa->get_int())
				{
					stridebreaker.cast();
				}
			}
		}
	}
	//
	void on_issue_order(game_object_script& target, vector& pos, _issue_order_type& type, bool* process)
	{

	}
	void on_draw()
	{
		//惩戒
		if (smite && draw_settings::state_smite->get_bool())
		{
			for (auto& object : entitylist->get_jugnle_mobs_minions())
			{
				if (object->is_valid() && summoner::smite->get_bool())
				{
					//巴龍
					if (summoner::baron->get_bool())
					{
						if (object->get_name().compare("SRU_Baron12.1.1") == 0)
						{
							if (!smite->is_ready())
							{
								draw_manager->add_circle(object->get_position(), summoner::smite_draw_range->get_int(), MAKE_COLOR(255, 255, 255, 50), 3);
							}
							else
							{
								if (myhero->get_distance(object) < 560)
								{
									draw_manager->add_circle(object->get_position(), summoner::smite_draw_range->get_int(), MAKE_COLOR(255, 100, 0, 255), 3);
								}
								else if (myhero->get_distance(object) >= 560)
								{
									draw_manager->add_circle(object->get_position(), summoner::smite_draw_range->get_int(), MAKE_COLOR(255, 255, 255, 255), 3);
								}
							}
						}
					}
					//小龍
					if (summoner::dragon->get_bool())
					{
						if (object->get_name().compare("SRU_Dragon_Hextech") == 0 || object->get_name().compare("SRU_Dragon_Air") == 0 || object->get_name().compare("SRU_Dragon_Earth") == 0 || object->get_name().compare("SRU_Dragon_Fire") == 0 || object->get_name().compare("SRU_Dragon_Water") == 0 || object->get_name().compare("SRU_Dragon_Chemtech") == 0 || object->get_name().compare("SRU_Dragon_Elder") == 0)
						{
							if (!smite->is_ready())
							{
								draw_manager->add_circle(object->get_position(), summoner::smite_draw_range->get_int(), MAKE_COLOR(255, 255, 255, 50), 3);
							}
							else
							{
								if (myhero->get_distance(object) < summoner::smite_draw_range->get_int())
								{
									draw_manager->add_circle(object->get_position(), summoner::smite_draw_range->get_int(), MAKE_COLOR(255, 100, 0, 255), 3);
								}
								else if (myhero->get_distance(object) >= summoner::smite_draw_range->get_int())
								{
									draw_manager->add_circle(object->get_position(), summoner::smite_draw_range->get_int(), MAKE_COLOR(255, 255, 255, 255), 3);
								}
							}
						}
					}
					//大螃蟹
					if (summoner::big_crab->get_bool())
					{
						if (object->get_name().compare("SRU_RiftHerald17.1.1") == 0)
						{
							if (!smite->is_ready())
							{
								draw_manager->add_circle(object->get_position(), summoner::smite_draw_range->get_int(), MAKE_COLOR(255, 255, 255, 50), 3);
							}
							else
							{
								if (myhero->get_distance(object) < summoner::smite_draw_range->get_int())
								{
									draw_manager->add_circle(object->get_position(), summoner::smite_draw_range->get_int(), MAKE_COLOR(255, 100, 0, 255), 3);
								}
								else if (myhero->get_distance(object) >= summoner::smite_draw_range->get_int())
								{
									draw_manager->add_circle(object->get_position(), summoner::smite_draw_range->get_int(), MAKE_COLOR(255, 255, 255, 255), 3);
								}
							}
						}
					}
					//河蟹
					if (summoner::small_crab->get_bool())
					{
						if (object->get_name().compare("Sru_Crab16.1.1") == 0 || object->get_name().compare("Sru_Crab15.1.1") == 0)
						{
							if (!smite->is_ready())
							{
								draw_manager->add_circle(object->get_position(), summoner::smite_draw_range->get_int(), MAKE_COLOR(255, 255, 255, 50), 3);
							}
							else
							{
								if (myhero->get_distance(object) < summoner::smite_draw_range->get_int())
								{
									draw_manager->add_circle(object->get_position(), summoner::smite_draw_range->get_int(), MAKE_COLOR(255, 100, 0, 255), 3);
								}
								else if (myhero->get_distance(object) >= summoner::smite_draw_range->get_int())
								{
									draw_manager->add_circle(object->get_position(), summoner::smite_draw_range->get_int(), MAKE_COLOR(255, 255, 255, 255), 3);
								}
							}
						}
					}
					//紅
					if (summoner::red_buff->get_bool())
					{
						if (object->get_name().compare("SRU_Red4.1.1") == 0 || object->get_name().compare("SRU_Red10.1.1") == 0)
						{
							if (!smite->is_ready())
							{
								draw_manager->add_circle(object->get_position(), summoner::smite_draw_range->get_int(), MAKE_COLOR(255, 255, 255, 50), 3);
							}
							else
							{
								if (myhero->get_distance(object) < summoner::smite_draw_range->get_int())
								{
									draw_manager->add_circle(object->get_position(), summoner::smite_draw_range->get_int(), MAKE_COLOR(255, 100, 0, 255), 3);
								}
								else if (myhero->get_distance(object) >= summoner::smite_draw_range->get_int())
								{
									draw_manager->add_circle(object->get_position(), summoner::smite_draw_range->get_int(), MAKE_COLOR(255, 255, 255, 255), 3);
								}
							}
						}
					}
					//藍
					if (summoner::blue_buff->get_bool())
					{
						if (object->get_name().compare("SRU_Blue1.1.1") == 0 || object->get_name().compare("SRU_Blue7.1.1") == 0)
						{
							if (!smite->is_ready())
							{
								draw_manager->add_circle(object->get_position(), summoner::smite_draw_range->get_int(), MAKE_COLOR(255, 255, 255, 50), 3);
							}
							else
							{
								if (myhero->get_distance(object) < summoner::smite_draw_range->get_int())
								{
									draw_manager->add_circle(object->get_position(), summoner::smite_draw_range->get_int(), MAKE_COLOR(255, 100, 0, 255), 3);
								}
								else if (myhero->get_distance(object) >= summoner::smite_draw_range->get_int())
								{
									draw_manager->add_circle(object->get_position(), summoner::smite_draw_range->get_int(), MAKE_COLOR(255, 255, 255, 255), 3);
								}
							}
						}
					}
					//三狼
					if (summoner::three_wolf->get_bool())
					{
						if (object->get_name().compare("SRU_Murkwolf2.1.1") == 0 || object->get_name().compare("SRU_Murkwolf8.1.1") == 0)
						{
							if (!smite->is_ready())
							{
								draw_manager->add_circle(object->get_position(), summoner::smite_draw_range->get_int(), MAKE_COLOR(255, 255, 255, 50), 3);
							}
							else
							{
								if (myhero->get_distance(object) < summoner::smite_draw_range->get_int())
								{
									draw_manager->add_circle(object->get_position(), summoner::smite_draw_range->get_int(), MAKE_COLOR(255, 100, 0, 255), 3);
								}
								else if (myhero->get_distance(object) >= summoner::smite_draw_range->get_int())
								{
									draw_manager->add_circle(object->get_position(), summoner::smite_draw_range->get_int(), MAKE_COLOR(255, 255, 255, 255), 3);
								}
							}
						}
					}
					//石頭
					if (summoner::stone->get_bool())
					{
						if (object->get_name().compare("SRU_Krug5.1.1") == 0 || object->get_name().compare("SRU_Krug11.1.1") == 0)
						{
							if (!smite->is_ready())
							{
								draw_manager->add_circle(object->get_position(), summoner::smite_draw_range->get_int(), MAKE_COLOR(255, 255, 255, 50), 3);
							}
							else
							{
								if (myhero->get_distance(object) < summoner::smite_draw_range->get_int())
								{
									draw_manager->add_circle(object->get_position(), summoner::smite_draw_range->get_int(), MAKE_COLOR(255, 100, 0, 255), 3);
								}
								else if (myhero->get_distance(object) >= summoner::smite_draw_range->get_int())
								{
									draw_manager->add_circle(object->get_position(), summoner::smite_draw_range->get_int(), MAKE_COLOR(255, 255, 255, 255), 3);
								}
							}
						}
					}
					//六鳥
					if (summoner::six_bird->get_bool())
					{
						if (object->get_name().compare("SRU_Razorbeak3.1.1") == 0 || object->get_name().compare("SRU_Razorbeak9.1.1") == 0)
						{
							if (!smite->is_ready())
							{
								draw_manager->add_circle(object->get_position(), summoner::smite_draw_range->get_int(), MAKE_COLOR(255, 255, 255, 50), 3);
							}
							else
							{
								if (myhero->get_distance(object) < summoner::smite_draw_range->get_int())
								{
									draw_manager->add_circle(object->get_position(), summoner::smite_draw_range->get_int(), MAKE_COLOR(255, 100, 0, 255), 3);
								}
								else if (myhero->get_distance(object) >= summoner::smite_draw_range->get_int())
								{
									draw_manager->add_circle(object->get_position(), summoner::smite_draw_range->get_int(), MAKE_COLOR(255, 255, 255, 255), 3);
								}
							}
						}
					}
					//大蟾蜍
					if (summoner::gromp->get_bool())
					{
						if (object->get_name().compare("SRU_Gromp13.1.1") == 0 || object->get_name().compare("SRU_Gromp14.1.1") == 0)
						{
							if (!smite->is_ready())
							{
								draw_manager->add_circle(object->get_position(), summoner::smite_draw_range->get_int(), MAKE_COLOR(255, 255, 255, 50), 3);
							}
							else
							{
								if (myhero->get_distance(object) < summoner::smite_draw_range->get_int())
								{
									draw_manager->add_circle(object->get_position(), summoner::smite_draw_range->get_int(), MAKE_COLOR(255, 100, 0, 255), 3);
								}
								else if (myhero->get_distance(object) >= summoner::smite_draw_range->get_int())
								{
									draw_manager->add_circle(object->get_position(), summoner::smite_draw_range->get_int(), MAKE_COLOR(255, 255, 255, 255), 3);
								}
							}
						}
					}
				}
			}
			for (auto& minions : entitylist->get_enemy_minions())
			{
				if (minions->is_valid() && summoner::smite->get_bool())
				{
					//砲車
					if (summoner::smite_siege_minion->get_bool())
					{
						if (minions->get_bounding_radius() == 65)
						{
							if (!smite->is_ready())
							{
								draw_manager->add_circle(minions->get_position(), summoner::smite_draw_range->get_int(), MAKE_COLOR(255, 255, 255, 50), 3);
							}
							else
							{
								if (myhero->get_distance(minions) < 560)
								{
									draw_manager->add_circle(minions->get_position(), summoner::smite_draw_range->get_int(), MAKE_COLOR(255, 100, 0, 255), 3);
								}
								else if (myhero->get_distance(minions) >= 560)
								{
									draw_manager->add_circle(minions->get_position(), summoner::smite_draw_range->get_int(), MAKE_COLOR(255, 255, 255, 255), 3);
								}
							}
						}
					}
				}
			}
		}

		if (exhaust && summoner::exhaust->get_bool() && draw_settings::state_exhaust->get_bool())
		{
			/*if (language_info* lang = translation->add_language("cn", "CN"))
			{
				auto pos = myhero->get_position() + vector(40, -40);
				renderer->world_to_screen(pos, pos);
				draw_manager->add_text_on_screen((pos), MAKE_COLOR(255, 125, 0, 255), 17, "虛弱");
			}*/
			auto pos = myhero->get_position() + vector(40, -40);
			renderer->world_to_screen(pos, pos);
			draw_manager->add_text_on_screen((pos), MAKE_COLOR(255, 125, 0, 255), 17, "Exhaust");
		}

		/*if (gametime->get_time() > cassiopeia_r_time && cassiopeia_r_time + 0.5f > gametime->get_time())
		{

			//draw_manager->add_circle(cassiopeia_start_pos, 50, MAKE_COLOR(0, 255, 0, 255), 4.f);
			//draw_manager->add_circle(cassiopeia_end_pos, 50, MAKE_COLOR(0, 255, 0, 255), 4.f);

			auto pos = myhero->get_position().extend(cassiopeia_start_pos, -100);
			draw_manager->add_circle(pos, 50, MAKE_COLOR(0, 255, 0, 255), 4.f);

			auto radius = 700;
			const auto perp = (cassiopeia_end_pos - cassiopeia_start_pos).normalized().perpendicular(); //垂直
			auto cassiopeia_r_left_pos = cassiopeia_end_pos + perp * (radius);
			auto cassiopeia_r_right_pos = cassiopeia_end_pos - perp * (radius);
			cassiopeia_r_left_pos = cassiopeia_r_left_pos.extend(cassiopeia_start_pos, 200.0f);
			cassiopeia_r_right_pos = cassiopeia_r_right_pos.extend(cassiopeia_start_pos, 200.0f);

			geometry::polygon q1_sector;

			q1_sector.add(cassiopeia_start_pos);
			q1_sector.add(cassiopeia_end_pos);
			q1_sector.add(cassiopeia_r_left_pos);
			q1_sector.add(cassiopeia_r_right_pos);

			draw_manager->add_line(cassiopeia_start_pos, cassiopeia_r_left_pos, MAKE_COLOR(0, 255, 0, 255), 1.0f);
			draw_manager->add_line(cassiopeia_r_left_pos, cassiopeia_end_pos, MAKE_COLOR(0, 255, 0, 255), 1.0f);
			draw_manager->add_line(cassiopeia_end_pos, cassiopeia_r_right_pos, MAKE_COLOR(0, 255, 0, 255), 1.0f);
			draw_manager->add_line(cassiopeia_r_right_pos, cassiopeia_start_pos, MAKE_COLOR(0, 255, 0, 255), 1.0f);
		}*/

		for (lantern lantern : lanterns)
		{
			if (lantern.object->is_valid() && !lantern.object->is_dead())
			{
				//draw_manager->add_circle(lantern.object->get_position(), 50, MAKE_COLOR(0, 255, 0, 255), 4.f);
			}
		}

		for (xayah_e xayah_e : xayah_es)
		{
			//if (xayah_e.object->get_owner()->is_me())
			if (hero::xayah_e->get_bool() && xayah_e.object->is_valid() && !xayah_e.object->is_dead() && xayah_e.object->get_emitter()->get_champion() == champion_id::Xayah) //&& xayah_e.object->get_owner()->is_me()
			{
				geometry::rectangle r_sector = geometry::rectangle(
					xayah_e.object->get_position(), xayah_e.object->get_emitter()->get_position(), 80.0f);
				auto poly = r_sector.to_polygon();
				auto point_1 = poly.points.at(0);
				auto point_2 = poly.points.at(1);
				auto point_3 = poly.points.at(2);
				auto point_4 = poly.points.at(3);
				draw_manager->add_line(point_1, point_2, MAKE_COLOR(255, 69, 0, 255), 0.5f);
				draw_manager->add_line(point_2, point_3, MAKE_COLOR(255, 69, 0, 255), 0.5f);
				draw_manager->add_line(point_3, point_4, MAKE_COLOR(255, 69, 0, 255), 0.5f);
				draw_manager->add_line(point_4, point_1, MAKE_COLOR(255, 69, 0, 255), 0.5f);
			}

		}

		auto object4 = orbwalker->get_target();
		if (object4 != nullptr)
		{
			
			//draw_manager->add_circle(object4->get_position(), 50, MAKE_COLOR(0, 255, 0, 255), 4.f);	
			
		}	

		
		
	}
}