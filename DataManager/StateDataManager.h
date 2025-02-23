#ifndef _PAL3_ROLEDATAMANAGER_H_
#define _PAL3_ROLEDATAMANAGER_H_

#pragma once

// TODO： 后续写两个方法：1、根据ID获得string，考虑字典；2、根据ID获得描述，用于面板显示。允许存在外面，需要用的时候再说。之前的面板数据，看能不能做成map。魔剑技和合击注明，不受免疫和伤害减少机制影响。切换触发条件时，用句号分割。

// State Slot One
// State -> m_Role[nRoleIndex].snSpecStateLurk[CBRSS_PoisonWind]
// Duration -> m_Role[nRoleIndex].snSpecStateLurk[CBRSS_PoisonThunder]

// Define the state slot one
// States from enemies and items. If the target is a role of the player, it cannot be removed except waiting for elimination natually or using some special items
// If the state is used to hurt enemies, it will not disrupt the current action of the target
// For the marker at the end: "_D" means the state will use the second parameter defined by "m_Role[nRoleIndex].snSpecStateLurk[CBRSS_PoisonWater]", "_T" means the state is just used for coding, "_L[Number]" is used to prevent the duplicated symbols for states with the similar effect

#define STATE_SLOT_ONE_HP_LOSS_POISON 1 // 血海棠毒 回合开始时：精-25%/回合开始时：精-[120]
#define STATE_SLOT_ONE_ALL_DAMAGE_TAKE_INCREASE_POISON 2 // 无影毒毒 受全部伤害+200%/受全部伤害+100%
#define STATE_SLOT_ONE_MP_LOSS_POISON 3 // 孔雀胆毒 回合开始时：神-10%/回合开始时：神-[6]
#define STATE_SLOT_ONE_DAMAGE_POISON 4 // 三尸蛊毒 回合开始时：依次受到1111，2222，3333点伤害，持续3回合/回合开始时：依次受到[777]，[888]，[999]点伤害，持续3回合
#define STATE_SLOT_ONE_MONEY_LOSS_POISON 5 // 金蚕蛊毒 回合开始时：金钱-0.5%/回合开始时：精-[120]
#define STATE_SLOT_ONE_ALL_PARAMETER_DECREASE_POISON 6 // 断肠草毒 全部数值效果-100%/全部数值效果-90%
#define STATE_SLOT_ONE_SP_LOSS_POISON 7 // 鹤顶红毒 回合开始时：气-15%/回合开始时：精-[60]，神-[3] 
#define STATE_SLOT_ONE_HP_LOSS_30 9 // 冰刺 回合开始时：精-30
#define STATE_SLOT_ONE_HP_LOSS_60 10 // 寒冰刺 回合开始时：精-60
#define STATE_SLOT_ONE_MP_LOSS_15 11 // 暗毒刺 回合开始时：神-15
#define STATE_SLOT_ONE_MP_RECOVER_50 12 // 复苏毒雾 回合开始时：神+50
#define STATE_SLOT_ONE_HP_SP_LOSS_50_10 13 // 感电 回合开始时：精-50，气-10
#define STATE_SLOT_ONE_HP_LOSS_PERCENTAGE_10 16 // 流血 回合开始时：精-10%
#define STATE_SLOT_ONE_HP_SP_MP_LOSS_120_10_20 17 // 心能灼烧 回合开始时：精-120，气-10，神-20
#define STATE_SLOT_ONE_HP_LOSS_DYNAMIC_0_D 18 // 碎骨 回合开始时：精-%d。此状态伤害可被提升 %d -> m_Role[nRoleIndex].snSpecStateLurk[CBRSS_PoisonWater]
#define STATE_SLOT_ONE_HP_LOSS_DYNAMIC_60_D 19 // 毒液 回合开始时：精-%d。此状态伤害可被提升 %d -> 60 + m_Role[nRoleIndex].snSpecStateLurk[CBRSS_PoisonWater]
#define STATE_SLOT_ONE_HP_LOSS_120 20 // 蛇毒 回合开始时：精-120
#define STATE_SLOT_ONE_DEBUFF_WHEN_MAGIC_DAMAGE_RAMDOM 21 // 邪灵附体 使用仙术造成伤害时：5%概率，精-9999；5%概率，获得虚弱、破甲、迟钝和厄运，持续5回合；90%概率，精-伤害量*50%
#define STATE_SLOT_ONE_ALL_PARAMETER_DECREASE_WITHOUT_ITEM_POISON 22 // 小断肠草，除物品外全部数值效果-100%
#define STATE_SLOT_ONE_HP_LOSS_PERCENTAGE_12 23 // 流血，回合开始时：精-12%
#define STATE_SLOT_ONE_HP_LOSS_GIVE_ITEM_350 25 // 吸精 回合开始时：精-[350]，给予1个蛊，最后3回合给予的蛊会更好
#define STATE_SLOT_ONE_HP_LOSS_120_L2 26 // 暗毒刺 回合开始时：精-120
#define STATE_SLOT_ONE_HP_LOSS_LARGE 27 // 毒丝 回合开始时：精-150
#define STATE_SLOT_ONE_HP_LOSS_DAMAGE_BASED_WHEN_ALL_ATTACK_DAMAGE_PERCENTAGE_100 28// 死亡渴望 造成伤害时：精-伤害量*100%
#define STATE_SLOT_ONE_SP_MP_COST_TRANSFORM_TO_HP_PERCENTAGE_1000_500 29 // 分流 使用特技时：精-气消耗量*1000%，气消耗-100%；使用仙术时：精-神消耗量*500%，神消耗-100%
#define STATE_SLOT_ONE_LIVING_BUMB_PREPARE_T 30 // 活体炸弹
#define STATE_SLOT_ONE_HP_LOSS_ALL_PARTNER_REMOVE_9999 31 // 活体炸弹 准备1回合。回合开始时：所有己方角色精-9999，移除该状态1
#define STATE_SLOT_ONE_HP_LOSS_WHEN_SP_MP_COST_PERCENTAGE_400_200 32 // 燃烧 使用特技时：精-气消耗量*400%；使用仙术时：精-神消耗量*200%
#define STATE_SLOT_ONE_HP_LOSS_DAMAGE_BASED_ALL_PARTNER_WHEN_DAMAGE_TAKE_PERCENTAGE_100 33 // 连接 受到伤害时：己方所有角色精-伤害量*100%
#define STATE_SLOT_ONE_HP_LOSS_WHEN_NORMAL_ATTACK_DAMAGE 9999 34 // 静滞领域 使用普通攻击造成伤害时：精-9999
#define STATE_SLOT_ONE_HP_LOSS_WHEN_SKILL_9999 35 // 感知能量 使用技能产生效果时：精-9999
#define STATE_SLOT_ONE_HP_LOSS_WHEN_MAGIC_9999 36 // 法力损毁 使用仙术产生效果时：精-9999
#define STATE_SLOT_ONE_HP_LOSS_WHEN_ITEM_9999 37 // 邪能火焰 使用物品产生效果时：精-9999
#define STATE_SLOT_ONE_HP_LOSS_DYNAMIC_0_L2_D 38 // 感电 回合开始时：精-%d。此状态伤害可被提升 %d -> m_Role[nRoleIndex].snSpecStateLurk[CBRSS_PoisonWater]
#define STATE_SLOT_ONE_HP_LOSS_PERCENTAGE_15 39 // 流血 回合开始时：精-15%
#define STATE_SLOT_ONE_HP_MP_LOSS_200_50 40 // 蛛毒 回合开始时：精-200，神-50
#define STATE_SLOT_ONE_SPEED_DECREASE_PERCENTAGE_38 41 // 冰结 速-38%
#define STATE_SLOT_ONE_HP_LOSS_DYNAMIC_0_L3_D 42 // 碎骨 回合开始时：精-%d。此状态伤害可被提升 %d -> m_Role[nRoleIndex].snSpecStateLurk[CBRSS_PoisonWater]
#define STATE_SLOT_ONE_SPEED_DECREASE_PERCENTAGE_ALL_DAMAGE_DECREASE_PERCENTAGE_16_44 43 // 裂风 速-16%，全部伤害-44%
#define STATE_SLOT_ONE_SPEED_DECREASE_PERCENTAGE_74 44 // 虚弱 速-74%
#define STATE_SLOT_ONE_DEBUFF_RAMDOM 45 // 恶运缠身 回合开始时：84%概率，精-1%~50%；4%概率，获得定，持续5回合；4%概率，获得乱，持续32767回合；4%概率，获得狂，持续32767回合；4%概率，精-100%
#define STATE_SLOT_ONE_HP_SP_MP_LOSS_250_25_50 46 // 骨针 回合开始时：精-250，气-25，神-50
#define STATE_SLOT_ONE_ALL_DAMAGE_DECREASE_PERCENTAGE_50 47 // 烈火焚身 全部伤害-50%
#define STATE_SLOT_ONE_ALL_DAMAGE_TAKE_INCREASE_PERCENTAGE_FIRE_SOUL_INCREASE_20_3 48 // 引燃 受全部伤害+20%。回合开始时：火灵+3
#define STATE_SLOT_ONE_SPEED_DECREASE_PERCENTAGE_ALL_DAMAGE_TAKE_INCREASE_PERCENTAGE_84_90 49 // 蓄势 速-84%，受全部伤害-90%
#define STATE_SLOT_ONE_SKILL_MAGIC_ITEM_DAMAGE_INCREASE_PERCENTAGE_900_900_900 50 // 血怒，特技伤害+900%，仙术伤害+900%，物品伤害+900%
#define STATE_SLOT_ONE_MONEY_LOSS_PERCENTAGE_0021 51 // 穷鬼附身 回合开始时：金钱-0.021%
#define STATE_SLOT_ONE_DECREASE_MAGIC_LEVEL_RAMDOM 52 // 恐惧 仙术等级成为1~4级
#define STATE_SLOT_ONE_NORMAL_ATTACK_DAMAGE_INCREASE_PERCENTAGE_MAGIC_FORBID_40 53 // 心满意足 普通攻击伤害+40%，无法使用仙术
#define STATE_SLOT_ONE_HP_LOSS_350 54 // 诅咒 回合开始时：精-350
#define STATE_SLOT_ONE_SP_LOSS_100 55 // 诅咒 回合开始时：气-100
#define STATE_SLOT_ONE_MP_LOSS_150 56 // 诅咒 回合开始时：神-150
#define STATE_SLOT_ONE_SPEED_DECREASE_PERCENTAGE_20 57 // 诅咒 速-20%
#define STATE_SLOT_ONE_ALL_DAMAGE_DECREASE_PERCENTAGE_25 58 // 诅咒 全部伤害-25%
#define STATE_SLOT_ONE_SP_MP_COST_INCREASE_PERCENTAGE_20_20 59 // 诅咒 气消耗+20%，神消耗+20%
#define STATE_SLOT_ONE_HP_LOSS_600 60 // 诅咒 回合开始时：精-600
#define STATE_SLOT_ONE_SP_LOSS_150 61 // 诅咒 回合开始时：气-150
#define STATE_SLOT_ONE_MP_LOSS_250 62 // 诅咒 回合开始时：神-250
#define STATE_SLOT_ONE_SPEED_DECREASE_PERCENTAGE_30 63 // 诅咒 速-30%
#define STATE_SLOT_ONE_ALL_DAMAGE_DECREASE_PERCENTAGE_45 64 // 诅咒 全部伤害-45%
#define STATE_SLOT_ONE_SP_MP_COST_INCREASE_PERCENTAGE_50_50 65 // 诅咒 气消耗+50%，神消耗+50%
#define STATE_SLOT_ONE_SPEED_DECREASE_PERCENTAGE_30_L2 66 // 冻结 速-30%
#define STATE_SLOT_ONE_MAGIC_FORBID_208 67 // 装填弹药 无法使用“裂解”
#define STATE_SLOT_ONE_MP_LOSS_200 68 // 噬魂 回合开始时：神-200
#define STATE_SLOT_ONE_HP_LOSS_WHEN_DAMAGE_TAKE_ALL_PERCENTAGE_100 69 // 标记 受到伤害时：精-100%
#define STATE_SLOT_ONE_HP_LOSS_400 70 // 赤毒 回合开始时：精-400
#define STATE_SLOT_ONE_HP_LOSS_ALL_PARTNER_PERCENTAGE_20 71 // 爆裂 回合开始时：所有己方角色精-自身最大精*20%
#define STATE_SLOT_ONE_HP_LOSS_PERCENTAGE_20 72 // 流血 回合开始时：精-20%
#define STATE_SLOT_ONE_ALL_DAMAGE_TAKE_INCREASE_PERCENTAGE_30 73 // 燃烧 受全部伤害+30%
#define STATE_SLOT_ONE_HP_MP_LOSS_1500_50 74 // 中毒 回合开始时：精-1500，神-50
#define STATE_SLOT_ONE_HP_LOSS_500 75 // 毒瘴 回合开始时：精-500
#define STATE_SLOT_ONE_HP_LOSS_DAMAGE_BASED_ALL_PARTNER_WHEN_ATTACK_DAMAGE_PERCENTAGE_10 76 // 灼烧 造成伤害时：己方所有角色精-伤害量*10%
#define STATE_SLOT_ONE_FIRE_MAGIC_DAMAGE_TAKE_INCREASE_PERCENTAGE_22 77 // 灼烧 受火系仙术伤害+22%
#define STATE_SLOT_ONE_HP_LOSS_INCLUDING_LEVEL_40 78 // 感电 回合开始时：精-[40]
#define STATE_SLOT_ONE_HP_LOSS_INCLUDING_LEVEL_25 79 // 蛊毒1 回合开始时：精-[25]
#define STATE_SLOT_ONE_HP_LOSS_INCLUDING_LEVEL_50 80 // 蛊毒2 回合开始时：精-[50]
#define STATE_SLOT_ONE_HP_LOSS_INCLUDING_LEVEL_75 81 // 蛊毒3 回合开始时：精-[75]
#define STATE_SLOT_ONE_HP_LOSS_INCLUDING_LEVEL_100 82 // 蛊毒4 回合开始时：精-[100]
#define STATE_SLOT_ONE_HP_LOSS_INCLUDING_LEVEL_125 83 // 蛊毒5 回合开始时：精-[125]
#define STATE_SLOT_ONE_HP_LOSS_INCLUDING_LEVEL_150 84 // 蛊毒6 回合开始时：精-[150]
#define STATE_SLOT_ONE_HP_LOSS_INCLUDING_LEVEL_175 85 // 蛊毒7 回合开始时：精-[175]
#define STATE_SLOT_ONE_HP_LOSS_INCLUDING_LEVEL_200 86 // 蛊毒8 回合开始时：精-[200]
#define STATE_SLOT_ONE_HP_LOSS_INCLUDING_LEVEL_225 87 // 蛊毒9 回合开始时：精-[225]
#define STATE_SLOT_ONE_HP_LOSS_INCLUDING_LEVEL_250 88 // 蛊毒10 回合开始时：精-[250]
#define STATE_SLOT_ONE_ATTACK_DEFENSCE_SPEED_LUCK_DECREASE_PERCENTAGE_25_25_25_25 89 // 麻痹 武-25%，防-25%，速-25%，运-25%
#define STATE_SLOT_ONE_SPEED_DECREASE_PERCENTAGE_MAGIC_DAMAGE_TAKE_INCREASE_PERCENTAGE_10_20 90 // 侵蚀 速-10%，受仙术伤害+20%
#define STATE_SLOT_ONE_LUCK_DECREASE_PERCENTAGE_75 91 // 毒运 运-75%
#define STATE_SLOT_ONE_DEFENCE_LUCK_DECREASE_PERCENTAGE_95_25 92 // 噬心毒 防-95%，速-25%
#define STATE_SLOT_ONE_ATTACK_DEFENSCE_SPEED_LUCK_DECREASE_PERCENTAGE_HP_LOSS_99_99_50_99_10000 93 // 无极剧毒 武-99%，防-99%，速-50%，运-99%。回合开始时：精-10000
#define STATE_SLOT_ONE_LUCK_DECREASE_PERCENTAGE_HP_LOSS_99_15 94 // 险恶诅咒 运-99%。回合开始时：精-15
#define STATE_SLOT_ONE_RECOVERY_PARAMETER_DECREASE_PERCENTAGE_50 95 // 能量枯竭 精恢复数值效果-50%
#define STATE_SLOT_ONE_ATTACK_DEFENSCE_SPEED_LUCK_DECREASE_PERCENTAGE_50_50_50_50 96 // 死亡诅咒 武-50%，防-50%，速-50%，运-50%
#define STATE_SLOT_ONE_SPEED_DECREASE_PERCENTAGE_95 97 // 竭心毒 速-95%
#define STATE_SLOT_ONE_SPEED_DECREASE_PERCENTAGE_67 98 // 冻结 速-67%
#define STATE_SLOT_ONE_ATTACK_DEFENSCE_SPEED_DECREASE_PERCENTAGE_30_25_20 99 // 磁暴 武-30%，防-25%，速-20%
#define STATE_SLOT_ONE_HP_LOSS_9999 100 // 冰霜炸弹 回合开始时：精-9999
#define STATE_SLOT_ONE_MP_LOSS_DAMAGE_BASED_WHEN_DAMAGE_TAKE_PERCENTAGE_HP_LOSS_5_60 101 // 毒针 受到伤害时：神-伤害量*5%。回合开始时：精-60
#define STATE_SLOT_ONE_HP_LOSS_INCLUDING_LEVEL_STABEL_CHANCE_PERCENTAGE_DURATION_11_4_2 102 // 定电 回合开始时：精-[11]。回合开始时：4%概率，获得定，持续2回合
#define STATE_SLOT_ONE_HP_LOSS_INCLUDING_LEVEL_1_D 103 // 流血 回合开始时：精-[%d]。此状态伤害可被提升 %d -> m_Role[nRoleIndex].snSpecStateLurk[CBRSS_PoisonWater]
#define STATE_SLOT_ONE_HP_LOSS_DAMAGE_BASED_DURING_STATE_ALL_PARTNER_PERCENTAGE_WHEN_FINAL_TURN_20_D 104 // 诅咒 最后1回合开始时：己方所有角色精-%d。此状态伤害为状态持续期间受到的总伤害量*20% %d -> m_Role[nRoleIndex].snSpecStateLurk[CBRSS_PoisonWater] * 20%
#define STATE_SLOT_ONE_NORMAL_ATTACK_FORBID_REPEAT_FORBID 105 // 束缚 无法使用普通攻击，无法重复上一次动作
#define STATE_SLOT_ONE_HP_LOSS_DAMAGE_BASED_OTHER_PARTNER_WHEN_DAMAGE_TAKE_PERCENTAGE_80 106 // 烈焰锁链 受到伤害时：己方其他角色精-伤害量*80%
#define STATE_SLOT_ONE_MP_LOSS_DAMAGE_BASED_WHEN_MAGIC_MP_DAMAGE_TAKE_PERCENTAGE_ITEM_MP_DAMAGE_TAKE_PERCENTAGE_1000_900 107 // 灵力扰动 受物品神减少影响+900%。受仙术神减少影响时：神-减少量*1000%
#define STATE_SLOT_ONE_HP_LOSS_20 108 // 毒刺 回合开始时：精-20
#define STATE_SLOT_ONE_MP_LOSS_PERCENTAGE_5 109 // 腐蚀 回合开始时:神-5%

