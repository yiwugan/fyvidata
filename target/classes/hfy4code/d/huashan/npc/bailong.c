#include <ansi.h>
inherit NPC;
int do_leave(object me);
void create()
{
        set_name("��Զ��", ({ "sun yuanchao", "sun" }) );
        set("gender", "����" );
        set("age", 28);
        set("nickname", HIW"�������"NOR);
        set("long", @LONG
�����������˫Ŀ��Ȼ������ȥһ���˲ġ�
LONG
);
        set_skill("unarmed", 150);
        set_skill("blade", 150);
        set_skill("move", 120);
        set_skill("dodge", 140);
        set_skill("force", 130);
        set_skill("parry", 150);
        set_skill("meng-steps", 100);
        set_skill("liumang-strike", 90);
        set_skill("lianxin-blade", 140);
        map_skill("unarmed", "liumang-strike");
        map_skill("blade", "lianxin-blade");
        map_skill("move", "meng-steps");
        map_skill("dodge", "meng-steps");
        map_skill("parry", "lianxin-blade");
    set("max_gin", 3000);
    set("max_kee", 3000);
    set("max_sen", 3000);
    set("max_force", 1000);
    set("force", 1000);
        set("combat_exp", 300000);
        setup();
        carry_object("/obj/armor/cloth",
                ([ "name": "����" ])
                )->wear();
        carry_object("/obj/weapon/blade")->wield();
} 
void die(){
        object me;
        
        if(objectp(me=query_temp("last_damage_from") )){ 
                if(me->query("marks/���������")){
                        me->delete("marks/���������");
                        if(!me->query("m_success/�ȷ����")){
                                me->set("m_success/�ȷ����",1);
                                me->add("score",800);
                                me->add("combat_exp", 300);
                                me->add("potential", 200);
                        }
                environment(this_object())->check_rescue(me);
                }
        }       
        ::die();
}      
