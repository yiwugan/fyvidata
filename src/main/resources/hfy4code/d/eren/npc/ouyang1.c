#include <ansi.h>
inherit SMART_NPC;  
void create()
{
        set_name(HIY"�油"NOR,({"guardian"}));
//      set("title","��������");
        set("long", "�����ָ����֡�԰�����ʾ���Ц�е��������۾�������˹���˵����\n");
        set("age",30+random(20));
        set("attitude", "friendly");
        set("combat_exp", 4000000);
        set("dungeon_npc","eren"); 
                
        set("max_atman", 1000);
        set("atman", 1000);
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_force",2000);
        set("force",2000);
        set("force_factor",60);
        
        set("resistance/gin",30);
        set("resistance/kee",30);
        set("resistance/sen",30);
        
        set("inquiry", ([
                "С��" : "�����С�������컹������򶹸����š�",
                 "ŷ��������" : "�ٺ٣����ֵܿ��Ķ����̡�",
                 "������¥": "������¥��Ȼ�ǹ���������ඣ������ڲ���ඡ�",
                 "������": "������¥��Ȼ�ǹ���������ඣ������ڲ���ඡ�",
                "������ջ": "������ջ����������Ů�����ġ�",
                "��С��": "������ջ����������Ů����С�����ġ�",
                "���˹�": "����˹���������û�����ˡ�",
                "������": "�����������˭�˲��������ﻹ�����������ء�",
                "����": "����ҽ����������֮�ܡ�",
                "���ϵ�": "���ϵ�ר��������˵Ҫ�����İ���������ѧ������������С�",
                "��ԯ����": "�����ֻʣ���Ǽ䵱���ˡ�",
        ]));
        
        set("chat_chance", 1);
        set("chat_msg", ({
           "ŷ����˵����������������������İ˹�ɽ�����Ķ����洫����ڼ�������ڼ�������\n",
                
        }) );
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: auto_smart_fight() :),    
        }) );
         
        CHAR_D->setup_char(this_object());
        auto_npc_setup("guardian",200,170,1,"/d/eren2/npc/obj/","fighter_u","all");
        set_name("ŷ����",({"ouyang ding"}));
        setup();
        carry_object("/obj/armor/cloth")->wear();
        
}       