// State Slot Two
// State -> m_Role[nRoleIndex].snSpecStateLurk[CBRSS_PoisonFire]
// Duration -> m_Role[nRoleIndex].snSpecStateLurk[CBRSS_PoisonEarth]

// Define the state slot two
// States from players and items which can be removed or replaced easily. However, if the target is an enemy, it is impossible to remove or replace this
// For the marker at the end: "_D" means the state will use the second parameter defined by "m_Role[nRoleIndex].snSpecStateLurk[CBRSS_PoisonWater]", "_T" means the state is just used for coding, "_L[Number]" is used to prevent the duplicated symbols for states with the similar effect
// "_S" will be added when the state should be implemented by specific ways in the code

#define STATE_SLOT_TWO_HP_SP_MP_RECOVER_PERCENTAGE_30_30_30 1 // 女儿香 回合开始时：精+30%，气+30%，神+30%
#define STATE_SLOT_TWO_MAGIC_DAMAGE_REBOUND_40 2 // 魔力反射 仙术伤害反弹+40%
#define STATE_SLOT_TWO_EXTRA_DAMAGE_WHEN_ALL_ATTACK_DAMAGE_PERCENTAGE_20 3 // 利刃 造成伤害时：再造成一次等同于伤害量20%的伤害
#define STATE_SLOT_TWO_MP_RECOVER_50 4 // 复苏瘴气 回合开始时：神+50
#define STATE_SLOT_TWO_NORMAL_ATTACK_SKILL_MAGIC_IMMUNITY 5 // 五灵结界 免疫普通攻击、技能和仙术的效果
#define STATE_SLOT_TWO_NORMAL_ATTACK_SKILL_ITEM_IMMUNITY 6 // 铜墙铁壁 免疫普通攻击、技能和物品的效果
#define STATE_SLOT_TWO_ALL_IMMUNITY 7 // 无极障壁 免疫全部效果
#define STATE_SLOT_TWO_EXTRA_DAMAGE_WHEN_NORMALL_ATTACK_MAGIC_DAMAGE_PERCENTAGE_40 8 // 血刃 使用普通攻击或仙术造成伤害时：再造成一次等同于伤害量40%的伤害
#define STATE_SLOT_TWO_EXTRA_DAMAGE_WHEN_NORMALL_ATTACK_MAGIC_DAMAGE_PERCENTAGE_DEBUFF_DURATION_35_5 9 // 毒刃 使用普通攻击或仙术造成伤害时：再造成一次等同于伤害量35%的伤害；造成虚弱、破甲、迟钝或厄运，持续5回合
#define STATE_SLOT_TWO_HP_RECOVER_PERCENTAGE_25 10 // 邪能雨 回合开始时：精+25%
#define STATE_SLOT_TWO_KEEP_ALIVE_UNTIL_ALL_IN_THIS_STATE_S 11 // 魔力休眠 该角色始终存活，除非所有友方角色进入此状态
#define STATE_SLOT_TWO_HP_RECOVER_ATTACK_UP_STATUS_DEFENCE_UP_STATUS_DURATION_BOUND_STATUS_DURATION_9999_5_3 12 // 火之守护 回合开始获得神武、坚韧，持续5回合；获得界，持续3回合
#define STATE_SLOT_TWO_HP_SP_MP_RECOVER_9999_9999_9999 13 // 魔能 回合开始时：精+9999，气+9999，神+9999
#define STATE_SLOT_TWO_SPEED_INCREASE_PERCENTAGE_300 14 // 雷之守护 速+300%
#define STATE_SLOT_TWO_WALL_STATUS_DURATION_3 15 // 土之守护 回合开始时：获得壁，持续3回合
#define STATE_SLOT_TWO_MAGIC_DAMAGE_REBOUND_20 16 // 魔力折射 仙术伤害反弹+20%
#define STATE_SLOT_TWO_SPEED_INCREASE_PERCENTAGE_800 17 // 鬼灵附身 速+800%
#define STATE_SLOT_TWO_COMBAT_FORM_S 18 // 战斗形态 进入战斗形态
#define STATE_SLOT_TWO_ATTACK_UP_STATUS_DEFENCE_UP_STATUS_SPEED_UP_STATUS_RECOVERY_UP_STATUS_DURATION_5 19 // 枯萎精髓 回合开始时：获得神武、坚韧、迅捷和吉运，持续5回合
#define STATE_SLOT_TWO_HP_RECOVER_3000 20 // 枯萎精髓 回合开始时：精+3000
#define STATE_SLOT_TWO_DEBUFF_CODE_WHEN_NORMALL_ATTACK_MAGIC_DAMAGE_CHANCE_PERCENTAGE_DURATION_66_25_3 21 // 枯萎精髓 使用普通攻击或仙术造成伤害时：25%概率，造成冻结，持续3回合
#define STATE_SLOT_TWO_NORMAL_ATTACK_MAGIC_DAMAGE_IMMUNITY_CHANCE_PERCENTAGE_10 22 // 枯萎精髓 受到普通攻击或仙术伤害时：10%概率，免疫此伤害
#define STATE_SLOT_TWO_MAGIC_DAMAGE_ATTRIBUTE_DAMAGE_DECREASE_EFFECT_INCREASE_PERCENTAGE_200 23 // 枯萎精髓 受到仙术伤害时：被克制五灵属性减少的伤害+200%
#define STATE_SLOT_TWO_HP_RECOVER_SPEED_UP_STATUS_DURATION_1000_5 24 // 枯萎精髓 回合开始时：精+1000，获得迅捷，持续5回合
#define STATE_SLOT_TWO_MAGIC_DAMAGE_INCREASE_PERCENTAGE_MAGIC_DAMAGE_TAKE_DECREASE_PERCENTAGE_20_20 25 // 水灵护体 仙术伤害+20%,受仙术伤害-20%
#define STATE_SLOT_TWO_NORMAL_ATTACK_DAMAGE_TAKE_DECREASE_PERCENTAGE_50 27 // 狂风壁障 受普通攻击伤害-50%
#define STATE_SLOT_TWO_SPEED_INCREASE_PERCENTAGE_SP_MP_COST_DECREASE_PERCENTAGE_800_100_100 29 // 风怒 速+800%，气消耗-100%，神消耗-100%
#define STATE_SLOT_TWO_SKILL_POINT_INCREASE_5 30 // 快速充能 回合开始时:武灵+5
#define STATE_SLOT_TWO_SKILL_MAGIC_ITEM_DAMAGE_INCREASE_PERCENTAGE_10_10_10 31 // 快速聚能 技能伤害+10%，仙术伤害+10%，物品伤害+10%
#define STATE_SLOT_TWO_SKILL_POINT_INCREASE_HP_BASED_PERCENTAGE_SKILL_POINT_INCREASE_1_15_3 32 // 灵力之种 回合开始时:武灵+3，每有15%的精则武灵+1
#define STATE_SLOT_TWO_SKILL_POINT_INCREASE_FRIEND_COUNT_BASED_2_1 33 // 灵流 回合开始时:每有1个己方角色则武灵+2
#define STATE_SLOT_TWO_SPEED_INCREASE_100 34 // 鲜血能流 速+100%
#define STATE_SLOT_TWO_ATTACK_DEFENSCE_SPEED_LUCK_INCREASE_PERCENTAGE_50 35 // 四枢通灵 武+50%，防+50%，速+50%，运+50%
#define STATE_SLOT_TWO_HP_LOSS_PERCENTAGE_ATTACK_DEFENSCE_SPEED_LUCK_INCREASE_PERCENTAGE_25_100_100_100_100 36 // 魔炎灼烧 武+100%，防+100%，速+100%，运+100%。回合开始时:精-25%
#define STATE_SLOT_TWO_ATTACK_LUCK_INCREASE_PERCENTAGE_50_50 37 // 流水之盾 武+50%，运+50%
#define STATE_SLOT_TWO_DEFENSCE_SPEED_INCREASE_PERCENTAGE_50_50 38 // 狂雷之刃 防+50%，速+50%
#define STATE_SLOT_TWO_HP_RECOVER_PERCENTAGE_100 39 // 凝血 回合开始时:精+100%
#define STATE_SLOT_TWO_SKILL_MAGIC_COST_TYPE_CHANGE_SP_MP_COST_DECREASE_PERCENTAGE_20_20 40 // 魔能反转 交换技能和仙术消耗气和神的种类，气消耗-20%，神消耗-20%
#define STATE_SLOT_TWO_SKILL_MAGIC_ITEM_DAMAGE_TAKE_DECREASE_PERCENTAGE_35_35_35 41 // 活化壁障 受技能伤害-35%，受仙术伤害-35%，受物品伤害-35%
#define STATE_SLOT_TWO_LOSE_CONTROL_CAST_ATTACK_MAGIC_MAGIC_IMMUNITY_MP_COST_DECREASE_PERCENTAGE_20 42 // 神秘魔盒 不受控制，仅释放攻击仙术，神消耗-100%，免疫仙术效果
#define STATE_SLOT_TWO_ATTACK_DEFENCE_INCREASE_PERCENTAGE_100_100 43 // 龙吼 武+100%，防+100%
#define STATE_SLOT_TWO_DEFENCE_DECREASE_PERCENTAGE_SPEED_INCREASE_PERCENTAGE_100_800 44 // 疾风步 防-100%，速+800%
#define STATE_SLOT_TWO_SKILL_MAGIC_POINT_INCREASE_CHANCE_PERCENTAGE_20_50_20_50 45 // 灵力满溢 回合开始时：50%概率，武灵+20；50%概率，仙灵+20
#define STATE_SLOT_TWO_ALL_DAMAGE_ABSORB_PERCENTAGE_100 46 // 极性反转 全部伤害吸收+100%
#define STATE_SLOT_TWO_MAGIC_DAMAGE_ABSORB_PERCENTAGE_130 47 // 宁神 仙术伤害吸收+130%
#define STATE_SLOT_TWO_PROGRESS_BAR_INCREASE_WHEN_NORMALL_ATTACK_DAMAGE_PERCENTAGE_EXTRA_DAMAGE_OTHER_ENEMY_WHEN_NORMALL_ATTACK_DAMAGE_PERCENTAGE_50_50 48 // 分裂攻击 使用普通攻击造成伤害时:进度条+50%，对其他敌人造成等同于伤害量50%的伤害
#define STATE_SLOT_TWO_ATTACK_PERMANENT_INCREASE_1 49 // 炎刃 回合开始时:武+1
#define STATE_SLOT_TWO_LUCK_PERMANENT_INCREASE_6 50 // 幸运 回合开始时:运+6
#define STATE_SLOT_TWO_ALL_DAMAGE_INCREASE_PERCENTAGE_25 51 // 狂野怒火 全部伤害+25%
		
class RoleDataManager
{
public:

	RoleDataManager();
	~RoleDataManager();
};



#endif // #ifndef _PAL3_CB2DEFFECT_H_