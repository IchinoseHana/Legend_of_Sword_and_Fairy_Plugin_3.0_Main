#ifndef _PAL3_ROLEDATAMANAGER_H_
#define _PAL3_ROLEDATAMANAGER_H_

#pragma once

// TODO�� ����д����������1������ID���string�������ֵ䣻2������ID������������������ʾ������������棬��Ҫ�õ�ʱ����˵��֮ǰ��������ݣ����ܲ�������map��ħ�����ͺϻ�ע���������˺����١��л���������ʱ���þ�ŷָ

// State Slot One
// State -> m_Role[nRoleIndex].snSpecStateLurk[CBRSS_PoisonWind]
// Duration -> m_Role[nRoleIndex].snSpecStateLurk[CBRSS_PoisonThunder]

// Define the state slot one
// States from enemies and items. If the target is a role of the player, it cannot be removed or replaced except waiting for elimination natually
// If the state is used to hurt enemies, it will not disrupt the current action of the target
// For the marker at the end: "_D" means the state will use the second parameter defined by "m_Role[nRoleIndex].snSpecStateLurk[CBRSS_PoisonWater]", "_T" means the state is just used for coding, "_L[Number]" is used to prevent the duplicated symbols for states with the similar effect

#define STATE_SLOT_ONE_HP_LOSS_POISON 1 // Ѫ���Ķ� �غϿ�ʼʱ����-25%/�غϿ�ʼʱ����-[120]
#define STATE_SLOT_ONE_ALL_DAMAGE_TAKE_INCREASE_POISON 2 // ��Ӱ���� ��ȫ���˺�+200%/��ȫ���˺�+100%
#define STATE_SLOT_ONE_MP_LOSS_POISON 3 // ��ȸ���� �غϿ�ʼʱ����-10%/�غϿ�ʼʱ����-[6]
#define STATE_SLOT_ONE_DAMAGE_POISON 4 // ��ʬ�ƶ� �غϿ�ʼʱ�������ܵ�1111��2222��3333���˺�������3�غ�/�غϿ�ʼʱ�������ܵ�[777]��[888]��[999]���˺�������3�غ�
#define STATE_SLOT_ONE_MONEY_LOSS_POISON 5 // ��Ϲƶ� �غϿ�ʼʱ����Ǯ-0.5%/�غϿ�ʼʱ����-[120]
#define STATE_SLOT_ONE_ALL_PARAMETER_DECREASE_POISON 6 // �ϳ��ݶ� ȫ����ֵЧ��-100%/ȫ����ֵЧ��-90%
#define STATE_SLOT_ONE_SP_LOSS_POISON 7 // �׶��춾 �غϿ�ʼʱ����-15%/�غϿ�ʼʱ����-[60]����-[3] 
#define STATE_SLOT_ONE_HP_LOSS_30 9 // ���� �غϿ�ʼʱ����-30
#define STATE_SLOT_ONE_HP_LOSS_60 10 // ������ �غϿ�ʼʱ����-60
#define STATE_SLOT_ONE_MP_LOSS_15 11 // ������ �غϿ�ʼʱ����-15
#define STATE_SLOT_ONE_MP_RECOVER_50 12 // ���ն��� �غϿ�ʼʱ����+50
#define STATE_SLOT_ONE_HP_SP_LOSS_50_10 13 // �е� �غϿ�ʼʱ����-50����-10
#define STATE_SLOT_ONE_HP_LOSS_PERCENTAGE_10 16 // ��Ѫ �غϿ�ʼʱ����-10%
#define STATE_SLOT_ONE_HP_SP_MP_LOSS_120_10_20 17 // �������� �غϿ�ʼʱ����-120����-10����-20
#define STATE_SLOT_ONE_HP_LOSS_DYNAMIC_0_D 18 // ��� �غϿ�ʼʱ����-%d����״̬�˺��ɱ����� %d -> m_Role[nRoleIndex].snSpecStateLurk[CBRSS_PoisonWater]
#define STATE_SLOT_ONE_HP_LOSS_DYNAMIC_60_D 19 // ��Һ �غϿ�ʼʱ����-%d����״̬�˺��ɱ����� %d -> 60 + m_Role[nRoleIndex].snSpecStateLurk[CBRSS_PoisonWater]
#define STATE_SLOT_ONE_HP_LOSS_120 20 // �߶� �غϿ�ʼʱ����-120
#define STATE_SLOT_ONE_DEBUFF_WITH_MAGIC_RAMDOM 21 // а�鸽�� ʹ����������˺�ʱ��5%���ʣ���-9999��5%���ʣ�����������Ƽס��ٶۡ����ˣ�����5�غϣ�90%���ʣ���-�˺���*50%
#define STATE_SLOT_ONE_ALL_PARAMETER_DECREASE_WITHOUT_ITEM_POISON 22 // С�ϳ��ݣ�����Ʒ��ȫ����ֵЧ��-100%
#define STATE_SLOT_ONE_HP_LOSS_PERCENTAGE_12 23 // ��Ѫ���غϿ�ʼʱ����-12%
#define STATE_SLOT_ONE_HP_LOSS_GIVE_ITEM_350 25 // ���� �غϿ�ʼʱ����-[350]������1���ƣ����3�غϸ���Ĺƻ����
#define STATE_SLOT_ONE_HP_LOSS_120_L2 26 // ������ �غϿ�ʼʱ����-120
#define STATE_SLOT_ONE_HP_LOSS_LARGE 27 // ��˿ �غϿ�ʼʱ����-150
#define STATE_SLOT_ONE_HP_LOSS_DAMAGE_BASED_WHEN_ATTACK_PERCENTAGE_100 28// �������� ����˺�ʱ����-�˺���*100%
#define STATE_SLOT_ONE_SP_MP_COST_TRANSFORM_TO_HP_PERCENTAGE_1000_500 29 // ���� ʹ���ؼ�ʱ����-��������*1000%����������-100%��ʹ������ʱ����-��������*500%����������-100%
#define STATE_SLOT_ONE_LIVING_BUMB_PREPARE_T 30 // ����ը��
#define STATE_SLOT_ONE_HP_LOSS_ALL_PARTNER_REMOVE_9999 31 // ����ը�� ׼��1�غϡ��غϿ�ʼʱ�����м�����ɫ��-9999���Ƴ���״̬1
#define STATE_SLOT_ONE_HP_LOSS_WHEN_SP_MP_COST_PERCENTAGE_400_200 32 // ȼ�� ʹ���ؼ�ʱ����-��������*400%��ʹ������ʱ����-��������*200%
#define STATE_SLOT_ONE_HP_LOSS_DAMAGE_BASED_ALL_PARTNER_WHEN_DAMAGE_TAKE_PERCENTAGE_100 33 // ���� �ܵ��˺�ʱ���������н�ɫ��-�˺���*100%
#define STATE_SLOT_ONE_HP_LOSS_WHEN_NORMAL_ATTACK_9999 34 // �������� ʹ����ͨ��������˺�ʱ����-9999
#define STATE_SLOT_ONE_HP_LOSS_WHEN_SKILL_9999 35 // ��֪���� ʹ�ü��ܲ���Ч��ʱ����-9999
#define STATE_SLOT_ONE_HP_LOSS_WHEN_MAGIC_9999 36 // ������� ʹ����������Ч��ʱ����-9999
#define STATE_SLOT_ONE_HP_LOSS_WHEN_ITEM_9999 37 // а�ܻ��� ʹ����Ʒ����Ч��ʱ����-9999
#define STATE_SLOT_ONE_HP_LOSS_DYNAMIC_0_L2_D 38 // �е� �غϿ�ʼʱ����-%d����״̬�˺��ɱ����� %d -> m_Role[nRoleIndex].snSpecStateLurk[CBRSS_PoisonWater]
#define STATE_SLOT_ONE_HP_LOSS_PERCENTAGE_15 39 // ��Ѫ �غϿ�ʼʱ����-15%
#define STATE_SLOT_ONE_HP_MP_LOSS_200_50 40 // �붾 �غϿ�ʼʱ����-200����-50
#define STATE_SLOT_ONE_SPEED_DECREASE_PERCENTAGE_38 41 // ���� ��-38%
#define STATE_SLOT_ONE_HP_LOSS_DYNAMIC_0_L3_D 42 // ��� �غϿ�ʼʱ����-%d����״̬�˺��ɱ����� %d -> m_Role[nRoleIndex].snSpecStateLurk[CBRSS_PoisonWater]
#define STATE_SLOT_ONE_SPEED_DECREASE_PERCENTAGE_ALL_DAMAGE_DECREASE_PERCENTAGE_16_44 43 // �ѷ� ��-16%��ȫ���˺�-44%
#define STATE_SLOT_ONE_SPEED_DECREASE_PERCENTAGE_74 44 // ���� ��-74%
#define STATE_SLOT_ONE_DEBUFF_RAMDOM 45 // ���˲��� �غϿ�ʼʱ��84%���ʣ���-1%~50%��4%���ʣ���ö�������5�غϣ�4%���ʣ�����ң�����32767�غϣ�4%���ʣ���ÿ񣬳���32767�غϣ�4%���ʣ���-100%
#define STATE_SLOT_ONE_HP_SP_MP_LOSS_250_25_50 46 // ���� �غϿ�ʼʱ����-250����-25����-50
#define STATE_SLOT_ONE_ALL_DAMAGE_DECREASE_PERCENTAGE_50 47 // �һ���� ȫ���˺�-50%
#define STATE_SLOT_ONE_ALL_DAMAGE_TAKE_INCREASE_PERCENTAGE_FIRE_SOUL_INCREASE_20_3 48 // ��ȼ ��ȫ���˺�+20%���غϿ�ʼʱ������+3
#define STATE_SLOT_ONE_SPEED_DECREASE_PERCENTAGE_ALL_DAMAGE_INCREASE_PERCENTAGE_84_90 49 // ���� ��-84%����ȫ���˺�-90%
#define STATE_SLOT_ONE_SKILL_MAGIC_ITEM_DAMAGE_INCREASE_PERCENTAGE_900_900_900 50 // Ѫŭ���ؼ��˺�+900%�������˺�+900%����Ʒ�˺�+900%
#define STATE_SLOT_ONE_MONEY_LOSS_PERCENTAGE_0021 51 // ����� �غϿ�ʼʱ����Ǯ-0.021%
#define STATE_SLOT_ONE_DECREASE_MAGIC_LEVEL_RAMDOM 52 // �־� �����ȼ���Ϊ1~4��
#define STATE_SLOT_ONE_NORMAL_ATTACK_DAMAGE_INCREASE_PERCENTAGE_MAGIC_FORBID_40 53 // �������� ��ͨ�����˺�+40%���޷�ʹ������
#define STATE_SLOT_ONE_HP_LOSS_350 54 // ���� �غϿ�ʼʱ����-350
#define STATE_SLOT_ONE_SP_LOSS_100 55 // ���� �غϿ�ʼʱ����-100
#define STATE_SLOT_ONE_MP_LOSS_150 56 // ���� �غϿ�ʼʱ����-150
#define STATE_SLOT_ONE_SPEED_DECREASE_PERCENTAGE_20 57 // ���� ��-20%
#define STATE_SLOT_ONE_ALL_DAMAGE_DECREASE_PERCENTAGE_25 58 // ���� ȫ���˺�-25%
#define STATE_SLOT_ONE_SP_MP_COST_INCREASE_PERCENTAGE_20_20 59 // ���� ������+20%��������+20%
#define STATE_SLOT_ONE_HP_LOSS_600 60 // ���� �غϿ�ʼʱ����-600
#define STATE_SLOT_ONE_SP_LOSS_150 61 // ���� �غϿ�ʼʱ����-150
#define STATE_SLOT_ONE_MP_LOSS_250 62 // ���� �غϿ�ʼʱ����-250
#define STATE_SLOT_ONE_SPEED_DECREASE_PERCENTAGE_30 63 // ���� ��-30%
#define STATE_SLOT_ONE_ALL_DAMAGE_DECREASE_PERCENTAGE_45 64 // ���� ȫ���˺�-45%
#define STATE_SLOT_ONE_SP_MP_COST_INCREASE_PERCENTAGE_50_50 65 // ���� ������+50%��������+50%
#define STATE_SLOT_ONE_SPEED_DECREASE_PERCENTAGE_30_L2 66 // ���� ��-30%
#define STATE_SLOT_ONE_MAGIC_FORBID_208 67 // װ�ҩ �޷�ʹ�á��ѽ⡱
#define STATE_SLOT_ONE_MP_LOSS_200 68 // �ɻ� �غϿ�ʼʱ����-200
#define STATE_SLOT_ONE_HP_LOSS_WHEN_DAMAGE_TAKE_ALL_PERCENTAGE_100 69 // ��� �ܵ��˺�ʱ����-100%
#define STATE_SLOT_ONE_HP_LOSS_400 70 // �඾ �غϿ�ʼʱ����-400
#define STATE_SLOT_ONE_HP_LOSS_ALL_PARTNER_PERCENTAGE_20 71 // ���� �غϿ�ʼʱ�����м�����ɫ��-�������*20%
#define STATE_SLOT_ONE_HP_LOSS_PERCENTAGE_20 72 // ��Ѫ �غϿ�ʼʱ����-20%
#define STATE_SLOT_ONE_ALL_DAMAGE_TAKE_INCREASE_PERCENTAGE_30 73 // ȼ�� ��ȫ���˺�+30%
#define STATE_SLOT_ONE_HP_MP_LOSS_1500_50 74 // �ж� �غϿ�ʼʱ����-1500����-50
#define STATE_SLOT_ONE_HP_LOSS_500 75 // ���� �غϿ�ʼʱ����-500
#define STATE_SLOT_ONE_HP_LOSS_DAMAGE_BASED_ALL_PARTNER_WHEN_ATTACK_PERCENTAGE_10 76 // ���� ����˺�ʱ���������н�ɫ��-�˺���*10%
#define STATE_SLOT_ONE_FIRE_MAGIC_DAMAGE_TAKE_INCREASE_PERCENTAGE_22 77 // ���� �ܻ�ϵ�����˺�+22%
#define STATE_SLOT_ONE_HP_LOSS_INCLUDING_LEVEL_40 78 // �е� �غϿ�ʼʱ����-[40]
#define STATE_SLOT_ONE_HP_LOSS_INCLUDING_LEVEL_25 79 // �ƶ�1 �غϿ�ʼʱ����-[25]
#define STATE_SLOT_ONE_HP_LOSS_INCLUDING_LEVEL_50 80 // �ƶ�2 �غϿ�ʼʱ����-[50]
#define STATE_SLOT_ONE_HP_LOSS_INCLUDING_LEVEL_75 81 // �ƶ�3 �غϿ�ʼʱ����-[75]
#define STATE_SLOT_ONE_HP_LOSS_INCLUDING_LEVEL_100 82 // �ƶ�4 �غϿ�ʼʱ����-[100]
#define STATE_SLOT_ONE_HP_LOSS_INCLUDING_LEVEL_125 83 // �ƶ�5 �غϿ�ʼʱ����-[125]
#define STATE_SLOT_ONE_HP_LOSS_INCLUDING_LEVEL_150 84 // �ƶ�6 �غϿ�ʼʱ����-[150]
#define STATE_SLOT_ONE_HP_LOSS_INCLUDING_LEVEL_175 85 // �ƶ�7 �غϿ�ʼʱ����-[175]
#define STATE_SLOT_ONE_HP_LOSS_INCLUDING_LEVEL_200 86 // �ƶ�8 �غϿ�ʼʱ����-[200]
#define STATE_SLOT_ONE_HP_LOSS_INCLUDING_LEVEL_225 87 // �ƶ�9 �غϿ�ʼʱ����-[225]
#define STATE_SLOT_ONE_HP_LOSS_INCLUDING_LEVEL_250 88 // �ƶ�10 �غϿ�ʼʱ����-[250]
#define STATE_SLOT_ONE_ATTACK_DEFENSCE_SPEED_LUCK_DECREASE_PERCENTAGE_25_25_25_25 89 // ��� ��-25%����-25%����-25%����-25%
#define STATE_SLOT_ONE_SPEED_DECREASE_PERCENTAGE_MAGIC_DAMAGE_TAKE_INCREASE_PERCENTAGE_10_20 90 // ��ʴ ��-10%���������˺�+20%
#define STATE_SLOT_ONE_LUCK_DECREASE_PERCENTAGE_75 91 // ���� ��-75%
#define STATE_SLOT_ONE_DEFENCE_LUCK_DECREASE_PERCENTAGE_95_25 92 // ���Ķ� ��-95%����-25%
#define STATE_SLOT_ONE_ATTACK_DEFENSCE_SPEED_LUCK_DECREASE_PERCENTAGE_HP_LOSS_99_99_50_99_10000 93 // �޼��綾 ��-99%����-99%����-50%����-99%���غϿ�ʼʱ����-10000
#define STATE_SLOT_ONE_LUCK_DECREASE_PERCENTAGE_HP_LOSS_99_15 94 // �ն����� ��-99%���غϿ�ʼʱ����-15
#define STATE_SLOT_ONE_RECOVERY_PARAMETER_DECREASE_PERCENTAGE_50 95 // �����ݽ� ���ָ���ֵЧ��-50%
#define STATE_SLOT_ONE_ATTACK_DEFENSCE_SPEED_LUCK_DECREASE_PERCENTAGE_50_50_50_50 96 // �������� ��-50%����-50%����-50%����-50%
#define STATE_SLOT_ONE_SPEED_DECREASE_PERCENTAGE_95 97 // ���Ķ� ��-95%
#define STATE_SLOT_ONE_SPEED_DECREASE_PERCENTAGE_67 98 // ���� ��-67%
#define STATE_SLOT_ONE_ATTACK_DEFENSCE_SPEED_DECREASE_PERCENTAGE_30_25_20 99 // �ű� ��-30%����-25%����-20%
#define STATE_SLOT_ONE_HP_LOSS_9999 100 // ��˪ը�� �غϿ�ʼʱ����-9999
#define STATE_SLOT_ONE_MP_LOSS_DAMAGE_BASED_WHEN_DAMAGE_TAKE_PERCENTAGE_HP_LOSS_5_60 101 // ���� �ܵ��˺�ʱ����-�˺���*5%���غϿ�ʼʱ����-60
#define STATE_SLOT_ONE_HP_LOSS_INCLUDING_LEVEL_STABEL_CHANCE_PERCENTAGE_DURATION_11_4_2 102 // ���� �غϿ�ʼʱ����-[11]���غϿ�ʼʱ��4%���ʣ���ö�������2�غ�
#define STATE_SLOT_ONE_HP_LOSS_INCLUDING_LEVEL_1_D 103 // ��Ѫ �غϿ�ʼʱ����-[%d]����״̬�˺��ɱ����� %d -> m_Role[nRoleIndex].snSpecStateLurk[CBRSS_PoisonWater]
#define STATE_SLOT_ONE_HP_LOSS_DAMAGE_BASED_DURING_STATE_ALL_PARTNER_PERCENTAGE_WHEN_FINAL_TURN_20_D 104 // ���� ���1�غϿ�ʼʱ���������н�ɫ��-%d����״̬�˺�Ϊ״̬�����ڼ��ܵ������˺���*20% %d -> m_Role[nRoleIndex].snSpecStateLurk[CBRSS_PoisonWater] * 20%
#define STATE_SLOT_ONE_NORMAL_ATTACK_FORBID_REPEAT_FORBID 105 // ���� �޷�ʹ����ͨ�������޷��ظ���һ�ζ���
#define STATE_SLOT_ONE_HP_LOSS_DAMAGE_BASED_OTHER_PARTNER_WHEN_DAMAGE_TAKE_PERCENTAGE_80 106 // �������� �ܵ��˺�ʱ������������ɫ��-�˺���*80%
#define STATE_SLOT_ONE_MP_LOSS_DAMAGE_BASED_WHEN_MAGIC_MP_DAMAGE_TAKE_PERCENTAGE_ITEM_MP_DAMAGE_TAKE_PERCENTAGE_1000_900 107 // �����Ŷ� ����Ʒ�����Ӱ��+900%�������������Ӱ��ʱ����-������*1000%
#define STATE_SLOT_ONE_HP_LOSS_20 108 // ���� �غϿ�ʼʱ����-20
#define STATE_SLOT_ONE_MP_LOSS_PERCENTAGE_5 109 // ��ʴ �غϿ�ʼʱ:��-5%

// State Slot Two
// State -> m_Role[nRoleIndex].snSpecStateLurk[CBRSS_PoisonFire]
// Duration -> m_Role[nRoleIndex].snSpecStateLurk[CBRSS_PoisonEarth]

// Define the state slot two
// States from players and items which can be removed or replaced easily
// For the marker at the end: "_D" means the state will use the second parameter defined by "m_Role[nRoleIndex].snSpecStateLurk[CBRSS_PoisonWater]", "_T" means the state is just used for coding, "_L[Number]" is used to prevent the duplicated symbols for states with the similar effect


		
class RoleDataManager
{
public:

	RoleDataManager();
	~RoleDataManager();
};



#endif // #ifndef _PAL3_CB2DEFFECT_H_