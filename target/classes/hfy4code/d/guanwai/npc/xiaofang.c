#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("С��", ({ "xiao fang","fang" }) );
        set("gender", "����" );
        set("long",
                "һ���������⡢Ư������Ĺ¶����ӡ�\n"
                );
        set("title", HIW"����"NOR);
        set("attitude", "peaceful");
        
        set("age", 28);
        set("str", 40);
        set("cor", 36);
        set("agi", 60);
        set("per", 30);
        
        set("combat_exp", 5000000);
        
        set("max_gin", 5000);
        set("max_sen", 5000);
        
        set("force",3000);
        set("max_force",3000);
        set("force_factor",100);
        set("no_busy",4);
        set("class","fighter");
         
        set("chat_chance", 1);
        set("chat_msg", ({
                "С��Զ�����Ŵ����ʥĸѩ�壬����ɤ�ӵ�����ӥ������һ�����ҵ�\n�㣬�ҵ�һ���úû��ŵ��㡭��\n",
                }) ); 
        set_skill("unarmed", 200);
        set_skill("parry", 200);
        set_skill("dodge", 300);
        set_skill("sword", 300);
        set_skill("doomforce", 150);
        set_skill("lingxi-zhi", 200);
        set_skill("doomsteps", 200);
           set_skill("doomsword",150);
        
        map_skill("unarmed", "lingxi-zhi");
        map_skill("sword", "doomsword");
        map_skill("dodge", "doomsteps");
        map_skill("parry","doomsword"); 
        set("chat_chance_combat", 30);
        set("chat_msg_combat",({
                      (:perform_action,"sword.hunranyijian":),
        }));
        
        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/icesword")->wield();
} 
int accept_object(object me, object obj)
{
        if(obj->query("name") == BLU"ħ�۽�"NOR && obj->query("owner") == me->query("id"))
        {
                message_vision("$N��������ħ�۽������������˸���԰׵����Ϸ�����Ѫɫ��\n", this_object());
                message_vision("$N��$n�м��ص��˵�ͷ������绹���ţ�����֪���������š�\n",this_object(),me);
                if(!me->query("imbue/xiaofang")){
                                call_out("imbue_event", 2, me);
                        }
                if(!me->query("m_success/������ӥ"))
                {
                        me->set("m_success/������ӥ",1);
                        me->add("score",200);
                }
                return 1;
        }
        else
        {
                write("С�����ֵ��������Ӳ��������������²��ܽ������Ķ�������\n");
                return 0;
        }
} 
void imbue_event(object me){
        object weapon, *inv, obj;
        string prop;
   int i;
        if(!interactive(me) || environment(me) != environment(this_object())) {
                return 0;
        }
        obj = me->query_temp("weapon");
        if(objectp(obj) && obj->query("owner")) {
                weapon = me->query_temp("weapon");
        } else { 
                inv = all_inventory(me);        
                for(i=0; i<sizeof(inv); i++) {
                        if(inv[i]->query("weapon_prop") && inv[i]->query("owner")) {
                                weapon = inv[i];
                                break;
                        }
                }       
        }                       
        if(!objectp(weapon)){
                if(!objectp(obj)){
                        message_vision(HIC"\n��ϲ����ˮһ��һ�ε����ڵ��ϡ�����\n"NOR, me);
                } else {
                        message_vision(HIC"\n��ϲ����ˮһ��һ�ε���$N��" + obj->name() + HIC"���ֻ��䵽���ϡ�\n", me);
                }
        }else {
                message_vision(HIC"\n��ϲ����ˮһ��һ�ε�����$N��" + weapon->name() + HIC"�ϣ���һ��������˾�Ө�����ı�������� \n"NOR,
                                me);
                message_vision(HIC"�������" + weapon->name() + HIC"��ɢ������ʵĹ�â������ת˲������ʧ�޺ۡ�\n"NOR, me);
                if(weapon->query("weapon_prop")) {
                        prop="weapon_prop/";
                }
                if(weapon->query("equipped") == "wielded") {
                        weapon->unequip();
             if(random(me->query("����B/̩ɽ_�ճ�"))==9 ) {
                                weapon->add(prop+"karma", 5);
                                weapon->add(prop+"intelligence", 2);
                                weapon->add(prop+"damage", 10);
                                weapon->add("base_damage", 10);
                        } else {
                weapon->add(prop+"karma", 2);
                                weapon->add(prop+"personality", 2);
                        }
                   weapon->wield();
                } else {
             if(random(me->query("����B/̩ɽ_�ճ�"))==9 ) {
                weapon->add(prop+"karma", 5);
                                weapon->add(prop+"intelligence", 2);
                                weapon->add(prop+"damage", 10);
                                weapon->add("base_damage", 10);
                        } else {
                weapon->add(prop+"karma", 2);
                                weapon->add(prop+"personality", 2);
                        }
                }
                weapon->save();                 
                me->set("imbue/xiaofang", 1);
                me->save();
                return;
        } 
        me->set("imbue/xiaofang", 2);
        me->save();
        return;
}   
